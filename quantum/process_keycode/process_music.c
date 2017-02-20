#include "process_music.h"
#ifdef MIDI_ENABLE
#include "midi.h"
#endif

bool music_activated = false;
uint8_t music_starting_note = 0x0C;
int music_offset = 7;

// music sequencer
static bool music_sequence_recording = false;
static bool music_sequence_recorded = false;
static bool music_sequence_playing = false;
static float music_sequence[16] = {0};
static uint8_t music_sequence_count = 0;
static uint8_t music_sequence_position = 0;

static uint16_t music_sequence_timer = 0;
static uint16_t music_sequence_interval = 100;

bool process_music(uint16_t keycode, keyrecord_t *record) {

	//dprintf("process music\n");

    if (keycode == AU_ON && record->event.pressed) {
      #ifdef AUDIO_ENABLE
      audio_on();
      #endif
      return false;
    }

    if (keycode == AU_OFF && record->event.pressed) {
      #ifdef AUDIO_ENABLE
      audio_off();
      #endif
      return false;
    }

    if (keycode == AU_TOG && record->event.pressed) {
      #ifdef AUDIO_ENABLE
        if (is_audio_on())
        {
            audio_off();
        }
        else
        {
            audio_on();
        }
      #endif
      return false;
    }

    if (keycode == MU_ON && record->event.pressed) {
        music_on();
        return false;
    }

    if (keycode == MU_OFF && record->event.pressed) {
        music_off();
        return false;
    }

    if (keycode == MU_TOG && record->event.pressed) {
        if (music_activated)
        {
            music_off();
        }
        else
        {
            music_on();
        }
        return false;
    }

    if (keycode == MUV_IN && record->event.pressed) {
    	#ifdef AUDIO_ENABLE
        voice_iterate();
        #endif
        music_scale_user();
        return false;
    }

    if (keycode == MUV_DE && record->event.pressed) {
    	#ifdef AUDIO_ENABLE
        voice_deiterate();
        #endif
        music_scale_user();
        return false;
    }

    if (music_activated) {

      if (keycode == KC_LCTL && record->event.pressed) { // Start recording
      	#ifdef AUDIO_ENABLE
        stop_all_notes();
        #endif
        music_sequence_recording = true;
        music_sequence_recorded = false;
        music_sequence_playing = false;
        music_sequence_count = 0;
        return false;
      }

      if (keycode == KC_LALT && record->event.pressed) { // Stop recording/playing
      	#ifdef AUDIO_ENABLE
        stop_all_notes();
        #endif
        if (music_sequence_recording) { // was recording
          music_sequence_recorded = true;
        }
        music_sequence_recording = false;
        music_sequence_playing = false;
        return false;
      }

      if (keycode == KC_LGUI && record->event.pressed && music_sequence_recorded) { // Start playing
      	#ifdef AUDIO_ENABLE
        stop_all_notes();
        #endif
        music_sequence_recording = false;
        music_sequence_playing = true;
        music_sequence_position = 0;
        music_sequence_timer = 0;
        return false;
      }

      if (keycode == KC_UP) {
        if (record->event.pressed)
            music_sequence_interval-=10;
        return false;
      }

      if (keycode == KC_DOWN) {
        if (record->event.pressed)
            music_sequence_interval+=10;
        return false;
      }

      #define MUSIC_MODE_GUITAR

      #ifdef MUSIC_MODE_CHROMATIC
      float freq = ((float)220.0)*pow(2.0, -5.0)*pow(2.0,(music_starting_note + record->event.key.col + music_offset)/12.0+(MATRIX_ROWS - record->event.key.row));
      uint8_t note = (music_starting_note + record->event.key.col + music_offset - 3)+12*(MATRIX_ROWS - record->event.key.row);
      #elif defined(MUSIC_MODE_GUITAR)
      float freq = ((float)220.0)*pow(2.0, -5.0)*pow(2.0,(music_starting_note + record->event.key.col + music_offset)/12.0+(float)(MATRIX_ROWS - record->event.key.row + 7)*5.0/12);
      uint8_t note = (music_starting_note + record->event.key.col + music_offset + 32)+5*(MATRIX_ROWS - record->event.key.row);
      #elif defined(MUSIC_MODE_VIOLIN)
      float freq = ((float)220.0)*pow(2.0, -5.0)*pow(2.0,(music_starting_note + record->event.key.col + music_offset)/12.0+(float)(MATRIX_ROWS - record->event.key.row + 5)*7.0/12);
      uint8_t note = (music_starting_note + record->event.key.col + music_offset + 32)+7*(MATRIX_ROWS - record->event.key.row);
      #else
      float freq = ((float)220.0)*pow(2.0, -5.0)*pow(2.0,(music_starting_note + SCALE[record->event.key.col + music_offset])/12.0+(MATRIX_ROWS - record->event.key.row));
      uint8_t note = (music_starting_note + SCALE[record->event.key.col + music_offset] - 3)+12*(MATRIX_ROWS - record->event.key.row);
      #endif

      dprintf("music freq: %d, note: %d, row: %d, col: %d, music_offset: %d, music_starting_note: %d, MATRIX_ROWS: %d\n", 
      	(int)freq,
      	note,
      	record->event.key.row,
      	record->event.key.col,
      	music_offset,
      	music_starting_note,
      	MATRIX_ROWS);

      if (record->event.pressed) {
      	#ifdef AUDIO_ENABLE
        play_note(freq, 0xF);
        #endif
        #ifdef MIDI_ENABLE
        midi_send_noteon(&midi_device, 0, note, 127);
        #endif
        if (music_sequence_recording) {
          music_sequence[music_sequence_count] = freq;
          music_sequence_count++;
        }
      } else {
      	#ifdef AUDIO_ENABLE
        stop_note(freq);
        #endif
        #ifdef MIDI_ENABLE
        midi_send_noteoff(&midi_device, 0, note, 0);
        #endif
      }

      if (keycode < 0xFF) // ignores all normal keycodes, but lets RAISE, LOWER, etc through
        return false;
    }
  return true;
}

bool is_music_on(void) {
    return (music_activated != 0);
}

void music_toggle(void) {
    if (!music_activated) {
        music_on();
    } else {
        music_off();
    }
}

void music_on(void) {
	dprintf("music on\n");
    music_activated = 1;
    music_on_user();
}

void music_off(void) {
	dprintf("music off\n");
    music_activated = 0;
    #ifdef AUDIO_ENABLE
    stop_all_notes();
    #endif
}


__attribute__ ((weak))
void music_on_user() {}

__attribute__ ((weak))
void audio_on_user() {}

__attribute__ ((weak))
void music_scale_user() {}

void matrix_scan_music(void) {
  if (music_sequence_playing) {
    if ((music_sequence_timer == 0) || (timer_elapsed(music_sequence_timer) > music_sequence_interval)) {
      music_sequence_timer = timer_read();
      #ifdef AUDIO_ENABLE
      stop_note(music_sequence[(music_sequence_position - 1 < 0)?(music_sequence_position - 1 + music_sequence_count):(music_sequence_position - 1)]);
      play_note(music_sequence[music_sequence_position], 0xF);
      #endif
      music_sequence_position = (music_sequence_position + 1) % music_sequence_count;
    }
  }
}

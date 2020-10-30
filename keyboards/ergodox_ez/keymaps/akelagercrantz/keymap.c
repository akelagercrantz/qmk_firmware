#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_nordic.h"
#include "keymap_norwegian.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,
  ALT_GUI_MDIA
};

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // mouse keys

#define PERMISSIVE_HOLD
#define QMK_KEYS_PER_SCAN 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |ALTGUI|           |      |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------| MDIA |           |      |------+------+------+------+------+--------|
 * | Cmd    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | MO 2 |           | MO 2 |   N  |   M  |   ,  |   .  |   -  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  Alt |   '  |   "  | MO 1 |                                       | MO 1 |   ;  |   :  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | PgUp |      |      |
 *                                 | Space| Tab  |------|       |------|Back  |Enter |
 *                                 |      |      |Delete|       | PgDn |space |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESCAPE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     ALT_GUI_MDIA,
        KC_LGUI,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
        KC_LSFT,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     MO(MDIA),
          KC_LCTL,  KC_LALT,  NO_APOS, NO_QUO2,  MO(SYMB),
                                                             KC_TRNS,  KC_TRNS,
                                                                       KC_TRNS,
                                                    KC_SPC,  KC_TAB,   KC_DEL,
        // right hand
          KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
          KC_TRNS,    KC_Y,     KC_U,       KC_I,       KC_O,     KC_P,     NO_AM,
                      KC_H,     KC_J,       KC_K,       KC_L,     KC_SCLN,  NO_AE,
          MO(MDIA),   KC_N,     KC_M,       KC_COMM,    KC_DOT,   NO_MINS,  KC_RSFT,
                              MO(SYMB),  NO_SCLN,  NO_COLN,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,
        KC_PGUP,
        KC_PGDN,  KC_BSPACE,  KC_ENT
    ),

// KC_ENT
// KC_BSPACE
// KC_TAB
// KC_SPC

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   <  |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------|   >  |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   &  |   [  |   ]  |   ~  |      |           |      |   ?  |   1  |   2  |   3  |   ^  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |   \  |   /  |      |                                       |      |   0  |   =  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
      // left hand
      KC_TRNS,  KC_F1,     KC_F2,             KC_F3,              KC_F4,              KC_F5,        KC_TRNS,
      KC_TRNS,  KC_EXLM,   NO_AT,             LALT(LSFT(KC_8)),   LALT(LSFT(KC_9)),   LALT(KC_7),   KC_TRNS,
      KC_TRNS,  KC_HASH,   NO_DLR,            NO_LPRN,            NO_RPRN,            LSFT(NO_BSLS),
      KC_TRNS,  KC_PERC,   NO_AMPR,           NO_LBRC,            NO_RBRC,            LALT(NO_QUOT),       KC_TRNS,
      KC_TRNS,  KC_TRNS,   LALT(LSFT(KC_7)),  LSFT(KC_7),         KC_TRNS,
                                                                              KC_TRNS,  KC_TRNS,
                                                                                        KC_TRNS,
                                                                    KC_TRNS,  KC_TRNS,  KC_TRNS,
      // right hand
        KC_TRNS,  KC_F6,    KC_F7,  KC_F8,   KC_F9,  KC_F10,           KC_F11,
        KC_TRNS,  NO_LESS_MAC,   KC_7,   KC_8,    KC_9,   KC_KP_ASTERISK,   KC_F12,
                  NO_GRTR_MAC,   KC_4,   KC_5,    KC_6,   KC_KP_PLUS,       KC_TRNS,
        KC_TRNS,  NO_QUES,  KC_1,   KC_2,    KC_3,   LSFT(NO_QUOT),          KC_TRNS,
                          KC_TRNS,   KC_0,   NO_EQL,   KC_TRNS,  KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
),
 /* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| Left | Down |  Up  |Right |      |        |  
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | Prev |TglPly| Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolDn |VolUp | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Brwser|Brwser|
 *                                 |      |      |------|       |------| Back | Frwd |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
      // left hand
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                          KC_TRNS, KC_TRNS,
                                                   KC_TRNS,
                                 KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN,     KC_UP,     KC_RIGHT,  KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_MRWD,     KC_MPLY,   KC_MFFD,   KC_TRNS, KC_TRNS,
                          KC__VOLDOWN, KC__VOLUP, KC__MUTE,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case ALT_GUI_MDIA:
      if (record->event.pressed) {
        ergodox_right_led_3_on();
        SEND_STRING(SS_DOWN(X_LALT));
        SEND_STRING(SS_DOWN(X_LGUI));
        layer_invert(MDIA);
      } else {
        layer_invert(MDIA);
        SEND_STRING(SS_UP(X_LALT));
        SEND_STRING(SS_UP(X_LGUI));
        ergodox_right_led_3_off();
      }
      return false;
  }

  return true;
};


// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();

  uint8_t layer = biton32(state);
  switch (layer) {
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      break; 
    default:
      break;
  }

  return state;
};



#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_swedish.h"

// clang-format off

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,
  ALT_GUI_MDIA,
  SWITCH_OS,
  MO_SYMBOLS
};

#define _BASE 0 // default layer
#define _SYMBOLS 1 // symbols
#define _SYMBOLS_WIN_OVERLAY 2 // windows overlay for symbols
#define _MEDIA 3 // mouse keys

#define PERMISSIVE_HOLD
#define QMK_KEYS_PER_SCAN 4

enum OS {
  MAC_OS = 0,
  WINDOWS = 1
};
static enum OS current_os = MAC_OS;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  0     |   1  |   2  |   3  |   4  |   5  |   6  |           |      |      |      |      |      |      |   OS   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Esc    |   Q  |   W  |   E  |   R  |   T  |ALTGUI|           |      |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------| MDIA |           |      |------+------+------+------+------+--------|
 * | Cmd    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | MO 2 |           |      |   N  |   M  |   ,  |   .  |   -  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  Alt |   '  |   "  | MO 1 |                                       | MO 1 |   ;  |   :  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |   7  |   8  |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |   9  |       | PgUp |      |      |
 *                                 | Space| Tab  |------|       |------|Back  |Enter |
 *                                 |      |      |Delete|       | PgDn |space |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_0,       KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,
        KC_ESCAPE,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     ALT_GUI_MDIA,
        KC_LGUI,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
        KC_LSFT,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     MO(_MEDIA),
          KC_LCTL,  KC_LALT,  SE_QUOT, SE_DQUO,  MO_SYMBOLS,
                                                             KC_7,     KC_8,
                                                                       KC_9,
                                                    KC_SPC,  KC_TAB,   KC_DEL,
        // right hand
          KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  SWITCH_OS,
          KC_TRNS,    KC_Y,     KC_U,       KC_I,       KC_O,     KC_P,     SE_ARNG,
                      KC_H,     KC_J,       KC_K,       KC_L,     SE_ODIA,  SE_ADIA,
          KC_TRNS,   KC_N,     KC_M,       KC_COMM,    KC_DOT,   SE_MINS,  KC_RSFT,
                              MO_SYMBOLS,  SE_SCLN,  SE_COLN,  KC_TRNS,  KC_TRNS,
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
 * |        |   #  |   $  |   (  |   )  |   /  |------|           |------|   >  |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   &  |   [  |   ]  |   \  |      |           |      |   ?  |   1  |   2  |   3  |   ^  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |   ~  |   ´  |   `  |      |                                       |      |   0  |   =  |      |      |
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
[_SYMBOLS] = LAYOUT_ergodox(

      // left hand
      KC_TRNS,    KC_F1,      KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRNS,
      KC_TRNS,    KC_EXLM,    SE_AT,          SE_LCBR_MAC,    SE_RCBR_MAC,    SE_PIPE_MAC,    KC_TRNS,
      KC_TRNS,    SE_HASH,    SE_DLR,         SE_LPRN,        SE_RPRN,        SE_SLSH,
      KC_TRNS,    SE_PERC,    SE_AMPR,        SE_LBRC,        SE_RBRC,        SE_BSLS_MAC,        KC_TRNS,
      KC_TRNS,    SE_TILD,    SE_ACUT,        SE_GRV,         KC_TRNS,

                                                                      KC_TRNS,  KC_TRNS,
                                                                                KC_TRNS,
                                                            KC_TRNS,  KC_TRNS,  KC_TRNS,


      // right hand
        KC_TRNS,    KC_F6,        KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
        KC_TRNS,    SE_SECT,      KC_7,       KC_8,       KC_9,       SE_ASTR,    KC_F12,
                    S(SE_SECT),   KC_4,       KC_5,       KC_6,       SE_PLUS,    KC_TRNS,
        KC_TRNS,    SE_QUES,      KC_1,       KC_2,       KC_3,       SE_CIRC,    KC_TRNS,
                                  KC_TRNS,    KC_0,       SE_EQL,     KC_TRNS,    KC_TRNS,

      KC_TRNS,  KC_TRNS,
      KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS

),
[_SYMBOLS_WIN_OVERLAY] = LAYOUT_ergodox(

      // left hand
      KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
      KC_TRNS,    KC_TRNS,    KC_TRNS,        SE_LCBR,        SE_RCBR,        SE_PIPE,        KC_TRNS,
      KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,        SE_BSLS,
      KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
      KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,

                                                                      KC_TRNS,  KC_TRNS,
                                                                                KC_TRNS,
                                                            KC_TRNS,  KC_TRNS,  KC_TRNS,


      // right hand
        KC_TRNS,    KC_TRNS,      KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,
        KC_TRNS,    SE_LABK,      KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,
                    S(SE_LABK),   KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,      KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,
                                  KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,

      KC_TRNS,  KC_TRNS,
      KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS

),
 /* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Left | Down |  Up  |Right |      |        |  
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | Prev |TglPly| Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolDn |VolUp | Mute |      |      |
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
[_MEDIA] = LAYOUT_ergodox(
      // left hand
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
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

void flash_led(uint8_t index, uint8_t count) {
  for (int i = 0; i < count; i++) {
    ergodox_right_led_on(index);
    _delay_ms(50);
    ergodox_right_led_off(index);
    _delay_ms(50);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case MO_SYMBOLS:
      if (record->event.pressed) {
        layer_on(_SYMBOLS);
        if (current_os == WINDOWS) {
          layer_on(_SYMBOLS_WIN_OVERLAY);
        }
      } else {
        layer_off(_SYMBOLS);
        layer_off(_SYMBOLS_WIN_OVERLAY);
      }
      return false;
    case SWITCH_OS:
      if (record->event.pressed) {
        current_os = (current_os == MAC_OS) ? WINDOWS : MAC_OS;
        uint8_t led = (current_os == MAC_OS) ? 1 : 3;
        flash_led(led, 5);
      }
      return false;
    case ALT_GUI_MDIA:
      if (record->event.pressed) {
        ergodox_right_led_3_on();
        SEND_STRING(SS_DOWN(X_LALT));
        SEND_STRING(SS_DOWN(X_LGUI));
        layer_invert(_MEDIA);
      } else {
        layer_invert(_MEDIA);
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
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
    case _SYMBOLS:
      ergodox_right_led_1_on();
      break;
    case _SYMBOLS_WIN_OVERLAY:
      ergodox_right_led_3_on();
      break;
    case _MEDIA:
      ergodox_right_led_2_on();
      break; 
    default:
      break;
  }

  return state;
};



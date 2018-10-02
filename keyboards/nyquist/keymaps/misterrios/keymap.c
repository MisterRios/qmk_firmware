#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GUI
};

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  QWERTY,
  GUI,
};

// German Layout Keyboard Symbols
#define DE_QUES LSFT(KC_MINS)
#define DE_AT RALT(KC_Q)      // @
#define DE_EURO RALT(KC_E)    // €
#define DE_ANGL KC_NUBS       // <
#define DE_PIPE RALT(KC_MINS) // |
#define DE_BSLS RALT(KC_NUBS) // /
#define DE_TLDE RALT(KC_RBRC) // ~

// German Diacriticals
#define DE_OUML KC_SCLN       // ö
#define DE_AUML KC_QUOT       // ä
#define DE_UUML KC_LBRC       // ü
#define DE_ESZT KC_MINS       // ß

// german brackets
#define DE_LCUR RALT(KC_7)    // {
#define DE_RCUR RALT(KC_0)    // }
#define DE_LPAR LSFT(KC_8)    // (
#define DE_RPAR LSFT(KC_9)    // )
#define DE_LBRC RALT(KC_8)    // [
#define DE_RBRC RALT(KC_9)    // ]

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Z  |   <  |  ]   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Super| Alt  | Lower| Enter       | Space       |Raise | GUI  | Del  | Back |
 * `-----------------------------------------------------------------------------------'
 * Translated using Standard DE keymap to:
 * ,-----------------------------------------------------------------------------------.
 * |   ^  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | ´    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Z  |   <  |  +   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  #   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   -  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Super| Alt  | Lower| Enter       | Space       |Raise | GUI  | Del  | Back |
 * `-----------------------------------------------------------------------------------'
 *
 */
[_COLEMAK] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL, \
  KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    DE_ANGL, KC_RBRC, \
  KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_BSLS, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT , \
  KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_ENT,  KC_ENT,  KC_SPC,  KC_SPC,  RAISE,   GUI,     KC_DEL , KC_BSPC \
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Super| Alt  | Lower| Enter       | Space       |Raise | GUI  | Del  | Back |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, \
  _______, _______, _______, KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL, \
  _______, _______, KC_S,    KC_D,    KC_F,    KC_G,    _______, KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  _______, _______, _______, _______, _______, _______, KC_N,    _______, _______, _______, _______, KC_ENT , \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | Down | Right| -    |  7   |   8  |  9   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | Left |      |      |  4   |   5  |  6   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | Up   |      |      |  1   |   2  |  3   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | Alt  |      |  Delete     | Backspace   |      |  0   |  .   |Return|
 * `-----------------------------------------------------------------------------------'
 * Translated using Standard DE keymap to:
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | Down | Right| ?    |  7   |   8  |  9   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | Left | @    | Euro |  4   |   5  |  6   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | Up   |      |      |  1   |   2  |  3   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  Delete     | Backspace   |      |  0   |  .   |Return|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  _______, _______, _______, _______, _______, _______, KC_DOWN, KC_RGHT, DE_QUES, KC_P7,   KC_P8,   KC_P9, \
  _______, _______, _______, _______, _______, _______, KC_LEFT, DE_AT,   DE_EURO, KC_P4,   KC_P5,   KC_P6, \
  _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, KC_P1,   KC_P2,   KC_P3, \
  _______, _______, _______, _______, KC_DEL,  KC_DEL,  KC_BSPC, KC_BSPC, _______, KC_P0,   KC_PDOT, KC_PENT \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |  {   |   }  |      |      |  Ü   |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Numlk |  Ä   |      |  ß   |  [   |  ]   |      |  |   |  \   |  ~   |  Ö   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Capslk|      |      |      |  (   |  )   |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  Delete     |  Backspace  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, DE_LCUR, DE_RCUR, _______, _______, DE_UUML, _______, _______, _______, \
  KC_NLCK, DE_AUML, _______, DE_ESZT, DE_LBRC, DE_RBRC, _______, DE_PIPE, DE_BSLS, DE_TLDE, DE_OUML, _______, \
  KC_CAPS, _______, _______, _______, DE_LPAR, DE_RPAR, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_DEL,  KC_DEL,  KC_BSPC, KC_BSPC, _______, _______, _______, _______\
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|Sat Up|Sat Dn|Val Up|Val Dn|      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* GUI
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LchPly|PrvTrk|NxtTrk|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Play | Vol- | Vol+ |      |  Sleep      |  Lock       |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GUI] =  LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_U, _______, _______, \
  KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______, KC_WH_D, _______, _______, \
  KC_MSEL, KC_VOLD, KC_VOLU, _______, KC_SLEP, KC_SLEP, LCA(KC_L), LCA(KC_L), _______, _______, _______, _______  \
)

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case GUI:
      if (record->event.pressed) {
        layer_on(_GUI);
      } else {
        layer_off(_GUI);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

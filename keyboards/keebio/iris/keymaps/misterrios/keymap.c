#include QMK_KEYBOARD_H
#include "keymap_german.h"

// extern keymap_config_t keymap_config;

#define _COLEMAK 0
#define _LOWER 1
#define _RAISE 2
#define _QWERTY 3
#define _GUI 4
#define _ADJUST 5

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
  QWERTY,
  GUI,
  ADJUST,
  ALT_OR_SUPER,
  CFLX,
  LABRAC,
  ATSGN,
  LCBRAC,
  RCBRAC,
  LBRAC,
  RBRAC,
  TILDE,
  BKSLS,
  PIPE,
};

os_variant_t detected_os = OS_UNSURE;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //| ^      | 1      | 2      | 3      | 4      | 5      |                          | 6      | 7      | 8      | 9      | 0      | ´      |
     CFLX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DE_ACUT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //| Esc    | Q      | W      | F      | P      | G      |                          | J      | L      | U      | Z      | <      | +      |
     KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                               KC_J,    KC_L,    KC_U,    DE_Z,    LABRAC,  DE_PLUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //| Tab    | A      | R      | S      | T      | D      |                          | H      | N      | E      | I      | O      | #      |
     KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                               KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    DE_HASH,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //| Shift  | Y      | X      | C      | V      | B      | Alt    |        | Space  | K      | M      | ,      | .      | -      | Shift  |
     KC_LSFT, DE_Y,    KC_X,    KC_C,    KC_V,    KC_B,    ALT_OR_SUPER,      KC_SPC,  KC_K,    KC_M,    KC_COMM, KC_DOT,  DE_MINS, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                               | Super  | Lower  |Ctrl/Ent|                 | Space  | Raise  | GUI    |
                                    KC_LGUI, LOWER,   CTL_T(KC_ENT),             KC_SPC,  RAISE,   GUI
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //| F12    | F1     | F2     | F3     | F4     | F5     |                          | F6     | F7     | F8     | F9     | F10    | F11    |
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //| Reset  |        |        |        |        |        |                          | Down   | Right  | ?      | 7      | 8      | 9      |
     QK_BOOT, _______, _______, _______, _______, _______,                            KC_DOWN, KC_RGHT, DE_QUES, KC_P7,   KC_P8,   KC_P9,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        |                          | Left   | @      | €      | 4      | 5      | 6      |
     _______, _______, _______, _______, _______, _______,                            KC_LEFT, ATSGN,   DE_EURO, KC_P4,   KC_P5,   KC_P6,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        | Ctrl   |        |        | F12    |        | Bsp    | Up     |        |        | 1      | 2      | 3      |
     _______, _______, _______, _______, _______, _______, CTL_T(KC_F12),    KC_BSPC, KC_UP,   _______, _______, KC_P1,   KC_P2,   KC_P3,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                               |        |        | Delete |                 | Bsp    |        | 0      |
                                    _______, _______, KC_DEL,                    KC_BSPC, _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //|        |        |        |        |        |        |                          |        | \      |        |        |        |        |
     _______, _______, _______, _______, _______, _______,                            _______, BKSLS,   _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        | {      | }      |                          |        |        | ü      |        |        |        |
     _______, _______, _______, _______, LCBRAC,  RCBRAC,                             _______, _______, DE_UDIA, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //| NumLock| ä      |        | ß      | (      | )      |                          |        | ~      | \      | |      | ö      |        |
     KC_NUM,  DE_ADIA, _______, DE_SS,   DE_LPRN, DE_RPRN,                            _______, TILDE,   BKSLS,   PIPE,    DE_ODIA, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //| CpLock |        |        |        | [      | ]      | Delete |        |        |        |        |        |        |        |        |
     KC_LCAP, _______, _______, _______, LBRAC,   RBRAC,   KC_DEL,           _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                               |        |        | Delete |                 | Backsp |        |        |
                                    _______, _______,  KC_DEL,                    KC_BSPC, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LOWER,   KC_ENT,                    KC_SPC,  RAISE,   KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //|        |        |        |        |        |        |                          |        |        |        |        |        |        |
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //| Reset  | RGB Tg | RGB MdN| RGBMdP | RGBSpU | RGBSpD |                          |        |        |        |        |        |        |
     QK_MAKE, RM_TOGG, RM_NEXT, RM_PREV, RM_SPDU, RM_SPDD,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //| Inc Hue| Sat +  | Value +| Play   | PrvTr  | NxtTrk |                          | PgUp   | Mse Up | Home   |        |        |        |
     RM_HUEU, RM_SATU, RM_VALU, KC_MPLY, KC_MPRV, KC_MNXT,                            KC_PGUP, MS_WHLU, KC_HOME, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //| Dec Hue| Sat -  | Value -| Mplay  | VolDwn | Vol +  |        |        |        | PgDown | M Down | End    |        |        |        |
     RM_HUED, RM_SATD, RM_VALD, KC_MSEL, KC_VOLD, KC_VOLU, _______,          _______, KC_PGDN, MS_WHLD, KC_END,  _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                               |        |        | Sleep  |                 | Lock   |        |        |
                                    _______, _______, KC_SLEP,                   LGUI(KC_L), _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GUI] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //|        |        |        |        |        |        |                          |        |        |        |        |        |        |
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        |                          |        |        |        |        |        |        |
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        |                          |        |        |        |        |        |        |
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //|        |        |        |        |        |        |                          |        |        |        |        |        |        |
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                               |        |        |        |                 |        |        |        |
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_detected_host_os_kb(os_variant_t os) {
    if (!process_detected_host_os_user(os)) {
        return false;
    }
    detected_os = os;
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;

    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
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

    case ALT_OR_SUPER:
      if (record->event.pressed) {
        if (detected_os == OS_MACOS) {
          register_code(KC_LGUI);
          register_code(KC_SPC);
        } else {
          register_code(KC_LGUI);
        }
      } else {
        if (detected_os == OS_MACOS) {
          unregister_code(KC_SPC);
          unregister_code(KC_LGUI);
        } else {
          unregister_code(KC_LGUI);
        }
      }
      return false;
      break;

    case CFLX: // ^
      if (record->event.pressed) {
        if (detected_os == OS_MACOS) {
          register_code(KC_NUBS);
        } else {
          register_code(DE_CIRC);
        }
      } else {
        if (detected_os == OS_MACOS) {
          unregister_code(KC_NUBS);
        } else {
          unregister_code(DE_CIRC);
        }
      }
      return false;
      break;
    case LABRAC: // <
      if (record->event.pressed) {
        if (detected_os == OS_MACOS) {
          register_code(KC_GRV);
        } else {
          register_code(DE_LABK);
        }
      } else {
        if (detected_os == OS_MACOS) {
          unregister_code(KC_GRV);
        } else {
          unregister_code(DE_LABK);
        }
      }
      return false;
      break;
    case ATSGN: // @ DE_AT
      if (record->event.pressed) {
        if (detected_os == OS_MACOS) {
          register_code(KC_LALT);
          register_code(KC_L);
        } else {
          register_code(KC_ALGR);
          register_code(KC_Q);
        }
      } else {
        if (detected_os == OS_MACOS) {
          unregister_code(KC_L);
          unregister_code(KC_LALT);
        } else {
          unregister_code(KC_ALGR);
          unregister_code(KC_Q);
        }
      }
      return false;
      break;
    case LCBRAC: // { DE_LCBR
      if (record->event.pressed) {
        if (detected_os == OS_MACOS) {
          register_code(KC_LALT);
          register_code(KC_8);
        } else {
          register_code(KC_ALGR);
          register_code(KC_7);
        }
      } else {
        if (detected_os == OS_MACOS) {
          unregister_code(KC_8);
          unregister_code(KC_LALT);
        } else {
          unregister_code(KC_7);
          unregister_code(KC_ALGR);
        }
      }
      return false;
      break;
    case RCBRAC: // } DE_RCBR
      if (record->event.pressed) {
        if (detected_os == OS_MACOS) {
          register_code(KC_LALT);
          register_code(KC_9);
        } else {
          register_code(KC_ALGR);
          register_code(KC_0);
        }
      } else {
        if (detected_os == OS_MACOS) {
          unregister_code(KC_9);
          unregister_code(KC_LALT);
        } else {
          unregister_code(KC_0);
          unregister_code(KC_ALGR);
        }
      }
      return false;
      break;
    case LBRAC: // [ DE_LBRC
      if (record->event.pressed) {
        if (detected_os == OS_MACOS) {
          register_code(KC_LALT);
          register_code(KC_5);
        } else {
          register_code(KC_ALGR);
          register_code(KC_8);
        }
      } else {
        if (detected_os == OS_MACOS) {
          unregister_code(KC_5);
          unregister_code(KC_LALT);
        } else {
          unregister_code(KC_8);
          unregister_code(KC_ALGR);
        }
      }
      return false;
      break;
    case RBRAC: // ] DE_RBRC
      if (record->event.pressed) {
        if (detected_os == OS_MACOS) {
          register_code(KC_LALT);
          register_code(KC_6);
        } else {
          register_code(KC_ALGR);
          register_code(KC_9);
        }
      } else {
        if (detected_os == OS_MACOS) {
          unregister_code(KC_6);
          unregister_code(KC_LALT);
        } else {
          unregister_code(KC_9);
          unregister_code(KC_ALGR);
        }
      }
      return false;
      break;
    case TILDE: // ~ DE_TILD - ALGR(DE_PLUS) - ALGR(KC_RBRC)
      if (record->event.pressed) {
        if (detected_os == OS_MACOS) {
          register_code(KC_LALT);
          register_code(KC_N);
        } else {
          register_code(KC_ALGR);
          register_code(KC_RBRC);
        }
      } else {
        if (detected_os == OS_MACOS) {
          unregister_code(KC_N);
          unregister_code(KC_LALT);
        } else {
          unregister_code(KC_RBRC);
          unregister_code(KC_ALGR);
        }
      }
      return false;
      break;
    case BKSLS: // (backslash) ALGR(DE_SS) ALGR(KC_MINS)
      if (record->event.pressed) {
        if (detected_os == OS_MACOS) {
          register_code(KC_LSFT);
          register_code(KC_LALT);
          register_code(KC_7);
        } else {
          register_code(KC_ALGR);
          register_code(KC_MINS);
          }
      } else {
        if (detected_os == OS_MACOS) {
          unregister_code(KC_7);
          unregister_code(KC_LALT);
          unregister_code(KC_LSFT);
        } else {
          unregister_code(KC_MINS);
          unregister_code(KC_ALGR);
        }
      }
      return false;
      break;
    case PIPE: // | DE_PIPE
      if (record->event.pressed) {
        if (detected_os == OS_MACOS) {
          register_code(KC_LALT);
          register_code(KC_7);
        } else {
          register_code(KC_ALGR);
          register_code(KC_NUBS);
          }
      } else {
        if (detected_os == OS_MACOS) {
          unregister_code(KC_7);
          unregister_code(KC_LALT);
        } else {
          unregister_code(KC_NUBS);
          unregister_code(KC_ALGR);
        }
      }
      return false;
      break;
    }
  return true;
}

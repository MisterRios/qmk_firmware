/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keymap_german.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //| Esc    | Q      | W      | F      | P      | G      |                    | J      | L      | U      | Z      | <      | +      |
     KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    DE_Z,    DE_LESS, DE_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //| Tab    | A      | R      | S      | T      | D      |                    | H      | N      | E      | I      | O      | #      |
     KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    DE_HASH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //| Shift  | Y      | X      | C      | V      | B      |                    | K      | M      | ,      | .      | -      | Shift  |
     KC_LSFT, DE_Y,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M,    KC_COMM, KC_DOT,  DE_MINS, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                    | Super  | Lower  |Ctrl/Ent|  | Space  | Raise  |        |
                                          KC_LGUI, MO(1), CTL_T(KC_ENT), KC_SPC, MO(2),  KC_LALT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //| F12    | 1      | 2      | 3      | 4      | 5      |                    | Down   | Right  | ?      | 7      | 8      | 9      |
     KC_F12,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_DOWN, KC_RGHT, DE_QUES, KC_P7,   KC_P8,   KC_P9,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        | 6      | 7      | 8      | 9      | 0      |                    | Left   | @      | €      | 4      | 5      | 6      |
  CTL_T(KC_LALT), KC_6, KC_7,   KC_8,    KC_9,    KC_0,                          KC_LEFT, DE_AT,   DE_EURO, KC_P4,   KC_P5,   KC_P6,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //| Shift  | F1     | F2     | F3     | F4     | F5     |                    | Up     | ^      | ´      | 1      | 2      | 3      |
     KC_LSFT,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_UP,   DE_CIRC, DE_ACUT, KC_P1,   KC_P2,   KC_P3,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                    |        |        | Delete |  | Bsp    | Adjust | 0      |
                                         _______, _______, KC_DEL,     KC_BSPC, MO(3),   KC_P0
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //|        |        |        |        | {      | }      |                    |        |        | ü      |        |        |        |
     _______, _______, _______, _______, DE_LCBR, DE_RCBR,                      _______, _______, DE_UE,   _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //| NumLock| ä      |        | ß      | (      | )      |                    |        | ~      | \      | |      | ö      |        |
     KC_NLCK, DE_AE,   _______, DE_SS,   DE_LPRN, DE_RPRN,                      _______, DE_TILD, DE_BSLS, DE_PIPE, DE_OE,   _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //| CpLock |        |        |        | [      | ]      |                    | F6     | F7     | F8     | F9     | F10    | F11    |
     KC_LCAP, _______, _______, _______, DE_LBRC, DE_RBRC,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                    | Super  | Adjust | Delete |  | Bsp    |        | R Alt  |
                                         KC_LGUI, MO(3),   KC_DEL,     KC_BSPC,  _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //| Reset  | RGB Tg | RGB Md |        |        |        |                    |        |        |        |        |        |        |
     RESET,   RGB_TOG, RGB_MOD, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //| Inc Hue| Sat +  | Value +| Play   | PrvTr  | NxtTrk |                    | PgUp   | Mse Up | Home   |        |        |        |
     RGB_HUI, RGB_SAI, RGB_VAI, KC_MPLY, KC_MPRV, KC_MNXT,                      KC_PGUP, KC_WH_U, KC_HOME, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //| Dec Hue| Sat -  | Value -| Mplay  | VolDwn | Vol +  |                    | PgDown | M Down | End    |        |        |        |
     RGB_HUD, RGB_SAD, RGB_VAD, KC_MSEL, KC_VOLD, KC_VOLU,                      KC_PGDN, KC_WH_D, KC_END,  _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                    | Super  | Adjust | Sleep  |  | Lock   |        |        |
                                         KC_LGUI, _______, KC_SLEP,  LGUI(KC_L), _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE

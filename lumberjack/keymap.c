/* Copyright 2020 Paul James
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0,
  _FUNCTION,
  MACRO1
};

enum {
    TD_PC,
    TD_DP,
    TD_SLA,
    TD_CAPLOCK,
    TD_ALT,
    TD_DIAE,
    TD_GRV
};

#define FN MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   º  |  1   |  2   |  3   |  4   |  5   | |  6   |  7   |  8   |  9   |  0   | BkSp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |  O   |  P   | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |  A   |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shft |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  ,   |  .   |  /   | Entr |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |  Win | Alt  |AltGr |  Fn  | Spac | | Spac |  Fn  | Left | Down |  Up  | Rght |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x12(
    TD(TD_GRV),     KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,      KC_9,      KC_0,       KC_BSPC,
    KC_ESC,         KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,      KC_O,      KC_P,       KC_DEL,
    KC_TAB,         KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,      KC_L,      KC_SCLN,    TD(TD_DIAE),
    TD(TD_CAPLOCK), KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    TD(TD_PC), TD(TD_DP), TD(TD_SLA), RSFT_T(KC_ENT),
    KC_LCTL,        KC_LGUI,  KC_LALT, KC_RALT, FN,      KC_SPC,  KC_SPC,  FN,      KC_LEFT,   KC_DOWN,   KC_UP,      KC_RGHT
),

/* Function
* ,------------------------------------------. ,-----------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |  F7  |  F8  |  F9  |  F0  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |      |      |      |   <  |  >   | |      |      |      |      |MACRO1| Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  | Home |      |      |   [  |  ]   | |  '   |  ¡   |  `   |  +   |  ç   |  Ç   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shft | End  |      |      |   {  |  }   | |  ?   |  ¿   |  ^   |  *   |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      | |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_FUNCTION] = LAYOUT_ortho_5x12(
    KC_GRV,    KC_F1,   KC_F2,   KC_F3,   KC_F4,         KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
    KC_ESC,  _______, _______, _______,   KC_NUBS,       S(KC_NUBS),    _______, _______, _______, _______, MACRO1,  KC_DEL,
    KC_TAB,  KC_HOME, _______, _______,   ALGR(KC_LBRC), ALGR(KC_RBRC), KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_PIPE,
    KC_LSFT, KC_END,  _______, _______,   ES_LCBR,       ES_RCBR,       KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______,
    _______,_______,  _______, _______,  _______,        _______,       _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
)

};


// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PC] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, LSFT(KC_COMM)), // Tap once for , twice for ;
    [TD_DP] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, LSFT(KC_DOT)),   //Tap one for . twice for :
    [TD_SLA] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, LSFT(KC_SLSH)),//Tap one for - twice for _
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),  //Tap one for Left_Shift twice for Bloq_Mayus
    [TD_DIAE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, ES_DIAE),      //Tap one for Quote twice for Diaeresis
    [TD_GRV] = ACTION_TAP_DANCE_DOUBLE(ES_MORD, ES_FORD)       //Tap one for º twice for ª
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case MACRO1:
        if (record->event.pressed) {
            SEND_STRING("password");
        } else {
            
        }
        return false;
  }
  return true;
}
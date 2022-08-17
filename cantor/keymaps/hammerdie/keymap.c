// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layers {
  _QWERTY,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Custom keycodes for layer keys
// Dual function escape with left command


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      *                          QWERTY
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ Ñ │ ´ │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ - │Ent│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Ctr├───┐           ┌───┤Alt│
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤Spc│   │Spc├───┘
      *                       └───┘   └───┘
      */
      /*
      *                          DVORAK
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ . │ , │ Ñ │ P │ Y │       │ F │ G │ C │ H │ L │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ O │ E │ U │ I │       │ D │ R │ T │ N │ S │ ´ │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ - │ Q │ J │ K │ X │       │ B │ M │ W │ V │ Z │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Ctr├───┐           ┌───┤Alt│
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤Spc│   │Spc├───┘
      *                       └───┘   └───┘
      */
    [_QWERTY] = LAYOUT_split_3x6_3(
 //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TAB,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, TD(TD_DIAE),
  //---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TD(TD_CAPLOCK), KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                   KC_N,    KC_M,    TD(TD_PC),TD(TD_DP),TD(TD_SLA),RSFT_T(KC_ENT),
  //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LCTL, LOWER, KC_SPC,     KC_SPC, RAISE, TD(TD_ALT)
                                      //|--------------------------|  |--------------------------|
    ),
    [_DVORAK] = LAYOUT_split_3x6_3(
 //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_ESC,  TD(TD_DP),TD(TD_PC), KC_SCLN, KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_H,    KC_L,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TAB,  KC_A,   KC_O,    KC_E,    KC_U,    KC_I,                          KC_D,    KC_R,    KC_T,    KC_N,    KC_S, TD(TD_DIAE),
  //---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TD(TD_CAPLOCK), TD(TD_SLA),   KC_Q,    KC_J,    KC_K,    KC_X,             KC_B,    KC_M,    KC_W,    KC_V,    KC_Z    ,RSFT_T(KC_ENT),
  //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LCTL, LOWER, KC_SPC,     KC_SPC, RAISE, TD(TD_ALT)
                                      //|--------------------------|  |--------------------------|
    ),
    [_LOWER] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     TD(TD_GRV),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TAB, KC_HOME, XXXXXXX, XXXXXXX, ALGR(KC_LBRC), ALGR(KC_RBRC),          MACRO1, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_END, XXXXXXX, XXXXXXX, ES_LCBR, ES_RCBR,                     XXXXXXX , KC_NUBS, S(KC_NUBS), KC_LEFT,  KC_DOWN, KC_RGHT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         LCTL(KC_LALT), KC_TRNS, KC_SPC,KC_SPC, RAISE,   KC_RALT
                                      //|--------------------------|  |--------------------------|
  ),

   [_RAISE] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     ES_BSLS,  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PIPE, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                               KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSLSKC_PIPE, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LGUI, LOWER, KC_SPC,       KC_SPC, KC_TRNS, KC_RALT
                                      //|--------------------------|  |--------------------------|
  ),

    [_ADJUST] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       QWERTY,  DVORAK,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LCTL, KC_TRNS, KC_SPC,    KC_SPC, KC_TRNS, KC_RALT \
                                      //|--------------------------|  |--------------------------|
  )
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PC] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, LSFT(KC_COMM)), // Tap once for , twice for ;
    [TD_DP] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, LSFT(KC_DOT)),   //Tap one for . twice for :
    [TD_SLA] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, LSFT(KC_SLSH)),//Tap one for - twice for _
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),  //Tap one for Left_Shift twice for Bloq_Mayus
    [TD_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_LALT),      //Tap one for Right_Alt twice for Left_Alt
    [TD_DIAE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, ES_DIAE),      //Tap one for Quote twice for Diaeresis
    [TD_GRV] = ACTION_TAP_DANCE_DOUBLE(ES_MORD, ES_FORD)       //Tap one for º twice for ª
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  //static uint16_t my_colon_timer;

  switch (keycode) {
     case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case MACRO1:
        if (record->event.pressed) {
            SEND_STRING("password");
        } else {
            
        }
        return false;
  }
  return true;
}
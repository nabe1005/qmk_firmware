/* Copyright 2018 MakotoKurauchi
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
#include "keycode.h"
#include "quantum/keymap_extras/keymap_dvorak.h"

#ifdef RGBLIGHT_ENABLE
  extern rgblight_config_t rgblight_config;
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _DVORAK = 0,
    _EUCALYN,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  EISU,
  KANA,
  DVORAK,
  EUCALYN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* DVORAK
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Esc  |   '  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   :  |   Q  |   J  |   K  |   X  |             |   B  |   M  |   W  |   V  |   Z  |Shift |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * | Ctrl | Alt  | GUI  | GUI  | EISU |Lower |Space |Enter |Raise | KANA | GUI  | GUI  |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */

  [_DVORAK] = LAYOUT(
      KC_ESC,  DV_QUOT,  DV_COMM, DV_DOT,  DV_P,  DV_Y,                      DV_F,    DV_G,    DV_C,    DV_R,    DV_L,    KC_BSPC,
      KC_TAB,  DV_A,     DV_O,    DV_E,    DV_U,  DV_I,                      DV_D,    DV_H,    DV_T,    DV_N,    DV_S,    _______,
      KC_LSFT, DV_SCLN,  DV_Q,    DV_J,    DV_K,  DV_X,                      DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,    KC_RSFT ,
      KC_LCTL, KC_LALT,  KC_LGUI, KC_LGUI, EISU,  LOWER,   KC_SPC,  KC_ENT,  RAISE,   KANA,    KC_RGUI, KC_RGUI, _______, _______
      ),

    /* EUCALYN
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Esc  |   Q  |   W  |   ,  |   .  |   ;  |             |   M  |   R  |   D  |   Y  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   A  |   O  |   E  |   U  |   I  |             |   G  |   T  |   K  |   S  |   N  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   F  |             |   B  |   H  |   J  |   L  |   /  |Shift |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * | Ctrl | Alt  | GUI  | GUI  | EISU |Lower |Space |Enter |Raise | KANA | GUI  | GUI  |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */

  [_EUCALYN] = LAYOUT(
      KC_ESC,  DV_Q,     DV_W,    DV_COMM, DV_DOT, DV_QUOT,                   DV_M,    DV_R,    DV_D,    DV_Y,    DV_P,    KC_BSPC,
      KC_TAB,  DV_A,     DV_O,    DV_E,    DV_U,   DV_I,                      DV_G,    DV_T,    DV_K,    DV_S,    DV_N,    _______,
      KC_LSFT, DV_Z,     DV_X,    DV_C,    DV_V,   DV_F,                      DV_B,    DV_H,    DV_J,    DV_L,    DV_SLSH,    KC_RSFT ,
      KC_LCTL, KC_LALT,  KC_LGUI, KC_LGUI, EISU,   LOWER,   KC_SPC,  KC_ENT,  RAISE,   KANA,    KC_RGUI, KC_RGUI, _______, _______
      ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |   0  |   1  |   2  |   3  |  |   |             |   `  |   (  |   )  |   /  |   \  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |   '  |   4  |   5  |   6  |  &   |             |   =  |   [  |   ]  |   _  |   -  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |   7  |   8  |   9  |  ?   |             |   +  |   <  |   >  |      |      |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT(
      _______, DV_0,    DV_1,    DV_2,    DV_3,    DV_PIPE,                   DV_QUOT, DV_LPRN, DV_RPRN, DV_SLSH, DV_BSLS, _______,
      _______, DV_QUOT, DV_4,    DV_5,    DV_6,    DV_AMPR,                   DV_EQL,  DV_LBRC, DV_RBRC, DV_UNDS, DV_MINS, _______,
      _______, _______, DV_7,    DV_8,    DV_9,    DV_QUES,                   DV_PLUS, DV_LABK, DV_RABK, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |   0  |   1  |   2  |   3  |      |             |      |      |  Up  |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |   4  |   5  |   6  |      |             |      | Left | Down | Right|      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |   7  |   8  |   9  |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT(
      _______, DV_0,    DV_1,    DV_2,    DV_3,    _______,                   _______, _______, KC_UP,   _______, _______, _______,
      _______, _______, DV_4,    DV_5,    DV_6,    _______,                   _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
      _______, _______, DV_7,    DV_8,    DV_9,    _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),  /* Raise

  /* Aujust
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |Dvorak|      |      |      |      |      |             |      |      |      |      |      |EUCALYN|
   * |------+------+------+------+------+------|             |------+------+------+------+------+-------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |       |
   * |------+------+------+------+------+------|             |------+------+------+------+------+-------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |       |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+-------|
   * |      |      |      |      |      |      |RESET |      |      |      |      |      |      |       |
   * `--------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT(
      DVORAK,  _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, EUCALYN,
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______
      ),
};

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      rgblight_mode(RGB_current_mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case EUCALYN:
      if (record->event.pressed) {
        rgblight_mode(RGBLIGHT_MODE_TWINKLE);
        persistent_default_layer_set(1UL<<_EUCALYN);
      }
    case RAISE:
      if (record->event.pressed) {
        if (!TOG_STATUS) {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode(RGBLIGHT_MODE_SNAKE + 1);
          #endif
        }
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(RGBLIGHT_MODE_SNAKE);
        #endif
        layer_off(_RAISE);
        TOG_STATUS = false;
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        if (!TOG_STATUS) {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode(RGBLIGHT_MODE_SNAKE + 1);
          #endif
        }
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(RGBLIGHT_MODE_SNAKE);
        #endif
        layer_off(_LOWER);
        TOG_STATUS = false;
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case EISU:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LNG2);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LNG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LNG1);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LNG1);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
}

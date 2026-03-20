// Copyright 2019 @foostan
// Copyright 2020 Drashna Jaelre <@drashna>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Layer 0: Base (QWERTY)
  [0] = LAYOUT_split_3x6_3(
    MT(MOD_LGUI, KC_ESC),   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    MT(MOD_RGUI, KC_LBRC),
    LCTL_T(KC_TAB),          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MT(MOD_RCTL, KC_QUOT),
    KC_LALT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
                    LT(1, KC_BSPC), LSFT_T(KC_SPC), LT(2, KC_ENT),           LT(2, KC_ENT), RSFT_T(KC_SPC), LT(1, KC_DEL)
  ),

  // Layer 1: Symbols & Numbers
  [1] = LAYOUT_split_3x6_3(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
    KC_LALT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_INS,
                      KC_TRNS, KC_TRNS, LT(3, KC_ENT),         LT(3, KC_ENT), KC_TRNS, KC_TRNS
  ),

  // Layer 2: Navigation & Numpad
  [2] = LAYOUT_split_3x6_3(
    KC_GRV,  KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,      KC_EQL,  KC_HOME, KC_UP,   KC_PGUP, KC_MPRV, KC_LGUI,
    _______, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,      KC_VOLU, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, KC_BSLS,
    KC_NUM,  KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PCMM,      KC_VOLD, KC_END,  KC_PSCR, KC_PGDN, KC_MNXT, KC_RCTL,
                      LT(3, KC_BSPC), KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, LT(3, KC_DEL)
  ),

  // Layer 3: RGB & System
  [3] = LAYOUT_split_3x6_3(
    RGB_MODE_PLAIN, AS_DOWN, AS_TOGG, AS_UP,   QK_BOOT, _______,      _______, QK_BOOT,  AS_DOWN, AS_TOGG, AS_UP,   RGB_MODE_PLAIN,
    RGB_TOG,        RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,      RGB_MOD, RGB_SPI,  RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG,
    _______,        RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_RMOD,     RGB_RMOD,RGB_SPD,  RGB_VAD, RGB_SAD, RGB_HUD, _______,
                             _______, _______, _______,                _______, _______,  _______
  )
};

#include "oled.c"

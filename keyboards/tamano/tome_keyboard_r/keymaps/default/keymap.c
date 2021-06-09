/* Copyright 2021 Yuya TAMANO
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FUNC,
    _NUM
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
                                KC_KP_7,   KC_KP_8,   KC_KP_9,
                                KC_KP_4,   KC_KP_5,   KC_KP_6,
        KC_LSHIFT,   KC_LCTRL,  KC_KP_1,   KC_KP_2,   KC_KP_3,
        MO(_NUM),    MO(_FUNC), KC_KP_0,   KC_I,      KC_M
    ),
    [_FUNC] = LAYOUT(
                                KC_F7,     KC_F8,     KC_F9,
                                KC_F4,     KC_F5,     KC_F6,
        KC_TRNS,     KC_TRNS,   KC_F1,     KC_F2,     KC_F3,
        KC_TRNS,     KC_TRNS,   KC_F10,    KC_TRNS,   KC_TRNS
    ),
    [_NUM] = LAYOUT(
                                KC_7,      KC_8,      KC_9,
                                KC_4,      KC_5,      KC_6,
        KC_TRNS,     KC_TRNS,   KC_1,      KC_2,      KC_3,
        KC_TRNS,     KC_TRNS,   KC_0,      KC_TRNS,   KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

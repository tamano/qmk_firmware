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
    _L2,
    _L3,
    _L4
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_F13, KC_F14, KC_F15, KC_F16, TO(_L2)
    ),
    [_L2] = LAYOUT(
        KC_F17, KC_F18, KC_F19, KC_F20, TO(_BASE)
    ),
    [_L3] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, TO(_BASE)
    ),
    [_L4] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, TO(_BASE)
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

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

void oled_task_user(void) {
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("1"), false);
            break;
        case _L2:
            oled_write_P(PSTR("2"), false);
            break;
        case _L3:
            oled_write_P(PSTR("3"), false);
            break;
        case _L4:
            oled_write_P(PSTR("4"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    oled_write_P(PSTR("\n"), false);
}
#endif
#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

#define EJR_LAYER_DVORAK 0
#define EJR_LAYER_ONE    1
#define EJR_LAYER_TWO    2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ???  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ???  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[EJR_LAYER_DVORAK] = LAYOUT( \
 KC_GRV,  KC_A,    KC_2,    KC_3,    KC_4,   KC_5,                      KC_6,  KC_7,  KC_8,  KC_9,  KC_0, KC_EQL, \
 KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,   KC_Y,                      KC_F,  KC_G,  KC_C,  KC_R,  KC_L, KC_SLSH, \
 KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,   KC_I,                      KC_D,  KC_H,  KC_T,  KC_N,  KC_S, KC_MINS, \
 KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,   KC_X,  KC_LBRC,  KC_RBRC,  KC_B,  KC_M,  KC_W,  KC_V,  KC_Z, KC_RSFT, \
                    KC_LALT, KC_LGUI,    MO(1),    KC_ENT,        KC_SPC,    MO(2),    KC_BSPC,    KC_RGUI
),

[EJR_LAYER_ONE] = LAYOUT( \
 _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, \
 KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,            KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
 KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, \
 _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
 _______, _______, _______, _______,                      _______, TO(3), _______, _______
),

[EJR_LAYER_TWO] = LAYOUT( \
 _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, \
 KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                             KC_6, KC_7, KC_8, KC_9, KC_0, _______, \
 KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                          XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, \
 KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, KC_PLUS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, \
 _______, _______, TO(3), _______, _______, _______, _______, _______ \
),

	[3] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(0), OSL(4), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_DOWN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL, XXXXXXX, XXXXXXX, LCTL(KC_LEFT), XXXXXXX, LCTL(KC_RGHT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX),
	[4] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(3), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 454, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCTL(LSFT(KC_RGHT)), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)
};

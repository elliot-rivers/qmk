#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif


extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define EJR_VIM_G_DURATION 700

#define EJR_L_DVORAK     0
#define EJR_L_ONE        1
#define EJR_L_TWO        2
#define EJR_L_VIM        3
#define EJR_L_VIM_SHIFT  4
#define EJR_L_VIM_CTRLON 5

#define LV   EJR_L_VIM
#define LVS  EJR_L_VIM_SHIFT
#define LVC  EJR_L_VIM_CTRLON

enum custom_keycodes {
  VIM_1 = SAFE_RANGE,
  VIM_2,   // done
  VIM_3,   // done
  VIM_4,   // done
  VIM_5,   // done
  VIM_6,   // done
  VIM_7,   // done
  VIM_8,   // done
  VIM_9,   // done
  VIM_a,   // done
  VIM_A,   // done
  VIM_o,   // done
  VIM_O,   // done
  VIM_I,   // done
  VIM_i,   // done
  VIM_d,   // done
  VIM_D,   // done
  VIM_g,   // done
  VIM_ENT, // done
  VIM_MIN, // done
  VIM_y,
  VIM_x,   // done
  VIM_w,   // done* need y 
  VIM_b,   // done* -- no delete backwards capability
  VIM_ESC,
  VIM_T,  // done
  VIM_tj, // done
  VIM_c,  // done
  VIM_C,  // done
  VIM_FSL, // done
  VIM_Cw, // done
  VIM_Ce, // done
  VIM_NULL, // unused -- indicates safe null value
};

// Pound defines for easy translations
//#define VIM_i TG(EJR_L_VIM)
#define VIM_h KC_LEFT
#define VIM_j KC_DOWN
#define VIM_k KC_UP
#define VIM_l KC_RIGHT
#define VIM_u LCTL(KC_Z)
#define VIM_SPC KC_RIGHT
#define VIM_CR LCTL(KC_Y)
#define VIM_CLN TO(EJR_L_VIM_CTRLON)
#define VIM_SFT MO(EJR_L_VIM_SHIFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * | LCtl |   :  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  | Enter|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |SHIFT | / MO(1) /       \MO(2) \  |Space |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [EJR_L_DVORAK] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL, \
  KC_TAB,   KC_QUOT,KC_COMM, KC_DOT,  KC_P,    KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, \
  KC_ESC,   KC_A,   KC_O,    KC_E,    KC_U,    KC_I,                     KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, \
  KC_LCTL,  KC_SCLN,KC_Q,    KC_J,    KC_K,    KC_X, KC_LBRC,  KC_RBRC,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT, \
                             KC_LALT, KC_LGUI, LSFT_T(KC_SPC), MO(1),   MO(2), KC_SPC,   KC_BSPC,  KC_RGUI \
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | VIM  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[EJR_L_ONE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,\
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  TO(LV),  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, \
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
                             _______, _______, _______, _______, _______,  _______, _______, _______\
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | Ins  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right | Entr |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[EJR_L_TWO] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, KC_INS, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT, \
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),

/* VIM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |   y  |                    |      |   g  |      |   r  |      |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   a  |   o  |      |   u  |   i  |-------.    ,-------|   d  |   h  |   t  |   n  |   s  |  -   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   :  |      |   j  |   k  |   x  |-------|    |-------|   b  |      |   w  |      |   z  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |SHIFT | / MO(1) /       \MO(2) \  |Space |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [EJR_L_VIM] = LAYOUT( \
  XXXXXXX, VIM_1,   VIM_2,   VIM_3,   VIM_4,   VIM_5,                     VIM_6,   VIM_7,   VIM_8,   VIM_9,   XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, VIM_y,                     XXXXXXX, VIM_g,   VIM_c,   XXXXXXX, XXXXXXX, VIM_FSL, \
  VIM_ESC, VIM_a,   VIM_o,   XXXXXXX, VIM_u,   VIM_i,                     VIM_d,   VIM_h,   VIM_tj,   VIM_k,   VIM_l,   VIM_MIN, \
  MO(LVC), VIM_CLN, XXXXXXX, VIM_j,   VIM_k,   VIM_x,   XXXXXXX, XXXXXXX, VIM_b,   XXXXXXX, VIM_w,   XXXXXXX, KC_Z,    VIM_ENT, \
                             XXXXXXX, XXXXXXX, VIM_SFT, MO(1),   MO(2),   VIM_SPC, XXXXXXX, XXXXXXX \
),

/* VIM SHIFT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  A   |  O   |      |      |  I   |-------.    ,-------|      |      |   T  |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |  __  | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[EJR_L_VIM_SHIFT] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, VIM_C,   XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, VIM_A,   VIM_O,   XXXXXXX, XXXXXXX, VIM_I,                     XXXXXXX, XXXXXXX, VIM_T,   XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                             XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
  ),

/* VIM CTRL and colon
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |   r  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Esc |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  \/  |      |      |      |      |      |-------|    |-------|      |      |   w  |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      | Enter|      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[EJR_L_VIM_CTRLON] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, VIM_CR,  XXXXXXX, XXXXXXX, \
  TG(LVC), XXXXXXX, XXXXXXX, VIM_Ce,  XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, VIM_Cw,  XXXXXXX, XXXXXXX, XXXXXXX, \
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(LVC), XXXXXXX \
  )

};

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

uint16_t vim_number = 1;
uint16_t vim_command = VIM_NULL;
uint16_t vim_g_timer = 0;
bool is_vim_g = false; // use this for safety

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#if OLED_DRIVER_ENABLE
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
#endif

  switch(keycode)
  {
    case VIM_MIN:
      // "-" -> up, home
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_UP) SS_TAP(X_HOME));
      }
      return false;

    case VIM_ENT:
      // "enter" -> down, home
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_DOWN) SS_TAP(X_HOME));
      }
      return false;

    case VIM_a:
      // "a" -> right, insertmode
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_RIGHT));
        layer_off(EJR_L_VIM);
      }
      return false;

    case VIM_A:
      // "A" -> end, insertmode
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_END));
        layer_off(EJR_L_VIM);
      }
      return false;

    case VIM_O:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_UP));
      } // fallthrough

    case VIM_o:
      // "o" -> end, new-line, insertmode
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_END) "\n");
        layer_off(EJR_L_VIM);
      }
      return false;

    case VIM_i:
      if (record->event.pressed) {
        if (vim_command == VIM_d || vim_command == VIM_c) {
          // inner
          SEND_STRING(SS_TAP(X_LEFT));
        }
        else {
          // insert
          layer_off(EJR_L_VIM);
        }
      }
      return false;

    case VIM_I:
      // "I" -> home, insertmode
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_HOME));
        layer_off(EJR_L_VIM);
      }
      return false;

    case VIM_g:
      // "g" to be followed by t or T
      if (record->event.pressed) {
        if (vim_command != VIM_g) {
          register_code(KC_LALT);
        }
        vim_g_timer = timer_read();
        vim_command = VIM_g;
        is_vim_g = true;
      }
      return false;

    case VIM_tj:
      if (record->event.pressed) {
        if (vim_command == VIM_g) {
          SEND_STRING("\t");
          vim_g_timer = timer_read();
          vim_command = VIM_NULL;
        }

        else {
          SEND_STRING(SS_TAP(X_DOWN));
        }
      }
      return false;

    case VIM_T:
      if ((record->event.pressed) && (vim_command == VIM_g)) {
        SEND_STRING(SS_LSFT("\t"));
        vim_g_timer = timer_read();
        vim_command = VIM_NULL;
      }
      return false;

    case VIM_1:
    case VIM_2:
    case VIM_3:
    case VIM_4:
    case VIM_5:
    case VIM_6:
    case VIM_7:
    case VIM_8:
    case VIM_9:
      if (record->event.pressed) {
        vim_number = (keycode - VIM_1) + 1;
      }
      return false;

    case VIM_C:
    case VIM_D:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_TAP(X_DELETE));
        if (keycode == VIM_C) {
          layer_off(EJR_L_VIM);
        }
        vim_number = 1;
        return false;
      }

    case VIM_b:
      // TODO add delete handling like VIM_w
      if (record->event.pressed) {
        register_code(KC_LCTL);
        for (int16_t ii = 0; ii < vim_number; ii++) {
          SEND_STRING(SS_TAP(X_LEFT));
        }
        unregister_code(KC_LCTL);
        vim_number = 1;
        return false;
      }

    case VIM_w:
      if (record->event.pressed) {
        if (vim_command == VIM_d || vim_command == VIM_c) {
          register_code(KC_LSFT);
        }

        register_code(KC_LCTL);
        for (int16_t ii = 0; ii < vim_number; ii++) {
          SEND_STRING(SS_TAP(X_RIGHT));
        }
        unregister_code(KC_LCTL);

        if (vim_command == VIM_d || vim_command == VIM_c) {
          unregister_code(KC_LSFT);
          SEND_STRING(SS_TAP(X_DELETE));
        }

        if (vim_command == VIM_c) {
          layer_off(EJR_L_VIM);
        }

        vim_number = 1;
        vim_command = VIM_NULL;
        return false;
      }

    case VIM_c:
      if (record->event.pressed) {
        if (vim_command == VIM_NULL) {
          // This is the first d
          vim_command = VIM_c;
        }
        return false;
      }

    case VIM_d:
      if (record->event.pressed) {
        // dd 3dd d3w dw
        // 11  33 1   1
        // nd  nd n   n
        if (vim_command == VIM_NULL) {
          // This is the first d
          vim_command = VIM_d;
        }
        else if (vim_command == VIM_d) {
          // This is the second d

          SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_HOME));
          register_code(KC_LSFT);
          for (int16_t ii = 0; ii < vim_number; ii++) {
            SEND_STRING(SS_TAP(X_DOWN));
          }
          unregister_code(KC_LSFT);
          SEND_STRING(SS_TAP(X_DELETE));

          vim_number = 1;
          vim_command = VIM_NULL;
        }

        return false;
      }

    case VIM_x:
      // TODO add delete handling like VIM_w
      if (record->event.pressed) {
        for (int16_t ii = 0; ii < vim_number; ii++) {
          SEND_STRING(SS_TAP(X_DELETE));
        }
        vim_number = 1;
        return false;
      }

    case VIM_FSL:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_TAP(X_F)));
        layer_off(EJR_L_VIM);
        return false;
      }

    case VIM_Ce:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_TAP(X_O)));
        layer_off(EJR_L_VIM);
        return false;
      }

    case VIM_Cw:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_TAP(X_F)));
        layer_off(EJR_L_VIM);
        return false;
      }

  }
  return true;
}

void matrix_scan_user(void) {
  if (is_vim_g) {
    if (timer_elapsed(vim_g_timer) > EJR_VIM_G_DURATION) {
      unregister_code(KC_LALT);
      //vim_command = VIM_NULL;
      is_vim_g = false;
      layer_off(EJR_L_VIM);
    }
  }
}

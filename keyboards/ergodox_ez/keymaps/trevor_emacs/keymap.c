#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "./macros.h"

enum
{
    BASE,
    SYMB,
    NUMPAD
};

enum
{
    PASSWORD,
    EMAIL1,
    EMAIL2,
    EMAIL3
};

// Tap dances
/*enum
{
    TD_DT_LBRC,
    TD_DT_RBRC
};*/

// Tap Dance Definitions
/*qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_DT_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_LBRC),
    [TD_DT_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RCBR, KC_RBRC),
};*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  | CUT  |           |  DEL |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  | COPY |           | VOLUP|   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |A/Shft|   S  |   D  |   F  | G/L3 |------|           |------|   H  |   J  |   K  |   L  |;/Shft|        |
 * |--------+------+------+------+------+------| PASTE|           | VOLDN|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |   `  |      |      |      |                                       |  ENT |   -  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | RESET| LGui |       |Cmd/Del|Alt/Del|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Alt  |       | Mute |        |      |
 *                                 | Space|  L2  |------|       |------|  Cmd   |Backsp|
 *                                 |      |      | Cmd  |       | Ctrl |        |      |
 *                                 `--------------------'       `----------------------'
 */
    // If it accepts an argument (i.e, is a function), it doesn't need KC_.
    // Otherwise, it needs KC_*
    [BASE] = LAYOUT_ergodox( // layer 0 : default
        // left hand
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, LGUI(KC_X),
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, LGUI(KC_C),
        KC_NO, LSFT_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), LT(NUMPAD, KC_G),
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, LGUI(KC_V),
        KC_LCTRL, KC_GRAVE, KC_NO, KC_NO, KC_NO,

        RESET, KC_TRNS,
        KC_LALT,
        KC_SPC, MO(1), KC_LGUI,

        // right hand
        KC_DEL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL,
        KC_VOLU, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_H, RCTL_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RSFT_T(KC_SCLN), KC_QUOT,
        KC_VOLD, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_ENT, KC_MINS, KC_NO, KC_NO, KC_NO,

        LGUI(KC_DEL), LALT(KC_DEL),
        KC_MUTE,
        KC_LCTL, MO(1), KC_BSPACE),

    /* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | BSPC |  UP  |  ENT |      |      |           |      |      |   <  |   >  |      |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | LEFT | DOWN | RIGHT|      |------|           |------|      |   {  |   }  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   [  |   ]  |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    // SYMBOLS
    [SYMB] = LAYOUT_ergodox(
        // left hand
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_BSPC, KC_GT, KC_ENT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, KC_TRNS,
        KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,

        // right hand
        KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_MNXT, KC_TRNS, KC_LT, KC_GT, KC_TRNS, KC_TRNS, KC_F12,
        KC_TRNS, KC_RCBR, KC_RPRN, KC_RBRC, KC_GT, KC_TRNS,
        KC_MPRV, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS,
        M(EMAIL1), M(EMAIL2), M(EMAIL3), KC_TRNS, M(PASSWORD),

        KC_TRNS, KC_TRNS,
        KC_MPLY,
        KC_TRNS, KC_TRNS, KC_TRNS),

    /* Keymap 2: Numpad Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |   /  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |   +  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   .  |  ENT |  ENT |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    // Numpad
    [NUMPAD] = LAYOUT_ergodox(
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,

        // right hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLSH, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_7, KC_8, KC_9, KC_ASTR, KC_TRNS,
        KC_TRNS, KC_4, KC_5, KC_6, KC_MINS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_PLUS, KC_TRNS,
        KC_0, KC_DOT, KC_ENT, KC_ENT, KC_TRNS,

        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS),

};

//const uint16_t PROGMEM fn_actions[] = {
//[1] = ACTION_LAYER_TAP_TOGGLE(SYMB) // FN1 - Momentary Layer 1 (Symbols)
//};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch (id)
    {
    case PASSWORD:
        if (record->event.pressed)
        {
            SEND_STRING(MACRO_1);
        }
        break;
    case EMAIL1:
        if (record->event.pressed)
        {
            SEND_STRING(MACRO_2);
        }
        break;
    case EMAIL2:
        if (record->event.pressed)
        {
            SEND_STRING(MACRO_3);
        }
        break;
    case EMAIL3:
        if (record->event.pressed)
        {
            SEND_STRING(MACRO_4);
        }
        break;
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void){

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void)
{

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer)
    {
    // TODO: Make this relevant to the ErgoDox EZ.
    case 1:
        ergodox_right_led_3_on();
        break;
    case 2:
        ergodox_right_led_1_on();
        break;
    default:
        // none
        break;
    }
};

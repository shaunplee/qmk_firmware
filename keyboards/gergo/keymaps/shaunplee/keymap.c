/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion
#define NUMPAD 3 // number pad
#define MOUSE 4 // mouse layer

// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |NMPD/Tab|   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |  [     |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |  D   |   F  |   G  | MOUSE|           | Ins  |   H  |   J  |   K  |   L  | ;  : | '/RCtL |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | Esc  |           | Del  |   N  |   M  | ,  < | . >  | /  ? |\ / RSft|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .---------.                                 .-----------.   .-----.
 *                    | Gui      |   |SYMB/Menu|                                 | SYMB/PgDn |   |PgUp |
 *                    '----------'   '---------'                                 `-----------.   '-----'
 *                                        ,-------.                      ,-------.
 *                                        |GuiCtrl|                      |NUMPAD |
 *                                 ,------|-------|                      |-------|------.
 *                                 | NUMB | Alt   |                      | Bksp  | NUMB |
 *                                 | Space|       |                      |       |Enter |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[BASE] = LAYOUT_gergo(
    LT(NUMPAD, KC_TAB),     KC_Q,  KC_W,   KC_E,   KC_R, KC_T,                                             KC_Y,    KC_U, KC_I, KC_O,   KC_P,    KC_LBRC,
    KC_LCTL,                KC_A,  KC_S,   KC_D,   KC_F, KC_G, MO(MOUSE),                        KC_INS,   KC_H,    KC_J, KC_K, KC_L,   KC_SCLN, RCTL_T(KC_QUOT),
    KC_LSFT,                KC_Z,  KC_X,   KC_C,   KC_V, KC_B, KC_ESC, LGUI(KC_LCTL),  TG(NUMPAD), KC_DEL,   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_PIPE),
              MT(MOD_LGUI, KC_DEL), LT(SYMB, KC_APP), LT(NUMB, KC_SPC), KC_LALT,     KC_BSPC,    LT(NUMB, KC_ENT), LT(SYMB, KC_PGDN), KC_PGUP
    ),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |  ~     |  !   |  @   |  #   |  $   |  |   |                         |   ^  |  &   |  *   |  (   |   )  |  /     |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  [   |  ]   |  -   |  =   |  (   |      |           |      |   )  |  -   |  =   |  [   |  ]   |  |     |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  {   |  }   |  _   |  +   |  `   |      |           |      |      |  _   |  +   |  {   |  }   |  \     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[SYMB] = LAYOUT_gergo(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_SLSH,
    KC_TRNS, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_LPRN, KC_TRNS,                          KC_TRNS, KC_RPRN, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PIPE,
    KC_TRNS, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, KC_GRV,  KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_NO,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  F1  | F2   | F3   | F4   | F5   |      |           | F11  |      | LEFT | DOWN |  UP  | RIGHT|        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  F6  | F7   | F8   | F9   | F10  |      |           | F12  |      | HOME | PGDN | PGUP | END  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |CtrPD |   |CtrPU|
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[NUMB] = LAYOUT_gergo(
    KC_TRNS, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,                             KC_F11,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
    KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_NO,   KC_TRNS,         KC_TRNS, KC_F12,   KC_NO,  KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,  LCTL(KC_PGDN), LCTL(KC_PGUP)
    ),

/* Keymap 3: Numpad layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        | NLCK |  7   |  8   |  9   |  -   |                         | NLCK |  7   |  8   |  9   |  -   |    /   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |  4   |  5   |  6   |  +   |  /   |           |      |      |  4   |  5   |  6   |  +   |    *   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |  1   |  2   |  3   |  ,   |  *   |           |      |   ,  |  1   |  2   |  3   |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |  0   |   |  .   |                                 |  .   |   |  0  |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 */
[NUMPAD] = LAYOUT_gergo(
    KC_TRNS, KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,                                             KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PSLS,
    KC_TRNS, KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PSLS,                           KC_TRNS, KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAST,
    KC_TRNS, KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_PCMM, KC_PAST, KC_TRNS,         KC_TRNS, KC_TRNS, KC_PCMM, KC_P1,   KC_P2,   KC_P3,   KC_TRNS, KC_TRNS,
                                        KC_P0,   KC_PDOT, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_PDOT, KC_P0
                        ),

/* Keymap 4: mouse layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      | MUP  |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | MLT  | MDN  | MRT  |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 | BTN2 |   |BTN3 |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        | ACC2  |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 | ACC0 | ACC1  |       |       |BTN1  |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
*/
[MOUSE] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL2,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1,         KC_TRNS, KC_BTN1, KC_BTN2, KC_BTN3
                       )
};


/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
*/

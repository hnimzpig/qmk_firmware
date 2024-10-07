#include QMK_KEYBOARD_H

enum layers{
  _BASE,
  _NUM_SYM,
  _NAV,
  _4
};
enum combo_events {
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_COMM,
  COMBO_M3,
};

#define KC_NUM_SPC LT(_NUM_SYM, KC_SPC)
#define KC_GA LGUI_T(KC_A)
#define KC_CD LCTL_T(KC_D)
#define KC_SZ LSFT_T(KC_Z)
#define KC_SDOT RSFT_T(KC_DOT)
#define KC_CK RCTL_T(KC_K)
#define KC_AL RALT_T(KC_L)
#define KC_GSCLN RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_space(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,     KC_P,
    KC_A,  KC_S,  KC_D,  KC_F,   KC_G,   KC_H,  KC_J,   KC_K,  KC_L, KC_ENT,
    KC_SZ,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMMA, KC_SDOT,
    KC_LCTL, KC_LALT, KC_LGUI, LT(_NAV,KC_SPACE), LT(_NUM_SYM,KC_SPACE), KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_NUM_SYM] = LAYOUT_split_space(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQUAL, KC_MINS,
    KC_LEFT_SHIFT, KC_LBRC, KC_LPRN, KC_UNDS, KC_RPRN, KC_RBRC, KC_SCLN, KC_UP, KC_RIGHT_SHIFT,
    RGB_TOG, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_NAV] = LAYOUT_split_space(
    KC_GRAVE, KC_PIPE, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQUAL, KC_SCLN,
    KC_LEFT_SHIFT, KC_LBRC, KC_LPRN, KC_UNDS, KC_RPRN, KC_RBRC, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2,
    RGB_TOG, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT
  ),

  [_4] = LAYOUT_split_space(
    KC_GRAVE, KC_PIPE, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQUAL, KC_SCLN,
    KC_LEFT_SHIFT, KC_LBRC, KC_LPRN, KC_UNDS, KC_RPRN, KC_RBRC, KC_COMM, KC_SLASH, KC_RIGHT_SHIFT,
    RGB_TOG, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_P, KC_O, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_comm[] = {KC_DOWN, KC_RIGHT , COMBO_END};
const uint16_t PROGMEM combo_m3[] = {KC_X, KC_C , COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_COMM] = COMBO(combo_comm,KC_COMM),
  [COMBO_M3] = COMBO(combo_m3,MO(3)),
};
#endif

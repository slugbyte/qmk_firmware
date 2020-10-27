/* Copyright 2020 Duncan Marsh <duncan@slugbyte.com>
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

/*
 * a WORKMXN keymap by slugbyte for slugbyte
 * 
 * keymap goals 
 * 0) apply the workmxn layout philosophy to every layer
 * 2) be able to access all essential keys
 * 3) easy to type numbers (phone keypad style)
 * 4) (explicit rule 0) arrange symbols based on fequency of use and ease of typing!
 * 5) logicaly group symbols (braces, math, logic, quotes, punctuation, other)
 * 6) include a gamepad layer
 * 7) make this file easy to read and edit
 */

#include QMK_KEYBOARD_H
#include "alias.h"

enum layers {
    _WORKMXN = 0,
    _NUMBER,
    _SYMBOL,
    _NAVIGATION,
    _FUNCTION,
    _GAMEPAD,
    _GAMENUM,
};


// CUSTOM KEYS
enum {
  INSERT_GAMEPAD,
  OPEN_PAREN_ARROW,
  CLOSE_PAREN_ARROW,
};

void open_paren_arrow_finised(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code16(S_LPR);
    return;
  } 
};

void open_paren_arrow_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code16(S_LPR);
    return;
  } else {
    SEND_STRING("->");
    return;
  }
};

void close_paren_arrow_finised(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code16(S_RPR);
    return;
  } 
};

void close_paren_arrow_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code16(S_RPR);
    return;
  } else {
    SEND_STRING("=>");
    return;
  }
};

void insert_gamepad_finised(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(A_INS);
    return;
  } 
};

void insert_gamepad_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(A_INS);
    return;
  } 
  if (state->count == 5) {
    layer_on(_GAMEPAD);
    return;
  }
};

// TAP DANCE
qk_tap_dance_action_t tap_dance_actions[] = {
   [INSERT_GAMEPAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, insert_gamepad_finised, insert_gamepad_reset),
   [OPEN_PAREN_ARROW] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, open_paren_arrow_finised, open_paren_arrow_reset),
   [CLOSE_PAREN_ARROW] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, close_paren_arrow_finised, close_paren_arrow_reset),
};

// ALIASES SPECIFIC TO THE SLUGBYTE KEYMAP
// --- LAYER KEYS
#define Y_NUM LT(_NUMBER, S_SPC)             // _NUMBER when held, space when tapped
#define Y_SYM LT(_SYMBOL, S_SPC)             // _SYMBOL when held, space when tapped
#define Y_NAV LT(_NAVIGATION, A_BSP)         // _NAVIGATION when held, backspace when tapped
#define Y_FUN LT(_FUNCTION, A_DEL)           // _FUNCTION when held, del when tapped
#define Y_GAM TD(INSERT_GAMEPAD)
#define Y_WRK TO(_WORKMXN)

// --- MOD TAP
#define Y_ENT LCTL_T(A_ENT) // control when held, enter when tapped
#define Y_ESC LCTL_T(A_ESC) // control when held, escape when tapped
#define Y_SQT LCTL_T(S_SQT) // control when held, single quote when tapped
#define Y_DOT LCTL_T(S_DOT) // control when held, single quote when tapped

// --- MOD + KEY
#define Y_NXT LCTL(A_TAB) // next tab (browser)
#define Y_PRV RCS(A_TAB)  // prev tab (browser)


// -- GAMEING
#define G_CTL LCTL_T(S_SPC)
#define G_SFT LCTL_T(A_ENT)
#define G_NUM MO(_GAMENUM)

// -- TAP DANCE
#define Y_LPR TD(OPEN_PAREN_ARROW)
#define Y_RPR TD(CLOSE_PAREN_ARROW)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WORKMXN] = LAYOUT(
      A_TAB, __Q__, __D__, __R__, __W__, __B__,                                      __J__, __F__, __U__, __P__, S_SEM, A_BSP,
      Y_ESC, __A__, __S__, __H__, __T__, __G__,                                      __Y__, __N__, __E__, __O__, __I__, S_SQT,
      Y_ENT, __Z__, __X__, __M__, __C__, __V__,    M_ALT, M_SFT,    A_CPY, A_PUT,    __K__, __L__, S_COM, S_DOT, S_FSL, Y_ENT,
                           Y_FUN, Y_ENT, M_SFT,    M_SUP, M_ALT,    Y_NAV, Y_NUM,    Y_SYM, Y_ENT, Y_GAM
    ),
    [_NUMBER] = LAYOUT(
      _____, S_MUL, S_ADD, S_SUB, S_UND, XXXXX,                                       S_ADD, N_1__, N_2__, N_3__, S_SUB, _____,
      _____, S_LAB, S_RAB, S_LPR, S_RPR, S_SPC,                                       S_EQL, N_4__, N_5__, N_6__, N_0__, S_DOT,
      _____, S_LSB, S_RSB, S_LCB, S_RCB, XXXXX,    _____, _____,     _____, _____,    S_MUL, N_7__, N_8__, N_9__, S_DIV, _____,
                           _____, _____, _____,    _____, _____,     _____, _____,    _____, _____, _____
    ),
    [_SYMBOL] = LAYOUT(
      S_BSL, S_MUL, S_ADD, S_SUB, S_UND, A_ESC,                                       S_AT_, S_SQT, S_DQT, S_BQT, S_XOR, _____,
      S_FSL, S_LAB, S_RAB, Y_LPR, Y_RPR, S_EQL,                                       S_TIL, S_SEM, S_AND, S_OR_, S_NOT, S_MOD,
      _____, S_LSB, S_RSB, S_LCB, S_RCB, S_MON,    _____, _____,     _____, _____,    S_HSH, S_COL, S_COM, S_DOT, S_HUH, _____,
                           _____, _____, _____,    _____, _____,     _____, _____,    _____, _____, _____
    ),
    [_NAVIGATION] = LAYOUT(
      _____, A_CPY, XXXXX, A_UUU, XXXXX, XXXXX,                                       A_END, A_PDN, A_PUP, A_HOM, A_CPY, _____,
      _____, A_PUT, A_LLL, A_DDD, A_RRR, XXXXX,                                       A_LLL, A_DDD, A_UUU, A_RRR, A_PUT, _____,
      _____, A_CUT, XXXXX, Y_PRV, Y_NXT, XXXXX,    _____, _____,     A_RED, A_UND,    XXXXX, Y_PRV, Y_NXT, XXXXX, A_CUT, _____,
                           _____, _____, _____,    _____, _____,     _____, _____,    _____, _____, _____
    ),
    [_FUNCTION] = LAYOUT(
      _____, F_01_, F_02_, F_03_, F_04_, XXXXX,                                       XXXXX, F_01_, F_02_, F_03_, F_04_, _____,
      _____, F_05_, F_06_, F_07_, F_08_, XXXXX,                                       XXXXX, F_05_, F_06_, F_07_, F_08_, _____,
      _____, F_09_, F_10_, F_11_, F_12_, XXXXX,    XXXXX, XXXXX,     XXXXX, XXXXX,    XXXXX, F_09_, F_10_, F_11_, F_12_, _____,
                           XXXXX, XXXXX, XXXXX,    XXXXX, XXXXX,     XXXXX, XXXXX,    XXXXX, XXXXX, XXXXX
    ),
    [_GAMEPAD] = LAYOUT(
      A_TAB, A_ESC, __Q__, __W__, __E__, __R__,                                        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
      G_SFT, G_CTL, __A__, __S__, __D__, __F__,                                        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
      G_CTL, G_CTL, __Z__, __X__, __C__, __V__,     XXXXX, XXXXX,     XXXXX, XXXXX,    XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
                            Y_FUN, M_SUP, G_SFT,    G_CTL, G_NUM,     XXXXX, XXXXX,    XXXXX, XXXXX, Y_WRK
    ),
    [_GAMENUM] = LAYOUT(
      _____, _____, N_1__, N_2__, N_3__, XXXXX,                                        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
      _____, N_0__, N_4__, N_5__, N_6__, A_BSP,                                        XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
      _____, S_DOT, N_7__, N_8__, N_9__, XXXXX,    XXXXX, XXXXX,     XXXXX, XXXXX,     XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
                           XXXXX, _____, _____,    _____, _____,     XXXXX, XXXXX,     XXXXX, XXXXX, XXXXX 
    ),
};

//    [_LAYERINDEX] = LAYOUT(
//      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                                       XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
//      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                                       XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
//      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,    XXXXX, XXXXX,     XXXXX, XXXXX,    XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
//                           XXXXX, XXXXX, XXXXX,    XXXXX, XXXXX,     XXXXX, XXXXX,    XXXXX, XXXXX, XXXXX
//    ),

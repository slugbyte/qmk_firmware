/* Copyright 2020 Duncan Marsh <duncan@slugbyte.com>
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

#define XL_A__ KC_A
#define XL_B__ KC_B
#define XL_C__ KC_C
#define XL_D__ KC_D
#define XL_E__ KC_E
#define XL_F__ KC_F
#define XL_G__ KC_G
#define XL_H__ KC_H
#define XL_I__ KC_I
#define XL_J__ KC_J
#define XL_K__ KC_K
#define XL_L__ KC_L
#define XL_M__ KC_M
#define XL_N__ KC_N
#define XL_O__ KC_O
#define XL_P__ KC_P
#define XL_Q__ KC_Q
#define XL_R__ KC_R
#define XL_S__ KC_S
#define XL_T__ KC_T
#define XL_U__ KC_U
#define XL_V__ KC_V
#define XL_W__ KC_W
#define XL_X__ KC_X
#define XL_Y__ KC_Y
#define XL_Z__ KC_Z

#define XN_1__ KC_1
#define XN_2__ KC_2
#define XN_3__ KC_3
#define XN_4__ KC_4
#define XN_5__ KC_5
#define XN_6__ KC_6
#define XN_7__ KC_7
#define XN_8__ KC_8
#define XN_9__ KC_9
#define XN_0__ KC_0

// MATH
#define XS_SUB KC_MINS          // + plus
#define XS_ADD KC_PLUS          // - minus
#define XS_MUL KC_ASTR          // * multiply
#define XS_DIV KC_SLSH          // / 
#define XS_MOD KC_PERC          // % modulo
#define XS_EQL KC_EQUAL         // = equal

// PUNCTUATION
#define XS_DOT KC_DOT           // . dot
#define XS_COM KC_COMMA         // , comma
#define XS_SEM KC_SCLN          // ; semi-colon
#define XS_COL KC_COLN          // : colon
#define XS_HUH KC_QUES          // ? question mark
#define XS_SPC KC_SPACE         //   space

// SYMBOL
#define XS_MON KC_DLR           // $ money
#define XS_HSH KC_HASH          // # hashtag
#define XS_TIL KC_TILD          // ~ tilde
#define XS_AT_ KC_AT            // @ at
#define XS_UND KC_UNDS          // _ underscore
#define XS_FSL KC_SLSH          // / forward slash
#define XS_BSL KC_BSLS          // \ back slash

// LOGIC
#define XS_AND KC_AMPR          // & and
#define XS_OR_ KC_PIPE          // | or 
#define XS_NOT KC_EXLM          // ! not 
#define XS_XOR KC_CIRC          // ^ carrot

// QUOTES
#define XS_SQT KC_QUOT          // ' single quote
#define XS_DQT KC_DQT           // " double quote
#define XS_BQT KC_GRV           // ` back quote

// BRACKETS
#define XS_LPR KC_LPRN          // ( open paren
#define XS_RPR KC_RPRN          // ) close paren
#define XS_LSB KC_LBRC          // [ open square bracket
#define XS_RSB KC_RBRC          // ] close square bracket
#define XS_LCB KC_LCBR          // { open curly bracket 
#define XS_RCB KC_RCBR          // } close curly bracket
#define XS_LAB KC_LT            // < open angle bracket (less than)
#define XS_RAB KC_GT            // > close angle bracket (greater than)

// ACTIONS
#define XA_BSP KC_BSPC          // backspace
#define XA_DEL KC_DEL           // delete
#define XA_INS KC_INSERT        // insert
#define XA_ENT KC_ENT           // enter
#define XA_TAB KC_TAB           // tab
#define XA_ESC KC_ESC           // escape
#define XA_PUP KC_PGUP          // page up
#define XA_PDN KC_PGDN          // page down
#define XA_HOM KC_HOME          // home
#define XA_END KC_END           // end

// COPY CUT PASTE
#define XA_CPY KC_COPY          // copy 
#define XA_CUT KC_CUT           // cut 
#define XA_PUT KC_PASTE         // paste

// ARROW KENS
#define XA_UUU KC_UP              // up
#define XA_DDD KC_DOWN            // down
#define XA_LLL KC_LEFT            // left
#define XA_RRR KC_RIGHT           // right

// MODIFIERS
#define XM_LCT KC_LCTL         // left control
#define XM_RCT KC_RCTL         // right control
#define XM_LGU KC_LGUI         // left gui
#define XM_RGU KC_RGUI         // right gui
#define XM_LAL KC_LALT         // left alt
#define XM_RAL KC_RALT         // right alt
#define XM_LSH KC_LSFT         // left shift
#define XM_RSH KC_RSFT         // right shift

// QMK
#define XQ_NOP KC_NO           // do nothing
#define XQ_CLR KC_TRNS        // clear (transparent, fall through)

enum layers {
    _WORKMAN = 0,
    _NUMBER,
    _SYMBOL,
    _NAVIGATION
};

// SLUGBYTE'S SPECAIL KEYS
#define SB_ENT LCTL_T(XA_ENT) // control when held, enter when tapped
#define SB_ESC LCTL_T(XA_ESC) // control when held, escape when tapped
#define SB_SQT LCTL_T(XS_SQT) // control when held, single quote when tapped
#define SB_DOT LCTL_T(XS_DOT) // control when held, single quote when tapped

#define SB_NUM LT(_NUMBER, XS_SPC)             // _NUMBER when held, space when tapped
#define SB_SYM LT(_SYMBOL, XS_SPC)            // _SYMBOL when held, space when tapped
#define SB_NAV LT(_NAVIGATION, XA_BSP)         // _NAVIGATION when held, backspace when tapped

#define SB_BAM OSM(KC_HYPR) // one-shot hyper
#define SB_NXT LCTL(XA_TAB) // next tab
#define SB_PRV RCS(XA_TAB) // next tab


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WORKMAN] = LAYOUT(
      XA_TAB, XL_Q__, XL_D__, XL_R__, XL_W__, XL_B__,                                           XL_J__, XL_F__, XL_U__, XL_P__, XL_S__, XA_BSP,
      SB_ESC, XL_A__, XL_S__, XL_H__, XL_T__, XL_G__,                                           XL_Y__, XL_N__, XL_E__, XL_O__, XL_I__, SB_SQT,
      SB_ENT, XL_Z__, XL_X__, XL_M__, XL_C__, XL_V__,    XM_LAL, XM_LSH,    XQ_NOP, XQ_NOP,     XL_K__, XL_L__, XL_C__, XL_D__, XL_F__, SB_ENT,
                              XA_DEL, SB_ENT, XM_LSH,    XM_LGU, XM_LAL,    SB_NAV, SB_NUM,     SB_SYM, SB_ENT, SB_BAM
    ),
    [_NUMBER] = LAYOUT(
      XQ_CLR, XS_MUL, XS_ADD, XS_SUB, XS_UND, XQ_NOP,                                            XS_ADD, XN_1__, XN_2__, XN_3__, XS_SUB, XQ_CLR,
      XQ_CLR, XS_LAB, XS_RAB, XS_LPR, XS_RPR, XS_SPC,                                            XS_EQL, XN_4__, XN_5__, XN_6__, XN_0__, SB_DOT,
      XQ_CLR, XS_LSB, XS_RSB, XS_LCB, XS_RCB, XQ_NOP,    XQ_CLR, XQ_CLR,     XQ_CLR, XQ_CLR,     XS_MUL, XN_7__, XN_5__, XN_9__, XS_DIV, XQ_CLR,
                              XQ_CLR, XQ_CLR, XQ_CLR,    XQ_CLR, XQ_CLR,     XQ_CLR, XQ_CLR,     XQ_CLR, XQ_CLR, XQ_CLR
    ),
    [_SYMBOL] = LAYOUT(
      XS_BSL, XS_MUL, XS_ADD, XS_SUB, XS_UND, XA_ESC,                                            XS_AT_, XS_SQT, XS_DQT, XS_BQT, XS_XOR, XQ_CLR,
      XS_FSL, XS_LAB, XS_RAB, XS_LPR, XS_RPR, XS_EQL,                                            XS_TIL, XS_SEM, XS_AND, XS_OR_, XS_NOT, XS_MOD,
      XQ_CLR, XS_LSB, XS_RSB, XS_LCB, XS_RCB, XS_MON,    XQ_CLR, XQ_CLR,     XQ_CLR, XQ_CLR,     XS_HSH, XS_COL, XS_COM, XS_DOT, XS_HUH, XQ_CLR,
                              XQ_CLR, XQ_CLR, XQ_CLR,    XQ_CLR, XQ_CLR,     XQ_CLR, XQ_CLR,     XQ_CLR, XQ_CLR, XQ_CLR
    ),
    // TODO: left hand is mouse not arrows (@slugbyte)
    [_NAVIGATION] = LAYOUT(
      XQ_CLR, XQ_NOP, XQ_NOP, XA_UUU, XQ_NOP, XQ_NOP,                                            XA_END, XA_PUP, XA_PDN, XA_HOM, XQ_NOP, XQ_CLR,
      XQ_CLR, XQ_NOP, XA_LLL, XA_DDD, XA_RRR, XQ_NOP,                                            XA_LLL, XA_DDD, XA_UUU, XA_RRR, XQ_NOP, XQ_CLR,
      XQ_CLR, XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP,    XQ_CLR, XQ_CLR,     XQ_CLR, XQ_CLR,     XQ_NOP, SB_NXT, SB_PRV, XQ_NOP, XQ_NOP, XQ_CLR,
                              XQ_CLR, XQ_CLR, XQ_CLR,    XQ_CLR, XQ_CLR,     XQ_CLR, XQ_CLR,     XQ_CLR, XQ_CLR, XQ_CLR
    ),
//    [_LAYERINDEX] = LAYOUT(
//      XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP,                                            XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP,
//      XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP,                                            XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP,
//      XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP,    XQ_NOP, XQ_NOP,     XQ_NOP, XQ_NOP,     XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP, XQ_NOP,
//                              XQ_NOP, XQ_NOP, XQ_NOP,    XQ_NOP, XQ_NOP,     XQ_NOP, XQ_NOP,     XQ_NOP, XQ_NOP, XQ_NOP
//    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUMBER, _SYMBOL, _NAVIGATION);
}


/*#ifdef ENCODER_ENABLE*/
/*void encoder_update_user(uint8_t index, bool clockwise) {*/
    /*if (index == 0) {*/
        /*// Volume control*/
        /*if (clockwise) {*/
            /*tap_code(KC_VOLU);*/
        /*} else {*/
            /*tap_code(KC_VOLD);*/
        /*}*/
    /*}*/
    /*else if (index == 1) {*/
        /*// Page up/Page down*/
        /*if (clockwise) {*/
            /*tap_code(KC_PGDN);*/
        /*} else {*/
            /*tap_code(KC_PGUP);*/
        /*}*/
    /*}*/
/*}*/
/*#endif*/

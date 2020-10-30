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

/*
 * I created these aliases to clean up the readability of the keymap.c file
 *
 * XXXXX is KC_NO
 * _____ is KC_TRANSPARENT
 *
 * There are a few categories that each have a unique prefix.
 *    (__) Letters -- A through Z
 *    (N_) Numbers -- 0 through 9
 *    (F_) Funkeys -- F1 through F12
 *    (S_) Symbols -- non-alpha and non-number ascii characters
 *    (A_) Actions -- non ascii keys that have behavior (backspace, enter, pageup, ...)
 *    (M_) Modkeys -- modifier keys (GUI, ALT, SHIFT ...)
 */


#include QMK_KEYBOARD_H

// QMK                                                            
 #define XXXXX  KC_NO           // do nothing
 #define _____ KC_TRNS        // clear (transparent, fall through)

// LETTERS
#define __A__ KC_A
#define __B__ KC_B
#define __C__ KC_C
#define __D__ KC_D
#define __E__ KC_E
#define __F__ KC_F
#define __G__ KC_G
#define __H__ KC_H
#define __I__ KC_I
#define __J__ KC_J
#define __K__ KC_K
#define __L__ KC_L
#define __M__ KC_M
#define __N__ KC_N
#define __O__ KC_O
#define __P__ KC_P
#define __Q__ KC_Q
#define __R__ KC_R
#define __S__ KC_S
#define __T__ KC_T
#define __U__ KC_U
#define __V__ KC_V
#define __W__ KC_W
#define __X__ KC_X
#define __Y__ KC_Y
#define __Z__ KC_Z

// NUMBERS
#define N_1__ KC_1
#define N_2__ KC_2
#define N_3__ KC_3
#define N_4__ KC_4
#define N_5__ KC_5
#define N_6__ KC_6
#define N_7__ KC_7
#define N_8__ KC_8
#define N_9__ KC_9
#define N_0__ KC_0

// FUNCTION
#define F_01_ KC_F1
#define F_02_ KC_F2
#define F_03_ KC_F3
#define F_04_ KC_F4
#define F_05_ KC_F5
#define F_06_ KC_F6
#define F_07_ KC_F7
#define F_08_ KC_F8
#define F_09_ KC_F9
#define F_10_ KC_F10
#define F_11_ KC_F11
#define F_12_ KC_F12

// SYMBOLS
// -- PUNCTUATION
#define S_DOT KC_DOT           // . dot
#define S_COM KC_COMMA         // , comma
#define S_SEM KC_SCLN          // ; semi-colon
#define S_COL KC_COLN          // : colon
#define S_HUH KC_QUES          // ? question mark

// -- WHITESPACE
#define S_SPC KC_SPACE         //   space
#define S_TAB KC_TAB           // tab
#define S_ENT KC_ENT           // enter (new line)

// -- MATH
#define S_SUB KC_MINS          // + plus
#define S_ADD KC_PLUS          // - minus
#define S_MUL KC_ASTR          // * multiply
#define S_DIV KC_SLSH          // / 
#define S_MOD KC_PERC          // % modulo
#define S_EQL KC_EQUAL         // = equal

// -- LOGIC
#define S_AND KC_AMPR          // & and
#define S_OR_ KC_PIPE          // | or 
#define S_NOT KC_EXLM          // ! not 
#define S_XOR KC_CIRC          // ^ carrot

// -- QUOTES
#define S_SQT KC_QUOT          // ' single quote
#define S_DQT KC_DQT           // " double quote
#define S_BQT KC_GRV           // ` back quote

// -- BRACKETS
#define S_LPR KC_LPRN          // ( open paren
#define S_RPR KC_RPRN          // ) close paren
#define S_LSB KC_LBRC          // [ open square bracket
#define S_RSB KC_RBRC          // ] close square bracket
#define S_LCB KC_LCBR          // { open curly bracket 
#define S_RCB KC_RCBR          // } close curly bracket
#define S_LAB KC_LT            // < open angle bracket (less than)
#define S_RAB KC_GT            // > close angle bracket (greater than)

// -- MISC
#define S_MON KC_DLR           // $ money
#define S_HSH KC_HASH          // # hashtag
#define S_TIL KC_TILD          // ~ tilde
#define S_AT_ KC_AT            // @ at
#define S_UND KC_UNDS          // _ underscore
#define S_FSL KC_SLSH          // / forward slash
#define S_BSL KC_BSLS          // \ back slash

// ACTIONS
// -- MISC
#define A_BSP KC_BSPC          // backspace
#define A_DEL KC_DEL           // delete
#define A_INS KC_INSERT        // insert
#define A_ESC KC_ESC           // escape
#define A_PUP KC_PGUP          // page up
#define A_PDN KC_PGDN          // page down
#define A_HOM KC_HOME          // home
#define A_END KC_END           // end


// -- ARROW KENS
#define A_UUU KC_UP              // up
#define A_DDD KC_DOWN            // down
#define A_LLL KC_LEFT            // left
#define A_RRR KC_RIGHT           // right

// -- VOLUME
#define A_VOU KC__VOLUP       // volume up
#define A_VOD KC__VOLDOWN     // volume down
#define A_VOM KC__MUTE        // volume down

// -- UNDO REDO
#define A_UND KC_UNDO         // UNDO
#define A_RED KC_AGAIN        // REDO

// -- COPY CUT PASTE
#define A_CPY KC_COPY          // copy 
#define A_CUT KC_CUT           // cut 
#define A_PUT KC_PASTE         // paste

// MODIFIERS
#define M_CTL KC_LCTL         // left control
#define M_SUP KC_LGUI         // left gui
#define M_ALT KC_LALT         // left alt
#define M_SFT KC_LSFT         // left shift

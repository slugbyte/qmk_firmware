# SLUGBYTE KEYMAP
> a WORKMXN keymap by slugbyte for slugbyte

## GOALS
0) Alias keycodes into 5 char definitions, so that the layout plestant to read and write 
  * `__W__` instead of `KC_W`
  * `A_ESC` instead of `KC_ESCAPE`
2) All essential keys (80% layout) must be accesable within one layer change from the default layer
3) Numbers must be easy to type
4) Symbols should be arranged based on fequency of use and ease of typing!
5) Symbols should be arranged into logical groops (braces, math, logic, quotes, punctuation, other)
6) Include a gamepad layer

## ALIASES EXPLAINED
In order to cleanup up the *keymap.c* file, I created custom keycode aliases that have a consistant interface.
The aliases are each 5 chars long and have prefixes that group them into logical categories; letters, numbers, symbols and whitespace,
funtion keys, actions, and modifiers. The qmk keycodes `KC_NO` and `KC_TRANSPARENT` have also been aliases to `XXXXX` and `_____`.

#### ALIAS PREFIXES
* `__` Letters, A-Z -- `__F__`, `__Z__`
* `N_` Numbers, 0-9 -- `N_7__`, `N_0__`
* `F_` Function Keys, F1-F12 -- `F_01_`, `F_11_`
* `S_` Symbols and WHITE SPACE -- `S_COM` is comma, `S_SPC` is space
* `A_` Actions, non ascii keys that heave behavior -- `A_PUP` is page up, `A_BSP` is backspace
* `M_` Modifiers -- `M_SUP` is super, `M_SFT` is shift

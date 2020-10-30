# SLUGBYTE'S KYRIA KEYMAP
> a WORKMXN keymap

## GOALS
1) Alias keycodes into 5 char definitions, so that the layout plestant to read and write.
1) All essential keys (80% layout) must be accesable within one layer change from the default layer.
1) The default layer should have a workmxn layout
1) Numbers must be easy to type.
1) Symbols should be arranged based on fequency of use and ease of typing.
1) Symbols should also be arranged into logical groops (braces, math, logic, quotes, punctuation, other).
1) Include left handed modified qwerty and numpad layers for gaming.

## ALIASES EXPLAINED
In order to cleanup up the *keymap.c* file, I created custom keycode aliases that have a consistant interface.
The aliases are each 5 chars long and have prefixes that group them into logical categories; letters, numbers, symbols and whitespace,
function keys, actions, and modifiers. The qmk keycodes `KC_NO` and `KC_TRANSPARENT` have also been aliases to `XXXXX` and `_____`.

#### ALIAS PREFIXES
* `__` Letters, A-Z -- `__F__`, `__Z__`
* `N_` Numbers, 0-9 -- `N_7__`, `N_0__`
* `F_` Function keys, F1-F12 -- `F_01_`, `F_11_`
* `S_` Symbols and white space -- `S_COM` is comma, `S_SPC` is space
* `A_` Actions keys, non ascii keys that heave behavior -- `A_PUP` is page up, `A_BSP` is backspace
* `M_` Modifier keys -- `M_SUP` is super, `M_SFT` is shift

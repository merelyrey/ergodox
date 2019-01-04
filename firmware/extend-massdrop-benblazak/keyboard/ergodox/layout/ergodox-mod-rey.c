/* ----------------------------------------------------------------------------
* ergoDOX layout : QWERTY (modified from the Kinesis layout)
* -----------------------------------------------------------------------------
* Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
* Released under The MIT License (MIT) (see "license.md")
* Project located at <https://github.com/benblazak/ergodox-firmware>
* -------------------------------------------------------------------------- */
#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"
// FUNCTIONS ------------------------------------------------------------------
void kbfun_layer_pop_all(void) {
  kbfun_layer_pop_1_with_left_shift();
  kbfun_layer_pop_2_with_right_shift();
  kbfun_layer_pop_3_with_alt_gr();
  kbfun_layer_pop_4_remove_left_shift();
  kbfun_layer_pop_4_remove_right_shift();  
  kbfun_layer_pop_4_remove_alt_gr();  
}

// DEFINITIONS ----------------------------------------------------------------
#define  kprrel   &kbfun_press_release
#define  kprrelsl &kbfun_press_release_with_left_shift
#define  kprrelslr &kbfun_press_release_with_left_shift_reversed
#define  kprrelrsl &kbfun_press_release_removed_left_shift
#define  kprrelrslr &kbfun_press_release_removed_left_shift_reversed
#define  kprrelrslag &kbfun_press_release_removed_left_shift_with_altgr
#define  kprrelrslragr &kbfun_press_release_removed_left_shift_reversed_with_altgr_reversed
#define  kprrelrsrag &kbfun_press_release_removed_right_shift_with_altgr
#define  kprrelrsrragr &kbfun_press_release_removed_right_shift_reversed_with_altgr_reversed
#define  kprrelsr &kbfun_press_release_with_right_shift
#define  kprrelsrr &kbfun_press_release_with_right_shift_reversed
#define  kprrelrsr &kbfun_press_release_removed_right_shift
#define  kprrelrsrr &kbfun_press_release_removed_right_shift_reversed
#define  kprrelag &kbfun_press_release_with_altgr
#define  kprrelagr &kbfun_press_release_with_altgr_reversed
#define  kprrelrag &kbfun_press_release_removed_altgr
#define  kprrelragr &kbfun_press_release_removed_altgr_reversed
#define  kprrelal &kbfun_press_release_with_left_alt
#define  kprrelalr &kbfun_press_release_with_left_alt_reversed
#define  kprrelragal &kbfun_press_release_removed_altgr_with_left_alt
#define  kprrelragralr &kbfun_press_release_removed_altgr_reversed_with_left_alt_reversed
#define  kprrelragsl &kbfun_press_release_removed_altgr_with_left_shift
#define  kprrelragrslr &kbfun_press_release_removed_altgr_reversed_with_left_shift_reversed
#define  kprrelragsr &kbfun_press_release_removed_altgr_with_right_shift
#define  kprrelragrsrr &kbfun_press_release_removed_altgr_reversed_with_right_shift_reversed
#define  mprrel   &kbfun_mediakey_press_release
#define  mprrelag   &kbfun_mediakey_press_release_with_altgr
#define  mprrelagr   &kbfun_mediakey_press_release_with_altgr_reversed
#define  mprrelrag   &kbfun_mediakey_press_release_removed_altgr
#define  mprrelragr   &kbfun_mediakey_press_release_removed_altgr_reversed
#define  ktog     &kbfun_toggle
#define  ktrans   &kbfun_transparent
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush1ls   &kbfun_layer_push_1_with_left_shift
#define  lpush2rs   &kbfun_layer_push_2_with_right_shift
#define  lpush3ag   &kbfun_layer_push_3_with_alt_gr
#define  lpush4rls   &kbfun_layer_push_4_remove_left_shift
#define  lpush4rrs   &kbfun_layer_push_4_remove_right_shift
#define  lpush4rag   &kbfun_layer_push_4_remove_alt_gr
#define  lpop     &kbfun_layer_pop_all
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop1ls   &kbfun_layer_pop_1_with_left_shift
#define  lpop2rs   &kbfun_layer_pop_2_with_right_shift
#define  lpop3ag   &kbfun_layer_pop_3_with_alt_gr
#define  lpop4rls   &kbfun_layer_pop_4_remove_left_shift
#define  lpop4rrs   &kbfun_layer_pop_4_remove_right_shift
#define  lpop4rag   &kbfun_layer_pop_4_remove_alt_gr
#define  dbtldr   &kbfun_jump_to_bootloader
#define  sshprre  &kbfun_shift_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad
// ----------------------------------------------------------------------------

// LAYOUT ---------------------------------------------------------------------
const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
	// unused
	0,	
	// left hand
	KEY_Escape,	KEY_1_Exclamation,	KEY_2_At,	KEY_3_Pound,	KEY_4_Dollar,	KEY_5_Percent,	KEY_GraveAccent_Tilde,	
	KEY_Tab,	KEY_q_Q,	KEY_w_W,	KEY_d_D,	KEY_r_R,	KEY_k_K,	KEY_F1,	
	3,	KEY_a_A,	KEY_s_S,	KEY_t_T,	KEY_f_F,	KEY_g_G,	
	1,	KEY_z_Z,	KEY_x_X,	KEY_c_C,	KEY_v_V,	KEY_b_B,	KEY_F2,	
	KEY_LeftControl,	KEY_LeftGUI,	KEY_LeftAlt,	KEY_Semicolon_Colon,	KEY_SingleQuote_DoubleQuote,	
	KEY_Home,	KEY_End,	
	0,	0,	KEY_PageUp,	
	KEY_DeleteBackspace,	KEY_DeleteForward,	KEY_PageDown,	
	// right hand
	KEY_NonUS_Backslash_Pipe,	KEY_6_Caret,	KEY_7_Ampersand,	KEY_8_Asterisk,	KEY_9_LeftParenthesis,	KEY_0_RightParenthesis,	KEY_Insert,	
	KEY_F3,	KEY_y_Y,	KEY_u_U,	KEY_i_I,	KEY_l_L,	KEY_p_P,	KEY_Application,	
	KEY_h_H,	KEY_n_N,	KEY_e_E,	KEY_o_O,	KEY_RightBracket_RightBrace,	3,	
	KEY_F4,	KEY_j_J,	KEY_m_M,	KEY_Comma_LessThan,	KEY_Period_GreaterThan,	KEY_Slash_Question,	2,	
	KEY_Dash_Underscore,	KEY_LeftBracket_LeftBrace,	KEY_LeftAlt,	KEY_RightGUI,	KEY_RightControl,	
	KEY_LeftArrow,	KEY_RightArrow,	
	KEY_UpArrow,	0,	0,	
	KEY_DownArrow,	KEY_ReturnEnter,	KEY_Spacebar	
),
// LAYER 1 - enabled if Left Shift is pressed
KB_MATRIX_LAYER(
	// unused
	0,	
	// left hand
	KEY_Escape,	KEY_1_Exclamation,	KEY_2_At,	KEY_NonUS_Pound_Tilde,	KEY_4_Dollar,	KEY_5_Percent,	KEY_GraveAccent_Tilde,	
	KEY_Tab,	KEY_q_Q,	KEY_w_W,	KEY_d_D,	KEY_r_R,	KEY_k_K,	KEY_F5,	
	4,	KEY_a_A,	KEY_s_S,	KEY_t_T,	KEY_f_F,	KEY_g_G,	
	0,	KEY_z_Z,	KEY_x_X,	KEY_c_C,	KEY_v_V,	KEY_b_B,	KEY_F6,	
	KEY_LeftControl,	KEY_LeftGUI,	KEY_LeftAlt,	KEY_Semicolon_Colon,	KEY_SingleQuote_DoubleQuote,	
	KEY_Home,	KEY_End,	
	0,	0,	KEY_PageUp,	
	KEY_DeleteBackspace,	KEY_DeleteForward,	KEY_PageDown,	
	// right hand
	KEY_NonUS_Backslash_Pipe,	KEY_6_Caret,	KEY_7_Ampersand,	KEY_8_Asterisk,	KEY_9_LeftParenthesis,	KEY_Dash_Underscore,	KEY_Insert,	
	KEY_F7,	KEY_y_Y,	KEY_u_U,	KEY_i_I,	KEY_l_L,	KEY_p_P,	KEY_Application,	
	KEY_h_H,	KEY_n_N,	KEY_e_E,	KEY_o_O,	KEY_RightBracket_RightBrace,	4,	
	KEY_F8,	KEY_j_J,	KEY_m_M,	KEY_Comma_LessThan,	KEY_Period_GreaterThan,	KEY_Slash_Question,	KEY_CapsLock,	
	KEY_Dash_Underscore,	KEY_LeftBracket_LeftBrace,	KEY_LeftAlt,	KEY_RightGUI,	KEY_RightControl,	
	KEY_LeftArrow,	KEY_RightArrow,	
	KEY_UpArrow,	0,	0,	
	KEY_DownArrow,	KEY_ReturnEnter,	KEY_Spacebar	
),
// LAYER 2 - enabled if Right Shift is pressed
KB_MATRIX_LAYER(
	// unused
	0,	
	// left hand
	KEY_Escape,	KEY_1_Exclamation,	KEY_2_At,	KEY_NonUS_Pound_Tilde,	KEY_4_Dollar,	KEY_5_Percent,	KEY_GraveAccent_Tilde,	
	KEY_Tab,	KEY_q_Q,	KEY_w_W,	KEY_d_D,	KEY_r_R,	KEY_k_K,	KEY_F5,	
	4,	KEY_a_A,	KEY_s_S,	KEY_t_T,	KEY_f_F,	KEY_g_G,	
	KEY_CapsLock,	KEY_z_Z,	KEY_x_X,	KEY_c_C,	KEY_v_V,	KEY_b_B,	KEY_F6,	
	KEY_LeftControl,	KEY_LeftGUI,	KEY_LeftAlt,	KEY_Semicolon_Colon,	KEY_SingleQuote_DoubleQuote,	
	KEY_Home,	KEY_End,	
	0,	0,	KEY_PageUp,	
	KEY_DeleteBackspace,	KEY_DeleteForward,	KEY_PageDown,	
	// right hand
	KEY_NonUS_Backslash_Pipe,	KEY_6_Caret,	KEY_7_Ampersand,	KEY_8_Asterisk,	KEY_9_LeftParenthesis,	KEY_Dash_Underscore,	KEY_Insert,	
	KEY_F7,	KEY_y_Y,	KEY_u_U,	KEY_i_I,	KEY_l_L,	KEY_p_P,	KEY_Application,	
	KEY_h_H,	KEY_n_N,	KEY_e_E,	KEY_o_O,	KEY_RightBracket_RightBrace,	4,	
	KEY_F8,	KEY_j_J,	KEY_m_M,	KEY_Comma_LessThan,	KEY_Period_GreaterThan,	KEY_Slash_Question,	0,	
	KEY_Dash_Underscore,	KEY_LeftBracket_LeftBrace,	KEY_LeftAlt,	KEY_RightGUI,	KEY_RightControl,	
	KEY_LeftArrow,	KEY_RightArrow,	
	KEY_UpArrow,	0,	0,	
	KEY_DownArrow,	KEY_ReturnEnter,	KEY_Spacebar	
),
// LAYER 3
KB_MATRIX_LAYER(
	// unused
	0,	
	// left hand
	KEY_Escape,	KEY_1_Exclamation,	KEY_2_At,	KEY_3_Pound,	KEY_3_Pound,	KEY_Equal_Plus,	KEY_Equal_Plus,	
	KEY_Tab,	KEY_q_Q,	KEY_w_W,	KEY_d_D,	KEY_r_R,	KEY_k_K,	KEY_F9,	
	0,	KEY_a_A,	KEY_s_S,	KEY_t_T,	KEY_f_F,	KEY_g_G,	
	4,	KEY_z_Z,	KEY_x_X,	KEY_c_C,	KEY_v_V,	KEY_b_B,	KEY_F10,	
	KEY_LeftControl,	KEY_LeftGUI,	KEY_LeftAlt,	KEY_Semicolon_Colon,	KEY_SingleQuote_DoubleQuote,	
	KEY_PrintScreen,	MEDIAKEY_AUDIO_MUTE,	
	0,	0,	MEDIAKEY_AUDIO_VOL_UP,	
	KEY_DeleteBackspace,	KEY_DeleteForward,	MEDIAKEY_AUDIO_VOL_DOWN,	
	// right hand
	KEY_NonUS_Backslash_Pipe,	KEY_NonUS_Pound_Tilde,	KEY_7_Ampersand,	KEY_8_Asterisk,	KEY_9_LeftParenthesis,	KEY_0_RightParenthesis,	KEY_Pause,	
	KEY_F11,	KEY_y_Y,	KEY_u_U,	KEY_i_I,	KEY_l_L,	KEY_p_P,	KEY_Application,	
	KEY_h_H,	KEY_n_N,	KEY_e_E,	KEY_o_O,	KEY_RightBracket_RightBrace,	0,	
	KEY_F12,	KEY_j_J,	KEY_m_M,	KEY_Comma_LessThan,	KEY_Period_GreaterThan,	KEY_Slash_Question,	4,	
	KEY_0_RightParenthesis,	KEY_LeftBracket_LeftBrace,	KEY_LeftAlt,	KEY_RightGUI,	KEY_RightControl,	
	MEDIAKEY_PREV_TRACK,	MEDIAKEY_NEXT_TRACK,	
	MEDIAKEY_PLAY_PAUSE,	0,	0,	
	MEDIAKEY_STOP,	KEY_ReturnEnter,	KEY_Spacebar	
),
// LAYER 4
KB_MATRIX_LAYER(
	// unused
	0,	
	// left hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	KEY_Home,	KEY_UpArrow,	KEY_PageUp,	0,	0,	
	0,	0,	KEY_LeftArrow,	KEY_DownArrow,	KEY_RightArrow,	0,	
	0,	0,	KEY_End,	0,	KEY_PageDown,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	0,	
	0,	0,	0,	
	KEY_DeleteBackspace,	KEY_DeleteForward,	0,	
	// right hand
	0,	0,	0,	KEYPAD_Slash,	KEYPAD_Asterisk,	KEYPAD_Minus,	0,	
	0,	0,	KEYPAD_7_Home,	KEYPAD_8_UpArrow,	KEYPAD_9_PageUp,	KEYPAD_Plus,	0,	
	0,	KEYPAD_4_LeftArrow,	KEYPAD_5,	KEYPAD_6_RightArrow,	KEYPAD_Plus,	0,	
	0,	0,	KEYPAD_1_End,	KEYPAD_2_DownArrow,	KEYPAD_3_PageDown,	KEYPAD_ENTER,	0,	
	KEYPAD_0_Insert,	KEYPAD_0_Insert,	KEYPAD_Period_Delete,	KEYPAD_ENTER,	0,	
	0,	0,	
	0,	0,	0,	
	0,	KEY_ReturnEnter,	KEY_Spacebar	
),
};
// ----------------------------------------------------------------------------

// PRESS ----------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	lpush3ag,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	lpush1ls,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	
	NULL,	NULL,	kprrel,	
	kprrel,	kprrel,	kprrel,	
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	lpush3ag,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	lpush2rs,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	
	kprrel,	NULL,	NULL,	
	kprrel,	kprrel,	kprrel	
),
// LAYER 1
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	kprrel,	kprrel,	kprrel,	kprrelrsl,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrsl,	
	lpush4rls,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrsl,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	
	NULL,	NULL,	kprrel,	
	kprrel,	kprrel,	kprrel,	
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrslag,	kprrel,	
	kprrelrsl,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	lpush4rls,	
	kprrelrsl,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrsl,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	
	kprrel,	NULL,	NULL,	
	kprrel,	kprrel,	kprrel	
),
// LAYER 2
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	kprrel,	kprrel,	kprrel,	kprrelrsr,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrsr,	
	lpush4rrs,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrelrsr,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrsr,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	
	NULL,	NULL,	kprrel,	
	kprrel,	kprrel,	kprrel,	
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrsrag,	kprrel,	
	kprrelrsr,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	lpush4rrs,	
	kprrelrsr,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	
	kprrel,	NULL,	NULL,	
	kprrel,	kprrel,	kprrel	
),
// LAYER 3
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left
	kprrel,	kprrel,	kprrel,	kprrel,	kprrelragsr,	kprrelrag,	kprrelragsr,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrag,	
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	lpush4rag,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrag,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrelragal,	mprrelrag,	
	NULL,	NULL,	mprrelrag,	
	kprrelrag,	kprrelrag,	mprrelrag,	
	// right hand
	kprrel,	kprrelragsl,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrag,	
	kprrelrag,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	kprrelrag,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	lpush4rag,	
	kprrelragsl,	kprrel,	kprrel,	kprrel,	kprrel,	
	mprrelrag,	mprrelrag,	
	mprrelrag,	NULL,	NULL,	
	mprrelrag,	kprrelrag,	kprrelrag
),
// LAYER 4
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	kprrel,	kprrel,	kprrel,	NULL,	NULL,	
	NULL,	NULL,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	kprrel,	NULL,	kprrel,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	kprrel,	kprrel,	NULL,	
	// right hand
	NULL,	NULL,	NULL,	kprrel,	kprrel,	kprrel,	dbtldr,	
	NULL,	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	kprrel,	kprrel	
),
};
// ----------------------------------------------------------------------------

// RELEASE --------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	lpop3ag,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	lpop1ls,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	
	NULL,	NULL,	kprrel,	
	kprrel,	kprrel,	kprrel,	
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	lpop3ag,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	lpop2rs,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	
	kprrel,	NULL,	NULL,	
	kprrel,	kprrel,	kprrel	
),
// LAYER 1
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	kprrel,	kprrel,	kprrel,	kprrelrslr,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrslr,	
	lpop4rls,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrslr,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	
	NULL,	NULL,	kprrel,	
	kprrel,	kprrel,	kprrel,	
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrslragr,	kprrel,	
	kprrelrslr,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	lpop4rls,	
	kprrelrslr,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrslr,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	
	kprrel,	NULL,	NULL,	
	kprrel,	kprrel,	kprrel	
),
// LAYER 2
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	kprrel,	kprrel,	kprrel,	kprrelrsrr,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrsrr,	
	lpop4rrs,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrelrsrr,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrsrr,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	
	NULL,	NULL,	kprrel,	
	kprrel,	kprrel,	kprrel,	
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelrsrragr,	kprrel,	
	kprrelrsrr,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	lpop4rrs,	
	kprrelrsrr,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	
	kprrel,	NULL,	NULL,	
	kprrel,	kprrel,	kprrel	
),
// LAYER 3
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrelragrsrr,	kprrelragr,	kprrelragrsrr,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelragr,	
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	lpop4rag,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelragr,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrelragralr,	mprrelragr,	
	NULL,	NULL,	mprrelragr,	
	kprrelragr,	kprrelragr,	mprrelragr,	
	// right hand
	kprrel,	kprrelragrslr,	kprrel,	kprrel,	kprrel,	kprrel,	kprrelragr,	
	kprrelragr,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	kprrelragr,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	lpop4rag,	
	kprrelragrslr,	kprrel,	kprrel,	kprrel,	kprrel,	
	mprrelragr,	mprrelragr,	
	mprrelragr,	NULL,	NULL,	
	mprrelragr,	kprrelragr,	kprrelragr		
),
// LAYER 4
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	kprrel,	kprrel,	kprrel,	NULL,	NULL,	
	NULL,	NULL,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	kprrel,	NULL,	kprrel,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	kprrel,	kprrel,	NULL,	
	// right hand
	NULL,	NULL,	NULL,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	kprrel,	kprrel	
),
};
// ----------------------------------------------------------------------------

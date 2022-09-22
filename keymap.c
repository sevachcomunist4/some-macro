#include QMK_KEYBOARD_H

enum my_layers {
    _FIRST_LAYER,
    _SECOND_LAYER,
    _THIRD_LAYER
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case MACRO_1: 
		if(record->event.pressed) {
			// keydown event
			SEND_STRING("x99999x");
			// _delay_ms(250);
			register_code(KC_TAB);
			unregister_code(KC_TAB);
			SEND_STRING("x999999x");
			// _delay_ms(250);
			register_code(KC_ENTER);
			unregister_code(KC_ENTER);
		} else {
			// when keycode is released
		}
		break;
		
	case MACRO_2: 
		if(record->event.pressed) {
			SEND_STRING("9xxxxxxxxx9");
			register_code(KC_TAB);
			unregister_code(KC_TAB);
			SEND_STRING("9xxxxxxxx9");
			register_code(KC_ENTER);
			unregister_code(KC_ENTER);
		} else {

		}
		break;
		
	case MACRO_3: 
		if(record->event.pressed) {
			SEND_STRING("x99999x");
			register_code(KC_TAB);
			unregister_code(KC_TAB);
		} else {

		}
		break;
		
	case MACRO_4: 
		if(record->event.pressed) {
			SEND_STRING("x999999x");
		} else {

		}
		break;
		
	case MACRO_5: 
		if(record->event.pressed) {
			SEND_STRING("x999999x");
		} else {

		}
		break;
		
	case MACRO_6: 
		if(record->event.pressed) {
			SEND_STRING("xxxx.xxxxxxx@xxxx.xxxxxxxxxxx.99");
		} else {

		}
		break;
		
	case MACRO_20: 
		if(record->event.pressed) {
			register_code(KC_LSFT);
			register_code(KC_F12);
		} else {
			unregister_code(KC_F12);
			unregister_code(KC_LSFT);
		}
		break;
		
	case MACRO_21: 
		if(record->event.pressed) {
			register_code(KC_LCTL);
			register_code(KC_F12);
		} else {
			unregister_code(KC_F12);
			unregister_code(KC_LCTL);
		}
		break;
		
	case MACRO_22: 
		if(record->event.pressed) {
			register_code(KC_LALT);
			register_code(KC_F12);
		} else {
			unregister_code(KC_F12);
			unregister_code(KC_LALT);
		}
		break;
		
	case MACRO_23: 
		if(record->event.pressed) {
			register_code(KC_ALGR);
			register_code(KC_F12);
		} else {
			unregister_code(KC_F12);
			unregister_code(KC_ALGR);
		}
		break;		
	}
	return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_FIRST_LAYER] = LAYOUT(
        KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_ESC,
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS, RGB_MOD,
        KC_P4,   KC_P5,   KC_P6,   KC_PENT, RGB_TOG,
        KC_P1,   KC_P2,   KC_P3,   KC_UP,   MO(_SECOND_LAYER),
        KC_P0,   KC_PDOT, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_SECOND_LAYER] = LAYOUT(
        TG(_THIRD_LAYER), KC_F2,   KC_F3,   KC_F4,   KC_F5,
        KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_F11,           KC_F12,  KC_MUTE, KC_VOLD, KC_VOLU,
        KC_MPLY,          KC_MSTP, KC_MPRV, KC_MNXT, _______,
        KC_RSFT,          KC_RALT, KC_RGUI, KC_APP,  KC_RCTL
    ),
    [_THIRD_LAYER] = LAYOUT(
        MACRO_1,  MACRO_6, MACRO_2, MACRO_2, MACRO_20,
        MACRO_2,  MACRO_2, MACRO_2, MACRO_2, MACRO_21,
        MACRO_3,  MACRO_2, MACRO_2, MACRO_2, MACRO_22,
        MACRO_4,  MACRO_2, MACRO_2, MACRO_2, MACRO_23,
        MACRO_5,  MACRO_2, MACRO_2, MACRO_2, TG(_THIRD_LAYER)
    ),
};

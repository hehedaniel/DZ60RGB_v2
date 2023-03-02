#include QMK_KEYBOARD_H

enum dz60rgb_layers {
	_QWERTY,
	_NAV,
	_RGB,
};

//LAYOUT FINAL
// #define base 0
// #define uno 1
// #define dos 2
// #define tres 3
// #define cuatro 4

// bool rgbStatus = true;


//layout basico, ya se cambiara si es que funciona

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( 
        KC_ESC,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,           KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,           KC_LBRC, KC_RBRC, KC_BSLS,
        LT(1,KC_CAPS),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,        KC_QUOT,          KC_ENT,
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,        KC_UP,  KC_SLSH,
        KC_LCTL,        KC_LGUI, LT(1,KC_LALT),                      KC_SPC,                    KC_RALT, LT(2,KC_ESC),  KC_LEFT,  KC_DOWN, KC_RGHT
),
    [1] = LAYOUT(
        TO(3),        KC_LPRN,    KC_RPRN,    KC_LCBR,    KC_RCBR,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  TO(3),
        TO(0),         _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_PSCR,    _______, _______, _______,
        KC_CAPS, _______,    _______,    KC_MSTP,    KC_MPLY,    _______,    _______,    _______,    _______,    _______,    _______, _______,          _______,
        _______,                 _______,    KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,    _______,    _______,    KC_LT, KC_GT,  _______, KC_INS,  KC_DEL            ,
        _______,      _______, _______,                      _______,                       _______, KC_ESC,  _______,  _______, _______
    ),
    [2] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,
        _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, RGB_TOG, _______, _______, RGB_M_P, RGB_M_B, RGB_M_R, _______, _______,
        KC_CAPS, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, RGB_MOD, _______, RGB_M_SW, RGB_M_SN, RGB_M_K, _______,          _______,
        _______,          _______, _______, _______, _______, RGB_RMOD, _______, RGB_M_X, RGB_M_G, RGB_M_T, _______,          _______, _______,
        _______, _______, _______,                            _______,                             _______, KC_ESC, _______, _______, _______
    ),
    [3] = LAYOUT(
        KC_NUM, KC_PSLS,   KC_PAST,   KC_PMNS,   KC_PPLS,   _______,   _______,   _______,   _______,   KC_PSLS,   KC_PAST,  KC_PMNS,  KC_PPLS,  KC_NUM,
        _______, KC_P7, KC_P8, KC_P9, _______, _______, _______, KC_P7, KC_P8, KC_P9, _______, _______, _______, TO(0),
        TO(4), KC_P4, KC_P5, KC_P6, _______, _______, _______, KC_P4, KC_P5, KC_P6, _______, _______,          KC_PENT,
        _______,          KC_P1, KC_P2, KC_P3, _______, _______, _______, KC_P1, KC_P2, KC_P2, _______,          _______, _______,
        TO(0), KC_P0, KC_PDOT,                            KC_PENT,                             KC_P0, KC_PDOT, _______, _______, _______
    ),
    [4] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,
        TO(0), RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, RGB_TOG, _______, _______, RGB_M_P, RGB_M_B, RGB_M_R, _______, QK_BOOT,
        KC_CAPS, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, RGB_MOD, _______, RGB_M_SW, RGB_M_SN, RGB_M_K, _______,          _______,
        _______,          _______, _______, _______, _______, RGB_RMOD, _______, RGB_M_X, RGB_M_G, RGB_M_T, _______,          _______, _______,
        TO(0), LT(2,KC_RGUI), _______,                            _______,                             _______, KC_ESC, _______, _______, _______
    )
};


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) { //LEEDS XNO0

    uint8_t this_led = host_keyboard_leds();

    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
	            if (this_led & (1 << USB_LED_CAPS_LOCK)) {
	            	rgb_matrix_set_color(i, RGB_GREEN);
                    rgb_matrix_set_color(40, 0xFF, 0xFF, 0xFF);

            	} else {
			    }   
                break;
            case 1:
                rgb_matrix_set_color(i, RGB_YELLOW);
                    rgb_matrix_set_color(12, 0, 47, 255);
                    rgb_matrix_set_color(11, 0, 47, 255);
                    rgb_matrix_set_color(10, 0, 47, 255);
                    rgb_matrix_set_color(9, 0, 47, 255);
                    rgb_matrix_set_color(37, 0, 47, 255);
                    rgb_matrix_set_color(36, 0, 47, 255);   
                    rgb_matrix_set_color(49, 0, 47, 255);   
                    rgb_matrix_set_color(51, 0, 47, 255);
                    rgb_matrix_set_color(50, 0, 47, 255);
                    rgb_matrix_set_color(48, 0, 47, 255);
                    rgb_matrix_set_color(41, 0, 47, 255);
                    rgb_matrix_set_color(42, 0, 47, 255);
                    rgb_matrix_set_color(43, 0, 47, 255);
                    rgb_matrix_set_color(44, 0, 47, 255);
                break;
            case 2:
                rgb_matrix_set_color(i, RGB_RED);
                for (uint8_t i = 1; i < 13; i++) {
                        rgb_matrix_set_color(i, 0x12, 0xC2, 0x00);        
                }
                break;
            case 3:
                rgb_matrix_set_color(i, HSV_MAGENTA);
                //rgb teclado numerico izq
                rgb_matrix_set_color(26, 51, 229, 89);
                rgb_matrix_set_color(25, 51, 229, 89);
                rgb_matrix_set_color(24, 51, 229, 89);
                rgb_matrix_set_color(39, 51, 229, 89);
                rgb_matrix_set_color(38, 51, 229, 89);
                rgb_matrix_set_color(37, 51, 229, 89);
                rgb_matrix_set_color(52, 51, 229, 89);
                rgb_matrix_set_color(51, 51, 229, 89);
                rgb_matrix_set_color(50, 51, 229, 89);
                rgb_matrix_set_color(61, 51, 229, 89);
                //rgb simbolos teclado numerico izq
                rgb_matrix_set_color(13, 255, 49, 0);
                rgb_matrix_set_color(12, 255, 0, 0);
                rgb_matrix_set_color(11, 255, 0, 0);
                rgb_matrix_set_color(10, 255, 0, 0);
                rgb_matrix_set_color(9, 255, 0, 0);

                //rgb teclado numerico dec
                rgb_matrix_set_color(18, 143, 18, 39);
                rgb_matrix_set_color(19, 143, 18, 39);
                rgb_matrix_set_color(20, 143, 18, 39);
                rgb_matrix_set_color(31, 143, 18, 39);
                rgb_matrix_set_color(32, 143, 18, 39);
                rgb_matrix_set_color(33, 143, 18, 39);
                rgb_matrix_set_color(44, 143, 18, 39);
                rgb_matrix_set_color(45, 143, 18, 39);
                rgb_matrix_set_color(46, 143, 18, 39);
                rgb_matrix_set_color(58, 143, 18, 39);
                //rgb simbolos teclado numerico dec
                rgb_matrix_set_color(1, 255, 0, 0);
                rgb_matrix_set_color(2, 255, 49, 0);
                rgb_matrix_set_color(3, 255, 49, 0);
                rgb_matrix_set_color(4, 255, 49, 0);


                break;
            default:
                break;
        }
    }
    return false;
}


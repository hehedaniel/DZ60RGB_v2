RGB_MATRIX_EFFECT(jmgh)
RGB_MATRIX_EFFECT(Functions)
RGB_MATRIX_EFFECT(LoL)
RGB_MATRIX_EFFECT(Mtgarena)
RGB_MATRIX_EFFECT(Valorant)
RGB_MATRIX_EFFECT(Mtgo)




bool Functions(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = 1; i < 13; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, 0xE8, 0xBE, 0x3C);        
    }

    for (uint8_t i = 14; i < led_min; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, 0x12, 0xC2, 0x00);        
    }

    for (uint8_t i = 15; i < 26; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, 0x09, 0xC2, 0x00);        
    }

    rgb_matrix_set_color(14,  0x00, 0x00, 0x00);


    return led_max < DRIVER_LED_TOTAL;
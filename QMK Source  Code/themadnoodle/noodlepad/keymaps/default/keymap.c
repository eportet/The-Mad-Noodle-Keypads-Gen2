#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     /* LAYER 0
     * ,-----------------------.
     * |  <<   |  PLAY |   >>  |  ENCODER - PRESS (PAUSE/PLAY) / KNOB (VOLUME CONTROL)
     * |-------+-------+-------|
     * |  `/~  |   UP  |   F2  |
     * |-------+-------+-------|
     * |  LEFT |  DOWN | RIGHT |
     * `-----------------------'
     */

    [0] = LAYOUT_ortho_3x3(
      KC_MPRV, LT(1, KC_MPLY), KC_MNXT, 
      KC_GRAVE, KC_UP, LT(2, KC_F2),
      KC_LEFT, KC_DOWN, KC_RIGHT
      ),


    /* LAYER 1
     * ,-----------------------.
     * | MODE+ |       | MODE- |  ENCODER - PRESS (NA) / KNOB (Hue Control)
     * |-------+-------+-------|
     * |  SPD- |  SPD+ |RGB TOG|
     * |-------+-------+-------|
     * |  SAT+ |  SAT- |Bright |
     * `-----------------------'
     */
    
    [1] = LAYOUT_ortho_3x3(
      RGB_MOD,KC_TRNS, RGB_RMOD, 
      RGB_SPI, RGB_SPD, RGB_TOG, 
      RGB_SAI, RGB_SAD, RGB_VAI
      ),

      
    /* LAYER 2
     * ,-----------------------.
     * |   <<  |  MUTE |  >>   |  ENCODER - PRESS (MUTE) / KNOB (VOLUME CONTROL)
     * |-------+-------+-------|
     * |  STOP |  PLAY |       |
     * |-------+-------+-------|
     * | CALC  | MAIL  | PC/FN |
     * `-----------------------'
     */
    
    [2] = LAYOUT_ortho_3x3(
      KC_MPRV, KC_MUTE, KC_MNXT, 
      KC_MSTP, KC_MPLY, KC_TRNS,
      KC_CALC, KC_MAIL, KC_MYCM
      )

};

void encoder_update_user(uint8_t index, bool clockwise) {
    
  switch (get_highest_layer(layer_state)) {
      case 1:
          if (clockwise) {
              rgblight_increase_hue();
          } else {
              rgblight_decrease_hue();
          }
          break;
      default:
          if (clockwise) {
              tap_code(KC_VOLU);
          } else {
              tap_code(KC_VOLD);
          }
          break;
          
  }
}

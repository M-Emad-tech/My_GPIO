/* 
 * File:   application.c
 * Author: Okda
 *
 * Created on July 27, 2024, 10:37 PM
 */


#include "applicaiton.h"
/*
 * 
 */
pin_config_t led_1={
    .port = PORTC_INDEX,
    .pin = GPIO_PIN0,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_HIGH
};
pin_config_t led_2={
    .port = PORTC_INDEX,
    .pin = GPIO_PIN1,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_HIGH
};
pin_config_t led_3={
    .port = PORTC_INDEX,
    .pin = GPIO_PIN2,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_HIGH
};

pin_config_t btn_1={
    .port = PORTD_INDEX,
    .pin = GPIO_PIN0,
    .direction = GPIO_DIRECTION_INPUT,
    .logic = GPIO_HIGH
};


    Std_ReturnType ret =E_NOK;
    direction_t led_1_st;
    logic_t btn1_status;
    
int main() {
    ret=gpio_pin_direction_initialize(&btn_1);
    
     
    
    ret=gpio_pin_direction_initialize(&led_1);
    ret=gpio_pin_write_logic(&led_1,GPIO_HIGH);
    
    ret=gpio_pin_direction_initialize(&led_2);
    ret=gpio_pin_write_logic(&led_2,GPIO_HIGH);

    ret=gpio_pin_direction_initialize(&led_3);
    ret=gpio_pin_write_logic(&led_3,GPIO_HIGH);
 
    ret=gpio_pin_direction_initialize(NULL);
    while(1){
       ret=gpio_pin_read_logic(&btn_1,&btn1_status);
    }
    return (EXIT_SUCCESS);
}


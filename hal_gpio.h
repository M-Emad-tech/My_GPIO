/* 
 * File:   hal_gpio.h
 * Author: Okda
 *
 * Created on July 27, 2024, 10:47 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H


#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "hal_gpio_cfg.h"

#define BIT_MASK    (uint8)1
#define PORT_PIN_MAX_NUMBER 8
#define PORT_MAX_NUMBER     5

#define GPIO_PORT_PIN_CONFIGURATIONS CONFIG_ENABLE
#define GPIO_PORT_CONFIGURATIONS     CONFIG_ENABLE

typedef enum{
    GPIO_LOW,
    GPIO_HIGH
}logic_t;
typedef enum{
    GPIO_DIRECTION_OUTPUT,
    GPIO_DIRECTION_INPUT
}direction_t;
typedef enum{
    GPIO_PIN0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}pin_index_t;

typedef enum{
    PORTA_INDEX,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef struct{
    uint8 port:3;
    uint8 pin:3;
    uint8 direction:1;
    uint8 logic:1 ;
}pin_config_t;
/*Section : Macros Functions Declaration*/
#define HWREG8(_X)    (*((volatile uint8*)(_X)))
#define SET_BIT(REG,BIT_POSN)    (REG|=(BIT_MASK<<BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)  (REG&=~(BIT_MASK<<BIT_POSN))
#define TOGGLE_BIT(REG,BIT_POSN) (REG^=(BIT_MASK<<BIT_POSN))
#define READ_BIT(REG,BIT_POSN)   ((REG>>BIT_POSN)&BIT_MASK)

/* Section: Function Declarations*/
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *_pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config,direction_t *dic_status);
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config,logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config,logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config);


Std_ReturnType gpio_port_direction_initialize(port_index_t port, uint8 direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t port,uint8 *direction_status);
Std_ReturnType gpio_port_write_logic(const port_index_t port,uint8 logic);
Std_ReturnType gpio_port_read_logic(const port_index_t port,uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(const port_index_t port);









#endif	/* HAL_GPIO_H */


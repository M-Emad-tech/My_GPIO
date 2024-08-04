#include "hal_gpio.h"
/* Section: Function Declarations*/

volatile uint8 * tris_registers[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8 * lat_registers[] ={&LATA,&LATB,&LATC,&LATD,&LATE};
volatile uint8 * port_registers[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
/**
 * 
 * @param _pin_config
 * @return 
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *_pin_config){
    Std_ReturnType ret=E_OK;
    if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret=E_NOK;
    }
    else{
        switch (_pin_config->direction){
        case (GPIO_DIRECTION_OUTPUT):
            CLEAR_BIT(*tris_registers[_pin_config->port],_pin_config->pin);
            break;
        case (GPIO_DIRECTION_INPUT):
            SET_BIT(*tris_registers[_pin_config->port],_pin_config->pin);
            break;
        default:
            ret=E_NOK;
    }
    }
   
    return ret;
}
#endif

#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config,direction_t *dic_status){
    Std_ReturnType ret=E_OK;
    if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret=E_NOK;
    }
    else{
        *dic_status=READ_BIT(*tris_registers[_pin_config->port],_pin_config->pin);
    }
    
   
    return ret;
}
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config,logic_t logic){

    Std_ReturnType ret=E_OK;
    if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret=E_NOK;
    }
    else{
        switch(_pin_config->logic){
                case GPIO_LOW :
                    CLEAR_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
                    break;
                case GPIO_HIGH :
                    SET_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
                    break;
                default:
                    ret=E_NOK;
        }
    }
    
   
    return ret;
}
#endif

#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config,logic_t *logic){
    Std_ReturnType ret=E_OK;
    if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret=E_NOK;
    }
    else{
        *logic=READ_BIT(*port_registers[_pin_config->port],_pin_config->pin);
        
        }
    
    
   
    return ret;
}
#endif


#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config){
    Std_ReturnType ret=E_OK;
    if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER-1){
        ret=E_NOK;
    }
    else{
        TOGGLE_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
        
        }
    
    
   
    return ret;
    
    
    
}
#endif

#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_port_direction_initialize(port_index_t port , uint8 direction){
    Std_ReturnType ret= E_OK;
    if(port>PORT_MAX_NUMBER-1){
        ret=E_NOK;
    }
    else{
        *tris_registers[port]=direction;
    }
    }
#endif


#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_port_get_direction_status(port_index_t port,uint8 *direction_status){
    Std_ReturnType ret= E_OK;
    if(port>PORT_MAX_NUMBER-1){
        ret=E_NOK;
    }
    else{
        *direction_status=*tris_registers[port];
    }
}
#endif


#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic(const port_index_t port,uint8 logic){
    Std_ReturnType ret= E_OK;
    if(port>PORT_MAX_NUMBER-1){
        ret=E_NOK;
    }
    else{
        *lat_registers[port]=logic;
    }
}
#endif


#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic(const port_index_t port,uint8 *logic){
    Std_ReturnType ret= E_OK;
    if( (port>PORT_MAX_NUMBER-1) || logic==NULL){
        ret=E_NOK;
    }
    else{
        *logic=*lat_registers[port];
    }
}
#endif


#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic(const port_index_t port){
    Std_ReturnType ret= E_OK;
    if(port>PORT_MAX_NUMBER-1){
        ret=E_NOK;
    }
    else{
        *lat_registers[port]=~(*lat_registers[port]);
    }
}
#endif

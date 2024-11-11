// includes
#include <stdint.h>

//vector function prototype
//reset handler and default handler prototype
void reset_handler(void); 
void default_handler(void);

// ISR callback function prototype
void INT0_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void INT1_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void PCINT0_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void PCINT1_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void PCINT2_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void WDT_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void TIMER2_COMPA_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void TIMER2_COMPB_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void TIMER2_OVF_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void TIMER1_CAPT_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void TIMER1_COMPA_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void TIMER1_COMPB_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void TIMER1_OVF_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void TIMER0_COMPA_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void TIMER0_COMPB_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void TIMER0_OVF_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void SPI_STC_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void USART_RX_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void USART_UDRE_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void USART_TX_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void ADC_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void EE_READY_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void ANALOG_COMP_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void TWI_handler_callback      (void)__attribute__((weak, alias("default_handler")));
void SPM_READY_handler_callback      (void)__attribute__((weak, alias("default_handler")));



// vector table
uint16_t vector[] __attribute__((section(".isr_vector")))= {
    (uint16_t)&reset_handler,
    (uint16_t)&INT0_handler_callback,
    (uint16_t)&INT1_handler_callback,
    (uint16_t)&PCINT0_handler_callback,
    (uint16_t)&PCINT1_handler_callback,
    (uint16_t)&PCINT2_handler_callback,
    (uint16_t)&WDT_handler_callback,
    (uint16_t)&TIMER2_COMPA_handler_callback,
    (uint16_t)&TIMER2_COMPB_handler_callback,
    (uint16_t)&TIMER2_OVF_handler_callback,
    (uint16_t)&TIMER1_CAPT_handler_callback,
    (uint16_t)&TIMER1_COMPA_handler_callback,
    (uint16_t)&TIMER1_COMPB_handler_callback,
    (uint16_t)&TIMER1_OVF_handler_callback,
    (uint16_t)&TIMER0_COMPA_handler_callback,
    (uint16_t)&TIMER0_COMPB_handler_callback,
    (uint16_t)&TIMER0_OVF_handler_callback,
    (uint16_t)&SPI_STC_handler_callback,
    (uint16_t)&USART_RX_handler_callback,
    (uint16_t)&USART_UDRE_handler_callback,
    (uint16_t)&USART_TX_handler_callback,
    (uint16_t)&ADC_handler_callback,
    (uint16_t)&EE_READY_handler_callback,
    (uint16_t)&ANALOG_COMP_handler_callback,
    (uint16_t)&TWI_handler_callback,
    (uint16_t)&SPM_READY_handler_callback
};


// function defination
void reset_handler(void)
{

}

void default_handler(void)
{

}

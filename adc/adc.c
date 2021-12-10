/*
 * File:   sleep.c
 * Author: Matheus Gois Vieira
 *
 */


#include <xc.h>
#include "config.h"

// Resolu��o = (Vref+ - Vref-)/(2^n -1) = 5/1023 = 0.004887V
void main(void) {
    // Definir portas como entrada e sa�das
    TRISA=0xFF; 
    TRISB=0x00;
    TRISC=0x00;
    PORTB = 0x00; 
    PORTC = 0x00; 
    
    // Selecionar velocidade do clock FOSC/16
    ADCON1bits.ADCS = 0b101;
    
    // Selecionar canal | Right justified | VDD | AN0 | GO/FONE = 1 | ADC = 1
    ADCON0 = 0x83;
  
    while(1){
        if (ADCON0bits.GO_DONE == 0){ // Depois da convers�o o bit GO_DONE zerado
            ADCON0bits.GO_DONE = 1; // Definir como 1 para iniciar a pr�xima convers�o
            PORTB = ADRESL; // 8 bits menos significativos do resultado do adc
            PORTC = ADRESH; // 8 bits mais significativos do resultado do adc
        }
    }
    return;
}

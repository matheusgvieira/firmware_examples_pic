/*
 * File:   sleep.c
 * Author: Matheus Gois Vieira
 *
 */


#include <xc.h>
#include "config.h"

int value_an0 = 0;
int get_value_an0(void);

// Resolução = (Vref+ - Vref-)/(2^n -1) = 5/1023 = 0.004887V
void main(void) {
    
    // Setup
    OSCCONbits.IRCF = 0b111; // 8MHz
    OPTION_REG = 0x0E; // Prescaler WDT 1:64
    TRISCbits.TRISC4 = 0; //RBs são saída digital
    PORTCbits.RC4 = 1; // Liga RB4 = 1    
    ADCON1bits.ADCS = 0b101; // Selecionar velocidade do clock FOSC/16
    ADCON0 = 0x83; // Selecionar canal | Right justified | VDD | AN0 | GO/FONE = 1 | ADC = 1
    CLRWDT(); // limpa o WDT;
    
    // Loop
    while(1){
        CLRWDT(); // limpa o WDT
        value_an0 = get_value_an0(); // Lê o valor de AN0
        PORTCbits.RC4 = ~PORTCbits.RC4;
        SLEEP(); // Entra no modo sleep
    }
    return;
}

int get_value_an0(void){
    int an0;
    while(1){
        if (ADCON0bits.GO_DONE == 0){ // Depois da conversão o bit GO_DONE zerado
            ADCON0bits.GO_DONE = 1; // Definir como 1 para iniciar a próxima conversão
            an0 = ADRESL + (ADRESH *256); // Armazena o valor em um inteiro
            break;                              // Termina Leitura
        }
    }
    return an0;
}


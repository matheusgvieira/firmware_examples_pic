/*
 * File:   sleep.c
 * Author: Matheus Gois Vieira
 *
 */


#include <xc.h>
#include "config.h"

// Resolução = (Vref+ - Vref-)/(2^n -1) = 5/1023 = 0.004887V
void main(void) {
    
    // Setup
    OSCCONbits.IRCF = 0b111; // 8MHz
    OPTION_REG = 0x0E; // Prescaler WDT 1:64
    TRISCbits.TRISC4 = 0; //RBs são saída digital
    PORTCbits.RC4 = 1; // Liga RB4 = 1    
    CLRWDT(); // limpa o WDT;
    // Loop
    while(1){
        CLRWDT(); // limpa o WDT
        PORTCbits.RC4 = ~PORTCbits.RC4;
        SLEEP(); // Entra no modo sleep
    }
    return;
}


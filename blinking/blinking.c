/*
 * File:   blink.c
 * Author: Matheus Gois Vieira
 *
 */


#include <xc.h>

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)

#define _XTAL_FREQ 8000000

void main(void) {
    
    // Setup
    OSCCONbits.IRCF = 0b111; // 8MHz
    TRISCbits.TRISC4 = 0; //RBs são saída digital
    PORTCbits.RC4 = 1; // Liga RB4 = 1    
    
    // Loop
    while(1){
        PORTCbits.RC4 = ~PORTCbits.RC4;
        __delay_ms(5000);
    }
    return;
}


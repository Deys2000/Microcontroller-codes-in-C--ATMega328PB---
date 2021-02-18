#include <xc.h>
#include <stdint.h>
uint8_t globalvar = 0;
int main(void){
    
    //AND example solution
    // (0b0011) AND (0b0001) will result in 0b0001, stored in r22
    asm("LDI    r17, 0b0110");
    asm("INC    r17");
    //asm("AND    r22, r19");
    
    //Part 4
    asm("LDI    r16, 0xF");
    asm("DEC    r16");
    asm("DEC    r16");
    asm("STS (globalvar), r16");

    
    
    //set PB5 to out
    //DDRB |= (1U<<5);
    
    //drive PB5 to 0, Leave others the same
    //PORTB &= ~(1U<<5);
    
    //Drove PB5 to 1. Leave other the same
    //PORTB |= (1U<<5);
    
    //Invert PB5. Leave others the same
    //PORTB^=(1U<<5);
    
    return(1);
}
#include <xc.h>
/*
int main (void) {
    DDRB = (1<<5);
    PORTB = (1<<5);
    
    int32_t c = 0;
    
    TCCR0A |= (1<<WGM01); //CTC Mode
    TCCR0B |= (1<<CS00)|(1<<CS02); // 1024 times using the 101 bit pattern
    while(1){
        OCR0A = 0xFF;

        while((TIFR0&(1<<TOV0))==0){
            asm("NOP");
        }
        c=0;
        while(c < 4000000){
            c++;
        }
        TIFR0 |= (1<<TOV0); // Resetting the flag
        PORTB ^= (1<<5);
    }
    return 0;
}
*/

#include <avr/interrupt.h>
#define ISR_TIMER0_RELOAD (61)

int main (void) {
    DDRB = (1<<DDB5);
    PORTB = (1<<5);     
    TCCR0A |= (1<<WGM01); //CTC Mode
    OCR0A = 0xFF;
    TIMSK0 |= (1<<OCIE0A);
    TCCR0B |= (1<<CS00)|(1<<CS02); // 1024 times using the 101 bit pattern
    sei();
    while(1){
         asm("NOP");
    }  
}
//timer 0 overflow interrupt
ISR (TIMER0_COMPA_vect){
    static int32_t isr_count = ISR_TIMER0_RELOAD*4;
    //run the internal counter, once per ISR call
    if(isr_count > 0){
        isr_count--;
    }
    //toggle the LED on PB5
    else{
        PORTB ^= (1<<5);
        isr_count = ISR_TIMER0_RELOAD*4;
    }
}

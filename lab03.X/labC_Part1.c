#include <xc.h>
#include <stdint.h>

int32_t x =150000;

void delay_function( volatile int32_t x);

int main(void)
{
    //set PB5 to be out
    DDRB = (1<<5); //bit 5 is an output

    while(1){
        delay_function(x);
        PORTB = 0;
        
        delay_function(x);
        PORTB = (1<<5);
    }
    return 0;   
}
void delay_function(volatile int32_t x){
    while(x>0){
            x = x-1;
        }
    }



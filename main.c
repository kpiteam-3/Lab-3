#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>

// States
void port_on();
void port_off();

// State pointer
void (*statefunc)() = port _on;

void port_on() {
  ; // in this place   GPIO pin set to on
  statefunc = port_off;
}

void port_off() {
 ;// in this place   GPIO pin set to off
  statefunc = port_on;
}

int main() {
  (*statefunc)() =  port_on;

  while(1) {
    (*statefunc)();
    _delay_ms(1000); // sleep for a second
  }

  return 1; // should not get here
}

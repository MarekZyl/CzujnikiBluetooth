#include "Adafruit_TinyUSB.h"

int flag = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
//NRF52 Timer setup
  NRF_TIMER2->MODE = TIMER_MODE_MODE_Timer;
  NRF_TIMER2->TASKS_CLEAR = 1; 
//Clear the task first so it's usable later
  NRF_TIMER2->BITMODE = TIMER_BITMODE_BITMODE_16Bit; 
//Set 16 bit timer resolution
  NRF_TIMER2->PRESCALER = 6; 
// divided by 2^6 
  NRF_TIMER2->CC[0] = 20;		
//Set these to the compare values
  NRF_TIMER2->INTENSET=(TIMER_INTENSET_COMPARE0_Enabled << TIMER_INTENSET_COMPARE0_Pos); //Enable interupt
  NVIC_EnableIRQ(TIMER2_IRQn);
  NRF_TIMER2->TASKS_START = 1;
}
void loop() {
  Serial.println(flag);
  delay (100);
}
extern "C" {
  void TIMER2_IRQHandler() {
    if (NRF_TIMER2->EVENTS_COMPARE[0] !=0) {
      NRF_TIMER2->EVENTS_COMPARE[0] = 0;    //Clear compare register 
      flag++;
    }
  }
}

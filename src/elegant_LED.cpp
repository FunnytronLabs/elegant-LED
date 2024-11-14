/*
  elegant_LED.h - Arduino ESP32 library for controlling LED's, including: on, off, blinking/pulsing.
  Created by Joseph Elias [Funnytron Labs], June 28, 2024.
  Released into the public domain.
*/

// === INCLUDES === //
#include "elegant_LED.h"
#include "Arduino.h"


// === METHODS === //
elegant_LED::elegant_LED(int channel, int bit_resolution, int frequency, int pin)
{
  this->channel        = channel;
  this->bit_resolution = bit_resolution;
  this->duty_max       = (1<<bit_resolution) - 1;
  this->frequency      = frequency;
  this->pin            = pin;
  
  //ledcSetup(channel, frequency, bit_resolution); // OLD API
  //ledcAttachPin(pin, channel);                   // OLD API

  ledcAttach(pin, frequency, bit_resolution); // NEW API
}

void elegant_LED::on(void)
{
  //ledcWrite(channel, duty_max); // OLD API
  ledcWrite(pin, duty_max); // NEW API
}

void elegant_LED::off(void)
{
  //ledcWrite(channel, 0); // OLD API

  ledcWrite(pin, 0); // NEW API
}

void elegant_LED::rising_pulse(unsigned long period)
{
  static unsigned long time_start = millis();
  
  unsigned long time_now = millis();
  unsigned long time_difference = time_now - time_start;
  
  if(time_difference > period){
    time_start = millis(); //time_start = time_now - time_difference;
    time_difference = 0; //time_difference -= period;
  }

  unsigned int duty_now = (time_difference * duty_max) / period; // = gradient * time_difference : gradient = duty_max/period
  
  //ledcWrite(channel, duty_now); // OLD API
  ledcWrite(pin, duty_now); // NEW API
}

void elegant_LED::falling_pulse(unsigned long period) // !!! NEEDS CORRECTING !!!
{
  static unsigned long time_start = millis();
  
  unsigned long time_now = millis();
  unsigned long time_difference = time_now - time_start;
  
  if(time_difference > period){
    time_start = millis(); //time_start = time_now - time_difference;
    time_difference = 0; //time_difference -= period;
  }

  unsigned int duty_now = (time_difference * duty_max) / period; // = gradient * time_difference : gradient = duty_max/period
  
  //ledcWrite(channel, duty_now); // OLD API
  ledcWrite(pin, duty_now); // NEW API
}

void elegant_LED::rising_falling_pulse(unsigned long period) // !!! NEEDS CORRECTING !!!
{
  static unsigned long time_start = millis();
  
  unsigned long time_now = millis();
  unsigned long time_difference = time_now - time_start;
  
  if(time_difference > period){
    time_start = millis(); //time_start = time_now - time_difference;
    time_difference = 0; //time_difference -= period;
  }

  unsigned int duty_now = (time_difference * duty_max) / period; // = gradient * time_difference : gradient = duty_max/period
  
  //ledcWrite(channel, duty_now); // OLD API
  ledcWrite(pin, duty_now); // NEW API
}

void elegant_LED::sine_pulse(unsigned long period) // !!! NEEDS CORRECTING !!!
{
  static unsigned long time_start = millis();
  
  unsigned long time_now = millis();
  unsigned long time_difference = time_now - time_start;
  
  if(time_difference > period){
    time_start = millis(); //time_start = time_now - time_difference;
    time_difference = 0; //time_difference -= period;
  }

  unsigned int duty_now = (time_difference * duty_max) / period; // = gradient * time_difference : gradient = duty_max/period
  
  //ledcWrite(channel, duty_now); // OLD API
  ledcWrite(pin, duty_now); // NEW API
}

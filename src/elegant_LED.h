/*
  elegant_LED.h - Arduino ESP32 library for controlling LED's, including: on, off, blinking/pulsing.
  Created by Joseph Elias [Funnytron Labs], June 28, 2024.
  Released into the public domain.
*/

#ifndef elegant_LED_h
#define elegant_LED_h


class elegant_LED
{
  private:
    int channel;        // E [0,16] on ESP32
    int bit_resolution; // E [0,14] OR E [0,20] on ESP32
    int duty_max;       // = (2^bit_resolution) - 1
    int frequency;      // Hz
    int pin;            // GPIO PIN

  public:
    elegant_LED(int channel, int bit_resolution, int frequency, int pin);
    void on(void);
    void off(void);
    void rising_pulse(unsigned long period);
    /*void falling_pulse(void);
    void rising_falling_pulse(void);
    void sine_pulse(void);*/
};

#endif

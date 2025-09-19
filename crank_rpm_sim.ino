// This sketch simulates the output of a Hall sensor on a 36-1 trigger wheel. Square wave output.
// A VR sensor puts out a sine wave and for this sketch to be useful, would probably have to 
// make a simple circuit to convert the square wave to bi-polar to immuate the bi-polar nature
// of a sine wave. And then usefulness would depend on the automotive ECU or intermediary module
// (EDISx) processing the signal.

#include <Arduino.h>

void setup() {
  pinMode(9, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(115200);           // added by LG
}

void loop() {
  int a, wait;
  wait = 100;
  while (1) {
    for (a = 0; a < 35; a++)      // good for 35 iterations - 0 thru 34 
    {
      digitalWrite(9, HIGH);      // substituted by LG for incompatibe statement - R4 runs at 48mhz. Equal trade?
      //PORTB |= B00000010;       // not compatible with the UNO R4
      delayMicroseconds(wait);    // HIGH and LOW each on for value of wait - 50% duty cycle (square wave)
      digitalWrite(9, LOW);       // substituted by LG for incompatibe statement - R4 runs at 48mhz. Equal trade?
      //PORTB &= !B00000010;      // not compatible with the UNO R4
      delayMicroseconds(wait);    // HIGH and LOW each on for value of wait - 50% duty cycle (square wave)
    }
    wait = analogRead(A1) + 1 * 64;  // pot feeding A0 variable voltages to simulate changing RPM ???  64=min 1087=max wait value
    delayMicroseconds(wait * 2);     // missing tooth every 36th count - *2 covers the HIGH and LOW
    //Serial.println(wait);          // added by LG - takes a lot of time - use only for verification of changing "wait"
  }
}

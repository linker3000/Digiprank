// Program to toggle CAPS LOCK on and off.

#include <DigiKeyboard.h>

int led = 1;  //  Model A =pin 1 (otherwise it's 0)
long tog_wait = 600000; // How long between CAPS LOCK toggles. 600000mS = 10 mins.
long tog_jitter = 120000;  // a bit of jitter in the delay.
//int tog_wait = 30000; // How long between CAPS LOCK toggles. 30 sec for testing.
//int tog_jitter = 10000;  // shorter for testing.

void setup() {
  pinMode(led, OUTPUT);
  DigiKeyboard.update();
  digitalWrite(led, 0);
  delay(1000);
}

void loop() {
  DigiKeyboard.sendKeyStroke(57);
  digitalWrite(led, 1);
  delay(1000);
  digitalWrite(led, 0);
  delay(abs(tog_wait+random(-tog_jitter,tog_jitter)));
}

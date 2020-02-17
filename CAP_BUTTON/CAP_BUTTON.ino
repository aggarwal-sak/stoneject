#include "OneButton.h"                              //we need the OneButton library
 
 
OneButton button(D3, true);                         //attach a button on pin A1 to the libraRY
#define g D8
#define w D7
#define b D6
 
 
void setup() {
 
  pinMode(g, OUTPUT);                              // sets the digital pin as output
  pinMode(w, OUTPUT);                              // sets the digital pin as output
  pinMode(b, OUTPUT);                              // sets the digital pin as output
 
     
  button.attachDoubleClick(doubleclick);            // link the function to be called on a doubleclick event.
  button.attachClick(singleclick);                  // link the function to be called on a singleclick event.
  button.attachLongPressStop(longclick);            // link the function to be called on a longpress event.
}
 
 
 
void loop() {
 
  button.tick();                                    // check the status of the button
 
 
  delay(10);                                        // a short wait between checking the button
} // loop
 
 
 
void doubleclick() {                                // what happens when button is double-clicked
 digitalWrite(g,HIGH);                             // light the green LED
 delay(1000);                                       // wait one second
 digitalWrite(g,LOW);                              // turn off green LED
}
 
void singleclick(){                                 // what happens when the button is clicked
  digitalWrite(w,HIGH);                            // light the red LED
 delay(1000);                                       // wait one second
 digitalWrite(w,LOW);                              // turn off the gren led
}
 
void longclick(){                                   // what happens when buton is long-pressed
  digitalWrite(b,HIGH);                            // light the blue LED
 delay(1000);                                       // wait one second
 digitalWrite(b,LOW);                              // turn off the blue LED
}

//#include "OneButton.h"                              //we need the OneButton library
//
//
//OneButton button(D7, true);                         //attach a button on pin A1 to the libraRY
//#define b D8
//
//void setup()
//{
//  // sets the digital pin as output
//  pinMode(b, OUTPUT);                              // sets the digital pin as output
//
//  button.attachLongPressStop(longclick);            // link the function to be called on a longpress event.
//}
//
//
//
//void loop() {
//
//  button.tick();                                    // check the status of the button
//
//
//  delay(10);                                        // a short wait between checking the button
//} // loop
//
//
//
//void doubleclick() {                                // what happens when button is double-clicked
//  digitalWrite(g, HIGH);                            // light the green LED
//  delay(1000);                                       // wait one second
//  digitalWrite(g, LOW);                             // turn off green LED
//}
//
//void singleclick() {                                // what happens when the button is clicked
//  digitalWrite(w, HIGH);                           // light the red LED
//  delay(1000);                                       // wait one second
//  digitalWrite(w, LOW);                             // turn off the gren led
//}
//
//void longclick() {                                  // what happens when buton is long-pressed
//  digitalWrite(b, HIGH);                           // light the blue LED
//  delay(1000);                                       // wait one second
//  digitalWrite(b, LOW);                             // turn off the blue LED
//}

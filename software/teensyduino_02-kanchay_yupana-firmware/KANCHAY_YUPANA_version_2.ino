//Kanchay_Yupana_X



#include <Bounce.h>

// the MIDI channel number to send messages
const int channel = 2;

boolean toggleState = HIGH;
// the MIDI continuous controller for each analog input

// potenciometros

const int controllerA1 = 41; // 41 = pot 
const int controllerA2 = 42; // 42 = pot 
const int controllerA3 = 43; // 43 = pot
const int controllerA4 = 44; // 44 = pot
const int controllerA0 = 45; // 45 = pot


// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.

// 5 = 5 ms debounce time
Bounce button1 = Bounce(1, 5);  // which is appropriate for good
Bounce button2 = Bounce(2, 5);  // quality mechanical pushbuttons
Bounce button3 = Bounce(3, 5);  // if a button is too "sensitive"
Bounce button4 = Bounce(4, 5);  // to rapid touch, you can  // increase this time.
Bounce button5 = Bounce(5, 5);
Bounce button6 = Bounce(6, 5);
Bounce button7 = Bounce(7, 5);
Bounce button8 = Bounce(8, 5);
Bounce button9 = Bounce(9, 5);  // which is appropriate for good
Bounce button10 = Bounce(10, 5);  // quality mechanical pushbuttons
Bounce button11 = Bounce(11, 5);  // if a button is too "sensitive"
Bounce button12 = Bounce(12, 5);  // to rapid touch, you can  // increase this time.
Bounce button13 = Bounce(13, 5);
Bounce button14 = Bounce(14, 5);
Bounce button15 = Bounce(15, 5);
Bounce button16 = Bounce(16, 5);


void setup() {

  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);  // Teensy++ 2.0 LED, may need 1k resistor pullup
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);  // Teensy++ 2.0 LED, may need 1k resistor pullup
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
}

// store previously sent values, to detect changes



int previousA1 = -1;
int previousA2 = -1;
int previousA3 = -1;
int previousA4 = -1;
int previousA0 = -1;




elapsedMillis msec = 0;

void loop() {
  // only check the analog inputs 50 times per second,
  // to prevent a flood of MIDI messages
  // if (msec >= 20) {
  if (msec >= 60) {
    msec = 0;

    //int n0 = analogRead(A0) / 8;


    //POTENCIOMETROS

    int p35 = analogRead(A0) / 8;
    //int p31 = map(analogRead(A1), 0, 60, 0, 127);
    int p31 = analogRead(A1) / 8;
    //int p31 = map(analogRead(A1), 0, 25, 0, 127);
    int p32 = analogRead(A2) / 8;
    int p33 = analogRead(A3) / 8;
    int p34 = analogRead(A4) / 8;






    // only transmit MIDI messages if analog input changed

    //potenciometros
      if (p35 != previousA0) {
      usbMIDI.sendControlChange(controllerA0, p35, channel);
      previousA0 = p35;
    }

    if (p31 != previousA1) {
      usbMIDI.sendControlChange(controllerA1, p31, channel);
      previousA1 = p31;
    }

    if (p32 != previousA2) {
      usbMIDI.sendControlChange(controllerA2, p32, channel);
      previousA2 = p32;
    }
    if (p33 != previousA3) {
      usbMIDI.sendControlChange(controllerA3, p33, channel);
      previousA3 = p33;
    }
    if (p34 != previousA4) {
      usbMIDI.sendControlChange(controllerA4, p34, channel);
      previousA4 = p34;
    }




  }



  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();
  button10.update();
  button11.update();
  button12.update();
  button13.update();
  button14.update();
  button15.update();  
  button16.update();





  // Check each button for "falling" edge.
  // Send a MIDI Note On message when each button presses
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)

/*
  if (button1.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(41, 99, channel); //cuerda4
    else usbMIDI.sendNoteOn(41, 99, channel);//off
    toggleState = !toggleState;
  }
  if (button2.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(42, 99, channel); //cuerda 6
    else usbMIDI.sendNoteOn(42, 99, channel);//off
    toggleState = !toggleState;
  }
  if (button3.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(43, 99, channel); //cuerda9
    else usbMIDI.sendNoteOn(43, 99, channel);//off
    toggleState = !toggleState;
  }
  if (button4.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(44, 99, channel); //cuerda7
    else usbMIDI.sendNoteOn(44, 99, channel);//off
    toggleState = !toggleState;
  }
  if (button5.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(45, 99, channel); //cuerda1 on
    else usbMIDI.sendNoteOn(45, 99, channel); //off
    toggleState = !toggleState;
  }
  if (button6.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(46, 99, channel); //cuerda1 on
    else usbMIDI.sendNoteOn(65, 99, channel); //off
    toggleState = !toggleState;
  }
  if (button7.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(47, 99, channel); //cuerda1 on
    else usbMIDI.sendNoteOn(47, 99, channel); //off
    toggleState = !toggleState;
  }
  if (button8.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(48, 99, channel); //cuerda1 on
    else usbMIDI.sendNoteOn(48, 99, channel); //off
    toggleState = !toggleState;
  }
  
  if (button9.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(49, 99, channel); //cuerda4
    else usbMIDI.sendNoteOn(49, 99, channel);//off
    toggleState = !toggleState;
  }
  if (button10.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(50, 99, channel); //cuerda 6
    else usbMIDI.sendNoteOn(50, 99, channel);//off
    toggleState = !toggleState;
  }
  if (button11.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(51, 99, channel); //cuerda9
    else usbMIDI.sendNoteOn(52, 99, channel);//off
    toggleState = !toggleState;
  }
  if (button12.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(52, 99, channel); //cuerda7
    else usbMIDI.sendNoteOn(52, 99, channel);//off
    toggleState = !toggleState;
  }
  if (button13.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(53, 99, channel); //cuerda1 on
    else usbMIDI.sendNoteOn(53, 99, channel); //off
    toggleState = !toggleState;
  }
  if (button14.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(54, 99, channel); //cuerda1 on
    else usbMIDI.sendNoteOn(54, 99, channel); //off
    toggleState = !toggleState;
  }
  if (button15.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(55, 99, channel); //cuerda1 on
    else usbMIDI.sendNoteOn(55, 99, channel); //off
    toggleState = !toggleState;
  }
  if (button16.fallingEdge()) {
    if (toggleState) usbMIDI.sendNoteOn(56, 99, channel); //cuerda1 on
    else usbMIDI.sendNoteOn(56, 99, channel); //off
    toggleState = !toggleState;
  }
*/
  // aqui el codigo nuevo 

  
   
  if (button1.fallingEdge()) {
    usbMIDI.sendNoteOn(41, 99, channel);  // 61 = C#4
  }
  if (button2.fallingEdge()) {
    usbMIDI.sendNoteOn(42, 99, channel);  // 62 = D4
  }
  if (button3.fallingEdge()) {
    usbMIDI.sendNoteOn(43, 99, channel);  // 63 = D#4
  }
  if (button4.fallingEdge()) {
    usbMIDI.sendNoteOn(44, 99, channel);  // 64 = E4
  }
  if (button5.fallingEdge()) {
    usbMIDI.sendNoteOn(45, 99, channel);  // 65 = F4
  }
  if (button6.fallingEdge()) {
    usbMIDI.sendNoteOn(46, 99, channel);  // 66 = F#4
  }
  if (button7.fallingEdge()) {
    usbMIDI.sendNoteOn(47, 99, channel);  // 67 = G4
  }
  if (button8.fallingEdge()) {
    usbMIDI.sendNoteOn(48, 99, channel);  // 68 = G#4
  }
  if (button9.fallingEdge()) {
    usbMIDI.sendNoteOn(49, 99, channel);  // 69 = A5
  }
  if (button10.fallingEdge()) {
    usbMIDI.sendNoteOn(50, 99, channel);  // 70 = A#5
  }
  if (button11.fallingEdge()) {
    usbMIDI.sendNoteOn(51, 99, channel);  // 71 = B5
  }
   if (button12.fallingEdge()) {
    usbMIDI.sendNoteOn(52, 99, channel);  // 71 = B5
  }
   if (button13.fallingEdge()) {
    usbMIDI.sendNoteOn(53, 99, channel);  // 71 = B5
  }
   if (button14.fallingEdge()) {
    usbMIDI.sendNoteOn(54, 99, channel);  // 71 = B5
  }
   if (button15.fallingEdge()) {
    usbMIDI.sendNoteOn(55, 99, channel);  // 71 = B5
  }
   if (button16.fallingEdge()) {
    usbMIDI.sendNoteOn(56, 99, channel);  // 71 = B5
  }

  // Check each button for "rising" edge
  // Send a MIDI Note Off message when each button releases
  // For many types of projects, you only care when the button
  // is pressed and the release isn't needed.
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  
  
  if (button1.risingEdge()) {
    usbMIDI.sendNoteOff(41, 0, channel);  // 61 = C#4
  }
  if (button2.risingEdge()) {
    usbMIDI.sendNoteOff(42, 0, channel);  // 62 = D4
  }
  if (button3.risingEdge()) {
    usbMIDI.sendNoteOff(43, 0, channel);  // 63 = D#4
  }
  if (button4.risingEdge()) {
    usbMIDI.sendNoteOff(44, 0, channel);  // 64 = E4
  }
  if (button5.risingEdge()) {
    usbMIDI.sendNoteOff(45, 0, channel);  // 65 = F4
  }
  if (button6.risingEdge()) {
    usbMIDI.sendNoteOff(46, 0, channel);  // 66 = F#4
  }
  if (button7.risingEdge()) {
    usbMIDI.sendNoteOff(47, 0, channel);  // 67 = G4
  }
  if (button8.risingEdge()) {
    usbMIDI.sendNoteOff(48, 0, channel);  // 68 = G#4
  }
  if (button9.risingEdge()) {
    usbMIDI.sendNoteOff(49, 0, channel);  // 69 = A5
  }
  if (button10.risingEdge()) {
    usbMIDI.sendNoteOff(50, 0, channel);  // 70 = A#5
  }
  if (button11.risingEdge()) {
    usbMIDI.sendNoteOff(51, 0, channel);  // 71 = B5
  }
if (button12.risingEdge()) {
    usbMIDI.sendNoteOff(52, 0, channel);  // 71 = B5
  }
  if (button13.risingEdge()) {
    usbMIDI.sendNoteOff(53, 0, channel);  // 71 = B5
  }
  if (button14.risingEdge()) {
    usbMIDI.sendNoteOff(54, 0, channel);  // 71 = B5
  }
  if (button15.risingEdge()) {
    usbMIDI.sendNoteOff(55, 0, channel);  // 71 = B5
  }
  if (button16.risingEdge()) {
    usbMIDI.sendNoteOff(56, 0, channel);  // 71 = B5
  }
  while (usbMIDI.read()) {

  }
}

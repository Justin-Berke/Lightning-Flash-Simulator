/*  Lightning Flash Simulator:
      The intent of this project is to add lightning flashes
      to a pair of cloth clouds that are mounted over my 
      daughter's crib (see Ikea HIMMELSK - https://goo.gl/1AFNct).
      Using an Arduino Uno to control two or more LEDs, this program
      will use random numbers to populate a number of parameters --
      such as number of of flashes, flash spacing, cloud-to-cloud
      flash pattern offset, etc. -- to produce a realistic 
      pattern of lightning flashes inside the clouds.
*/

int pinLED = 13;        // Set onboard LED pin address
int flashDelay = 1000;  // Set delay between flash events

int stormRandomNumber(int lowBound, int highBound) {
  // Placeholder function to return flash paramaters
  return random(lowBound, highBound);
}

void flash() {
  // Grab a random number of flashes to blink
  int myValue = stormRandomNumber(0, 5);

  // Loop through a randomly generated number of flashes
  for (int x = 0; x < myValue; x++) {
    // Flash
    digitalWrite(pinLED, HIGH); // Illuminate
    delay(10);                  // Very short "on" state
    digitalWrite(pinLED, LOW);  // Turn off
    delay(200);                 // Pause before next blink iteration
  }
}

void setup() {
  pinMode(pinLED, OUTPUT);  // Set pin as output
}

void loop() {
  flash(); // Call a flash request
  
  delay(flashDelay);   // Pause between flashes
}

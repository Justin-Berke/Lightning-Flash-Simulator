/*  Lightning Flash Simulator:
      The intent of this project is to add lightning flashes
      to a pair of cloth clouds that are mounted over my 
      daughter's crib (see Ikea HIMMELSK - https://goo.gl/1AFNct).
      Using an Arduino Uno to control two or more LEDs, this program
      will use random numbers to populate a number of parameters --
      such as number of of flashes, flash spacing, cloud-to-cloud
      flash pattern offset, etc. -- to produce a realistic 
      pattern of lightning flashes inside the clouds.
<<<<<<< HEAD

      Whenever possible, the parameters used in this model are
      obtained from statistics and figures from NOAA / National 
      Weather Service.
      http://www.nssl.noaa.gov/education/svrwx101/lightning/types

      Items to add/adjust:
       - Step through logical progression and
          ensure it's correct
       - Multi-flash spacing
       - Positive flashes (brighter or longer
          or additional LED)
       - Fine tuning flash parameters
*/


// ARDUINO PARAMETERS
int pinLED_1 = 12;            // Set onboard LED pin addresses
int pinLED_2 = 10;
int onboardLED = 13;

// FLASH PARAMETERS
int flashDelay() {
  return random(20, 600);     // Set delay between flash events
=======
*/

int pinLED = 13;        // Set onboard LED pin address
int flashDelay = 1000;  // Set delay between flash events

int stormRandomNumber(int lowBound, int highBound) {
  // Placeholder function to return flash paramaters
  return random(lowBound, highBound);
>>>>>>> origin/master
}

// FLASH FUNCTION
void flash() {
  // SETUP FLASH COUNT
  int flashCount = random(0, 20);             // Pick 0-20 flashes
  Serial.println(flashCount);                 // Debug print

  // CALCULATE FLASH TYPE AND TRIGGER FLASH EVENT
  int flashType = random(100);                // Pick percentage for flash type
  
  if (flashType <= 20) {                      // Cloud to Ground - 20%
    int cloudEvent = random(2);               // Choose which cloud to flash
    if (cloudEvent == 0) {                    // Flash cloud 1
      for (int i = 0; i < flashCount; i++) {  // Loop through multi-flash
        digitalWrite(pinLED_1, HIGH);         // Illuminate cloud 1
        delay(10);                            // Very short "on" state
        digitalWrite(pinLED_1, LOW);          // Turn off cloud 1
         delay(flashDelay());                 // Pause between flashes
      }
    }
    else {                                    // Flash cloud 2
      for (int i = 0; i < flashCount; i++) {
        digitalWrite(pinLED_2, HIGH);
        delay(10);
        digitalWrite(pinLED_2, LOW);
        delay(flashDelay());
      }
    }
  }
  else {                                      // Cloud to Cloud - 80%
    for (int i = 0; i < flashCount; i++) {  
      digitalWrite(pinLED_1, HIGH);           // Illuminate cloud 1
      digitalWrite(pinLED_2, HIGH);           // Illuminate cloud 2
      delay(10);                            
      digitalWrite(pinLED_1, LOW);            // Turn off cloud 1
      digitalWrite(pinLED_2, LOW);            // Turn off cloud 2
      delay(flashDelay());    
    } 
  } // END Flash type If/Else
} // END void flash

void setup() {
  pinMode(pinLED_1, OUTPUT);    // Set pin as output
  pinMode(pinLED_2, OUTPUT);    // Set pin as output
  Serial.begin(9600);           // Setup return communication (for debug)
  randomSeed(analogRead(0));    // Configure unique random sequence

  pinMode(onboardLED, OUTPUT);   // Turn off onboard LED on pin 13
  digitalWrite(onboardLED, LOW);
}

<<<<<<< HEAD
void loop() {
  flash();             // Call a flash request 
=======
void setup() {
  pinMode(pinLED, OUTPUT);  // Set pin as output
}

void loop() {
  flash(); // Call a flash request
  
>>>>>>> origin/master
  delay(flashDelay);   // Pause between flashes
}

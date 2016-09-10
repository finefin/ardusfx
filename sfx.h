/*
 * SFX for Space Escape
 * 
 * 
 * 
 * 
 */


#include <Arduino.h>
#include "pitches.h"
#define TONE_PIN 8 //Pin of speaker/piezo, use 100 ohm resistor!

int melodies[2][6] = { { NOTE_D3, NOTE_E3, NOTE_C3, NOTE_C2, NOTE_G2, 0 },
                        { NOTE_C3, NOTE_E5, NOTE_C1, NOTE_G1, NOTE_C3, 0}
};


void sndfxSine() {
  float randomWhistle = random (5, 30) * .01;
  int randomPitch = random (150, 2200);
  int randomDur = random (50, 150);
  for (unsigned long i = 0; i <= randomDur; i += 1) {
    int ix = int( sin(i * randomWhistle) * randomPitch ) + randomPitch * 1.1;
    ///Serial.println(ix);
    NewTone(TONE_PIN, ix);
    delay(2);
  }
  noNewTone(TONE_PIN);
}

void sndfxUP() {
  for (unsigned long freq = 125; freq <= 1000; freq += 10) {
    NewTone(TONE_PIN, freq);
    delay(1);
  }
  noNewTone(TONE_PIN);
}

void sndfxDWN() {
  for (unsigned long freq = 1000; freq > 125; freq -= 10) {
    NewTone(TONE_PIN, freq);
    delay(1);
  }
  noNewTone(TONE_PIN);
}

void playRandomMelody(){
 int rndMelody = random (0, 2);
 for (int thisNote = 0; thisNote < 5; thisNote++) {
    NewTone(TONE_PIN, melodies[rndMelody][thisNote], 100);
    delay(50);
    noNewTone(TONE_PIN);
  } 
}


void playRandomSound () {
  //Serial.println ("PLAY RND SND");
  int rndSnd = random (0, 6);
  if (rndSnd < 3) {
    sndfxSine();
  } else if (rndSnd == 4) {
    playRandomMelody();
  } else if (rndSnd == 5) {
    sndfxUP();
  } else {
    sndfxDWN();
  }
}

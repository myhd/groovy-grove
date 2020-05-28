// This sketch helps to do the following:
// Play back MP3s on the Seeedstudio Grove MP3 v2.0 player breakout board.
// Product info: https://wiki.seeedstudio.com/Grove-MP3_v2.0/
// Library download: https://github.com/Seeed-Studio/Seeed_Serial_MP3_Player/archive/master.zip
// Library install info: https://learn.adafruit.com/adafruit-all-about-arduino-libraries-install-use/how-to-install-a-library

#include "KT403A_Player.h"

#ifdef __AVR__
#include <SoftwareSerial.h>
SoftwareSerial SSerial(2, 3); // RX, TX -- change this if player is connected to other pins
#define COMSerial SSerial
#define ShowSerial Serial
KT403A<SoftwareSerial> Mp3Player;
#endif

void setup() {
  ShowSerial.begin(9600);
  COMSerial.begin(9600);
  while (!ShowSerial);
  while (!COMSerial);
  Mp3Player.init(COMSerial);
}

void loop() {

  /*
    we are using "play music in MP3 folder."
    with command structure of playSongMP3(index);
    Naming rules on the SD card:
    MP3/0001.mp3 or MP3/0002.mp3 or MP3/0003.mp3, etc.
    see:  https://github.com/Seeed-Studio/Seeed_Serial_MP3_Player
  */

  //Mp3Player.volume(6); // values 0-30, default: 6

  Mp3Player.playSongMP3(1); // just play MP3/0001.mp3
  delay (2000);

  Mp3Player.playSongMP3(2); // just play MP3/0002.mp3
  delay (2000);

  Mp3Player.playSongMP3(3); // just play MP3/0003.mp3
  delay (2000);

  // another way of doing this:
  for (int i = 5; i > 0; i--) {
    Mp3Player.playSongMP3(i); // in a loop, 0005.mp3 to 0001.mp3
    delay (1000);
  }
}

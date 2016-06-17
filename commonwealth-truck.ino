/*  Arduino sketch to run ambient lighting in
    1950's truck installed at Commonwealth in Cambridge, MA, USA
    http://commonwealthcambridge.com/
    Copyright 2016 New American Public Art
    Written by Brandon Stafford, brandon@rascalmicro.com */

/*  This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#include <FastLED.h>

#define REDPIN   3
#define GREENPIN 4
#define BLUEPIN  5

void showAnalogRGB( const CRGB& rgb) {
  analogWrite(REDPIN,   255-rgb.r );
  analogWrite(GREENPIN, 255-rgb.g );
  analogWrite(BLUEPIN,  255-rgb.b );
}

void colorBars() {
  showAnalogRGB( CRGB::Red );   delay(3000);
  showAnalogRGB( CRGB::Green ); delay(3000);
  showAnalogRGB( CRGB::Blue );  delay(3000);
  showAnalogRGB( CRGB::Black ); delay(1000);
}

void setup() {
    Serial.begin(115200);
    pinMode(13, OUTPUT);
    pinMode(REDPIN, OUTPUT);
    pinMode(GREENPIN, OUTPUT);
    pinMode(BLUEPIN, OUTPUT);
    // Flash the "hello" color sequence: R, G, B, black.
    colorBars();
}

void loop() {
    uint8_t hue;
    int sensorValue = analogRead(A0);
    hue = map(sensorValue, 0, 1023, 0, 255);
    showAnalogRGB(CHSV( hue, 255, 255));
    Serial.println(hue);
    delay(20);
}

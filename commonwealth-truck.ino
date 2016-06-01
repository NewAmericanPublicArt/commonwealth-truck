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

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  digitalWrite(13, HIGH);
  delay(1 * sensorValue);
  digitalWrite(13, LOW);
  delay(1 * sensorValue);
}

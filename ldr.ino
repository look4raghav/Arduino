const int ledPin = 13;

const int ldrPin = A0;

void setup() {

Serial.begin(9600);

pinMode(ledPin, OUTPUT);

pinMode(ldrPin, INPUT);

}

void loop() {

int ldrStatus = analogRead(ldrPin);

Serial.println(ldrStatus);
  

if (ldrStatus <= 200) {

digitalWrite(ledPin, HIGH);

Serial.println("Its DARK, Turn on the LED : ");

Serial.println(ldrStatus);

} else {

digitalWrite(ledPin, LOW);

Serial.println("Its BRIGHT, Turn off the LED : ");

Serial.println(ldrStatus);

}

}

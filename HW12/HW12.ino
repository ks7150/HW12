int button1Pin = 2; // Connect button 1 to pin 2
int button2Pin = 3; // Connect button 2 to pin 3
int button3Pin = 4; // Connect button 3 to pin 4
int ledPin = 13; // Connect LED to pin 13

void setup() {
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char signal = Serial.read();
    if (signal == '1') {

       digitalWrite(ledPin, HIGH);
    } else if (signal == '0') {
      // Turn off the LED
      digitalWrite(ledPin, LOW);
    }
  }
  // Read button inputs
  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);
  int button3State = digitalRead(button3Pin);

  // Check if the correct sequence of buttons is pressed
  if (button1State == HIGH && button2State == LOW && button3State == LOW) {
    // Turn on the LED
    digitalWrite(ledPin, HIGH);
  } else {
    // Turn off the LED
    digitalWrite(ledPin, LOW);
  }
}

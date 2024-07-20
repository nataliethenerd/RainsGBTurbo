const int turboEnableButton = 11; // Button to toggle turbo mode
const int actionButton = 10; // Pin for the action button, will be used both as input and output

bool turboModeEnabled = false;
bool lastTurboEnableButtonState = HIGH;

void setup() {
  pinMode(turboEnableButton, INPUT_PULLUP);
  pinMode(actionButton, INPUT_PULLUP);
}

void loop() {
  bool currentTurboEnableButtonState = digitalRead(turboEnableButton);
  if (lastTurboEnableButtonState == HIGH && currentTurboEnableButtonState == LOW) {
    delay(200);
    turboModeEnabled = !turboModeEnabled;
  }
  lastTurboEnableButtonState = currentTurboEnableButtonState;

  if (turboModeEnabled && digitalRead(actionButton) == LOW) { 
    while(digitalRead(actionButton) == LOW);
    delay(200); 

    // Now simulate three button presses
    pinMode(actionButton, OUTPUT);
    for (int i = 0; i < 3; i++) {
      digitalWrite(actionButton, LOW); 
      delay(50); 
      digitalWrite(actionButton, HIGH); 
      delay(100); // Delay between presses
    }
    pinMode(actionButton, INPUT_PULLUP);
  }
}

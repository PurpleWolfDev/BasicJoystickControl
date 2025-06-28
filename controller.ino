

const int xPin = A0;
const int yPin = A1;
const int xPin2 = A2;
const int yPin2 = A3;
const int switch1 = 2;  // Right click
const int switch2 = 3;  // Shift

const int threshold = 300;
String lastCommand = "";

void setup() {
  pinMode(switch1, INPUT_PULLUP); // initially pulled HIGH, when clicked it pulled low
  pinMode(switch2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  String currentCommand = "";

  // Read Joystick 1 (movement)
  int xVal = analogRead(xPin) - 512;
  int yVal = analogRead(yPin) - 512;

  bool left = xVal > threshold;
  bool right = xVal < -threshold;
  bool forward = yVal > threshold;
  bool backward = yVal < -threshold;

  // 8-direction logic
  if (forward && right) currentCommand = "FORWARD RIGHT";
  else if (forward && left) currentCommand = "FORWARD LEFT";
  else if (backward && right) currentCommand = "BACKWARD RIGHT";
  else if (backward && left) currentCommand = "BACKWARD LEFT";
  else if (forward) currentCommand = "FORWARD";
  else if (backward) currentCommand = "BACKWARD";
  else if (left) currentCommand = "LEFT";
  else if (right) currentCommand = "RIGHT";
  else currentCommand = "STOP";

  if (currentCommand != lastCommand) {   // to prevent unecessary Serial communication 
    Serial.println(currentCommand);
    lastCommand = currentCommand;
  }

  // Joystick 2 (Boost = LEFT mouse click)
  int yVal2 = analogRead(yPin2) - 512;  // didn't had extra buttons for boost.
  if (yVal2 < -threshold) {
    Serial.println("LEFTCLK");
  }

  // Shift key
  if (digitalRead(switch1) == LOW) {
    Serial.println("SHIFT");
  }

  // Right mouse click
  if (digitalRead(switch2) == LOW) {
    Serial.println("RIGHTCLK");
  }

  delay(50);
}

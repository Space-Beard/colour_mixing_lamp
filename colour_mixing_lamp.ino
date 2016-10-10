//pin assignments
const int greenLEDPin = 9;
const int blueLEDPin = 10;
const int redLEDPin = 11;

//sensor pins
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

//LED color values
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

//light sensor values
int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  //print out sensor values
  //Serial.print("Raw sensor values \t red: ");
  //Serial.print(redSensorValue);
  //Serial.print("\t green: ");
  //Serial.print(greenSensorValue);
  //Serial.print("\t blue: ");
  //Serial.print(blueSensorValue);
  Serial.print(blueSensorValue);
  Serial.print(" ");
  Serial.print(greenSensorValue);
  Serial.print(" ");
  Serial.println(redSensorValue);

  //convert the sensor values to colourLED pin values
  redValue = redSensorValue/4;
  blueValue = blueSensorValue/4;
  greenValue = greenSensorValue/4;

  //print out LED values
  //Serial.print("Mapped sensor values \tRed: ");
  //Serial.print(redValue);
  //Serial.print("\tGreen: ");
  //Serial.print(greenValue);
  //Serial.print("\tBlue: ");
  //Serial.print(blueValue);
  //Serial.println();

  //write the mapped values to the colourLED pins
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);

}

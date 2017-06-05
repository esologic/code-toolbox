#define NUMINPUTPINS 4

int inputPins[NUMINPUTPINS] =           {0,          1,          4,           5};
int (*readPtr[NUMINPUTPINS])(uint8_t) = {analogRead, analogRead, digitalRead, digitalRead};

void setup() {
  // set the pinMode on the digital pins to input
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  for (int pinIndex = 0; pinIndex < NUMINPUTPINS; pinIndex++)
  {
    for (int readIndex = 0; readIndex < 5; readIndex++) // do 5 readings of the given sensor
    {
      Serial.print("Reading Pin: ");
      Serial.print(pinIndex);
      Serial.print(" - ");
      Serial.print(readPtr[pinIndex](inputPins[pinIndex]));
      Serial.println("");
      delay(100);
    }
    Serial.println("");
  }
}

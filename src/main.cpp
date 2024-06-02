#include <Arduino.h>

const int IS = 4;
const int INH = 5;
const int IN = 6;

const int pwmChannel = 0;
const int pwmFreq = 5000;
const int resolution = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(IS, INPUT);
  pinMode(INH, OUTPUT);
  pinMode(IN, OUTPUT);

  ledcSetup(pwmChannel, pwmFreq, resolution);
  ledcAttachPin(IN, pwmChannel);
}

void loop()
{
  // step 1 (Not considering IS value) ////////////////////////////////////////////////////
  digitalWrite(INH, HIGH);
  delay(10);
  for (int i = 0; i <= resolution; i++) // increse the motor speed
  {
    ledcWrite(pwmChannel, i);
    delay(8);
  }
  for (int i = resolution; i >= 0; i--) // decrese the motor speed
  {
    ledcWrite(pwmChannel, i);
    delay(8);
  }
  // Step 2 (Considering IS value as 1 or 0) //////////////////////////////////////////////
  /*if (IS == LOW)
  {
    digitalWrite(INH, HIGH);
    delay(10);
    for (int i = 0; i <= resolution; i++) // increse the motor speed
    {
      ledcWrite(pwmChannel, i);
      delay(8);
    }
    for (int i = resolution; i >= 0; i--) // decrese the motor speed
    {
      ledcWrite(pwmChannel, i);
      delay(8);
    }
  }
  else
  {
    digitalWrite(INH, LOW);
    ledcWrite(pwmChannel, 0);
  } */
  // Step 3 (Considering the IS value as analog reading) /////////////////////////////////
  /*int pwmIS = analogRead(IS);
  if (pwmIS <= 150)
  {
    digitalWrite(INH, HIGH);
    delay(10);
    for (int i = 0; i <= resolution; i++) // increse the motor speed
    {
      ledcWrite(pwmChannel, i);
      delay(8);
    }
    for (int i = resolution; i >= 0; i--) // decrese the motor speed
    {
      ledcWrite(pwmChannel, i);
      delay(8);
    }
  }
  else
  {
    digitalWrite(INH, LOW);
    ledcWrite(pwmChannel, 0);
  } */
}
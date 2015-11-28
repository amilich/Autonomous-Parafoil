#include <PID_v1.h>
#include <Stepper.h>

#define STEPS 100

int previous = 0;
Stepper stepper(STEPS, 8, 9, 10, 11);

double Setpoint, Input, Output;
PID myPID(&Input, &Output, &Setpoint, 2, 5, 1, DIRECT);

void setup() {
  stepper.setSpeed(30);
  Input = analogRead(0);
  Setpoint = 100; // customize to compass reading?
  myPID.SetMode(AUTOMATIC);
}

// change stepper control parameters 
void loop() {
  int val = analogRead(0);
  stepper.step(val - previous);
  previous = val;

  Input = analogRead(0);
  myPID.Compute();
  analogWrite(3, Output);
}

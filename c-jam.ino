#include <AccelStepper.h>

// Define the pins connected to the stepper motors
#define motor1Pin1 2
#define motor1Pin2 3
#define motor1Pin3 4
#define motor1Pin4 5

#define motor2Pin1 6
#define motor2Pin2 7
#define motor2Pin3 8
#define motor2Pin4 9

#define motor3Pin1 23
#define motor3Pin2 25
#define motor3Pin3 27
#define motor3Pin4 29

#define motor4Pin1 31
#define motor4Pin2 33
#define motor4Pin3 35
#define motor4Pin4 37

#define motor5Pin1 2
#define motor5Pin2 3
#define motor5Pin3 4
#define motor5Pin4 5

#define motor6Pin1 2
#define motor6Pin2 3
#define motor6Pin3 4
#define motor6Pin4 5

// Define the maximum speed for each motor
#define motor1MaxSpeed 1500
#define motor2MaxSpeed 1500
#define motor3MaxSpeed 1500
#define motor4MaxSpeed 1500
#define motor5MaxSpeed 1500
#define motor6MaxSpeed 1500

// Create two AccelStepper objects for the two motors
AccelStepper motor1(AccelStepper::FULL4WIRE, motor1Pin1, motor1Pin3, motor1Pin2, motor1Pin4);
AccelStepper motor2(AccelStepper::FULL4WIRE, motor2Pin1, motor2Pin3, motor2Pin2, motor2Pin4);
AccelStepper motor3(AccelStepper::FULL4WIRE, motor3Pin1, motor3Pin3, motor3Pin2, motor3Pin4);
AccelStepper motor4(AccelStepper::FULL4WIRE, motor4Pin1, motor4Pin3, motor4Pin2, motor4Pin4);
AccelStepper motor5(AccelStepper::FULL4WIRE, motor5Pin1, motor5Pin3, motor5Pin2, motor5Pin4);
AccelStepper motor6(AccelStepper::FULL4WIRE, motor6Pin1, motor6Pin3, motor6Pin2, motor6Pin4);

// Define the button pin
#define buttonPin1 12
#define buttonPin2 11


// Define the serial communication variables
const int baudRate = 115200;
int incomingAngle = 0;

void setup() {
  // Set the maximum speed and acceleration for each motor
  motor1.setMaxSpeed(motor1MaxSpeed);
  // motor1.setAcceleration(motor1MaxSpeed);
  motor1.setAcceleration(motor1MaxSpeed);
 
  motor2.setMaxSpeed(motor2MaxSpeed);
  // motor2.setAcceleration(motor2MaxSpeed / 2);
  motor2.setAcceleration(motor2MaxSpeed);

   motor3.setMaxSpeed(motor3MaxSpeed);
  // motor2.setAcceleration(motor2MaxSpeed / 2);
  motor3.setAcceleration(motor3MaxSpeed);

  motor4.setMaxSpeed(motor4MaxSpeed);
  // motor2.setAcceleration(motor2MaxSpeed / 2);
  motor4.setAcceleration(motor4MaxSpeed);

   motor5.setMaxSpeed(motor5MaxSpeed);
  // motor2.setAcceleration(motor2MaxSpeed / 2);
  motor5.setAcceleration(motor5MaxSpeed);

   motor6.setMaxSpeed(motor6MaxSpeed);
  // motor2.setAcceleration(motor2MaxSpeed / 2);
  motor6.setAcceleration(motor6MaxSpeed);

  // Initialize the button pin
  pinMode(buttonPin1, INPUT_PULLUP);
pinMode(buttonPin2, INPUT_PULLUP);

  // Initialize serial communication
  Serial.begin(baudRate);
}

void loop() {
  // Check for button press
  if (digitalRead(buttonPin1) == LOW) {
    // Move motor 1 90 degrees in the opposite direction
    motor1.move(-500);
   
   
    // Move motor 2 90 degrees in the opposite direction
    motor2.move(540);

    motor3.move(-540);
    motor4.move(540);
  }
  if (digitalRead(buttonPin2) == LOW) {
    // Move motor 1 90 degrees in the opposite direction
    motor1.move(500);
   
   
    // Move motor 2 90 degrees in the opposite direction
    motor2.move(-540);

    motor3.move(540);

    motor4.move(-540);
  }
 
  // // Check for incoming data from Unity
  // if (Serial.available() > 0) {
  //   incomingAngle = Serial.parseInt();
  //   Serial.print("Received angle: ");
  //   Serial.println(incomingAngle);
   
  //   // Move motor 1 to the specified angle
  //   motor1.moveTo(incomingAngle);
   
  //   // Move motor 2 to the opposite angle
  //   motor2.moveTo(-incomingAngle);
  // }

  // //read serial string
  // if (Serial.available() > 0) {     //wait for data available
  //   String inputString = Serial.readString();  //read until >timeout<
  //   inputString.trim();

  //   if (inputString == "A") {
  //     motor1.move(-720);
  //     motor2.move(-720);
  //     motor3.move(-720);
  //     motor4.move(-720);
  //     motor5.move(-720);
  //     motor6.move(-720);
  //   } else if (inputString == "B") {
  //     motor1.move(-720);
  //     motor2.move(-720);
  //     motor3.move(-720);
  //     motor4.move(-720);
  //     motor5.move(-720);
  //     motor6.move(-720);
  //     }
  //   } else if (inputString == "C") {
  //     motor1.move(-720);
  //     motor2.move(-720);
  //     motor3.move(-720);
  //     motor4.move(-720);
  //     motor5.move(-720);
  //     motor6.move(-720);

  //     } else if (inputString == "D") {
  //     motor1.move(-720);
  //     motor2.move(-720);
  //     motor3.move(-720);
  //     motor4.move(-720);
  //     motor5.move(-720);
  //     motor6.move(-720);
  //     }
  //   }
  // }
  // delay(20);        // delay in between reads for stability

  // Move both motors
  motor1.run();
  motor2.run();
  motor3.run();
  motor4.run();
}
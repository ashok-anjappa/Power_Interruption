
#define TEN_MILI_SEC      10
#define NINETY_MILI_SEC  90

/* 
Arduino code to compute the life cycle count of Single Axis joystick.
Infineon's BTT6030 24V protected switch shield is used to switch the power suply to two joysticks. Frequency is 1Hz.
When the motor is actuating the joystick, it also depresses a swtich to keep track of the cycle count of Joystick.
The value of the cycle count is transmitted by the arduino serially via com port at 9600 baud rate.
The cycle count value is written to EEPROM every hour to save the cycle count upon power loss; maximum 1 hour counts will be lost in case of power off
*/

// Control output control of FET switches
const int IS_0 = A0;
const int IS_1 = A1;
const int IS_2 = A2;
// Control output control of FET switches
const int DEN_0 = 9;
const int DEN_1 = 5;
const int DEN0_0 = A4;
// Control output control of FET switches
const int DSEL_0 = 2;
const int DSEL_1 = 6;
// Control output control of FET switches
const int IN0_0 = A3; // Control of output OUT0_0
const int IN1_0 = 3;
const int IN0_1 = 4;
const int IN1_1 = 7;
const int IN0_2 = 8;

void setup() {
  
  pinMode(IN0_0, OUTPUT);
  pinMode(IN1_0, OUTPUT);
  pinMode(IN0_1, OUTPUT);
  pinMode(IN1_1, OUTPUT);
  pinMode(IN0_2, OUTPUT);
  pinMode(DSEL_0, OUTPUT);
  pinMode(DSEL_1, OUTPUT);
  pinMode(DEN0_0, OUTPUT);
  pinMode(DEN_0, INPUT);
  pinMode(DEN_1, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  #define out0_0_off digitalWrite(IN0_0, LOW);  // Set output for BTT6030(0) channel 0
  digitalWrite(IN0_0, LOW);
  digitalWrite(IN1_0, LOW);  // Set output for BTT6030(0) channel 1
  digitalWrite(IN1_1, LOW);  // Set output for BTT6030(1) channel 0
  digitalWrite(IN0_2, LOW);  // Set output for BTT6030(1) channel 1
  digitalWrite(DSEL_0, LOW);
  digitalWrite(DSEL_1, LOW);
  digitalWrite(DEN0_0, HIGH);
  digitalWrite(DEN_0, LOW);
  digitalWrite(DEN_1, LOW);
  }

void loop() {

    digitalWrite(IN0_0, HIGH);
    delay(NINETY_MILI_SEC);
    digitalWrite(IN0_0, LOW);
    delay(TEN_MILI_SEC);
  }

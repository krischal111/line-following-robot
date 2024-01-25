// Wheel class
class Wheel {
public:
  char input1, input2, enable;  // pins
  int speed = 100;             // value of speed
  int lower_limit = 20;
  int upper_limit = 255;

  Wheel();
  Wheel(int in1, int in2, int en);

  void stop();
  void forward();
  void reverse();
  void setSpeed(int speed_value);
  void increaseSpeed();
  void decreaseSpeed();
};


/*! Important constants */
const int IR_count = 4;
const int IR[4] = { 2, 3, 4, 5 };

// Important variables
Wheel *wheelA, *wheelB;
int no_computer_intervention = 1;


// Setting up: Wheels, IR, Serial
void setup() {
  wheelA = new Wheel(A0, A1, 9);
  wheelB = new Wheel(A2, A3, 6);
  IR_setup();
  Serial.begin(9600);
  stop_wheels();
}
void IR_setup() {
  for (int i = 0; i < IR_count; ++i)
    pinMode(IR[i], INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  // wheel_test();
  computer_control();

  if (no_computer_intervention) {
    line_follow_basic_control();
  }
}


void stop_wheels() {
  wheelA->stop();
  wheelB->stop();
}

// Wheel class
class Wheel {
  public:
  int input1, input2, enable; // pins
  int speed=100; // value of speed
  int lower_limit=20;
  int upper_limit=200;

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
const int IR[4] = {2, 3, 4, 5};


// Important variables
Wheel *wheelA, *wheelB;
int enable_line_follow = 1;

void setup() {
  // put your setup code here, to run once:
  wheel_setup();
  IR_setup();
  Serial.begin(9600);
}

void wheel_setup() {
  wheelA = new Wheel(A0, A1, 9);
  wheelB = new Wheel(A2, A3, 6);
}
void stop_wheels() {
  wheelA->stop();
  wheelB->stop();
}
void IR_setup() {
  for (int i = 0; i<IR_count; ++i)
    pinMode(IR[i], INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  // wheel_test();
  computer_control();

  if (enable_line_follow) {
    line_follow_basic_control();
  }
}



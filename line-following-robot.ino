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
Wheel *left_wheel, *right_wheel;
int no_computer_intervention = 1;


// Setting up: Wheels, IR, Serial
void setup() {
  left_wheel = new Wheel(A0, A1, 9);
  right_wheel = new Wheel(A2, A3, 6);
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
    right_wall();
  }
}

void stop_wheels() {
  left_wheel->stop();
  right_wheel->stop();
}

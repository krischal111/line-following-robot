class Wheel {
  public:
  int input1, input2, enable; // pins
  int speed=255; // value of speed

  Wheel();

  Wheel(int in1, int in2, int en);

  void stop();
  void forward();
  void reverse();
  void setSpeed(int speed_value);
};

Wheel *wheelA, *wheelB;
int IR[4] = {A0, A1, A2, A3};

void setup() {
  // put your setup code here, to run once:
  wheel_setup();
  IR_setup();
  
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  // wheel_test();
  IR_test();
}




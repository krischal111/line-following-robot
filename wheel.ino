  Wheel::Wheel() {}

  Wheel::Wheel(int in1, int in2, int en) {
    input1 = in1;
    input2 = in2;
    enable = en;

    pinMode(input1, OUTPUT);
    pinMode(input2, OUTPUT);
    pinMode(enable, OUTPUT);

    this->stop();
  }

  void Wheel::stop() {
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    analogWrite(enable, speed);
  }

  void Wheel::forward() {
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
  }

  void Wheel::reverse() {
    digitalWrite(input2, LOW);
    digitalWrite(input1, HIGH);
  }

  void Wheel::setSpeed(int speed_value) {
    this->speed = speed_value;
    analogWrite(enable, speed);
  }

void wheel_setup() {
  wheelA = new Wheel(A0, A1, 6);
  wheelB = new Wheel(A2, A3, 9);
}
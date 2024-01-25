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

void Wheel::increaseSpeed() {
  if (speed < upper_limit)
    speed += 1;
}
void Wheel::decreaseSpeed() {
  if (speed > lower_limit)
    speed -= 1;
}

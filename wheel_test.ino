void wheel_test() {
  forward_test();
  delay(1000);

  reverse_test();
  delay(1000);

  stop_wheels();
}

void stop_wheels() {
  wheelA->stop();
  wheelB->stop();
  Serial.write("Test: Both wheels stopped");
  delay(500);
}

void forward_test() {
  wheelA->forward();
  wheelB->forward();
  Serial.write("Test: Wheel A and B forward mode");
  delay(1000);
}

void reverse_test() {
  wheelA->reverse();
  wheelB->reverse();
  Serial.write("Test: Wheel B and A reverse mode");
  delay(1000);
}
void wheel_test() {
  forward_test();
  delay(1000);

  reverse_test();
  delay(1000);

  stop_wheels_test();
}


// testing 
void stop_wheels_test() {
  left_wheel->stop();
  right_wheel->stop();
  Serial.println("\nTest: Both wheels stopped");
  delay(500);
}


void forward_test() {
  left_wheel->forward();
  right_wheel->forward();
  Serial.println("\nTest: Wheel A and B forward mode");
  delay(1000);
}

void reverse_test() {
  left_wheel->reverse();
  right_wheel->reverse();
  Serial.println("\nTest: Wheel B and A reverse mode");
  delay(1000);
}
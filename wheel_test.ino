void wheel_test() {
  forward_test();
  delay(1000);

  reverse_test();
  delay(1000);

  stop_wheels_test();
}


// testing 
void stop_wheels_test() {
  wheelA->stop();
  wheelB->stop();
  Serial.println("\nTest: Both wheels stopped");
  delay(500);
}


void forward_test() {
  wheelA->forward();
  wheelB->forward();
  Serial.println("\nTest: Wheel A and B forward mode");
  delay(1000);
}

void reverse_test() {
  wheelA->reverse();
  wheelB->reverse();
  Serial.println("\nTest: Wheel B and A reverse mode");
  delay(1000);
}
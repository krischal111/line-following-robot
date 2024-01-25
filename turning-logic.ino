void turn_left() {
  // start by stopping left wheel
  // and pushing the right wheel
  // do until LEDs are correct
  // stop
  left_wheel->stop();
  right_wheel->forward();
  delay(300);
  stop_when_correct();
}
void turn_right() {
  right_wheel->stop();
  left_wheel->forward();
  delay(300);
  stop_when_correct();
}
void turn_about() {
  // rotate both wheels in reverse direction
  left_wheel->forward();
  right_wheel->reverse();
  delay(300);
  stop_when_correct();
}
void stop_when_correct() {
  for(int i=1; i<200; ++i) {
    read_signals();
    process_signals();
    if (left_touching == false && right_touching == false && center_on_line == true) {
      stop_wheels();
      break;
    }
    delay(20);
  }
}

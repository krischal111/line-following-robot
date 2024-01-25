bool logging = false;

// convention
// kalo = sensor ma balxa
// sensor ma balxa = mero ma low
// kalo = low

String signal_value(int signal) {
  return signal ? "baleko" : "niveko";
}

void line_follow_basic_control() {

  int right_ir = digitalRead(IR[0]);
  int left_ir = digitalRead(IR[3]);
  int center_ir_r = digitalRead(IR[1]);
  int center_ir_l = digitalRead(IR[2]);
  int center = center_ir_r || center_ir_l;

  if (logging) {
    Serial.println(center);
  }

  auto & right_wheel = *wheelB;
  auto & left_wheel = *wheelA;

  if (!center) {
    stop_wheels();
    delay(100);
  } else {
    right_wheel.forward();
    left_wheel.forward();
  }
  return;

  // so left lai badhayera milauna parxa
  if (left_ir) {
    left_wheel.setSpeed(left_wheel.speed+1);
    right_wheel.setSpeed(right_wheel.speed-1);
    delay(20);
  }

  if (right_ir) {
    left_wheel.setSpeed(left_wheel.speed-1);
    right_wheel.setSpeed(right_wheel.speed+1);
    delay(20);
  }
}

void turn_left() {};


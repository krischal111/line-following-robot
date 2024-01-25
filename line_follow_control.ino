// Things to check
// 1. If left and right wheels are as expected
// 2. If IRs are as expected
// 3. If IR give signal when it encounters white (to the arduino)
// 4. If left and right wheel rotate towards the line


// convention
// Kalo = HIGH signal
// reason : kalo = sensor ma nibhxa = mero ma singal dinxa

int left_ir, right_ir, center_ir_r, center_ir_l;
bool left_touching, right_touching, center_on_line;

void line_follow_basic_control() {
  auto & right_wheel = *wheelB;
  auto & left_wheel = *wheelA;
  
  read_signals();
  process_signals();

  if (left_touching && right_touching) {
    // it can be T-junction
    // but for now, we consider it is unplaced
    stop_wheels();
    delay(100);
  }

  if (!center_on_line) {
    // it means it's outside the area
    // we need it to somehow find the path
    // but for now, we will just stop
    stop_wheels();
    delay(100);
  } else {
    right_wheel.forward();
    left_wheel.forward();
  }

  if (left_touching) {
    left_wheel.decreaseSpeed();
    right_wheel.increaseSpeed();
    delay(20);
  }

  if (right_touching) {
    left_wheel.increaseSpeed();
    right_wheel.decreaseSpeed();
    delay(20);
  }
}

void turn_left() {
}
void turn_right() {
}

bool display_ir_values = true;
void read_signals() {
  int left_ir = digitalRead(IR[3]);
  int center_ir_l = digitalRead(IR[2]);
  int center_ir_r = digitalRead(IR[1]);
  int right_ir = digitalRead(IR[0]);

  int center = center_ir_r || center_ir_l;

  if (display_ir_values) {
    Serial.println("\nLeft \tCenterL \tCenterR \tRight");
    Serial.print(left_ir);
    Serial.print("\t");
    Serial.print(center_ir_l);
    Serial.print("\t");
    Serial.print(center_ir_r);
    Serial.print("\t");
    Serial.print(right_ir);
    Serial.println("\n");
    delay(200);
  }
}

void process_signals() {
  // left IR on black, black = low signal input
  left_touching = left_ir == HIGH;
  right_touching = right_ir == HIGH;
  center_on_line = center_ir_l==HIGH || center_ir_r==HIGH;
}

String signal_value(int signal) {
  return signal ? "baleko" : "niveko";
}
// Things to check
// 1. If left and right wheels are as expected
// 2. If IRs are as expected
// 3. If IR give signal when it encounters white (to the arduino)
// 4. If left and right wheel rotate towards the line


// convention
// Kalo = HIGH signal
// reason : kalo = sensor ma nibhxa = mero ma singal dinxa

// IR lights
int left_ir, right_ir, center_ir_r, center_ir_l;
// Basic interpretation
bool left_touching, right_touching, center_on_line;

// Meaning in map
bool Right_turn, Left_turn, Dead_end, Straight;
bool T_junction, Plus_junction; // ignore these

void right_wall() {
  read_signals();
  process_signals();
  interpret_signals();

  // Junction logic
  if (Right_turn) {
    turn_right();
  } else if (Straight) {
    right_wheel->forward();
    left_wheel->forward();
  } else if (Left_turn) {
    turn_left();
  } else /*Dead end case*/ {
    turn_about();
  }
  
  // Path correction logic
  delay(50);
}

void line_follow_basic_control() {
  // auto & rightWheel = *right_wheel;
  // auto & leftWheel = *left_wheel;
  
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
    right_wheel->forward();
    left_wheel->forward();
  }

  if (left_touching) {
    left_wheel->decreaseSpeed();
    right_wheel->increaseSpeed();
    delay(20);
  }

  if (right_touching) {
    left_wheel->increaseSpeed();
    right_wheel->decreaseSpeed();
    delay(20);
  }
}

bool display_ir_values = true;
void read_signals() {
  int left_ir = digitalRead(IR[3]);
  int center_ir_l = digitalRead(IR[2]);
  int center_ir_r = digitalRead(IR[1]);
  int right_ir = digitalRead(IR[0]);

  int center = center_ir_r || center_ir_l;

  if (display_ir_values) {
    Serial.println("\nLeft\tCenterL\tCenterR\tRight");
    Serial.print(left_ir);
    Serial.print("\t");
    Serial.print(center_ir_l);
    Serial.print("\t");
    Serial.print(center_ir_r);
    Serial.print("\t");
    Serial.print(right_ir);
    Serial.println("\n");
  }
}


void process_signals() {
  // left IR on black, black = low signal input
  left_touching = left_ir == HIGH;
  right_touching = right_ir == HIGH;
  center_on_line = center_ir_l==HIGH || center_ir_r==HIGH;

  if (display_ir_values) {
    Serial.print("\nLeft_touching = ");
    Serial.print(left_touching);
    Serial.print("\nRight_touching = ");
    Serial.print(right_touching);
    Serial.print("\nOn_the_line = ");
    Serial.print(center_on_line);
    Serial.println("\n");
    delay(200);
  }
}

void interpret_signals() {
  // Meaning in map
  Right_turn = right_touching;
  Straight = center_on_line;
  Left_turn = left_touching;

  Dead_end = !right_touching && !left_touching && !center_on_line;
}

String signal_value(int signal) {
  return signal ? "baleko" : "niveko";
}
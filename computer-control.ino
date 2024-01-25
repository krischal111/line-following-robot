void computer_control() {
  if (Serial.available() <= 0) {
    // if no serial input, early return
    return;
  }
  
  char input = Serial.read();
  if (input == ' ') {
    no_computer_intervention = 1 - no_computer_intervention;
    if (no_computer_intervention) {
      Serial.println("\n\nNo computer intervention");
      Serial.println("Arduino runs normally");
      // early return when computer intervention disabled
      return;
    }

    Serial.println("\n\nEnable computer intervention");

    Serial.println("\nLeft wheels");
    Serial.println("q = run, e = stop wheels");
    Serial.println("w = increase, s = decrease speed");

    Serial.println("\nRight wheels");
    Serial.println("u = run, o = stop wheels");
    Serial.println("i = increase, k = decrease speed\n");
    
    Serial.println("Wheels stopped");

    stop_wheels();
  }

  // minimum: WheelA = 120, wheelB = 120
  //

  // control wheel A
  switch (input) {
    case 'q':
      left_wheel->forward();
      break;
    case 'e':
      left_wheel->stop();
      break;
    case 'w':
      left_wheel->increaseSpeed();
      Serial.print("Wheel A speed= ");
      Serial.println(left_wheel->speed);
      break;
    case 's':
      left_wheel->decreaseSpeed();
      Serial.print("Wheel A speed= ");
      Serial.println(left_wheel->speed);
      break;
  }

  // control wheel B
  switch (input) {
    case 'u':
      right_wheel->forward();
      break;
    case 'o':
      right_wheel->stop();
      break;
    case 'i':
      right_wheel->increaseSpeed();
      Serial.print("Wheel B speed= ");
      Serial.println(right_wheel->speed);
      break;
    case 'k':
      right_wheel->decreaseSpeed();
      Serial.print("Wheel B speed= ");
      Serial.println(right_wheel->speed);
      break;
  }

  
}
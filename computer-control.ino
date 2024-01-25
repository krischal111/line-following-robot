void computer_control() {
  if (Serial.available() <= 0) {
    return;
  }
  
  char input = Serial.read();
  if (input == ' ') {
    enable_line_follow = 1 - enable_line_follow;
    if (enable_line_follow) {
      Serial.println("\n\nDisable computer intervention");
      Serial.println("Arduino runs normally");
      return;
    } else {

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
  }

  // minimum: WheelA = 120, wheelB = 120
  //

  // control wheel A
  switch (input) {
    case 'q': // forward A
      wheelA->forward();
      break;
    case 'e': // stop A
      wheelA->stop();
      break;
    case 'w':
      wheelA->increaseSpeed();
      Serial.print("Wheel A speed= ");
      Serial.println(wheelA->speed);
      break;
    case 's':
      wheelA->decreaseSpeed();
      Serial.print("Wheel A speed= ");
      Serial.println(wheelA->speed);
      break;
  }

  // control wheel A
  switch (input) {
    case 'u': // forward A
      wheelB->forward();
      break;
    case 'o': // stop A
      wheelB->stop();
      break;
    case 'i':
      wheelB->increaseSpeed();
      Serial.print("Wheel B speed= ");
      Serial.println(wheelB->speed);
      break;
    case 'k':
      wheelB->decreaseSpeed();
      Serial.print("Wheel B speed= ");
      Serial.println(wheelB->speed);
      break;
  }
}
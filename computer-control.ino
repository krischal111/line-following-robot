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
      wheelA->forward();
      break;
    case 'e':
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

  // control wheel B
  switch (input) {
    case 'u':
      wheelB->forward();
      break;
    case 'o':
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
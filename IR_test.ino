void IR_test() {
  for(int i = 0; i<IR_count; ++i){
    Serial.print(i+1);
    Serial.print(": ");
    Serial.print(analogRead(IR[i]));
    Serial.print("\t");
  }
    // Serial.print("%d: %d\t ", i, analogRead(IR[i]));
  Serial.println();
  delay(200);
}
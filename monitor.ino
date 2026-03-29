int sensorPin = A0;
int readings[5];  // Moving average buffer
int sum = 0; int index = 0;
int hydrationPercent = 0;
void loop() {
    int rawValue = analogRead(sensorPin);
    sum = sum - readings[index];
    readings[index] = rawValue;
    sum = sum + rawValue;
    index = (index + 1) % 5;
    int avgValue = sum / 5;
    hydrationPercent = map(avgValue, minDry, maxWet, 0, 100);
    lcd.setCursor(0,0);
    lcd.print("Hydration: ");
    lcd.print(hydrationPercent);
    lcd.print("%");
    delay(500);
}

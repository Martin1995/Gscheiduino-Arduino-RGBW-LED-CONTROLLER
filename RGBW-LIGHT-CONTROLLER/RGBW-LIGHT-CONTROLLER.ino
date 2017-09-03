
  #define LED_1 9 //1. LED_ausgang (z.B. Rot einer RGB LED)
  #define LED_2 10 //2. LED_ausgang (z.B. Grün einer RGB LED)
  #define LED_3 11 //3. LED_ausgang (z.B. Blau einer RGB LED)
  #define LED_4 6 //4. LED_ausgang (z.B. zusätzliche weisse LED
  #define LED_puls 13 //Onboard Status_LED des Gscheiduino boards
  #define FADER 2
  #define ONE 3
  #define TWO 4
  #define THREE 5
  #define FOUR 7
  int brightness1 = 0; //Starthelligkeit LED1
  int brightness2 = 255; //Starthelligkeit LED2
  int brightness3 = 125; //Starthelligkeit LED3
  int fadeAmount1 = 5; //Zählergröße LED1
  int fadeAmount2 = fadeAmount1; //Zählergröße LED2
  int fadeAmount3 = fadeAmount2; //Zählergröße LED3
  int blink = 0; //Ausganszustand Status_LED
  int fader = 1; //FADER == OFF


  
void setup() {
  // put your setup code here, to run once:
  pinMode (LED_1, OUTPUT); //LED1 Ausgang
  pinMode (LED_2, OUTPUT); //LED2 Ausgang
  pinMode (LED_3, OUTPUT); //LED3 Ausgang
  pinMode (LED_4, OUTPUT); //LED4 Ausgang
  pinMode (LED_puls, OUTPUT); //Status_LED Ausgang
  pinMode (FADER, INPUT); //FADER-Button Eingang
  pinMode (ONE, INPUT); //ONE-Button Eingang
  pinMode (TWO, INPUT); //TWO-Button Eingang
  pinMode (THREE, INPUT); //THREE-Button Eingang
  pinMode (FOUR, INPUT); //FOUR-BUTTON Eingang
  digitalWrite (FADER, HIGH); //FADER-Button Eingang
  digitalWrite (ONE, HIGH); //ONE-Button Eingang
  digitalWrite (TWO, HIGH); //TWO-Button Eingang
  digitalWrite (THREE, HIGH); //THREE-Button Eingang
  digitalWrite (FOUR, HIGH); //FOUR-BUTTON Eingang
  digitalWrite (LED_4, HIGH); //LED4 Ausgang
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("BUTTON1: " + String(digitalRead(ONE)) + ", BUTTON2: " + String(digitalRead(TWO)) + ", BUTTON3: " + String(digitalRead(THREE)) + ", BUTTON4: " + String(digitalRead(FOUR)) + ", FADER-BUTTON: " + String(digitalRead(FADER)) + ", FADER-STATE: " + String(fader));
  if (digitalRead(FADER) == LOW && fader == 0){
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    fader = fader + 1;
  }
  else if (digitalRead(FADER) == LOW && fader == 1) {
    fader = fader - 1;
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    
  }
  else {
  }

  if (digitalRead(ONE) == LOW && (digitalRead(LED_1) == LOW || fader == 1) ){
     if (fader == 1){
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    fader = 0;
    digitalWrite(LED_1, HIGH);
     }
     else {
      digitalWrite(LED_1, HIGH);
     }
  }
  else if (digitalRead(ONE) == LOW && digitalRead(LED_1) == HIGH) {
    digitalWrite(LED_1, LOW);
    }
  else {
  }
  
  if (digitalRead(TWO) == LOW && (digitalRead(LED_2) == LOW || fader == 1 )){
     if (fader == 1){
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    fader = 0;
    digitalWrite(LED_2, HIGH);
     }
     else{
      digitalWrite(LED_2, HIGH);
     }
  }
  else if (digitalRead(TWO) == LOW && digitalRead(LED_2) == HIGH) {
    digitalWrite(LED_2, LOW);
    }
  else {
  }
  
  if (digitalRead(THREE) == LOW && (digitalRead(LED_3) == LOW || fader == 1 )){
     if (fader == 1){
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    fader = 0;
    digitalWrite(LED_3, HIGH);
     }
     else{
      digitalWrite(LED_3, HIGH);
     }
  }
  else if (digitalRead(THREE) == LOW && digitalRead(LED_3) == HIGH) {
    digitalWrite(LED_3, LOW);
    }
  else {
  }
  
  if (digitalRead(FOUR) == LOW && digitalRead(LED_4) == LOW  ){
    digitalWrite(LED_4, HIGH);
  }
  else if (digitalRead(FOUR) == LOW && digitalRead(LED_4) == HIGH) {
    digitalWrite(LED_4, LOW);
    }
  else {
  }
  
  if (fader == 1) {
  // set the brightness:
  //  Wir schreiben die Helligkeit und den Zustand der Status_LED:
  analogWrite(LED_1, brightness1); //wir schreiben den helligkeitswert für LED1
  analogWrite(LED_2, brightness2); //wir schreiben den helligkeitswert für LED2
  analogWrite(LED_3, brightness3); //wir schreiben den helligkeitswert für LED3
  digitalWrite(LED_puls, blink); //Wir schreiben den Ausganspegel HIGH/LOW für die Status_LED

  // change the brightness for next time through the loop:
  //Wir ändern die helligkeit für den nächsten schleifen durchlauf:
  brightness1 = brightness1 + fadeAmount1;
  brightness2 = brightness2 - fadeAmount2;
  brightness3 = brightness3 + fadeAmount3;

  // reverse the direction of the fading at the ends of the fade:
  //Wir kehren die richtung des Faders am Anfang und am Ende (0 - 255 -> 255 - 0):
  if (brightness1 <= 0 || brightness1 >= 255) {
    fadeAmount1 = -fadeAmount1;
  }
  if (brightness2 <= 0 || brightness2 >= 255) {
    fadeAmount2 = -fadeAmount2;
  }
  if (brightness3 <= 0 || brightness3 >= 255) {
    fadeAmount3 = -fadeAmount3;
  }
  //Umschaltung der Status_LED mit Boolscher Algebra jeden Programm durchlauf
  if (blink == 0) {
    blink = blink + 1;
  }
  else {
    blink = blink - 1;
  }
  // wait for ... milliseconds to see the dimming effect
  //Wir warten ... Millisekunden um den Dimmereffekt zu sehen
  delay(75);
  }



}

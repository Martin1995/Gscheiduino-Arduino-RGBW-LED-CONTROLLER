
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
  #define FIVE 8
  int brightness1 = 0; //Starthelligkeit LED1
  int brightness2 = 255; //Starthelligkeit LED2
  int brightness3 = 125; //Starthelligkeit LED3
  int fadeAmount1 = 5; //Zählergröße LED1
  int fadeAmount2 = fadeAmount1; //Zählergröße LED2
  int fadeAmount3 = fadeAmount2; //Zählergröße LED3
  int ledpuls = 1; //Ausganszustand Status_LED
  int central_off = 1; //Zentral-Aus-EIN ==> ON
  int fader = 1; //FADER INIT After powercycle
  int led1_state = 0; //LED1 INIT after Powercycle with on/off Button
  int led2_state = 0; //LED2 INIT after Powercycle with on/off Button
  int led3_state = 0; //LED3 INIT after Powercycle with on/off Button
  int led4_state = 1; //LED4 INIT after Powercycle with on/off Button




  
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
  pinMode (FIVE, INPUT); //FIVE-BUTTON Eingang
  digitalWrite (FADER, HIGH); //FADER-Button Eingang pullup
  digitalWrite (ONE, HIGH); //ONE-Button Eingang pullup
  digitalWrite (TWO, HIGH); //TWO-Button Eingang pullup
  digitalWrite (THREE, HIGH); //THREE-Button Eingang pullup
  digitalWrite (FOUR, HIGH); //FOUR-BUTTON Eingang pullup
  digitalWrite (FIVE, HIGH); //FIVE-BUTTON Eingang pullup
  digitalWrite (LED_4, HIGH); //LED4 Ausgang
  Serial.begin(9600);
}

void loop() {

  // put your main code here, to run repeatedly:

  Serial.println("BUTTON1: " + String(digitalRead(ONE)) + ", LED1_ON: " + String(led1_state) + ", BUTTON2: " + String(digitalRead(TWO)) + + ", LED2_ON: " + String(led2_state) + ", BUTTON3: " + String(digitalRead(THREE)) +  ", LED3_ON: " + String(led3_state)  + ", BUTTON4: " + String(digitalRead(FOUR)) + ", LED4_ON: " + String(led4_state) + ", FADER-BUTTON: " + String(digitalRead(FADER)) + ", FADER-STATE: " + String(fader) + ", BUTTON5: " + String(digitalRead(FIVE)) + ", ON/OFF: " + String(central_off));
    //Umschaltung der Status_LED mit Boolscher Algebra jeden Programm durchlauf

    if (digitalRead(FIVE) == LOW && central_off == 0){
      central_off = 1;
      if (led1_state == 1){
      digitalWrite(LED_1, HIGH);
      }
      if (led2_state == 1){
      digitalWrite(LED_2, HIGH);
      }
      if (led3_state == 1){
      digitalWrite(LED_3, HIGH);
      }
      if (led4_state == 1){
      digitalWrite(LED_4, HIGH);
      }
    }
    else if (digitalRead(FIVE) == LOW && central_off == 1) {
      central_off = 0;
      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, LOW);
      digitalWrite(LED_3, LOW);
      digitalWrite(LED_4, LOW);
    }
    else {
    }

    if (central_off == 1) {
    if (ledpuls == 0) {
    ledpuls = ledpuls + 1;
    }
    else {
    ledpuls = ledpuls - 1;
    }
    digitalWrite(LED_puls, ledpuls); //Wir schreiben den Ausganspegel HIGH/LOW für die Status_LED


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
    led1_state = 1;
     }
     else {
      digitalWrite(LED_1, HIGH);
    led1_state = 1;
     }
  
  }
  else if (digitalRead(ONE) == LOW && digitalRead(LED_1) == HIGH) {
    digitalWrite(LED_1, LOW);
    led1_state = 0;
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
    led2_state = 1;
     }
     else{
      digitalWrite(LED_2, HIGH);
    led2_state = 1;
     }
    }
  else if (digitalRead(TWO) == LOW && digitalRead(LED_2) == HIGH) {
    digitalWrite(LED_2, LOW);
    led2_state = 0; 
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
    led3_state = 1;
     }
     else{
      digitalWrite(LED_3, HIGH);
    led3_state = 1;
     }
  
  }
  else if (digitalRead(THREE) == LOW && digitalRead(LED_3) == HIGH) {
    digitalWrite(LED_3, LOW);
    led3_state = 0;
 
    }
  else {
 
  }
  
  if (digitalRead(FOUR) == LOW && digitalRead(LED_4) == LOW  ){
    digitalWrite(LED_4, HIGH);
    led4_state = 1;
  }
  else if (digitalRead(FOUR) == LOW && digitalRead(LED_4) == HIGH) {
    digitalWrite(LED_4, LOW);
    led4_state = 0;
    }
  else {
  }
  
  if (fader == 1) {
  // set the brightness:
  //  Wir schreiben die Helligkeit und den Zustand der Status_LED:
  analogWrite(LED_1, brightness1); //wir schreiben den helligkeitswert für LED1
  analogWrite(LED_2, brightness2); //wir schreiben den helligkeitswert für LED2
  analogWrite(LED_3, brightness3); //wir schreiben den helligkeitswert für LED3

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
  else {
  }
  }

  // wait for ... milliseconds to see the dimming effect
  //Wir warten ... Millisekunden um den Dimmereffekt zu sehen
  delay(75);
  }
  if (central_off == 0) {
    if (ledpuls == 0) {
    ledpuls = ledpuls + 1;
    }
    else {
    ledpuls = ledpuls - 1;
    }
    digitalWrite(LED_puls, ledpuls); //Wir schreiben den Ausganspegel HIGH/LOW für die Status_LED
    delay(200);

  }
}



/**
 * This turn on and off the LED light on btn click.
 */

 #define DEBUG 1
 
const int switchPin = 8;
const int ledPin = 12;

unsigned int ledLevel = 0;
boolean lastButton = LOW;
boolean currentButton = LOW;

void setup() {
  pinMode(switchPin,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  #if DEBUG==1
  Serial.begin(9600);
  #endif
}

void loop() {
  //get if btn was press.
  currentButton = debounce(lastButton);
  
  if(lastButton == LOW && currentButton == HIGH){
    ledLevel += 51;
    if(ledLevel > 255)
      ledLevel = 0;
    #if DEBUG==1
    Serial.println(ledLevel);
    #endif
  }
  lastButton = currentButton;
  analogWrite(ledPin,ledLevel);

}

//resolve the bounce of the btn problome.
boolean debounce(boolean last){
  //get current state.
  bool current = digitalRead(switchPin);
  if(last != current){//case changed
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}


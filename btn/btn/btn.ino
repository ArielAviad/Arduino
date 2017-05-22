/**
 * This turn on and off the LED light on btn click.
 */
 
const int switchPin = 8;
const int ledPin = 13;

boolean isOn = false;
boolean lastButton = LOW;
boolean currentButton = LOW;

void setup() {
  pinMode(switchPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  //get if btn was press.
  currentButton = debounce(lastButton);
  
  if(lastButton == LOW && currentButton == HIGH){
    isOn = !isOn;
  }
  lastButton = currentButton;
  digitalWrite(ledPin,isOn);
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


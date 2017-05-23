
#define DEBUG 1

#define trigPin 9
#define echoPin 10

long duration;
int distance;



void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  #if DEBUG==1
  Serial.begin(9600);
  #endif
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  duration = pulseIn(echoPin,HIGH);
  distance = duration*0.034/2;
  #if DEBUG==1
  Serial.print("distance: ");
  Serial.println(distance);
  #endif
}

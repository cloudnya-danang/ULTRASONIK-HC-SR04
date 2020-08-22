/*****************************************************************
 * PROGRAM SAFETY AGV 2 WHEEL
 * CREATED BY: DANANG MUHIM
 * SEMOGA DAPAT DIKEMBANGKAN LEBIH KEREN LAGI BUAT NEXT ACTION NYA
*****************************************************************/

#define echoPin1 8      // Echo Pin1
#define trigPin1 9      // Trigger Pin1
#define echoPin2 10     // Echo Pin2
#define trigPin2 11     // Trigger Pin2
#define obstacle_1 12   // send obstacle1

byte buzzer = 13;       // buzzer   

//Duration used to calculate distance
long duration1, distance1; 
long duration2, distance2;

void setup() {
  Serial.begin(115200);
  //set pin sensor ultra
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  //set pin obstacle sensor
  pinMode(obstacle_1, OUTPUT);

  //set pin buzzer
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration1 = pulseIn(echoPin1, HIGH);

  //Calculate the distance (in cm) based on the speed of sound.
  distance1 = duration1 * 0.034 / 2;
  Serial.print("jarak sensor 1: ");
  Serial.print(distance1);
  Serial.println("cm");
  //Delay 50ms before next reading.
  delay(50);


  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);

  //Calculate the distance (in cm) based on the speed of sound.
  distance2 = duration2 * 0.034 / 2;
  Serial.print("jarak sensor 2: ");
  Serial.print(distance2);
  Serial.println("cm");
  //Delay 50ms before next reading.
  delay(50);


  if (distance1 <= 50 || distance2 <= 50) {
    digitalWrite(obstacle_1,HIGH);
    buzzer_obstacle();
    Serial.println("stop, ada obstacle jahat ......");
  } else {
    digitalWrite(obstacle_1,LOW);
    buzzer_noobstacle();
  }
}

//set buzzer
void buzzer_obstacle(){
   digitalWrite(buzzer, HIGH);
  //tone(buzzer, 900);
}
void buzzer_noobstacle(){
  digitalWrite(buzzer, LOW);
  //tone(buzzer, 900); delay(500);
  //tone(buzzer, 1000); delay(500);
}

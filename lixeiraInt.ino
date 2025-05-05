#include <Servo.h>

const int trigPin = 13;
const int echoPin = 12;
const int ledVerde = 4;
const int ledVermelho = 3;
const int buzzer = 5;
const int botao = 2;
const int servoPin = 6;

const int LIMITE_CHEIO = 15;

Servo servo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(botao, INPUT_PULLUP); 
  servo.attach(servoPin);
  servo.write(0);
  Serial.begin(9600);
}

void loop() {
  long duracao;
  float distancia;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracao = pulseIn(echoPin, HIGH);
  distancia = duracao * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia <= LIMITE_CHEIO) {
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW);
    tone(buzzer, 1000);
  } else {
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, HIGH);
    noTone(buzzer);
  }

  if (digitalRead(botao) == HIGH) {
    servo.write(90);
    delay(3000);
    servo.write(0);
    delay(200);
  }

  delay(200);
}

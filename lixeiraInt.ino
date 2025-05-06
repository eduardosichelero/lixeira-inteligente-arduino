#include <Servo.h>

const int trigPin = 13;
const int echoPin = 12;
const int ledVerde = 4;
const int ledVermelho = 3;
const int buzzer = 5;
const int botao = 2;
const int servoPin = 6;

const float LIMITE_CHEIO = 6.0;
const float LIMITE_VAZIO = 7.0;

Servo servo;

int contadorApitos = 0;
const int maxApitos = 3;

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
  Serial.println("Sistema iniciado.");
}

float lerDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracao = pulseIn(echoPin, HIGH, 30000);

  if (duracao == 0) {
    Serial.println("[Sensor] Falha na leitura (timeout).");
    return 999;
  }

  float distancia = duracao * 0.034 / 2;
  return distancia;
}

void verificarLixeira() {
  float distancia = lerDistancia();

  Serial.print("[Sensor] Distância lida: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia <= LIMITE_CHEIO) {
    Serial.println("[Estado] Lixeira CHEIA. LED vermelho ON.");
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW);
    if (contadorApitos < maxApitos) {
      tone(buzzer, 1000);
      contadorApitos++;
      delay(500);
      noTone(buzzer);
      delay(500);
    }
  } 
  else if (distancia > LIMITE_VAZIO) {
    Serial.println("[Estado] Distância maior que 7 cm. Acionando LED vermelho e buzzer.");
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW);
    tone(buzzer, 1000);
  } else {
    Serial.println("[Estado] Lixeira VAZIA. LED verde ON, buzzer OFF.");
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, HIGH);
    noTone(buzzer);
    contadorApitos = 0;
  }
}

void loop() {
  verificarLixeira();

  if (digitalRead(botao) == HIGH) {
    Serial.println("[Ação] Botão pressionado. Abrindo tampa...");
    servo.write(90);
    delay(3000);
    servo.write(0);
    Serial.println("[Ação] Tampa fechada.");
    delay(1000);
    verificarLixeira();
  }

  delay(200);
}


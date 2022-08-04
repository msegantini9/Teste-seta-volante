#include <Arduino.h>

//definindo quais são as portas que o arduino vai usar
//pin = pino/entrada   btn = botão    led = led     left = esquerda      right - direita
#define pinBtnLeft 1
#define pinBtnRight 2
#define pinLedLeft 3
#define pinLedRight 4

//variavel que vai guardar estado da seta
bool leftIsOn = false;
bool rightIsOn = false;

void setup() {
  //define os botões como entrada e os leds como saída
  pinMode(pinBtnLeft, INPUT);
  pinMode(pinBtnRight, INPUT);
  pinMode(pinLedLeft, OUTPUT);
  pinMode(pinLedRight, OUTPUT);

  //desliga os dois leds
  digitalWrite(pinLedLeft, LOW);
  digitalWrite(pinLedRight, LOW);
}

void loop() {

// verifica se ligou a seta

  if(digitalRead(pinBtnLeft) == HIGH)
  {
    //se a seta da esquerda estiver ligada, deliga, caso contrário, liga ela

    if(leftIsOn)
    {
      leftIsOn = false;
      rightIsOn = false;
    }
    else
    {
      leftIsOn = true;
      rightIsOn = false;
    }
  }
  else if (digitalRead(pinBtnRight) == HIGH)
  {
    //se a seta da direita estiver ligada, desliga, caso contrário, liga ela

    if(rightIsOn)
    {
      leftIsOn = false;
      rightIsOn = true;
    }
    else
    {
      leftIsOn = false;
      rightIsOn = true;
    }
  }

  //se a seta para esquerda estiver ligada, pisca o led
  if(leftIsOn)
  {
    digitalWrite(pinLedLeft, LOW);
    delay(300);
    digitalWrite(pinLedLeft, HIGH);
    delay(300);
  }
  //se a seta para direita estiver ligada, pisca o led
  else if(rightIsOn)
  {
    digitalWrite(pinLedRight, LOW);
    delay(300);
    digitalWrite(pinLedRight, HIGH);
    delay(300);
  }
  //caso nenhuma seta estiver ligada, deliga os leds
  else
  {
    digitalWrite(pinLedLeft, LOW);
    digitalWrite(pinLedRight, LOW);
  }
  
}
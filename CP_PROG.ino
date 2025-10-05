// Pinos dos botões e do LED
const int botao1 = 32;   // Botão 1 no pino digital 32 - a
const int botao2 = 33;   // Botão 2 no pino digital 33 - b
const int botao3 = 27;   // Botão 3 no pino digital 27 - c
const int led1 = 23;     // Led vermelho
const int led2 = 22;     // led verde
const int led3 = 19;      //led amarelo

void setup() {
  pinMode(botao1, INPUT_PULLUP); // Usa resistor interno de pull-up
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // Leitura dos botões (LOW = pressionado por causa do pull-up)
  bool estadoBotao1 = digitalRead(botao1);
  bool estadoBotao2 = digitalRead(botao2);
  bool estadoBotao3 = digitalRead(botao3);

  // Usa operador AND: para acendimento dos LEDS
  //“O botão 1 está pressionado E o botão 2 está solto E o botão 3 está solto”.
  if (!estadoBotao3 || (!estadoBotao1 && !estadoBotao2)) { //LED vermelho (emergência)
    digitalWrite(led1, HIGH);  // VERMELHO OFF
    digitalWrite(led2, LOW);  // VERDE ON
    digitalWrite(led3, LOW);  // AMARELO ON
     }
  else if (!estadoBotao1 && estadoBotao2){ //LED AMARELO - ATENCAO 
    digitalWrite(led1, LOW); //VERMELHO OFF
    digitalWrite(led2, LOW);  // VERDE OFF
    digitalWrite(led3, HIGH); // amarelo ON
    
  } else { // LED VERDE - FUNCIONAMENTO NORMAL
    digitalWrite(led1, LOW);  //VERMELHO OFF
    digitalWrite(led2, HIGH); //VERDE ON
    digitalWrite(led3, LOW); //AMARELO OFF
  }

  delay(100);
}




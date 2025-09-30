// Pinos dos botões e do LED
const int botao1 = 32;   // Botão 1 no pino digital 2
const int botao2 = 33;   // Botão 2 no pino digital 3
const int led = 23;     // LED no pino digital

void setup() {
  pinMode(botao1, INPUT_PULLUP); // Usa resistor interno de pull-up
  pinMode(botao2, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  // Leitura dos botões (LOW = pressionado por causa do pull-up)
  bool estadoBotao1 = digitalRead(botao1);
  bool estadoBotao2 = digitalRead(botao2);

  // Usa operador AND: LED só acende se os dois forem pressionados
  if (!estadoBotao1 && !estadoBotao2) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  delay(100);
}


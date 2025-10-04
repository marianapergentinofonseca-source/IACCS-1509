// Pinos dos botões e do LED
const int botao1 = 32;   // Botão 1 no pino digital 32
const int botao2 = 33;   // Botão 2 no pino digital 33
const int botao3 = 27;   // Botão 3 no pino digital 27
const int led1 = 5;     // Led verde
const int led2 = 18;     // led amarelo 
const int led3 = 19;      // led vermelho

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
  bool estadoBotao3 = digitalRead(botao1);

  // Usa operador AND: para acendimento dos LEDS
  if (estadoBotao3 || (!estadoBotao1 && !estadoBotao2)) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
     }
  else if (estadoBotao1 && estadoBotao2){
    digitalWrite(led3, HIGH);
    digitalWrite(led2, LOW);
    
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led3, LOW);
  }

  delay(100);
}
// verde else
// amarelo botao 1 ativo e botao 2 desativado
// vermelho(3) acende quando o botao 3 ativo OU botao 1 e botao 2 estiverem ativos ao mesmo tempo


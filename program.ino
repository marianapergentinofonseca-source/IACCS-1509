#define trigPin 23  		// Pino GPIO conectado ao Trig do HC-SR04
#define echoPin 22 		// Pino GPIO conectado ao Echo do HC-SR04
#define pinLED 17 		// Pino GPIO conectado ao resistor de LED


void setup() {
    Serial.begin(9600);        		// Inicializa a comunicação serial
    pinMode(trigPin, OUTPUT);  	// Define o pino Trig como saída
    pinMode(echoPin, INPUT);   	// Define o pino Echo como entrada
    pinMode(pinLED, OUTPUT);	// Define o pino do LED como saída para acender o LED
}


void loop() {
    long duration;
    int distance;


    // Envia um pulso de 10us para o Trig
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);


    // Calcula o tempo de duração do pulso de retorno no Echo
    duration = pulseIn(echoPin, HIGH);


    // Calcula a distância em centímetros
    distance = duration * 0.034 / 2;


    // Exibe a distância no Monitor Serial
    Serial.print("Distância: ");
    Serial.print(distance);
    Serial.println(" cm");


    if(distance < 20){
	digitalWrite(pinLED, HIGH);
    }
    else digitalWrite(pinLED, LOW);


    // Atraso antes da próxima leitura
    delay(500);
}

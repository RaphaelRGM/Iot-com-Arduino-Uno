#include <LiquidCrystal.h>

// Inicializa um objeto nos pinos para acesso às funções do LCD
const int RS = 12, EN = 11, D4 = 10, D5 = 9, D6 = 8, D7 = 7;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

// Define o pino do LED
const int LED_PIN = 6;

void setup() {
  // Configura o LCD com 16 colunas e 2 linhas
  lcd.begin(16, 2);
  lcd.clear();
  
  // Imprime mensagem inicial no LCD
  lcd.setCursor(0, 0);
  lcd.print("MonteCarloDig");

  // Configura o LED como saída
  pinMode(LED_PIN, OUTPUT);

  // Inicializa a comunicação serial
  Serial.begin(9600);
  Serial.println("Digite 'on' para ligar e 'off' para desligar o LED.");
}

void loop() {
  // Calcula o tempo decorrido em segundos desde que o Arduino foi iniciado
  unsigned long tempo_decorrido = millis() / 1000; // ms → s

  // Imprime no LCD
  lcd.setCursor(0, 1);
  lcd.print(tempo_decorrido);
  lcd.print("s  "); // Adiciona espaços para evitar caracteres extras

  // Verifica se há dados disponíveis na Serial
  if (Serial.available()) {
    String comando = Serial.readString();  // Lê o texto digitado
    comando.trim();  // Remove espaços extras no início e fim

    if (comando == "on") {
      digitalWrite(LED_PIN, HIGH); // Liga o LED
      Serial.println("LED Ligado!");
    } else if (comando == "off") {
      digitalWrite(LED_PIN, LOW); // Desliga o LED
      Serial.println("LED Desligado!");
    } else {
      Serial.println("Comando inválido! Digite 'on' ou 'off'.");
    }
  }
}

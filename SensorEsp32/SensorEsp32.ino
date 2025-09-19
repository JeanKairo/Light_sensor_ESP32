#include <WiFi.h>
#include <HTTPClient.h>

// ======= CONFIGURAÇÕES =======

// Dados da rede Wi-Fi
const char* ssid = "moto g84 5G_9823";        
const char* password = "12345abcd";          

// API e canal ThingSpeak
const char* server = "http://api.thingspeak.com/update";
const char* apiKey = "ECTBRZIISBOEIG7I";      

// Pino onde está ligado o sensor LDR
const int analogPin = 35;  

void setup() {
  Serial.begin(115200);

  // Configura Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  WiFi.setAutoReconnect(true);

  Serial.print("Conectando-se ao Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");
}

void loop() {
  // Leitura do sensor LDR
  int analogValue = analogRead(analogPin);

  // Conversão para tensão (3.3V como referência)
  float voltage = analogValue * (3.3 / 4095.0);

  // Exibe no Serial Monitor
  Serial.print("Valor analógico: ");
  Serial.print(analogValue);
  Serial.print(" | Tensão: ");
  Serial.print(voltage, 3);
  Serial.println(" V");

  // Verifica conexão Wi-Fi
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Monta a URL com os campos field1 (valor analógico) e field2 (tensão)
    String url = String(server) + "?api_key=" + apiKey +
                 "&field1=" + String(voltage, 3) +
                 "&field2=" + String(voltage, 3);  // 3 casas decimais

    Serial.print("Enviando dados para: ");
    Serial.println(url);

    http.begin(url);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.print("Resposta HTTP: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Erro na requisição: ");
      Serial.println(http.errorToString(httpResponseCode).c_str());
    }

    http.end();
  } else {
    Serial.println("WiFi desconectado. Tentando reconectar...");
    WiFi.begin(ssid, password);
  }

  delay(15000); // Tempo mínimo de envio para ThingSpeak
}

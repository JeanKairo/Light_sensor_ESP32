# Sensor de Luminosidade com ESP32 e ThingSpeak

Projeto desenvolvido para medir a luminosidade ambiente usando um sensor LDR conectado a um ESP32, enviando os dados coletados para a nuvem via plataforma ThingSpeak.

## Descrição
O sistema lê valores analógicos do sensor LDR, converte para tensão e envia periodicamente os dados para um canal do ThingSpeak usando conexão Wi-Fi. A alimentação é feita por uma bateria LiPo (3.3 V).

## Componentes Utilizados
- ESP32 DevKit  
- Sensor LDR com resistor de 1 kΩ  
- Bateria LiPo 3S 2200 mAh  
- Protoboard e jumpers

## Funcionalidades
- Conexão automática com Wi-Fi  
- Leitura analógica no pino 35  
- Conversão para tensão (0–3.3 V)  
- Envio HTTP para ThingSpeak a cada 15 segundos

## Esquemático e PCB
Circuito e PCB desenvolvidos na plataforma EasyEDA.

## Resultados
Os dados são plotados em tempo real em um gráfico no canal do ThingSpeak, evidenciando a variação de luminosidade (0 V em baixa luz e até 3.3 V em alta luz).

## Como Usar
1. Conectar o LDR ao pino 35 do ESP32  
2. Alimentar o sistema com 3.3 V da bateria LiPo  
3. Aguardar conexão Wi-Fi  
4. Acompanhar os dados no canal do ThingSpeak

## Considerações
Projeto simples e eficaz para introdução à leitura de sensores analógicos, IoT e sistemas embarcados com ESP32.

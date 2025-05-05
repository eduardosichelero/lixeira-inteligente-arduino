# Lixeira Inteligente com Arduino

Este projeto implementa uma lixeira inteligente utilizando Arduino, sensor ultrassônico, LEDs, buzzer, servo motor e um botão. O sistema detecta o nível de lixo e realiza a abertura automática da tampa ao pressionar o botão, além de alertar quando a lixeira está cheia.

## Funcionalidades

- **Detecção de nível de lixo:** Utiliza um sensor ultrassônico para medir a distância até o lixo e determinar se a lixeira está cheia.
- **Sinalização visual e sonora:** LEDs e buzzer indicam quando a lixeira está cheia.
- **Abertura automática da tampa:** Um servo motor abre a tampa por 3 segundos ao pressionar o botão.
- **Monitoramento serial:** Exibe a distância medida no monitor serial.

## Componentes necessários

- 1 Arduino Uno (ou similar)
- 1 Sensor ultrassônico HC-SR04
- 1 Servo motor
- 1 LED vermelho
- 1 LED verde
- 1 Buzzer
- 1 Botão
- Resistores para os LEDs e botão
- Jumpers e protoboard

## Esquemático de ligações

| Componente      | Pino Arduino |
|-----------------|-------------|
| Trig HC-SR04    | 13          |
| Echo HC-SR04    | 12          |
| LED Verde       | 4           |
| LED Vermelho    | 3           |
| Buzzer          | 5           |
| Botão           | 2           |
| Servo Motor     | 6           |

## Como usar

1. Monte o circuito conforme o esquemático acima.
2. Carregue o código no Arduino.
3. Abra o monitor serial para acompanhar as leituras de distância.
4. Quando o botão for pressionado, a tampa será aberta automaticamente.
5. Se o nível de lixo atingir o limite configurado, o LED vermelho e o buzzer serão ativados.

## Personalização

- **Ajuste do limite:** Modifique o valor da constante `LIMITE_CHEIO` para alterar o limite de detecção de lixo cheio (em centímetros).
- **Tempo de abertura da tampa:** Altere o valor do `delay(3000)` para modificar o tempo em que a tampa permanece aberta.
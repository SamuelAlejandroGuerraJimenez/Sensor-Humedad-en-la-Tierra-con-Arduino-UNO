# Sensor-Humedad-en-la-Tierra-con-Arduino-UNO
El sensor de humedad mide el nivel de agua en el suelo para optimizar el cultivo y adaptarse a los cambios ambientales. Este monitoreo continuo previene el riego excesivo que daña las raíces. Como resultado, esta tecnología beneficia al sector agropecuario al promover el ahorro de agua y mejorar el rendimiento de las cosechas.

El codigo fue hecho en el programa Arduino IDE, cuenta con 174 lineas en total de codigo, su idea principal es ser modificada dependiendo en el contexto de la siembra dependiendo mas en lo que se siembra (por ejemplo un rabano que necesita Humedad Alta, termina con un rango mayor en el riego automatico).

IMPLEMENTOS USADOS PARA EL CIRCUITO:
1. Arduino UNO CH340 (en el PDF se muestra el uso de Arduino UNO R3, lo cual no es usado en el circuito)
2. Protoboard 730
3. Cables Jumper MM
4. Cables Jumper HM
5. Cables Jumper HH (solo se necesitan 4, 2 ya vienen con el YL-69 en el empaque)
6. Sensor de Humedad en la tierra YL-69
7. Microcontrolador YL-38
8. 3 Luces LED
9. 3 Resistencias de 330 OHM (opcional)
10. Servomotor SG90
11. Modulo Relay 5V (SONGLE SRD-05VDC-SL-C)
12. LCD 16x2
13. Potenciometro 10K
14. Buzzer
15. Bomba de Agua (para Riego Automatico)

PINES USADOS
1.   D2: RS (lcd 16x2)
2.   D3: EN (lcd 16x2)
3.   D4: D4 (lcd 16x2)
4.   D5: D5 (lcd 16x2)
5.   D6: D6 (lcd 16x2)
6.   D7: D7 (lcd 16x2)
7.   D8: Modulo Relay 5V
8.   D9: Buzzer
9.   D10: Servomotor
10.  D11: LED verde
11.  D12: LED amarillo
12.  D13: LED rojo
13.  A0: Analogico 0 del YL 38
14.  5V: + Servomotor
15.  GND: - Servomotor
16.  5V: Riel (+) de  la Protoboard
17.  GND: Riel (-) de la Protoboard
18.  3.3V: LED+ (lcd 16x2)  [Alternativamente se puede Usar la fuente de energia ICSP del Arduino si el brillo de la lcd 16x2 resulta ser demasiado bajo]

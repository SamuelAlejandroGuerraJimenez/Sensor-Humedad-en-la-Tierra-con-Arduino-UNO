(REVISAR LA PRESENTACION PDF SI EXISTEN DUDAS)

ESXPLICACION DEL CODIGO:
Descripción general del proyecto:
Este sketch de Arduino implementa un sistema de monitoreo de humedad conectado a el sensor YL-69 mediante una conexión analógica en el pin A0, una pantalla LCD de 16x2 caracteres, un servomotor, cuatro salidas digitales (13, 12, 11 y 8), un buzzer piezoeléctrico y salida de datos por comunicación serie. A partir de la lectura del sensor, el programa calcula un porcentaje de humedad basandose en la logica decreciente del YL-69 (1023-0) y un ángulo para el servomotor del 0 grados al 180 grados de manera fluente, actualiza la interfaz en pantalla y usa la mima logica de calculo del servomotor, en este caso 0% a 100% y activa indicadores visuales o sonoros según el rango medido.

Librerías, pines y definición de constantes:
Al inicio del archivo se incluyen <Servo.h> y <LiquidCrystal.h> para gestionar el servomotor y la pantalla LCD en modo de 4 bits. Se instancia el objeto myServo y se declaran los pines de control y datos del LCD (rs = 2, en = 3, digi4 = 4, digi5 = 5, digi6 = 6, digi7 = 7) junto con el objeto lcd(rs, en, digi4, digi5, digi6, digi7). 

A continuación se definen mediante #define el pin del buzzer (BUZZER_PIN en el pin 9) y tres frecuencias en Hertz (NOTE_E5 a 200, NOTE_F5 a 600 y NOTE_G5 a 800), que luego se asignan a las constantes melody, melody2 y melody3. También se fijan servoPin en el pin 10 y sensorPin en la entrada analógica A0.


RIEGO AUTOMATICO:
El Pin 9 se encarga del Modulo Relay 5V, la funcion es estar que el relay este conectado a la Motobomba, esa conexión depende en que Tipo de bomba de Agua se usa (no podria recomendar una Fija mas que todoporque esa parte hubo error, pero la parte de activar/desactivar el Relay esta funcional de manera perfecta). Es importante notar que la idea es que la variable que cambia cuando se activa/desactiva sea constantemente cambiada (Por Ejemplo, como esta ahora, la funcion que se va a proximamente explicar es cuando empieza a ser una alarma de saturación masiva, cuales son los datos de una aproximación de un Rábano).



Configuración inicial en setup()
La función setup() arranca la comunicación serie a 9600 baudios mediante Serial.begin(9600) y configura los pines 13, 12, 11, 8 y BUZZER_PIN como salidas (OUTPUT).

En este mismo bloque se inicializa la pantalla con lcd.begin(16, 2), se registra el carácter personalizado en el slot 0 con lcd.createChar(0, waterDrop) y se vincula el servomotor al pin 10 mediante myServo.attach(servoPin).

Funciones de parpadeo y alerta (superexhaustBlink y hyperexhaustBlink)
La función superexhaustBlink() alterna los pines 13, 12 y 11 entre HIGH y LOW en dos ciclos con pausas de 500 ms usando delay(), bloqueando el flujo del programa durante 1000 ms en total sin emitir sonido.

Por su parte, hyperexhaustBlink() dispara un tono con tone(BUZZER_PIN, melody, 500) y ejecuta un parpadeo más rápido en los pines 13, 12 y 11 con retardos de 200 ms (400 ms acumulados de pausas en el parpadeo).

Lectura del sensor, mapeo y pantalla en loop()
En cada iteración de loop(), el código lee A0 con analogRead(sensorPin) y utiliza map() invirtiendo el rango (1023 a 0) para obtener inicialAngle (0 a 180 grados) y moistDisplay (0 a 100 por ciento), moviendo el servomotor con myServo.write(inicialAngle). Esta inversión corresponde a sensores donde valores altos indican menor humedad o ambiente seco y valores bajos indican mayor humedad.

Luego posiciona el cursor en (0, 0), muestra el carácter de gota (lcd.write((uint8_t)0)), escribe "Humedad:" y, en la columna 12 de la misma fila, imprime el porcentaje seguido de "%". Si el valor baja de tres a un dígito, conviene tener en cuenta que no se limpian los caracteres residuales a la derecha.

Inmediatamente después se realiza una segunda lectura en moisture, se imprime su valor crudo por el Monitor Serie con Serial.println(moisture) y se recalcula servoAngle para actualizar de nuevo la posición de myServo, sobrescribiendo el movimiento anterior del mismo ciclo.

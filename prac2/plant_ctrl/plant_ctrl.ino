/**
 * Copyright (C) 2017 UAH. Departamento de Automática

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

/**
 * 
 * Práctica 2. Ejecutivo cíclico: control de una planta
 * 
 * En el arranque del sistema, el programa debe realizar las siguientes
 * operaciones:
 *
 * - Configurar la puerta serie a 9600 baudios.
 * - Tomar una primera medida de temperatura y definir el rango inicial.
 * - Configurar las entradas y salidas digitales y analógicas de acuerdo con el
 *   enunciado de la práctica.
 * 
 * El programa debe implementar las siguientes tareas periódicas:
 * 
 * - Cada segundo debe de encender o apagar el LED_BUILTIN para indicar que el
 *   programa está funcionando correctamente.
 * - Cada 500 milisegundos debe tomar una muestra del sensor de temperatura. A
 *   continuación, debe calcular la media de las últimas 20 tomas de temperatura
 *   para obtener el valor de temperatura representativo.
 * - Cada segundo debe realizar el control del sistema de acuerdo con los
 *   siguientes requisitos:
 *   - Si el pulsador 1 ha sido pulsado al menos una vez durante el último
 *     segundo, decrementar los límites del rango en una unidad.
 *   - Si el pulsador 2 ha sido pulsado al menos una vez durante el último
 *     segundo, incrementar los límites del rango en una unidad.
 *   - Si la temperatura es menor que el límite inferior del rango, pasar a o
 *     permanecer en modo HEATING.
 *   - Si la temperatura es mayor que el límite superior del rango, pasar a o
 *     permanecer en modo COOLING.
 *   - Si la temperatura está dentro del rango, pasar a o permanecer en modo
 *     STANDBY.
 * - En modo HEATING:
 *   - El LED rojo debe de estar encendido permanentemente.
 *   - Cada segundo, girar 90 grados el "agitador" (servo motor) [0, 90, 180]
 * - En modo COOLING:
 *   - El motor de continua debe estar en funcionamiento permanentemente con un
 *     ciclo de trabajo del 10%.
 *
 * El sistema siempre arranca en modo STANDBY.
 * 
 * Cada vez que se inicie un subperiodo del ejecutivo cíclico, el sistema
 * deberá mostrar el siguiente mensaje por la puerta serie:
 * - [XXXX]: Frame Y
 * donde XXXX son los milisegundos desde el arranque e Y es el número de marco
 * o subperiodo.
 *
 *
 * Para ello se proponen las siguientes funciones:
 * 
 * 
 * - void analogWrite(pin, value)
 * 
 * Parámetros: 
 * 
 * - pin: identificador del pin digital que se va a escribir. Este PIN debe 
 * - value: el ciclo de trabajo, entre 0 (siempre apagado) y 255 (siempre
 *   encendido).
 * 
 * Función que permite generar una función PWM a través de un PIN digital con
 * capacidad para ello.  Los pines digitales con posible salida PWM son los
 * pines 3, 5, 6, 9, 10, y 11.
 *
 *
 * - void servo.attach(pin)
 * 
 * Parámetros: 
 * 
 * - pin: identificador del pin digital al que está conectado el servo. El pin
 *   ha de tener capacidad de generar un PWM.
 *
 * Función que asocia el objeto Servo definido globalmente con el pin al que el
 * corresponiente motor está conectado. Esta función ha de ser llamada durante
 * el proceso de inicilización.
 * 
 *
 * - void servo.write(angle)
 * 
 * Parámetros: 
 * 
 * - angle: el valor del ángulo que debe de tomar el servo. Acepta valores
 *   entre 0 y 180.
 *
 * Función que escribe un valor en el servo. Dicho valor será el ángulo en
 * grados que tiene que adoptar el servo.
 *
 *
 */

#include <Servo.h>

#define RED_LED 12
#define MOTOR 11

#define TOTAL_MEASURES 20

typedef enum mode {
  STANDBY = 0,
  HEATING = 1,
  COOLING = 2
} e_mode;

e_mode mode = STANDBY;

Servo servo;

void setup() {
  
  // Código de configuración. Solo se ejecutará al comienzo de la aplicación.
  
}

void loop() {
  
  // Código principal de la aplicación. Se ejecutará de forma indefinida.
  
}


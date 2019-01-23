/*--------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------
--                             SISTEMAS ELECTR�NICOS DIGITALES                                          --
--                                  	 TRABAJO MICROS                                                   --
--                                    CURSO  2018/2019                                                  --
--                                                                                                      --
--                                                                                                      --
--  AUTORES:                                                                                            --
--      JAVIER LASERNA MORATALLA N�52431                                                                --
--      ALEJANDRO MORA S�NCHEZ N�52496                                                                  --
--      LUIS PEDRERO MORCILLO N�52541                                                                   --
--                                                                                                      --
----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------*/


#include "stm32f4xx.h"
#include "delay.h"
#include "led.h"
#include "button.h"
#include <stdio.h>
#include "SPI.h"
#include "matrixDisplay.h"
#include "buzzer.h"
#include "main.h"
#include "sensor_Function.h"
#include "adc.h"
#include "string.h"


//Estructuras necesarias para el funcionamiento de las m�quinas de estado
enum modo_func {PERRO_GUARDIAN, CONTADOR, TEMPORIZADOR};
enum modo_alarm {APAGADA, ACTIVADA};
enum modo_cont {NOCONTANDO, CONTANDO};
enum modo_crono {PARADO, INICIANDO, CORRIENDO, TERMINADO};
enum detecion {NODETECTADO, DETECTADO};
enum modo_menu {ELIGIENDO, FUNCIONAMIENTO};
	
enum modo_func modo = TEMPORIZADOR;
enum modo_alarm alarma = APAGADA;
enum modo_cont contand = NOCONTANDO;
enum detecion detec = NODETECTADO;
enum modo_crono crono = PARADO;
enum modo_menu menu = ELIGIENDO;
enum modo_func opcion = PERRO_GUARDIAN;

//Variables usadas en las m�quinas de estado
int16_t contador = 0;
int32_t distancia = 0;
int16_t temporizador = 0;
char str[4];
int32_t tiempoInicio = 0;
volatile int8_t eleccion = 0;

//Handler para el manejo de la activaci�n del tiempo
void systick(void) {
}

//Handler para el manejo de la interrupci�n del SW0
void button1_interrupt(void) {
	eleccion++;
}

//Handler para el manejo de la interrupci�n del SW1
void button2_interrupt(void) {
	menu = FUNCIONAMIENTO;
}

//Funci�n que calcula la distancia frente a la PCB bas�ndose en las medidas
//	tomadas por los dos sensores frontales
int32_t distanciaMedida(int32_t LeftSensor, int32_t RightSensor) {
	return (LeftSensor + RightSensor) / 2;
}

//Funciones p�blicas de las m�quinas de estado

//M�quina de estado del contador
void contado() {
	switch(contand) {
		case NOCONTANDO:
			if(distancia > 2050) {
				contand = CONTANDO;
				contador++;
				delay_ms(1000);
			}
			break;
		case CONTANDO:
			if(distancia < 2050)
				contand = NOCONTANDO;
			break;
	}
}

//M�quina de estado del perro guardian
void perroGuardian() {
	switch(alarma) {
		case APAGADA:
			ALL_LED_OFF;
			if(distancia > 2050)
				alarma = ACTIVADA;
			break;
		case ACTIVADA:
			detec = DETECTADO;
			ALL_LED_ON;
			shortBeep(2000, 8000);
			if(distancia < 2050)
				alarma = APAGADA;
			break;
	}
}

//M�quina de estado del temporizador
void temporizado() {
	switch(crono) {
		case PARADO:
			if(distancia > 2050)
				crono = INICIANDO;
			break;
		case INICIANDO:
			delay_ms(50);
			if(distancia < 2050) {
				tiempoInicio = millis();
				crono = CORRIENDO;
			}
			break;
		case CORRIENDO:
			temporizador = (millis()-tiempoInicio)/100;
			if(distancia > 2050) {
				crono = TERMINADO;
			}
			break;
		case TERMINADO:
			sprintf(str, "%2d.%d", temporizador/10, temporizador%10);
			displayMatrix(str);
			ALL_LED_ON;
			delay_ms(1000);
			clearScreen();
			ALL_LED_OFF;
			delay_ms(1000);
			displayMatrix(str);
			ALL_LED_ON;
			delay_ms(1000);
			clearScreen();
			ALL_LED_OFF;
			delay_ms(1000);
			displayMatrix(str);
			ALL_LED_ON;
			delay_ms(1000);
			ALL_LED_OFF;
			delay_ms(1000);
			crono = PARADO;
			temporizador = 0;
			delay_ms(3000);
			break;
	}
}

//M�quina de estado que selecciona el modo de funcionamiento
void evaluar() {
	switch(modo) {
		case PERRO_GUARDIAN:
			perroGuardian();
			break;
		case CONTADOR:
			contado();
			break;
		case TEMPORIZADOR:
			temporizado();
			break;
	}
}

//Funci�n que muestra el resultado en pantalla dependiendo del
//	modo de funcionamiento
void mostrarPantalla() {
	switch(modo) {
		case PERRO_GUARDIAN:
				switch(detec) {
					case NODETECTADO:
						displayMatrix("None");
						break;
					case DETECTADO:
						displayMatrix("WARN");
						delay_ms(2000);
						if(alarma == APAGADA)
							detec = NODETECTADO;
						break;
				}
			break;
		case CONTADOR:
			displayInt(contador);
			break;
		case TEMPORIZADOR:
			sprintf(str, "%2d.%d", temporizador/10, temporizador%10);
			displayMatrix(str);
		
			break;
	}
}

//M�quina de estado inicial para permitir al usuario seleccionar el modo
//	 de funcionamiento
void evaluarMenu() {
	switch(opcion) {
		case PERRO_GUARDIAN:
			displayMatrix("Perr");
			break;
		case TEMPORIZADOR:
			displayMatrix("Temp");
			break;
		case CONTADOR:
			displayMatrix("Cont");
			break;
	}
	
	switch(eleccion % 3) {
		case 0:
			opcion = PERRO_GUARDIAN;
			modo = PERRO_GUARDIAN;
			break;
		case 1:
			opcion = TEMPORIZADOR;
			modo = TEMPORIZADOR;
			break;
		case 2:
			opcion = CONTADOR;
			modo = CONTADOR;
			break;
	}
}

//Funci�n de inicio del programa
int main(void) {
	//Llamada a las funciones para configurar los perif�ricos, buses internos de configuraci�n,
	// y temporizadores
	Systick_Configuration();
	LED_Configuration();
	button_Configuration();
	SPI_Configuration();
	buzzer_Configuration();
	ADC_Config();
	
	//Bucle de ejecuci�n continua
	while(1) {
		//Lectura de los sensores de infrarrojos
		readSensor();
		readVolMeter();
		
		//C�lculo de la distancia medida por los sensores infrarrojos
		distancia = distanciaMedida(LFSensor, RFSensor);
	
		//Ejecuci�n del men� o del modo seleccionado
		if(menu == FUNCIONAMIENTO) {
			evaluar();
			mostrarPantalla();
		}
		else {
			evaluarMenu();
		}
	}
}

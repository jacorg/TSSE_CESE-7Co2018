/* Copyright 2019, UNPA 
 * Unidad Academica Rio Gallegos.
 * TP 3 - SALVADOR, Jacobo Omar

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include "stdio.h"
#include <stdint.h>
#include <stdbool.h>

#include "unity.h"
#include "control.h"

// L_LEVEL_0      6              //define nivel mínimo de temperatura 0
// L_LEVEL_1     -15             //define nivel mínimo de temperatura 1
// L_LEVEL_2     -25             //define nivel mínimo de temperatura 2

// H_LEVEL_0     20              //define nivel máximo de temperatura se activa cooling system por sobre 20
// H_LEVEL_1     80		 //define nivel máximo de temperatura se activa cooling system por sobre 80
// H_LEVEL_2     100             //define nivel máximo de temperatura se activa cooling system por sobre 100

//Sistema de control para controlar temperatura en un medio cerrado. El sensor de temperatura genera dato valido entre -40 a 150 C.
// El sistema de calentamiento se hace en base a una serie de heater que trabajan en escalera.
// EL sistema de enfrimiento se hace en base a celdas peltiers trabajando tambien en modo escalonado.



heater_t heater;
cooling_t cooling;


float tmpCase_1[] ={6.0,5.8,5.7,5.6,5.5,5.4};                     //caso 1: 5.66
float tmpCase_2[] ={-16.0,-16.1,-16.2,-16.3,-16.4,-16.5};         //caso 2:-16.25
float tmpCase_3[] ={-26.5,-26.5,-26.5,-26.5,-26.5,-26.5};         //caso 3:-26.5


float tmpCase_4[] ={25.0,25.0,25.0,25.0,25.0,25.0};        //caso 4: 25.0
float tmpCase_5[] ={85.0,85.0,85.0,85.0,85.0,85.0};        //caso 5: 85.0
float tmpCase_6[] ={110.5,110.5,110.5,110.5,110.5,110.5};   //caso 6:110.5

//En los tres casos a continuación se testea el sistema de calentamiento "heater" para tres valores diferentes de temperatura. El sistema de enfriamiento "cooling" debe permanecer apagado siempre.

void test_menor_L_LEVEL_0 (void){
	float *pTemp=tmpCase_1;
	float resultado=0;

	resultado=average(pTemp);
	TEST_ASSERT_FLOAT_WITHIN(0.1,5.66,resultado);

	heaterSystem(&heater,resultado);               //eval heater system with sensor

	TEST_ASSERT_EQUAL(ON,heater.heater_0);         //Se habilito primer heater
	TEST_ASSERT_EQUAL(OFF,heater.heater_1);
	TEST_ASSERT_EQUAL(OFF,heater.heater_2);

	coolingSystem(&cooling,resultado);             //eval cooling system with sensor

	TEST_ASSERT_EQUAL(OFF,cooling.cooling_0);
	TEST_ASSERT_EQUAL(OFF,cooling.cooling_1);
	TEST_ASSERT_EQUAL(OFF,cooling.cooling_2);
}

void test_menor_L_LEVEL_1 (void){
	float *pTemp=tmpCase_2;
	float resultado=0;

	resultado=average(pTemp);
	TEST_ASSERT_FLOAT_WITHIN(0.1,-16.25,resultado);

	heaterSystem(&heater,resultado);               //eval heater system with sensor

	TEST_ASSERT_EQUAL(ON,heater.heater_0);         //Se habilito primer heater_0 y heater_1
	TEST_ASSERT_EQUAL(ON,heater.heater_1);	       //Se habilito primer heater_0 y heater_1
	TEST_ASSERT_EQUAL(OFF,heater.heater_2);

	coolingSystem(&cooling,resultado);             //eval cooling system with sensor

	TEST_ASSERT_EQUAL(OFF,cooling.cooling_0);
	TEST_ASSERT_EQUAL(OFF,cooling.cooling_1);
	TEST_ASSERT_EQUAL(OFF,cooling.cooling_2);
}

void test_menor_L_LEVEL_2 (void){
	float *pTemp=tmpCase_3;
	float resultado=0;

	resultado=average(pTemp);
	TEST_ASSERT_FLOAT_WITHIN(0.1,-26.5,resultado);

	heaterSystem(&heater,resultado);               //eval heater system with sensor

	TEST_ASSERT_EQUAL(ON,heater.heater_0);         //Se habilito primer heater_0 , heater_1 y heater_2
	TEST_ASSERT_EQUAL(ON,heater.heater_1);	       //Se habilito primer heater_0 , heater_1 y heater_2
	TEST_ASSERT_EQUAL(ON,heater.heater_2);	       //Se habilito primer heater_0 , heater_1 y heater_2

	coolingSystem(&cooling,resultado);             //eval cooling system with sensor

	TEST_ASSERT_EQUAL(OFF,cooling.cooling_0);
	TEST_ASSERT_EQUAL(OFF,cooling.cooling_1);
	TEST_ASSERT_EQUAL(OFF,cooling.cooling_2);
}

//=========================================================================================================================================

void test_mayor_H_LEVEL_0 (void){
	float *pTemp=tmpCase_4;
	float resultado=0;

	resultado=average(pTemp);
	TEST_ASSERT_FLOAT_WITHIN(0.1,25.0,resultado);

	heaterSystem(&heater,resultado);               //eval heater system with sensor

	TEST_ASSERT_EQUAL(OFF,heater.heater_0);         //Los heaters en este test deben estar apagados
	TEST_ASSERT_EQUAL(OFF,heater.heater_1);		//Los heaters en este test deben estar apagados
	TEST_ASSERT_EQUAL(OFF,heater.heater_2);		//Los heaters en este test deben estar apagados

	coolingSystem(&cooling,resultado);             //eval cooling system with sensor

	TEST_ASSERT_EQUAL(ON,cooling.cooling_0);	//Se activa 1  cooling porque la temp es superior a 20C
	TEST_ASSERT_EQUAL(OFF,cooling.cooling_1);
	TEST_ASSERT_EQUAL(OFF,cooling.cooling_2);
}

void test_mayor_H_LEVEL_1 (void){
	float *pTemp=tmpCase_5;
	float resultado=0;

	resultado=average(pTemp);
	TEST_ASSERT_FLOAT_WITHIN(0.1,85.0,resultado);

	heaterSystem(&heater,resultado);               //eval heater system with sensor

	TEST_ASSERT_EQUAL(OFF,heater.heater_0);         //Los heaters en este test deben estar apagados
	TEST_ASSERT_EQUAL(OFF,heater.heater_1);		//Los heaters en este test deben estar apagados
	TEST_ASSERT_EQUAL(OFF,heater.heater_2);		//Los heaters en este test deben estar apagados

	coolingSystem(&cooling,resultado);             //eval cooling system with sensor

	TEST_ASSERT_EQUAL(ON,cooling.cooling_0);       //Se activan los 2 cooling porque la temp es superior a 80C
	TEST_ASSERT_EQUAL(ON,cooling.cooling_1);
	TEST_ASSERT_EQUAL(OFF,cooling.cooling_2);
}

void test_mayor_H_LEVEL_2 (void){
	float *pTemp=tmpCase_6;
	float resultado=0;

	resultado=average(pTemp);
	TEST_ASSERT_FLOAT_WITHIN(0.1,110.5,resultado);

	heaterSystem(&heater,resultado);               //eval heater system with sensor

	TEST_ASSERT_EQUAL(OFF,heater.heater_0);         //Los heaters en este test deben estar apagados
	TEST_ASSERT_EQUAL(OFF,heater.heater_1);		//Los heaters en este test deben estar apagados
	TEST_ASSERT_EQUAL(OFF,heater.heater_2);		//Los heaters en este test deben estar apagados

	coolingSystem(&cooling,resultado);             //eval cooling system with sensor

	TEST_ASSERT_EQUAL(ON,cooling.cooling_0);        //Se activan los 3 cooling porque la temp es superior a 100C
	TEST_ASSERT_EQUAL(ON,cooling.cooling_1);
	TEST_ASSERT_EQUAL(ON,cooling.cooling_2);
}


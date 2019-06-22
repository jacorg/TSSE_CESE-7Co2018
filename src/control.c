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
#include "control.h"


//Sistema de control para controlar temperatura en un medio cerrado. El sensor de temperatura genera dato valido entre -40 a 150 C.
// El sistema de calentamiento se hace en base a una serie de heater que trabajan en escalera.
// EL sistema de enfrimiento se hace en base a celdas peltiers trabajando tambien en modo escalonado.


void heaterSystem(heater_t *heater,float temp){

	if (temp<L_LEVEL_2){
		heater->heater_0=ON;
		heater->heater_1=ON;
		heater->heater_2=ON;
	}
	else if (temp<L_LEVEL_1){
		heater->heater_0=ON;
		heater->heater_1=ON;
		heater->heater_2=OFF;
	}
	else if (temp<L_LEVEL_0){
		heater->heater_0=ON;
		heater->heater_1=OFF;
		heater->heater_2=OFF;
	}
	else{
		heater->heater_0=OFF;
		heater->heater_1=OFF;
		heater->heater_2=OFF;
	}
	return;
}


void coolingSystem(cooling_t *cooling,float  temp){
	if (temp>H_LEVEL_2){
		cooling->cooling_0=ON;
		cooling->cooling_1=ON;
		cooling->cooling_2=ON;
	}
	else if (temp>H_LEVEL_1){
		cooling->cooling_0=ON;
		cooling->cooling_1=ON;
		cooling->cooling_2=OFF;
	}
	else if (temp>H_LEVEL_0){
		cooling->cooling_0=ON;
		cooling->cooling_1=OFF;
		cooling->cooling_2=OFF;
	}
	return;
}

float average(float  *pTemp){

	uint8_t i=0;
	float resultado=0;

	for(i=0;i<N_DATA;i++)
	 resultado=*(pTemp+i)+resultado;

   return (resultado/N_DATA);
}







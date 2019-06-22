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


#include <stdint.h>

#define L_LEVEL_0      6              //define nivel mínimo de temperatura 0
#define L_LEVEL_1     -15             //define nivel mínimo de temperatura 1
#define L_LEVEL_2     -25             //define nivel mínimo de temperatura 2

#define H_LEVEL_0     20//define nivel máximo de temperatura se activa cooling system
#define H_LEVEL_1     80
#define H_LEVEL_2     100


#define N_DATA        6

#define OFF           0
#define ON            1

#define TLIMIT_L    -40
#define TLIMIT_H     150


typedef struct{
	bool heater_0;
	bool heater_1;
	bool heater_2;
}heater_t;

typedef struct{
	bool cooling_0;
	bool cooling_1;
	bool cooling_2;
}cooling_t;


void heaterSystem(heater_t *heater,float temp);
void coolingSystem(cooling_t *cooling,float temp);
float average(float  *pTemp);




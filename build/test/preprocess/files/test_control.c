#include "build/temp/_test_control.c"
#include "control.h"
#include "unity.h"


heater_t heater;

cooling_t cooling;





float tmpCase_1[] ={6.0,5.8,5.7,5.6,5.5,5.4};

float tmpCase_2[] ={-16.0,-16.1,-16.2,-16.3,-16.4,-16.5};

float tmpCase_3[] ={-26.5,-26.5,-26.5,-26.5,-26.5,-26.5};





float tmpCase_4[] ={25.0,25.0,25.0,25.0,25.0,25.0};

float tmpCase_5[] ={85.0,85.0,85.0,85.0,85.0,85.0};

float tmpCase_6[] ={110.5,110.5,110.5,110.5,110.5,110.5};







void test_menor_L_LEVEL_0 (void){

 float *pTemp=tmpCase_1;

 float resultado=0;



 resultado=average(pTemp);

 UnityAssertFloatsWithin((UNITY_FLOAT)((0.1)), (UNITY_FLOAT)((5.66)), (UNITY_FLOAT)((resultado)), (

((void *)0)

), (UNITY_UINT)(72));



 heaterSystem(&heater,resultado);



 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((heater.heater_0)), (

((void *)0)

), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((heater.heater_1)), (

((void *)0)

), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((heater.heater_2)), (

((void *)0)

), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_INT);



 coolingSystem(&cooling,resultado);



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((cooling.cooling_0)), (

((void *)0)

), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((cooling.cooling_1)), (

((void *)0)

), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((cooling.cooling_2)), (

((void *)0)

), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_INT);

}



void test_menor_L_LEVEL_1 (void){

 float *pTemp=tmpCase_2;

 float resultado=0;



 resultado=average(pTemp);

 UnityAssertFloatsWithin((UNITY_FLOAT)((0.1)), (UNITY_FLOAT)((-16.25)), (UNITY_FLOAT)((resultado)), (

((void *)0)

), (UNITY_UINT)(92));



 heaterSystem(&heater,resultado);



 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((heater.heater_0)), (

((void *)0)

), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((heater.heater_1)), (

((void *)0)

), (UNITY_UINT)(97), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((heater.heater_2)), (

((void *)0)

), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_INT);



 coolingSystem(&cooling,resultado);



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((cooling.cooling_0)), (

((void *)0)

), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((cooling.cooling_1)), (

((void *)0)

), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((cooling.cooling_2)), (

((void *)0)

), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_INT);

}



void test_menor_L_LEVEL_2 (void){

 float *pTemp=tmpCase_3;

 float resultado=0;



 resultado=average(pTemp);

 UnityAssertFloatsWithin((UNITY_FLOAT)((0.1)), (UNITY_FLOAT)((-26.5)), (UNITY_FLOAT)((resultado)), (

((void *)0)

), (UNITY_UINT)(112));



 heaterSystem(&heater,resultado);



 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((heater.heater_0)), (

((void *)0)

), (UNITY_UINT)(116), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((heater.heater_1)), (

((void *)0)

), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((heater.heater_2)), (

((void *)0)

), (UNITY_UINT)(118), UNITY_DISPLAY_STYLE_INT);



 coolingSystem(&cooling,resultado);



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((cooling.cooling_0)), (

((void *)0)

), (UNITY_UINT)(122), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((cooling.cooling_1)), (

((void *)0)

), (UNITY_UINT)(123), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((cooling.cooling_2)), (

((void *)0)

), (UNITY_UINT)(124), UNITY_DISPLAY_STYLE_INT);

}







void test_mayor_H_LEVEL_0 (void){

 float *pTemp=tmpCase_4;

 float resultado=0;



 resultado=average(pTemp);

 UnityAssertFloatsWithin((UNITY_FLOAT)((0.1)), (UNITY_FLOAT)((25.0)), (UNITY_FLOAT)((resultado)), (

((void *)0)

), (UNITY_UINT)(134));



 heaterSystem(&heater,resultado);



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((heater.heater_0)), (

((void *)0)

), (UNITY_UINT)(138), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((heater.heater_1)), (

((void *)0)

), (UNITY_UINT)(139), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((heater.heater_2)), (

((void *)0)

), (UNITY_UINT)(140), UNITY_DISPLAY_STYLE_INT);



 coolingSystem(&cooling,resultado);



 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((cooling.cooling_0)), (

((void *)0)

), (UNITY_UINT)(144), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((cooling.cooling_1)), (

((void *)0)

), (UNITY_UINT)(145), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((cooling.cooling_2)), (

((void *)0)

), (UNITY_UINT)(146), UNITY_DISPLAY_STYLE_INT);

}



void test_mayor_H_LEVEL_1 (void){

 float *pTemp=tmpCase_5;

 float resultado=0;



 resultado=average(pTemp);

 UnityAssertFloatsWithin((UNITY_FLOAT)((0.1)), (UNITY_FLOAT)((85.0)), (UNITY_FLOAT)((resultado)), (

((void *)0)

), (UNITY_UINT)(154));



 heaterSystem(&heater,resultado);



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((heater.heater_0)), (

((void *)0)

), (UNITY_UINT)(158), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((heater.heater_1)), (

((void *)0)

), (UNITY_UINT)(159), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((heater.heater_2)), (

((void *)0)

), (UNITY_UINT)(160), UNITY_DISPLAY_STYLE_INT);



 coolingSystem(&cooling,resultado);



 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((cooling.cooling_0)), (

((void *)0)

), (UNITY_UINT)(164), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((cooling.cooling_1)), (

((void *)0)

), (UNITY_UINT)(165), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((cooling.cooling_2)), (

((void *)0)

), (UNITY_UINT)(166), UNITY_DISPLAY_STYLE_INT);

}



void test_mayor_H_LEVEL_2 (void){

 float *pTemp=tmpCase_6;

 float resultado=0;



 resultado=average(pTemp);

 UnityAssertFloatsWithin((UNITY_FLOAT)((0.1)), (UNITY_FLOAT)((110.5)), (UNITY_FLOAT)((resultado)), (

((void *)0)

), (UNITY_UINT)(174));



 heaterSystem(&heater,resultado);



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((heater.heater_0)), (

((void *)0)

), (UNITY_UINT)(178), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((heater.heater_1)), (

((void *)0)

), (UNITY_UINT)(179), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((heater.heater_2)), (

((void *)0)

), (UNITY_UINT)(180), UNITY_DISPLAY_STYLE_INT);



 coolingSystem(&cooling,resultado);



 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((cooling.cooling_0)), (

((void *)0)

), (UNITY_UINT)(184), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((cooling.cooling_1)), (

((void *)0)

), (UNITY_UINT)(185), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((cooling.cooling_2)), (

((void *)0)

), (UNITY_UINT)(186), UNITY_DISPLAY_STYLE_INT);

}

#include "SENSORS_interface.h"


static const u16 NTC_LockTable[]= {
	27513,
	26342,
	25228,
	24167,
	23158,
	22196,
	21279,
	20406,
	19573,
	18779,
	18016,
	17299,
	16610,
	15952,
	15323,
	14723,
	14150,
	13602,
	13079,
	12578,
	12099,
	11642,
	11204,
	10785,
	10384,
	10000,
	9632,
	9280,
	8942,
	8619,
	8309,
	8012,
	7727,
	7453,
	7191,
	6940,
	6698,
	6467,
	6244,
	6030,
	5825,
	5628,
	5438,
	5256,
	5081,
	4913,
	4751,
	4595,
	4445,
	4301,
	4168,
	4029,
	3900,
	3776,
	3657,
	3542,
	3431,
	3324,
	3222,
	3122,
	3027,
	2934,
	2845,
	2760,
	2677,
	2597,
	2520,
	2445,
	2373,
	2304,
	2237,
	2172,
	2109,
	2049,
	1990,
	1934,
	1879,
	1826,
	1775,
	1725,
	1678,
	1631,
	1586,
	1543,
	1501,
	1461,
	1421,
	1383,
	1346,
	1310,
	1276,
	1242,
	1210,
	1178,
	1147,
	1118,
	1089,
	1061,
	1034,
	1008,
	983

} ;


u16 SENSORS_TempRead (void) {
	
	u16 miliVolt  =  ADC_ReadToMiliVolt(LM35_CH) ;
	
	//u16 temp =  miliVolt/10 ;
	
	return miliVolt ;
	
	
	
}


u16 SENSORS_MpxRead(void)  {
	
	u16 adc =  ADC_Read(MPX_CH) ;
	u16 pas  ;
	
	pas =(((u32)1000*(adc-55))/921)+150 ;
	return pas ;
	


	
}


u8 SENSORS_NTC10KGetTemp(void){
	
	u16  r1=0 ;
	u8 temp=  0 ;

	u16 milivolt= ADC_ReadToMiliVolt(NTC_10) ;
	
	/* resistance every change temp equation */
	/* 150 equal 150000 potentiometer */
	/* 50  equal  5000    millivlots */
	
	r1= ((50*150)/(milivolt/100)) - 150 ;
	u8 i=0 ; 
	u8 flag=0 ; 
	r1= r1*100 ; 
	
	
	for ( i=0 ; i <100 &&flag==0 ;i++ )
	{
		
		if(NTC_LockTable[i]>r1){
			
			flag=1 ; 
			
			temp =i-1; 
		}
	}
	
	return temp;
}

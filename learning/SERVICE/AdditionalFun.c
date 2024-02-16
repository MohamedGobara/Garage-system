



/********************** includes   *********************************************/

/********************** Helper Functions Declaration "prototype"   *************/

/*********************  Global Variable Defination    **************************/

/*********************  APIs Defination          *******************************/

/*********************  ISRs Defination          *******************************/

/*********************  Helper Function Defination    **************************/




#include "AdditionalFun.h"


u8 string_compare(u8 *str1, u8 *str2)
{
	
	u8 i;
	for (i = 0; str1[i] || str2[i]; i++)
	{
		if (str1[i] != str2[i])
		return FALSE;
	}
	return TRUE;
	
}

void SubStringtoStrAndNum(u8* mainStr, u8* new_str , u8* num ){
	
	u8 i , n=0;

	for(i=0;(mainStr[i]>='A'&&mainStr[i]<='z')||mainStr[i]==' ';i++) {

		new_str[i]=mainStr[i] ;
		
	}
	if(new_str[i-1]==' '){
		new_str[i-1]=0;
	}
	new_str[i]=0 ;
	for(;mainStr[i];i++) {
		if((mainStr[i]>='0'&&mainStr[i]<='9')) {
			n=(mainStr[i]-'0')+(n*10) ;
		}
		
	}
	
	*num=n;
}





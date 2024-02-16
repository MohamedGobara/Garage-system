

#ifndef UTILS_H_
#define UTILS_H_



/********************** includes   *********************************************/

/********************** Macro Declarations   ***********************************/

/*********************  Macro Fucnction Declarations  **************************/

#define SET_BIT(REG,BIT)  (REG=REG|(1<<BIT))
#define CLR_BIT(REG,BIT)  (REG=REG&~(1<<BIT))
#define READ_BIT(REG,BIT) ((REG>>BIT)&1)
#define TOG_BIT(REG,BIT)  (REG=REG^(1<<BIT))
#define WRITE_BIT(REG,BIT,VAL) {\
	REG=REG&~(1<<BIT);\
	REG =REG^(VAL<<BIT);\
}


/*********************  Data Type Declarations   *******************************/



/*********************  Software Interfaces Declarations "APIs"    *************/




#endif /* UTILS_H_ */
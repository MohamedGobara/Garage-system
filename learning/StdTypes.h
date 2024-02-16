/*
File: StdTypes.h
Version: 1.0
Date: 8-7-2032
Author: Mohamed Hussein
Description: contains standard types data types
*/ 

/* File Gard */
#ifndef STDTYPES_H_
#define STDTYPES_H_

/********************** includes   *********************************************/

/********************** Macro Declarations   ***********************************/


#define  NULL_PTR   ((void*)0)
#define  NULL       0


#define MAX_U16 ((u16)65535)
#define MAX_S16 ((s16)32767)
#define MIN_S16 ((S16)-32768)
#define MIN_U16 ((u16)0)

/*********************  Macro Fucnction Declarations  **************************/

/*********************  Data Type Declarations   *******************************/


/* data type equal 8 bits (unsigned) */
typedef unsigned char u8;
/* data type equal 8 bits (signed) */
typedef signed   char s8;

/* data type equal 16 bits (unsigned) */
typedef unsigned int u16;
/* data type equal 16 bits (signed) */
typedef signed   int s16;

/* data type equal 32 bits (unsigned) */
typedef unsigned long u32;
/* data type equal 32 bits (signed) */
typedef signed   long s32;


typedef enum {
	OK,
	NOK,
	OUT_OF_RANGE
}Error_type;

typedef enum {
	FALSE ,
	TRUE
}Bool_type;

/*********************  Software Interfaces Declarations "APIs"    *************/







#endif /* STDTYPES_H_ */
/***************************************************************************
*
*  	Filename: prob6.h
*	Description: Create structure using union, bit fields, and 
*                    standard integer types so that we can either access 
*                    individiual bit fields or the entire regiser with 
*                    a single variable name.
*                    
*       Author: Kathy Grimes 
*               
*       
****************************************************************************/

#ifndef _PROB6_H
#define _PROB6_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//Structure for prob6
typedef union {
  uint32_t reg;
  struct {
    uint8_t ADC14SC : 1;
    uint8_t ADC14ENC : 1;
    uint8_t Reserved23 : 2;
    uint8_t ADC14ON : 1;
    uint8_t Reserved56 : 2;
    uint8_t ADC14MSC : 1;

    uint8_t ADC14SHT0x : 4;
    uint8_t ADC14SHT1x : 4;

    uint8_t ADC14BUSY : 1;
    uint8_t ADC14CONSEQx : 2;
    uint8_t ADC14DIVx : 1;

    uint8_t ADC14DIVx : 1;
    uint8_t ADC14ISSH : 1;
    uint8_t ADC14SHP : 1;
    uint8_t ADC14SHSx : 3;
    uint8_t ADC14PDIV : 2;
  } bit_fields;
} ADC_reg;

#define ADC_REG (*(ADC_reg*)0x3FFF4000)

#endif

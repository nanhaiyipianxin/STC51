main.c
#include "Delay.h"
#include "neixie.h"
#include <REGX52.H>
void main(){
    while(1){
     nixie(1,2);
     //Delay(5);
    nixie(2,0);
     //Delay(5);
    nixie(3,2);
     nixie(4,3);
     //Delay(5);
}
}


Delay.h
#define __DELAY_H__
#ifdef __DELAY_H__
void Delay(unsigned int xms);
#endif

Delay.c
void Delay(unsigned int xms)    //@11.0592MHz
{
  unsigned char i, j;
while(xms--){
  i = 11;
  j = 190;
  do{while (--j);
  } while (--i);
}
}


neixie.h
#define __NEIXIE_H__
#ifdef __NEIXIE_H__
void nixie(unsigned char Location,number);
#endif


neixie.c
#include <REGX52.H>
#include "Delay.h"
unsigned char numl[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void nixie(unsigned char Location,number){
switch(Location){
 case 1:P2_4=1;P2_3=1;P2_2=1;break;
 case 2:P2_4=1;P2_3=1;P2_2=0;break;
 case 3:P2_4=1;P2_3=0;P2_2=1;break;
 case 4:P2_4=1;P2_3=0;P2_2=0;break;
 case 5:P2_4=0;P2_3=1;P2_2=1;break;
 case 6:P2_4=0;P2_3=1;P2_2=0;break;
 case 7: P2_4=0;P2_3=0;P2_2=1;break;
 case 8:P2_4=0;P2_3=0;P2_2=0;break;}
P0=numl[number];
Delay(1);//消除Led残影
P0=0xFF;
}

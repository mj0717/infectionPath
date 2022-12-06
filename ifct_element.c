//
//  ifs_element.c
//  InfestPath
//
//  Created by Juyeop Kim on 2020/10/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ifct_element.h"
//place_t p1;
typedef enum place {
    Seoul,          //0
    Jeju,           //1
    Tokyo,          //2
    LosAngeles,     //3
    NewYork,        //4
    Texas,          //5
    Toronto,        //6
    Paris,          //7
    Nice,           //8
    Rome,           //9
    Milan,          //10
    London,         //11
    Manchester,     //12
    Basel,          //13
    Luzern,         //14
    Munich,         //15
    Frankfurt,      //16
    Berlin,         //17
    Barcelona,      //18
    Madrid,         //19
    Amsterdam,      //20
    Stockholm,      //21
    Oslo,           //22
    Hanoi,          //23
    Bangkok,        //24
    KualaLumpur,    //25
    Singapore,      //26
    Sydney,         //27
    SaoPaulo,       //28
    Cairo,          //29
    Beijing,        //30
    Nairobi,        //31
    Cancun,         //32
    BuenosAires,    //33
    Reykjavik,      //34
    Glasgow,        //35
    Warsow,         //36
    Istanbul,       //37
    Dubai,          //38
    CapeTown        //39
} place_t;

char countryName[N_PLACE+1][MAX_PLACENAME] =
{   "Seoul",
    "Jeju",
    "Tokyo",
    "LosAngeles",
    "NewYork",
    "Texas",
    "Toronto",
    "Paris",
    "Nice",
    "Rome",
    "Milan",
    "London",
    "Manchester",
    "Basel",
    "Luzern",
    "Munich",
    "Frankfurt",
    "Berlin",
    "Barcelona",
    "Madrid",
    "Amsterdam",
    "Stockholm",
    "Oslo",
    "Hanoi",
    "Bangkok",
    "KualaLumpur",
    "Singapore",
    "Sydney",
    "SaoPaulo",
    "Cairo",
    "Beijing",
    "Nairobi",
    "Cancun",
    "BuenosAires",
    "Reykjavik",
    "Glasgow",
    "Warsow",
    "Istanbul",
    "Dubai",
    "CapeTown",
    "Unrecognized"
};

//구조체 구성  
typedef struct ifs_ele{
	//번호 정수 
	//나이 정수 
	//감염시점 정수 
	//감염 직전 이동경로 (enum) place_t배열- N_HISTORY 
} ifs_ele_t;


static ifs_ele_t ifsarray[20];//나중에 바꿀 것 
static int ifs_cnt;//몇 명의 환자가 들어있다


void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY])
{
	ifsarray[ifs_cnt].index = index;
	ifsarray[ifs_cnt].index = index;
	ifsarray[ifs_cnt].index = index;
	ifsarray[ifs_cnt].index = index;
	
	ifs_cnt++;
	
	return (void*)&ifsarray[인덱스]
	 
}




int ifctele_getAge(void* obj)
{
	ifs_ele_t *strPtr = {ifs_ele_t *}obj;
	
	return(//포인터로 멤버에 접근해서 나이);
 } 
void ifsele_printElement(void* obj)
{
	ifs_ele_t *strPtr = {ifs_ele_t *}obj;
	
	//print elements
}








char *ifctele_getPlaceName(int placeIndex)
{
	
	return countryName[placeIndex];
}

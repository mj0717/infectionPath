//
//  main.c
//  infestPath
//
//  Created by Juyeop Kim on 2022/10/20.
//

#include <stdio.h>
#include <string.h>
#include "ifct_element.h"
#include "ifct_database.h"

#define MENU_PATIENT        1
#define MENU_PLACE          2
#define MENU_AGE            3
#define MENU_TRACK          4
#define MENU_EXIT           0

#define TIME_HIDE           2


int trackInfester(int patient_no, int *detected_time, int *place);
int main(int argc, const char * argv[]) {
    
    int menu_selection;
    void *ifct_element;
    FILE* fp;
    int pIndex, age, time;
    int placeHist[N_HISTORY];
    
    //------------- 1. loading patient info file ------------------------------
    //1-1. FILE pointer open
    if (argc != 2)
    {
        printf("[ERROR] syntax : infestPath (file path).");
        return -1;
    }
    
    fp = fopen(argv[1],"r");
    if (fp == NULL)
    {
        printf("[ERROR] Failed to open database file!! (%s)\n", argv[1]);
        return -1;
    }
    
    //1-2. loading each patient informations
    
    while (3==fscanf(fp,"%i %i %i", &pIndex, &age, &time))
	{
		int i;
		for(i=0;i<5;i++)
			fscanf(fp,"%s",&placeHist[i]);
			
			
		ifct_element = ifctele_genElement(pIndex, age, time, placeHist);
		
		ifctdb_addTail(ifct_element);
			
	}   
      	
    
    //1-3. FILE pointer close
    fclose(fp);
    
    
    
    
    do {
        printf("\n=============== INFECTION PATH MANAGEMENT PROGRAM (No. of patients : %i) =============\n", ifctdb_len());
        printf("1. Print details about a patient.\n");                      //MENU_PATIENT
        printf("2. Print list of patients infected at a place.\n");        //MENU_PLACE
        printf("3. Print list of patients in a range of age.\n");          //MENU_AGE
        printf("4. Track the root of the infection\n");                     //MENU_TRACK
        printf("0. Exit.\n");                                               //MENU_EXIT
        printf("=============== ------------------------------------------------------- =============\n\n");
        
        printf("Select a menu :");
        scanf("%d", &menu_selection);
        fflush(stdin);
        
        switch(menu_selection)
        {
            case MENU_EXIT:
                printf("Exiting the program... Bye bye.\n");
                break;
                
            case MENU_PATIENT: 
            
            	printf("index: ");
            	scanf("%i", &pIndex);
            	
            	ifct_element = ifctdb_getData(pIndex);
                ifctele_printElement(ifct_element);//환자 정보 출력 
                
                
                break;
                
           case MENU_PLACE:
            	
		/*	ifct_element;
			int i; 
				
            for(i=0;i<5;i++)
			{  	
               	char *ifctele_getPlaceName(ifctele_getHistPlaceIndex);
                ifct_element = ifctdb_getData(pIndex);	
               	if (strcmp(,placeHist[4])==0)// 
                {
                	ifct_element = ifctdb_getData(pIndex);
                	ifctele_printElement(ifct_element);
				}
			}
                
               braek;*/
			    
            case MENU_AGE:
            	
            	ifct_element;
            	
            	int M;
            	printf("range of age(M):");//최대 나이 입 력  
                scanf("%i", &M);
                
               	int m;
                printf("range of age(m):");//최소 나이 입력  
                scanf("%i", &m);
                
				//나이 범위에 들어가는 환자의 정보 출력  
               for(pIndex=0;pIndex<5;pIndex++)
               {
               		ifct_element = ifctdb_getData(pIndex);
					ifctele_getAge(ifct_element);
					
					if (m<=ifctele_getAge(ifct_element) && ifctele_getAge(ifct_element)<=M)
					
                		ifctele_printElement(ifct_element);//환자 정보 출력  
						
			   }
				
            break;
            
                
            case MENU_TRACK:
            	ifct_element;
            	
            	/*현재환자=입력값;
				while(현재환자==0)
				{
					전파자=trackinfester(현재환자);
					if (trackInfester==0)
						printf("%i환자는 %i환자에게 전파됨\n", 현재환자, trackInfester);
					else
						최초전파자=현재환자;
						현재환자=trackinfester; 
				 }
				for(i=0;i<5;i++)
				{
				 
					만난시간=isMet(현재환자, i번째 환자);
					if (만난시간>0)//만났다면
					{
						if (지금까지 환자 중 만난시간이 가장 이른가?)
						{
							trackInfester=i;
							 
						}
					 } 
				 } 
				
				 return trackInfester;
				 
				for(i=2;i<N_HISTORY;i++)  
				{
					현재환자의 i번쨰 이동장소 시점 계산;
					계산된 시점에서의 대상환자 이동장소 계산;
					if (i번째 이동장소== 대상환자 이동장소)
					{
						만난시간 = i번쩨 이동장소 시점; 
					 } 
				 } 
                
				return 만난시간;    
			
				
                break;*/
                
         
        }
    
    } while(menu_selection != 0);
    
    
    return 0;
}

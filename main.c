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
                ifctele_printElement(ifct_element);//ȯ�� ���� ��� 
                
                
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
            	printf("range of age(M):");//�ִ� ���� �� ��  
                scanf("%i", &M);
                
               	int m;
                printf("range of age(m):");//�ּ� ���� �Է�  
                scanf("%i", &m);
                
				//���� ������ ���� ȯ���� ���� ���  
               for(pIndex=0;pIndex<5;pIndex++)
               {
               		ifct_element = ifctdb_getData(pIndex);
					ifctele_getAge(ifct_element);
					
					if (m<=ifctele_getAge(ifct_element) && ifctele_getAge(ifct_element)<=M)
					
                		ifctele_printElement(ifct_element);//ȯ�� ���� ���  
						
			   }
				
            break;
            
                
            case MENU_TRACK:
            	ifct_element;
            	
            	/*����ȯ��=�Է°�;
				while(����ȯ��==0)
				{
					������=trackinfester(����ȯ��);
					if (trackInfester==0)
						printf("%iȯ�ڴ� %iȯ�ڿ��� ���ĵ�\n", ����ȯ��, trackInfester);
					else
						����������=����ȯ��;
						����ȯ��=trackinfester; 
				 }
				for(i=0;i<5;i++)
				{
				 
					�����ð�=isMet(����ȯ��, i��° ȯ��);
					if (�����ð�>0)//�����ٸ�
					{
						if (���ݱ��� ȯ�� �� �����ð��� ���� �̸���?)
						{
							trackInfester=i;
							 
						}
					 } 
				 } 
				
				 return trackInfester;
				 
				for(i=2;i<N_HISTORY;i++)  
				{
					����ȯ���� i���� �̵���� ���� ���;
					���� ���������� ���ȯ�� �̵���� ���;
					if (i��° �̵����== ���ȯ�� �̵����)
					{
						�����ð� = i���� �̵���� ����; 
					 } 
				 } 
                
				return �����ð�;    
			
				
                break;*/
                
         
        }
    
    } while(menu_selection != 0);
    
    
    return 0;
}

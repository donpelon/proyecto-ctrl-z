#include <stdio.h>


void pasar(char* paso){
	FILE * pFile;
    pFile = fopen ("ctr_z.txt", "wb");
	for(int i = 0;i<=sizeof(paso);i++){
	
	 fputc (paso[i],pFile);
     
	}
	fclose (pFile);
	
}

void Borrar(char *filename)
{ 
    FILE *output = fopen("ctr_z.txt", "w");
    fclose(output);
}

int control(char *Queue_list){
	int i;
    FILE *pFile;
    pFile = fopen("ctr_z.txt", "w");
    if(!pFile) {
         perror("Error opening");
         return 1;
    }
    for(i = 0; i < 100; i++){
    	
    }    
	fclose(pFile);

}



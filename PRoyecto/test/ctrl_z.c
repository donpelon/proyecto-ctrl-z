
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>


boolean LastKey(int x){ // ingrese la tecla que se supone que deberia ser en codigo ASCII
	if(GetAsyncKeyState(VK_BACK) && x == 32){ // agregar aqui en else if eventos para cualquier tecla en especial
		
		return 1;
	}
		
}

char LastChar(char* x){
	int i=0;
	while(x[i] != '\0'){
		i++;
	}
	return x[i];
}



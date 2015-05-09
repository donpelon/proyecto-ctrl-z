#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define LIMIT 5
#define txtbox 1
#define button 2
#define SIZE 100



/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	static HWND Textbox,Button,BackgroundIMG;
	static time_t time1;
	static time_t time2;
	static char buffer[SIZE] = {};
	static boolean tof = 1;
	static boolean deltof = 0;
	if(deltof){ // si el ultimo fue delete
		
		deltof = 0;
	}
	switch(Message) {
			
		case WM_COMMAND:{ // es para detectar eventos
			if(LOWORD(wParam) == txtbox){
			
				if(HIWORD(wParam) == EN_CHANGE && !tof){
					if(time1 == 0){
						
						time1 = time(NULL);
						char buff[20];
						strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&time1));
						SetWindowText(Textbox,buff);
					}
					else{
						time1 = time2;
						time2 = time(NULL);
						
					}
					
					if((time2 - time1) > LIMIT )
					{	
						time1 = time2;
					
						MessageBox(NULL,"me tarde mucho","",MB_OK);
					}
					else if(LastKey(32)){
						deltof = 1;
					}	
				}
				tof = 0;
			}
			else if(LOWORD(wParam) == button){
				MessageBox(NULL,"ME LA PELAS DIEGITO","",MB_OK);	// accion del boton aqui	
			}
			break;
		}
		
		case WM_CREATE:{
			Textbox = CreateWindow(TEXT("edit"),"ezcribeme aqui papirico",WS_BORDER | WS_CHILD |ES_MULTILINE| ES_AUTOHSCROLL| WS_VISIBLE,0,250,640,185,hwnd,(HMENU) txtbox,((LPCREATESTRUCT) lParam)->hInstance,NULL);
			Button = CreateWindow("BUTTON","CONTROL Z",WS_BORDER | WS_VISIBLE | WS_CHILD,200,50,200,50,hwnd,(HMENU) button,NULL,NULL);
			
			break;
		}
		/* trap the WM_CLOSE (clicking X) message, and actually tell the window to close */
		case WM_CLOSE: {
			DestroyWindow(hwnd);
			break;
		}
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG Msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produre unreasonably CPU usage
	*/
	
	while(GetMessage(&Msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&Msg); /* Translate keycodes to chars if present */
		DispatchMessage(&Msg); /* Send it to WndProc */
	}
	return Msg.wParam;
}

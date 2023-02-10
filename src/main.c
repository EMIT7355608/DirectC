#define SDL_MAIN_HANDLED
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "GameObject.h"
#include "Init.h"

extern void FrameEvent();
 
 
int main()
{
	Initialize();
	extern bool quit;int start;
	while (!quit)
	{
		start=SDL_GetTicks();
		FrameEvent();
		int delta=(int)(1000*deltaTime)+start-SDL_GetTicks();
		if(delta>0){
    		SDL_Delay(delta);
		}
	}
	TTF_Quit();
	SDL_DestroyWindow(win);
	SDL_Quit();
	system("pause");
	return 0;
}
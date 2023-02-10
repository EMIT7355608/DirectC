#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include "GameObject.h"
#include "GameManager.h"
#include "EventManager.h"
#include "PlayerManager.h"
#include "CameraManager.h"
#include "Init.h"
#include "ObjectList/Generator.h"
#include "BGMManager.h"
extern SDL_Renderer* renderer;
bool quit = false;

extern struct PlayerManager playerManager;
extern void RenderUI(SDL_Renderer* renderer);

void Inputer(){
	SDL_Event event;
	int counts=0;
	SDL_StopTextInput();
	while (SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT){quit = true;}
		if(event.type==SDL_KEYDOWN){
			if(!gameManager.pause){
				if (event.key.keysym.sym == SDLK_SPACE) { Generate(Default, 0, 0, 0); }
				if (event.key.keysym.sym == SDLK_i) { GameObjectInfo(player); }
			}
			if(gameManager.lose&&event.key.keysym.sym==SDLK_r){StartOver();}
			if(event.key.keysym.sym==SDLK_p){PauseController();}
		}
		counts++;
	}
    SDL_PumpEvents();
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
	
	if(!gameManager.pause){
        if (currentKeyStates[SDL_SCANCODE_DOWN]) {

        }
	}
}

void Rendering(){
	GameObject* pinObject=player;
	for(int layer=0;layer<6;layer++){
		pinObject=player;
		while (pinObject!=NULL)
		{
			if(pinObject->animation.layer==layer){
				RenderObject(renderer,pinObject);
			}
			pinObject=pinObject->next;
		}
	}
	RenderUI(renderer);
}

void FrameUpdate(){
	GameObject* pinObject=player;
	while (pinObject!=NULL)
	{
		pinObject->Update(pinObject);
		pinObject=pinObject->next;
	}
	FrameController();
	EventFrameTime();
}



void FrameEvent()
{
	Inputer();
	if(!gameManager.pause){
	FrameUpdate();}
	SDL_RenderClear(renderer);
    SyncCamera();
	Rendering();
	SDL_RenderPresent(renderer);
    BGMProcess();
}


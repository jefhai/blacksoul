/*
	BlackSoul - Created by Jeffrey Haines
 */

#ifndef BLACKSOUL_ENGINE_H
#define BLACKSOUL_ENGINE_H

#include <stdio.h>
#include <allegro5/allegro.h>

namespace BLACKSOUL  
{      
	class Engine
	{
	public:
		Engine();
		~Engine();

		int go();

		const double cFPS = 60.0;
		const int cScreenWidth = 640;
		const int cScreenHeight = 480;

		bool mDone;
		bool mRedraw;

		ALLEGRO_DISPLAY	*mDisplay = NULL;
		ALLEGRO_EVENT_QUEUE *mEventQueue = NULL;
		ALLEGRO_TIMER *mTimer = NULL;
	};
}

#endif

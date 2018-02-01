/*
	BlackSoul - Created by Jeffrey Haines
 */

#include "engine.h"

#include <allegro5/allegro.h>

namespace BLACKSOUL  
{     
	Engine::Engine() 
	{

	}

	Engine::~Engine() 
	{
		al_destroy_timer(mTimer);
   		al_destroy_display(mDisplay);
   		al_destroy_event_queue(mEventQueue);
	}

	int Engine::go()
	{
		if (!al_init()) 
		{
			return -1;
		}

		mTimer = al_create_timer(1.0 / cFPS);
		if (!mTimer) 
		{
			return -1;
		}

		mDisplay = al_create_display(cScreenWidth, cScreenHeight);
		if(!mDisplay) {
			return -1;
		}

		mEventQueue = al_create_event_queue();
		if (!mEventQueue) 
		{
			return -1;
		}

		al_register_event_source(mEventQueue, al_get_display_event_source(mDisplay));
		al_register_event_source(mEventQueue, al_get_timer_event_source(mTimer));

		al_clear_to_color(al_map_rgb(0,0,0));

		al_flip_display();

		al_start_timer(mTimer);

		while (!mDone)
		{
			ALLEGRO_EVENT ev;
      		al_wait_for_event(mEventQueue, &ev);

			if(ev.type == ALLEGRO_EVENT_TIMER) {
				mRedraw = true;
			}
			else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				return 0;
			}

			if(mRedraw && al_is_event_queue_empty(mEventQueue)) {
				mRedraw = false;
				al_clear_to_color(al_map_rgb(0,0,0));
				al_flip_display();
			}
		}

		return 0;
	}
}













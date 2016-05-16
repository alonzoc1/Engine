#include "event_manager.h"
EventManager::EventManager(ALLEGRO_TIMER * timer, ALLEGRO_DISPLAY * display) {
	event_queue = new  ALLEGRO_EVENT_QUEUE*;
	*event_queue = al_create_event_queue();
	al_register_event_source(*event_queue, al_get_display_event_source(display));
	al_register_event_source(*event_queue, al_get_timer_event_source(timer));
	al_register_event_source(*event_queue, al_get_mouse_event_source());
	al_register_event_source(*event_queue, al_get_keyboard_event_source());
	usable = true;
}

EventManager::~EventManager() {
	if (event_queue != NULL && *event_queue != NULL) {
		al_destroy_event_queue(*event_queue);
		delete event_queue;
		*event_queue = NULL;
		event_queue = NULL;
		usable = false;
	}
}

EventManager::EventManager(){
	event_queue = NULL;
}
#include "event_manager.h"

EventManager::EventManager(ALLEGRO_TIMER * timer, ALLEGRO_DISPLAY * display) {
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());
}

EventManager::~EventManager() {
	if (event_queue != NULL) {

		al_destroy_event_queue(event_queue);
		event_queue = NULL;
	}
}

EventManager::EventManager(){
	event_queue = NULL;
}
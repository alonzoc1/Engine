#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

//this is for holding data regarding the box that shows up when telling units to do actions
//on the map


class ActionBox {
public:
	bool spawn_top;
	bool spawn_left;
	int x;
	int y; //top left corner pixels
	int indv_box_x;
	int indv_box_y;
	char * actions[5]; //Move, Attack, Item, Special, Wait
	bool disable_special;
	int dull[5];
	ActionBox(int x_orig, int y_orig, int x_max, int y_max, int * gray, char * special) {
		if (special == nullptr)
			disable_special = true;
		else {
			disable_special = false;
			actions[3] = special; //what to say in the special box
		}
		int ticker = 0;
		while (ticker < 5) {
			dull[ticker] = gray[ticker];
			ticker++;
		}
		indv_box_y = 40 * (y_orig / 720); //scale
		indv_box_x = 120 * (x_orig / 1280); //scale
		int sum_actions;
		if (disable_special == 1)
			sum_actions = 4;
		else
			sum_actions = 5;
		int x_len = 120;
		int y_len = sum_actions * indv_box_y;
		spawn_left = false;
		if ((x_orig + x_len) > x_max)
			spawn_left = true;
		spawn_top = false;
		if ((y_orig + y_len) > y_max)
			spawn_top = true;
		x = x_orig;
		y = y_orig;
	}

	void draw_box(int x, int y) {
		//draws a signel box, x and y are top left corner coords
	}
	void draw_boxes() {
		//does "draw_box(x, y) a few times to draw all the boxes
	}

};

#endif
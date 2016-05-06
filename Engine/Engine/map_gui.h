#ifndef MAPGUI_H
#define MAPGUI_H
#include "map.h"
#include "event_manager.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <vector>

class MapGui {
private:
	Map m;
	EventManager em;
	vector<ALLEGRO_BITMAP*> bitmaps;
	void drop_at_coords(int x, int y, ALLEGRO_BITMAP * what);
	void add_unit();
	void remove_unit();
	void move_unit();
	void draw_grid(int thick);
	void fill_tiles();
	void place_units();

	int unique_tiles = 2; //how many unique different types of tiles there are (in existance, not just this map) HARDCODED
	int show_x; // how many tiles at once horizontally
	int show_y; // ^^^
	int tile_width =  75; //how many pixels is a tile (its always a square)
	int max_x; //how many tiles there are horizontally on the map
	int max_y; //how many tiles there are vertically
	int cam_x; //measured by tile, cam_x = 0 cam_y = 0 is top left corner
	int cam_y;
public:
	MapGui(Map m_in, EventManager em_in, int res_x, int res_y, int camx, int camy);
	~MapGui();
	int display_map(int thick); //returns 1 if success, 0 otherwise
	void start_game();
};

#endif
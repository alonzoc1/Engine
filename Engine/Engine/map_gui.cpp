#include "map_gui.h"

MapGui::MapGui(Map m_in, EventManager em_in, int res_x, int res_y, int camx, int camy) {
	m = m_in;
	em = em_in;
	show_x = res_x / tile_width;
	show_y = res_y / tile_width;
	max_x = m_in.map_x();
	max_y = m_in.map_y();
	cam_x = camx;
	cam_y = camy;
}

//MapGui::~MapGui() {}

int MapGui::display_map(int thick) {
	draw_grid(thick);
	fill_tiles();
	place_units();
}

void MapGui::start_game() {

}

void MapGui::draw_grid(int thick) {
	int ticker = cam_x;
	int thickness = thick;
	int cur_x = 0;
	int cur_y = 0;
	al_clear_to_color(al_map_rgb(0, 0, 0)); //DO NOT CLEAR COLOR AGAIN, draw_grid DOES IT
	while (ticker <= show_x) {
		al_draw_line(cur_x, 0, cur_x, (show_y*tile_width), al_map_rgb(128,128,128), thick);
		ticker++;
	}
	ticker = 0;
	while (ticker <= show_y) {
		al_draw_line(0, cur_y, (show_x*tile_width), cur_y, al_map_rgb(128, 128, 128), thick);
	}
}

void MapGui::fill_tiles() {

}

void MapGui::place_units() {

}

void MapGui::move_unit() {

}

void MapGui::remove_unit() {

}

void MapGui::add_unit() {

}


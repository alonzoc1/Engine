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
	printf("max_x is %i, max_y is %i\n", max_x, max_y);//DEBUG
}

MapGui::~MapGui() {
	EventManager b;
	em = b;
}

int MapGui::display_map(int thick) {
	fill_tiles();
	draw_grid(thick);
	place_units();
	return 1;
}

void MapGui::start_game() {

}

void MapGui::draw_grid(int thick) {
	printf("map is %i tiles wide and %i tiles tall\n", max_x, max_y); //DEBUG
	int ticker = 0;
	int thickness = thick;
	int cur_x = 0;
	int cur_y = 0;
	int temp;
	if (show_x < max_x)
		temp = show_x;
	else
		temp = max_x;
	while ((ticker <= show_y) && (ticker <= max_y)) {
		al_draw_line(0, cur_y, (temp*tile_width), cur_y, al_map_rgb(128, 128, 128), thick);
		ticker++;
		cur_y += 75;
	}
	ticker = cam_x;
	cur_y -= 75;
	while ((ticker <= show_x) && (ticker <= max_x)) {
		al_draw_line(cur_x, 0, cur_x, (cur_y), al_map_rgb(128,128,128), thick);
		ticker++;
		cur_x += 75;
	}
}

void MapGui::fill_tiles() {
	al_clear_to_color(al_map_rgb(0, 0, 0)); //DO NOT CLEAR COLOR AGAIN, THIS DOES IT
	ALLEGRO_BITMAP ** tiles;
	tiles = new ALLEGRO_BITMAP*[unique_tiles];
	int i = 0;
	while (i < unique_tiles) {
		tiles[i] = NULL;
		i++;
	}
	int cur_x = 0;
	int cur_y = 0;
	int temp;
	int ticker = cam_x;
	if (show_x < max_x)
		temp = show_x;
	else
		temp = max_x;
	while ((ticker < show_y) && (ticker < max_y)) {
		int ticker2 = cam_y;
		printf("ticker = %i\n", ticker);//DEBUG
		vector<int> row = m.get_row_number(ticker);
		while ((ticker2 < show_x) && (ticker2 < max_x)) {
			printf("ticker2 = %i\n", ticker2);//DEBUG
			int tile_id = row[ticker2];
			printf("--tile_id = %i\n", tile_id);//DEBUG
			if (tiles[tile_id - 1] == NULL) { //initialize tile if its not
				switch (tile_id) {
				case 1:
					tiles[tile_id - 1] = al_load_bitmap("tiles/grass.png");
					break;
				case 2:
					tiles[tile_id - 1] = al_load_bitmap("tiles/mountain.png");
					break;
				}
			}
			al_draw_bitmap(tiles[tile_id-1],cur_x, cur_y,0);
			cur_x += 75;
			ticker2++;
		}
		cur_y += 75;
		cur_x = cam_x;
		ticker++;
	}
	delete[] tiles;
}

void MapGui::place_units() {

	al_flip_display(); //place_units is last step, so it updates display
}

void MapGui::move_unit() {

}

void MapGui::remove_unit() {

}

void MapGui::add_unit() {

}


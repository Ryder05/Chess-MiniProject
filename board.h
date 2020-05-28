#pragma once
#include "chessman.h"
struct st
{
	set_of_pairs stsp;
	int poss;
};
class board
{
private:
public:
	board();
	chessman* T[8][8];
	chessman* get_T();
	void show();
	bool move(int_pair s, int_pair f);
	int_pair king_pos();
	bool king_safe();
	void show(int_pair s);
};
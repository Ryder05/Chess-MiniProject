#pragma once
#include <set>
#include <utility>
#include <string>

#include "Player.h"
extern bool valid(int x, int y);
extern int P[8][8];
typedef std::set<std::pair<int, int>> set_of_pairs;
typedef std::pair<int, int> int_pair;
typedef std::string string;
class chessman
{
public:
	bool double_jump_available;
	string id;
	bool is_alive;
private:
	int color;
	std::pair<int, int> cord;
	//Player owner;
public:
	bool set_alive(bool b);
	virtual ~chessman() = default;
	chessman();
	chessman(string ch, int_pair ip);
	void set_cord(int_pair ip, chessman* p);
	int_pair get_cord() const;
	int get_color() { return color; }
	void wipe(chessman* p);
	void set_color(int x) { color = x; };
	virtual set_of_pairs free_movs();
	virtual set_of_pairs valid_pawn_attack() { return set_of_pairs(); };
};
class pawn :public chessman
{
public:
	pawn(string ch, int_pair ip);
    set_of_pairs free_movs();
	set_of_pairs valid_pawn_attack();
private:
};
class rook : virtual public chessman
{
public:
	rook(string ch, int_pair ip);
	virtual set_of_pairs free_movs();
};
class knight :virtual public chessman
{
public:
	knight(string ch, int_pair ip);
	virtual  set_of_pairs free_movs();
};
class bishop :virtual public chessman
{
public:
	bishop(string ch, int_pair ip);
	set_of_pairs free_movs();
};
class queen : virtual public bishop, virtual public rook
{
public:
	queen(string ch, int_pair ip);
	set_of_pairs free_movs();
};
class king :public chessman
{
public:
	king(string ch, int_pair ip);
	set_of_pairs free_movs();
	};
#include <iostream>
#include "chessman.h"

chessman::chessman()
{
	id = "          ";
	cord = std::make_pair(-1, -1);
	color = -1;
	is_alive = true;
}
chessman::chessman(string ch, int_pair ip)
{
	if (ch == "white")
		color = 1;
	else if (ch == "black")
		color = 0;

	cord = ip;
	is_alive = true;
	id = "";
}
void chessman::set_cord(int_pair ip, chessman* p) { p->cord = ip; }
set_of_pairs chessman::free_movs()
{
	std::cout << "fuck phis crappy" << std::endl;
	return set_of_pairs();
}
int_pair chessman::get_cord() const { return cord; }
pawn::pawn(string ch, int_pair ip) :chessman(ch, ip)
{
	double_jump_available = true;
	id = "pn";
}
set_of_pairs pawn::free_movs()
{
	set_of_pairs sp;
	int X = std::get<0>(get_cord()) - 1;
	int Y = std::get<1>(get_cord()) - 1;
	if (get_color() == 1)
	{
		if (double_jump_available)
		{
			if ((valid((X - 1), (Y)) || (valid((X - 2), (Y)))))
			{
				if (((P[X - 1][Y]) == 0))
				{
					sp.insert(std::make_pair(X, Y + 1));
				}
				if ((P[X - 2][Y]) == 0)
				{
					sp.insert(std::make_pair(X - 1, Y + 1));
				}
			}
		}
		else
		{
				if (((P[X - 1][Y]) == 0))
				{
					sp.insert(std::make_pair(X, Y + 1));
				}
		}
		
	}
	else if (get_color() == 0)
	{
		if (double_jump_available)
		{
			if ((valid((X + 1), (Y)) || (valid((X + 2), (Y)))))
			{
				if (((P[X + 1][Y]) == 0))
				{
					sp.insert(std::make_pair(X + 2, Y + 1));
				}
				if ((P[X + 2][Y]) == 0)
				{
					sp.insert(std::make_pair(X + 3, Y + 1));
				}
			}
		}
		else
		{
			if (((P[X + 1][Y]) == 0))
			{ sp.insert(std::make_pair(X + 2, Y + 1)); }
		}
		}
	return sp;}
set_of_pairs pawn::valid_pawn_attack()
{
	set_of_pairs sp;
	int X = std::get<0>(get_cord()) - 1;
	int Y = std::get<1>(get_cord()) - 1;
	if (get_color() == 1)
	{
		if (P[X - 1][Y + 1] == -1)
		{
			sp.insert(std::make_pair(X, Y + 2));
		}
		if (P[X - 1][Y - 1] == -1)
		{
			sp.insert(std::make_pair(X, Y));
		}
		return sp;
	}
	else if (get_color() == 0)
	{
		if (P[X + 1][Y + 1] == -1)
		{
			sp.insert(std::make_pair(X + 2, Y + 2));
		}
		if (P[X + 1][Y - 1] == -1)
		{
			sp.insert(std::make_pair(X + 2, Y));
		}
		/*
				for (auto s : sp)
				{
					std::cout << '(' << s.first << ',' << s.second << ')' << std::endl;
				}*/
		return sp;
	}
}

rook::rook(string ch, int_pair ip) :chessman(ch, ip) { id = "rk"; }
set_of_pairs rook::free_movs()
{
	int X = std::get<0>(get_cord()) - 1;
	int Y = std::get<1>(get_cord()) - 1;
	set_of_pairs sp;
	int i = 1;
	while ((X - i) >= 0)
	{
		if (P[X - i][Y] == 1)
			break;
		else if (P[X - i][Y] == -1)
		{
			sp.insert(std::make_pair(X - i + 1, Y + 1));
			break;
		}
		else
		{
			sp.insert(std::make_pair(X - i + 1, Y + 1));
			i++;
		}
	}
	i = 1;
	while (X + i < 8)
	{
		if (P[X + i][Y] == 1)
			break;
		else if (P[X + i][Y] == -1)
		{
			sp.insert(std::make_pair(X + i + 1, Y + 1));
			break;
		}
		else
		{
			sp.insert(std::make_pair(X + i + 1, Y + 1));
			i++;
		}
	}
	i = 1;
	while ((Y - i) >= 0)
	{
		if (P[X][Y - i] == 1)
			break;
		else if (P[X][Y - i] == -1)
		{
			sp.insert(std::make_pair(X + 1, Y - i + 1));
			break;
		}
		else
		{
			sp.insert(std::make_pair(X + 1, Y - i + 1));
			i++;
		}

	}
	i = 1;
	while (Y + i < 8)
	{
		if (P[X][Y + i] == 1)
			break;
		else if ((P[X][Y + i] == -1))
		{
			sp.insert(std::make_pair(X + 1, Y + 1 + i));
			break;
		}
		else
		{
			sp.insert(std::make_pair(X + 1, Y + i + 1));
			i++;
		}
	}
	/*	for(auto s:sp)
		{
			std::cout << '('<< s.first <<','<<s.second<<')'<<std::endl;
		}*/
	return sp;
}

knight::knight(string ch, int_pair ip) :chessman(ch, ip) { id = "kn"; }
set_of_pairs knight::free_movs()
{
	set_of_pairs sp;
	int X = std::get<0>(get_cord()) - 1;
	int Y = std::get<1>(get_cord()) - 1;
	if (valid(X + 1, Y + 2))
	{
		if (P[X + 1][Y + 2] != 1)
			sp.insert(std::make_pair(X + 1 + 1, Y + 2 + 1));
	}
	if (valid(X + 2, Y + 1))
	{
		if (P[X + 2][Y + 1] != 1)
			sp.insert(std::make_pair(X + 2 + 1, Y + 1 + 1));
	}
	if (valid(X - 1, Y + 2))
	{
		if (P[X - 1][Y + 2] != 1)
			sp.insert(std::make_pair(X - 1 + 1, Y + 2 + 1));
	}
	if (valid(X + 2, Y - 1))
	{
		if (P[X + 2][Y - 1] != 1)
			sp.insert(std::make_pair(X + 2 + 1, Y - 1 + 1));
	}
	if (valid(X - 2, Y + 1))
	{
		if (P[X - 2][Y + 1] != 1)
			sp.insert(std::make_pair(X - 2 + 1, Y + 1 + 1));
	}
	if (valid(X + 1, Y - 2))
	{
		if (P[X + 1][Y - 2] != 1)
			sp.insert(std::make_pair(X + 1 + 1, Y - 2 + 1));
	}
	if (valid(X - 1, Y - 2))
	{
		if (P[X - 1][Y - 2] != 1)
			sp.insert(std::make_pair(X - 1 + 1, Y - 2 + 1));
	}
	if (valid(X - 2, Y - 1))
	{
		if (P[X - 2][Y - 1] != 1)
			sp.insert(std::make_pair(X - 2 + 1, Y - 1 + 1));
	}
	return sp;
}

bishop::bishop(string ch, int_pair ip) :chessman(ch, ip) { id = "bi"; }
set_of_pairs bishop::free_movs()
{
	set_of_pairs sp;
	int X = std::get<0>(get_cord()) - 1;
	int Y = std::get<1>(get_cord()) - 1;
	int i = 1;
	while (valid((X + i), (Y + i)))
	{
		//if((P[X+i][Y+i]<8)&& (P[X + i][Y + i]>=0))
		if (P[X + i][Y + i] == 0)
		{
			sp.insert(std::make_pair(X + i + 1, Y + i + 1));
			i++;
		}
		else if (P[X + i][Y + i] == -1)
		{
			sp.insert(std::make_pair(X + i + 1, Y + i + 1));
			break;
		}
		else
			break;
	}
	i = 1;
	while (valid((X + i), (Y - i)))
	{
		if (P[X + i][Y - i] == 0)
		{
			sp.insert(std::make_pair(X + i + 1, Y - i + 1));
			i++;
		}
		else if (P[X + i][Y - i] == -1)
		{
			sp.insert(std::make_pair(X + i + 1, Y - i + 1));
			break;
		}
		else
			break;
	}
	i = 1;
	while (valid((X - i), (Y + i)))
	{
		if (P[X - i][Y + i] == 0)
		{
			sp.insert(std::make_pair(X - i + 1, Y + i + 1));
			i++;
		}
		else if (P[X - i][Y + i] == -1)
		{
			sp.insert(std::make_pair(X - i + 1, Y + i + 1));
			break;
		}
		else
			break;
	}
	i = 1;
	while (valid((X - i), (Y - i)))
	{
		if (P[X - i][Y - i] == 0)
		{
			sp.insert(std::make_pair(X - i + 1, Y - i + 1));
			i++;
		}
		else if (P[X - i][Y - i] == -1)
		{
			sp.insert(std::make_pair(X - i + 1, Y - i + 1));
			break;
		}
		else
			break;
	}
	/*	for (auto s : sp)
		{
			std::cout << '(' << s.first << ',' << s.second << ')' << std::endl;
		}*/
	return sp;
}

queen::queen(string ch, int_pair ip) :bishop(ch, ip), rook(ch, ip), chessman(ch, ip)
{
	id = "Qn";
}
set_of_pairs queen::free_movs()
{
	set_of_pairs sp,spp;
	sp = bishop::free_movs();
	spp = rook::free_movs();
	for (auto const& x : spp) {sp.insert(std::make_pair(x.first,x.second));}
	return sp;
}

king::king(string ch, int_pair ip) :chessman(ch, ip) { id = "Kg"; }
set_of_pairs king::free_movs()
{
	set_of_pairs sp;
	int X = std::get<0>(get_cord()) - 1;
	int Y = std::get<1>(get_cord()) - 1;
	if (valid(X + 1, Y))
	{
		if (P[X + 1][Y] != 1)
		{
			sp.insert(std::make_pair(X + 1 + 1, Y + 1));
		}
	}
	if (valid(X, Y + 1))
	{
		if (P[X][Y + 1] != 1)
		{
			sp.insert(std::make_pair(X + 1, Y + 1 + 1));
		}
	}

	if (valid(X - 1, Y))
	{
		if (P[X - 1][Y] != 1)
		{
			sp.insert(std::make_pair(X - 1 + 1, Y + 1));
		}
	}
	if (valid(X, Y - 1))
	{
		if (P[X][Y - 1] != 1)
		{
			sp.insert(std::make_pair(X + 1, Y + 1 - 1));
		}
	}
	if (valid(X + 1, Y + 1))
	{
		if (P[X + 1][Y + 1] != 1)
		{
			sp.insert(std::make_pair(X + 1 + 1, Y + 1 + 1));
		}
	}
	if (valid(X - 1, Y - 1))
	{
		if (P[X - 1][Y - 1] != 1)
		{
			sp.insert(std::make_pair(X - 1 + 1, Y + 1 - 1));
		}
	}
	if (valid(X - 1, Y + 1))
	{
		if (P[X - 1][Y + 1] != 1)
		{
			sp.insert(std::make_pair(X - 1 + 1, Y + 1 + 1));
		}
	}
	if (valid(X + 1, Y - 1))
	{
		if (P[X + 1][Y - 1] != 1)
		{
			sp.insert(std::make_pair(X + 1 + 1, Y - 1 + 1));
		}
	}
	/*for (auto s : sp)
	{
		std::cout << '(' << s.first << ',' << s.second << ')' << std::endl;
	}*/
	return sp;
}
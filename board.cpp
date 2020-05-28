#include <iostream>
#include <list>
#include<Windows.h>
#include "Board.h"
#define RED     "\033[31m"
#define RESET   "\033[0m"
board::board()
{
	for (int i = 0; i < 8; i++)
	{
		T[1][i] = new  pawn("black", std::make_pair(2, i + 1));
		T[6][i] = new  pawn("white", std::make_pair(7, i + 1));
	}
	for (int i = 0; i < 8; i++)
	{
		T[2][i] = nullptr;
		T[3][i] = nullptr;
		T[4][i] = nullptr;
		T[5][i] = nullptr;
	}
	T[0][0] = new rook("black", std::make_pair(1, 1));
	T[0][7] = new rook("black", std::make_pair(1, 8));
	T[7][0] = new rook("white", std::make_pair(8, 1));
	T[7][7] = new rook("white", std::make_pair(8, 8));

	T[0][2] = new bishop("black", std::make_pair(1, 3));
	T[0][5] = new bishop("black", std::make_pair(1, 6));
	T[7][2] = new bishop("white", std::make_pair(8, 3));
	T[7][5] = new bishop("white", std::make_pair(8, 6));

	T[0][1] = new knight("black", std::make_pair(1, 2));
	T[0][6] = new knight("black", std::make_pair(1, 7));
	T[7][1] = new knight("white", std::make_pair(8, 2));
	T[7][6] = new knight("white", std::make_pair(8, 7));

	T[0][3] = new queen("black", std::make_pair(1, 4));
	T[7][3] = new queen("white", std::make_pair(8, 4));

	T[0][4] = new king("black", std::make_pair(1, 5));
	T[7][4] = new king("white", std::make_pair(8, 5));
}
chessman* board::get_T()
{
	return T[8][8];
}
void board::show()
{
	std::cout << "\t\t\t\t  ._______________________________________."<< std::endl;
	std::cout << "\t\t\t\t  |-A--|-B--|-C--|-D--|-E--|-F--|-G--|-H--|" << std::endl;
	std::cout << "\t\t\t\t__|____|____|____|____|____|____|____|____|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j == 0)
			{
				std::cout << "\t\t\t\t" << i + 1 << "-| ";
			}
			if (T[i][j] != nullptr)
			{
				if (T[i][j]->get_color() == 1)
					std::cout << "\033[1;34m" << T[i][j]->id << "\033[0m" << " | ";
				if (T[i][j]->get_color() == 0)
					std::cout << "\033[1;35m" << T[i][j]->id << "\033[0m" << " | ";
			}
			else
			{
				std::cout << "** | ";
			}
		}
		if (i != 7)
		{
			std::cout << std::endl;
			std::cout << "\t\t\t\t__|____|____|____|____|____|____|____|____|" << std::endl;

		}
	}
	std::cout << std::endl;
	std::cout << "\t\t\t\t__|____|____|____|____|____|____|____|____|" << std::endl;
	std::cout<<std::endl;
	//std::cout << "__________________________________________|" << std::endl;
}
bool board::move(int_pair s, int_pair f)
{
	chessman* p = T[s.first - 1][s.second - 1];
	int X = s.first - 1;
	int Y = s.second - 1;
	if((P[X][Y]==-1)||(p==nullptr))	{	return	false	;	}
	set_of_pairs sp = p->free_movs();
	if (p->id == "pn")
	{
		set_of_pairs sp1 = p->valid_pawn_attack();
		if (sp1.find(f) != sp1.end())
		{
			p->set_cord(f, T[X][Y]);
			P[f.first - 1][f.second - 1] = P[s.first - 1][s.second - 1];
			T[f.first - 1][f.second - 1] = T[s.first - 1][s.second - 1];
			P[X][Y] = 0;
			T[X][Y] = nullptr;
			return true;
		}
	}
	if (sp.find(f) != sp.end())
	{
		p->set_cord(f, T[X][Y]);
		if (P[f.first - 1][f.second - 1] == -1)
		{
			if (p->id == "pn")
			{
				p->double_jump_available= false;
			}
			T[f.first - 1][f.second - 1] = T[s.first - 1][s.second - 1];
			T[s.first - 1][s.second - 1] = nullptr;
			P[f.first - 1][f.second - 1] = P[s.first - 1][s.second - 1];
			P[X][Y] = 0;
			
			return true;
		}
		else if (P[f.first - 1][f.second - 1] == 0)
		{
			if (p->id == "pn")
			{
				p->double_jump_available = false;
			}
			p->set_cord(f, T[X][Y]);
			P[f.first - 1][f.second - 1] = P[s.first - 1][s.second - 1];
			T[f.first - 1][f.second - 1] = T[s.first - 1][s.second - 1];
			P[X][Y] = 0;
			T[X][Y] = nullptr;
			return true;
		}
	}
	else
	{
		return false;
	}
}
int_pair board::king_pos()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((T[i][j]->id == "Kg") && (P[i][j] == 1))
				return std::make_pair(i + 1, j + 1);

		}
	}
}
bool board::king_safe()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if  (P[i][j] == -1)
			{
				set_of_pairs sp=T[i][j]->free_movs();
				for(const auto&  x:sp)
					if(king_pos()==std::make_pair(i+1,j+1))
						return true	;

			}
		}
	}

}
void board::show(int_pair s)
{
	chessman* p = T[s.first - 1][s.second - 1];
	if(p==nullptr)
	{
		std::cout << RED << "Movement not allowed! TRY AGAIN " << RESET << std::endl; 
		return;
	}
	set_of_pairs sp=p->free_movs();

	std::cout << "\t\t\t\t  ._______________________________________." << std::endl;
	std::cout << "\t\t\t\t  |-A--|-B--|-C--|-D--|-E--|-F--|-G--|-H--|" << std::endl;
	std::cout << "\t\t\t\t__|____|____|____|____|____|____|____|____|" << std::endl;
	if (p->id == "pn")
	{
		set_of_pairs spp=p->valid_pawn_attack();
		for (int i = 0; i < 8; i++)
		{
			std::cout << "\t\t\t\t";
			for (int j = 0; j < 8; j++)
			{
				int_pair f = std::make_pair(i + 1, j + 1);

				if (j == 0)
				{
					std::cout << "" << i + 1 << "-| ";
				}
				if (T[i][j] != nullptr)
				{
					if (T[i][j]->get_color() == 1)
					{
						if (spp.find(f) != spp.end())
							std::cout << "\033[7;31m" << T[i][j]->id << "\033[0m" << " | ";
						else
						{
							if ((i ==s.first-1 ) && (j ==s.second-1 ))
							{
								std::cout << "\033[4;36m" << T[i][j]->id << "\033[0m" << " | ";
							}
							else
							{
								std::cout << "\033[1;34m" << T[i][j]->id << "\033[0m" << " | ";
							}
						}
						
					}
					if (T[i][j]->get_color() == 0)
					{
						if (spp.find(f) != spp.end())
							std::cout << "\033[7;31m" << T[i][j]->id << "\033[0m" << " | ";
						else
						{
							if ((i == s.first - 1) && (j == s.second - 1))
								std::cout << "\033[4;35m" << T[i][j]->id << "\033[0m" << " | ";
							else
								std::cout << "\033[1;35m" << T[i][j]->id << "\033[0m" << " | ";
						}
					}
				}
				else
				{
					if (sp.find(f) != sp.end())
						//std::cout << "\033[7;33m" << "  " << "\033[0m" << " | ";
						//std::cout << "\033[7;33m" << "><" << "\033[0m" << " | ";
						std::cout << "\033[7;33m" << "><" << "\033[0m" << " | ";

					else
						std::cout << "** | ";
				}
			}
			if (i != 7)
			{
				std::cout << std::endl;
				std::cout << "\t\t\t\t__|____|____|____|____|____|____|____|____|" << std::endl;

			}
		}
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			std::cout<<"\t\t\t\t";
			for (int j = 0; j < 8; j++)
			{
				int_pair f = std::make_pair(i + 1, j + 1);

				if (j == 0)
				{
					std::cout << "" << i + 1 << "-| ";
				}
				if (T[i][j] != nullptr)
				{
					if (T[i][j]->get_color() == 1)
					{
						if (sp.find(f) != sp.end())
							std::cout << "\033[7;31m" << T[i][j]->id << "\033[0m" << " | ";
						else
						{
							if ((i == s.first - 1) && (j == s.second - 1))
								std::cout << "\033[4;36m" << T[i][j]->id << "\033[0m" << " | ";
							else
								std::cout << "\033[1;34m" << T[i][j]->id << "\033[0m" << " | ";
						}
					}
					if (T[i][j]->get_color() == 0)
					{
						if (sp.find(f) != sp.end())
							std::cout << "\033[7;31m" << T[i][j]->id << "\033[0m" << " | ";
						else
						{
							if ((i == s.first - 1) && (j == s.second - 1))
								std::cout << "\033[4;35m" << T[i][j]->id << "\033[0m" << " | ";
							else
								std::cout << "\033[1;35m" << T[i][j]->id << "\033[0m" << " | ";
						}
					}
				}
				else
				{
					if (sp.find(f) != sp.end())
						//std::cout << "\033[7;33m" << "  " << "\033[0m" << " | ";
						//std::cout << "\033[7;33m" << "><" << "\033[0m" << " | ";
						std::cout << "\033[7;33m" << "><" << "\033[0m" << " | ";

					else
						std::cout << "** | ";
				}
			}
			if (i != 7)
			{
				std::cout << std::endl;
				std::cout << "\t\t\t\t__|____|____|____|____|____|____|____|____|" << std::endl;

			}
		}
	}
	std::cout << std::endl;
	std::cout << "\t\t\t\t__|____|____|____|____|____|____|____|____|" << std::endl;
	std::cout << std::endl;
}

#pragma once
#include <iostream>
#include<tuple>
#include "Board.h"
#define  inverse(P) for(int ii = 0; ii <= 7; ii++){for (int j = 0; j <= 7; j++){P[ii][j] = P[ii][j] * -1;}}
#define RED     "\033[31m"
#define BLUE     "\033[1;34m"
#define PURPLE     "\033[1;35m"
#define RESET   "\033[0m"
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
int P[8][8] = {
	{-1, -1, -1, -1, -1, -1, -1, -1,},
	{-1, -1, -1, -1, -1, -1, -1, -1,},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1} };
inline bool valid(int x, int y)
{
	if ((x >= 0) && (y >= 0) && (x <= 7) && (y <= 7))
		return true;
	else
		return false;
}
inline int** inv()
{
	int** Pc = new int* [8];
	for (int i = 0; i < 8; i++)
		Pc[i] = new int[8];

	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			Pc[i][j] = (P[i][j]) * -1;
		}
    }
	return Pc;
}
std::tuple<int_pair, int_pair> Extract(string str)
{
	try
	{
		std::string x = str.substr(0, 2);
		std::string y = str.substr(6, 2);
		char x1 = x[0];
		char x2 = x[1];
		char y1 = y[0];
		char y2 = y[1];
		int_pair ip1 = std::make_pair((int)x1 - '0', (int)(x2 - 96));
		int_pair ip2 = std::make_pair((int)y1 - '0', (int)(y2 - 96));
		return std::make_tuple(ip1, ip2);
	}
	catch (const std::out_of_range& oor)
	{
		std::cerr << RED<<"\t\t\t\tError: Try again\n"<<RESET;
		int_pair ip1 = std::make_pair(-1,-1);
		int_pair ip2 = std::make_pair(-1,-1);
		return std::make_tuple(ip1, ip2);

	}
}
void display_header()
{
	std::cout << "*********************************************************************" << std::endl;
	std::cout << "*     _()_                                                           *" <<
		std::endl << "*   _/____\\_                                                         *" <<
		std::endl << "*   \\      /                                               _  _  _   *" <<
		std::endl << "*    \\____/                                               | || || |  *" <<
		std::endl << "*    (____)                                               |_______|  *" <<
		std::endl << "*     |  |                                                \\__ ___ /  *" <<
		std::endl << "*     |__|                  _                              |___|_|   *" <<
		std::endl << "*    /    \\             ___| |__   ___  ___ ___            |_|___|   *" <<
		std::endl << "*   (______)           / __| '_ \\ / _ \\/ __/ __|           |___|_|   *" <<
		std::endl << "*  (________)         | (__| | | |  __/\\__ \\__ \\          (_______)  *" <<
		std::endl << "*  /________\\          \\___|_| |_|\\___||___/___/          /_______\\  *" << std::endl;
	std::cout << std::endl << "*********************************************************************" << std::endl;
}
void welcome()
{
	std::cout
		<< "         ,....,\n"
		<< "      ,::::::<                 ___  ___  ___ ______ _____  ________   __            \n"
		<< "     ,::/^\\\"``.                |  \\/  | / _ \\|  _  \\  ___| | ___ \\ \\ / /    _\n"
		<< "    ,::/, `   e`.              | .  . |/ /_\\ \\ | | | |__   | |_/ /\\ V /    (_)                     \n"
		<< "   ,::; |        '.            | |\\/| ||  _  | | | |  __|  | ___ \\ \\ /                                        \n"
		<< "   ,::|  \\___,-.  c)           | |  | || | | | |/ /| |___  | |_/ / | |      _                                 \n"
		<< "   ;::|     \\   '-'            \\_|  |_/\\_| |_/___/ \\____/  \\____/  \\_/     (_)                                \n"
		<< "   ;::|      \\                \n"
		<< "   ;::|   _.=`\\                \n"
		<< "   `;:|.=` _.=`\\                 _____ _____  ___  ___  ___  ___             ___  ___ _   _ ___________ _____  \n"
		<< "     '|_.=`   __\\               |  _  /  ___|/ _ \\ |  \\/  | / _ \\            |  \\/  || | | |_   _| ___ \\_   _|\n"
		<< "     `\\_..==`` /                | | | \\ `--./ /_\\ \\| .  . |/ /_\\ \\           | .  . || |_| | | | | |_/ / | |  \n"
		<< "      .'.___.-'.                | | | |`--. \\  _  || |\\/| ||  _  |           | |\\/| ||  _  | | | |    /  | |   \n"
		<< "     /          \\               \\ \\_/ /\\__/ / | | || |  | || | | |           | |  | || | | |_| |_| |\\ \\ _| |_  \n"
		<< "    ('--......--')               \\___/\\____/\\_| |_/\\_|  |_/\\_| |_/           \\_|  |_/\\_| |_/\\___/\\_| \\_|\\___/  \n"
		<< "    /'--......--'\\                \n"
		<< "    `\"--......--\"                \n";
}
int_pair help(string str)
{
	std::string x = str.substr(5, 2);
	char x1 = x[0];
	char x2 = x[1];
	return std::make_pair((int)x1 - '0', (int)(x2 - 96));
}
bool inline seek_help(string str)
{
	std::string x = str.substr(0, 4);
	if (x == "help")	
		return true;
	else
		return false;
}
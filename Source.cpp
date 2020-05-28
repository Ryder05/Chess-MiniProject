#include "global.h"
#include<windows.h>
int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 950, 650, TRUE);
	board b;
	int n = -1;
	int vb = -1;
	std::string str; 
	while (true)
	{
		n++;
		bool ERR=false;
		system("cls");
		welcome();
		if ((pow(-1, n)) == 1)
		{
			if (++vb)
			{
				inverse(P)
				welcome();
			}
		jGreater:
				b.show();
			    if (ERR)
			    {
			    	system("cls");
			    	welcome();
					std::cout << std::endl << RED << "\t\t\t\t\tMovement not allowed! TRY AGAIN " << RESET << std::endl;

			    	b.show();
			    }
		jjGreater:
				std::cout <<BLUE<< "\t\t\tPlayer 1 turn :"<<RESET;
				getline(std::cin, str);
				if(seek_help(str))
				{
			    	system("cls");
			    	welcome();
			    	b.show(help(str));
			    	goto jjGreater ;
		  		}
			std::tuple<int_pair, int_pair> tup=Extract(str);
			if(std::get<0>(tup)==std::make_pair(-1,-1))
				goto jjGreater;
			if (b.move(std::get<0>(tup), std::get<1>(tup)) == false)
				{
					ERR=true;
					goto jGreater;
				}
		}
		else if ((pow(-1, n)) == -1)
		{
			bool ERRR=false;
			inverse(P)
		iGreater:
			system("cls");
			welcome();
			b.show();
			if (ERRR)
			{

				system("cls");
				welcome();
				std::cout << std::endl << RED << "\t\t\t\t\tMovement not allowed! TRY AGAIN " << RESET << std::endl;

				b.show();

			}
		iiGreater:
			std::cout << PURPLE<<"\t\t\tPlayer 2 turn :"<<RESET;	
			getline(std::cin, str);
			if (seek_help(str))
			{
				system("cls");
				welcome();
				b.show(help(str));
				goto iiGreater;
			}
			std::tuple<int_pair, int_pair> tup = Extract(str);
			if (std::get<0>(tup) == std::make_pair(-1, -1))
				goto iiGreater;
			if (b.move(std::get<0>(tup), std::get<1>(tup)) == false)
			{
				ERRR = true;
				goto iGreater;
			}
		}
	}
}
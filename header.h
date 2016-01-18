#include <iostream>
#include "rlutil.h"
#include <string.h>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>

int v;
using namespace std;
void AfisareTitlu()
{
	rlutil::setColor(11);
	cout << "                  .===================.\n";
	cout << "                 ||"; rlutil::resetColor(); cout << "       X si 0 "; rlutil::setColor(11); cout << "     || \n";
	cout << "                  '==================='\n\n\n";
	rlutil::resetColor();
}
void AfisareMeniu()
{
	system("CLS");
	rlutil::saveDefaultColor();
	cout << "\n";
	AfisareTitlu();
	rlutil::setColor(11); 
	cout << "   _______________________MENIU_______________________\n";
	cout << "  |                                                   |\n";
	cout << "  |               "; rlutil::setColor(10); cout << "1) Jucator vs Computer"; rlutil::setColor(11); cout<<"              | \n";
	cout << "  |               "; rlutil::setColor(10); cout << "2) Jucator vs Jucator"; rlutil::setColor(11); cout<<"               | \n";
	cout << "  |               "; rlutil::setColor(10); cout << "3) Iesire"; rlutil::setColor(11); cout << "                           | \n";
	cout << "  |___________________________________________________|\n";

	for (int i = 0; i < 12; i++) cout << '\n';
}
void AfisareMatrice(char m[3][3])
{
	rlutil::setColor(10); cout << "                       A    B    C\n\n";
	rlutil::resetColor(); cout << "                          |   |  \n";
	rlutil::setColor(14); cout << "                1      "; rlutil::setColor(7); cout << m[0][0]; rlutil::resetColor(); cout << "  | "; rlutil::setColor(7); cout << m[0][1]; rlutil::resetColor(); cout << " | "; rlutil::setColor(7); cout << m[0][2] << "\n";
	rlutil::resetColor(); cout << "                    ------+---+-----\n";
	rlutil::setColor(14); cout << "                2      "; rlutil::setColor(7); cout << m[1][0]; rlutil::resetColor(); cout << "  | "; rlutil::setColor(7); cout << m[1][1]; rlutil::resetColor(); cout << " | "; rlutil::setColor(7); cout << m[1][2] << "\n";
	rlutil::resetColor(); cout << "                    ------+---+-----\n";
	rlutil::setColor(14); cout << "                3      "; rlutil::setColor(7); cout << m[2][0]; rlutil::resetColor(); cout << "  | "; rlutil::setColor(7); cout << m[2][1]; rlutil::resetColor(); cout << " | "; rlutil::setColor(7); cout << m[2][2] << "\n";
	rlutil::resetColor(); cout << "                          |   |\n";
}
bool Castigat(char m[3][3], char J)
{
	if (m[0][0] == m[0][1] && m[0][1] == m[0][2] && m[0][2] == J)// l1
		return true;
	if (m[1][0] == m[1][1] && m[1][1] == m[1][2] && m[1][2] == J)// l2
		return true;
	if (m[2][0] == m[2][1] && m[2][1] == m[2][2] && m[2][2] == J)// l3
		return true;
	if (m[0][0] == m[1][0] && m[1][0] == m[2][0] && m[2][0] == J) // c1
		return true;
	if (m[0][1] == m[1][1] && m[1][1] == m[2][1] && m[2][1] == J)
		return true;
	if (m[0][2] == m[1][2] && m[1][2] == m[2][2] && m[2][2] == J) ////
		return true;
	if (m[0][0] == m[1][1] && m[1][1] == m[2][2] && m[2][2] == J)
		return true;
	if (m[0][2] == m[1][1] && m[1][1] == m[2][0] && m[2][0] == J)
		return true;
	return false;
}
bool EsteValid(char t[2])
{
	return (strchr("123", t[0]) && strchr("ABCabc", t[1]) || strchr("123", t[1]) && strchr("ABCabc", t[0]) ) && strlen(t)==2;
}
void AfisareScor(int mJ, int scorX, int scor0, char* nX, char* n0)
{
	char str1[15], str2[15];
	int nrsp1 = 13 - strlen(nX);
	int nrsp2 = 13 - strlen(n0);
	int i = 0;
	while (i < nrsp1)
	{
		str1[i++] = ' ';
	}
	str1[i] = 0;
	i = 0;
	while (i < nrsp2)
	{
		str2[i++] = ' ';
	}
	str2[i] = 0;
	rlutil::setColor(11); cout << "           ____________________________________\n";
	rlutil::setColor(11); cout << "          |           "; rlutil::setColor(10); cout << "Tabela de scor"; rlutil::setColor(11); cout << "           | \n";
	rlutil::setColor(11); cout << "          |                                    |\n";
	rlutil::setColor(11); cout << "          |          "; rlutil::resetColor(); cout << "Mecuri jucate: " << mJ; rlutil::setColor(11); cout<< "          | \n";
	rlutil::setColor(11); cout << "          |          "; rlutil::resetColor(); cout << nX << ": " << str1 << scorX; rlutil::setColor(11); cout << "          | \n";
	rlutil::setColor(11); cout << "          |          "; rlutil::resetColor(); cout << n0 << ": " << str2 << scor0; rlutil::setColor(11); cout << "          | \n";
	rlutil::setColor(11); cout << "          |____________________________________|\n";
}
bool Egalitate(char m[3][3])
{
	int sp = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (m[i][j] != ' ') sp++;

	return sp == 9;
}
void GolireMatrice(char m[3][3])
{
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
		m[i][j] = ' ';
}
void Miscare_Computer(char M[3][3], int dif, int k, char S)
{
	if (dif == 1)
	{
		int i, j;
		i = rand() % 3;
		j = rand() % 3;
		while (M[i][j] != ' ') { 
			i = rand() % 3; 
			j = rand() % 3;
		}
		M[i][j] = S;
	}
	else
	{
		if (S == 'X')
		{
			if (k == 1)
				M[1][1] = 'X';
			else if (k == 2)
			{
				srand(time(NULL));
				if (M[0][0] == '0') M[2][2] = 'X';
				else if (M[2][2] == '0') M[0][0] = 'X';
				else if (M[2][0] == '0') M[0][2] = 'X';
				else if (M[0][2] == '0') M[2][0] = 'X';
				else
				{
				t:
					int v1[2] = { 0, 2 }, v2[2] = { 0, 2 };
					int i = v1[rand() % 2], j = v2[rand() % 2];
					if (M[i][j] == ' ') M[i][j] = 'X';
					else goto t;
				}
			}
			else if (k == 3)
			{
				if (M[0][0] == 'X' && M[2][2] == ' ') M[2][2] = 'X';///////Castiga pe diag
				else if (M[2][2] == 'X' && M[0][0] == ' ') M[0][0] = 'X';//------||------
				else if (M[2][0] == 'X' && M[0][2] == ' ') M[0][2] = 'X';//------||------
				else if (M[0][2] == 'X' && M[2][0] == ' ') M[2][0] = 'X';//------||------
				else if (M[0][0] == '0' && M[2][0] == '0') M[1][0] = 'X';//Aparare
				else if (M[0][0] == '0' && M[0][2] == '0') M[0][1] = 'X';//---||---
				else if (M[0][2] == '0' && M[2][2] == '0') M[1][2] = 'X';//---||---
				else if (M[2][0] == '0' && M[2][2] == '0') M[2][1] = 'X';//---||---
				// V
				else if (M[2][2] == 'X')
				{
					if (M[1][0] == '0') M[2][0] = 'X', v = 1;
					else if (M[0][1] == '0') M[0][2] = 'X', v = 2;
					else if (M[1][2] == ' ') M[0][2] = 'X', v = 2;
					else if (M[2][1] == ' ') M[2][0] = 'X', v = 1;
				}
				else if (M[2][0] == 'X')
				{
					if (M[1][2] == '0') M[2][2] = 'X', v = 3;
					else if (M[1][0] == '0') M[0][0] = 'X', v = 4;
					else if (M[1][0] == ' ') M[0][0] = 'X', v = 4;
					else if (M[2][1] == ' ') M[2][2] = 'X', v = 3;
				}

				else if (M[0][2] == 'X')
				{
					if (M[1][0] == '0') M[0][0] = 'X', v = 5;
					else if (M[2][1] == '0') M[2][2] = 'X', v = 6;
					else if (M[0][1] == ' ') M[0][0] = 'X', v = 5;
					else if (M[1][2] == ' ') M[2][2] = 'X', v = 6;
				}
				else if (M[0][0] == 'X')
				{
					if (M[1][2] == '0') M[0][2] = 'X', v = 7;
					else if (M[2][1] == '0') M[2][0] = 'X', v = 8;
					else if (M[1][0] == ' ') M[2][0] = 'X', v = 8;
					else if (M[1][0] == ' ') M[0][2] = 'X', v = 7;
				}
			}
			else if (k == 4)
			{
				//win
				if (M[1][2] == 'X' && M[1][0] == ' ') M[1][0] = 'X';
				else if (M[1][0] == 'X' && M[1][2] == ' ') M[1][2] = 'X';
				else if (M[0][1] == 'X' && M[2][1] == ' ') M[2][1] = 'X';
				else if (M[2][1] == 'X' && M[0][1] == ' ') M[0][1] = 'X';
				//V
				else if (v == 1)
				{
					if (M[2][1] == ' ') M[2][1] = 'X';
					else if (M[0][2] == ' ') M[0][2] = 'X';
				}
				else if (v == 2)
				{
					if (M[1][2] == ' ') M[1][2] = 'X';
					else if (M[2][0] == ' ') M[2][0] = 'X';
				}
				else if (v == 3)
				{
					if (M[2][1] == ' ') M[2][1] = 'X';
					else if (M[0][0] == ' ') M[0][0] = 'X';
				}
				else if (v == 4)
				{
					if (M[2][2] == ' ') M[2][2] = 'X';
					else if (M[1][0] == ' ') M[1][0] = 'X';
				}
				else if (v == 5)
				{
					if (M[2][2] == ' ') M[2][2] = 'X';
					else if (M[0][1] == ' ') M[0][1] = 'X';
				}
				else if (v == 6)
				{
					if (M[1][2] == ' ') M[1][2] = 'X';
					else if (M[0][0] == ' ') M[0][0] = 'X';
				}
				else if (v == 7)
				{
					if (M[2][0] == ' ') M[2][0] = 'X';
					else if (M[0][1] == ' ') M[0][1] = 'X';
				}
				else if (v == 8)
				{
					if (M[1][0] == ' ') M[1][0] = 'X';
					else if (M[0][2] == ' ') M[0][2] = 'X';
				}
				//
				else if (M[1][0] == ' ') M[1][0] = 'X';
				else if (M[0][1] == ' ') M[0][1] = 'X';
				else if (M[1][2] == ' ') M[1][2] = 'X';
				else if (M[2][1] == ' ') M[2][1] = 'X';
			}
			else if (k == 5)
			{
				if (M[0][1] == 'X' && M[2][1] == ' ') M[2][1] = 'X';
				else if (M[0][1] == ' ' && M[2][1] == 'X') M[0][1] = 'X';
				else if (M[1][0] == 'X' && M[1][2] == ' ') M[1][2] = 'X';
				else if (M[1][0] == ' ' && M[1][2] == 'X') M[1][0] = 'X';
				else if (M[0][0] == ' ') M[0][0] = 'X';
				else if (M[2][2] == ' ') M[2][2] = 'X';
				else if (M[0][2] == ' ') M[0][2] = 'X';
				else M[2][0] = 'X';
			}
		}
		else
		{
			if (k == 1)
			{
				if (M[1][1] == ' ') 
					M[1][1] = '0';
				else
				{
					srand(time(NULL));
					t4:
						int v1[2] = { 0, 2 }, v2[2] = { 0, 2 };
						int i = v1[rand() % 2], j = v2[rand() % 2];
						if (M[i][j] == ' ') M[i][j] = '0';
						else goto t4;
				}
			}
			else if (k == 2)
			{
				//Aparare
				if (M[1][1] == '0')
				{
					if (M[0][0] == 'X' && M[0][1] == 'X' && M[0][2] == ' ') M[0][2] = '0';
					else if (M[0][0] == ' ' && M[0][1] == 'X' && M[0][2] == 'X') M[0][0] = '0';
					else if (M[0][0] == 'X' && M[0][1] == ' ' && M[0][2] == 'X') M[0][1] = '0';

					else if (M[2][0] == ' ' && M[2][1] == 'X' && M[2][2] == 'X') M[2][0] = '0';
					else if (M[2][0] == 'X' && M[2][1] == 'X' && M[2][2] == ' ') M[2][2] = '0';
					else if (M[2][0] == 'X' && M[2][1] == ' ' && M[2][2] == 'X') M[2][1] = '0';

					else if (M[0][0] == ' ' && M[1][0] == 'X' && M[2][0] == 'X') M[0][0] = '0';
					else if (M[0][0] == 'X' && M[1][0] == 'X' && M[2][0] == ' ') M[2][0] = '0';
					else if (M[0][0] == 'X' && M[1][0] == ' ' && M[2][0] == 'X') M[1][0] = '0';

					else if (M[0][2] == 'X' && M[1][2] == 'X' && M[2][2] == ' ') M[2][2] = '0';
					else if (M[0][2] == ' ' && M[1][2] == 'X' && M[2][2] == 'X') M[0][2] = '0';
					else if (M[0][2] == 'X' && M[1][2] == ' ' && M[2][2] == 'X') M[1][2] = '0';
					else if (M[0][1] == ' ') M[0][1] = '0';
					else if (M[2][1] == ' ') M[2][1] = '0';
					else if (M[1][0] == ' ') M[1][0] = '0';
					else if (M[1][2] == ' ') M[1][2] = '0';
				}
				else
				{
					if (M[0][0] == 'X' && M[2][2] == ' ') M[2][2] = '0';
					else if (M[0][0] == ' ' && M[2][2] == 'X') M[0][0] = '0';

					else if (M[0][2] == 'X' && M[2][0] == ' ') M[2][0] = '0';
					else if (M[0][2] == ' ' && M[2][0] == 'X') M[0][2] = '0';

					else if (M[0][1] == 'X' && M[2][1] == ' ') M[2][1] = '0';
					else if (M[0][1] == ' ' && M[2][1] == 'X') M[0][1] = '0';

					else if (M[1][0] == 'X' && M[1][2] == ' ') M[1][2] = '0';
					else if (M[1][0] == ' ' && M[1][2] == 'X') M[1][0] = '0';
					else
					{
						srand(time(NULL));
					t5:
						int v1[2] = { 0, 2 }, v2[2] = { 0, 2 };
						int i = v1[rand() % 2], j = v2[rand() % 2];
						if (M[i][j] == ' ') M[i][j] = '0';
						else goto t5;
					}

				}
			}
			else if (k == 3)
			{
				if (M[1][1] == '0')
				{
					//atc
					if (M[0][0] == '0' && M[2][2] == ' ') M[2][2] = '0';//dp
					else if (M[0][0] == ' ' && M[2][2] == '0') M[0][0] = '0';//

					else if (M[0][2] == '0' && M[2][0] == ' ') M[2][0] = '0'; // ds
					else if (M[0][2] == ' ' && M[2][0] == '0') M[0][2] = '0';

					else if (M[0][1] == '0' && M[2][1] == ' ') M[2][1] = '0';
					else if (M[0][1] == ' ' && M[2][1] == '0') M[0][1] = '0';

					else if (M[1][0] == '0' && M[1][2] == ' ') M[1][2] = '0';
					else if (M[1][0] == ' ' && M[1][2] == '0') M[1][0] = '0';

					//
					//apr
					else if (M[0][0] == 'X' && M[0][1] == ' ' && M[0][2] == 'X') M[0][1] = '0';
					else if (M[0][0] == 'X' && M[1][0] == ' ' && M[2][0] == 'X') M[1][0] = '0';
					else if (M[2][0] == 'X' && M[2][1] == ' ' && M[2][2] == 'X') M[2][1] = '0';
					else if (M[0][2] == 'X' && M[1][2] == ' ' && M[2][2] == 'X') M[1][2] = '0';
					else
					{
						if (M[0][1] == ' ' && M[2][1] == ' ') M[0][1] = '0';
						else if (M[1][0] == ' ' && M[1][2] == ' ') M[1][2] = '0';
					}
				}
				else
				{
					//atc
					if (M[0][0] == '0' && M[0][1] == ' ' && M[0][2] == '0') M[0][1] = '0';
					else if (M[0][0] == '0' && M[1][0] == ' ' && M[2][0] == '0') M[1][0] = '0';
					else if (M[0][2] == '0' && M[1][2] == ' ' && M[2][2] == '0') M[1][2] = '0';
					else if (M[2][0] == '0' && M[2][1] == ' ' && M[2][2] == '0') M[2][1] = '0';
					//apr
					else if (M[0][0] == 'X' && M[2][2] == ' ') M[2][2] = '0';//dp
					else if (M[0][0] == ' ' && M[2][2] == 'X') M[0][0] = '0';//

					else if (M[0][2] == 'X' && M[2][0] == ' ') M[2][0] = '0'; // ds
					else if (M[0][2] == ' ' && M[2][0] == 'X') M[0][2] = '0';

					else if (M[0][1] == 'X' && M[2][1] == ' ') M[2][1] = '0';
					else if (M[0][1] == ' ' && M[2][1] == 'X') M[0][1] = '0';

					else if (M[1][0] == 'X' && M[1][2] == ' ') M[1][2] = '0';
					else if (M[1][0] == ' ' && M[1][2] == 'X') M[1][0] = '0';
				}
			}
			else if (k == 4)
			{
				if (M[1][1] == '0')
				{

					if (M[1][0] == '0' && M[1][2] == ' ') M[1][2] = '0';
					else if (M[1][0] == ' ' && M[1][2] == '0') M[1][0] = '0';
					else if (M[0][1] == '0' && M[2][1] == ' ') M[2][1] = '0';
					else if (M[0][1] == ' ' && M[2][1] == '0') M[0][1] = '0';

					else if (M[0][0] == 'X' && M[0][1] == 'X' && M[0][2] == ' ') M[0][2] = '0';
					else if (M[0][0] == ' ' && M[0][1] == 'X' && M[0][2] == 'X') M[0][0] = '0';

					else if (M[2][0] == 'X' && M[2][1] == 'X' && M[2][2] == ' ') M[2][2] = '0';
					else if (M[2][0] == ' ' && M[2][1] == 'X' && M[2][2] == 'X') M[2][0] = '0';

					else if (M[0][0] == 'X' && M[1][0] == 'X' && M[2][0] == ' ') M[2][0] = '0';
					else if (M[0][0] == ' ' && M[1][0] == 'X' && M[2][0] == 'X') M[0][0] = '0';

					else if (M[0][2] == 'X' && M[1][2] == 'X' && M[2][2] == ' ') M[2][2] = '0';
					else if (M[0][2] == ' ' && M[1][2] == 'X' && M[2][2] == 'X') M[0][2] = '0';

					else
					{
						srand(time(NULL));
					t7:
						int v1[2] = { 0, 2 }, v2[2] = { 0, 2 };
						int i = v1[rand() % 2], j = v2[rand() % 2];
						if (M[i][j] == ' ') M[i][j] = '0';
						else goto t7;
					}
				}
				else
				{
					if (M[1][0] == 'X' && M[1][2] == ' ') M[1][2] = '0';
					else if (M[1][0] == ' ' && M[1][2] == 'X') M[1][0] = '0';
					else if (M[0][1] == 'X' && M[2][1] == ' ') M[2][1] = '0';
					else if (M[0][1] == ' ' && M[2][1] == 'X') M[0][1] = '0';
					else if (M[0][1] == ' ') M[0][1] = '0';
					else if (M[2][1] == ' ') M[2][1] = '0';
					else if (M[1][0] == ' ') M[1][0] = '0';
					else if (M[1][2] == ' ') M[1][2] = '0';
				}
			}
		}
	}
}
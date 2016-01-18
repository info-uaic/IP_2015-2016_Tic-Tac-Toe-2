#include "header.h"
using namespace std;


char M[3][3] = { { ' ', ' ', ' ' },
				 { ' ', ' ', ' ' },
				 { ' ', ' ', ' ' } };
bool sf;
int mJ, scor0, cmd, i, j, cmd2, k=1;
int scorJ1, scorJ2;
char t[2], ord, nJuc1[15], nJuc2[15], nJucX[15], nJuc0[15];
char nScorJ1[18], nScorJ2[18];
#define LUNG_NUME 9

int main()
{
start:
	AfisareMeniu();
	rlutil::resetColor();
	scorJ1 = 0;
	scorJ2 = 0;
	mJ = 0;
	ord = 'X';	
	k = 1;
p:
	cin >> cmd;
	if (cmd == 1) // Player vs Computer
	{
		system("CLS");
		cout << "\n";
		AfisareTitlu();
		rlutil::setColor(10); cout << "              Alegeti nivelul de dificultate:\n";
		rlutil::resetColor(); cout << "                    (1-USOR / 2-GREU)\n\n";
		cin >> cmd2;
	re:
		system("CLS");
		cout << "\n";
		AfisareTitlu();
		rlutil::setColor(10); cout << "                   Introduceti numele:\n";
		rlutil::resetColor();
		cout << "                       "; cin >> nJuc1;
		if (strlen(nJuc1) > LUNG_NUME)
		{
			rlutil::setColor(11); cout << "        EROARE!  ";
			rlutil::resetColor(); cout << "Lungimea maxima a numelui este de 9 caractere.\n";
			Sleep(2500);
			goto re;
		}
		if (cmd2 == 1)
		{
			
		runda_noua:
			srand(time(NULL));
			int rnd = rand() % 2; // 0 - Juc / 1 - Comp
			if (rnd == 0)
			{ 
				strcpy_s(nJucX, nJuc1); 
				strcpy_s(nScorJ1, nJuc1);
				strcat_s(nScorJ1, " (X)");
				strcpy_s(nJuc0, "Computer");
				strcpy_s(nScorJ2, "Computer (0)");
			}
			else
			{
				strcpy_s(nJucX, "Computer");
				strcpy_s(nScorJ2, "Computer (X)");
				strcpy_s(nJuc0, nJuc1);
				strcpy_s(nScorJ1, nJuc1);
				strcat_s(nScorJ1, " (0)");
			}

		jump2:
			system("CLS");
			cout << "\n";
			AfisareTitlu();
		//	cout << "           " << nJucX <<"     vs       "<<nJuc0<<"\n\n";
			AfisareMatrice(M);
			cout << "\n\n";
			AfisareScor(mJ, scorJ1, scorJ2, nScorJ1, nScorJ2);
			cout << "\n";
			if (ord == 'X')
			{
				if (strcmp(nJucX, nJuc1) == 0)
				{
					cout << " -> Randul lui " << nJucX<<": ";
				err4:
					cin >> t;
					if (EsteValid(t)){
						if (strchr("ABCabc", t[1]))
						{
							if (strchr("abc", t[1])) t[1] -= 32;
							char aux = t[1];
							t[1] = t[0];
							t[0] = aux;
						}
					}
					else
					{
						rlutil::setColor(11); cout << "EROARE!  ";
						rlutil::resetColor(); cout << "Introduceti corect comanda.\n";
						goto err4;
					}
					if (strchr("abc", t[0])) t[0] -= 32;
					j = t[0] - 65;
					i = t[1] - 49;
					if (M[i][j] != ' ') {
						rlutil::setColor(11); cout << "EROARE!  ";
						rlutil::resetColor(); cout << "Casuta nu este libera.\n";
						goto err4;
					}
					M[i][j] = 'X';
					ord = '0';
				}
				else if (strcmp(nJucX, "Computer") == 0)
				{
					Miscare_Computer(M, 1, k, 'X');
					ord = '0';
				}
			}
			else
			{
				if (strcmp(nJuc0, nJuc1) == 0)
				{
					cout << " -> Randul lui " << nJuc0 << ": ";;
				err4a:
					cin >> t;
					if (EsteValid(t)){
						if (strchr("ABCabc", t[1]))
						{
							if (strchr("abc", t[1])) t[1] -= 32;
							char aux = t[1];
							t[1] = t[0];
							t[0] = aux;
						}
					}
					else
					{
						rlutil::setColor(11); cout << "EROARE!  ";
						rlutil::resetColor(); cout << "Introduceti corect comanda.\n";
						goto err4a;
					}
					if (strchr("abc", t[0])) t[0] -= 32;
					j = t[0] - 65;
					i = t[1] - 49;
					if (M[i][j] != ' ') {
						rlutil::setColor(11); cout << "EROARE!  ";
						rlutil::resetColor(); cout << "Casuta nu este libera.\n";
						goto err4a;
					}
					M[i][j] = '0';
					ord = 'X';
				}
				else if (strcmp(nJuc0, "Computer") == 0)
				{
					Miscare_Computer(M, 1, k, '0');
					ord = 'X';
				}
			}
			system("CLS");
			cout << "\n";
			AfisareTitlu();
			//cout << "           " << nJucX << "     vs       " << nJuc0 << "\n\n";
			AfisareMatrice(M);
			cout << '\n';
			sf = false;
			if (Castigat(M, 'X'))
			{
				sf = true;
				cout << "            Runda castigata de " << nJucX << "!\n";
				if (strcmp(nJucX, nJuc1) == 0) scorJ1++;
				else if (strcmp(nJucX, "Computer") == 0) scorJ2++;
				mJ++;
			}
			else if (Castigat(M, '0'))
			{
				sf = true;
				cout << "            Runda castigata de " << nJuc0 << "!\n";
				if (strcmp(nJuc0, nJuc1) == 0) scorJ1++;
				else if (strcmp(nJuc0, "Computer") == 0) scorJ2++;
				mJ++;
			}
			else if (Egalitate(M))
			{
				sf = true;
				cout << "            Runda aceasta s-a terminat la egalitate!\n";
				mJ++;
			}
			cout << "\n";
			AfisareScor(mJ, scorJ1, scorJ2, nScorJ1, nScorJ2);
			cout << "\n";
			if (sf)
			{
				cout << "Doriti sa jucati o alta runda ? (1-DA / 0-NU)\n";
			err5:
				cin >> cmd;
				if (cmd == 1)
				{
					GolireMatrice(M);
					ord = 'X';
					goto runda_noua;
				}
				else if (cmd == 0)
				{
					GolireMatrice(M);
					goto start;
				}
				else
				{
					rlutil::setColor(11); cout << "EROARE!  ";
					rlutil::resetColor(); cout << "Introduceti corect comanda.\n";
					goto err5;
				}
			}
			goto jump2;
		}
		else if (cmd2 == 2)
		{

		runda_noua3:
			srand(time(NULL));
			int rnd = rand() % 2; // 0 - Juc / 1 - Comp (GREU)
			if (rnd == 0)
			{
				strcpy_s(nJucX, nJuc1);
				strcpy_s(nScorJ1, nJuc1);
				strcat_s(nScorJ1, " (X)");
				strcpy_s(nJuc0, "Computer");
				strcpy_s(nScorJ2, "Computer (0)");
			}
			else
			{
				strcpy_s(nJucX, "Computer");
				strcpy_s(nScorJ2, "Computer (X)");
				strcpy_s(nJuc0, nJuc1);
				strcpy_s(nScorJ1, nJuc1);
				strcat_s(nScorJ1, " (0)");
			}

		jump3:
			system("CLS");
			cout << "\n";
			AfisareTitlu();
			//cout << "         Computer (X)       vs       Jucator (O)\n\n";
			AfisareMatrice(M);
			cout << "\n\n";
			AfisareScor(mJ, scorJ1, scorJ2, nScorJ1, nScorJ2);
			cout << "\n";
			if (ord == 'X')
			{
				if (strcmp(nJucX, nJuc1) == 0)
				{
					cout << " -> Randul lui "<<nJuc1<<":\n";
				err6:
					cin >> t;
					if (EsteValid(t)){
						if (strchr("ABCabc", t[1]))
						{
							if (strchr("abc", t[1])) t[1] -= 32;
							char aux = t[1];
							t[1] = t[0];
							t[0] = aux;
						}
					}
					else
					{
						rlutil::setColor(11); cout << "EROARE!  ";
						rlutil::resetColor(); cout << "Introduceti corect comanda.\n";
						goto err6;
					}
					if (strchr("abc", t[0])) t[0] -= 32;
					j = t[0] - 65;
					i = t[1] - 49;
					if (M[i][j] != ' ') {
						rlutil::setColor(11); cout << "EROARE!  ";
						rlutil::resetColor(); cout << "Casuta nu este libera.\n";
						goto err6;
					}
					M[i][j] = 'X';
					ord = '0';
				}
				else if (strcmp(nJucX, "Computer") == 0)
				{
					Sleep(1250);
					Miscare_Computer(M, 2, k, 'X');
					ord = '0';
				}
			}
			else
			{
				if (strcmp(nJuc0, nJuc1) == 0)
				{
					cout << "Randul lui " << nJuc0 << ":\n";
				err7:
					cin >> t;
					if (EsteValid(t)){
						if (strchr("ABCabc", t[1]))
						{
							if (strchr("abc", t[1])) t[1] -= 32;
							char aux = t[1];
							t[1] = t[0];
							t[0] = aux;
						}
					}
					else
					{
						rlutil::setColor(11); cout << "EROARE!  ";
						rlutil::resetColor(); cout << "Introduceti corect comanda.\n";
						goto err7;
					}
					if (strchr("abc", t[0])) t[0] -= 32;
					j = t[0] - 65;
					i = t[1] - 49;
					if (M[i][j] != ' ') {
						rlutil::setColor(11); cout << "EROARE!  ";
						rlutil::resetColor(); cout << "Casuta nu este libera.\n";
						goto err7;
					}
					M[i][j] = '0';
					ord = 'X';
					k++;
				}
				else if (strcmp(nJuc0, "Computer") == 0)
				{
					Sleep(1250);
					Miscare_Computer(M, 2, k, '0');
					ord = 'X';
					k++;
				}
			}
			system("CLS");
			cout << "\n";
			AfisareTitlu();
			//cout << "         Computer (X)       vs       Jucator (O)\n\n";
			AfisareMatrice(M);
			cout << '\n';
			sf = false;
			if (Castigat(M, 'X'))
			{
				sf = true;
				cout << "            Runda castigata de " << nJucX << "!\n";
				if (strcmp(nJucX, nJuc1) == 0) scorJ1++;
				else if (strcmp(nJucX, "Computer") == 0) scorJ2++;
				mJ++;
			}
			else if (Castigat(M, '0'))
			{
				sf = true;
				cout << "            Runda castigata de " << nJuc0 << "!\n";
				if (strcmp(nJuc0, nJuc1) == 0) scorJ1++;
				else if (strcmp(nJuc0, "Computer") == 0) scorJ2++;
				mJ++;
			}
			else if (Egalitate(M))
			{
				sf = true;
				cout << "            Runda aceasta s-a terminat la egalitate!\n";
				mJ++;
			}
			cout << "\n";
			AfisareScor(mJ, scorJ1, scorJ2, nScorJ1, nScorJ2);
			cout << "\n";
			if (sf)
			{
				cout << "Doriti sa jucati o alta runda ? (1-DA / 0-NU)\n";
			err8:
				cin >> cmd;
				if (cmd == 1)
				{
					GolireMatrice(M);
					ord = 'X';
					k = 1;
					goto runda_noua3;
				}
				else if (cmd == 0)
				{
					GolireMatrice(M);
					goto start;
				}
				else
				{
					rlutil::setColor(11); cout << "EROARE!  ";
					rlutil::resetColor(); cout << "Introduceti corect comanda.\n";
					goto err8;
				}

			}
			goto jump3;
		}

	}
	if (cmd == 2) // Player vs Player
	{
		system("CLS");
		cout << "\n";
		AfisareTitlu();
		rlutil::setColor(10); cout << "            Introduceti numele jucatorului 1:\n";
		rlutil::resetColor();
		re1: cout << "                     "; cin >> nJuc1;
		if (strlen(nJuc1) > LUNG_NUME)
		{
			rlutil::setColor(11); cout << "\n\n        EROARE!  ";
			rlutil::resetColor(); cout << "Lungimea maxima a numelui este de 13 caractere.\n";
			goto re1;
		}
		rlutil::setColor(10); cout << "            Introduceti numele jucatorului 2:\n";
		rlutil::resetColor();
		re2: cout << "                     "; cin >> nJuc2;
		if (strlen(nJuc2) > LUNG_NUME )
		{
			rlutil::setColor(11); cout << "\n\n        EROARE!  ";
			rlutil::resetColor(); cout << "Lungimea maxima a numelui este de 13 caractere.\n";
			goto re2;
		}


	runda_noua2:
		srand(time(NULL));
		int rnd = rand() % 2; // 0 - Juc1 / 1 - Juc2
		if (rnd == 0)
		{
			strcpy_s(nJucX, nJuc1);
			strcpy_s(nScorJ1, nJuc1);
			strcat_s(nScorJ1, " (X)");
			strcpy_s(nJuc0, nJuc2);
			strcpy_s(nScorJ2, nJuc2);
			strcat_s(nScorJ2, " (0)");
		}
		else
		{
			strcpy_s(nJucX, nJuc2);
			strcpy_s(nScorJ2, nJuc2);
			strcat_s(nScorJ2, " (X)");
			strcpy_s(nJuc0, nJuc1);
			strcpy_s(nScorJ1, nJuc1);
			strcat_s(nScorJ1, " (0)");
		}

		jump:
		system("CLS");
		cout << "\n";
		AfisareTitlu();
	//	cout << "          "<<nJuc1<<"        vs        "<<nJuc2<<"\n\n";
		AfisareMatrice(M);
		cout << "\n\n";
		AfisareScor(mJ, scorJ1, scorJ2, nScorJ1, nScorJ2);
		cout << "\n";

		if (ord == 'X')
		{
			
			cout << " -> Randul lui "<<nJucX<<":\n";
		err:
			cin >> t;
			if (EsteValid(t)){
				if (strchr("ABCabc", t[1]))
				{
					if (strchr("abc", t[1])) t[1] -= 32;
					char aux = t[1];
					t[1] = t[0];
					t[0] = aux;
				}
			}
			else
			{
				rlutil::setColor(11); cout << "EROARE!  ";
				rlutil::resetColor(); cout << "Introduceti corect comanda.\n";
				goto err;
			}
			if (strchr("abc", t[0])) t[0] -= 32;
			j = t[0] - 65;
			i = t[1] - 49;
			if (M[i][j] != ' ') {
				rlutil::setColor(11); cout << "EROARE!  ";
				rlutil::resetColor(); cout << "Casuta nu este libera.\n";
				goto err;
			}
			M[i][j] = 'X';
			ord = '0';
		}
		else
		{
			cout << " -> Randul lui "<<nJuc0<<":\n";
		err2:
			cin >> t;
			if (EsteValid(t)){
				if (strchr("ABCabc", t[1]))
				{
					if (strchr("abc", t[1])) t[1] -= 32;
					char aux = t[1];
					t[1] = t[0];
					t[0] = aux;
				}
			}
			else
			{
				rlutil::setColor(11); cout << "EROARE!  ";
				rlutil::resetColor(); cout << "Introduceti corect comanda.\n";
				goto err2;
			}
			if (strchr("abc", t[0])) t[0] -= 32;
			j = t[0] - 65;
			i = t[1] - 49;
			if (M[i][j] != ' ') {
				rlutil::setColor(11); cout << "EROARE!  ";
				rlutil::resetColor(); cout << "Casuta nu este libera.\n";
				goto err2;
			}
			M[i][j] = '0';
			ord = 'X';
		}

		system("CLS");
		cout << "\n";
		AfisareTitlu();
		//cout << "          " << nJuc1 << "        vs        " << nJuc2 << "\n\n";
		AfisareMatrice(M);
		cout << '\n';
		sf = false;
		if (Castigat(M, 'X'))
		{
			sf = true;
			cout << "            Runda castigata de " << nJucX << "!\n";
			if (strcmp(nJucX, nJuc1) == 0) scorJ1++;
			else if (strcmp(nJucX, nJuc2) == 0) scorJ2++;
			mJ++;
		}
		else if (Castigat(M, '0'))
		{
			sf = true;
			cout << "            Runda castigata de " << nJuc0 << "!\n";
			if (strcmp(nJuc0, nJuc1) == 0) scorJ1++;
			else if (strcmp(nJuc0, nJuc2) == 0) scorJ2++;
			mJ++;
		}
		else if (Egalitate(M))
		{
			sf = true;
			cout << "            Runda aceasta s-a terminat la egalitate!\n";
			mJ++;
		}
		cout << "\n";
		AfisareScor(mJ, scorJ1, scorJ2, nScorJ1, nScorJ2);
		cout << "\n";
		if (sf)
		{
			cout << "Doriti sa jucati o alta runda ? (1-DA / 0-NU)\n";
		err3:
			cin >> cmd;
			if (cmd == 1)
			{
				GolireMatrice(M);
				ord = 'X';
				goto runda_noua2;
			}
			else if (cmd == 0)
			{
				GolireMatrice(M);
				goto start;
			}
			else
			{
				rlutil::setColor(11); cout << "EROARE!  ";
				rlutil::resetColor(); cout << "Introduceti corect comanda.\n";
				goto err3;
			}

		}
		goto jump;
	}
	else if (cmd == 3) goto exit;
	else goto p;
	system("pause");
	exit:
	return 0;
}

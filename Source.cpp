#include<iostream>
#include<conio.h>
#include<Windows.h>

using namespace std;
using namespace System;

const int PIEZAS_POR_JUGADOR = 9;//cantidad de fichas por jugador 
const int TABLERO = 3;           //contantes 
const int DEFAULT = 15;          //contantes 
const int JUGADOR_1 = 1;         //contantes 
const int JUGADOR_2 = 7;         //contantes 

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//

void Nombre_Menu()
{
	SetConsoleTextAttribute(hConsole, 3);
	cout << "\n";
	cout << "\n";
	cout << "	            ###        ###   #########   ##########     ##########      #######     ########" << endl;
	cout << "	            ####     #####  ###########  ############   ############    #######    ###########" << endl;
	cout << "	            #####   ###### ####     #### ####     ####  ####     ####     ###     ####     ####" << endl;
	cout << "	            ###### ####### ####     #### ####     ####  ####     ####     ###     ####" << endl;
	cout << "	            #### #### #### ####     #### ############   ############      ###      #########" << endl;
	cout << "	            ####  ##  #### ####     #### ####   ####    ####   ####       ###            ######" << endl;
	cout << "	            ####      #### ####     #### ####    ####   ####    ####      ###     ####    #####" << endl;
	cout << "	            ####      ####  ###########  ####     ####  ####     ####   #######    ###########" << endl;
	cout << "	            ####      ####   #########   ####     ####  ####     ####   #######     #########" << endl;
	cout << "" << endl;
	SetConsoleTextAttribute(hConsole, 5);
	cout << "				   O-----------O-----------O" << endl;
	cout << "				   |           |           |" << endl;
	cout << "				   |   O-------O-------O   |" << endl;
	cout << "				   |   |       |       |   |" << endl;
	cout << "				   |   |   O---O---O   |   |       1. -REGLAS DEL JUEGO " << endl;
	cout << "				   |   |   |       |   |   |       2. -JUGAR " << endl;
	cout << "				   |   |   |       |   |   |       3. -SALIR " << endl;
	cout << "				   O---O---O       O---O---O      " << endl;
	cout << "				   |   |   |       |   |   |      " << endl;
	cout << "				   |   |   |       |   |   |" << endl;
	cout << "				   |   |   O---O---O   |   |" << endl;
	cout << "				   |   |       |       |   |" << endl;
	cout << "				   |   O-------O-------O   |" << endl;
	cout << "				   |           |           |" << endl;
	cout << "				   O-----------O-----------O" << endl;
}
void logo() {

	int Mlogo[14][16] =
	{
		{0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0 },
		{0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0 },
		{0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0 },
		{0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0 },
		{0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0 },
		{0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0 },
		{0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0 },
		{0,0,0,1,1,0,1,0,1,0,1,0,1,1,0,0 },
		{0,0,1,1,0,1,0,1,0,1,0,1,0,1,1,0 },
		{0,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1 },
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0 },
		{0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0 },
		{0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0 },
		{0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0 } };
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (Mlogo[i][j] == 0)
			{
				Console::BackgroundColor = ConsoleColor::Black;
				cout << " ";
			}
			if (Mlogo[i][j] == 1) {
				Console::BackgroundColor = ConsoleColor::Yellow;
				cout << " ";
			}
		}
		cout << "\n";
	}
}
void Trofeo() {

	int Mtrofeo[18][28] = {

	 { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	 { 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
	 { 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
	 { 0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0 },
	 { 0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0 },
	 { 0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0 },
	 { 0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0 },
	 { 0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0 },
	 { 0,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0 },
	 { 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 },
	 { 0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
	 { 0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
	 { 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	 { 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	 { 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	 { 0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0 },
	 { 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 } };

	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			if (Mtrofeo[i][j] == 0)
			{
				Console::BackgroundColor = ConsoleColor::Black;
				cout << " ";
			}
			if (Mtrofeo[i][j] == 1) {
				Console::BackgroundColor = ConsoleColor::Yellow;
				cout << " ";
			}
		}
		cout << "\n";
	}
}

void reglas()
{
	system("cls");
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t \n\n\t\t�Bienvenidos jugadores!" << endl;
	cout << "\t " << endl;
	cout << "\t Si usted quiere jugar este juego debe saber lo siguiente:" << endl;
	cout << "\t " << endl;
	cout << "\t El juego esta conformado por las difirentes fases las cuales son de colo fases de colocaccion" << endl;
	cout << "\t	fase de movimiento y fase de vuelo.Ahora vamos con las reglas del juego : " << endl;
	cout << "\t Tambien esta conformado por colores de cada jugador, el primer jugador que comienza" << endl;
	cout << "\tva a ser del color azul con figura de diamante y el segundo jugador va a ser de color blanco con figura de corazon" << endl;
	cout << "\t " << endl;
	cout << "\t 1.- Al empezar a jugar ustedes tienen un tablero vacio, lo cual ustedes deben colocar una ficha" << endl;
	cout << "\t	turno por turno, hasta que coloque 9 fichas de cada jugador" << endl;
	cout << "\t 2.- Si logra uno de los jugadores consiguir hacer una raya de 3 fichas ya sea horizontal o vertical" << endl;
	cout << "\tse le quitara una ficha del contricante.Esto lo puedes hacer en las diferentes fases del juego" << endl;
	cout << "\t 3.- Si un jugador consigue hacer una raya de 3, y su contricante ya tenga otra raya de " << endl;
	cout << "\t 4.- Si logra conseguir una raya de 3 durante la fase de colocaci�n puede quitar la ficha de su " << endl;
	cout << "\tcontricante.Si no es asi, mire la regla n�2." << endl;
	cout << "\t 5.- Durante la fase de colocaci�n, ni usted, ni el contricante podran desplazarse por el tablero" << endl;
	cout << "\thasta que las todas las fichas esten colocadas." << endl;
	cout << "\t 6.- Si uno de los jugadores tengan 2 fichas el juego terminara." << endl;
	cout << "\t Disfrute del maravilloso juego �Morries!(o tambien llamado al espanol el juego del molino >:))" << endl;
	cout << "\t \nPulsa cualquier tecla para volver...";
}
string ingresarJugador(int i) {
	string c;
	cout << "\n=======================================";
	cout << "\n Ingresar Nombre del jugador " << i << ": ";
	cin >> c;
	cout << "\n=======================================";
	return c;
}

char morris_tab[][52]{
	" A --------------------- B --------------------- C ",
	" |                       |                       | ",
	" |                       |                       | ",
	" |                       |                       | ",
	" |       D ------------- E ------------- F       | ",
	" |       |               |               |       | ",
	" |       |               |               |       | ",
	" |       |               |               |       | ",
	" |       |       G ----- H ----- I       |       | ",
	" |       |       |               |       |       | ",
	" |       |       |               |       |       | ",
	" |       |       |               |       |       | ",
	" J ----- K ----- L               M ----- N ----- O ",
	" |       |       |               |       |       | ",
	" |       |       |               |       |       | ",
	" |       |       |               |       |       | ",
	" |       |       P ----- Q ----- R       |       | ",
	" |       |               |               |       | ",
	" |       |               |               |       | ",
	" |       |               |               |       | ",
	" |       S ------------- T ------------- U       | ",
	" |                       |                       | ",
	" |                       |                       | ",
	" |                       |                       | ",
	" V --------------------- W --------------------- X ",
};

void setCColor(int color) {
	static HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct PiezaJugador {
	int color;
	char letraEn;
	char valor;
};

int pieza_en_casilla(PiezaJugador* P, char l) {
	for (int i = 0; i < PIEZAS_POR_JUGADOR; i++) {
		if (P[i].letraEn == l) return i;
	}
	return -1;
}

void mostrarJuego(PiezaJugador* P1, PiezaJugador* P2) {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 51; j++) {
			gotoxy(30 + j, i);
			if (morris_tab[i][j] >= 'A' && morris_tab[i][j] <= 'X') {
				if (pieza_en_casilla(P1, morris_tab[i][j]) > -1) {
					setCColor(P1[pieza_en_casilla(P1, morris_tab[i][j])].color);
					cout << P1[pieza_en_casilla(P1, morris_tab[i][j])].valor;
				}
				else if (pieza_en_casilla(P2, morris_tab[i][j]) > -1) {
					setCColor(P2[pieza_en_casilla(P2, morris_tab[i][j])].color);
					cout << P2[pieza_en_casilla(P2, morris_tab[i][j])].valor;
				}
				else {
					setCColor(TABLERO);
					cout << morris_tab[i][j];
				}
			}
			else {
				setCColor(TABLERO);
				cout << morris_tab[i][j];
			}
		}
	}
}

void limpiarJuego() {
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 51; j++) {
			gotoxy(j, i);
			cout << " ";
		}
	}
}

bool inStr(char posicion_final, string lets) {
	for (int i = 0; i < lets.size(); i++) {
		if (posicion_final == lets[i]) return true;
	}
	return false;
}
bool adyacentes(char posicion_inicial, char posicion_final) {
	if (posicion_inicial == 'A')      return inStr(posicion_final, "BJ");
	else if (posicion_inicial == 'B') return inStr(posicion_final, "ACE");
	else if (posicion_inicial == 'C') return inStr(posicion_final, "BO");
	else if (posicion_inicial == 'D') return inStr(posicion_final, "EK");
	else if (posicion_inicial == 'E') return inStr(posicion_final, "BDFH");
	else if (posicion_inicial == 'F') return inStr(posicion_final, "EN");
	else if (posicion_inicial == 'G') return inStr(posicion_final, "HL");
	else if (posicion_inicial == 'H') return inStr(posicion_final, "EGI");
	else if (posicion_inicial == 'I') return inStr(posicion_final, "HM");
	else if (posicion_inicial == 'J') return inStr(posicion_final, "AVK");
	else if (posicion_inicial == 'K') return inStr(posicion_final, "DSJL");
	else if (posicion_inicial == 'L') return inStr(posicion_final, "GPK");
	else if (posicion_inicial == 'M') return inStr(posicion_final, "IRN");
	else if (posicion_inicial == 'N') return inStr(posicion_final, "FUMO");
	else if (posicion_inicial == 'O') return inStr(posicion_final, "CXN");
	else if (posicion_inicial == 'P') return inStr(posicion_final, "LQ");
	else if (posicion_inicial == 'Q') return inStr(posicion_final, "PRT");
	else if (posicion_inicial == 'R') return inStr(posicion_final, "MQ");
	else if (posicion_inicial == 'S') return inStr(posicion_final, "KT");
	else if (posicion_inicial == 'T') return inStr(posicion_final, "QSUW");
	else if (posicion_inicial == 'U') return inStr(posicion_final, "NT");
	else if (posicion_inicial == 'V') return inStr(posicion_final, "JW");
	else if (posicion_inicial == 'W') return inStr(posicion_final, "VTX");
	else if (posicion_inicial == 'X') return inStr(posicion_final, "WO");

	return false;
}

bool finalJuego(PiezaJugador* P, int actual) {
	int cont = 0;
	for (int i = 0; i < PIEZAS_POR_JUGADOR; i++) {
		if (P[i].letraEn != 'Y') cont++;
	}

	if (cont == 2) {
		gotoxy(0, 7);
		cout << "GANO EL JUGADOR " << actual + 1 << "! MAS SUERTE PARA LA PROXIMA JUGADOR " << (actual + 2) % 2 << "             ";
		system("pause>t");
		return true;
	}

	return false;
}

bool trio(PiezaJugador* P, string cad) {
	for (int i = 0; i < cad.size(); i++) {
		if (pieza_en_casilla(P, cad[i]) == -1) return false;
	}
	return true;
}

bool matchTrio(PiezaJugador* P) {
	if (trio(P, "AJV")) return true;
	if (trio(P, "DKS")) return true;
	if (trio(P, "GLP")) return true;
	if (trio(P, "BEH")) return true;
	if (trio(P, "QTW")) return true;
	if (trio(P, "IMR")) return true;
	if (trio(P, "FNU")) return true;
	if (trio(P, "COX")) return true;
	if (trio(P, "ABC")) return true;
	if (trio(P, "DEF")) return true;
	if (trio(P, "GHI")) return true;
	if (trio(P, "JKL")) return true;
	if (trio(P, "MNO")) return true;
	if (trio(P, "PQR")) return true;
	if (trio(P, "STU")) return true;
	if (trio(P, "VXW")) return true;

	return false;
}

void primeraEtapa(PiezaJugador* act, PiezaJugador* enem, int ind) {
	bool seguir = true;
	do {
		char posicion_final;
		setCColor(act[0].color);

		gotoxy(0, 27);
		cout << "EN QUE POSICION DESEAS COLOCAR? ";
		cin >> posicion_final;
		gotoxy(0, 27);
		cout << "                                              ";

		int fin_yo = pieza_en_casilla(act, posicion_final);
		int fin_otro = pieza_en_casilla(enem, posicion_final);

		if (fin_yo = -1 && fin_otro == -1) {
			act[ind].letraEn = posicion_final;
			seguir = false;
		}
		else {
			gotoxy(0, 27);
			cout << "ELIGE UNA POSICION CORRECTA Y VACIA!!!!";
			system("pause>t");
		}
	} while (seguir);
}

void segundaEtapa(PiezaJugador* act, PiezaJugador* enem) {
	bool seguir = true;
	do {
		char posicion_inicial, posicion_final;
		setCColor(act[0].color);
		gotoxy(0, 27);
		cout << "EN QUE CASILLA ESTA TU FICHA??? ";
		cin >> posicion_inicial;
		gotoxy(0, 27);
		cout << "                                              ";

		gotoxy(0, 27);
		cout << "A QUE CASILLA LA QUIERES MOVER??? ";
		cin >> posicion_final;
		gotoxy(0, 27);
		cout << "                                              ";

		int inicial_yo = pieza_en_casilla(act, posicion_inicial);
		int fin_yo = pieza_en_casilla(act, posicion_final);
		int fin_otro = pieza_en_casilla(enem, posicion_final);

		if (adyacentes(posicion_inicial, posicion_final) && inicial_yo != -1 && fin_yo == -1 && fin_otro == -1) {
			act[inicial_yo].letraEn = posicion_final;
			seguir = false;
		}
		else {
			gotoxy(0, 27);
			cout << "LA POSICION INDICADA ES INCORRECTA";
			system("pause>t");
		}
	} while (seguir);

	if (matchTrio(act)) {
		limpiarJuego();
		mostrarJuego(act, enem);

		setCColor(DEFAULT);
		gotoxy(0, 27);
		seguir = true;
		cout << "FORMASTE UN TRIO, ELIGE LA FICHA DEL JUGADOR A COMER";
		system("pause>t");
		do {
			char posicion_final;
			setCColor(act[0].color);
			gotoxy(0, 27);
			cout << "                                                           ";
			gotoxy(0, 27);
			cout << "FICHA DEL OPONENTE:  ";
			cin >> posicion_final;
			gotoxy(0, 27);
			cout << "                                              ";

			int indEne = pieza_en_casilla(enem, posicion_final);

			if (indEne > -1) {
				enem[indEne].letraEn = 'Y';
				seguir = false;
			}
			else {
				gotoxy(0, 27);
				cout << "NO ES UNA FICHA CORRECTA";
				system("pause>t");
			}
		} while (seguir);
	}
}

void colocarFichas(PiezaJugador* primerJug, PiezaJugador* segundoJug,string jugs[]) {
	for (int i = 0; i < 2 * PIEZAS_POR_JUGADOR; i++) {
		limpiarJuego();
		mostrarJuego(primerJug, segundoJug);
		gotoxy(0, 26);
		cout << "Turno de " << jugs[i%2] << endl;

		if (i % 2 == 0) primeraEtapa(primerJug, segundoJug, i / 2);
		else primeraEtapa(segundoJug, primerJug, i / 2);
	}
}

void crearFichas(PiezaJugador* jugador, int COLOR, char valor, char posicion) {
	for (int i = 0; i < PIEZAS_POR_JUGADOR; i++) {
		jugador[i].color = COLOR;
		jugador[i].valor = valor;
		jugador[i].letraEn = posicion;
	}
}
int main()
{
	PiezaJugador* primerJug = new PiezaJugador[PIEZAS_POR_JUGADOR];
	PiezaJugador* segundoJug = new PiezaJugador[PIEZAS_POR_JUGADOR];

	crearFichas(primerJug, JUGADOR_1, char(4), 'Y');
	crearFichas(segundoJug, JUGADOR_2, char(3), 'Y');
	int* opcion = new int;
	do {
		system("cls");
		Nombre_Menu();
		do {

			SetConsoleTextAttribute(hConsole, 6);
			cout << "\n              Elegir opcion: ";
			cin >> *opcion;

		} while (*opcion < 1 || *opcion>4);

		switch (*opcion) {
		case 1: {
			reglas();
		}
			  break;
		case 2: {

			system("cls");
			string jugadores[] = { ingresarJugador(1),ingresarJugador(2) };
			//PRIMERA ETAPA , POSICIONANDO FICHAS
			setCColor(DEFAULT);
			gotoxy(0, 27);
			cout << "                                                          ";

			colocarFichas(primerJug, segundoJug, jugadores);

			//SEGUNDA ETAPA , JUGANDO!!!
			setCColor(DEFAULT);
			gotoxy(0, 27);
			cout << "JUGADORES SE PUEDEN MOVER, QUE GANE EL MEJOR";
			system("pause>t");
			gotoxy(0, 27);
			cout << "                                                ";

			int actual = 0;
			while (1) {
				limpiarJuego();
				mostrarJuego(primerJug, segundoJug);
				gotoxy(0, 26);
				cout << "Turno de " << jugadores[actual] << "                  " << endl;

				if (actual % 2 == 0) {
					segundaEtapa(primerJug, segundoJug);
					if (finalJuego(segundoJug, actual)) break;
				}
				else {
					segundaEtapa(segundoJug, primerJug);
					if (finalJuego(segundoJug, actual)) break;
				}

				actual++;
			}
		}
			  break;
		case 3: 
			  break;
		}
		_getch();
	} while (*opcion != 4);
	cout << "Gracias .......";
	_getch();
	return(0);
}
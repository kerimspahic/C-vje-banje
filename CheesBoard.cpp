#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
using namespace std;

const int Tiles = 9;

void chessBoard (int board[] [Tiles]){
	char horiz = 'A';
	char vert = '1';
	for (int i=0; i<Tiles; i++){
		for (int j=0; j<Tiles; j++){
			if ((i==1 && j==1) || (i==8 && j==1) || (i==1 && j==8) || (i==8 && j==8)){
				board [i] [j] = 'R';
			}
			else if ((i==1 && j==2) || (i==1 && j==7) || (i==8 && j==2) || (i==8 && j==7)){
				board [i] [j] = 'N';
			}
			else if ((i==1 && j==3) || (i==1 && j==6) || (i==8 && j==3) || (i==8 && j==6)){
				board [i] [j] = 'B';
			}
			else if ((i==1 && j==4) || (i==8 && j==5)){
				board [i] [j] = 'Q';
			}
			else if ((i==1 && j==5) || (i==8 && j==4)){
				board [i] [j] = 'K';
			}
			else if ((i==2 && j!=0)|| (i==7 && j!=0)){
				board [i] [j] = 'P';
			}
			else if (i==0  && j!=0){
				board [i] [j] = char(horiz);
				board [j] [i] = char(vert);
				horiz++;
				vert++;
				

			} 
			else{
				board [i] [j] = ' ';
			}
		}
	}

}

void drawBoard (int board[] [Tiles]){
	cout<<endl;
	for (int i=0; i<Tiles; i++){
		for (int j=0; j<Tiles; j++){
			cout << setw(3) << char(board[i] [j]);
		}
		cout<<endl;
	}
	cout<<endl;
}

void movePiece (int board[] [Tiles]){
	char hKoor1,hKoor2;
	int vKoor1,vKoor2;
	cout<<"Koju figuru zelis pomjeriti :"<<endl;
	cout<<"Horizontala: ";
	cin>>hKoor1;
	cout<<"Vertikala: ";
	cin>>vKoor1;
	cout<<"Gdje figuru zelis pomjeriti :"<<endl;
	cout<<"Horizontala: ";
	cin>>hKoor2;
	cout<<"Vertikala: ";
	cin>>vKoor2;
	hKoor1-=64;
	hKoor2-=64;
	board[vKoor2] [hKoor2] = board[vKoor1] [hKoor1];
	board[vKoor1] [hKoor1] = ' ';
}


int main ()
{

	int Board[Tiles] [Tiles];
	char actions;
	
	chessBoard(Board);
	drawBoard(Board);
	cout<<endl;
	do {
	cout<<endl<<"Unesi jednan od sljedecih simbola: "<<endl;
	cout<<"[A]-uraditi potez"<<endl;
	cout<<"[R]-restartovati plocu"<<endl;
	cout<<"[E]-izlaz"<<endl;
	cin>>actions;
	
	switch (actions)
	{
	case ('A'):{
		movePiece(Board);
		drawBoard(Board);
		break;
	}
	case ('R'):{
		chessBoard(Board);
		drawBoard(Board);		
		break;
	}
	case ('E'):{
		break;
	}
	default :{
		cout<<"Uneseni simbol nije vallidan ili je malo slovo."<<endl;
		break;
	}
	}
	}while (actions !='E');

	
	return 0;
}



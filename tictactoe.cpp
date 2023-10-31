#include<iostream>
using namespace std;
class board{
	public:
   	virtual void printBoard()=0;
   	virtual void Input()=0;
   	virtual int addMark()=0;
   	virtual int check()=0;
   	virtual void Play()=0;
   	virtual int getResult()=0;
   	virtual void Result(int)=0;
   	virtual void Reset()=0;
};
class game:public board{
	private:
		char board[3][3];
		int turn,win,input;
   	    char mark;
  public:
  game(){
  	Reset();
   	win=0;
	input=0;
	turn=1;
	mark='O';
 }
 void Reset(){
 	char a='1';
  	int i,j;
 	for(i=0;i<3;i++){
  		for(j=0;j<3;j++){
  			board[i][j]=a;
  			a++;
		  }
    }
 }
  void printBoard(){
  	cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" "<<endl;
  	cout<<"-----------"<<endl;
  	cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" "<<endl;
  	cout<<"-----------"<<endl;
  	cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" "<<endl<<endl;
	  	if(turn){
   	 		cout<<"0-Player 1 (1-9): ";
			}
		else{
			cout<<"1-Player 2 (1-9): ";
		}
	  }
   	 void Input(){
		cin>>input;
		while(input<1 || input>9){
			cout<<endl<<"Wrong Input. Please re-enter: ";
			cin>>input;
		}
		if(turn){
			mark='O';
		}
		else{
			mark='X';
		}
		}
    int addMark(){
	int i,j,k=1;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++){
			if(k==input){
				if(board[i][j]!='O' && board[i][j]!='X')
				{
					board[i][j]=mark;
					return 1;
				}
				else{
					return 0;
				}
			}
			k++;
		}
	}
		}
   	 int check(){
   	 	if(board[0][0]==mark && board[0][1]==mark && board[0][2]==mark){
   	 		win=1;
		}
		if(board[1][0]==mark && board[1][1]==mark && board[1][2]==mark){
   	 		win=1;
		}
		if(board[2][0]==mark && board[2][1]==mark && board[2][2]==mark){
   	 		win=1;
		}
		if(board[0][0]==mark && board[1][0]==mark && board[2][0]==mark){
   	 		win=1;
		}
		if(board[0][1]==mark && board[1][1]==mark && board[2][1]==mark){
   	 		win=1;
		}
		if(board[0][2]==mark && board[1][2]==mark && board[2][2]==mark){
   	 		win=1;
		}
		if(board[0][0]==mark && board[1][1]==mark && board[2][2]==mark){
   	 		win=1;
		}
		if(board[0][2]==mark && board[1][1]==mark && board[2][0]==mark){
   	 		win=1;
		}
		return win;
		}
   	 void Play(){
   	 	int i;
		for(i=0;i<9;i++)
		{
			system("cls");
			printBoard();
			Input();
			int validInput=addMark();
			if(!validInput){
				cout<<"Invalid Input";
				i--;
				continue;
			}
			Result(i);
			if(win!=0){
				break;
			}
			turn=!turn;
		}
	}
   	 int getResult(){
   	 	return win;
		}
   	 void Result(int i){
   	 	if(check()){
   	 		system("cls");
   	 		printBoard();
   	 		if(turn){
   	 			cout<<endl<<"*****  Player 1  won  *****"<<endl;
   	 			win=1;
   	 			return;
				}
			else{
				cout<<endl<<"*****  Player 2  won  *****"<<endl;
   	 			win=2;
   	 			return;
			}
			}
			if(i==8){
				system("cls");
				printBoard();
				cout<<endl<<"***** Match tied *****"<<endl;
   	 			win=3;
   	 			return;
			}
			return;
		}
};
int main(){
	char replay;
	do{
		board *ptr;
		ptr=new game;
	ptr->Play();
	ptr->Reset();
	cout<<"Do you want to play again (y/n): ";
	cin>>replay;
}while(replay=='y' || replay=='Y');
	return 0;
}

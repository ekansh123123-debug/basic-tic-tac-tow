#include<iostream>
using namespace std;
void print(char arr[3][3]){
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << " |" ;
    for(int i = 0 ; i < 3 ; i++){
        cout << i+1 ;
        if(i!=2)
            cout <<"\t" ;
    }
    cout << " ";
    cout<< "|" << endl;
    for(int i = 0 ; i < 3 ; i++){
        cout << i+1<< "|" ;
        for(int j = 0 ; j < 3 ;j++){
            cout << arr[i][j] << "  ";
            if(j!=2)
                cout << "\t";
            
        }
        cout << "|" << endl;
    }
}
bool check(char arr[3][3]){
    for(int i = 0 ; i < 3 ; i++){
        if(arr[i][1]==arr[i][2] && arr[i][1] == arr[i][0] && arr[i][0]!='\0')
            return false;
    }
    for(int i = 0 ; i < 3 ; i++){
        if(arr[1][i]==arr[2][i] && arr[2][i]==arr[0][i] && arr[0][i]!='\0')
            return false;
    }
    if(arr[0][0]==arr[1][1] && arr[0][0]== arr[2][2] && arr[1][1] !='\0'){
        return false;
    }
    if(arr[0][2]==arr[1][1] && arr[1][1]== arr[2][0] && arr[1][1]!='\0'){
        return false;
    }
    return true;
    
}
void input(char arr[3][3] , bool &turn){
    char a = turn ? 'X' : 'O';
    char b = turn ? 'O' : 'X';
    if(check(arr)==false) {
        print(arr);
        cout << "\t\tThe game has ended and the player with :" <<b<< " has won "<<endl;
        cout << "-----------------------------------------------------------------------" << endl;
        return;
    }
    print(arr);
    int i , j;
    cout << "This is the turn of player '" << a << "', " << endl;
    cout << "Enter the cordinates of position you want to mark ::";
    cin >> i >> j;
    if(arr[i-1][j-1]=='\0'){
        arr[i-1][j-1] = a;
        turn =!turn ;
    }
    else{
        cout << "Invalid opration , The given cordinates are alredy ocupied " << endl; 
        cout << "Try again " << endl;
    }
    
    input(arr,turn);
    return;
}
int main(){
    cout << "--------------------------------------------------------------------" << endl;;
    cout << "\t\tThis is a game of tic-tac-tow" << endl;
    cout << "The game starts with X as 1st player" << endl;
    bool turn = true;
    char arr[3][3] ={};
    input(arr,turn);

    return 0;
}
#include <iostream>
#include "matrix.h"
#include <conio.h>
#include <string.h>
#include <windows.h>
using namespace std;

typedef struct node{
    char name[20];
    int hitpts;
    struct node* next;
}node;

node* insPlayers(char* name1, char* name2){
    node* p1 = new node;
    node* p2 = new node;
    strcpy(p1->name,name1);
    strcpy(p2->name,name2);
    p1->hitpts = p2->hitpts = 17;
    p1->next = p2;
    p2->next = p1;
    return p1;
}

void arrow1(int optPos, int curPos){
        if(optPos==curPos)printf(">");
};

void menuDesc(int i,int x){
        if(i == 1 && x == 1 )printf("    (Start a new game)\n\n");
        else if(i == 2 && x == 2 )printf("      (New to the Game?)\n\n");
        else if(i == 3 && x == 3 )printf("          (The Devs)\n\n");
        else printf("\n\n");
};

int renderMainMenu() {
    int x = 1;
    while(1){
        system("cls");
        if(x<1)x=4;
        if(x>4)x=1;
        printf("========== BATTLESHIP ==========\n");
        arrow1(1,x);cout<<" PLAY          ";menuDesc(1,x);
        arrow1(2,x);cout<<" How To Play   ";menuDesc(2,x);
        arrow1(3,x);cout<<" Crdits        ";menuDesc(3,x);
        arrow1(4,x);cout<<" QUIT"<<endl;
        printf("[Use Arrow keys to select]");
        char ch = getch();
        switch(ch){
            case 72: x--;break;
            case 75: x--;break;
            case 80: x++;break;
            case 77: x++;break;
            case 13:
            if(x==1)return 1;
            if(x==2)return 2;
            if(x==3)return 3;
            if(x==4)return 4;
            break;
        }
    }
}

int checkOverlap(char** matrix, int orien, int dir, int row, int col, int to){
    if(orien==1){
        if(dir==1){
            for (int i = col; i<to; i++){
                if(matrix[row][i] != '#'){
                    return 1;
                }
            }
        }
        if(dir==0){
            for (int i = col; i>to; i--){
                if(matrix[row][i] != '#'){
                    return 1;
                }
            }
        }
        return 0;
    }
    if(orien==0){
        if(dir==1){
            for (int i = row; i<to; i++){
                if(matrix[i][col] != '#'){
                    return 1;
                }
            }
        }
        if(dir==0){
            for (int i = row; i>to; i--){
                if(matrix[i][col] != '#'){
                    return 1;
                }
            }
        }
        return 0;
    }
}

int placeShip(char** plr, char type, int orien, int row, int col){
    int loopCnt = 0;
    if(type == 'A'){
        loopCnt = 5;
        if(orien == 1){  // Horizontal
            if (col-loopCnt < 0){
                if(!checkOverlap(plr,orien,1,row,col,col+loopCnt)){
                    for(int i = col;i<(loopCnt+col);i++){
                        updateMatrix(plr,10,'A',row,i);
                    }
                }else return 0;
            }
            else if (col+loopCnt > 9){
                if(!checkOverlap(plr,orien,0,row,col,col-loopCnt)){
                    for(int i = col;i>(col-loopCnt);i--){
                        updateMatrix(plr,10,'A',row,i);
                    }
                }else return 0;
            }
            else{
                if(!checkOverlap(plr,orien,1,row,col,col+loopCnt)){
                    for(int i = col;i<(loopCnt+col);i++){
                        updateMatrix(plr,10,'A',row,i);
                    }
                }else return 0;
            }
        }
        if(orien == 0){
            if (row-loopCnt < 0){
                if(!checkOverlap(plr,orien,1,row,col,row+loopCnt)){
                    for(int i = row;i<(loopCnt+row);i++){
                        updateMatrix(plr,10,'A',i,col);
                    }
                }else return 0;
            }
            else if (row+loopCnt > 9){
                if(!checkOverlap(plr,orien,0,row,col,row-loopCnt)){
                    for(int i = row;i>(row-loopCnt);i--){
                        updateMatrix(plr,10,'A',i,col);
                    }
                }else return 0;
            }
            else{
                if(!checkOverlap(plr,orien,1,row,col,row+loopCnt)){
                    for(int i = row;i<(loopCnt+row);i++){
                        updateMatrix(plr,10,'A',i,col);
                    }
                }else return 0;
            }
        }
    }
    if(type == 'B'){
        loopCnt = 4;
        if(orien == 1){  // Horizontal
            if (col-loopCnt < 0){
                if(!checkOverlap(plr,orien,1,row,col,col+loopCnt)){
                    for(int i = col;i<(loopCnt+col);i++){
                        updateMatrix(plr,10,'B',row,i);
                    }
                }else return 0;
            }
            else if (col+loopCnt > 9){
                if(!checkOverlap(plr,orien,0,row,col,col-loopCnt)){
                    for(int i = col;i>(col-loopCnt);i--){
                        updateMatrix(plr,10,'B',row,i);
                    }
                }else return 0;
            }
            else{
                if(!checkOverlap(plr,orien,1,row,col,col+loopCnt)){
                    for(int i = col;i<(loopCnt+col);i++){
                        updateMatrix(plr,10,'B',row,i);
                    }
                }else return 0;
            }
        }
        if(orien == 0){
            if (row-loopCnt < 0){
                if(!checkOverlap(plr,orien,1,row,col,row+loopCnt)){
                    for(int i = row;i<(loopCnt+row);i++){
                        updateMatrix(plr,10,'B',i,col);
                    }
                }else return 0;
            }
            else if (row+loopCnt > 9){
                if(!checkOverlap(plr,orien,0,row,col,row-loopCnt)){
                    for(int i = row;i>(row-loopCnt);i--){
                        updateMatrix(plr,10,'B',i,col);
                    }
                }else return 0;
            }
            else{
                if(!checkOverlap(plr,orien,1,row,col,row+loopCnt)){
                    for(int i = row;i<(loopCnt+row);i++){
                        updateMatrix(plr,10,'B',i,col);
                    }
                }else return 0;
            }
        }
    }
    if(type == 'C'){
        loopCnt = 3;
        if(orien == 1){  // Horizontal
            if (col-loopCnt < 0){
                if(!checkOverlap(plr,orien,1,row,col,col+loopCnt)){
                    for(int i = col;i<(loopCnt+col);i++){
                        updateMatrix(plr,10,'C',row,i);
                    }
                }else return 0;
            }
            else if (col+loopCnt > 9){
                if(!checkOverlap(plr,orien,0,row,col,col-loopCnt)){
                    for(int i = col;i>(col-loopCnt);i--){
                        updateMatrix(plr,10,'C',row,i);
                    }
                }else return 0;
            }
            else{
                if(!checkOverlap(plr,orien,1,row,col,col+loopCnt)){
                    for(int i = col;i<(loopCnt+col);i++){
                        updateMatrix(plr,10,'C',row,i);
                    }
                }else return 0;
            }
        }
        if(orien == 0){
            if (row-loopCnt < 0){
                if(!checkOverlap(plr,orien,1,row,col,row+loopCnt)){
                    for(int i = row;i<(loopCnt+row);i++){
                        updateMatrix(plr,10,'C',i,col);
                    }
                }else return 0;
            }
            else if (row+loopCnt > 9){
                if(!checkOverlap(plr,orien,0,row,col,row-loopCnt)){
                    for(int i = row;i>(row-loopCnt);i--){
                        updateMatrix(plr,10,'C',i,col);
                    }
                }else return 0;
            }
            else{
                if(!checkOverlap(plr,orien,1,row,col,row+loopCnt)){
                    for(int i = row;i<(loopCnt+row);i++){
                        updateMatrix(plr,10,'C',i,col);
                    }
                }else return 0;
            }
        }
    }
    if(type == 'S'){
        loopCnt = 3;
        if(orien == 1){  // Horizontal
            if (col-loopCnt < 0){
                if(!checkOverlap(plr,orien,1,row,col,col+loopCnt)){
                    for(int i = col;i<(loopCnt+col);i++){
                        updateMatrix(plr,10,'S',row,i);
                    }
                }else return 0;
            }
            else if (col+loopCnt > 9){
                if(!checkOverlap(plr,orien,0,row,col,col-loopCnt)){
                    for(int i = col;i>(col-loopCnt);i--){
                        updateMatrix(plr,10,'S',row,i);
                    }
                }else return 0;
            }
            else{
                if(!checkOverlap(plr,orien,1,row,col,col+loopCnt)){
                    for(int i = col;i<(loopCnt+col);i++){
                        updateMatrix(plr,10,'S',row,i);
                    }
                }else return 0;
            }
        }
        if(orien == 0){
            if (row-loopCnt < 0){
                if(!checkOverlap(plr,orien,1,row,col,row+loopCnt)){
                    for(int i = row;i<(loopCnt+row);i++){
                        updateMatrix(plr,10,'S',i,col);
                    }
                }else return 0;
            }
            else if (row+loopCnt > 9){
                if(!checkOverlap(plr,orien,0,row,col,row-loopCnt)){
                    for(int i = row;i>(row-loopCnt);i--){
                        updateMatrix(plr,10,'S',i,col);
                    }
                }else return 0;
            }
            else{
                if(!checkOverlap(plr,orien,1,row,col,row+loopCnt)){
                    for(int i = row;i<(loopCnt+row);i++){
                        updateMatrix(plr,10,'S',i,col);
                    }
                }else return 0;
            }
            
        }
    }
    if(type == 'D'){
        loopCnt = 2;
        if(orien == 1){  // Horizontal
            if (col-loopCnt < 0){
                if(!checkOverlap(plr,orien,1,row,col,col+loopCnt)){
                    for(int i = col;i<(loopCnt+col);i++){
                        updateMatrix(plr,10,'D',row,i);
                    }
                }else return 0;
            }
            else if (col+loopCnt > 9){
                if(!checkOverlap(plr,orien,0,row,col,col-loopCnt)){
                    for(int i = col;i>(col-loopCnt);i--){
                        updateMatrix(plr,10,'D',row,i);
                    }
                }else return 0;
            }
            else{
                if(!checkOverlap(plr,orien,1,row,col,col+loopCnt)){
                    for(int i = col;i<(loopCnt+col);i++){
                        updateMatrix(plr,10,'D',row,i);
                    }
                }else return 0;
            }
        }
        if(orien == 0){
            if (row-loopCnt < 0){
                if(!checkOverlap(plr,orien,1,row,col,row+loopCnt)){
                    for(int i = row;i<(loopCnt+row);i++){
                        updateMatrix(plr,10,'D',i,col);
                    }
                }else return 0;
            }
            else if (row+loopCnt > 9){
                if(!checkOverlap(plr,orien,0,row,col,row-loopCnt)){
                    for(int i = row;i>(row-loopCnt);i--){
                        updateMatrix(plr,10,'D',i,col);
                    }
                }else return 0;
            }
            else{
                if(!checkOverlap(plr,orien,1,row,col,row+loopCnt)){
                    for(int i = row;i<(loopCnt+row);i++){
                        updateMatrix(plr,10,'D',i,col);
                    }
                }else return 0;
            }
        }
    }
    return 1;
}

void plrShipSetup(node* plr, char** mat){
    int row,col,orient;
    int A=0,B=0,C=0,S=0,D=0;
    while(!(A&&B&&C&&D&&S)){
        if(A==0){
            cout<<"=== Captain "<<plr->name<<"'s Fleet ==="<<endl;
            printMatrix(mat,10);
            cout<<"Enter Position of Aircraft Carrier [row column orientation(0: Vertical, 1:Horizontal)]: ";
            cin>>row>>col>>orient;
            if(placeShip(mat,'A',orient,row,col)){cout<<"Carrier positioned!"<<endl;A=1;Sleep(3000);}
            else{cout<<"[!] Invalid Position :/"<<endl;Sleep(2000);}
            system("cls");
        }
        if(B==0){
            cout<<"=== Captain "<<plr->name<<"'s Fleet ==="<<endl;
            printMatrix(mat,10);
            cout<<"Enter Position of Battleship [row column orientation(0: Vartical, 1:Horizontal)]: ";
            cin>>row>>col>>orient;
            if(placeShip(mat,'B',orient,row,col)){cout<<"Battleship positioned!"<<endl;B=1;Sleep(3000);}
            else{cout<<"[!] Invalid Position :/"<<endl;Sleep(2000);}
            system("cls");
        }
        if(C==0){
            cout<<"=== Captain "<<plr->name<<"'s Fleet ==="<<endl;
            printMatrix(mat,10);
            cout<<"Enter Position of Cruiser [row column orientation(0: Vartical, 1:Horizontal)]: ";
            cin>>row>>col>>orient;
            if(placeShip(mat,'C',orient,row,col)){cout<<"Cruiser positioned!"<<endl;C=1;Sleep(3000);}
            else{cout<<"[!] Invalid Position :/"<<endl;Sleep(2000);}
            system("cls");
        }
        if(S==0){
            cout<<"=== Captain "<<plr->name<<"'s Fleet ==="<<endl;
            printMatrix(mat,10);
            cout<<"Enter Position of Submarine [row column orientation(0: Vartical, 1:Horizontal)]: ";
            cin>>row>>col>>orient;
            if(placeShip(mat,'S',orient,row,col)){cout<<"Submarine positioned!"<<endl;S=1;Sleep(3000);}
            else{cout<<"[!] Invalid Position :/"<<endl;Sleep(2000);}
            system("cls");
        }
        if(D==0){
            cout<<"=== Captain "<<plr->name<<"'s Fleet ==="<<endl;
            printMatrix(mat,10);
            cout<<"Enter Position of Destroyer [row column orientation(0: Vartical, 1:Horizontal)]: ";
            cin>>row>>col>>orient;
            if(placeShip(mat,'D',orient,row,col)){cout<<"Destroyer positioned!"<<endl;D=1;Sleep(3000);}
            else{cout<<"[!] Invalid Position :/"<<endl;Sleep(2000);}
            system("cls");
        }
    }
}

void checkCollission(node* plr,char** mat,int row, int col){
    if(mat[row][col] == 'A' ||mat[row][col] == 'B' ||mat[row][col] == 'C' ||mat[row][col] == 'S' || mat[row][col] == 'D'){
        mat[row][col] = 'X';
        cout<<"[TGT HIT]"<<endl;
        (plr->hitpts)--;
    }
    else cout<<"[TGT MISS]"<<endl;;
}

int gameplay(char** p1A,char** p1B,char** p2A,char** p2B, node* h){
    node* aux = h;
    int fireX,fireY;
    while(1){
        system("cls");
        cout<<"=== Captain "<<aux->name<<"'s turn to attack ==="<<endl;
        cout<<"Your Ship Positions:"<<endl;
        if(aux==h)printMatrix(p1A,10);
        else printMatrix(p2A,10);
        cout<<"\nCoordinates Fired:"<<endl;
        if(aux==h)printMatrix(p1B,10);
        else printMatrix(p2B,10);
        cout<<"Enter Coordinates of point to Fire at [row, column]: ";
        cin>>fireX>>fireY;
        system("cls");
        cout<<"SSM (Surface to Surface Missile) Fired at ("<<fireX<<","<<fireY<<") ..."<<endl;
        Sleep(3000);
        if(aux==h)updateMatrix(p1B,10,'X',fireX,fireY);
        else updateMatrix(p2B,10,'X',fireX,fireY);
        if(aux==h)checkCollission(aux->next,p2A,fireX,fireY);
        else checkCollission(aux->next,p1A,fireX,fireY);
        Sleep(3000);
        if(aux->next->hitpts == 0){
            system("cls");
            cout<<"=== Congratulations! Captain "<<aux->name<<" ==="<<endl;
            cout<<"\n\n You've won!"<<endl;
            Sleep(5000);
            break;
        }
        aux = aux->next;
    }
}

int main(){
    node* head = NULL;

    const int size = 10;
    int win = 0,quit=0;
    char n1[20],n2[20];
    char** p1Ships = readMatrixFromFile("grid.txt", size);
	char** p1Target = readMatrixFromFile("grid.txt", size);
    char** p2Ships = readMatrixFromFile("grid.txt", size);
	char** p2Target = readMatrixFromFile("grid.txt", size);
    while(!quit){
        int menuChoice = renderMainMenu();
        switch(menuChoice){
            case 1:
            
            system("cls");
            cout<<"Enter name of Player 1: ";
            cin>>n1;
            cout<<"Enter name of Player 2: ";
            cin>>n2;
            system("cls");
            head = insPlayers(n1,n2);
            cout<<"Ship Setup: Do not let the opponent see your ship placement\n[press anykey to continue]"<<endl;
            getch();
            system("cls");
            plrShipSetup(head,p1Ships);
            plrShipSetup(head->next,p2Ships);
            gameplay(p1Ships,p1Target,p2Ships,p2Target,head);
            break;
            case 2:
            system("cls");
            cout<<"Google it plis"<<endl;
            Sleep(3000);
            break;
            case 3:
            system("cls");
            cout<<"Game Logic, Design and Player Handling - Arnab\nGrid generation, Game Coordinate system - Siri\nGrid modification and Memory handling - Anishya"<<endl;
            Sleep(5000);
            break;
            case 4:
            quit = 1;
            break;


        }
    }
    
    

}
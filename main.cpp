#include<bits/stdc++.h>
#include <windows.h>    //  header file for gotoxy
#include <iostream> //header file for standard input output
#include <conio.h>
#include<stdio.h>
#include<dos.h>
#include<cstdlib>
#include<ctime>

using namespace std;
COORD coord= {0,0}; // this is global variable
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
// random number generator function
int Random_N_generator(int k){
    srand(time(0));
    return rand()%k;
}
// check attack function
bool check_attack(int zombie_x,int zombie_y,int survivor_x,int survivor_y){
    int distance_btw_zombie_and_survivor;

    distance_btw_zombie_and_survivor=abs(survivor_x-zombie_x)+abs(survivor_y-zombie_y);

    return distance_btw_zombie_and_survivor<=1;
}

int mainA()
{
    int x=10,y=10;
    while(1){
        system("cls");
        gotoxy(x,y);
        cout<<"X";
        char ch;
        if(kbhit)
        {
        ch=getch();
        int a[]={0,0,1,-1};
        int b[]={1,-1,0,0};
        switch(ch){

            case 'a':{
                x=x+a[3];
                y=y+b[3];
            }
            break;
            case 's':{
                x=x+a[0];
                y=y+b[0];
            }
            break;
            case 'd':{
                x=x+a[2];
                y=y+b[2];
            }
            break;
            case 'w':{
                x=x+a[1];
                y=y+b[1];
            }
            break;
        }

        }
    }
    getch();

    return 0;
}

int main(){
    //ios_base::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
    queue<pair<int,int>> zombie_position;
    int player_score=0,max_hp=100,hp=100,generator=4,max_x_width=100,max_y_width=80,loop_time=0,x=10,y=10;
    while(1){
            system("cls");
            loop_time++;
        if(loop_time>=10){
            loop_time-=10;
            hp=min(max_hp,hp+1);
        }
        generator=player_score*4/30+4;
        for(int i=0;i<generator;i++){
            int new_x_pos=Random_N_generator(max_x_width);
            int new_y_pos=0;//random generator
            zombie_position.push({new_x_pos,new_y_pos});
        }
        player_score+=generator;
        int k=zombie_position.size();
        int zombie_new_x[]={-1,0,1,1,1,0,-1,-1};
        int zombie_new_y[]={1,1,1,0,-1,-1,-1,0};
        for(int i=0;i<k;i++){
            int zx=zombie_position.front().first;
            int zy=zombie_position.front().second;
            zombie_position.pop();
            int rand_index=Random_N_generator(8);
            int nx=zx+zombie_new_x[rand_index];
            int ny=zy+zombie_new_y[rand_index];
            if(nx>=0&&nx<max_x_width&&ny>=0&&ny<max_y_width){
                if(check_attack(nx,ny,x,y)){
                    hp--;
                    if(hp==0)
                    return 0;
                }else{
                zombie_position.push({nx,ny});
                gotoxy(nx,ny);
                cout<<"O";}
            }else{
                if(check_attack(zx,zy,x,y)){
                    hp--;
                    if(hp==0)
                    return 0;
                }else{
                zombie_position.push({nx,ny});
                gotoxy(zx,zy);
                cout<<"O";}
            }
        }
        gotoxy(x,y);
        cout<<"X";
        char ch;
        if(kbhit)
        {
        ch=getch();
        int a[]={0,0,1,-1};
        int b[]={1,-1,0,0};
        switch(ch){

            case 'a':{
                x=x+a[3];
                y=y+b[3];
            }
            break;
            case 's':{
                x=x+a[0];
                y=y+b[0];
            }
            break;
            case 'd':{
                x=x+a[2];
                y=y+b[2];
            }
            break;
            case 'w':{
                x=x+a[1];
                y=y+b[1];
            }
            break;
        }
        gotoxy(80 ,10);
        cout<<hp;

    }
}
}

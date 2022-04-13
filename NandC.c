#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void printGrid(char* gridP);
void updatePointer(char* player, char*gridP,char coord[]);
char winCheck(char*gridPointer);

char winCheck(char* gridPointer){
    for (int i = 0; i <= 4; i+=2){
        if (*(gridPointer + i) != 32){
            if (*(gridPointer + i) == (*(gridPointer + i +10)) && *(gridPointer + i) == (*(gridPointer + i + 20))){
                return *(gridPointer + i);
            }
        }
    }
    for (int i = 0; i <=2; i++){
        if (*(gridPointer + (i*10)) != 32){
            if (*(gridPointer + (i*10)) == (*((gridPointer + (i*10) +2))) && *(gridPointer + (i*10)) == (*((gridPointer + (i*10) + 4)))){
                return *(gridPointer + (i*10));
            }
        }
    }
    if (*gridPointer != 32){
        if (*gridPointer == *(gridPointer + 12) && *gridPointer == *(gridPointer + 24)){
            printf("down\n");
            return *gridPointer;
        }
    }
        if (*(gridPointer + 4) != 32){
            if (*(gridPointer+4) == *(gridPointer + 12) && *(gridPointer+4) == *(gridPointer + 20)){
                printf("up\n");
                return (*(gridPointer + 4));
        }
    }
    return ' ';
}

void printGrid(char* gridP){
    for (int i = 1; i < 26; i++){
        printf("%c",*gridP);
        gridP ++;
        if(i % 5 == 0){
            printf("\n");
        }
    }
    printf("\n");
}

void updatePointer(char* player, char* gridP, char coord[]){
    if (!strcmp(coord,"tl")){
        gridP += 0;
    }else if (!strcmp(coord,"tm")){
        gridP += 2;
    }else if (!strcmp(coord,"tr")){
        gridP += 4;
    }else if (!strcmp(coord,"ml")){
        gridP += 10;
    }else if (!strcmp(coord,"mm")){
        gridP += 12;
    }else if (!strcmp(coord,"mr")){
        gridP += 14;
    }else if (!strcmp(coord,"bl")){
        gridP += 20;
    }else if (!strcmp(coord,"bm")){
        gridP += 22;
    }else if (!strcmp(coord,"br")){
        gridP += 24;
    }else{
        return;
    }

    if (*gridP == 32){
        if (*player == 'X'){
            *player = 'O';
        }else{
            *player = 'X';
        }
        *gridP = *player;
    }
}

int main(){
     char grid[5][5]= {{' ','|',' ','|',' '},{'-','+','-','+','-'},{' ','|',' ','|',' '},{'-','+','-','+','-'},{' ','|',' ','|',' '}};
     char player = 'X';
     char coord[] = "tr";
     printGrid(&grid[0][0]);
    while(1){
        printf("Enter a coord ");
        scanf("%s",coord);
        updatePointer(&player,&grid[0][0],coord);
        printGrid(&grid[0][0]);
        char win = winCheck(&grid[0][0]);
        if(win != ' '){
            printf("%c Won BOOM",win);
            break;
        }
    }
}
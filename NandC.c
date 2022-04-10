#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void updateCheck(char* gridPointer,char* playerPointer){
    //printf("%c\n",*gridPointer);
    char turn = *playerPointer;
    if (*gridPointer == 32){
        if (*playerPointer =='X'){
            *playerPointer = 'O';
        }else{
            *playerPointer = 'X';
        }
        printf("%c here \n",*playerPointer);
        *gridPointer = turn;
    }
    
}

void updateGrid(char* gridPointer,char* playerPointer,char coord[]){

    if (!strcmp(coord,"tl")){//this workds, expand for rest of coords and add a default
    }
    else if (!strcmp(coord,"tm")){
        gridPointer += 2;
    }else if (!strcmp(coord,"tr")){
        gridPointer += 4;
    }else if (!strcmp(coord,"ml")){
        gridPointer += 10;
    }else if (!strcmp(coord,"mm")){
        gridPointer += 12;
    }else if (!strcmp(coord,"mr")){
        gridPointer += 14;
    }else if (!strcmp(coord,"bl")){
        gridPointer += 20;
    }else if (!strcmp(coord,"bm")){
        gridPointer += 22;
    }else if (!strcmp(coord,"br")){
        gridPointer += 24;
    }
    updateCheck(gridPointer,playerPointer);
}


void winCheck(bool* win,char* gridPointer){
    char* gridCopy = gridPointer;
    for (int i = 0; i < 4; i+=2){
        char first = *gridCopy + i;
        if (first != 32){
            if (first == (*(gridCopy +10)) && first == (*(gridCopy + 10))){
                *win = true;
            }
        }
    }
        for (int i = 0; i < 4; i++){
        char first = *gridCopy + (i*10);
        if (first != 32){
            if (first == (*(gridCopy +2)) && first == (*(gridCopy + 4))){
                *win = true;
            }
        }
    }

    if (*gridCopy != 32){
        if (*gridCopy == *(gridCopy + 12) && *gridCopy == *(gridCopy + 24)){
            *win = true;
        }
    }
        if (*(gridCopy + 4) != 32){
            if (*gridCopy == *(gridCopy + 12) && *gridCopy == *(gridCopy + 20)){
                *win = true;
        }
    }

}

void printGrid(char grid[5][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%c",grid[i][j]);
        }
        printf("\n");
    }
}

int main(){
    char grid[5][5] = {{' ','|',' ','|',' '},{'-','+','-','+','-'},{' ','|',' ','|',' '},{'-','+','-','+','-'},{' ','|',' ','|',' '}};
    //char grid[5][5] = {{'1','|','2','|','3'},{'-','+','-','+','-'},{'4','|','5','|',' '},{'-','+','-','+','-'},{' ','|',' ','|',' '}};

    char player = 'X';
    char coord[2];
    bool win = false;
    printGrid(grid);

    while(1){
        printf("Enter a coord,e.g. tr\t");
        scanf("%s",coord);
        updateGrid(&grid[0][0], &player,coord);
        printGrid(grid);
        // winCheck(&win,&grid[0][0]);
        // if (win){
        //     break;
        // }
    }
}


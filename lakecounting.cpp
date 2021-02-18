#include <iostream>
#include <vector>
int N = 10;
int M = 12;

std::vector<std::vector<std::string>> map(N,std::vector<std::string>(M, "."));
std::vector<std::vector<int>> arrivemap(N, std::vector<int>(M, 0));

bool findstart(int* start){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == "W" && arrivemap[i][j] == 0){
                arrivemap[i][j] = 1;
                start[0] = i;
                start[1] = j;
                return true;
            }
        }
    }
    return false;
}  

void lakefind(int* position){
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            int y = position[0] + i;
            int x = position[1] + j;
            if(x >= 0 && x < M && y >= 0 && y < N && !(x == 0 && y == 0)){
                if(map[y][x] == "W" && arrivemap[y][x] == 0){
                    arrivemap[y][x] = 1;
                    int next[2] = {y, x};
                    lakefind(next);
                }
            }
        }
    }
}

int main(){
    map[0][0] = "W";
    map[0][9] = "W";
    map[0][10] = "W";
    map[1][1] = "W";
    map[1][2] = "W";
    map[1][3] = "W";
    map[1][9] = "W";
    map[1][10] = "W";
    map[1][11] = "W";
    map[2][4] = "W";
    map[2][5] = "W";
    map[2][9] = "W";
    map[2][10] = "W";
    map[3][9] = "W";
    map[3][10] = "W";
    map[4][9] = "W";
    map[5][2] = "W";
    map[5][9] = "W";
    map[6][1] = "W";
    map[6][3] = "W";
    map[6][9] = "W";
    map[6][10] = "W";
    map[7][0] = "W";
    map[7][2] = "W";
    map[7][4] = "W";
    map[7][10] = "W";
    map[8][1] = "W";
    map[8][3] = "W";
    map[8][10] = "W";
    map[9][2] = "W";
    map[9][10] = "W";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }

    int start[2];
    int count = 0;
    while(findstart(start)){
        lakefind(start);
        count++;
    }

    std::cout << count << std::endl;
}
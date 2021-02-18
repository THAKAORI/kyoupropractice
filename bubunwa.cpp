#include <iostream>

const int n = 4;
int a[4] = {1, 2, 4, 7};
int k = 13;

bool dfs(int i, int sum){
    if(i==n) return sum == k;

    if(dfs(i+1, sum)) return true;
    
    if(dfs(i+1, sum + a[i])) return true;

    return false;
}

int main(){
    if(dfs(0, 0)){
        std::cout << "found" << std::endl;
    }else{
        std::cout << "Not found" << std::endl;
    }
}
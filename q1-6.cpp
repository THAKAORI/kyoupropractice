#include <iostream>

int main(){
    const int n = 4; 
    int a[n] = {4, 5, 10, 20};
    int results[3] = {0, 0, 0};
    for(int i = 0; i < n - 3; i++){
        int lines[3] = {a[n-i-3], a[n-i-2], a[n-i-1]};
        if(lines[0] + lines[1] > lines[2]){
            results[0] = lines[0];
            results[1] = lines[1];
            results[2] = lines[2];
            break;
        }
    }
    int linesum = results[0] + results[1] + results[2];
    if(linesum == 0){
        std::cout << "no triangle found" << std::endl;
    }else{
        std::cout << linesum << std::endl;
    }
}
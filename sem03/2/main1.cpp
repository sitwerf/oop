#include <iostream>

int main(){
    int *ptr = new int(100);
    int *arr = new int[10];

    for (int i = 0; i < 10; i++){
        arr[i] = i + 3;
    }
    std ::cout << "Массив: ";
    for (int i = 0; i < 10; i++){
        std :: cout << arr[i];
    }
    
}
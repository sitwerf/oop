#include <iostream>

int main(){
    int *ptr = new int(100);    //указатель на 1 значение
    int *arr = new int[10];     //указатель на массив


    for (int i = 0; i < 10; i++){       //заполняем массив значениями
        arr[i] = i + 3;
    }
    std ::cout << "Массив: ";           //выводим значения массива
    for (int i = 0; i < 10; i++){
        std :: cout << arr[i] << " ";
    }
    

    int *vis_ykaz = new int(5);
    std::cout << "До удаления " << *vis_ykaz << std::endl;
    delete vis_ykaz;        // vis_ykaz теперь висячий указатель
                            // std::cout << *vis_ykaz; - неопределенное поведение
    vis_ykaz = nullptr;


    int *new_arr = new int(11);
    for (int i = 0; i < 5; i++){
        new_arr[i] = arr[i];
    }
    new_arr[5] = 100;               //добавляем элемент в середину массива
    for (int i = 5; i < 10; i++){
        new_arr[i+1] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    new_arr = nullptr;
    delete[] new_arr;


    std::cout << "Новый массив: ";
    for (int i=0; i < 11; i++){         //выводим новый массив
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    delete ptr;                         //правильное освобождение памяти
    ptr = nullptr;
    delete[] arr; 
    arr = nullptr;


    return 0;
}
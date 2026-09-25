#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> ptr = std::make_unique<int>(5);

    std::cout << "Значение: " << *ptr << std::endl;

    ptr.reset(); // удаляет объект и делает ptr == nullptr

    if (ptr == nullptr) {
        std::cout << "Указатель теперь nullptr " << std::endl;
    }

    return 0;
}
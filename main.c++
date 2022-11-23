#include "fparser.h"

int main(){
    std::string f_input;
    std::cout << "Ввод функции: ";

    // Значение переменной "X"
    int x = 5;
    int y = 15;
    int z = 10;

    // Ввод строки пользователя 
    // с пробелом в теле функции
    getline(std::cin, f_input); 

    // FParser parser(x);
    FParser parser(x, y , z);

    std::cout << "Результат вычисления: " << parser.parse(f_input) << "\n";

	return EXIT_SUCCESS;
}

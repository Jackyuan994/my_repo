#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("file.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        ::std::cout << "Error: unable to open file" << std::endl;
        return 1;
    }
    return 0;
}
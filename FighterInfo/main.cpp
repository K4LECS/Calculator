#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter Fighter Name: ";
    if (!std::getline(std::cin, name)) return 0;
    std::cout << "You entered: " << name << '\n';
    if(name == "Max Holloway") {
        std::cout << "Nickname: 'Blessed'\n";
        std::cout << "Division: Featherweight\n";
        std::cout << "Record: 21-6-0\n";
    } 
    else{
        std::cout << "Who?\n";
    } 
    return 0;
}
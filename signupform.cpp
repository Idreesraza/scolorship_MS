#include <iostream>
#include <fstream>
#include <string>

class User {
public:
    std::string username;
    std::string password;
    std::string email;

    void signUp();
    void saveToFile();
};

void User::signUp() {
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter email: ";
    std::cin >> email;
}

void User::saveToFile() {
    std::ofstream outFile("users.txt", std::ios::app); // Open file in append mode
    if (outFile.is_open()) {
        outFile << username << " " << password << " " << email << "\n";
        outFile.close();
        std::cout << "User information saved successfully.\n";
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

int main() {
    User newUser;
    newUser.signUp();
    newUser.saveToFile();

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>

void readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}

void writeFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        std::string line;
        std::cout << "Enter text (type 'quit' to finish):\n";
        while (true) {
            std::getline(std::cin, line);
            if (line == "quit") {
                break;
            }
            file << line << std::endl;
        }
        file.close();
        std::cout << "File saved successfully." << std::endl;
    } else {
        std::cout << "Unable to create file: " << filename << std::endl;
    }
}

int main() {
    std::string filename;

    std::cout << "File Operations Application" << std::endl;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    readFile(filename);

    std::cout << "Options:\n";
    std::cout << "1. Edit the file\n";
    std::cout << "2. Save as new file\n";
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            writeFile(filename);
            break;
        case 2:
            std::cout << "Enter the new filename: ";
            std::cin >> filename;
            writeFile(filename);
            break;
        default:
            std::cout << "Invalid choice. Exiting the program." << std::endl;
            break;
    }

    return 0;
}

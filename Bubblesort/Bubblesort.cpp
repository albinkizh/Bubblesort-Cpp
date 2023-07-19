#include <iostream>
#include <random>
#include <vector>
#include <iomanip> 

int minNumber;
int maxNumber;
int amount;
int option = 1;

void Questiongrid(int minNumber, int maxNumber, int amount) {

    if (option == 1) {
        system("CLS");
        std::cout << "                  Type a number";
        std::cout << "\n                _________________                _________________                _________________\n";
        std::cout << "                From: " << std::setw(21) << std::left << minNumber;
        std::cout << "      Till: " << std::setw(21) << std::left << maxNumber;
        std::cout << "      Amount: " << std::setw(21) << std::left << amount << "\n";
    }
    else if (option == 2){
        system("CLS");
        std::cout << "                                                   Type a number";
        std::cout << "\n                _________________                _________________                _________________\n";
        std::cout << "                From: " << std::setw(21) << std::left << minNumber;
        std::cout << "      Till: " << std::setw(21) << std::left << maxNumber;
        std::cout << "      Amount: " << std::setw(21) << std::left << amount << "\n";
    }
    else if (option == 3) {
        system("CLS");
        std::cout << "                                                                                    Type a number";
        std::cout << "\n                _________________                _________________                _________________\n";
        std::cout << "                From: " << std::setw(21) << std::left << minNumber;
        std::cout << "      Till: " << std::setw(21) << std::left << maxNumber;
        std::cout << "      Amount: " << std::setw(21) << std::left << amount << "\n";
    }
    else {
        system("CLS");
        std::cout << "\n                _________________                _________________                _________________\n";
        std::cout << "                From: " << std::setw(21) << std::left << minNumber;
        std::cout << "      Till: " << std::setw(21) << std::left << maxNumber;
        std::cout << "      Amount: " << std::setw(21) << std::left << amount << "\n";
    }

    std::cout << "\n";
}
void randomnumbergenerator(std::vector<int>& saves) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(minNumber, maxNumber);
    std::cout << "\n";
    std::cout << "\n                                                  ________________\n";
    std::cout << "                                                   Random numbers\n\n\n";
    for (int i = 0; i < amount; i++) {
        int randomNumber = distribution(generator);
        saves.push_back(randomNumber);
        std::cout << saves[i] << " ";
    }
}
void bubbleSort(std::vector<int>& saves) {
    int size = saves.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (saves[j] > saves[j + 1]) {
                int temp = saves[j];
                saves[j] = saves[j + 1];
                saves[j + 1] = temp; 
            }
        }
    }
}
int main() {
    std::vector<int> saves;

    do {

        Questiongrid(minNumber, maxNumber, amount);
        std::cin >> minNumber;
        option = 2;
        Questiongrid(minNumber, maxNumber, amount);
        std::cin >> maxNumber;
        option = 3;
        Questiongrid(minNumber, maxNumber, amount);
        std::cin >> amount;
        option = 0;
        Questiongrid(minNumber, maxNumber, amount);

        randomnumbergenerator(saves);
        std::cout << "\n\n\n                                               Ready to sort? [Yes/No]\n";
        std::cout << "                                              _________________________\n";
        std::string ans;
        std::cin >> ans;

        if (ans == "Yes") {
            bubbleSort(saves);
            break;
        }
    } while (true);

    int size = saves.size();
    system("CLS");
    Questiongrid(minNumber, maxNumber, amount);
    std::cout << "\n                                                  ________________\n";
    std::cout << "                                                   Sorted numbers\n\n\n";
    for (int i = 0; i < size; i++) {
        std::cout << saves[i] << " ";
    }
    std::cout << "\n";
}

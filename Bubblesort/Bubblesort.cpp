#include <iostream>
#include <random>
#include <vector>
int minNumber;
int maxNumber;
int amount;

void Questiongrid(int minNumber, int maxNumber, int amount) {
    system("CLS");

    std::cout << "                _________________                _________________                _________________\n";
    std::cout << "                From: " << minNumber;
    std::cout << "                          Till: " << maxNumber;
    std::cout << "                          Amount: " << amount << "\n";

}

void randomnumbergenerator(std::vector<int>& saves) {

    Questiongrid(minNumber, maxNumber, amount);
    std::cin >> minNumber;
    Questiongrid(minNumber, maxNumber, amount);
    std::cin >> maxNumber;
    Questiongrid(minNumber, maxNumber, amount);
    std::cin >> amount;
    Questiongrid(minNumber, maxNumber, amount);

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(minNumber, maxNumber);
    std::cout << "\n\n";
    for (int i = 0; i < amount; i++) {
        int randomNumber = distribution(generator);
        saves.push_back(randomNumber);
        std::cout << saves[i] << " ";
    }
    std::cout << "\n------------------------------------------------------------------------------------------------------------------\n";

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
        randomnumbergenerator(saves);
        std::cout << "\n\nready to sort? [Yes/No]\n\n";
        std::string ans;
        std::cin >> ans;

        if (ans == "Yes") {
            bubbleSort(saves);
            break;
        }
    } while (true);

    int size = saves.size();
    std::cout << "\n------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        std::cout << saves[i] << " ";
    }
    std::cout << "\n";

}

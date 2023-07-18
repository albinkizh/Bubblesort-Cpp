#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

int randomNumber;
std::string ans;

void randomnumbergenerator(std::vector<int>& saves) {
    for (int i = 0; i < 50; i++) {
        std::random_device rd;
        std::mt19937 generator(rd());
        int minNumber = 1;
        int maxNumber = 1000;
        std::uniform_int_distribution<int> distribution(minNumber, maxNumber);
        randomNumber = distribution(generator);
        saves.push_back(randomNumber);
        std::cout << saves[i] << ",";
    }
}

int main()
{
    std::vector<int> saves;

    do {
        randomnumbergenerator(saves);
        std::cout << "\n\nready to sort? [Yes/No]\n";
        std::cin >> ans;

        if (ans == "Yes") {
            std::sort(saves.begin(), saves.end());
            break;
        }
    } while (true);

    for (const auto& num : saves) {
        std::cout << num << " ";
    }
}

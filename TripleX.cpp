#include <iostream>

bool playGame(int difficulty, bool didFail) 
{
    int a = rand() % difficulty + 1;
    int b = rand() % difficulty + 1;
    int c = rand() % difficulty + 1; 

    int sum = a + b + c;
    int product = a * b * c; 

    std::cout << std::endl;
    std::cout << "+ This is a 3 number combo lock.";
    std::cout << "+ The 3 numbers add up to, " << sum << std::endl;
    std::cout << "+ The 3 numbers multiply to " << product << std::endl;
    std::cout << "+ Please enter your answers seperated by a space."<< std::endl;

    int guessA, guessB, guessC; 

    std::cin >> guessA >> guessB >> guessC; 
    std::cout << "You entered: " << guessA << guessB << guessC << std::endl; 

    if (guessA + guessB + guessC == sum && guessA * guessB * guessC == product) {
        return true; 
    }
    return false;
}


int main() 
{
    std::cout << "You are a lock smith that needs to break a lock that your client forgot the passcode for." << std::endl;
    std::cout << "You need to enter the passcode to proceed."<< std::endl;

    int difficulty = 2; 
    const int MAX_DIFFICULTY = 10; 
    bool didFail = false; 

    while (difficulty < MAX_DIFFICULTY) {
        didFail = playGame(difficulty, didFail); 
        if (!didFail) {
            std::cout << "You've guess wrong! The client is pissed." << std::endl;
            std::cout << "Game over.";
            break;
        }
        ++difficulty;
    }

    return 0; 
}
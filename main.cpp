#include <iostream>
#include <vector>
#include <random>

std::string upper(std::string& text) {
    //std::string uppertext;
    for (auto& c : text) {
        c = toupper(c);
    }

    return text;
}

int main() {
    std::vector<std::vector<std::string>> questions = {
      {"What is 1+1?", "2", "exact"},
      {"What is 2+2?", "4", "exact"},
      {"What is 3+3?", "6", "exact"},
      {"What is 4+4?", "8", "exact"},
      {"What is the role of non-coding DNA?", "to switch genes on and off (so that they can or cannot make specific proteins)", "judge"},
      {"Explain the pathway of the nervous system", "Stimula --> Receptor --> Sensory Neurones --> Relay Neurones --> CNS --> Relay Neurones --> Moto Neurones --> Effector --> Response", "judge"}
    };
    std::string answer;
    std::cout << "\n\n---Welcome to flashCarLI!---\n\n";

    
    while (1 == 1) {

      // Generate a random number between 1 and the length of questions
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<> distrib(0, questions.size() - 1);
      int randomNumber = distrib(gen);

      // std::cout << "Random Number: " << randomNumber << std::endl; // Testing purposes

      std::cout << questions[randomNumber][0] << std::endl;
      std::cin >> answer;

    
      if (questions[randomNumber][2] == "exact") {
	if (upper(answer) == upper(questions[randomNumber][1])) {
	  std::cout << "Correct!" << std::endl;
	}
      }
    
      if (questions[randomNumber][2] == "judge") {
	std::cout << "The answer was " << questions[randomNumber][1] << std::endl;
      
      }
    }
    
    return 0;
}

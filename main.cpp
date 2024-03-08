#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <string>
#include <sstream>
#include "main.h"

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
      std::string rating = "";

     
      
      // Generate a random number between 1 and the length of questions
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<> distrib(0, questions.size() - 1);
      int randomNumber = distrib(gen);

      if (readFileToArray("rating.txt")[randomNumber] == "G") {
	std::cout << "You previously did well on this" << std::endl;
      }
      
      // std::cout << "Random Number: " << randomNumber << std::endl; // Testing purposes
      
      std::cout << questions[randomNumber][0] << std::endl;
      std::cin >> answer;

      if (answer.substr(0, 1) == ":") {
	std::cout << "Commands not currently working" << std::endl;
      }
      else if (questions[randomNumber][2] == "exact") {
	if (upper(answer) == upper(questions[randomNumber][1])) {
	  std::cout << "Correct!" << std::endl;
	}
      }
    
      else if (questions[randomNumber][2] == "judge") {
	std::cout << "The answer was " << questions[randomNumber][1] << std::endl;
	std::cout << "Rate how you did (Red/Amber/Green)(R/A/G): " << std::endl;
	std::cin >> rating;

	if (upper(rating) == "Green" || upper(rating) == "G") {
	  //std::cout << "Green Read" << std::endl;
	  writeStringToLine("rating.txt","G",randomNumber); 
	}
	if (upper(rating) == "AMBER" || upper(rating) == "A") {
	  //std::cout << "Amber Read" << std::endl;
	  writeStringToLine("rating.txt","A",randomNumber);
	}
	if (upper(rating) == "RED" || upper(rating) == "R") {
	  //std::cout << "Red Read" << std::endl;
	  writeStringToLine("rating.txt","R",randomNumber);
	}
      }
    }
    
    return 0;
}

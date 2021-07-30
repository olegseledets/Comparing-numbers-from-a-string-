#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

bool checkCorrectDot(std::string number) {
  return (number[0] != '.' || number[number.size()-1] != '.') ? ((count(number.begin(),number.end(), '.') > 1) ? false : true) : false;
}

bool checkSymbol (char symbol) {
  return ((symbol >= '0' && symbol <= '9') || symbol == '.');
}

std::string removeZeros (std::string number) {        
  int correctPosition = 0;
  int i = 0;
  bool minus = false;
  if (number[0] == '-') {
    minus = true;
    i = 1;
  }
  for ( ; i < number.size() ; ++i) {
    if (number[i] == '0') {
      correctPosition++;
    } else if (i >= 0 && number[i] != '0') {
      return (minus) ? '-' + number.substr(correctPosition + 1) : number.substr(correctPosition);
    }
  }
  return number;
}

std::string findSecondSide(std::string number) {
  return (count(number.begin(), number.end(), '.')) ? number.substr(number.find('.') + 1) : "0"; 
}

std::string findFirstSide(std::string number){
    return number.substr(0, number.find('.')); 
}

bool checkCorrectNumber(std::string number) {
  if (checkCorrectDot(number)) {
    for (int i = 0; i < number.size(); ++i) {
      if( i == 0 && number[i] == '-') continue;
      if (!checkSymbol(number[i])) {
        return false;
      }
    }
    return true;
  }
  return false;
}

std::string compareSide(std::string leftSideOne, std::string leftSideTwo, std::string rightSideOne, std::string rightSideTwo, std::string resultOne, std::string resultTwo) {
  if (leftSideOne.size() > leftSideTwo.size()) {    
    return resultOne; 
  } else if (leftSideTwo.size() > leftSideOne.size()) {
    return resultTwo;
  } else {
    for (int i = 0; i < leftSideOne.size(); ++i) {
      if ((leftSideOne[i] - '0') > (leftSideTwo[i] - '0')) {
        return resultOne;
      } else if ((leftSideOne[i] - '0') < (leftSideTwo[i] - '0')) {
        return resultTwo;
      }
    }
  }
  int maxSecondSize = (rightSideOne.size() >= rightSideTwo.size()) ? rightSideOne.size() : rightSideTwo.size();
  for (int i = 0; i < maxSecondSize; ++i) {
    if((rightSideOne[i] == '\0') || (rightSideTwo[i] == '\0')){
      break;
    } else if ((rightSideOne[i] - '0') > (rightSideTwo[i] - '0')) {
      return resultOne;
    } else if ((rightSideOne[i] - '0') < (rightSideTwo[i] - '0')) {
      return resultTwo;
    }
  }
  return "Equal";
}

std::string comparisonNumber(std::string numberOne, std::string numberTwo) {
  std::string oneFirstSide = findFirstSide(removeZeros(numberOne));
  std::string oneSecondSide = findSecondSide(removeZeros(numberOne));
  std::string twoFirstSide = findFirstSide(removeZeros(numberTwo));
  std::string twoSecondSide = findSecondSide(removeZeros(numberTwo));
  if((numberOne == "0" && numberTwo == "-0") || (numberOne == "-0" && numberTwo == "0")){
    return "Equal";
  }else if(oneFirstSide[0] == '-' && twoFirstSide[0] != '-') {
    return "Less";
  } else if (oneFirstSide[0] != '-' && twoFirstSide[0] == '-') {
    return "More";
  } else if (oneFirstSide[0] != '-' && twoFirstSide[0] != '-') {
    return compareSide(oneFirstSide, twoFirstSide, oneSecondSide, twoSecondSide, "More", "Less");
  } else {
    return compareSide(oneFirstSide, twoFirstSide, oneSecondSide, twoSecondSide, "Less", "More");
  }
  return "Equal";
}

void test() {
  std::vector<std::string> numberOne =  {
                                        "0",                    // Equal
                                        "12345.12345",          // Equal
                                        "6.12",                 // Less
                                        "123.56",               // More
                                        "-6.12",                // More
                                        "-1.013",               // Less
                                        "-000012.4",            // More
                                        "00017523.0023",        // Equal
                                        "00000000008.000000007" // Less
                                        };
  std::vector<std::string> numberTwo =  {
                                        "0",
                                        "12345.12345",
                                        "9.12",
                                        "12.356",
                                        "-9.12",
                                        "-0.013",
                                        "-044.04",
                                        "017523.00230000",
                                        "00000000008.000000008"
                                        };
  for (int i = 0; i < numberOne.size(); ++i) {
    std::cout << ((checkCorrectNumber(numberOne[i]) && checkCorrectNumber(numberTwo[i])) ? comparisonNumber(numberOne[i], numberTwo[i]) : "Uncorrect");
    std::cout << std::endl;
  }
}

int main() {
  //test();
  std::string numberOne, numberTwo;
  std::cout << "Number 1: ";
  std::getline(std::cin, numberOne);
  std::cout << "Number 2: ";
  std::getline(std::cin, numberTwo);
  std::cout << ((checkCorrectNumber(numberOne) && checkCorrectNumber(numberTwo)) ? comparisonNumber(numberOne, numberTwo) : "Uncorrect");
}

/*
Вы продолжаете писать калькулятор, работающий над вещественными числами повышенной точности. Вы уже научились проверять корректность записи вещественных чисел в виде строк, и теперь перед вами новая цель — научиться сравнивать такие вещественные числа.
Пользователь вводит две строки, задающие вещественные числа, в том же формате, как было описано в задаче «Длинное вещественное число». Программа должна проверить корректность ввода (для этого можно переиспользовать код, написанный в задаче «Длинное вещественное число»), после чего вывести слово Less, если первое число строго меньше второго; слово More, если первое число строго больше второго; и слово Equal, если введённые числа равны.
  Ввод: 2.39 3.61
  Ответ: Less
Ввод: 0123 12.3
Ответ: More
  Ввод: 12345678 12345678.00
  Ответ: Equal
Ввод: -1.0 1.0
Ответ: Less
*/
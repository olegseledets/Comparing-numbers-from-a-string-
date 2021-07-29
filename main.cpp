#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

bool checkCorrectDot(std::string number) {
  if (number[0] != '.' && number[number.size()-1] != '.')
    return (count(number.begin(),number.end(), '.') > 1) ? false : true;
  return false;
}

bool checkSymbol (char symbol) {
  return ((symbol >= '0' && symbol <= '9') || symbol == '.');
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

std::string comparisonNumber(std::string numberOne, std::string numberTwo) {
  if (stod(numberOne) == stod(numberTwo)) {
    return "Equal";
  } else if (stod(numberOne) > stod(numberTwo)) {
    return "More";
  } else {
    return "Less";
  }  
}

int main() {
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
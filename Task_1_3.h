#ifndef LR_4_TASK_1_3_H
#define LR_4_TASK_1_3_H
#include <array>
#include <exception>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

bool task_1_2() {
  cout << "Выберите тип исключения: " << endl;
  cout << "out_of_range - 1, \nlength_error - 2, \ninvalid_argument - 3, "
          "\nbad_cast - 4, \nbad_alloc - 5\n";
  int k;
  cin >> k;
  switch (k) {

    // std::out_of_range  - выход за границы диапазона.
  case 1:
    try {
      int N = 5;
      std::array<int, 5> arr{1, 2, 3, 4, 5};
      arr.at(7);

    } catch (std::out_of_range &d) {
      cout << d.what() << " - error type std::out_of_range" << endl;
      return true; // выходим сразу же из программы
    }

    // std::length_error - неверная длина
  case 2:
    try {
      std::string s;
      s.reserve(-10);

    } catch (std::length_error &d) {
      cout << d.what() << " - error type std::length_error" << endl;
      return true;
    }
    break;

    // std::invalid_argument - неверный аргумент (std::string в bitset)
  case 3:
    try {
      std::bitset<32> bitset(std::string("11001010101100001b100101010110000"));
    } catch (std::invalid_argument &d) {
      cout << d.what() << " - error type std::invalid_argument" << endl;
      return true;
    }
    break;

    // std::bad_cast - отсутствует наследование.
  case 4:

    try {
      struct bad1 {
        virtual ~bad1() = default;
      };
      struct bad2 {
        virtual ~bad2() = default;
      };
      bad1 b;
      bad2 &f = dynamic_cast<bad2 &>(b);
    } catch (std::bad_cast &d) {
      cout << d.what() << " - error type std::bad_cast" << endl;
      return true;
    }
    break;

    // std::bad_alloc - выделение памяти через new
    // тут небольшая проблема с компилятором у мака -
    // https://sun9-20.userapi.com/c206716/v206716697/e6fce/MIlJfuvBKds.jpg
  case 5:

    std::vector<int *> vec;
    try {
      while (true) {
        vec.push_back(new int[10000000ul]);
      }

    } catch (std::bad_alloc &d) {
      cout << d.what() << " - error type std::bad_alloc" << endl;
      for (auto a : vec)
        delete[] a;
      return true;
    }
  }
  return false;
}
#endif // LR_4_TASK_1_3_H

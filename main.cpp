#include "Task_1_2.h"
#include "Task_3_4.h"
#include <array>
#include <exception>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main() {
  if (!task_1_2())
    cout << "Программа не завершилась после того, как выкинула "
            "исключение";
  else
    cout << "Программа завершилась после того, как выкинула "
            "исключение";


}
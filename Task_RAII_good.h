#ifndef LR_4_TASK_RAII_GOOD_H
#define LR_4_TASK_RAII_GOOD_H

#include <exception>
void RAII_good() {
  int *a = new int[100]; // сразу иниализируем
  try {
    int k = -15;
    if (k < 0)
      throw std::exception();
  } catch (std::exception &d) {
    cout << "Error" << endl;
  }
  delete[] a; // очищаем при выходе из области видимости
}

#endif // LR_4_TASK_RAII_GOOD_H

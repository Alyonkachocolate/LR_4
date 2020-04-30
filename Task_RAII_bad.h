#ifndef LR_4_TASK_RAII_BAD_H
#define LR_4_TASK_RAII_BAD_H

#include <exception>
void RAII_bad() {
  try {
    int k = -15;
    int *a = new int[100];
    if (k < 0)
      throw std::exception();
    delete[] a;
  } catch (std::exception &d) {
    cout << "Error_bad" << endl;
  }
}

#endif // LR_4_TASK_RAII_BAD_H

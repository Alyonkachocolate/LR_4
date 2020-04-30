#include "Task_1_3.h"
#include "Task_4_5.h"
#include "Task_RAII_bad.h"
#include "Task_RAII_good.h"

int main() {
  // task_1_3 - обработка стандартных исключений
  if (!task_1_2())
    cout << "Программа не завершилась после того, как выкинула "
            "исключение"
         << endl;
  else
    cout << "Программа завершилась после того, как выкинула "
            "исключение"
         << endl;

  // task_4_5 - реализация собственного класса-исключения
  cout << "Matrix: ввод - rows, cols, det. Ошибки если rows,cols<0 или "
          "det==0"
       << endl;

  cout << "C нормальными значениями." << endl;
  if (!Matrix()) // false - если дошла до конца
    cout << "Программа завершилась и не выкинула "
            "исключение"
         << endl;
  cout << endl;

  cout << "С отрицательными rows или cols" << endl;
  if (!Matrix())
    cout << "Программа завершилась после того, как выкинула "
            "исключение"
         << endl;
  cout << endl;

  cout << "C отрицательными обоими rows и cols" << endl;
  if (!Matrix())
    cout << "Программа завершилась после того, как выкинула "
            "исключение"
         << endl;
  cout << endl;

  cout << "C определитлем равным 0" << endl;
  if (!Matrix())
    cout << "Программа завершилась после того, как выкинула "
            "исключение"
         << endl;
  cout << endl;

  // task_RAII
  RAII_bad();
  RAII_good();
}
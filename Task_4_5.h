#ifndef LR_4_TASC_3_4_H
#define LR_4_TASC_3_4_H

class error_matrix : public std::exception {
private:
  int rows_ = 0;
  int cols_ = 0;

public:
  explicit error_matrix (int rows, int cols) : rows_(rows), cols_(cols),
      std::exception
  () {}
  std::string get_error() {
    if (rows_<0 && cols_>=0) return (". Rows is negative");
    if (rows_>=0 && cols_<0) return (". Cols is negative");
    return (". Rows and cols is negative");
  }
};

bool Matrix() {
  cout << "rows = ";
  int rows;
  cin >> rows;
  cout << "cols = ";
  int cols;
  cin >> cols;
  cout << "det = ";
  size_t det;
  cin >> det;
try {
    if (rows < 0 || cols < 0)
      throw error_matrix(rows, cols);
    if (det==0) throw std::invalid_argument("Invalid_argument: det == 0");
  }
catch (std::invalid_argument &d){
  cout << d.what() << endl;
  return true;
}

catch (error_matrix &d){
  cout << d.what() << d.get_error() << endl;
  return true;
}

return false;
}





#endif // LR_4_TASC_3_4_H

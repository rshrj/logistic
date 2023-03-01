#include <iostream>
#include <fstream>
#include <random>

double M(double x, double r) {
  return r * x * (1 - x);
}

int main(int argc, char** argv) {
  using namespace std;

  const size_t numX = 1000;
  const size_t numr = 1000;
  const int T = 1000;

  std::random_device rd;
  std::mt19937 e2(rd());
  std::uniform_real_distribution<> dist(0, 1);

  if (argc != 2) {
    cerr << "Expected an output file" << "\n";
    return(EXIT_FAILURE);
  }

  string outfile = argv[1];
  ofstream fout(outfile);

  for (size_t k = 0; k < numX; ++k) {
    // random initial condition between 0 and 1
    double x0 = dist(e2);

    for (double r = 0.0; r <= 4.0; r += (4.0/numr)) {
      
      // start at the initial condition
      double x = x0;

      // find the orbit
      for (size_t i = 0; i <= T; ++i) {
        x = M(x, r);
      }

      // print the landing point
      fout << r << "    " << x << endl;
    }

    // update the progress display
    cout << "\r[";
    for (size_t m = 0; m < k * 100 / numX; ++m) {
      cout << ".";
    }
    cout << "]";
  }

  cout << endl << "Written to " << outfile << endl;

  return(EXIT_SUCCESS);
}
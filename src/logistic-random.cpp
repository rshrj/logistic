#include <iostream>
#include <fstream>
#include <random>

double M(double x, double r) {
  return r * x * (1 - x);
}

int main(int argc, char** argv) {
  using namespace std;

  const size_t numX = 10000;
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

  for (size_t k = 0; k < (numX * numr); ++k) {
    // random initial condition between 0 and 1
    double x = dist(e2);
    double r = 4.0 * dist(e2);

    // find the orbit
    for (size_t i = 0; i <= T; ++i) {
      x = M(x, r);
    }

    // print the landing point
    fout << r << "    " << x << endl;

    // update the progress display
    if ((k * 50 * 10) % (numX * numr) == 0) {
      cout << "\r[";
      for (size_t m = 0; m < k * 50 / (numX * numr); ++m) {
        cout << ".";
      }
      cout << "]";
    }
  }

  cout << endl << "Written to " << outfile << endl;

  return(EXIT_SUCCESS);
}
#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <vector>

std::random_device rand_dev;
std::mt19937 generator(rand_dev());

double dist(double x, double y, double xa, double ya) {
  return std::sqrt((x - xa) * (x - xa) + (y - ya) * (y - ya));
}

double GetAnsWithBigZone(std::vector<double>& data, size_t n) {
  double x1 = data[0], y1 = data[1], r1 = data[2];
  double x2 = data[3], y2 = data[4], r2 = data[5];
  double x3 = data[6], y3 = data[7], r3 = data[8];

  double xmax = std::max(x1 + r1, std::max(x2 + r2, x3 + r3));
  double xmin = std::min(x1 - r1, std::min(x2 - r2, x3 - r3));
  double ymax = std::max(y1 + r1, std::max(y2 + r2, y3 + r3));
  double ymin = std::min(y1 - r1, std::min(y2 - r2, y3 - r3));

  std::uniform_real_distribution<> xdistr(xmin, xmax);
  std::uniform_real_distribution<> ydistr(ymin, ymax);

  size_t k = n;

  size_t yes = 0;

  for (size_t t = 0; t < k; ++t) {
    double x = xdistr(generator);
    double y = ydistr(generator);

    if (dist(x, y, x1, y1) <= r1 && dist(x, y, x2, y2) <= r2 && dist(x, y, x3, y3) <= r3) {
      ++yes;
    }
  }

  return (static_cast<double>(yes) / k) * ((xmax - xmin) * (ymax - ymin));
}

double GetAnsWithSmallZone(std::vector<double>& data, size_t n) {
  double x1 = data[0], y1 = data[1], r1 = data[2];
  double x2 = data[3], y2 = data[4], r2 = data[5];
  double x3 = data[6], y3 = data[7], r3 = data[8];

  double xmax = std::min(x1 + r1, std::min(x2 + r2, x3 + r3));
  double xmin = std::max(x1 - r1, std::max(x2 - r2, x3 - r3));
  double ymax = std::min(y1 + r1, std::min(y2 + r2, y3 + r3));
  double ymin = std::max(y1 - r1, std::max(y2 - r2, y3 - r3));

  std::uniform_real_distribution<> xdistr(xmin, xmax);
  std::uniform_real_distribution<> ydistr(ymin, ymax);

  size_t k = n;

  size_t yes = 0;

  for (size_t t = 0; t < k; ++t) {
    double x = xdistr(generator);
    double y = ydistr(generator);

    if (dist(x, y, x1, y1) <= r1 && dist(x, y, x2, y2) <= r2 && dist(x, y, x3, y3) <= r3) {
      ++yes;
    }
  }

  return (static_cast<double>(yes) / k) * ((xmax - xmin) * (ymax - ymin));
}

int main() {
  std::ofstream outf1("resultData1.txt");
  std::ofstream outf2("resultData2.txt");

  std::vector<double> data1 = { 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0 };
  std::vector<double> data2 = { 0.3, 0.3, 1, 0.3, 0.3, 0.8, 0.3, 0.3, 0.9 };

  for (size_t n = 100; n <= 100000; n += 500) {
    double apr_ans_b_1 = GetAnsWithBigZone(data1, n);
    double apr_ans_s_1 = GetAnsWithSmallZone(data1, n);
    double apr_ans_b_2 = GetAnsWithBigZone(data2, n);
    double apr_ans_s_2 = GetAnsWithSmallZone(data2, n);

    outf1 << n << ' ' << apr_ans_b_1 << ' ' << apr_ans_s_1 << '\n';
    outf2 << n << ' ' << apr_ans_b_2 << ' ' << apr_ans_s_2 << '\n';
  }
}

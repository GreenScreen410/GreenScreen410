#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
  long double x, y;
};

long double polygon_size(vector<Point> points) {
  long double size = 0;
  for (int i = 1; i < points.size() - 1; i++) {
    long double x1 = points[0].x, y1 = points[0].y;
  	long double x2 = points[i].x, y2 = points[i].y;
  	long double x3 = points[i + 1].x, y3 = points[i + 1].y;
  	size += (x3 - x1) * (y2 - y1) - (x2 - x1) * (y3 - y1);
  }
  return size / 2;
}

int main() {
  int N;
  cin >> N;
  
  vector<Point> points(N);
  for (int i = 0; i < N; i++) {
    cin >> points[i].x >> points[i].y;
  }
  
  cout.precision(1);
  cout << fixed;
  cout << abs(polygon_size(points));
  
  return 0;
}
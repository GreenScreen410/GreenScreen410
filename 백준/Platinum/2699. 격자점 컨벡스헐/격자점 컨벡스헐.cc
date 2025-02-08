#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
  long long x, y;
};
vector<Point> points;

long long ccw(Point a, Point b, Point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

bool compare_y(Point a, Point b) {
  if (a.y == b.y) return a.x < b.x;
  else return a.y > b.y;
}

bool compare_ccw(Point a, Point b) {
  long long value = ccw(points[0], a, b);
  if (value == 0) {
    if (a.y == b.y) return a.x < b.x;
    return a.y > b.y;
  }
  return value < 0;
}

int main() {
  int P;
  cin >> P;
  
  while (P--) {
    int N;
    cin >> N;
  
    points.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end(), compare_y);
    sort(points.begin() + 1, points.end(), compare_ccw);
  
    vector<Point> convex_hull;
    convex_hull.push_back(points[0]);
    convex_hull.push_back(points[1]);
  
    for (int i = 2; i < N; i++) {
      while (convex_hull.size() >= 2) {
        Point b = convex_hull.back();
        convex_hull.pop_back();
        Point a = convex_hull.back();
        if (ccw(points[i], a, b) < 0) {
          convex_hull.push_back(b);
          break;
        }
      }
      convex_hull.push_back(points[i]);
    }
  
    cout << convex_hull.size() << "\n";
    for (int i = 0; i < convex_hull.size(); i++) {
      cout << convex_hull[i].x << " " << convex_hull[i].y << "\n";
    }
  }
  

  return 0;
}
#ifndef _TSP_H_
#define _TSP_H_

#include <utility>
#include <vector>
#include <map>

class TSP {
public:
  TSP();
  void print();
  double getValue(int x, int y) const;
  void addRow(int x, int y, double value);
  void findAnyCycle();
  void findGoodCycle();
private:
  std::map<std::pair<int, int>, double> mList;
  std::vector<int> mVistedNodes;
  int mNodeCount;
  double mMinWeight;
  double mMaxWeight;
};

#endif // _TSP_H_


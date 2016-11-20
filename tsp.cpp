#include <iostream>
#include <utility>
#include "tsp.h"

TSP::TSP() : mNodeCount(0), mMinWeight(0), mMaxWeight(0) {}

void TSP::print() {
  for (auto && i: mList) {
    std::cout << i.first.first << ", " << i.first.second << ", " << i.second << std::endl;
  }
  std::cout << "n: " << mNodeCount << std::endl;
  std::cout << "Minimum Possible Weight: " << mMinWeight * mNodeCount << std::endl;
  std::cout << "Maximum Possible Weight: " << mMaxWeight * mNodeCount << std::endl;
}

double TSP::getValue(int x, int y) const {
  return mList.find(std::make_pair(x, y))->second;
}

void TSP::addRow(int x, int y, double value) {
  if (mList.size() == 0) {
    mNodeCount = x;
    mMinWeight = value;
    mMaxWeight = value;
  }

  if (x > mNodeCount) {
    mNodeCount = x;
  }

  if (value < mMinWeight) {
    mMinWeight = value;
  }

  if (value > mMaxWeight) {
    mMaxWeight = value;
  }

  mList.insert(std::make_pair(std::make_pair(x, y), value));
}

void TSP::findAnyCycle() {
  double totalWeight = 0;
  mVistedNodes.push_back(1);
  std::cout << "1 ";
  for (auto && i: mList) {
    if (std::find(mVistedNodes.begin(), mVistedNodes.end(), i.first.first) == mVistedNodes.end()) {
      mVistedNodes.push_back(i.first.first);
      std::cout << i.first.first << " ";
      totalWeight += getValue(i.first.first, mVistedNodes[mVistedNodes.size() - 2]);
    }
  }
  totalWeight += getValue(mNodeCount, 1);
  double quality = 1 - (totalWeight - (mMinWeight * mNodeCount)) / ((mMaxWeight * mNodeCount) - (mMinWeight * mNodeCount));
  std::cout << totalWeight << " " << quality << std::endl;
}


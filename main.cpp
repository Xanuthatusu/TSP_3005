#include <iostream>
#include <utility>
#include "tsp.h"

int main(int argc, char *argv[]) {
  TSP tsp;

  int v_one, v_two;
  double weight;
  while(std::cin >> v_one >> v_two >> weight) {
    tsp.addRow(v_one, v_two, weight);
  }

  //tsp.findAnyCycle();
  tsp.findGoodCycle();
}


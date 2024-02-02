#ifndef EVALLUATOR_H
#define EVALLUATOR_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Evaluator {
public:
  Evaluator(const vector<vector<string>> &program);
  void evaluate(unordered_map<string, int> &env);

private:
  vector<vector<string>> program;
};

#endif // EVALLUATOR_H

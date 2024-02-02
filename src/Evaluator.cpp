#include "Evaluator.h"
#include <iostream>
#include <unordered_map>

using namespace std;

Evaluator::Evaluator(const vector<vector<string>> &program)
    : program(program) {}

void Evaluator::evaluate(unordered_map<string, int> &env) {
  for (const auto &line : program) {
    if (line.empty())
      continue;
    if (line[0] == "let") {
      env[line[1]] = stoi(line[2]);
    } else if (line[0] == "print") {
      cout << env.at(line[1]) << endl;
    }
  }
}

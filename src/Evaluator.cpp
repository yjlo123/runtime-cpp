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
    string cmd = line[0];
    if (cmd == "let") {
      env[line[1]] = stoi(line[2]);
    } else if (cmd == "add") {
      // TODO
      env[line[1]] = stoi(line[3]);
    } else if (cmd == "prt") {
      string content = line[1];
      if (content[0] == '$') {
        cout << env.at(content.substr(1)) << endl;
      } else {
        cout << content << endl;
      }
    }
  }
}

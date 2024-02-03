#include "Evaluator.h"
#include "Tokenizer.h"
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, int> env;

  string filename = "example.runtime";
  ifstream inputFile(filename);

  if (!inputFile.is_open()) {
    cout << "Could not open file: " << filename << endl;
    return 1;
  }

  string fileContent((istreambuf_iterator<char>(inputFile)),
                     istreambuf_iterator<char>());

  inputFile.close();

  Tokenizer tokenizer(fileContent);
  vector<vector<string>> tokens = tokenizer.tokenize();

  cout << "===Tokens===" << endl;
  for (const auto &tokenLine : tokens) {
    for (const auto &token : tokenLine) {
      cout << token << " | ";
    }
    cout << endl;
  }
  cout << "============" << endl;

  Evaluator evaluator(tokens);
  evaluator.evaluate(env);

  cout << "===env===" << endl;
  for (const auto &pair : env) {
    cout << pair.first << " : " << pair.second << endl;
  }
  cout << "=========" << endl;
  return 0;
}

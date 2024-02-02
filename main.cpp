#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

void interpret(string instruction, unordered_map<string, int>& registers) {
  istringstream iss(instruction);
  string operation, operand;
  iss >> operation;

  if (operation == "MOV") {
    iss >> operand;
    int value;
    if (iss >> value) {
      registers[operand] = value;
    } else {
      cout << "Invalid MOV instruction: " << instruction << endl;
    }
  } else if (operation == "ADD") {
    iss >> operand;
    int value;
    if (iss >> value) {
      registers[operand] += value;
    } else {
      cout << "Invalid ADD instruction: " << instruction << endl;
    }
  } else if (operation == "PRINT") {
    iss >> operand;
    if (registers.find(operand) != registers.end()) {
      cout << operand << ":" << registers[operand] << endl;
    } else {
      cout << "Invalid PRINT instruction: " << instruction << endl;
    }
  } else {
    cout << "Unknown instruction: " << instruction << endl;
  }
}

int main() {
  //std::cout << "123" << std::endl;

  unordered_map<string, int> registers;

  registers["A"] = 0;
  registers["B"] = 0;

  interpret("MOV A 10", registers);
  interpret("ADD A 5", registers);
  interpret("PRINT A", registers);

  // string instruction;
  // cin >> instruction;
  return 0;
}

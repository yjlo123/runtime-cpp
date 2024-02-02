#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

class Tokenizer {
public:
  Tokenizer(const std::string &src);
  std::vector<std::vector<std::string>> tokenize();

private:
  std::string src;
};

#endif // TOKENIZER_H

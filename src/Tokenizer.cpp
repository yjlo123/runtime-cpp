#include "Tokenizer.h"

using namespace std;

Tokenizer::Tokenizer(const string &src) : src(src) {}

vector<vector<string>> Tokenizer::tokenize() {
  vector<vector<string>> tokens;
  vector<string> line;
  string token;

  for (size_t i = 0; i < src.length(); ++i) {
    char c = src[i];

    if (c == '\n' || c == ' ') {
      // end of a token
      if (!token.empty()) {
        line.push_back(token);
      }
      token.clear();
      // end of a line
      if (c == '\n') {
        tokens.push_back(line);
        line.clear();
      }
    } else if (c == '\'') {
      // string
      char quote = c;
      token += src[i];
      ++i;
      while (true) {
        if (i == src.length() || src[i] == '\n') {
          throw runtime_error("Unterminated string: " + token);
        }
        if (src[i] == '\\') {
          ++i;
          if (i == src.length()) {
            throw runtime_error("Unterminated string escape: " + token);
          }
          if (src[i] == 'n') {
            token += '\n';
          } else if (src[i] == 'b') {
            token += '\b';
          } else if (src[i] == 't') {
            token += '\t';
          } else if (src[i] == '\'') {
            token += '\'';
          } else {
            token += src.substr(i - 1, 2);
          }
          ++i;
          continue;
        }

        if (src[i] == quote) {
          break;
        }
        token += src[i];
        ++i;
      }
      token += src[i];
    } else if (c == '/') {
      while (true) {
        if (i == src.length() || src[i] == '\n') {
          --i; // to trigger newline in the next iteration
          break;
        }
        ++i;
      }
    } else {
      token += c;
    }
  }

  if (!token.empty()) {
    line.push_back(token);
  }
  if (!line.empty()) {
    tokens.push_back(line);
  }

  return tokens;
}

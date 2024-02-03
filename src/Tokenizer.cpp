#include "Tokenizer.h"
#include <stdexcept>

using namespace std;

Tokenizer::Tokenizer(const string &src) : src(src) {}

vector<vector<string>> Tokenizer::tokenize() {
  vector<vector<string>> tokens;
  string token;

  tokens.push_back(vector<string>());

  for (size_t i = 0; i < src.length(); ++i) {
    char c = src[i];

    if (c == '\n' || c == '\r' || c == ' ') {
      // end of a token
      if (!token.empty()) {
        tokens.back().push_back(token);
      }
      
      // end of a line
      if (c == '\n') {
        tokens.push_back(vector<string>());
      }

      token = "";
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
    tokens.back().push_back(token);
  }
  if (tokens.back().empty()) {
    tokens.pop_back();
  }

  return tokens;
}

#include <fstream>
#include <string>
using namespace std;
int main(int argc, char const *argv[]) {
  fstream newsnippets;
  fstream codetemplate;
  newsnippets.open("snippets.json", ios::out);
  for (int i = 1; i < argc; i++) {
    codetemplate.open(argv[i], ios::in);
    string line;
    newsnippets << "\"\": {\n  \"prefix\": \"\",\n  \"body\": [" << endl;
    while (getline(codetemplate, line)) {
      while (line.find("\\") != string::npos)
        line.replace(line.find("\\"), 1, "&&&");
      while (line.find("&&&") != string::npos)
        line.replace(line.find("&&&"), 3, "\\\\");
      while (line.find("\"") != string::npos)
        line.replace(line.find("\""), 1, "$$$");
      while (line.find("$$$") != string::npos)
        line.replace(line.find("$$$"), 3, "\\\"");
      newsnippets << "    \"" << line << "\"," << endl;
    }
    newsnippets << "  ],\n  \"description\": \"\",\n}," << endl;
    codetemplate.close();
  }
  newsnippets.close();
  return 0;
}
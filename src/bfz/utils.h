#ifndef UTILS_H_
#define UTILS_H_

std::string inputFile(const std::string& filename);
void writeFile(const std::string& filename, std::string content);
void tokenize(std::string const &str, const char delim, std::vector<std::string> &out);
bool isNumber(const std::string& s);

#endif
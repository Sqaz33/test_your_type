#include "include/utils.hpp"

#include <algorithm>
#include <string>
#include <iterator>
#include <fstream>

namespace utils {

void loadText(const char* file, std::string& text) {
    std::fstream f(file);
    std::string buf;
    while (f) {
        f >> buf;
        text.append(buf);
        text.append(1, '\n');
    }
    f.close();
}

} // namespace utils
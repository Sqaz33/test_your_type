#include "include/text_load.hpp"

#include <algorithm>
#include <string>
#include <iterator>
#include <fstream>

namespace text_loader {

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

} // namespace text_load
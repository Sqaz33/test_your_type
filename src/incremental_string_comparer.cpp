#include "include/incremental_string_comparer.hpp"

#include <string>

namespace typo_checker {

IncrementalStringComparer::IncrementalStringComparer(const std::string& src) :
    src_(src)
{}

void IncrementalStringComparer::clear() {
    src_.clear();
    clearChecked();
}

void IncrementalStringComparer::clearChecked() {
    checked_.clear();
}

void IncrementalStringComparer::setSrc(const std::string& src) {
    clearChecked();
    index2Check_ = 0;
    src_ = src;
}

bool IncrementalStringComparer::pushLetter(char c) {
    checked_.append(1, c);
    return src_[index2Check_++] == c;
}

char IncrementalStringComparer::popLetter() {
    char back = checked_.back();
    checked_.erase(checked_.begin() + checked_.length() - 1);
    --index2Check_; 
    return back;
}

} // typo_checker
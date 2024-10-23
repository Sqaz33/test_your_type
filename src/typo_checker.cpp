#include "include/typo_checker.hpp"

#include <string>

namespace typo_checker {

TypoChecker::TypoChecker(const std::string& src) :
    src_(src)
{}

void TypoChecker::clear() {
    src_.clear();
    clearChecked();
}

void TypoChecker::clearChecked() {
    checked_.clear();
}

void TypoChecker::setSrc(const std::string& src) {
    clearChecked();
    index2Check_ = 0;
    src_ = src;
}

bool TypoChecker::pushLetter(char c) {
    checked_.append(1, c);
    return src_[index2Check_++] == c;
}

char TypoChecker::popLetter() {
    char back = checked_.back();
    checked_.erase(checked_.begin() + checked_.length() - 1);
    return back;
}

} // typo_checker
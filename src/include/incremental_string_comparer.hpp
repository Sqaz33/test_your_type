/**
 * @file typo_checker.hpp
 * @brief Файл содержит объявление класса IncrementalStringComparer. 
 * 
 * @author Матвеев С.А. mail: mset321@gmail.com
 */

#ifndef SRC_INCLUDE_TYPO_CHECKER
#define SRC_INCLUDE_TYPO_CHECKER

#include <string>

namespace typo_checker {

/**
 * @class TypoChecker
 * @brief Класс для сравнения строк.
 * 
 * Основные задачи класса:
 *  -
 */
class IncrementalStringComparer {
public:
    IncrementalStringComparer() = default; 
    IncrementalStringComparer(const std::string& src);
    
    void setSrc(const std::string& src);
    bool pushLetter(char c);
    char popLetter();

    void clear();
    void clearChecked();

    auto srcLength() const {
        return src_.length();
    }

    auto checkedLength() const {
        return checked_.length();
    }

    const auto& checked() const {
        return checked_;
    }
private:
    size_t index2Check_ = 0;
    std::string src_;
    std::string checked_;
};

} // typo_checker


#endif // SRC_INCLUDE_TYPO_CHECKER
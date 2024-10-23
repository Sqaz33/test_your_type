/**
 * @file typo_checker.hpp
 * @brief This file contains the declaration of the IncrementalStringComparer class.
 * 
 * @author Matveev S.A. email: mset321@gmail.com
 */

#ifndef INCREMENTAL_STRING_COMPARER
#define INCREMENTAL_STRING_COMPARER

#include <>

namespace incremental_string_comparer {

/**
 * @class IncrementalStringComparer
 * @brief A class for incremental string comparison.
 * 
 * @tparam String A string Class.
 * 
 * The main tasks of the class:
 *  - Compare the character passed to the pushLetter(c) method with the character 
 *    in the string passed to the constructor at a certain position (index). 
 *    Initially, index = 0. With each call to pushLetter(c), index 
 *    increments by 1.
 */
template <std::ranges::range_value_t String>
class IncrementalStringComparer {
public:
    /**
     * @brief Default constructor for IncrementalStringComparer.
     * 
     */
    IncrementalStringComparer() = default;

    /**
     * @brief Constructs a new IncrementalStringComparer object.
     * 
     * @param src The string to compare against.
     */
    IncrementalStringComparer(const String& src) :
        src_(src)
    {}
    
    /**
     * @brief Sets the string to compare against.
     * 
     * @param src The string to compare against.
     */
    void setSrc(const String& src) {
        clear();
        src_ = src;
    }

    /**
     * @brief Compares the input character with the character 
     *        in the string passed to the constructor at a certain index. 
     *        Initially, index = 0. With each call, the index increments by 1.
     * 
     * @tparam Char A class for char in String. 
     * @param c The character to compare.
     * @return true If the characters match.
     * @return false If the characters do not match or index 
     *         more than of the comparison string length.
     */
    template <class Char>
    bool pushLetter(Char c) {
        if (index2Check_ >= src_.length()) {
            ++index2Check_;
            return false;
        }
        return src_[index2Check_++] == c;
    }

    /**
     * @brief Decrements the index by 1.
     * 
     */
    void popLetter() {
        --index2Check_; 
    }

    /**
     * @brief Clears the string and resets the index to zero.
     * 
     */
    void clear() {
        index2Check_ = 0;
        src_.clear();
    }

    /**
     * @brief Returns the length of the comparison string.
     * 
     * @return auto The length of the comparison string.
     */
    auto srcLength() const {
        return src_.length();
    }

    /**
     * @brief Returns a reference to the comparison string.
     * 
     * @return const auto& A reference to the comparison string.
     */
    const auto& src() const {
        return src_;
    }

private:
    size_t index2Check_ = 0;
    String src_;
};

} // namespace incremental_string_comparer

#endif // INCREMENTAL_STRING_COMPARER

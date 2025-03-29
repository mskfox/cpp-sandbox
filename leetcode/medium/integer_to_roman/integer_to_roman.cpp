#include <string>
#include <vector>
#include <array>

class Solution {
private:
    // static lookup table for Roman numeral mappings
    static constexpr std::array<std::pair<int, const char*>, 13> ROMAN_MAPPINGS{{
        {1000, "M"},
        {900,  "CM"},
        {500,  "D"},
        {400,  "CD"},
        {100,  "C"},
        {90,   "XC"},
        {50,   "L"},
        {40,   "XL"},
        {10,   "X"},
        {9,    "IX"},
        {5,    "V"},
        {4,    "IV"},
        {1,    "I"}
    }};

public:
    /**
     * @brief Converts an integer to its Roman numeral representation
     * @param num Integer to convert (assumes 1 <= num <= 3999)
     * @return The Roman numeral representation as a string
     */
    std::string intToRoman(int num) const {
        std::string result;

        for (const auto& [value, symbol] : ROMAN_MAPPINGS) {
            while (num >= value) {
                result += symbol;
                num -= value;
            }

            if (num == 0) break;
        }

        return result;
    }
};
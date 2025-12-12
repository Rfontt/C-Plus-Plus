/**
 * @file
 * @brief Provides a function to reverse the digits of a 32-bit integer safely.
 *
 * This implementation reverses the digits of an integer while preventing
 * overflow by checking limits against INT32_MAX and INT32_MIN.
 *
 * @author [Rfontt](https://github.com/Rfontt)
 */

#include <iostream>
#include <limits>

/**
 * @brief Reverses the digits of a 32-bit signed integer.
 *
 * This function extracts digits one by one from the input integer and builds
 * the reversed number. Before each multiplication and addition, it checks
 * whether the operation would overflow a 32-bit signed integer. If an overflow
 * would occur, the function returns 0.
 *
 * @param number The integer whose digits will be reversed.
 * @return The reversed integer, or 0 if the reversal would overflow.
 */
int reverse(int number) {
    int32_t reversed = 0;

    while (number != 0) {
        int digit = number % 10;

        if (reversed > INT32_MAX / 10 || reversed < INT32_MIN / 10) {
            return 0;
        }

        reversed = reversed * 10 + digit;

        number = number / 10;
    }

    return reversed;
}

int main() {
    int reversed = reverse(123);

    std::cout << "Number reversed: " << reversed << "\n";
}

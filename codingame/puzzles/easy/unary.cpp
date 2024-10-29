// Puzzle: https://www.codingame.com/ide/puzzle/unary

#include <bitset>
#include <iostream>
#include <string>

/**
 * @brief Encodes a given message using unary encoding.
 *
 * This function takes a string message as input and converts it into a unary
 * encoded string.
 * Unary encoding is a simple form of encoding where each character is
 * represented by a sequence of bits.
 *
 * @param message The input string message to be encoded.
 * @return A unary encoded string representation of the input message.
 */
std::string encode_unary(const std::string &message) {
	std::string binary_string;
	for (const char c : message) { binary_string += std::bitset<7>(c).to_string(); }

	std::string encoded_message;
	char current_char = binary_string[0];
	int count = 0;

	for (const char bit : binary_string) {
		if (bit == current_char) { count++; }
		else {
			if (current_char == '1') { encoded_message += "0 "; }
			else { encoded_message += "00 "; }
			encoded_message += std::string(count, '0') + " ";
			current_char = bit;
			count = 1;
		}
	}

	if (current_char == '1') { encoded_message += "0 "; }
	else { encoded_message += "00 "; }
	encoded_message += std::string(count, '0');

	return encoded_message;
}

/**
 * @brief The program reads a message then prints the unary encoded message.
 */
int main() {
	std::string message;
	std::getline(std::cin, message);

	const std::string encoded_message = encode_unary(message);
	std::cout << encoded_message << std::endl;

	return 0;
}

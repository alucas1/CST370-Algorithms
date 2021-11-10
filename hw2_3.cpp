/* Title: hw2_3.cpp
 * Abstract: This program checks if an input string is a palindrome or not.
 *           Note that the empty string is considered a palindrome, as it is
 *           empty in either direction.
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 11/09/21
 */

#include <algorithm>
#include <iostream>
#include <string>

bool recPalindromeCheck(std::string, int, int);
std::string sanitizeString(std::string s);
bool isNotAlphaNum(char c);

int main()
{
	// Get Input
	std::string input = "";
    std::getline(std::cin, input);

    // Sanitize input
    input = sanitizeString(input);

    // Output result in all caps
    std::cout << (input.length() == 0 || recPalindromeCheck(input, 0, input.length() - 1) ? "TRUE" : "FALSE");

	return 0;
}

/*
 * Sanitizes string by removing non alphanumeric chars and making it upper case
 * @param  s       The string to be sanitized
 * @return string  A copy of the original string sanitized
 */
std::string sanitizeString(std::string s)
{
    // Remove all non alphanumeric chars
    s.erase(remove_if(s.begin(), s.end(), isNotAlphaNum), s.end());

    // Convert remaining chars to lowercase
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);

    return s;
}

/* Returns a bool indicating if the char is alphanumeric or not
 * @param  c     The char that will be analyzed
 * @return bool  A bool indicating if the char is alphanumeric
 */
bool isNotAlphaNum(char c) {
    return isalnum(c) == 0;
}

/*
 * Checks if a string is a palindrome - string must be sanitized first
 * Uses a recursive algorithm
 * @param  s        	The string to check
 * @param  firstChar	The position of the first char in the string
 * @param  lastChar     The position of the last char in the string
 * @return bool 	    Returns true if s is a palindrome, else false
 */
bool recPalindromeCheck(std::string s, int firstChar, int lastChar)
{
    // Base case if there is only one character left
    if (firstChar == lastChar)
        return true;

    // If first and last char do not match, it is not a palindrome
    if (s[firstChar] != s[lastChar])
        return false;

    // If there is more than one char, remove the first and last char
    // and check if that is a palindrome
    if (firstChar < lastChar + 1)
        return recPalindromeCheck(s, firstChar + 1, lastChar - 1);

    return true;
}
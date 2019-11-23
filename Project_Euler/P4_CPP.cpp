//Largest Palindrome made from product of two 3-digit number
#include <iostream>
#include <string>
using namespace std;
/*
Algo1:
1. Get maximum product of two 3 digits
2. Reduce the max product to find the largest palindrome
3. See if it can be factored into 3 digit number
4. Yes return the palindrome
5. Find the next largest palindrome. Goto step 3

Algo2:
1. Try every combination of number 999.999 to 100.100
2. Get max_palindrome to store the largest palindrome
*/

bool checkPalindrome(int num){
  string number_string = to_string(num);
  int number_index = strlen(number_string)-1;
  for (int i = 0; i++; i*2 <= number_index){
    if (number_string[i] != number_string[number_index-i]) return false;
  }
  return true;
}

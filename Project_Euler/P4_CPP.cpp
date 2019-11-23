//Largest Palindrome made from product of two 3-digit number
#include <iostream>
#include <string>
#include <string.h>
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

Algo3:
1. Try from the biggest product of 2 3 digits number 

Algo4:
1. Recursion?
*/

bool checkPalindrome(int num){
  string number_string = to_string(num);
  int number_index = strlen(number_string)-1;
  for (int i = 0; i++; i*2 <= number_index){
    if (number_string[i] != number_string[number_index-i]) return false;
  }
  return true;
}

long int findThePalindrome(int alpha, int beta){
  if (checkPalindrome(alpha*beta)) return alpha*beta;
  else{
    if (alpha == beta) {
      alpha = 999;beta -= 1;
      return findThePalindrome(alpha,beta);
    }
    else return findThe Palindrome(alpha-1,beta);
  }
}

int main(){
  cout << findThePalindrome(999,999);
  return 0;
}

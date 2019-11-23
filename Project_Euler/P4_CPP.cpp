//Largest Palindrome made from product of two 3-digit number
#include <iostream>
#include <math.h>
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

Algo5: Try from the biggest palindrome, find out if we can factor it into the product of two 3 digits number
*/
//Reference - useless
bool checkPalindrome(int num){
  string number_string = to_string(num);
  int number_index = strlen(number_string)-1;
  for (int i = 0;i*2 <= number_index ;i++ ){
    if (number_string[i] != number_string[number_index-i]) return false;
  }
  return true;
}

//Reference - useless
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
  //I test case-by-case
  //case 1 : palindrome with 6 digit => I got the correct answer luckily
	int palindrome = 999999; //maximum palindrome with 6 digits
  //when palindrome == 100001
	while(palindrome-100000!=1){
    //i is the divisor for palindrome
		for(int i=100;i<=sqrt(palindrome);i++){
			if (palindrome%i==0){
        //if the quotient has 3 digits
				if (palindrome/i < 1000) {
          //RESULT
          cout << palindrome << " : " << i << " X " << palindrome/i <<endl;
          return 0;
        }
      }
    }
    //990099 -> 989989 -> 988889
		if ((palindrome%1000)/100==0) {
      //900009 -> 899998 -> 898898 
			if ((palindrome%100)/10==0) palindrome -= 11;
			else palindrome -= 110;
		}
    //998899 -> 997799 -> 996699
		else palindrome -= 1100;
	}
	return 0;
}

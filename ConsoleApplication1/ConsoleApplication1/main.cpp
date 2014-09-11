#include <iostream>


int gcd(int num1, int num2){
	if(num2 == 0)
		return num1;
	else 
		return gcd(num2, num1 % num2);
}

int main()
{
	std::cout<<gcd(259,111)<<std::endl;
}



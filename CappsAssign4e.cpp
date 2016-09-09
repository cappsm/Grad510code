#include <iostream>


int main(){

	// Part 2: print out indices of "upper" cells in 3D array

	int n = 4; // size of the array

	std::cout << std::endl;
	std::cout << "Printing indices of upper cells of a " << n << "x" << n << "x"<<n<< " array:" << std::endl;	
	std::cout << "i j k" << std::endl;
	for(int i = n-1; i!=0; --i)
	{
		for(int j=n-1; j!=n-i-1; --j)
		{
			for(int k=n-1; k!= 2*(n-1)-i-j; --k)
			//for(int k=n-1; k!= n-i-j; --k)
			{
				std::cout << i << " "<< j << " " << k << std::endl;
			}
		}
	}

	return 0;
}
#include <iostream>

int main(){

	// Part 1: Print out indices on outside of an 8x8x8 cube
	
	std::cout << "Printing indices on outside of cube:" << std::endl;
	std::cout << "i j k" << std::endl;
	for(int i=0; i!=8; ++i)
	{
		if (i==0 || i==7)
		{ // loop over a face
			for(int j=0; j!=8;++j)
			{
				for(int k=0; k!= 8; ++k){std::cout << i << " " << j << " " << k << std::endl;}
			}
			continue;
		}

		for(int j=0; j!=8;++j) //else middle layer
		{
			if (j==0 || j==7) // edge
			{
				for(int k=0; k!=8; ++k){std::cout << i << " " << j << " " << k << std::endl;}
				continue;
			}
			for(int k=0;k!=2;++k){std::cout << i << " " << j << " " << 7*k << std::endl;} // else just need k=0,7
		} //end inner loop
	}// end outer loop

	return 0;
}
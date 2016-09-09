// Assignment 3(?)

// USER NOTES:
// Everything is contained in the class "CharsInInt", including methods for packing and unpacking
// Example testing is given in main()
// Storage positions are 1-4

#include <iostream>

class CharsInInt
{
	private:
		unsigned storage_int = 0x0;
	public:
		void packChar(unsigned char, int);
		unsigned char unpackChar(unsigned);
};

void CharsInInt::packChar(unsigned char char_in, int placement)
{
	// Check placement input for validity
	if(placement < 1 || placement > 4){
		std::cout << placement << " is not a valid placement." << std::endl;
		exit(EXIT_FAILURE);
	}// end if

	unsigned shift_num = (placement-1)*8;

	// Clear the space we want to save to
	unsigned clear_block = 0xffffffff;
	unsigned clear_space = 0xff << shift_num;
	clear_block = clear_block ^ clear_space;
	storage_int = storage_int & clear_block;

	// Store the number
	unsigned store_num = (unsigned)char_in;
	store_num <<= shift_num;
	storage_int = storage_int | store_num;
} // end packChar

unsigned char CharsInInt::unpackChar(unsigned requested_char)
{
	if(requested_char < 1 || requested_char > 4){
		std::cout << requested_char << " is an invalid char request." << std::endl;
		exit(EXIT_FAILURE);
	}
	requested_char = --requested_char;
	unsigned char char_to_return;
	unsigned masks[4];
	masks[0] = 0xff;
	masks[1] = 0xff00;
	masks[2] = 0xff0000;
	masks[3] = 0xff000000;
	unsigned shift_num = 8*requested_char;
	unsigned return_num = storage_int & masks[requested_char];
	return_num >>= shift_num;
	char_to_return = (unsigned char)return_num;
	return char_to_return;
	//Note: The masking here is actually unncessary, assigning an int to a char variable results
	// in only the first byte of the integer being stored (so we can shift off the stuff we don't
	// want and everything else gets ignored during assignment).
}//end unpackChar

int main()
{

	CharsInInt test1;
	test1.packChar('a',1);
	test1.packChar('J',2);
	test1.packChar('h',3);
	test1.packChar('3',4);
	unsigned char a = test1.unpackChar(1);
	unsigned char b = test1.unpackChar(2);
	unsigned char c = test1.unpackChar(3);
	unsigned char d = test1.unpackChar(4);
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;

return 0;
}



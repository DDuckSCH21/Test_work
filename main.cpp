#include <iostream>
#include "Processor.hpp"

int main(int ac, char** av){
	Processor my_processor;
	
	if (ac != NUMB_FILE + 1){
		std::cout << "You need specify 5 files in the arguments\n";
		return(1);
	}
	my_processor.get_res_for_vendor(NUM_VENDOR1, av);
	my_processor.get_res_for_vendor(NUM_VENDOR2, av);
	my_processor.get_res_for_product(NAME_PRODUCT, av);
		return(0);
}
#include <string>
#include <iostream>
//#include <fstream>
#include "Processor.hpp"

int main(int ac, char** av){
//	std::ifstream in_file;
	Processor my_processor;
	
	if (ac != NUMB_FILE + 1){
		std::cout << "You need specify 5 files in the arguments\n";
		return(1);
	}
	
//	for (int i = 1; i < NUMB_FILE + 1; i++){
//		in_file.open(av[i]);
//		if(!in_file || !in_file.is_open())
//			std::cout << "File \"" << av[i] << "\" dosn't open\n";
//		else{
//			if(!my_processor.parse_file(in_file))
//				std::cout << "invalid file \"" << av[i] << "\" content\n";
//		}
//		in_file.close();
//	}
	
	
//	my_processor.get_res_for_vendor(NUM_VENDOR1, av);
//	my_processor.get_res_for_vendor(NUM_VENDOR2, av);
	my_processor.get_res_for_product(NAME_PRODUCT, av);
//	my_processor.print_all_data();
		return(0);
}
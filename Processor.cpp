#include "Processor.hpp"

Processor::Processor(){

}

Processor::~Processor(){
	for (int i = 0; i < _all_data.size(); i++)
		delete _all_data[i];
}

void Processor::print_all_data(){
	for (int i = 0; i < _all_data.size(); i++){
		for (int j = 0; j < _all_data[i]->size(); j++){
			std::cout << "'" << *(_all_data[i]->begin() + j)  << "'\n";
		}
	}
}

bool Processor::parse_file(std::ifstream &in_file){
	std::string raw_string;
	std::string token;
	
	std::vector<std::string> *new_vector;
	
//	std::cout << "kek1\n";
	
	new_vector = new std::vector<std::string>; //todo: delete in destructor Processor

	while(getline(in_file, raw_string)){
		
		std::stringstream tmp(raw_string);
		while(getline(tmp, token, DELIM)){
			new_vector->push_back(token);
		}
			_all_data.push_back(new_vector);
			std::cout << "size=" << new_vector->size() << '\n';
			new_vector = new std::vector<std::string>;
	}
	delete new_vector;
	
	
//	if(new_vector->size() != 4)
//		return(false);
//	_all_data.push_back(new_vector);
	return(true);
}

void Processor::get_res_for_manufacture(std::string name_manufacture){

}


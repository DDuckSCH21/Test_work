#include "Processor.hpp"

Processor::Processor(){
}

Processor::~Processor(){
}

void Processor::print_all_data(){
	for (int i = 0; i < _all_data.size(); i++){
		for (int j = 0; j < _all_data[i]->size(); j++){
			std::cout << "'" << *(_all_data[i]->begin() + j)  << "'\n";
		}
	}
}

bool Processor::check_string_for_products(std::string raw_string, std::string name_products){
		std::vector<std::string> new_vector;
		std::string token;
		std::stringstream tmp(raw_string);
		while(getline(tmp, token, DELIM))
			new_vector.push_back(token);
		if (new_vector[0] == name_products)
			return(true);
		else
			return(false);
}

bool Processor::parse_file(std::ifstream &in_file){
	std::string raw_string;
	std::string token;
	
	std::vector<std::string> *new_vector;
	new_vector = new std::vector<std::string>; //todo: delete in destructor Processor
	while(getline(in_file, raw_string)){
		std::stringstream tmp(raw_string);
		while(getline(tmp, token, DELIM))
			new_vector->push_back(token);
		if(new_vector->size() != 4)
			return(false);
			_all_data.push_back(new_vector);
			new_vector = new std::vector<std::string>;
	}
	delete new_vector;
	return(true);
}

std::string Processor::join_string_res(std::vector<std::string> vector_source){
	std::string res;
	
	for (int i = 0; i < vector_source.size(); i++)
		res += vector_source[i] + ',';
    res[res.size() - 1] = '\n';
	return (res);
}

bool Processor::get_res_for_manufacture(std::string name_manufacture){
	std::ofstream file_res;
	std::vector<std::string> vector_tmp;
	int flag_fill = 0;
	
	file_res.open(name_manufacture);
	if (!file_res)
		return(false);
	for(int i = 0; i < _all_data.size(); i++){
		vector_tmp = *_all_data[i];
			if (vector_tmp[2] == name_manufacture){
				file_res << join_string_res(vector_tmp);
				flag_fill = 1;
			}
		}
	if (!flag_fill)
		file_res << "Empty result\n";
	file_res.close();
	return(true);
}

bool Processor::get_res_for_product(std::string name_product, char **av)
{
	std::vector<std::string> vector_tmp;
	std::ifstream in_file;
	std::ofstream out_file;
	std::string raw_string;
	int flag_empty;

	
	out_file.open(name_product + "_result");
	if (!out_file)
		return(false);
	for (int i = 1; i < NUMB_FILE + 1; i++){
		in_file.open(av[i]);
		if(!in_file || !in_file.is_open())
			std::cout << "File \"" << av[i] << "\" dosn't open\n";
		else{
			out_file << "----Vendor \"" << av[i] << "\"\n";
			flag_empty = 1;
			while(getline(in_file, raw_string))
			{
//				std::stringstream tmp(raw_string);
				
				if (check_string_for_products(raw_string, name_product)){
					out_file << raw_string << '\n';
					flag_empty = 0;
				}
				
			}
			if (flag_empty)
				out_file << "-Empty result\n";
		}
		in_file.close();
	}
	
	out_file.close();
	return(true);
}

bool Processor::get_res_for_vendor(int number_vendor, char **av)
{
	std::ifstream in_file;
	std::string raw_string;
	std::ofstream file_res;

	in_file.open(av[number_vendor]);
	
	if(!in_file || !in_file.is_open()){
//		std::cout << "File \"" << av[number_vendor] << "\" dosn't open\n";
		return(false);
	}
	else{
		file_res.open((std::string)av[number_vendor] + "_result");
		while(getline(in_file, raw_string)){
			file_res << raw_string << '\n';
		}
	}
	in_file.close();
	return(true);
}


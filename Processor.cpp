#include "Processor.hpp"

Processor::Processor(){
}

Processor::~Processor(){
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

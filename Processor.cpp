#include "Processor.hpp"

Processor::Processor(){

}

Processor::~Processor(){

}

bool Processor::parse_file(std::ifstream &in_file){
	
	std::string token;
	std::vector<std::string> *new_vector;
	
//	std::cout << "kek1\n";
	
	new_vector = new std::vector<std::string>; //todo: delete in destructor Processor
	
	while(getline(in_file, token, DELIM)){
//		std::cout << token << '\n';
		new_vector->push_back(token);
	}
	_all_data.push_back(new_vector);

	for (int i = 0; i < _all_data.size(); i++)
	{
		for (int j = 0; j < _all_data[i]->size(); j++)
		{
			std::cout << _all_data[i] << '\n';
		}
	}
	
	return(true);
}



//class Processor{
//public:
//	Processor();
//	~Processor();
//
//	parse_file(std::ifstream in_file);
//	get_res_for_vendor(std::string name_vendor);
//
//private:
//	std::vector<vector<std::string>> all_data;
//};

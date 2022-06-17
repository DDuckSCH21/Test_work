#ifndef PROCESSOR_HPP
# define PROCESSOR_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

# define NUMB_FILE	5
# define DELIM ','
# define MANUFACT_1 'Производитель1'
# define MANUFACT_2 'Произволитель2'

class Processor{
public:
	Processor();
	~Processor();
	
	bool parse_file(std::ifstream &in_file);
	void get_res_for_manufacture(std::string name_manufacture);
	void print_all_data();

private:
	std::vector<std::vector<std::string>* > _all_data;
	std::vector<std::vector<std::string> > _result_first;
	std::vector<std::vector<std::string> > _result_second;
	std::vector<std::vector<std::string> > _result_third;
};

#endif
#ifndef PROCESSOR_HPP
# define PROCESSOR_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

# define NUMB_FILE	5
# define DELIM ','

class Processor{
public:
	Processor();
	~Processor();
	
	bool parse_file(std::ifstream &in_file);
	void get_res_for_vendor(std::string name_vendor);

private:
	std::vector<std::vector<std::string>* > _all_data;
};


#endif
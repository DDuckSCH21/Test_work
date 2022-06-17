#ifndef PROCESSOR_HPP
# define PROCESSOR_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

# define NUMB_FILE	5
# define DELIM ','
# define MANUFACT_1 "Узбекистан"
# define MANUFACT_2 "Lenovo"
# define NUM_VENDOR1 1
# define NUM_VENDOR2 2
# define NAME_PRODUCT "Яблоки"


class Processor{
public:
	Processor();
	~Processor();

	bool get_res_for_product(std::string name_product, char **av);
	bool get_res_for_vendor(int number_vendor, char **av);

private:
	bool check_string_for_products(std::string raw_string, std::string name_products);
};

#endif
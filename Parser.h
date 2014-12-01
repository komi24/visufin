#ifndef DEF_PARSER
#define DEF_PARSER

#include <iostream>
#include <string>
#include <vector>
#include "libxl.h"
#include "Station.h"


class Parser {

	public:
		Parser();
		void parseFile(int day, int hour);

		std::vector<Station> stations;

};

#endif

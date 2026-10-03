#pragma once


#include <string>
#include <vector>
#include "Spectrum.hpp"

class MgfParser {
public:
	std::vector<Spectrum> parse(const std::string& filepath);
};

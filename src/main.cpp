#include <iostream>
#include "MgfParser.hpp"

int main() {
	MgfParser parser;

	std::vector<Spectrum> spectra = parser.parse("data/example.mgf");

	std::cout << "Number of spectra: "
          	<< spectra.size() << '\n';

	if (!spectra.empty()) {
    		std::cout << "Peaks in first spectrum: "
                  	<< spectra[0].getPeaks().size() << '\n';
    	}

    return 0;
}

#include "MgfParser.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<Spectrum> MgfParser::parse(const std::string& filepath) {
    std::ifstream file(filepath);

    if (!file) {
        throw std::runtime_error("Could not open MGF file: " + filepath);
    }

    std::vector<Spectrum> spectra;
    Spectrum currentSpectrum;
    std::string line;
    bool insideSpectrum = false;

    while (std::getline(file, line)) {

        if (line == "BEGIN IONS") {
            currentSpectrum = Spectrum{};
            insideSpectrum = true;
            continue;
        }

        if (line == "END IONS") {
            spectra.push_back(currentSpectrum);
            insideSpectrum = false;
            continue;
        }

        if (!insideSpectrum) {
            continue;
        }

        std::istringstream iss(line);

        double mz;
        double intensity;

        if (iss >> mz >> intensity) {
            currentSpectrum.addPeak(mz, intensity);
        }
    }

    return spectra;
}

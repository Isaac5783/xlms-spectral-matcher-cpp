#include "Spectrum.hpp"

void Spectrum::addPeak(double mz, double intensity) {
    peaks.push_back({mz, intensity});
}

const std::vector<Peak>& Spectrum::getPeaks() const {
    return peaks;
}

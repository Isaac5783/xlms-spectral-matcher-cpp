#pragma once

#include <vector>
#include <Peak.hpp>

class Spectrum {
public:
	void addPeak(double mz, double intensity);
	const std::vector<Peak>& getPeaks() const;

private:
	std::vector<Peak> peaks;
};




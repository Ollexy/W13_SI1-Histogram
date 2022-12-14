#pragma once
#include <map>
#include <vector>
#include "Range.h"
#include <fstream>
#include <algorithm>

class Histogram
{
public:
    Histogram();
    virtual ~Histogram() {};
    std::map<Range, int> getHistogram();
    std::vector<Range> generateRanges(int step, int amount);
    std::map<Range, int> generate(std::string text, std::vector<Range> ranges);
    void normalize();
    std::string draw();
    int getMin();
    int getMax();

private:
    std::map<Range, int> histogram;
    std::vector<std::string> split(const std::string str, const std::string regexStr);
    //std::map<Range, int> histogramNormalized;
};

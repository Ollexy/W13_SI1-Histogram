#pragma once
#include <gtest/gtest.h>
#include "../HistogramLibrary/Histogram.h"

namespace HistogramTest 
{
	TEST(HistogramTest, TestNameHistogram) {
		Histogram histogram = Histogram();
		EXPECT_EQ(histogram.draw(), "");
	}

	TEST(HistogramTest, TestPositive) {
		Histogram histogram;
		EXPECT_NO_THROW(histogram.generateRanges(5, 5));
	}
	TEST(HistogramTest, TestNegativeStep) {
		Histogram histogram;
		EXPECT_ANY_THROW(histogram.generateRanges(-5, 5));
	}
	TEST(HistogramTest, TestNegativeAmount) {
		Histogram histogram;
		EXPECT_ANY_THROW(histogram.generateRanges(5, -5));
	}

	bool areWordsInGivenRange(std::map<Range, int> testMap, Range range, int expected) {
		return testMap[range] == expected;
	}

	TEST(HistogramTest, TestInGivenRange) {
		Histogram histogram;
		std::vector<Range> ranges = histogram.generateRanges(3, 6);
		std::map<Range, int> testMap = histogram.generate("razy dwwa trzy", ranges);
		EXPECT_EQ(testMap[ranges[1]], 3);
	}

	TEST(HistogramTest, TestOutOfRange) {
		Histogram histogram;
		std::vector<Range>range = histogram.generateRanges(1, 6);
		std::map<Range, int> testMap = histogram.generate("raz dwa trzy", range);
		EXPECT_NO_THROW();
	}

	TEST(HistogramTest, TestEmptyText) {
		Histogram histogram;
		std::vector<Range>range = histogram.generateRanges(1, 6);
		std::map<Range, int> testMap = histogram.generate("raz dwa trzy", range);
		EXPECT_NO_THROW(histogram.generate("example", range));
	}

	TEST(histogramtest, testHistogramMultipleTimes) {
		Histogram histogram;
		std::vector<Range>range = histogram.generateRanges(1, 5);
		histogram.generate("siema", range);
		histogram.generate("siema", range);
		EXPECT_NO_THROW(histogram.generate("example", range));
	}

	TEST(HistogramTest, TestCallingBeforeGeneratingHistogram) {
		Histogram histogram = Histogram();
		auto exampleMap = histogram.getHistogram();
		EXPECT_TRUE(exampleMap.empty());
	}

	TEST(HistogramTest, TestCallingAfterGeneratingHistogram) {
		Histogram histogram = Histogram();
		std::vector<Range>range = histogram.generateRanges(1, 5);
		histogram.generate("siema", range);
		auto exampleMap = histogram.getHistogram();
		EXPECT_FALSE(exampleMap.empty());
	}

	TEST(HistogramTest, TestCallingAfterMultipleCalls) {
		Histogram histogram = Histogram();
		std::vector<Range>range = histogram.generateRanges(1, 5);
		histogram.generate("siema", range);
		auto histogram1 = histogram.getHistogram();
		histogram.generate("colka", range);
		auto histogram2 = histogram.getHistogram();
		EXPECT_TRUE(histogram1.empty() == false && histogram2.empty() == false);
	}

	TEST(HistogramTest, TestHistogramBeforeGenerating) {
		Histogram histogram = Histogram();
		EXPECT_EQ(histogram.draw(), "");
	}

	TEST(HistogramTest, TestHistogramAfterGenerating) {
		Histogram histogram = Histogram();
		std::vector<Range>range = histogram.generateRanges(1, 5);
		auto histogram1 = histogram.generate("siema", range);

		EXPECT_FALSE(histogram.draw().empty());
	}

	//TEST(HistogramTest, TestGetMax) {
	//	Histogram histogram = Histogram();
	//	EXPECT_EQ(histogram.draw(), "");
	//}

	//TEST(HistogramTest, TestGetMax) {
	//	Histogram histogram = Histogram();
	//	EXPECT_EQ(histogram.draw(), "");
	//}
}

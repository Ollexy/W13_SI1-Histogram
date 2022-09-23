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
		std::map<Range, int> testMap = histogram.generate("raz dwa trzy", ranges);
		EXPECT_TRUE(areWordsInGivenRange(testMap, ranges[1], 3));
		//EXPECT_TRUE(histogram.generate("example", range));
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
		
		//przeiterowac przez mape zeby sprawdzic czy ma wszystkie elementy
		EXPECT_EQ(histogram.getHistogram(), "");
	}

	/*TEST(HistogramTest, TestCallingAfterMultipleCalls) {
		Histogram histogram = Histogram();
		EXPECT_EQ(histogram.getHistogram(), "");
	}*/

	//TEST(HistogramTest, TestGetMin) {
	//	Histogram histogram = Histogram();
	//	EXPECT_EQ(histogram.draw(), "");
	//}

	//TEST(HistogramTest, TestGetMax) {
	//	Histogram histogram = Histogram();
	//	EXPECT_EQ(histogram.draw(), "");
	//}

	//TEST(HistogramTest, TestGetMax) {
	//	Histogram histogram = Histogram();
	//	EXPECT_EQ(histogram.draw(), "");
	//}
}

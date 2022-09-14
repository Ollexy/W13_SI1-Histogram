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
		EXPECT_ANY_THROW(histogram.generateRanges(5, 5));
	}
	TEST(HistogramTest, TestNegativeStep) {
		Histogram histogram;
		EXPECT_ANY_THROW(histogram.generateRanges(-5, 5));
	}
	TEST(HistogramTest, TestNegativeAmount) {
		Histogram histogram;
		EXPECT_ANY_THROW(histogram.generateRanges(5, -5));
	}

	TEST(HistogramTest, TestInGivenRange) {
		Histogram histogram;
		std::vector<Range>range = histogram.generateRanges(1, 6);
		std::map<Range, int> map = histogram.generate("siema", range);
		EXPECT_NO_THROW(histogram.generate("hello",range));
	}

	TEST(HistogramTest, TestOutOfRange) {
		Histogram histogram;
		std::vector<Range>range = histogram.generateRanges(1, 6);
		std::map<Range, int> map = histogram.generate("siema", range);
		EXPECT_NO_THROW(histogram.generate("hello", range));
	}

	TEST(HistogramTest, TestEmptyText) {
		Histogram histogram;
		std::vector<Range>range = histogram.generateRanges(1, 6);
		std::map<Range, int> map = histogram.generate("siema", range);
		EXPECT_NO_THROW(histogram.generate("", range));
	}

	TEST(histogramtest, testHistogramMultipleTimes) {
		Histogram histogram;
		std::vector<Range>range = histogram.generateRanges(1, 5);
		std::map<Range, int> mapka = histogram.generate("siema", range);
		histogram.generate("siema", range);
		histogram.generate("siema", range);
		EXPECT_NO_THROW(histogram.generate("hello", range));
	}

	TEST(HistogramTest, TestCallingBeforeGeneratingHistogram) {
		Histogram histogram = Histogram();
		auto mapka = histogram.getHistogram();
		EXPECT_TRUE(mapka.empty());
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
}
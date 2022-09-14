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
		EXPECT_EQ(histogram.draw(), "");
	}

	TEST(HistogramTest, TestOutOfRange) {
			Histogram histogram = Histogram();
		EXPECT_EQ(histogram.draw(), "");
	}

	TEST(HistogramTest, TestEmptyText) {
		Histogram histogram = Histogram();
		EXPECT_EQ(histogram.draw(), "");
	}

	TEST(HistogramTest, TestHistogramMultipleTimes) {
		Histogram histogram = Histogram();
		EXPECT_EQ(histogram.draw(), "");
	}
	//TEST(HistogramTest, TestNameHistogram) {
	//	// Example, feel free to modify
	//	Histogram histogram = Histogram();
	//	EXPECT_EQ(histogram.draw(), "");
	//}

	//TEST(HistogramTest, TestNameHistogram) {
	//	// Example, feel free to modify
	//	Histogram histogram = Histogram();
	//	EXPECT_EQ(histogram.draw(), "");
	//}

	//TEST(HistogramTest, TestNameHistogram) {
	//	// Example, feel free to modify
	//	Histogram histogram = Histogram();
	//	EXPECT_EQ(histogram.draw(), "");
	//}

	//TEST(HistogramTest, TestNameHistogram) {
	//	// Example, feel free to modify
	//	Histogram histogram = Histogram();
	//	EXPECT_EQ(histogram.draw(), "");
	//}

	//TEST(HistogramTest, TestNameHistogram) {
	//	// Example, feel free to modify
	//	Histogram histogram = Histogram();
	//	EXPECT_EQ(histogram.draw(), "");
	//}
}
#pragma once
#include <gtest/gtest.h>
#include "../HistogramLibrary/TextReader.h"
#include <fstream>


namespace TextReaderTests
{
	class TextReaderTest : public ::testing::Test {
	public:
		
		TextReaderTest()
			:r1("..\\..\\Histogram\\empty.txt"),
		r2("..\\..\\Histogram\\test.txt"),
		r3("..\\..\\Histogram\\text.txt") {};
		int numberOfLines(std::string str) {
			int x = 0;
			for (auto& a : str) {
				if (a == '\n') {
					x++;
				}
			};
			return x;
		};

	protected:
		TextReader r1;
		TextReader r2;
		TextReader r3;
	};
	TEST_F(TextReaderTest, TestingIfEmpty) {
		std::string readFile = r1.read();

		EXPECT_EQ(readFile, "");
	}
	TEST_F(TextReaderTest, TestingIfOneLine) {
		std::fstream plik;
		plik.open("aaa.txt", std::ios::out);

		plik << "imie" << std::endl;
		plik << "nazwisko" << std::endl;
		plik << "nr_tel" << std::endl;

		plik.close();
		std::string readFile = r2.read();
		std::cout << numberOfLines(readFile);
		ASSERT_EQ(numberOfLines(readFile), 0);
		EXPECT_NE(readFile, "");

	}

	TEST_F(TextReaderTest, TestingIfMultiLine) {
		std::string readFile = r3.read();
		ASSERT_GE(numberOfLines(readFile), 1);

	}
	
}
#pragma once

#define MAXALPHLEN 40    // Максимальная длина алфавита

namespace WordProcessing {
	using namespace System;

	class Alphabit {
	public:
		int firstchar, lastchar, length;
		double freaquancy[MAXALPHLEN];

		Alphabit(String^ lang);
	private:
		void getDataFor(String^ lang);
	};

	String^ ChangeTextUp(String^ text, String^ freaquancyTable);
	int ChangeDown(String^ *text, String^ *freaquancyTable);
}
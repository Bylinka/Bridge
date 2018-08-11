// Bridge.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Report.h"
int main()
{
	const int reportCount = 7;
	IReport** reports = new IReport*[reportCount] {
		new DaylyReport(new PDFTool),
		new WeeklyReport(new PDFTool),
		new DaylyReport(new ProxyTool(new PDFTool)),
		new WeeklyReport(new ProxyTool(new PDFTool)),
		new DaylyReport(new DOCTool),
		new WeeklyReport(new DOCTool),
		new DaylyReport(new ProxyTool(new ProxyTool(new PDFTool)))

	};
	for (int report = 0; report < reportCount; ++report) {
		reports[report]->print();
		delete reports[report];
	}
	delete[]reports;
	system("pause");
    return 0;
}


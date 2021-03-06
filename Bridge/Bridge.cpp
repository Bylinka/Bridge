// Bridge.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Report.h"
int main()
{
	const int reportCount = 10;
	IReport** reports = new IReport*[reportCount] {
		new DaylyReport(new PDFTool),
		new WeeklyReport(new PDFTool),
		new DaylyReport(new DOCToolMethod1),
		new WeeklyReport(new DOCToolMethod2),
		new DaylyReport(new ProxyDOCTool),
		new WeeklyReport(new ProxyDOCTool),
		new DaylyReport(new ProxyPDFTool),
		new WeeklyReport(new ProxyPDFTool),
		new WeeklyReport(new Decorator(new DOCTool)),
		new DaylyReport(new Decorator(new Decorator(new ProxyPDFTool))),


	};
	for (int report = 0; report < reportCount; ++report) {
		reports[report]->print();
		delete reports[report];
		cout << endl;
	}
	delete[]reports;
	system("pause");
    return 0;
}


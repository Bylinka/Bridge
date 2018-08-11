#pragma once
class ITool {
public:
	virtual void printLine(const char* str) = 0;
	virtual void printHeader(const char* str) = 0;

};
class PDFTool : public ITool {
public:
	void printLine(const char* str) {
		cout << "PDF Line: " << str << endl;
	};
	void printHeader(const char* str) {
		cout << "PDF Header: " << str << endl;
	};
};
class DOCTool : public ITool {
public:
	void printLine(const char* str) {
		cout << "DOC Line: " << str << endl;
	};
	void printHeader(const char* str) {
		cout << "DOC Header: " << str << endl;
	};
};
class IReport {
protected:
	ITool * tool = nullptr;
public:
	virtual void print() = 0;
	virtual ~IReport() {
		cout << "deleting: " << typeid(this).name()
			<< " and " << typeid(tool).name() << endl;
		if (tool)delete tool;
	}
};
class WeeklyReport : public IReport {
public:
	WeeklyReport(ITool* tool) {
		this->tool = tool;
	}
	void print() {
		tool->printHeader("Weekly report");
		tool->printLine("Some weekly report line.");
	}
};
class DaylyReport : public IReport {
public:
	DaylyReport(ITool* tool) {
		this->tool = tool;
	}
	void print() {
		tool->printHeader("Dayly report");
		tool->printLine("Some dayly report line.");
	}
};
#pragma once

class ITool {
public:
	virtual void printLine(const char* str) = 0;
	virtual void printHeader(const char* str) = 0;
	virtual ~ITool() {}
};
class IPDFTool : public ITool {};
class PDFTool : public IPDFTool {
	public:
	void printLine(const char* str) {
		cout << "PDF Line: " << str << endl;
	};
	void printHeader(const char* str) {
		cout << "PDF Header: " << str << endl;
	};
};
class IDOCTool : public ITool {};
class DOCTool : public IDOCTool {
public:
	void printLine(const char* str) {
		cout << "DOC Line method "<< method() << ": " << str << endl;
	};
	void printHeader(const char* str) {
		cout << "DOC Header: " << str << endl;
	};
	virtual int method() { return 0; }
};
class DOCToolMethod1 : public DOCTool {
public:
	int method() { return 1; }
};
class DOCToolMethod2 : public DOCTool {
public:
	int method() { return 2; }
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
class ProxyDOCTool : public IDOCTool {
public:
	void printLine(const char* str) {
		cout << "ProxyDOCTool action -> ";
		DOCTool().printLine(str);
	};
	void printHeader(const char* str) {
		cout << "ProxyDOCTool action -> ";
		DOCTool().printHeader(str);
	};
};
class ProxyPDFTool : public IPDFTool {
public:
	void printLine(const char* str) {
		cout << "ProxyPDFTool action -> ";
		PDFTool().printLine(str);
	};
	void printHeader(const char* str) {
		cout << "ProxyPDFTool action -> ";
		PDFTool().printHeader(str);
	};
};
class Decorator : public ITool {
	ITool* next;
public:
	Decorator(ITool* next) :next(next) {}
	~Decorator() {
		cout << "deleting " << typeid(next).name() << endl;
		if (next)delete next;
	}
	void printLine(const char* str) {
		cout << "Decorator action -> ";
		next->printLine(str);
	};
	void printHeader(const char* str) {
		cout << "Decorator action -> ";
		next->printHeader(str);
	};
};
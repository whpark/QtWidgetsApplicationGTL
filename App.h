#pragma once

#include "MainWnd.h"

//---------------------------------------------------------------------------------------------------------------------------------
class xApp : public QApplication {
	Q_OBJECT
public:
	using this_t = xApp;
	using base_t = QApplication;

protected:
	QSettings m_reg { "Biscuit-lab", "TestApp" };
	std::unique_ptr<xMainWnd> m_wndMain;

public:
	xApp(int &argc, char **argv/*, int flag = ApplicationFlags*/);
	~xApp();

	bool Init();

public:
	QSettings& GetReg() { return m_reg; };
	xMainWnd& GetMainWnd() { return *m_wndMain; }

};

//---------------------------------------------------------------------------------------------------------------------------------
extern std::optional<xApp> theApp;

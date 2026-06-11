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
	std::filesystem::path m_root;

public:
	xApp(int &argc, char **argv/*, int flag = ApplicationFlags*/);
	~xApp();

	int Run();

	std::filesystem::path const& GetRoot() const { return m_root; }
	std::filesystem::path const& GetDefaultProjectRoot() const {
		//auto str = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
		//static std::filesystem::path root = [] { return std::filesystem::path(str.toStdWString()) / L"TestApp"; }();
		static std::filesystem::path root = m_root.root_path() / "TestApp";
		return root;
	}

public:
	QSettings& GetReg() { return m_reg; };
	xMainWnd& GetMainWnd() { return *m_wndMain; }
};

//---------------------------------------------------------------------------------------------------------------------------------
extern std::optional<xApp> app;


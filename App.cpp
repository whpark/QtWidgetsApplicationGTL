#include "pch.h"
#include "App.h"

std::optional<xApp> theApp;

xApp::xApp(int &argc, char **argv) : QApplication(argc, argv) {
}

xApp::~xApp() {
}

bool xApp::Init() {
	//setStyle("fusion");

	m_wndMain = std::make_unique<xMainWnd>();
	m_wndMain->show();

	return true;
}

int main(int argc, char* argv[]) {
	//auto r = gtl::SetCurrentPath_BinFolder();
	theApp.emplace(argc, argv);
	if (!theApp->Init())
		return -1;

	return theApp->exec();
}

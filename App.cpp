#include "pch.h"
#include "App.h"

int main(int argc, char* argv[]) {
	//auto r = gtl::SetCurrentPath_BinFolder();
	xApp app(argc, argv);
	if (!app.Init())
		return -1;

	return app.exec();
}

xApp::xApp(int &argc, char **argv) : QApplication(argc, argv) {
}

bool xApp::Init() {
	//setStyle("fusion");

	m_wndMain = std::make_unique<xMainWnd>();
	m_wndMain->show();

	return true;
}

xApp::~xApp() {
}

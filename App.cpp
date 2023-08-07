#include "pch.h"
#include "App.h"

int main(int argc, char* argv[]) {
	//auto r = gtl::SetCurrentPath_BinFolder();
	xApp a(argc, argv);
	return a.exec();
}

xApp::xApp(int &argc, char **argv) : QApplication(argc, argv) {
	m_wndMain.show();
}

xApp::~xApp() {
}

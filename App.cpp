#include "pch.h"
#include "App.h"

int main(int argc, char* argv[]) {
	xApp a(argc, argv);
	return a.exec();
}

xApp::xApp(int &argc, char **argv) : QApplication(argc, argv) {
	m_wndMain.show();
}

xApp::~xApp() {
}

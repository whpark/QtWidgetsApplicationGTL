#include "pch.h"
#include "App.h"

//W_OBJECT_IMPL(xApp)

std::optional<xApp> app;

xApp::xApp(int &argc, char **argv) : QApplication(argc, argv) {
	m_root = gtl::SetCurrentPath_ProjectFolder(L"").value_or("C:\\");


	setStyle("fusion");

	setOrganizationName("Biscuit-lab");
	setOrganizationDomain("biscuit-lab.com");
	setApplicationName("TestApp");

	//auto folderProject = GetDefaultProjectRoot();
	//if (!std::filesystem::exists(folderProject))
	//	std::filesystem::create_directories(folderProject);
}

xApp::~xApp() {
}

int xApp::Run() {

	m_wndMain = std::make_unique<xMainWnd>();
	m_wndMain->show();

	return exec();
}

int main(int argc, char* argv[]) {
	// set locale utf-8 (NOT WORKING ON WINDOWS)
	std::locale l("ko_kr.utf-8");
	auto gl = std::locale::global(l);

	//FreeImage_Initialise();

	if (argc > 1)
		argc = 1;
	app.emplace(argc, argv);

	auto r = app->Run();

	//FreeImage_DeInitialise();
	return r;
}

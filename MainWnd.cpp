#include "pch.h"
#include "App.h"
#include "MainWnd.h"
#include "AboutDlg.h"

using namespace gtl::qt;

xMainWnd::xMainWnd(QWidget *parent) : base_t(parent) {
    ui.setupUi(this);

	LoadWindowPosition(theApp->GetReg(), "MainWnd", this);

	// Application Icon
	QIcon* icon = new QIcon(":/image/icon.ico");
	setWindowIcon(*icon);

	connect(ui.actionAbout, &QAction::triggered, this, &this_t::OnAction_About);
}

xMainWnd::~xMainWnd() {
	SaveWindowPosition(theApp->GetReg(), "MainWnd", this);
}

void xMainWnd::OnAction_About(bool bChecked) {
	xAboutDlg dlg(this);
	dlg.exec();
}

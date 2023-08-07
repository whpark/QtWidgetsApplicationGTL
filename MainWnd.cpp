#include "pch.h"
#include "MainWnd.h"
#include "AboutDlg.h"

xMainWnd::xMainWnd(QWidget *parent) : base_t(parent) {
    ui.setupUi(this);

	// Application Icon
	QIcon* icon = new QIcon(":/image/icon.png");
	setWindowIcon(*icon);

	connect(ui.actionAbout, &QAction::triggered, this, &this_t::OnAction_About);
}

xMainWnd::~xMainWnd() {
}

void xMainWnd::OnAction_About(bool bChecked) {
	xAboutDlg dlg;
	dlg.exec();
}

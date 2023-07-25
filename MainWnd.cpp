#include "pch.h"
#include "MainWnd.h"

xMainWnd::xMainWnd(QWidget *parent) : base_t(parent) {
    ui.setupUi(this);

	// CI Bitmap
	QIcon* icon = new QIcon(":/image/icon.png");
	setWindowIcon(*icon);
}

xMainWnd::~xMainWnd() {
}

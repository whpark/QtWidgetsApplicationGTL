#pragma once

#include <QDialog>
#include "ui_AboutDlg.h"

class xAboutDlg : public QDialog {
	Q_OBJECT

public:
	xAboutDlg(QWidget* parent = nullptr);
	~xAboutDlg();

	std::string m_strID;

private:
	Ui::AboutDlgClass ui;
};

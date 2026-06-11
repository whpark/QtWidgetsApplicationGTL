#include "pch.h"

#include "App.h"
#include "AboutDlg.h"
#include "gtl/qt/util.h"

using namespace gtl::qt;

xAboutDlg::xAboutDlg(QWidget* parent) : QDialog(parent) {
	ui.setupUi(this);
	ui.txtID->setText("");

	if (auto txt = gtl::FileToString(app->GetRoot() / "readme.md")) {
		ui.textEdit->setMarkdown(ToQString(*txt));
	}

	QString strBuildDate;
	try {
		std::istringstream strDate(__DATE__);
		std::string month;
		int day{}, year{};
		strDate >> month;
		strDate >> day;
		strDate >> year;
		static std::vector<std::string> const months { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", };
		auto pos = std::find(months.begin(), months.end(), month);
		auto m = std::distance(months.begin(), pos) + 1;
		strBuildDate = ToQString(std::format("{}-{:02d}-{:02d}", year, (int)m, day));
	} catch (...) {
		strBuildDate = __DATE__;
	}

	ui.grpAbout->setTitle(strBuildDate);

	connect(ui.buttonBox, &QDialogButtonBox::accepted, this, [this]{
		m_strID = ui.txtID->text().toStdString();
		accept();
	});
	connect(ui.buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

xAboutDlg::~xAboutDlg() {
}

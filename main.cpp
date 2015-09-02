#include "stdafx.hpp"

#include "TreeModel.hpp"
#include "TreeModelView.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QFile file("default.txt");
	file.open(QIODevice::ReadOnly);
	TreeModel model(file.readAll());
	file.close();

	TreeModelView view;
	view.setModel(&model);
	view.show();

	return app.exec();
}

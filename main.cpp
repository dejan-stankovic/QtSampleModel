#include "global.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	SampleModelView view;
	view.show();

	return app.exec();
}

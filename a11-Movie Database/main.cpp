#include <QApplication>
#include <QPushButton>
#include "../headers/a11.h"

int main(int argc, char *argv[]) {
    /*QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);

    button.resize(200, 100);
    button.show();*/

    QApplication a(argc, argv);
    FileRepository* repo = new FileRepository("moviesfile.txt");
    AdminServices* adminServices = new AdminServices(*repo);
    UserServices* userServices = new UserServices(*repo);
    a11 gui{adminServices, userServices};
    gui.show();
    return a.exec();
}

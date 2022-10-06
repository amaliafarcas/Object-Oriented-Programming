#include <QApplication>
#include <QPushButton>
#include "users.h"
#include "repo.h"
#include "service.h"
#include "window.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repo* repo = new Repo{"posts", "topics"};
    Service* service = new Service{repo};

    for (auto user : repo->GetUsers())
    {
        Window* pp = new Window{service, user};
        pp->setWindowTitle(QString::fromStdString(user.getName()));
        service->addObserver(pp);
        pp->show();
    }

    return a.exec();
}

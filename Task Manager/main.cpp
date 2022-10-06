#include <QApplication>
#include "taskRepo.h"
#include "service.h"
#include "programmerwindow.h"
#include "programmer.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    TaskRepo* repo = new TaskRepo{"tasks"};
    Service* service = new Service{repo};

    for (auto programmer : repo->GetProgrammers())
    {
        programmerWindow* pp = new programmerWindow{service, programmer};
        pp->setWindowTitle(QString::fromStdString(programmer.getName()));
        service->addObserver(pp);
        pp->show();
    }

    return a.exec();
}

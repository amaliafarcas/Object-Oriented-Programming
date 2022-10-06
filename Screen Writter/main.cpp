#include <QApplication>
#include <QPushButton>
#include "idea.h"
#include "ideaRepo.h"
#include "service.h"
#include "Observer.h"
#include "IdeaTableModel.h"
#include "writerwindow.h"
#include "fstream"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    IdeaRepo* repo = new IdeaRepo{"idea"};
    Service* service = new Service{repo};

    IdeaTableModel* model = new IdeaTableModel{repo};

    std::ifstream fileIn("writer");
    ScreenWriter user;
    while (fileIn >> user)
    {
        WriterWindow* pp = new WriterWindow{model, service, user};
        pp->setWindowTitle(QString::fromStdString(user.getName()));
        service->AddObserver(pp);
        pp->show();
    }

    return a.exec();
}

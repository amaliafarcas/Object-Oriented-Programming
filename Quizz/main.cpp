#include <QApplication>
#include <QtWidgets/QApplication>
#include "participants.h"
#include "quizz.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    std::string qPath{ "questions.txt" };
    std::string pPath{ "participants.txt" };

    FileRepository<Question>* q = new FileRepository<Question>{qPath};
    FileRepository<Participant>* p = new FileRepository<Participant>{pPath};
    Service* service = new Service{q, p};

    std::ifstream fileIn("participants.txt");
    Participant participant;

    while (fileIn >> participant)
    {
        participants* pp = new participants{service, participant};
        pp->setWindowTitle(QString::fromStdString(participant.getName()));
        service->addObserver(pp);
        pp->show();
    }

    quizz w{service};
    service->addObserver(&w);
    w.show();

    return a.exec();
}

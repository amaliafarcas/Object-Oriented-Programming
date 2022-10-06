#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <crtdbg.h>
#include "ui.h"

int main()
{
    RunAllTestsRefrigerator();
    RunAllTestsRepo();
    RunAllTestsService();
    RunAllTestsUndoService();

    Repository* repository = CreateRepo(10);
    Service* service = CreateService(repository);
    UndoService* undoService = CreateUndoService(4);
    Console* console = CreateConsole(service, undoService);

    InitRepo(repository);

    Repository repoCopy = DuplicateRepo(*repository);
    AddEntry(undoService, repoCopy);

    MainLoop(console);

    DestroyConsole(console);
    DestroyService(service);
    DestroyRepo(repository);

    return 0;
}


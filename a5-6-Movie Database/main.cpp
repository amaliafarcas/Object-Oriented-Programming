#include <iostream>
#include <crtdbg.h>
#include <memory>
#include "ui.h"


int main()
{
    MovieTests::TestAllMovie();
    DynamicVectorTests::TestAll();
    RepositoryTests::TestAll();
    AdminServicesTests::TestAll();
    UserServicesTests::TestAll();

    Repository* repo = new Repository(12);
    AdminServices* adminServices = new AdminServices(*repo);
    UserServices* userServices = new UserServices(*repo);
    Console* console = new Console(*adminServices, *userServices);

    console->SelectMode();

    delete console;
    delete userServices;
    delete adminServices;
    delete repo;

    int c = _CrtDumpMemoryLeaks();
    std::cout << c;
}


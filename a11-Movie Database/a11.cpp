#include "../headers/a11.h"
#include "../headers/MovieValidator.h"
#include <QtWidgets/QMessageBox>
//#include "ui_a11.h"

a11::a11(AdminServices* sv, UserServices* us_sv)
{
    this->serv = sv;
    this->user_sv = us_sv;
    this->title_widget = new QLabel(this);
    this->text_w = new QLabel(this);
    this->admin_button = new QPushButton(this);
    this->user_button = new QPushButton(this);
    this->initGui();
    this->connectSignalAndSlots();
}

a11::~a11()
{
}

void a11::initGui()
{
    QWidget* m_myWidget = new QWidget(this);
    m_myWidget->setGeometry(0, 0, 300, 130);
    QVBoxLayout* layout = new QVBoxLayout(m_myWidget);
    QFont title_font = this->title_widget->font();
    this->title_widget->setText("Welcome to movie department!");
    title_font.setItalic(true);
    title_font.setPointSize(13);
    title_font.setStyleHint(QFont::System);
    this->title_widget->setFont(title_font);
    //title_widget->setStyleSheet("QLabel { background-color : white; color : #660035; }");
    title_widget->setStyleSheet("* {color: qlineargradient(spread:pad, x1:0 y1:0, x2:1 y2:0, stop:0 pink, stop:1 #660035);"
                                     "background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 white, stop:1 pink);}");
    layout->addWidget(this->title_widget, Qt::AlignCenter);

    QFont text_font = this->text_w->font();
    this->text_w->setText("Choose mode:");
    text_font.setPointSize(10);
    text_font.setStyleHint(QFont::System);
    this->text_w->setFont(text_font);
    text_w->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
    layout->addWidget(this->text_w);

    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::white);

    m_myWidget->setAutoFillBackground(true);
    m_myWidget->setPalette(pal);
    m_myWidget->show();

    this->admin_button->setText("Admin mode");
    layout->addWidget(this->admin_button);

    admin_button->setStyleSheet("QPushButton"
                         "{"
                         "background-color : #ffcce6;"
                         "}"
                         "QPushButton::pressed"
                         "{"
                         "background-color : #ff0084;"
                         "}"
    );

    this->user_button->setText("User mode");
    layout->addWidget(this->user_button);

    user_button->setStyleSheet("QPushButton"
                                "{"
                                "background-color : #ffcce6;"
                                "}"
                                "QPushButton::pressed"
                                "{"
                                "background-color : #ff0084;"
                                "}"
    );
}

void a11::showAdmin()
{
    QWidget* admin = new AdminGUI(NULL, this->serv);
    admin->showNormal();
}

void a11::showUser()
{
    QWidget* user= new UserGUI(NULL, this->serv, this->user_sv);
    user->showNormal();
}

void a11::connectSignalAndSlots()
{
    QObject::connect(this->admin_button, &QPushButton::clicked, this, &a11::showAdmin);
    QObject::connect(this->user_button, &QPushButton::clicked, this, &a11::showUser);
}

void AdminGUI::initAdminGui()
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QFont title_font = this->title_widget->font();
    this->title_widget->setText("Admin mode");
    title_font.setItalic(true);
    title_font.setPointSize(13);
    title_font.setStyleHint(QFont::System);
    this->title_widget->setFont(title_font);
    title_widget->setStyleSheet("QLabel { background-color : white; color : #660035; }");
    layout->addWidget(this->title_widget, Qt::AlignCenter);
    layout->addWidget(this->title_widget);

    QFont text_font = this->text_w->font();
    this->text_w->setText("Choose mode:");
    text_font.setPointSize(10);
    text_font.setStyleHint(QFont::System);
    this->text_w->setFont(text_font);
    text_w->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
    layout->addWidget(this->text_w);

    layout->addWidget(this->movie_list_widget);

    auto* movie_details_layout = new QFormLayout{};
    QLabel* text = new QLabel;
    QFont font = text->font();
    text->setText("Title");
    font.setStyleHint(QFont::System);
    text->setFont(font);
    text->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
    movie_details_layout->addRow(text, this->titleLineEdit);
    text = new QLabel;
    font = text->font();
    text->setText("Genre");
    font.setStyleHint(QFont::System);
    text->setFont(font);
    text->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
    movie_details_layout->addRow(text, this->genreLineEdit);
    text = new QLabel;
    font = text->font();
    text->setText("Year");
    font.setStyleHint(QFont::System);
    text->setFont(font);
    text->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
    movie_details_layout->addRow(text, this->yearLineEdit);
    text = new QLabel;
    font = text->font();
    text->setText("Likes");
    font.setStyleHint(QFont::System);
    text->setFont(font);
    text->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
    movie_details_layout->addRow(text, this->likesLineEdit);
    text = new QLabel;
    font = text->font();
    text->setText("Link");
    font.setStyleHint(QFont::System);
    text->setFont(font);
    text->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
    movie_details_layout->addRow(text, this->linkLineEdit);
    titleLineEdit->setStyleSheet("color: darkBlue;  background-color: white");
    genreLineEdit->setStyleSheet("color: darkBlue;  background-color: white");
    yearLineEdit->setStyleSheet("color: darkBlue;  background-color: white");
    likesLineEdit->setStyleSheet("color: darkBlue;  background-color: white");
    linkLineEdit->setStyleSheet("color: darkBlue;  background-color: white");
    layout->addLayout(movie_details_layout);

    auto* buttons_layout = new QGridLayout{};
    buttons_layout->addWidget(this->addButton, 0, 0);
    addButton->setStyleSheet("QPushButton"
                                "{"
                                "background-color : #ffcce6;"
                                "}"
                                "QPushButton::pressed"
                                "{"
                                "background-color : #ff0084;"
                                "}"
    );

    buttons_layout->addWidget(this->deleteButton, 0, 1);
    deleteButton->setStyleSheet("QPushButton"
                             "{"
                             "background-color : #ffcce6;"
                             "}"
                             "QPushButton::pressed"
                             "{"
                             "background-color : #ff0084;"
                             "}"
    );

    buttons_layout->addWidget(this->updateButton, 1, 0);
    updateButton->setStyleSheet("QPushButton"
                             "{"
                             "background-color : #ffcce6;"
                             "}"
                             "QPushButton::pressed"
                             "{"
                             "background-color : #ff0084;"
                             "}"
    );

    buttons_layout->addWidget(this->chartButton, 1, 1);
    chartButton->setStyleSheet("QPushButton"
                             "{"
                             "background-color : #ffcce6;"
                             "}"
                             "QPushButton::pressed"
                             "{"
                             "background-color : #ff0084;"
                             "}"
    );

    layout->addLayout(buttons_layout);
}

void AdminGUI::populateList()
{
    this->movie_list_widget->clear();
    std::vector<Movie> allMovies = this->serv->GetAll();
    int i=0;
    for (auto& m : allMovies)
    {
        QString stringItem = QString::fromStdString(
                m.GetTitle() + "   " +
                m.GetGenre() + "   " +
                std::to_string(m.GetYear()) + "   " +
                std::to_string(m.GetLikes()) + "   " +
                m.GetTrailer());
        this->movie_list_widget->addItem(stringItem);
        this->movie_list_widget->item(i)->setForeground(Qt::darkBlue);
        i++;
    }
}

void AdminGUI::connectSignalAndSlots()
{
    QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminGUI::guiAddMovie);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminGUI::guiDeleteMovie);
    QObject::connect(this->updateButton, &QPushButton::clicked, this, &AdminGUI::guiUpdateMovie);

    QObject::connect(this, &AdminGUI::updateMoviesSignal, this, &AdminGUI::populateList);
    QObject::connect(this, &AdminGUI::addMovieSignal, this, &AdminGUI::addMovie);
    QObject::connect(this, &AdminGUI::removeMovieSignal, this, &AdminGUI::removeMovie);
    QObject::connect(this, &AdminGUI::updateMovieSignal, this, &AdminGUI::updateMovie);
}

void AdminGUI::addMovie(std::string title, std::string genre, size_t year, size_t likes, std::string link)
{
    std::string text = "Movie added succesfully!";

    try
    {
        this->serv->AddMovie(title, genre, year, likes, link);
        emit updateMoviesSignal();
    }
    catch (ValidationException error)
    {
        text = error.getMessage();
    }

    QMessageBox msgBox;
    msgBox.setText(text.c_str());
    msgBox.exec();
}

void  AdminGUI::removeMovie(std::string title)
{
    std::string text = "Movie removed succesfully!";

    try
    {
        this->serv->RemoveMovie(title);
        emit updateMoviesSignal();

    }
    catch (ValidationException error)
    {
        text = error.getMessage();
    }

    QMessageBox msgBox;
    msgBox.setText(text.c_str());
    msgBox.exec();
}

void AdminGUI::updateMovie(std::string t, std::string title, std::string genre, size_t year, size_t likes, std::string link)
{
    std::string text = "Movie updated successfully!";

    try
    {
        if (!title.empty()) this->serv->UpdateMovieTitle(t, title);
        if (!genre.empty()) this->serv->UpdateMovieGenre(t, genre);
        if (year) this->serv->UpdateMovieYear(t, year);
        if (likes) this->serv->UpdateMovieLikes(t, likes);
        if(!link.empty()) this->serv->UpdateMovieTrailer(t, link);

        emit updateMoviesSignal();
    }
    catch (ValidationException error)
    {
        text = error.getMessage();
    }

    QMessageBox msgBox;
    msgBox.setText(text.c_str());
    msgBox.exec();
}

void AdminGUI::guiAddMovie()
{
    int year = atoi(this->yearLineEdit->text().toStdString().c_str());
    int likes = atoi(this->likesLineEdit->text().toStdString().c_str());
    std::string title = this->titleLineEdit->text().toStdString();
    std::string genre = this->genreLineEdit->text().toStdString();
    std::string link = this->linkLineEdit->text().toStdString();


    this->titleLineEdit->clear();
    this->genreLineEdit->clear();
    this->yearLineEdit->clear();
    this->likesLineEdit->clear();
    this->linkLineEdit->clear();

    emit addMovieSignal(title, genre, year, likes, link);
    emit updateMoviesSignal();
}

void AdminGUI::guiDeleteMovie()
{
    std::string title = this->titleLineEdit->text().toStdString();

    this->titleLineEdit->clear();
    this->genreLineEdit->clear();
    this->yearLineEdit->clear();
    this->likesLineEdit->clear();
    this->linkLineEdit->clear();

    emit removeMovieSignal(title);
    emit updateMoviesSignal();
}

void AdminGUI::guiUpdateMovie()
{
    int id = this->getSelectedIndex();
    Movie mov;

    if (id != -1)
    {
        mov = this->serv->GetAll()[id];

        std::string t = mov.GetTitle();

        std::string title = this->titleLineEdit->text().toStdString();
        std::string genre = this->genreLineEdit->text().toStdString();
        int year = atoi(this->yearLineEdit->text().toStdString().c_str());
        int likes = atoi(this->likesLineEdit->text().toStdString().c_str());
        std::string link = this->linkLineEdit->text().toStdString();

        emit updateMovieSignal(t, title, genre, year, likes, link);
        emit updateMoviesSignal();
    }
    else {
        QMessageBox mess;
        mess.setText("Please select the movie you want to remove!");
        mess.exec();
    }
}

void AdminGUI::displayChart()
{

}

int AdminGUI::getSelectedIndex() const
{
    if (this->movie_list_widget->count() == 0)
    {
        return -1;
    }

    QModelIndexList  index = this->movie_list_widget->selectionModel()->selectedRows();

    if (index.size() == 0)
    {
        this->titleLineEdit->clear();
        this->genreLineEdit->clear();
        this->yearLineEdit->clear();
        this->likesLineEdit->clear();
        this->linkLineEdit->clear();

        return -1;
    }

    return index.at(0).row();
}

AdminGUI::AdminGUI(QWidget* parent, AdminServices* serv)
{
    this->setStyleSheet("background-color: white");
    setParent(parent);
    this->serv = serv;
    this->title_widget = new QLabel(this);
    this->text_w = new QLabel(this);
    this->movie_list_widget = new QListWidget();
    this->titleLineEdit = new QLineEdit{};
    this->genreLineEdit = new QLineEdit{};
    this->yearLineEdit = new QLineEdit{};
    this->likesLineEdit = new QLineEdit{};
    this->linkLineEdit = new QLineEdit{};
    this->addButton = new QPushButton("Add");
    this->deleteButton = new QPushButton("Delete");
    this->updateButton = new QPushButton("Update");
    this->chartButton = new QPushButton("Display chart");
    this->initAdminGui();
    this->connectSignalAndSlots();
    this->populateList();
}

AdminGUI::~AdminGUI()
{
}

UserGUI::UserGUI(QWidget* parent, AdminServices* serv, UserServices* us_sv)
{
    this->setStyleSheet("background-color: white");
    setParent(parent);
    this->serv = serv;
    this->user_sv = us_sv;
    this->title_widget = new QLabel(this);
    this->text_w = new QLabel(this);
    this->playlist_list_widget = new QListWidget{};
    this->movie_list_widget = new QListWidget();
    this->filter_movie_list_widget = new QListWidget();
    this->titleLineEdit = new QLineEdit{};
    this->genreLineEdit = new QLineEdit{};
    this->yearLineEdit = new QLineEdit{};
    this->likesLineEdit = new QLineEdit{};
    this->linkLineEdit = new QLineEdit{};
    this->filterLineEdit = new QLineEdit{};
    this->titleFilterLineEdit = new QLineEdit{};
    this->genreFilterLineEdit = new QLineEdit{};
    this->addButton = new QPushButton("Add to the watchlist list");
    this->removeButton = new QPushButton("Remove from the watchlist list");
    this->filterButton = new QPushButton("Filter the movies");
    this->nextButton = new QPushButton("Next movie");
    this->openListButton = new QPushButton("Open file");
    this->csvButton = new QRadioButton("CSV");
    this->htmlButton = new QRadioButton("HTML");
    this->repoTypeSelected = false;
    this->filtered = false;
    this->index = -1;

    this->initUserGui();
    this->populateMovieList();
    this->connectingSignalsAndSlots();
    this->nextSignal();
}

UserGUI::~UserGUI()
{
}

void UserGUI::populateMovieList()
{
    this->movie_list_widget->clear();
    int i = 0;
    std::vector<Movie> allMovies = this->serv->GetAll();
    for (auto& m : allMovies)
    {
        this->movie_list_widget->addItem(QString::fromStdString(m.GetTitle()));
        this->movie_list_widget->item(i)->setForeground(Qt::darkBlue);
        i++;
    }
}

void UserGUI::populatePlaylistList()
{
    this->playlist_list_widget->clear();
    int i=0;
    std::vector<Movie> allMovies = this->user_sv->SeeWatchList();
    for (auto& m : allMovies)
    {
        this->playlist_list_widget->addItem(QString::fromStdString(m.GetTitle()));
        this->playlist_list_widget->item(i)->setForeground(Qt::darkBlue);
        i++;
    }
}

void UserGUI::populateFilterList()
{
    this->filter_movie_list_widget->clear();
    std::vector<Movie> allMovies = this->user_sv->GetMovieList();
    //allMovies.erase(allMovies.begin());
    for (auto& m : allMovies)
    {
        QString stringItem = QString::fromStdString(
                m.GetTitle() + "   " +
                m.GetGenre() + "   " +
                std::to_string(m.GetYear()) + "   " +
                std::to_string(m.GetLikes()) + "   " +
                m.GetTrailer());
        this->filter_movie_list_widget->addItem(stringItem);
    }
}

void UserGUI::connectingSignalsAndSlots()
{
    QObject::connect(this->addButton, &QPushButton::clicked, this, &UserGUI::AddMovieHandler);
    QObject::connect(this->removeButton, &QPushButton::clicked, this, &UserGUI::RemoveMovieHandler);
    QObject::connect(this->nextButton, &QPushButton::clicked, this, &UserGUI::nextMovieHandler);
    QObject::connect(this->filterButton, &QPushButton::clicked, this, &UserGUI::guiFilterMovies);
    QObject::connect(this->openListButton, &QPushButton::clicked, this, &UserGUI::fileHandler);

    QObject::connect(this, &UserGUI::updateWatchListSignal, this, &UserGUI::populatePlaylistList);
    QObject::connect(this, &UserGUI::updateFilterListSignal, this, &UserGUI::populateFilterList);
    QObject::connect(this, &UserGUI::addMovieSignal, this, &UserGUI::addMovie);
    QObject::connect(this, &UserGUI::removeMovieSignal, this, &UserGUI::removeMovie);
    QObject::connect(this, &UserGUI::nextSignal, this, &UserGUI::nextMovie);
    QObject::connect(this, &UserGUI::filterSignal, this, &UserGUI::filterMovie);
}

void UserGUI::initUserGui() {


    QVBoxLayout *layout = new QVBoxLayout(this);

        QFont title_font = this->title_widget->font();
        this->title_widget->setText("User mode");
        title_font.setItalic(true);
        title_font.setPointSize(13);
        title_font.setStyleHint(QFont::System);
        this->title_widget->setFont(title_font);
        title_widget->setStyleSheet("QLabel { background-color : white; color : #660035; }");
        layout->addWidget(this->title_widget, Qt::AlignCenter);
        layout->addWidget(this->title_widget);

        QFont text_font = this->text_w->font();
        this->text_w->setText("Choose how you want to open watch list:");
        text_font.setPointSize(10);
        text_font.setStyleHint(QFont::System);
        this->text_w->setFont(text_font);
        text_w->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
        layout->addWidget(this->text_w);

//o
    auto* radio_buttons_layout = new QGridLayout{};
    //this->csvButton->setStyleSheet("color: darkBlue");
    radio_buttons_layout->addWidget(this->csvButton, 0, 0);
    //this->csvButton->setStyleSheet("color: darkBlue");
    radio_buttons_layout->addWidget(this->htmlButton, 1, 0);
    openListButton->setStyleSheet("QPushButton"
                                "{"
                                "background-color : #ffcce6;"
                                "}"
                                "QPushButton::pressed"
                                "{"
                                "background-color : #ff0084;"
                                "}"
    );
    radio_buttons_layout->addWidget(this->openListButton, 0, 1);
    layout->addLayout(radio_buttons_layout);
    //o
    this->text_w = new QLabel;
    text_font = this->text_w->font();
    this->text_w->setText("All movies:");
    text_font.setPointSize(10);
    text_font.setStyleHint(QFont::System);
    this->text_w->setFont(text_font);
    text_w->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
    layout->addWidget(this->text_w);
    auto* list_layout = new QGridLayout{};
    list_layout->addWidget(this->movie_list_widget, 0, 0);

    this->text_w = new QLabel;
    text_font = this->text_w->font();
    this->text_w->setText("Watch list:");
    text_font.setPointSize(10);
    text_font.setStyleHint(QFont::System);
    this->text_w->setFont(text_font);
    text_w->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
    list_layout->addWidget(this->text_w, 1, 0);

    list_layout->addWidget(this->playlist_list_widget, 2, 0);
    layout->addLayout(list_layout);


    auto* movie_details_layout = new QFormLayout{};
    QLabel* text = new QLabel;
    QFont font = text->font();
    text->setText("Title");
    font.setStyleHint(QFont::System);
    text->setFont(font);
    text->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
    movie_details_layout->addRow(text, this->titleLineEdit);
    text = new QLabel;
    font = text->font();
    text->setText("Genre");
    font.setStyleHint(QFont::System);
    text->setFont(font);
    text->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
    movie_details_layout->addRow(text, this->genreLineEdit);
    text = new QLabel;
    font = text->font();
    text->setText("Year");
    font.setStyleHint(QFont::System);
    text->setFont(font);
    text->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
    movie_details_layout->addRow(text, this->yearLineEdit);
    text = new QLabel;
    font = text->font();
    text->setText("Likes");
    font.setStyleHint(QFont::System);
    text->setFont(font);
    text->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
    movie_details_layout->addRow(text, this->likesLineEdit);
    text = new QLabel;
    font = text->font();
    text->setText("Link");
    font.setStyleHint(QFont::System);
    text->setFont(font);
    text->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
    movie_details_layout->addRow(text, this->linkLineEdit);

    titleLineEdit->setStyleSheet("color: darkBlue;  background-color: white");
    genreLineEdit->setStyleSheet("color: darkBlue;  background-color: white");
    yearLineEdit->setStyleSheet("color: darkBlue;  background-color: white");
    likesLineEdit->setStyleSheet("color: darkBlue;  background-color: white");
    linkLineEdit->setStyleSheet("color: darkBlue;  background-color: white");
    layout->addLayout(movie_details_layout);

    auto* buttons_layout = new QGridLayout{};

    nextButton->setStyleSheet("QPushButton"
                               "{"
                               "background-color : #ffcce6;"
                               "}"
                               "QPushButton::pressed"
                               "{"
                               "background-color : #ff0084;"
                               "}"
    );
    buttons_layout->addWidget(this->nextButton, 0, 0);

    addButton->setStyleSheet("QPushButton"
                               "{"
                               "background-color : #ffcce6;"
                               "}"
                               "QPushButton::pressed"
                               "{"
                               "background-color : #ff0084;"
                               "}"
    );
    buttons_layout->addWidget(this->addButton, 0, 1);

    removeButton->setStyleSheet("QPushButton"
                               "{"
                               "background-color : #ffcce6;"
                               "}"
                               "QPushButton::pressed"
                               "{"
                               "background-color : #ff0084;"
                               "}"
    );
    buttons_layout->addWidget(this->removeButton, 0, 2);
    layout->addLayout(buttons_layout);

    auto* filter_title = new QLabel("Filter the available movies by genre");
    QFont filter_font = filter_title->font();
    filter_font.setItalic(true);
    filter_font.setPointSize(14);
    filter_font.setStyleHint(QFont::System);
    filter_title->setStyleSheet("QLabel { background-color : white; color : #e60077; }");
    layout->addWidget(filter_title);

    //auto* movie_filter_layout = new QFormLayout{};
    filterLineEdit->setStyleSheet("color: darkBlue;  background-color: white");
    layout->addWidget(this->filterLineEdit);
    filterButton->setStyleSheet("QPushButton"
                                "{"
                                "background-color : #ffcce6;"
                                "}"
                                "QPushButton::pressed"
                                "{"
                                "background-color : #ff0084;"
                                "}"
    );
    layout->addWidget(this->filterButton);
    //layout->addLayout(movie_filter_layout);

    //o
    auto* list_filtered_layout = new QGridLayout{};
    list_filtered_layout->addWidget(this->filter_movie_list_widget, 0, 0);
    layout->addLayout(list_filtered_layout);

}

int UserGUI::getSelectedIndexPlaylist() const {
    if (this->playlist_list_widget->count() == 0)
    {
        return -1;
    }

    QModelIndexList  index = this->playlist_list_widget->selectionModel()->selectedRows();

    if (index.size() == 0)
    {
        this->titleLineEdit->clear();
        this->genreLineEdit->clear();
        this->yearLineEdit->clear();
        this->likesLineEdit->clear();
        this->linkLineEdit->clear();

        return -1;
    }
    std::cout<<index.at(0).row()<<std::endl;
    return index.at(0).row();
}

int UserGUI::getSelectedIndexMovies() const {
    if (this->movie_list_widget->count() == 0)
    {
        return -1;
    }

    QModelIndexList  index = this->movie_list_widget->selectionModel()->selectedRows();

    if (index.size() == 0)
    {
        this->titleLineEdit->clear();
        this->genreLineEdit->clear();
        this->yearLineEdit->clear();
        this->likesLineEdit->clear();
        this->linkLineEdit->clear();

        return -1;
    }

    return index.at(0).row();
}

void UserGUI::nextMovie() {
    this->index++;
    this->index %= this->serv->GetAll().size();
    std::string command_link = "start " + user_sv->GetCurrentMovie().GetTrailer();
    system(command_link.c_str());
    this->updateLabels();
}

void UserGUI::addMovie(std::string title, std::string genre, size_t year, size_t likes, std::string link) {
    std::string text = "Movie added succesfully!";
    try
    {
        this->user_sv->AddToWatchList(Movie(title, genre, year, likes, link));
        emit updateWatchListSignal();
        emit nextSignal();
    }
    catch (ValidationException error)
    {
        text = error.getMessage();
    }

    QMessageBox msgBox;
    msgBox.setText(text.c_str());
    msgBox.exec();
}

void UserGUI::removeMovie(std::string title) {
    std::string text = "Movie removed succesfully!";

    try
    {
        this->user_sv->WatchMovie(title, true);
        emit updateWatchListSignal();

    }
    catch (ValidationException error)
    {
        text = error.getMessage();
    }

    QMessageBox msgBox;
    msgBox.setText(text.c_str());
    msgBox.exec();
}

void UserGUI::filterMovie(std::string genre) {
    std::string text = "Please enter genre";

    if (genre.size())
    {
        this->user_sv->FilterByGenre(genre);
        emit updateFilterListSignal();
    }
    else {
        QMessageBox msg;
        msg.setText(text.c_str());
        msg.exec();
    }
}

void UserGUI::AddMovieHandler()
{
    int year = atoi(this->yearLineEdit->text().toStdString().c_str());
    int likes = atoi(this->likesLineEdit->text().toStdString().c_str());
    std::string title = this->titleLineEdit->text().toStdString();
    std::string genre = this->genreLineEdit->text().toStdString();
    std::string link = this->linkLineEdit->text().toStdString();

    emit addMovieSignal(title, genre, year, likes, link);
}

void UserGUI::RemoveMovieHandler()
{
    int id = this->getSelectedIndexPlaylist();
    Movie mov;

    if (id != -1)
    {
        mov = this->user_sv->GetMovieList()[id];

        std::string title = mov.GetTitle();

        emit removeMovieSignal(title);
    }

    else {
        QMessageBox mess;
        mess.setText("Please select the movie you want to remove!");
        mess.exec();
    }
}

void UserGUI::nextMovieHandler()
{
    emit nextSignal();
}

void UserGUI::guiFilterMovies()
{
    std::string genre = this->filterLineEdit->text().toStdString();
    emit filterSignal(genre);
}

void UserGUI::fileHandler()
{
    if (csvButton->isChecked())
    {
        this->user_sv->SetWriteMode("CSV");
    }
    else if (htmlButton->isChecked())
    {
        this->user_sv->SetWriteMode("HTML");
    }
    if (this->user_sv->GetWriteMode() == "CSV")
    {
        this->user_sv->WriteData();

        std::string command = "notepad " + this->user_sv->GetFileName();

        system("D:");
        system("cd Ama\\ubb\\year1\\sem2\\oop\\a9-912-farcas-amaliamaria - Copy\\moviedatabase");
        system(command.c_str());
    }
    else
    {
        this->user_sv->WriteData();

        system("D:");
        system("cd Ama\\ubb\\year1\\sem2\\oop\\a9-912-farcas-amaliamaria - Copy\\moviedatabase");
        system(this->user_sv->GetFileName().c_str());
    }
}

void UserGUI::updateLabels()
{
    Movie m = this->serv->GetAll()[index];

    this->titleLineEdit->setText(QString::fromStdString(std::string(m.GetTitle())));
    this->genreLineEdit->setText(QString::fromStdString(std::string(m.GetGenre())));
    this->yearLineEdit->setText(QString::fromStdString(std::to_string(m.GetYear())));
    this->likesLineEdit->setText(QString::fromStdString(std::to_string(m.GetLikes())));
    this->linkLineEdit->setText(QString::fromStdString(std::string(m.GetTrailer())));
}

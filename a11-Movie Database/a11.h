#ifndef A11_A11_H
#define A11_A11_H

#include <QtWidgets/QWidget>
#include "adminservice.h"
#include "userservice.h"
#include <qlabel.h>
#include <qpushbutton.h>
#include <QLineEdit>
#include <QListWidget>
#include <QBoxLayout>
#include <QFormLayout>
#include <qlistwidget.h>
#include <qradiobutton.h>

QT_BEGIN_NAMESPACE
namespace Ui { class a11; }
QT_END_NAMESPACE

class a11 : public QWidget {
Q_OBJECT

public:
    //explicit a11(QWidget *parent = nullptr);
    a11(AdminServices* sv, UserServices* us_sv);

    ~a11();
    //~a11() override;

private:
    AdminServices* serv;
    UserServices* user_sv;
    void initGui();
    QLabel* title_widget;
    QLabel* text_w;
    QPushButton* admin_button;
    QPushButton* user_button;
    void showAdmin();
    void showUser();
    void connectSignalAndSlots();
    Ui::a11 *ui;
};

class AdminGUI : public QWidget {
    Q_OBJECT
private:
    AdminServices* serv;
    void initAdminGui();
    QLabel* title_widget;
    QLabel* text_w;
    QListWidget* movie_list_widget;
    QLineEdit* titleLineEdit, * genreLineEdit, * yearLineEdit, * likesLineEdit, * linkLineEdit;
    QPushButton* addButton, * deleteButton, * updateButton, * chartButton;

    void populateList();
    void connectSignalAndSlots();
    void guiAddMovie();
    void guiDeleteMovie();
    void guiUpdateMovie();
    void displayChart();
    [[nodiscard]] int getSelectedIndex() const;

    QWidget* chart_window;
public:
    AdminGUI(QWidget* parent, AdminServices* serv);
    ~AdminGUI();

public:
signals: void updateMoviesSignal();
signals: void addMovieSignal(std::string title, std::string genre, size_t year, size_t likes, std::string link);
signals: void removeMovieSignal(std::string title);
signals: void updateMovieSignal(std::string t, std::string title, std::string genre, size_t year, size_t likes, std::string link);


public slots: void addMovie(std::string title, std::string genre, size_t year, size_t likes, std::string link);
public slots: void removeMovie(std::string title);
public slots: void updateMovie(std::string t, std::string title, std::string genre, size_t year, size_t likes, std::string link);

};

class UserGUI : public QWidget {
Q_OBJECT
private:
    UserServices* user_sv;
    AdminServices* serv;
    QLabel* title_widget;
    QLabel* text_w;
    QListWidget* movie_list_widget, * playlist_list_widget, * filter_movie_list_widget;
    QLineEdit* titleLineEdit, * genreLineEdit, * yearLineEdit, * likesLineEdit, * linkLineEdit, * titleFilterLineEdit, * genreFilterLineEdit, * filterLineEdit;
    QPushButton* addButton, * removeButton, * filterButton, * openListButton, *nextButton;
    QRadioButton* csvButton, * htmlButton;
    bool repoTypeSelected, filtered;
    void populateMovieList();
    void populatePlaylistList();
    void populateFilterList();
    void connectingSignalsAndSlots();
    void initUserGui();
    int getSelectedIndexMovies() const;
    int getSelectedIndexPlaylist() const;
    void AddMovieHandler();
    void RemoveMovieHandler();
    void nextMovieHandler();
    void guiFilterMovies();
    void fileHandler();
    void updateLabels();

    int index;
public:
    UserGUI(QWidget* parent, AdminServices* serv, UserServices* us_sv);
    ~UserGUI();
public:
signals: void nextSignal();
signals: void updateWatchListSignal();
signals: void addMovieSignal(std::string title, std::string genre, size_t year, size_t likes, std::string link);
signals: void removeMovieSignal(std::string title);
signals: void filterSignal(std::string genre);
signals: void updateFilterListSignal();

public slots: void nextMovie();
public slots: void addMovie(std::string title, std::string genre, size_t year, size_t likes, std::string link);
public slots: void removeMovie(std::string title);
public slots: void filterMovie(std::string genre);
};

#endif //A11_A11_H

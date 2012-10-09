#ifndef AMUWINDOW_H
#define AMUWINDOW_H

#include <QMainWindow>
#include "ui_amuwindow.h"

class AmuView;

class AmuWindow : public QMainWindow, public Ui::AmuWindow
{
    Q_OBJECT
    
public:
    AmuWindow(QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *event);
    
private slots:
    void openRecentProject();
    void updateStatusBar();
    void windowModified();

    void on_actionNew_triggered();

    bool on_actionSave_triggered();

private:
    void createActions();

    void writeSettings();
    void readSettings();

    void updateRecentProjectActions();
    void loadProject(const QString &flieName);
    void saveProject(const QString &fileName);
    void setCurrentProject(const QString &fileName);
    bool saveToClose();

    AmuView *view;

    QString *curProject;
    QStringList *recentProjects;
    enum { MaxRecentProjects = 5 };
    QAction *recentFileActions[MaxRecentProjects];

};

#endif // AMUWINDOW_H

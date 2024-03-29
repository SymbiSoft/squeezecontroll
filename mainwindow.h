/*
    Copyright (C) 2010 Michael Rahr

    This file is part of SqueezeRemote.

    SqueezeRemote is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License.

    SqueezeRemote is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SqueezeRemote.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtDebug>
#include <QSettings>
#include "databasehandler.h"
#include "squeezecli.h"
#include "database_struct.h"
#include "SqueezeStatus.h"
#include "squeezeboxhelper.h"
#include "squeezelistner.h"
#include "getalbumcover.h"
#include <QListWidget>
#include <QTimer>
#include <QTime>
#include <QPropertyAnimation>
#include <QRadioButton>
#include "SqueezePlayer.h"
#include "SqueezeSearch.h"
//#include <QtNetwork>
//#include <qmobilityglobal.h>
//#include <qnetworksession.h>
//#include <QNetworkConfigurationManager>


enum {s_none,s_sync,s_analyze,s_power,s_start,s_start2,s_start3,s_start4,s_start5,s_start6};//State for more that one networkcommand
enum {mode_album,mode_fav};
namespace Ui
{
    class MainWindow;

}
//QTM_USE_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QList<allAlbum> allAlbums;
    QList<allAlbum> allFavorites;
    QList<SqueezeSearchAlbum> searchAlbum;
    QList<SqueezeSearchTrack> searchTrack;
    QList<SqueezeSearchContributor> searchContributor;
    QList<SqueezePlayer> playerStatus;
    QList<allAlbum> trackListe;

    QPoint oldPos;
    QString nowLabel;
    QString currentView;
    QString maxFav;
    QTimer *t;
    QTimer *UIInsertPanelTimer;
    QTimer *UITimeout;
    QPixmap *albumArt;
    //QNetworkSession* session;

    QPropertyAnimation *animation,*insertAnimation;
    QPropertyAnimation *networkGroupAnimation;
    QPropertyAnimation *squeezeCenterGroupAnimation;
    QPropertyAnimation *squeezeSyncAnimation;

    QString oldAlbum;
    QString oldTitle;
    QString oldNumOfTracks;

    int curIndex;
    dataBaseHandler *myMusic;
    squeezeCli *myClihandler;
    squeezeListner *mySqueezeListner;
    GetAlbumCover *myAlbumCover;
    int state;
    int oldVolumen;
    int numOfIttr;
    int divider;
    div_t answer;
    bool get_track;
    int playmode;


    squeezeboxHelper *mySqueezeHelper;

    allAlbum myAlbum;
    SqueezeStatus myStatus;
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void rollwidget(bool dir);
    void getSettings();
    void setSettings();
    void upDateUI();
    void upDateUIPage();
    void upDateAlbumList();
    void syncDatabase();
    void nextState(); //Used for sending more that one network command, but not react before received data;
    void getServerStatus();
    void getPlayerInfo();
    void getNumberOfPlayers();
    void resetStatus();
    void getAllAlbums();




    QString ip_addr;
    QString port_nr;
    QString http_port_nr;
    QString last_sync;
    bool autoconnect;
    bool ignor_volume_command;
    bool networkGroup;
    QTime nowPressed;



private slots:


    void on_play_released();
    void on_verticalSlider_sliderMoved(int position);
    void on_Add_clicked();
    void on_play_3_clicked();
    void on_trackliste_clicked(QModelIndex index);
    void on_contributor_clicked(QModelIndex index);
    void on_album_clicked(QModelIndex index);
    void on_album_entered(QModelIndex index);
    void on_trackliste_doubleClicked(QModelIndex index);
    void on_album_doubleClicked(QModelIndex index);
    void on_contributor_doubleClicked(QModelIndex index);
    void on_search_clicked();
    void on_pushButton_8_clicked();
    void on_SqueezeCenter_clicked();
    void on_Network_clicked();

    void on_TestButton_clicked();

    void on_ControlBox_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void removePanel();
    void insertPanel();
    void startAniTimer();
    void on_lineEdit_returnPressed();
    void on_receive_albumcover(QPixmap *p);
    void on_pushButton_4_clicked();
    void on_Settings_clicked();
    void on_back_clicked();
    void on_forward_clicked();
    void on_back_2_clicked();
    void on_forward_2_clicked();
    void on_back_3_clicked();
    void on_forward_3_clicked();
    void on_back_4_clicked();
    void on_forward_4_clicked();



    void on_ff_clicked();
    void on_skib_f_3_clicked();
    void on_pause_clicked();
    void on_on_clicked();
    void on_volume_2_clicked();
    void on_volume_clicked();
    void on_skib_f_clicked();
    void on_stop_clicked();
    void on_play_clicked();
    void on_skib_b_clicked();
    void on_power_sliderReleased();
    void on_power_valueChanged(int value);
    void on_play_2_clicked();
    void on_skib_b_2_clicked();
    void on_skib_f_2_clicked();
    void on_stop_2_clicked();
    void on_on_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void receiveString(QString data);
    void receiveStatus(QString data);
    void playItem(QListWidgetItem* index);
    void flickPlayAlbum(int index);
    void playTrack(int index);
    void widgetChanged(int page);
    void end_of_offset(int offset);
    void longPress(int index);

    void httpError(QString);

};

#endif // MAINWINDOW_H

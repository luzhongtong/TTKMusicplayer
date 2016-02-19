#ifndef MUSICMOBILEDEVICESWIDGET_H
#define MUSICMOBILEDEVICESWIDGET_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2014 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QLabel>
#include "musicobject.h"
#include "musicglobaldefine.h"

class QToolButton;

class MUSIC_TOOLSET_EXPORT MusicMobileDevicesWidget : public QLabel
{
    Q_OBJECT
public:
    explicit MusicMobileDevicesWidget(QWidget *parent = 0);
    ~MusicMobileDevicesWidget();

Q_SIGNALS:

public Q_SLOTS:
    void showMobileManager();

protected:
    QToolButton *m_closeButton;
    QToolButton *m_openButton;

};

#endif // MUSICMOBILEDEVICESWIDGET_H
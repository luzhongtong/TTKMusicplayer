#include "musiclrcfloatwidget.h"
#include "musiclrcfloatphotowidget.h"
#include "musiclrcfloatsettingwidget.h"

#include <QPushButton>
#include <QVBoxLayout>

MusicLrcFloatWidget::MusicLrcFloatWidget(QWidget *parent)
    : MusicLrcFloatAbstractWidget(parent)
{
    setStyleSheet("background:rgba(0, 0, 0, 100)");
    m_rectIn = QRect(405, 120, 115, 210);
    m_rectOut = QRect(515, 171, 115, 105);
    setGeometry( m_rectOut );

    m_floatPhotoWidget = new MusicLrcFloatPhotoWidget(parent);
    m_floatPhotoWidget->hide();
    m_floatSettingWidget = new MusicLrcFloatSettingWidget(parent);
    m_floatSettingWidget->hide();

    const QString style = "QPushButton{background:transparent;text-align:left; \
                           color:white;}QPushButton::hover{image:url(:/lrc/shadow);}";
    m_update = new QPushButton(tr(" Update"), this);
    m_search = new QPushButton(tr(" Search"), this);
    m_more = new QPushButton(tr(" More"), this);
    m_wallp = new QPushButton(tr(" Wallp"), this);
    m_photo = new QPushButton(tr(" Photo"), this);

    m_update->setIcon(QIcon(":/lrc/update"));
    m_search->setIcon(QIcon(":/lrc/search"));
    m_more->setIcon(QIcon(":/lrc/more"));
    m_wallp->setIcon(QIcon(":/lrc/wallpaper"));
    m_photo->setIcon(QIcon(":/lrc/photo"));

    m_update->setStyleSheet( style );
    m_search->setStyleSheet( style );
    m_more->setStyleSheet( style );
    m_wallp->setStyleSheet( style );
    m_photo->setStyleSheet( style );

    QVBoxLayout *box = new QVBoxLayout(this);
    box->addWidget(m_update);
    box->addWidget(m_search);
    box->addWidget(m_more);
    box->addWidget(m_wallp);
    box->addWidget(m_photo);
    setLayout(box);

    m_update->setCursor(QCursor(Qt::PointingHandCursor));
    m_search->setCursor(QCursor(Qt::PointingHandCursor));
    m_more->setCursor(QCursor(Qt::PointingHandCursor));
    m_wallp->setCursor(QCursor(Qt::PointingHandCursor));
    m_photo->setCursor(QCursor(Qt::PointingHandCursor));

    connect(m_update, SIGNAL(clicked()), parent, SIGNAL(theCurrentLrcUpdated()));
    connect(m_search, SIGNAL(clicked()), parent, SLOT(searchMusicLrcs()));
    connect(m_photo, SIGNAL(clicked()), m_floatPhotoWidget, SLOT(show()));
    connect(m_more, SIGNAL(clicked()), this, SLOT(showFloatSettingWidget()));
}

MusicLrcFloatWidget::~MusicLrcFloatWidget()
{
    delete m_more, m_update, m_search;
    delete m_wallp, m_photo;
    delete m_floatPhotoWidget;
    delete m_floatSettingWidget;
}

void MusicLrcFloatWidget::showFloatSettingWidget()
{
    animationOut();
    m_floatSettingWidget->show();
}
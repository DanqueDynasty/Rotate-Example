#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Rotation Example");
    initGUI();
}

MainWindow::~MainWindow()
{

}

void MainWindow::updateX(int value)
{
    x_valueDisp->setText(QString::number(value));
    viewport->updateX_Axis(value);
}

void MainWindow::updateY(int value){
    y_valueDisp->setText(QString::number(value));
    viewport->updateY_Axis(value);
}

void MainWindow::updateZ(int value){
    z_valueDisp->setText(QString::number(value));
    viewport->updateZ_Axis(value);
}

void MainWindow::reset()
{
    xSlider->setValue(0);
    ySlider->setValue(0);
    zSlider->setValue(0);
}

void MainWindow::initGUI()
{
    vis = new Matrix_Vis(this);

    defaultRotChkBx = new QRadioButton("Default", this);
    defaultRotChkBx->setChecked(true);
    quatRotChkBx = new QRadioButton("Quaternion", this);

    auto resetBtn = new QPushButton("Reset", this);

    auto modeLayout = new QHBoxLayout;
    modeLayout->addWidget(defaultRotChkBx);
    modeLayout->addWidget(quatRotChkBx);

    auto modeGroupBox = new QGroupBox(this);
    modeGroupBox->setTitle("Rotation Mode");
    modeGroupBox->setLayout(modeLayout);

    auto xLbl = new QLabel("X: ", this);
    x_valueDisp = new QLabel("0.00", this);
    auto xLayout = new QHBoxLayout;
    xLayout->addWidget(xLbl);
    xLayout->addWidget(x_valueDisp);

    auto xGroup = new QGroupBox(this);
    xGroup->setLayout(xLayout);

    xSlider = new QSlider(this);
    xSlider->setOrientation(Qt::Horizontal);
    xSlider->setMinimum(-360);
    xSlider->setMaximum(360);
    auto xControlLayout = new QVBoxLayout;
    xControlLayout->addWidget(xGroup);
    xControlLayout->addWidget(xSlider);

    auto yLbl = new QLabel("Y: ", this);
    y_valueDisp = new QLabel("0.00", this);
    auto yLayout = new QHBoxLayout;
    yLayout->addWidget(yLbl);
    yLayout->addWidget(y_valueDisp);

    auto yGroup = new QGroupBox(this);
    yGroup->setLayout(yLayout);

    ySlider = new QSlider(this);
    ySlider->setOrientation(Qt::Horizontal);
    ySlider->setMinimum(-360);
    ySlider->setMaximum(360);
    auto yControlLayout = new QVBoxLayout;
    yControlLayout->addWidget(yGroup);
    yControlLayout->addWidget(ySlider);

    auto zlbl = new QLabel("Z: ", this);
    z_valueDisp = new QLabel("0.00", this);
    auto zLayout = new QHBoxLayout;
    zLayout->addWidget(zlbl);
    zLayout->addWidget(z_valueDisp);

    auto zGroup = new QGroupBox(this);
    zGroup->setLayout(zLayout);

    zSlider = new QSlider(this);
    zSlider->setOrientation(Qt::Horizontal);
    zSlider->setMinimum(-360);
    zSlider->setMaximum(360);
    auto zControlLayout = new QVBoxLayout;
    zControlLayout->addWidget(zGroup);
    zControlLayout->addWidget(zSlider);

    auto controlLayout = new QVBoxLayout;
    controlLayout->addWidget(modeGroupBox);
    controlLayout->addLayout(xControlLayout);
    controlLayout->addLayout(yControlLayout);
    controlLayout->addLayout(zControlLayout);
    controlLayout->addWidget(vis);
    controlLayout->addWidget(resetBtn);
    controlLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

    auto controlWidget = new QWidget(this);
    controlWidget->setLayout(controlLayout);

    viewport = new Viewport(this);
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(3, 2);
    format.setProfile(QSurfaceFormat::CoreProfile);
    viewport->setFormat(format);

    auto splitter = new QSplitter(this);
    splitter->setOrientation(Qt::Horizontal);
    splitter->addWidget(viewport);
    splitter->addWidget(controlWidget);

    setCentralWidget(splitter);
    connect(defaultRotChkBx, SIGNAL(toggled(bool)), viewport, SLOT(toggleRotationMode(bool)));
    connect(xSlider, SIGNAL(valueChanged(int)), SLOT(updateX(int)));
    connect(ySlider, SIGNAL(valueChanged(int)), SLOT(updateY(int)));
    connect(zSlider, SIGNAL(valueChanged(int)), SLOT(updateZ(int)));
    connect(viewport, SIGNAL(modelUpdated(Matrix4f)), vis, SLOT(updateData(Matrix4f)));
    connect(resetBtn, SIGNAL(clicked()), SLOT(reset()));
}

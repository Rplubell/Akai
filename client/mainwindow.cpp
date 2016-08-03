#include <iostream>

#include "mainwindow.h"


MainWindow::MainWindow(QHostAddress serverHost, qint16 serverPort)
{
    m_network = new Network(serverHost, serverPort, this);
    m_audio   = new Audio(this);
    setupUI();
}


MainWindow::~MainWindow()
{
}


void MainWindow::setupUI()
{
    setObjectName(QStringLiteral("MainWindow"));
    resize(800, 600);

    addFriendAction = new QAction(this);
    createChatAction = new QAction(this);

    m_messageWidget = new QWidget(this);
    m_gridLayout = new QGridLayout(m_messageWidget);

    m_mainSplit = new QSplitter(m_messageWidget);
    m_mainSplit->setOrientation(Qt::Horizontal);

    m_messageList = new MessageList(m_mainSplit);

    m_mainSplit->addWidget(m_messageList);

    m_messageSplit = new QSplitter(m_mainSplit);
    m_messageSplit->setOrientation(Qt::Vertical);
    m_messageHistory = new MessageHistory(m_messageSplit);
    m_messageSplit->addWidget(m_messageHistory);
    m_messageInput = new MessageInput(m_messageSplit);
    m_messageSplit->addWidget(m_messageInput);
    m_mainSplit->addWidget(m_messageSplit);

    m_gridLayout->addWidget(m_mainSplit, 0, 0, 1, 1);

    setCentralWidget(m_messageWidget);
    menubar = new QMenuBar(this);
    friendsMenu = new QMenu(menubar);
    chatsMenu = new QMenu(menubar);
    menuOptions = new QMenu(menubar);
    setMenuBar(menubar);
    statusbar = new QStatusBar(this);
    setStatusBar(statusbar);

    menubar->addAction(friendsMenu->menuAction());
    menubar->addAction(chatsMenu->menuAction());
    menubar->addAction(menuOptions->menuAction());
    friendsMenu->addAction(addFriendAction);
    chatsMenu->addAction(createChatAction);

    retranslateUI();

    m_loginDialog = new LoginDialog(this);
    m_addFriendDialog = new AddFriendDialog(this);
    connect(m_loginDialog, &LoginDialog::login, m_network, &Network::login);

    connect(m_messageInput, &MessageInput::sendMessage, m_messageHistory, &MessageHistory::sendMessage);
    connect(m_messageHistory, &MessageHistory::sendUserMessage, m_network, &Network::sendUserMessage);
    connect(m_network, &Network::recvUserMessage, m_messageHistory, &MessageHistory::recvUserMessage);
    connect(m_network, &Network::sentUserMessage, m_messageHistory, &MessageHistory::sentUserMessage);

    connect(m_messageList, &MessageList::friendSelected, m_messageHistory, &MessageHistory::friendSelected);
    connect(m_messageHistory, &MessageHistory::addUser, m_messageList, &MessageList::addFriend);
    connect(m_network, &Network::updateFriends, m_messageList, &MessageList::updateFriends);

    connect(addFriendAction, &QAction::triggered, m_addFriendDialog, &AddFriendDialog::show);
    connect(m_network, &Network::updateUsers, m_addFriendDialog, &AddFriendDialog::updateUsers);
    connect(m_network, &Network::updateFriends, m_addFriendDialog, &AddFriendDialog::updateFriends);
    connect(m_addFriendDialog, &AddFriendDialog::listUsers, m_network, &Network::listUsers);
    connect(m_addFriendDialog, &AddFriendDialog::listFriends, m_network, &Network::listFriends);
    connect(m_addFriendDialog, &AddFriendDialog::addFriend, m_network, &Network::addFriend);

    m_loginDialog->show();
}


void MainWindow::retranslateUI()
{
    setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
    addFriendAction->setText(QApplication::translate("MainWindow", "Add Friend", 0));
    createChatAction->setText(QApplication::translate("MainWindow", "Create Chat", 0));
    friendsMenu->setTitle(QApplication::translate("MainWindow", "&Friends", 0));
    chatsMenu->setTitle(QApplication::translate("MainWindow", "&Chats", 0));
    menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0));
}

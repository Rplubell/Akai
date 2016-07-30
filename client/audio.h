#ifndef H_AUDIO
#define H_AUDIO

#include <QtNetwork/QUdpSocket>
#include <QtMultimedia/QAudioFormat>
#include <QtMultimedia/QAudioInput>
#include <QtMultimedia/QAudioOutput>


class Audio: public QUdpSocket
{
private:
    //TODO we probably want seprate formats for input and output
    QAudioFormat m_format;
    QAudioInput  *m_input;
    QAudioOutput *m_output;

public:
    Audio();
    ~Audio();

    void init();

private slots:
    void readDatagrams();
};

#endif
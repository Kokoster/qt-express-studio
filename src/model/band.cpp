#include "band.h"

#include <QSize>

#include "point.h"
#include "instrument.h"

Band::Band(QSize mainWindowSize)
{
    Point guitarPosition(mainWindowSize.width()  / 8 - 50,
                         mainWindowSize.height() / 2);
    std::unique_ptr<Instrument> guitar(new Instrument(":/instruments/instruments/Guitars/main_guitar/guitar.png",
                                                      ":/instruments/instruments/Guitars/main_guitar/disabled_guitar.png",
                                                      "qrc:/tracks/tracks/main_vocal_voice.mp3", guitarPosition));

    instruments.push_back(std::move(guitar));

    Point drumsPosition(mainWindowSize.width() / 2,
                        mainWindowSize.height() / 2 - mainWindowSize.height() / 12);
    std::unique_ptr<Instrument> drums(new Instrument(":/instruments/instruments/Drums/drums.png",
                                                     ":/instruments/instruments/Drums/disabled_drums.png",
                                                     "qrc:/tracks/tracks/drums.mp3", drumsPosition));
    instruments.push_back(std::move(drums));
}

void Band::toggleInstrument(int index) {
    bool isPlaying = false;
    for (int i = 0; i < instruments.size(); ++i) {
        if (instruments[i]->isPlaying()) {
            isPlaying = true;
            break;
        }
    }

    instruments[index]->toggle();

    if (!isPlaying) {
        for (int i = 0; i < instruments.size(); ++i) {
            instruments[i]->restart();
        }
    }
}

std::vector<std::unique_ptr<Instrument>> const& Band::getInstruments() {
    return instruments;
}




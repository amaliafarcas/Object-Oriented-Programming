//
// Created by Ama on 7/2/2022.
//

#include "screenWriter.h"

ScreenWriter::ScreenWriter() : name{""}, expertise{""}{
}

ScreenWriter::~ScreenWriter() {
}

ScreenWriter::ScreenWriter(std::string name, std::string expertise) : name{name}, expertise{expertise}{
}

std::string ScreenWriter::getName() {
    return name;
}

std::string ScreenWriter::getExpertise() {
    return expertise;
}

std::ostream &operator<<(std::ostream &os, const ScreenWriter &writer) {
    return os<<writer.name<<" "<<writer.expertise<<"\n";
}

std::istream &operator>>(std::istream &is, ScreenWriter &writer) {
    return is>>writer.name>>writer.expertise;
}

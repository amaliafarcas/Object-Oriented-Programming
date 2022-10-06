//
// Created by Ama on 7/2/2022.
//

#ifndef SCREENWRITTER_SCREENWRITER_H
#define SCREENWRITTER_SCREENWRITER_H
#pragma once
#include <iostream>

class ScreenWriter {
public:
    ScreenWriter();
    ScreenWriter(std::string name, std::string expertise);
    ~ScreenWriter();

    std::string getName();
    std::string getExpertise();

    friend std::ostream& operator<<(std::ostream& os, const ScreenWriter& writer);
    friend std::istream& operator>>(std::istream& is, ScreenWriter& writer);

private:
    std::string name;
    std::string expertise;
};


#endif //SCREENWRITTER_SCREENWRITER_H

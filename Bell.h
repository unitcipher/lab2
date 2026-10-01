#pragma once
#ifndef BELL_H
#define BELL_H

class Bell {
private:
    bool nextIsDing;

public:
    Bell();
    void sound();
};

#endif
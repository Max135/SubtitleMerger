//
// Created by Max on 2021-05-09.
//

#ifndef SUBTITLEMERGE_BLOCK_H
#define SUBTITLEMERGE_BLOCK_H


#include <string>
#include "TimeStamp.h"

class Block {
public:
    Block ();

    bool empty();

    std::string getTimeStampString();

    int index;
    TimeStamp from;
    TimeStamp to;
    std::string content;
};


#endif //SUBTITLEMERGE_BLOCK_H

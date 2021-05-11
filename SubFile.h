//
// Created by Max on 2021-05-09.
//

#ifndef SUBTITLEMERGE_SUBFILE_H
#define SUBTITLEMERGE_SUBFILE_H


#include <fstream>
#include "Block.h"

class SubFile {
public:
    SubFile (const std::string& fileName);

    Block getNextBlock();

private:
    std::string getNextLine();

    std::string temp;
    std::ifstream file;
};


#endif //SUBTITLEMERGE_SUBFILE_H

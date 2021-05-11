//
// Created by Max on 2021-05-09.
//

#include "SubFile.h"

SubFile::SubFile(const std::string &fileName) {
    file = std::ifstream(fileName);
}

Block SubFile::getNextBlock() {
    std::string line;
    int pos = 0;
    Block block;

    while (!(line = getNextLine()).empty()) {
        if (pos == 0) {
            block.index = std::stoi(line);
        } else if (pos == 1) {
            TimeStamp from{};
            from.init(line.substr(0, line.find('-')));
            block.from = from;

            TimeStamp to{};
            to.init(line.substr(line.find('>')+1, line.length()));
            block.to = to;
        } else {
            block.content.append(line);
            block.content.append("\n");
        }
        pos++;
    }

    return block;
}

std::string SubFile::getNextLine() {
    temp = "";
    getline(file, temp);
    return temp;
}

//
// Created by Max on 2021-05-09.
//

#include "Block.h"

Block::Block() {
    content = "";
}

bool Block::empty() {
    return content.empty();
}

std::string Block::getTimeStampString() {
    return from.toString().append(" --> ").append(to.toString());
}

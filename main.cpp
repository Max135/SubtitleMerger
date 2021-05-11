#include <iostream>
#include "SubFile.h"

void appendBlockToFile(std::ofstream *MergedSubtitles, Block block, int index);

int main() {
    std::ofstream MergedSubtitles("mergedTranslation.srt");

    SubFile primary("primary.srt");
    SubFile secondary("secondary.srt");

//    SubFile empty("empty.txt");
    Block primaryBlock = primary.getNextBlock();;
    Block secondaryBlock = secondary.getNextBlock();
    Block lastPrimaryBlock = primaryBlock;
    Block nextPrimaryBlock = primary.getNextBlock();
    int index = 1;

    while (true) {
        if (index == 124) {
            int i = 0;
        }

        if (primaryBlock.empty()) break;

        if (!secondaryBlock.empty() &&
            (secondaryBlock.from > primaryBlock.from || secondaryBlock.to > primaryBlock.to)) {
            appendBlockToFile(&MergedSubtitles, primaryBlock, index);
            lastPrimaryBlock = primaryBlock;
            primaryBlock = nextPrimaryBlock;
            nextPrimaryBlock = primary.getNextBlock();
        } else if (!secondaryBlock.empty()
                   && ((secondaryBlock.from < primaryBlock.to && secondaryBlock.from > primaryBlock.from)
                   || (secondaryBlock.to < primaryBlock.to && secondaryBlock.to > primaryBlock.from)
                   || (secondaryBlock.from < nextPrimaryBlock.to && secondaryBlock.from > nextPrimaryBlock.from)
                   || (secondaryBlock.to < nextPrimaryBlock.to && secondaryBlock.to > nextPrimaryBlock.from)
                   || (secondaryBlock.from < lastPrimaryBlock.to && secondaryBlock.from > lastPrimaryBlock.from)
                   || (secondaryBlock.to < lastPrimaryBlock.to && secondaryBlock.to > lastPrimaryBlock.from))) {

//            appendBlockToFile(&MergedSubtitles, primaryBlock, index);
//            lastPrimaryBlock = primaryBlock;
//            primaryBlock = nextPrimaryBlock;
//            nextPrimaryBlock = primary.getNextBlock();
            secondaryBlock = secondary.getNextBlock();
        } else if (!secondaryBlock.empty() && (secondaryBlock.to < primaryBlock.from)) {
            appendBlockToFile(&MergedSubtitles, secondaryBlock, index);
            secondaryBlock = secondary.getNextBlock();
        } else {
            appendBlockToFile(&MergedSubtitles, primaryBlock, index);
            lastPrimaryBlock = primaryBlock;
            primaryBlock = nextPrimaryBlock;
            nextPrimaryBlock = primary.getNextBlock();
        }

        index++;
    }

    MergedSubtitles.close();
    return 0;
}

void appendBlockToFile(std::ofstream *MergedSubtitles, Block block, int index) {
    *MergedSubtitles << index;
    *MergedSubtitles << std::endl;
    *MergedSubtitles << block.getTimeStampString();
    *MergedSubtitles << std::endl;
    *MergedSubtitles << block.content;
    *MergedSubtitles << std::endl;
}

//If end time (secondary) < start time (primary) -> append (secondary) (do not skip primary)
//else if start time (secondary) between start and end (primary) -> append (primary) + skip (secondary)
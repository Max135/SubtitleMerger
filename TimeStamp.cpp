//
// Created by Max on 2021-05-09.
//

#include "TimeStamp.h"

void TimeStamp::init(std::string timestamp) {
    timestamp = trim(timestamp);
    hours = splitTime(&timestamp);
    minutes = splitTime(&timestamp);
    seconds = splitTime(&timestamp);
    milliseconds = splitTime(&timestamp);
}

int TimeStamp::splitTime(std::string *timestamp) {
    int endPos = (timestamp->find(':') == std::string::npos) ? timestamp->find(',') : timestamp->find(':');
    std::string temp = timestamp->substr(0, endPos);
    timestamp->erase(0, endPos+1);
    return std::stoi(temp);
}

TimeStamp &TimeStamp::operator=(const TimeStamp &other) {
    if (this == &other)
        return *this;

    this->hours = other.hours;
    this->minutes = other.minutes;
    this->seconds = other.seconds;
    this->milliseconds = other.milliseconds;

    return *this;
}

bool TimeStamp::operator<(const TimeStamp &other) {
    if (this->hours != other.hours) return this->hours < other.hours;
    if (this->minutes != other.minutes) return this->minutes < other.minutes;
    if (this->seconds != other.seconds) return this->seconds < other.seconds;
    return this->milliseconds < other.milliseconds;
}

bool TimeStamp::operator>(const TimeStamp &other) {
    if (this->hours != other.hours) return this->hours > other.hours;
    if (this->minutes != other.minutes) return this->minutes > other.minutes;
    if (this->seconds != other.seconds) return this->seconds > other.seconds;
    return this->milliseconds > other.milliseconds;
}

std::string TimeStamp::toString() {
    std::string time;
    time.append(format(hours, 2)).append(":").append(format(minutes, 2))
    .append(":").append(format(seconds, 2)).append(",").append(format(milliseconds, 3));
    return time;
}

std::string TimeStamp::format(int n, int len) {
    std::string result(len--, '0');
    for (int val=(n<0)?-n:n; len>=0&&val!=0; --len,val/=10)
        result[len]='0'+val%10;
    if (len>=0&&n<0) result[0]='-';
    return result;
}



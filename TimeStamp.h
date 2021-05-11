//
// Created by Max on 2021-05-09.
//

#ifndef SUBTITLEMERGE_TIMESTAMP_H
#define SUBTITLEMERGE_TIMESTAMP_H


#include <string>

class TimeStamp {
public:
    TimeStamp() = default;

    void init(std::string timestamp);

    std::string toString();

    TimeStamp &operator=(const TimeStamp &other);

    bool operator<(const TimeStamp &other);

    bool operator>(const TimeStamp &other);

    int hours, minutes, seconds, milliseconds;

private:
    int splitTime(std::string *timestamp);

    static std::string format(int n, int len);

    //Bullshit because c++ default string library cant trim strings
    std::string &ltrim(std::string &str, const std::string &chars = "\t\n\v\f\r ") {
        str.erase(0, str.find_first_not_of(chars));
        return str;
    }

    std::string &rtrim(std::string &str, const std::string &chars = "\t\n\v\f\r ") {
        str.erase(str.find_last_not_of(chars) + 1);
        return str;
    }

    std::string &trim(std::string &str, const std::string &chars = "\t\n\v\f\r ") {
        return ltrim(rtrim(str, chars), chars);
    }
};


#endif //SUBTITLEMERGE_TIMESTAMP_H

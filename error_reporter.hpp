#ifndef LUNA_ERROR_REPORTER
#define LUNA_ERROR_REPORTER

#include <cstring>
#include <iostream>

//enum ERROR_LEVEL {
//    ERROR,
//    WARNING
//}

class error_reporter {
public:
    void report(const std::string& msg,
            unsigned int line,
            unsigned int pos,
            const std::string& expectation)
    {
        if (errors_number < LIMIT_ERRORS) {
            fprintf(stderr, "Error at line %d-%d:\n\t%s\n", line, pos, msg.c_str());
            // TODO: pos - 1 ???
            fprintf(stderr, "\t%s^---- here\n", repeat_spaces(pos - 1).c_str());
            fprintf(stderr, "Expected: %s\n\n",  expectation.c_str());
        }
        errors_number++;
    }

private:
    int errors_number;
    const int LIMIT_ERRORS = 1000;

    std::string repeat_spaces(const int num) {
        if (num == 0) return "";
        return std::string(num, ' ');
    }
};

#endif
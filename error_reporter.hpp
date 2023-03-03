#ifndef LUNA_ERROR_REPORTER
#define LUNA_ERROR_REPORTER

#include <cstring>
#include <iostream>


enum ERROR_LEVEL {
   ERROR,
   WARNING
};

class error_reporter {
public:

    void report(ERROR_LEVEL level,
        const std::string& error_msg,
        const std::string& error_line,
        unsigned int line,
        unsigned int pos,
        const std::string& expectation = "")
    {
        if (errors_number < LIMIT_ERRORS) {
            std::string lvl = level == ERROR ? "Error" : "Warning";
            fprintf(stderr, "%s. Line %d-%d: %s\n\t%s\n", lvl.c_str(), line, pos, error_msg.c_str(), error_line.c_str());
            fprintf(stderr, "\t%s^---- here\n", repeat_spaces(pos).c_str());

            if (expectation != "") {
                fprintf(stderr, "Expected: %s\n\n",  expectation.c_str());
            }
        }

        if (level == ERROR) {
            errors_number++;
        }
    }

    bool has_errors() const {
        return errors_number != 0;
    }

private:
    unsigned int errors_number = 0;
    const int LIMIT_ERRORS = 1000;

    std::string repeat_spaces(const int num) {
        if (num == 0) return "";
        return std::string(num, ' ');
    }
};

#endif
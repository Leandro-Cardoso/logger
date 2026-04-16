#pragma once

#include "LogEntry.hpp"

namespace logger {

class ILogSink {
public:
    virtual ~ILogSink() = default;
    virtual void write(const LogEntry& entry) = 0;
};

}

#pragma once

#include <string>
#include <chrono>
#include <optional>

#include "LogLevel.hpp"

namespace logger {

struct ProgressInfo {
    size_t current{0};
    size_t total{0};

    float percentage() const {
        if (total == 0) return 0.0f;
        return (static_cast<float>(current) / static_cast<float>(total)) * 100.0f;
    }
};

struct LogEntry {
    LogLevel level;
    std::string message;
    std::chrono::system_clock::time_point timestamp;

    std::optional<ProgressInfo> progress;
};

}

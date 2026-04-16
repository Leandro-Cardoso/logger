#pragma once

#include <vector>
#include <memory>
#include <string>

#include "ILogSink.hpp"
#include "LogLevel.hpp"

namespace logger {

class Logger {
private:
    std::vector<std::shared_ptr<ILogSink>> sinks;

public:
    Logger() = default;
    ~Logger() = default;

    // Evita cópia acidental (logger geralmente é compartilhado)
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Permite movimento
    Logger(Logger&&) = default;
    Logger& operator=(Logger&&) = default;

    // Adiciona um destino de log
    void addSink(std::shared_ptr<ILogSink> sink);

    // Log genérico
    void log(LogLevel level, const std::string& message);

    // Log com progresso
    void logProgress(LogLevel level,
                     const std::string& message,
                     size_t current,
                     size_t total);

    // Helpers por nível
    void debug(const std::string& message);
    void info(const std::string& message);
    void success(const std::string& message);
    void warning(const std::string& message);
    void error(const std::string& message);
};

}

// TODO: Estudar conseitos aplicados.

#include <iostream>
#include <string>
#include <vector>

class File {
public:
    File(const std::string& filename) : filename(filename) {
        std::cout << "📂 Opened: " << filename << "\n";
    }

    ~File() {
        std::cout << "📂 Closed: " << filename << "\n";
    }

    void write(const std::string& content) {
        std::cout << "✏️ Writing to " << filename << ": " << content << "\n";
    }

private:
    std::string filename;
};

class Logger {
public:
    void addLogFile(File* file) {
        logFiles.push_back(file);
    }

    void log(const std::string& msg) {
        for (auto file : logFiles) {
            file->write(msg);
        }
    }

private:
    std::vector<File*> logFiles;  // ❌ Unsafe raw pointers
};

int main() {
    Logger logger;

    File* appLog = new File("app.log");
    File* errorLog = new File("errors.log");

    logger.addLogFile(appLog);
    logger.addLogFile(errorLog);

    logger.log("System started");

    // ❌ Memory leak - files never closed!
    return 0;
}

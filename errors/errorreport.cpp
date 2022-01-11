#include <iostream> 

#include <errors/errorreport.h> 

void ErrorReport::clearErrors() {
    errorMessage.clear();
    status = LoxStatus::OK ;
}

auto ErrorReport::getStatus()->LoxStatus {
    return status;
}

void ErrorReport::printToStdErr() {
    for(auto& s: errorMessage)
      std::cerr << s << std::endl;
}

void ErrorReport::setError(int line, const std::string& message) {
    errorMessage.emplace_back("[Line" + std::to_string(line) + "] Error: " + message);

    status = LoxStatus::ERROR;
}
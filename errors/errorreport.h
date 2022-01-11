#ifndef PHYLANG_ERRORS_ERRORREPORT_H
#define PHYLANG_ERRORS_ERRORREPORT_H 
#pragma once 

#include <string>
#include <vector>

enum struct LoxStatus {
    OK,ERROR
};

class ErrorReport {
    public: 
     void clearErrors();
     auto getStatus()->LoxStatus;
     void printToStdErr();
     void setError(int line, const std::string& message);

  private:
   std::vector<std::string> errorMessage;
   LoxStatus status = LoxStatus::OK;
};

#endif
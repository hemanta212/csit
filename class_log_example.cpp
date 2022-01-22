#include <iostream>

class Log{
  public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;

  private:
    int m_logLevel = 2;

  public:
    void SetLevel(int level){
      m_logLevel = level;
   }
    void Error(const char* message){
      if(m_logLevel >= LogLevelError)
       std::cout << "[Error]: " << message << std::endl;
    }
    void Warn(const char* message){
      if(m_logLevel >= LogLevelWarning)
       std::cout << "[Warn]: " << message << std::endl;
    }
    void Info(const char* message){
      if(m_logLevel >= LogLevelInfo)
       std::cout << "[Info]: " << message << std::endl;
    }
  };

int main(){
    Log log;

    log.Info("Setting level to Error");
    log.SetLevel(log.LogLevelError);
    log.Warn("This is warning!");
    log.Error("This is error!!");


    log.SetLevel(log.LogLevelInfo);
    log.Info("Setting level to Info");
    log.Error("This is error!!");
    log.Warn("This is warning!");
    log.Info("This is info.");

    return 0;
  }

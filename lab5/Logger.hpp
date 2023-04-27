#pragma once
#include <sstream>
#include <fstream>
#include <ios>
#include <ctime>

enum LoggerType
{
    DEBUG, INFO, ERROR, COMPLETION
};

class Logger
{
private:
    static std::ofstream m_out;
    static LoggerType m_LogT;
    std::string m_s;
public:
    Logger() {}

    static void GoFile()
    {
        m_out.open("/Users/a.sagitovich/programming/lab_vscode/2sem/lab5/record.txt", std::ios::app);
    }

    static void SetLoggerType(LoggerType LogT)
    {
        m_LogT = LogT;
    }

    static std::string Message(std::string Type, std::string OutType, std::string Message, std::string OutMessage)
    {
        time_t t = time(nullptr);
        tm* now = localtime(&t);

        std::stringstream ss;

        ss << Type << "[" << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << "] " <<
            Message << "\n";

        std::cerr <<  ss.str();

        m_out << OutType << " [";
        m_out << now->tm_mday << "." << now->tm_mon + 1 << "." << now->tm_year + 1900 << " ";
        m_out << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << "] ";
        m_out << OutMessage << "\n";

        m_out.flush();

        return ss.str();
    }

    static std::string Report(bool flagD, bool flagI, bool flagE, bool flagC)
    {
        std::string Deb = "\033[33m[DEBUG]\033[0m";  // жёлтый
        std::string Inf = "\033[32m[INFO]\033[0m";   // зелёный
        std::string Err = "\033[31m[ERROR]\033[0m";  // красный
        std::string Com = "\033[35m[COMPLETION]\033[0m"; // магнета 

        std::string OutDeb = "{D}"; 
        std::string OutInf = "{I}";
        std::string OutErr = "[[ERROR]]"; 
        std::string OutCom = "{C}";

        std::string DebMes = "\033[33mProgram is start.\033[0m";   
        std::string InfMes = "\033[32mPrint message: \033[0m";  
        std::string ErrMes = "\033[31mError of input. Try again.\033[0m";        
        std::string ComMes = "\033[35mProgram is complete.\033[0m";                      

        std::string OutDebMes = "Программа запущена.";
        std::string OutInfMes = "Выведено сообщение.";
        std::string OutErrMes = "Ошибка ввода."; 
        std::string OutComMes = "Программа завершила свою работу. \n"; 
        
        switch (m_LogT)
        {
            case DEBUG:
                if (flagD == 1)
                    return Logger::Message(Deb, OutDeb, DebMes, OutDebMes);
                else
                    return " ";

            case INFO:
                if (flagI == 1)
                    return Logger::Message(Inf, OutInf, InfMes, OutInfMes);
                else
                    return " ";

            case ERROR:
                if (flagE == 1)    
                    return Logger::Message(Err, OutErr, ErrMes, OutErrMes);
                else
                    return " ";

            case COMPLETION:
                if (flagC == 1)    
                    return Logger::Message(Com, OutCom, ComMes, OutComMes);
                else
                    return " ";
        }
    }
    
    ~Logger() {}
};

std::ofstream Logger::m_out;
LoggerType Logger::m_LogT;

static void Debug(bool flagD)
{
    Logger::SetLoggerType(DEBUG);
    Logger::Report(flagD, false, false, false);
}

static void Info(bool flagI)
{
    Logger::SetLoggerType(INFO);
    Logger::Report(false, flagI, false, false);
}

static void Error(bool flagE)
{
    Logger::SetLoggerType(ERROR);
    Logger::Report(false, false, flagE, false);
}

static void Completion(bool flagC)
{
    Logger::SetLoggerType(COMPLETION);
    Logger::Report(false, false, false, flagC);
}

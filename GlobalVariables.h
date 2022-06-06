#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H
#include <QString>
struct GlobalVariables
{
    static QString studentId;
};

QString GlobalVariables::studentId = "";
#endif // GLOBALVARIABLES_H

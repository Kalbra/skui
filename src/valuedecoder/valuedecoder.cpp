#include "valuedecoder.h"
#include <QDebug>
#include <string>
#include <ctime>

using namespace std;

ValueDecoder::ValueDecoder()
{

}

QString ValueDecoder::Decode(QString str, int value){
    string cppstring = str.toStdString();
    size_t pos;

    time_t t = time(0);
    tm*  now = localtime(&t);

    pos = cppstring.find("$VALUE$");
    if(pos != string::npos){
        cppstring.replace(pos, 7, to_string(value));
    }
    pos = cppstring.find("$TIME_SEC$");
    if(pos != string::npos){
        cppstring.replace(pos, 10, to_string(now->tm_sec));
    }
    pos = cppstring.find("$TIME_MIN$");
    if(pos != string::npos){
        cppstring.replace(pos, 10, to_string(now->tm_min));
    }
    pos = cppstring.find("$TIME_HOUR$");
    if(pos != string::npos){
        cppstring.replace(pos, 11, to_string(now->tm_hour));
    }
    pos = cppstring.find("$TIME_DAY$");
    if(pos != string::npos){
        cppstring.replace(pos, 10, to_string(now->tm_mday));
    }
    pos = cppstring.find("$TIME_YEAR$");
    if(pos != string::npos){
        cppstring.replace(pos, 11, to_string(now->tm_year));
    }


    return QString::fromStdString(cppstring);;
}

#ifndef ORACLE_H
#define ORACLE_H
#include <QSqlDatabase>

class oracle
{
private:
    QSqlDatabase db;

public:
    oracle();
    bool create_cnx();
};

#endif // ORACLE_H

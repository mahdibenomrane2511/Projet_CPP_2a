#include "oracle.h"
//test tutoriel git
oracle::oracle()
{

}
bool oracle::create_cnx(){
bool test=false;
QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("mahdi2511");
db.setUserName("mahdibo");
db.setPassword("mahdibo1");

if(db.open())
 test=true;

return test;


}

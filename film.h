    #ifndef FILM_H
#define FILM_H
#include <QString>

class film
{
public:
    void setnom(QString n);
    void settype(QString n);
    void setdate(QString n);

    QString get_nom();
    QString get_type();
    QString get_date();

    film();
private:
    QString nom, type, date;
};

#endif // FILM_H

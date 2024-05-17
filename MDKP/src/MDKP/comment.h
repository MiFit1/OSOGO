#ifndef COMMENT_H
#define COMMENT_H
#include <QString>
#include <QDateTime>

class Comment
{
public:
    Comment();
    Comment(QString Comment, QString AccountantPesonalData, QString Date);
    QString GetComment();
    QString GetAccountantPesonalData();
    QString GetDate();
    void SetComment(QString Comment);
    void SetAccountantData(QString AccData);
    void SetDate(QString Date);
private:
    QString comment;
    QString accountantPesonalData;
    QString date;
};

#endif // COMMENT_H

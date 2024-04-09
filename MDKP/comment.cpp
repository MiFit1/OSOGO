#include "comment.h"
Comment::Comment(){
}

Comment::Comment(QString Comment, QString AccountantPesonalData, QString Date) {
    comment = Comment;
    accountantPesonalData = AccountantPesonalData;
    date = Date;
}

QString Comment::GetComment(){
    return comment;
}

QString Comment::GetAccountantPesonalData(){
    return accountantPesonalData;
}

QString Comment::GetDate(){
    return date;
}

void Comment::SetComment(QString Comment){
    comment = Comment;
}
void Comment::SetAccountantData(QString AccData){
    accountantPesonalData = AccData;
}
void Comment::SetDate(QString Date){
    date = Date;
}

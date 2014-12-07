#ifndef  __DEBUGDEFINES_H
#define  __DEBUGDEFINES_H


#define myOut() qDebug() << __PRETTY_FUNCTION__ << __LINE__
#define myErr() qDebug() << __PRETTY_FUNCTION__ << __LINE__ << "Error:"

#endif  // __DEBUGDEFINES_H 

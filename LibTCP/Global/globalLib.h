#ifndef GLOBALLIB_H
#define GLOBALLIB_H

#include <QtCore/qglobal.h>

#if defined(_TCP)
#   define TCPSHARED_EXPORT Q_DECL_EXPORT
# else
#   define TCPSHARED_EXPORT Q_DECL_IMPORT
# endif

#endif // GLOBALLIB_H

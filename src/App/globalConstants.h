#ifndef GLOBALCONSTANTS_H
#define GLOBALCONSTANTS_H

#include <QString>

//(It is necessary to define these consts in the current or some other .cpp-file,
//in order to configure connection to DB)
namespace GlobalConstants {
extern const QString db_host_name;
extern const QString db_database_name;
extern const QString db_user_name;
extern const QString db_user_password;
}

#endif // GLOBALCONSTANTS_H

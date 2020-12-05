#include "db_define.h"
#include <libpq-fe.h>
#include <iostream>
#include <string>

int main()
{
    std::string conn_info("dbname=yli user=lee password=asd");
    std::string sql("select * from weather");
    PGconn* conn = PQconnectdb(conn_info.data());
    PGresult* result = PQexec(conn, sql.data());
    int field_num = PQnfields(result);
    for (int i = 0; i < PQntuples(result); ++i)
    {
        for (int j = 0; j < field_num; ++j)
        {
            std::cout << PQgetvalue(result, i, j) << "\t";
        }
        std::cout << std::endl;
    }
    PQclear(result);
    return 1;
}
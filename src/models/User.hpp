#include "../../include/sqlite_orm/include/sqlite_orm/sqlite_orm.h"
#include <string>

struct User {
    int id;
    int age;
    std::string name;
};

auto storage =
    sqlite_orm::make_storage("banana.sqlite",
    sqlite_orm::make_table("users",
        sqlite_orm::make_column("id", &User::id, sqlite_orm::autoincrement(), sqlite_orm::primary_key()),
        sqlite_orm::make_column("age", &User::age),
        sqlite_orm::make_column("name", &User::name)));

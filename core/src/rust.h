#ifndef CRSQLITE_RUST_H
#define CRSQLITE_RUST_H

#include "crsqlite.h"

// Parts of CR-SQLite are written in Rust and parts are in C.
// As we gradually convert more code to Rust, we'll have to expose
// structures to the old C-code that hasn't been converted yet.
// These are those definitions.

int crsql_backfill_table(sqlite3 *db, const char *tblName,
                         const char **zpkNames, int pkCount,
                         const char **zNonPkNames, int nonPkCount,
                         int isCommitAlter, int noTx);
int crsql_is_crr(sqlite3 *db, const char *tblName);
int crsql_compare_sqlite_values(const sqlite3_value *l, const sqlite3_value *r);
int crsql_remove_crr_triggers_if_exist(sqlite3 *db, const char *tblName);

int crsql_init_site_id(sqlite3 *db, unsigned char *ret);
int crsql_init_peer_tracking_table(sqlite3 *db);
int crsql_create_schema_table_if_not_exists(sqlite3 *db);
int crsql_maybe_update_db(sqlite3 *db, char **pzErrMsg);
int crsql_is_table_compatible(sqlite3 *db, const char *tblName, char **err);
int crsql_create_crr(sqlite3 *db, const char *schemaName, const char *tblName,
                     int isCommitAlter, int noTx, char **err);
int crsql_ensure_table_infos_are_up_to_date(sqlite3 *db,
                                            crsql_ExtData *pExtData,
                                            char **err);

#endif

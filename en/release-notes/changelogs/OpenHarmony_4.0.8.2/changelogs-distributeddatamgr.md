
# Distributed Data Management Subsystem Changelog

## cl.distributeddatamgr.1 Replacement of context with a context Without the Optional Identifier

**Change Impact**

For applications developed based on earlier versions, use SDK API version 10 when **context** is used.

**Key API/Component Changes**

Deleted the following:

 ```ts
    /**
     * Indicates datashare extension ability context.
     *
     * @type ?{ ExtensionContext }
     * @syscap SystemCapability.DistributedDataManager.DataShare.Provider
     * @systemapi
     * @StageModelOnly
     * @since 9
     */
    context?: ExtensionContext;
 ```
Added the following:

 ```ts
    /**
     * Indicates datashare extension ability context.
     *
     * @type { ExtensionContext }
     * @syscap SystemCapability.DistributedDataManager.DataShare.Provider
     * @systemapi
     * @StageModelOnly
     * @since 10
     */
    context: ExtensionContext;
 ```

## cl.distributeddatamgr.2 Change of the Return Value Type of Function Pointer Variables in the OH_Predicates Struct from OH_Predicates to OH_Predicates *

**Change Impact**

This change is incompatible with earlier versions. You need to use the new function pointer variables in the **OH_Predicates** struct.

**Key API/Component Changes**

Before the change:

 ```ts
    OH_Predicates (*equalTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
    OH_Predicates (*notEqualTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
    OH_Predicates (*beginWrap)(OH_Predicates *predicates);
    OH_Predicates (*endWrap)(OH_Predicates *predicates);
    OH_Predicates (*orOperate)(OH_Predicates *predicates);
    OH_Predicates (*andOperate)(OH_Predicates *predicates);
    OH_Predicates (*isNull)(OH_Predicates *predicates, const char *field);
    OH_Predicates (*isNotNull)(OH_Predicates *predicates, const char *field);
    OH_Predicates (*like)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
    OH_Predicates (*between)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
    OH_Predicates (*notBetween)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
    OH_Predicates (*greaterThan)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
    OH_Predicates (*lessThan)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
    OH_Predicates (*greaterThanOrEqualTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
    OH_Predicates (*lessThanOrEqualTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
    OH_Predicates (*orderBy)(OH_Predicates *predicates, const char *field, OH_OrderType type);
    OH_Predicates (*distinct)(OH_Predicates *predicates);
    OH_Predicates (*limit)(OH_Predicates *predicates, unsigned int value);
    OH_Predicates (*offset)(OH_Predicates *predicates, unsigned int rowOffset);
    OH_Predicates (*groupBy)(OH_Predicates *predicates, char const *const *fields, int length);
    OH_Predicates (*in)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
    OH_Predicates (*notIn)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
    OH_Predicates (*clear)(OH_Predicates *predicates);
 ```

After the change:

 ```ts
   OH_Predicates *(*equalTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
   OH_Predicates *(*notEqualTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
   OH_Predicates *(*beginWrap)(OH_Predicates *predicates);
   OH_Predicates *(*endWrap)(OH_Predicates *predicates);
   OH_Predicates *(*orOperate)(OH_Predicates *predicates);
   OH_Predicates *(*andOperate)(OH_Predicates *predicates);
   OH_Predicates *(*isNull)(OH_Predicates *predicates, const char *field);
   OH_Predicates *(*isNotNull)(OH_Predicates *predicates, const char *field);
   OH_Predicates *(*like)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
   OH_Predicates *(*between)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
   OH_Predicates *(*notBetween)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
   OH_Predicates *(*greaterThan)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
   OH_Predicates *(*lessThan)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
   OH_Predicates *(*greaterThanOrEqualTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
   OH_Predicates *(*lessThanOrEqualTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
   OH_Predicates *(*orderBy)(OH_Predicates *predicates, const char *field, OH_OrderType type);
   OH_Predicates *(*distinct)(OH_Predicates *predicates);
   OH_Predicates *(*limit)(OH_Predicates *predicates, unsigned int value);
   OH_Predicates *(*offset)(OH_Predicates *predicates, unsigned int rowOffset);
   OH_Predicates *(*groupBy)(OH_Predicates *predicates, char const *const *fields, int length);
   OH_Predicates *(*in)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
   OH_Predicates *(*notIn)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject);
   OH_Predicates *(*clear)(OH_Predicates *predicates);
 ```

**Adaptation Guide**

The sample code is as follows:

Sample code before the change:

```
predicates->beginWrap(predicates).equalTo(predicates, "data1", valueObject).orOperate(predicates);
```

Sample code after the change:

```
predicates->beginWrap(predicates)->equalTo(predicates, "data1", valueObject)->orOperate(predicates);
```

## cl.distributeddatamgr.3 Change of the Error Codes in the OH_Rdb_ErrCode Struct

**Change Impact**

Changed **RDB_ERR_INVALID_ARGS** to **RDB_E_INVALID_ARGS**, and **RDB_ERR_OK** to **RDB_OK**, and added error codes.

**Key API/Component Changes**

Before the change:

 ```ts
  RDB_ERR_INVALID_ARGS = -2,
  RDB_ERR = -1,
  RDB_ERR_OK = 0
 ```

After the change:

 ```ts
    RDB_ERR = -1,
    RDB_OK = 0,
    E_BASE = 14800000,
    RDB_E_NOT_SUPPORTED = 801,
    RDB_E_ERROR = E_BASE,
    RDB_E_INVALID_ARGS = (E_BASE + 1),
    RDB_E_CANNOT_UPDATE_READONLY = (E_BASE + 2),
    RDB_E_REMOVE_FILE = (E_BASE + 3),
    RDB_E_EMPTY_TABLE_NAME = (E_BASE + 5),
    RDB_E_EMPTY_VALUES_BUCKET = (E_BASE + 6),
    RDB_E_EXECUTE_IN_STEP_QUERY = (E_BASE + 7),
    RDB_E_INVALID_COLUMN_INDEX = (E_BASE + 8),
    RDB_E_INVALID_COLUMN_TYPE = (E_BASE + 9),
    RDB_E_EMPTY_FILE_NAME = (E_BASE + 10),
    RDB_E_INVALID_FILE_PATH = (E_BASE + 11),
    RDB_E_TRANSACTION_IN_EXECUTE = (E_BASE + 12),
    RDB_E_INVALID_STATEMENT = (E_BASE + 13),
    RDB_E_EXECUTE_WRITE_IN_READ_CONNECTION = (E_BASE + 14),
    RDB_E_BEGIN_TRANSACTION_IN_READ_CONNECTION = (E_BASE + 15),
    RDB_E_NO_TRANSACTION_IN_SESSION = (E_BASE + 16),
    RDB_E_MORE_STEP_QUERY_IN_ONE_SESSION = (E_BASE + 17),
    RDB_E_NO_ROW_IN_QUERY = (E_BASE + 18),
    RDB_E_INVALID_BIND_ARGS_COUNT = (E_BASE + 19),
    RDB_E_INVALID_OBJECT_TYPE = (E_BASE + 20),
    RDB_E_INVALID_CONFLICT_FLAG = (E_BASE + 21),
    RDB_E_HAVING_CLAUSE_NOT_IN_GROUP_BY = (E_BASE + 22),
    RDB_E_NOT_SUPPORTED_BY_STEP_RESULT_SET = (E_BASE + 23),
    RDB_E_STEP_RESULT_SET_CROSS_THREADS = (E_BASE + 24),
    RDB_E_STEP_RESULT_QUERY_NOT_EXECUTED = (E_BASE + 25),
    RDB_E_STEP_RESULT_IS_AFTER_LAST = (E_BASE + 26),
    RDB_E_STEP_RESULT_QUERY_EXCEEDED = (E_BASE + 27),
    RDB_E_STATEMENT_NOT_PREPARED = (E_BASE + 28),
    RDB_E_EXECUTE_RESULT_INCORRECT = (E_BASE + 29),
    RDB_E_STEP_RESULT_CLOSED = (E_BASE + 30),
    RDB_E_RELATIVE_PATH = (E_BASE + 31),
    RDB_E_EMPTY_NEW_ENCRYPT_KEY = (E_BASE + 32),
    RDB_E_CHANGE_UNENCRYPTED_TO_ENCRYPTED = (E_BASE + 33),
    RDB_E_CHANGE_ENCRYPT_KEY_IN_BUSY = (E_BASE + 34),
    RDB_E_STEP_STATEMENT_NOT_INIT = (E_BASE + 35),
    RDB_E_NOT_SUPPORTED_ATTACH_IN_WAL_MODE = (E_BASE + 36),
    RDB_E_CREATE_FOLDER_FAIL = (E_BASE + 37),
    RDB_E_SQLITE_SQL_BUILDER_NORMALIZE_FAIL = (E_BASE + 38),
    RDB_E_STORE_SESSION_NOT_GIVE_CONNECTION_TEMPORARILY = (E_BASE + 39),
    RDB_E_STORE_SESSION_NO_CURRENT_TRANSACTION = (E_BASE + 40),
    RDB_E_NOT_SUPPORT = (E_BASE + 41),
    RDB_E_INVALID_PARCEL = (E_BASE + 42),
    RDB_E_QUERY_IN_EXECUTE = (E_BASE + 43),
    RDB_E_SET_PERSIST_WAL = (E_BASE + 44),
    RDB_E_DB_NOT_EXIST = (E_BASE + 45),
    RDB_E_ARGS_READ_CON_OVERLOAD = (E_BASE + 46),
    RDB_E_WAL_SIZE_OVER_LIMIT = (E_BASE + 47),
    RDB_E_CON_OVER_LIMIT = (E_BASE + 48)
 ```

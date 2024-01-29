# Distributed Data Management Changelog

## cl.distributeddatamgr.1 Change of ValuesBucket to a Public Interface

**Change Impact**

For applications developed based on earlier versions, only system applications can use **ValuesBucket**. From this version, **ValuesBucket** can be called by third-party applications.

**Key API/Component Changes**

Before change:

```ts
   /**
    * Indicates possible value types
    *
    * @syscap SystemCapability.DistributedDataManager.DataShare.Core
    * @systemapi
    * @StageModelOnly
    * @since 9
    */
   export type ValueType = number | string | boolean;
```

After change:

```ts
   /**
    * Indicates possible value types
    *
    * @syscap SystemCapability.DistributedDataManager.DataShare.Core
    * @StageModelOnly
    * @since 10
    */
   export type ValueType = number | string | boolean;
```


## cl.distributeddatamgr.2 Change of Some Predicate Interfaces in dataSharePredicates to Public Interfaces

**Change Impact**

For applications developed based on earlier versions, only system applications can use **dataSharePredicates**. From this version, the namespace **dataSharePredicates**, **dataSharePredicates** class, and some predicate interfaces can be called by third-party applications.

**Key API/Component Changes**

The involved interfaces are as follows:

- equalTo(field: string, value: ValueType): DataSharePredicates

- and(): DataSharePredicates

- orderByAsc(field: string): DataSharePredicates

- orderByDesc(field: string): DataSharePredicates

- limit(total: number, offset: number): DataSharePredicates

- in(field: string, value: Array[/topic/body/section/ul/li/p/valuetype 				{""}) ): DataSharePredicates (valuetype]


## cl.distributeddatamgr.3 Change of the DataShareExtensionAbility Context

Removed the optional flag from the context attribute of @ohos.application.DataShareExtensionAbility, and changed the start version from API version 9 to API version 10.

**Change Impact**

For applications developed based on earlier versions, use SDK API version 10 for the context.

**Key API/Component Changes**

Before change:

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

After change:

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


## cl.distributeddatamgr.4 Change of the Return Value Type of Function Pointer Variables in the OH_Predicates Struct from OH_Predicates to OH_Predicates \*

**Change Impact**

This change is incompatible with earlier versions. You need to use the new function pointer variables in the **OH_Predicates** struct.

**Key API/Component Changes**

Before change:

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

After change:

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

Example:

Code before change:

```
predicates->beginWrap(predicates).equalTo(predicates, "data1", valueObject).orOperate(predicates);
```

Code after change:

```
predicates->beginWrap(predicates)->equalTo(predicates, "data1", valueObject)->orOperate(predicates);
```


## cl.distributeddatamgr.5 Change of the Error Codes of the OH_Rdb_ErrCode Struct

**Change Impact**

Changed **RDB_ERR_INVALID_ARGS** to **RDB_E_INVALID_ARGS**, and **RDB_ERR_OK** to **RDB_OK**, and added error codes.

**Key API/Component Changes**

Before change:

```ts
 RDB_ERR_INVALID_ARGS = -2,
 RDB_ERR = -1,
 RDB_ERR_OK = 0
```

After change:

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



## cl.distributeddatamgr.6 Change of int (*close)(OH_Cursor *cursor) in OH_Cursor Struct to int (\*destroy)(OH_Cursor \*cursor)

**Change Impact**

This change is incompatible with earlier versions. The function pointer name is changed from **close** to **destroy**. The input parameters and return values remain unchanged.

**Key API/Component Changes**

Before change:

```ts
int (*close)(OH_Cursor *cursor);
```

After change:

```ts
int (*destroy)(OH_Cursor *cursor);
```

**Adaptation Guide**

Example:

Code before change:

```
cursor->close(cursor);
```

Code after change:

```
cursor->destroy(cursor);
```


## cl.distributeddatamgr.7 Change of int (\*destroyPredicates)(OH_Predicates \*predicates) in OH_Predicates Struct to int (\*destroy) (OH_Predicates \*predicates)

**Change Impact**

This change is incompatible with earlier versions. The function pointer name is changed from **destroyPredicates** to **destroy**. The input parameters and return values remain unchanged.

**Key API/Component Changes**

Before change:

```ts
int (*destroyPredicates)(OH_Predicates *predicates);
```

After change:

```ts
int (*destroy)(OH_Predicates *predicates);
```

**Adaptation Guide**

Example:

Code before change:

```
predicates->destroyPredicates(predicates);
```

Code after change:

```
predicates->destroy(predicates);
```


## cl.distributeddatamgr.8 Change of int (\*destroyValueObject)(OH_VObject \*valueObject) in OH_VObject Struct to int (\*destroy) (OH_VObject \*valueObject)

**Change Impact**

This change is incompatible with earlier versions. The function pointer name is changed from **destroyValueObject** to **destroy**. The input parameters and return values remain unchanged.

**Key API/Component Changes**

Before change:

```ts
int (*destroyValueObject)(OH_VObject *valueObject);
```

After change:

```ts
int (*destroy)(OH_VObject *valueObject);
```

**Adaptation Guide**

Example:

Code before change:

```
valueObject->destroyValueObject(valueObject);
```

Code after change:

```
valueObject->destroy(valueObject);
```


## cl.distributeddatamgr.9 Change of int (\*destroyValuesBucket)(OH_VBucket \*bucket) in OH_VBucket Struct to int (\*destroy) (OH_VBucket \*bucket)

**Change Impact**

This change is incompatible with earlier versions. The function pointer name is changed from **destroyValuesBucket** to **destroy**. The input parameters and return values remain unchanged.

**Key API/Component Changes**

Before change:

```ts
int (*destroyValuesBucket)(OH_VBucket *bucket);
```

After change:

```ts
int (*destroy)(OH_VBucket *bucket);
```

**Adaptation Guide**

Example:

Code before change:

```
valueBucket->destroyValuesBucket(valueBucket);
```

Code after change:

```
 valueBucket->destroy(valueBucket);
```


## cl.distributeddatamgr.10 Change of OH_Rdb_Config Struct Member Variables

**Change Impact**

The changes are incompatible with earlier versions. <br>The type of **securityLevel** is changed from **enum OH_Rdb_SecurityLevel** to **in**.<br>The member variable **path** is deleted.<br>The member variables **selfSize**, **dataBaseDir**, **storeName**, **bundleName**, and **moduleName** are added.

**Key API/Component Changes**

OH_Rdb_Config before change:

```ts
typedef struct {
   const char *path;
   bool isEncrypt;
   enum OH_Rdb_SecurityLevel securityLevel;
} OH_Rdb_Config;
```

OH_Rdb_Config after change:

```ts
typedef struct {
   int selfSize;
   const char *dataBaseDir;
   const char *storeName;
   const char *bundleName;
   const char *moduleName;
   bool isEncrypt;
   int securityLevel;
} OH_Rdb_Config;
```

**Adaptation Guide**

When creating an RDB store with **OH_Rdb_Config**, you need to pass in the bundle name and module name.


## cl.distributeddatamgr.11 Change of const char *path in OH_Rdb_DeleteStore() to const OH_Rdb_Config \*config

**Change Impact**

This change is incompatible with earlier versions. The input parameter is changed from **const char \*path** to **const OH_Rdb_Config \*config**.

**Key API/Component Changes**

OH_Rdb_DeleteStore before change:

```ts
int OH_Rdb_DeleteStore(const char *path);
```

OH_Rdb_DeleteStore after change:

```ts
int OH_Rdb_DeleteStore(const OH_Rdb_Config *config);
```

**Adaptation Guide**

Example:

Code before change:

```
OH_Rdb_DeleteStore("")
```

Code after change:

```
OH_Rdb_DeleteStore(config)
```

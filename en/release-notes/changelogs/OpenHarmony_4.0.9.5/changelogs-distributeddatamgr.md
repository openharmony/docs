
# Distributed Data Management Subsystem Changelog

## cl.distributeddatamgr.1 Change of int (*close)(OH_Cursor *cursor) in OH_Cursor Struct to int (\*destroy)(OH_Cursor \*cursor)

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

## cl.distributeddatamgr.2 Change of int (\*destroyPredicates)(OH_Predicates \*predicates) in OH_Predicates Struct to int (*destroy)(OH_Predicates *predicates)

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

## cl.distributeddatamgr.3 Change of int (\*destroyValueObject)(OH_VObject \*valueObject) in OH_VObject Struct to int (\*destroy)(OH_VObject \*valueObject)

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

## cl.distributeddatamgr.4 Change of int (\*destroyValuesBucket)(OH_VBucket \*bucket) in OH_VBucket Struct to int (\*destroy)(OH_VBucket \*bucket)

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

## cl.distributeddatamgr.5 Change of OH_Rdb_Config Struct Member Variables

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

## cl.distributeddatamgr.6 Change of const char *path in OH_Rdb_DeleteStore() to const OH_Rdb_Config *config

**Change Impact**

This change is incompatible with earlier versions. The input parameter is changed from **const char *path** to **const OH_Rdb_Config *config**.

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

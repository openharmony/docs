
# 分布式数据管理子系统ChangeLog

## cl.distributeddatamgr.1 OH_Cursor结构体的函数指针成员变量**int** (*close)(OH_Cursor *cursor)变更为**int** (*destroy)(OH_Cursor *cursor)

**变更影响**

该变更为不兼容变更，函数指针名称由close更改为destroy，入参及返回值均未更改。

**关键接口/组件变更**

修改前的OH_Cursor该成员变量原型：

 ```ts
 int (*close)(OH_Cursor *cursor);
 ```

修改后的OH_Predicates成员变量原型：

 ```ts
 int (*destroy)(OH_Cursor *cursor);
 ```

**适配指导**
示例代码如下：

变更前代码示例：

```
cursor->close(cursor);
```

变更后代码示例：

```
cursor->destroy(cursor);
```

## cl.distributeddatamgr.2 OH_Predicates结构体的函数指针成员变量**int** (*destroyPredicates)(OH_Predicates *predicates)变更为 **int** (*destroy)(OH_Predicates *predicates)

**变更影响**

该变更为不兼容变更，函数指针名称由destroyPredicates更改为destroy，入参及返回值均未更改。

**关键接口/组件变更**

修改前的OH_Predicates该成员变量原型：

 ```ts
int (*destroyPredicates)(OH_Predicates *predicates);
 ```

修改后的OH_Predicates成员变量原型：

 ```ts
int (*destroy)(OH_Predicates *predicates);
 ```

**适配指导**
示例代码如下：

变更前代码示例：

```
predicates->destroyPredicates(predicates);
```

变更后代码示例：

```
predicates->destroy(predicates);
```

## cl.distributeddatamgr.3 OH_VObject结构体的函数指针成员变量**int** (*destroyValueObject)(OH_VObject *valueObject)变更为 **int** (*destroy)(OH_VObject *valueObject)

**变更影响**

该变更为不兼容变更，函数指针名称由destroyValueObject更改为destroy，入参及返回值均未更改。

**关键接口/组件变更**

修改前的OH_VObject该成员变量原型：

 ```ts
int (*destroyValueObject)(OH_VObject *valueObject);
 ```

修改后的OH_Predicates成员变量原型：

 ```ts
int (*destroy)(OH_VObject *valueObject);
 ```

**适配指导**
示例代码如下：

变更前代码示例：

```
valueObject->destroyValueObject(valueObject);
```

变更后代码示例：

```
valueObject->destroy(valueObject);
```

## cl.distributeddatamgr.4 OH_VBucket结构体的函数指针成员变量**int** (*destroyValuesBucket)(OH_VBucket *bucket)变更为 int (*destroy)(OH_VBucket *bucket)

**变更影响**

该变更为不兼容变更，函数指针名称由destroyValuesBucket更改为destroy，入参及返回值均未更改。

**关键接口/组件变更**

修改前的OH_VBucket该成员变量原型：

 ```ts
int (*destroyValuesBucket)(OH_VBucket *bucket);
 ```

修改后的OH_Predicates成员变量原型：

 ```ts
int (*destroy)(OH_VBucket *bucket);
 ```

**适配指导**
示例代码如下：

变更前代码示例：

```
valueBucket->destroyValuesBucket(valueBucket);
```

变更后代码示例：

```
 valueBucket->destroy(valueBucket);
```

## cl.distributeddatamgr.5 OH_Rdb_Config结构体成员变量变更

**变更影响**

该变更为不兼容变更，将成员变量securityLevel的类型由enum OH_Rdb_SecurityLevel改为in；删除成员变量path；并新增成员变量selfSize、dataBaseDir、storeName、bundleName、moduleName。

**关键接口/组件变更**

修改前的OH_Rdb_Config：

 ```ts
typedef struct {
    const char *path;
    bool isEncrypt;
    enum OH_Rdb_SecurityLevel securityLevel;
} OH_Rdb_Config;
 ```

修改后的OH_Rdb_Config：

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

**适配指导**
用户在利用OH_Rdb_Config创建数据库时，需要传入包名以及模块名等信息。

## cl.distributeddatamgr.6 **OH_Rdb_DeleteStore**接口入参**const** **char** *pat变更为**const** OH_Rdb_Config *config

**变更影响**

该变更为不兼容变更，函数入参由const char *path变更为const OH_Rdb_Config *config。

**关键接口/组件变更**

修改前OH_Rdb_DeleteStore接口：

 ```ts
int OH_Rdb_DeleteStore(const char *path);
 ```

修改后OH_Rdb_DeleteStore接口：

 ```ts
int OH_Rdb_DeleteStore(const OH_Rdb_Config *config);
 ```

**适配指导**

示例代码如下：

变更前代码示例：

```
OH_Rdb_DeleteStore(“”)
```

变更后代码示例：

```
OH_Rdb_DeleteStore(config)
```


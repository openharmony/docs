# 关系型数据库开发指导

## 场景介绍

关系型数据库是在SQLite基础上实现的本地数据操作机制，提供给用户无需编写原生SQL语句就能进行数据增删改查的方法，同时也支持原生SQL语句操作。

## 接口说明
### 数据库的创建和删除

关系型数据库提供了数据库创建方式，以及对应的删除接口，涉及的API如下所示。

表1 数据库创建和删除API

| 类名 | 接口名 | 描述 |
|  ----  |  ----  |  ----  |
| RdbStoreConfig | RdbStoreConfig(const std::string &path, <br> StorageMode storageMode = StorageMode::MODE_DISK, <br> bool readOnly = false, <br> const std::vector<uint8_t> &encryptKey = std::vector<uint8_t>(), <br> const std::string &journalMode = "", <br> const std::string &syncMode = "", <br> const std::string &databaseFileType = "", <br> const std::string &databaseFileSecurityLevel = "") | 对数据库进行配置，包括设置数据库名、存储模式、日志模式、同步模式，是否为只读，及数据库加密。 <ul><li> path：数据库路径；</li><li> readOnly：是否只读；</li><li> storageMode：存储模式；</li><li> encryptKey：加密密钥; </li><li> journalMode：日志模式；</li><li> syncMode：同步模式；</li><li> databaseFileType：数据库类型； </li><li> databaseFileSecurityLevel：安全等级 </li></ul> |
| RdbOpenCallback | int OnCreate(RdbStore &rdbStore) | 数据库创建时被回调，开发者可以在该方法中初始化表结构，并添加一些应用使用到的初始化数据。 |
| RdbOpenCallback | int OnUpgrade(RdbStore &rdbStore, int currentVersion, int targetVersion) | 数据库升级时被回调。 |
| RdbOpenCallback | int OnDowngrade(RdbStore &rdbStore, int currentVersion, int targetVersion) | 数据库降级时被回调。 |
| RdbHelper | std::shared_ptr\<RdbStore\> GetRdbStore(const RdbStoreConfig &config, int version, RdbOpenCallback &openCallback, int &errCode) | 根据配置创建或打开数据库。 |
| RdbHelper | int DeleteRdbStore(const std::string &path) | 删除指定的数据库。 |

### 数据库的加密

关系型数据库提供数据库加密的能力，在创建数据库时若指定了密钥，则会创建为加密数据库。再次使用此数据库时，需要指定该密钥，才能正确打开数据库。

表2 数据库修改密钥API
| 类名 | 接口名 | 描述 |
|  ----  |  ----  |  ----  |
| RdbStore | int ChangeEncryptKey(const std::vector<uint8_t> &newKey) | 为数据库设置新的加密密钥。注：仅支持加密数据库更换加密密钥。 |

### 数据库谓词的使用

关系型数据库提供了用于设置数据库操作条件的谓词AbsRdbPredicates，其中包括两个实现子类RdbPredicates和RawRdbPredicates：

- RdbPredicates：开发者无需编写复杂的SQL语句，仅通过调用该类中条件相关的方法，如equalTo、notEqualTo、groupBy、orderByAsc、beginsWith等，就可自动完成SQL语句拼接，方便用户聚焦业务操作。
- RawRdbPredicates：可满足复杂SQL语句的场景，支持开发者自己设置where条件子句和whereArgs参数。不支持equalTo等条件接口的使用。

  表7 数据库谓词API
  | 类名 | 接口名 | 描述 |
  |  ----  |  ----  |  ----  |
  | RdbPredicates | AbsPredicates *EqualTo(std::string field, std::string value) | 设置谓词条件，满足field字段与value值相等。 |
  | RdbPredicates | AbsPredicates *NotEqualTo(std::string field, std::string value) | 设置谓词条件，满足field字段与value值不相等。 |
  | RdbPredicates | AbsPredicates *BeginsWith(std::string field, std::string value) | 设置谓词条件，满足field字段以value值开头。 |
  | RdbPredicates | AbsPredicates *Between(std::string field, std::string low, std::string high) | 设置谓词条件，满足field字段在最小值low和最大值high之间。 |
  | RdbPredicates | AbsPredicates *OrderByAsc(std::string field) | 设置谓词条件，根据field字段升序排列。 |
  | RdbPredicates | void SetWhereClause(std::string whereClause) | 设置where条件子句。 |
  | RdbPredicates | void SetWhereArgs(std::vector\<std::string\> whereArgs) | 设置whereArgs参数，该值表示where子句中占位符的值。 |

### 数据表的增删改查

关系型数据库提供对本地数据增删改查操作的能力，相关API如下所示。

- 新增

  关系型数据库提供了插入数据的接口，通过ValuesBucket输入要存储的数据，通过返回值判断是否插入成功，插入成功时返回最新插入数据所在的行号，失败时则返回-1。

  表3 数据表插入API

  | 类名 | 接口名 | 描述 |
  |  ----  |  ----  |  ----  |
  | RdbStore | int Insert(int64_t &outRowId, const std::string &table, const ValuesBucket &initialValues) | 向数据库插入数据。<ul><li>table：待添加数据的表名。 </li><li> initialValues：以ValuesBucket存储的待插入的数据。它提供一系列put方法，如PutString(const std::string &columnName, const std::string &value)，PutDouble(const std::string &columnName, double value)，用于向ValuesBucket中添加数据。</li></ul> |

- 删除
  
  调用删除接口，通过AbsRdbPredicates指定删除条件。该接口的返回值表示删除的数据行数，可根据此值判断是否删除成功。如果删除失败，则返回0。

  表5 数据表删除API
  | 类名 | 接口名 | 描述 |
  |  ----  |  ----  |  ----  |
  | RdbStore | int Delete(int &deletedRows, const AbsRdbPredicates &predicates) | 删除数据。<ul><li> deletedRows：删除的记录条数。 </li><li> predicates：Rdb谓词，指定了删除操作的表名和条件。AbsRdbPredicates的实现类有两个：RdbPredicates和RawRdbPredicates。<ul><li> RdbPredicates：支持调用谓词提供的equalTo等接口，设置更新条件。</li><li> RawRdbPredicates：仅支持设置表名、where条件子句、whereArgs三个参数，不支持equalTo等接口调用。 </li></ul></li></ul> |

- 更新

  调用更新接口，传入要更新的数据，并通过AbsRdbPredicates指定更新条件。该接口的返回值表示更新操作影响的行数。如果更新失败，则返回0。

  表4 数据表更新API
  | 类名 | 接口名 | 描述 |
  |  ----  |  ----  |  ----  |
  | RdbStore | int Update(int &changedRows, const ValuesBucket &values, const AbsRdbPredicates &predicates) | 更新数据库表中符合谓词指定条件的数据。<ul><li> changedRows：更新的记录条数。 </li><li> values：以ValuesBucket存储的要更新的数据。 </li><li> predicates：指定了更新操作的表名和条件。AbsRdbPredicates的实现类有两个：RdbPredicates和RawRdbPredicates。<ul><li> RdbPredicates：支持调用谓词提供的equalTo等接口，设置更新条件。</li><li> RawRdbPredicates：仅支持设置表名、where条件子句、whereArgs三个参数，不支持equalTo等接口调用。 </li></ul></li></ul> |

- 查询

  关系型数据库提供了两种查询数据的方式：

  - 直接调用查询接口。使用该接口，会将包含查询条件的谓词自动拼接成完整的SQL语句进行查询操作，无需用户传入原生的SQL语句。
  - 执行原生的SQL语句进行查询操作。

  表6 数据表查询API
  | 类名 | 接口名 | 描述 |
  |  ----  |  ----  |  ----  |
  | RdbStore | std::unique_ptr<AbsSharedResultSet> Query(const AbsRdbPredicates &predicates, const std::vector\<std::string\> columns) | 查询数据。<ul><li> predicates：谓词，可以设置查询条件。AbsRdbPredicates的实现类有两个：RdbPredicates和RawRdbPredicates。<ul><li> RdbPredicates：支持调用谓词提供的equalTo等接口，设置更新条件。</li><li> RawRdbPredicates：仅支持设置表名、where条件子句、whereArgs三个参数，不支持equalTo等接口调用。 </li></ul> <li> columns：规定查询返回的列。</li></ul></li></ul> |
  | RdbStore | std::unique_ptr<AbsSharedResultSet> QuerySql(const std::string &sql, const std::vector\<std::string\> &selectionArgs = std::vector\<std::string\>()) | 执行原生的用于查询操作的SQL语句。<ul><li> sql：原生用于查询的sql语句。</li><li> selectionArgs：sql语句中占位符参数的值，若select语句中没有使用占位符，该参数可以设置为null。</li></ul> |

### 查询结果集的使用

关系型数据库提供了查询返回的结果集ResultSet，其指向查询结果中的一行数据，供用户对查询结果进行遍历和访问。ResultSet对外API如下所示。

  表8 结果集API
  | 类名 | 接口名 | 描述 |
  |  ----  |  ----  |  ----  |
  | ResultSet | int GoTo(int offset) | 从结果集当前位置移动指定偏移量。 |
  | ResultSet | int GoToRow(int position) | 将结果集移动到指定位置。 |
  | ResultSet | int GoToNextRow() | 将结果集向后移动一行。 |
  | ResultSet | int GoToPreviousRow() | 将结果集向前移动一行。 |
  | ResultSet | int IsStarted(bool &result) | 判断结果集是否被移动过。 |
  | ResultSet | int IsEnded(bool &result) | 判断结果集是否被移动到最后一行之后。 | 
  | ResultSet | int IsAtFirstRow(bool &result) | 判断结果集当前位置是否在第一行。 |
  | ResultSet | int IsAtLastRow(bool &result) | 判断结果集当前位置是否在最后一行。 |
  | ResultSet | int GetRowCount(int &count) | 获取当前结果集中的记录条数。 |
  | ResultSet | int GetColumnCount(int &count) | 获取结果集中的列数。 |
  | ResultSet | int GetString(int columnIndex, std::string &value) | 获取当前行指定列的值，以String类型返回。 |
  | ResultSet | int GetBlob(int columnIndex, std::vector\<uint8_t\> &blob) | 获取当前行指定列的值，以字节数组形式返回。 |
  | ResultSet | int GetDouble(int columnIndex, double &value) | 获取当前行指定列的值，以double型返回。 |

## 约束与限制

无。

## 开发步骤

1. 创建数据库。

    a. 配置数据库相关信息，包括数据库的名称、存储模式、是否为只读模式等。

    b. 初始化数据库表结构和相关数据。

    c. 创建数据库。

    示例代码如下：
    ```
    const std::string DATABASE_NAME = RDB_TEST_PATH + "RdbStoreTest.db";
    const CREATE_TABLE_TEST = "CREATE TABLE IF NOT EXISTS test (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, salary REAL, blobType BLOB)";

    class OpenCallback : public RdbOpenCallback {
    public:
        int OnCreate(RdbStore &rdbStore) override;
        int OnUpgrade(RdbStore &rdbStore, int oldVersion, int newVersion) override;
    };

    int OpenCallback::OnCreate(RdbStore &store)
    {
        return store.ExecuteSql(CREATE_TABLE_TEST);
    }

    RdbStoreConfig config(DATABASE_NAME);
    OpenCallback callback;

    std::shared_ptr<RdbStore> store = RdbHelper::GetRdbStore(config, 1, callback, 0); 
    ```

2. 插入数据。

    a. 构造要插入的数据，以ValuesBucket形式存储。

    b. 调用关系型数据库提供的插入接口。

    c. 创建数据库。

    示例代码如下：
    ```
    ValuesBucket values;

    values.PutInt("id", 1);
    values.PutString("name", std::string("Tom"));
    values.PutInt("age", 18);
    values.PutDouble("salary", 100.5);
    values.PutBlob("blobType", std::vector<uint8_t>{ 1, 2, 3 });
    store->Insert(id, "test", values);
    ```

3. 查询数据。

    a. 构造用于查询的谓词对象，设置查询条件。

    b. 指定查询返回的数据列。

    c. 调用查询接口查询数据。

    d. 调用结果集接口，遍历返回结果。

    示例代码如下：
    ```
    std::vector<std::string> columns = {"id", "name", "age", "salary"};

    RdbPredicates predicates("test");
    predicates.EqualTo("age", "25")->OrderByAsc("salary");
    std::unique_ptr<ResultSet> resultSet  = store->Query(predicates, columns)
    resultSet.goToNextRow();
    ```


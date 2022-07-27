# RDB Development

## When to Use

A relational database (RDB) store allows you to operate local data with or without native SQL statements based on SQLite.

## Available APIs
### Creating and Deleting an RDB Store

The table below describes the APIs for creating and deleting an RDB store.

**Table 1** APIs for creating and deleting an RDB store

| Class| API| Description|
|  ----  |  ----  |  ----  |
| RdbStoreConfig | RdbStoreConfig(const std::string &path, <br> StorageMode storageMode = StorageMode::MODE_DISK, <br> bool readOnly = false, <br> const std::vector<uint8_t> &encryptKey = std::vector<uint8_t>(), <br> const std::string &journalMode = "", <br> const std::string &syncMode = "", <br> const std::string &databaseFileType = "", <br> const std::string &databaseFileSecurityLevel = "") | Configures an RDB store, including setting the RDB store name, storage mode, log mode, synchronization mode, and read-only mode, and whether to encrypt the RDB store.<br/> - **path**: path of the RDB store. <br>- **readOnly**: whether the RDB store is read-only. <br>- **storageMode**: storage mode. <br>- **encryptKey**: key used to encrypt the RDB store. <br>- **journalMode**: logging mode. <br>- **syncMode**: data synchronization mode. <br>- **databaseFileType**: RDB store type. <br>- **databaseFileSecurityLevel**: security level of the RDB store.|
| RdbOpenCallback | int OnCreate(RdbStore &rdbStore) | Called when an RDB store is created. You can add the method for initializing the table structure and initialization data used by your application in this callback.|
| RdbOpenCallback | int OnUpgrade(RdbStore &rdbStore, int currentVersion, int targetVersion) | Called when the RDB store is upgraded.|
| RdbOpenCallback | int OnDowngrade(RdbStore &rdbStore, int currentVersion, int targetVersion) | Called when the RDB store is downgraded.|
| RdbHelper | std::shared_ptr\<RdbStore\> GetRdbStore(const RdbStoreConfig &config, int version, RdbOpenCallback &openCallback, int &errCode) | Creates or obtains an RDB store.|
| RdbHelper | int DeleteRdbStore(const std::string &path) | Deletes an RDB store.|

### Encrypting an RDB Store

When creating an RDB store, you can add a key for security purposes. After that, the RDB store can be accessed only with the correct key.

**Table 2** API for changing the key
| Class| API| Description|
|  ----  |  ----  |  ----  |
| RdbStore | int ChangeEncryptKey(const std::vector<uint8_t> &newKey) | Changes the encryption key for an RDB store. <br>Note that the encryption key can be changed only for an encrypted RDB store.|

### Using Predicates

The RDB store provides **AbsRdbPredicates** for you to set database operation conditions. The **AbsRdbPredicates** class has the following child classes:

- **RdbPredicates**: allows you to combine SQL statements by simply calling methods in this class, such as **equalTo**, **notEqualTo**, **groupBy**, **orderByAsc**, and **beginsWith**. With this class, you do not need to write complex SQL statements.
- **RawRdbPredicates**: allows you to write complex SQL statements, such as setting **whereClause** and **whereArgs**. However, this class does not support APIs such as **equalTo**.

  **Table 3** APIs for setting RDB predicates 
  | Class| API| Description|
  |  ----  |  ----  |  ----  |
  | RdbPredicates | AbsPredicates *EqualTo(std::string field, std::string value) | Sets an **AbsPredicates** to match the field that is equal to the specified value.|
  | RdbPredicates | AbsPredicates *NotEqualTo(std::string field, std::string value) | Sets an **AbsPredicates** to match the field that is not equal to the specified value.|
  | RdbPredicates | AbsPredicates *BeginsWith(std::string field, std::string value) | Sets an **AbsPredicates** to match the field that starts with the specified value.|
  | RdbPredicates | AbsPredicates *Between(std::string field, std::string low, std::string high) | Sets an **AbsPredicates** to match the field that is within the range specified by **low** and **high**.|
  | RdbPredicates | AbsPredicates *OrderByAsc(std::string field) | Sets an **AbsPredicates** that sorts values in ascending order.|
  | RdbPredicates | void SetWhereClause(std::string whereClause) | Sets **whereClause**.|
  | RdbPredicates | void SetWhereArgs(std::vector\<std::string\> whereArgs) | Sets **whereArgs**, which indicates the value of the placeholder in **whereClause**.|
  | RdbPredicates | AbsRdbPredicates *InDevices(std::vector<std::string>& devices) | Sets an **AbsPredicates** to specify the remote devices on the network with databases to be synchronized.|
  | RdbPredicates | AbsRdbPredicates *InAllDevices() | Sets an **AbsPredicates** to connect to all remote devices on the network when synchronizing distributed databases.|


### Managing Data in an RDB Store

You can use the APIs provided by the RDB to insert, delete, update, and query local data.

- Inserting data

  Call **int Insert()** to insert data through **ValuesBucket**. If data is inserted, the row number of the data inserted is returned; otherwise, **-1** is returned.

  **Table 4** API for inserting data

  | Class| API| Description|
  |  ----  |  ----  |  ----  |
  | RdbStore | int Insert(int64_t &outRowId, const std::string &table, const ValuesBucket &initialValues) | Inserts data based on the passed table name and data in **ValuesBucket**. <br/>- **table**: name of the target table. <br/>- **initialValues**: data to insert. The data is stored in **ValuesBucket**. A series of **put()** methods, such as **PutString(const std::string &columnName, const std::string &value)** and **PutDouble(const std::string &columnName, double value)**, are provided to add data to **ValuesBucket**. |

- Deleting data
  
  Call **delete()** to delete the data that meets the conditions specified by **AbsRdbPredicates**. If data is deleted, the row number of the deleted data is returned; otherwise, **0** is returned.

  **Table 5** API for deleting data
  | Class| API| Description|
  |  ----  |  ----  |  ----  |
  | RdbStore | int Delete(int &deletedRows, const AbsRdbPredicates &predicates) | Deletes data.<br> - **deletedRows**: number of rows to delete.<br> - **predicates**: table name and conditions for deleting the data. **AbsRdbPredicates** has the following classes:<br> - **RdbPredicates**: specifies conditions by calling its methods, such as **equalTo**.<br> - **RawRdbPredicates**: specifies the table name, **whereClause**, and **whereArgs** only. |

- Updating data

  Call **update()** to update data based on the passed data and the conditions specified by **AbsRdbPredicates**. If data is updated, the row number of the updated data is returned; otherwise, **0** is returned.

  **Table 6** API for updating data
  | Class| API| Description|
  |  ----  |  ----  |  ----  |
  | RdbStore | int Update(int &changedRows, const ValuesBucket &values, const AbsRdbPredicates &predicates) | Updates the data that meets the conditions specified by predicates.<br> - **changedRows**: number of rows to update.<br> - **values**: new data stored in **ValuesBucket**.<br> - **predicates**: table name and conditions for the update operation. **AbsRdbPredicates** has the following classes:<br> - **RdbPredicates**: specifies update conditions by calling its methods, such as **equalTo**.<br> - **RawRdbPredicates**: specifies the table name, **whereClause**, and **whereArgs** only. |

- Querying data

  You can query data in an RDB store in either of the following ways:

  - Call the **query()** method to query data based on the predicates, without passing any SQL statement.
  - Run the native SQL statement.

  **Table 7** APIs for querying data
  | Class| API| Description|
  |  ----  |  ----  |  ----  |
  | RdbStore | std::unique_ptr<AbsSharedResultSet> Query(const AbsRdbPredicates &predicates, const std::vector\<std::string\> columns) | Queries data.<br> - **predicates**: query conditions. **AbsRdbPredicates** has the following classes:<br> - **RdbPredicates**: specifies query conditions by calling its methods, such as **equalTo**.<br> - **RawRdbPredicates**: specifies the table name, **whereClause**, and **whereArgs** only.<br> - **columns**: number of columns returned. |
  | RdbStore | std::unique_ptr<AbsSharedResultSet> QuerySql(const std::string &sql, const std::vector\<std::string\> &selectionArgs = std::vector\<std::string\>()) | Executes the native SQL statements to query data.<br> - **sql**: native SQL statement.<br> - **selectionArgs**: parameter values corresponding to the placeholders in the SQL statements. Set it to **null** if the **select** statement has no placeholder. |

### Obtaining the Query Result

You can use the APIs provided by **ResultSet** to traverse and access the data you have queried. A result set can be regarded as a row of data in the queried result. The table below describes the APIs of **ResultSet**.

**Table 8** APIs of **ResultSet**
| Class| API| Description|
|  ----  |  ----  |  ----  |
| ResultSet | int GoTo(int offset) | Moves forwards or backwards by the specified offset relative to its current position.|
| ResultSet | int GoToRow(int position) | Moves to the specified row.|
| ResultSet | int GoToNextRow() | Moves to the next row.|
| ResultSet | int GoToPreviousRow() | Moves to the previous row.|
| ResultSet | int IsStarted(bool &result) | Checks whether the result set has been moved.|
| ResultSet | int IsEnded(bool &result) | Checks whether the result set is moved after the last line.|
| ResultSet | int IsAtFirstRow(bool &result) | Checks whether the result set is located in the first row.|
| ResultSet | int IsAtLastRow(bool &result) | Checks whether the result set is located in the last row.|
| ResultSet | int GetRowCount(int &count) | Obtains the number of rows of this result set.|
| ResultSet | int GetColumnCount(int &count) | Obtains the number of columns of this result set.|
| ResultSet | int GetString(int columnIndex, std::string &value) | Obtains the value in the specified column of the current row, in strings.|
| ResultSet | int GetBlob(int columnIndex, std::vector\<uint8_t\> &blob) | Obtains the value in the specified column of the current row, in a byte array.|
| ResultSet | int GetDouble(int columnIndex, double &value) | Obtains the value in the specified column of the current row, in double.|

### Setting Distributed Tables

Call **bool SetDistributedTables()** to set distributed tables for data operations across devices.

**Table 9** API for setting distributed tables
| Class| API| Description|
|  ----  |  ----  |  ----  |
| RdbStore | bool SetDistributedTables(const std::vector<std::string>& tables) | Sets distributed tables.<br> - **tables**: names of the distributed tables to set.

### Obtaining the Distributed Table Name for a Remote Device

You can obtain the distributed table name for a remote device based on the local table name. The distributed table name can be used to query the RDB store of the remote device.<br>

**Table 10** API for obtaining the distributed table name of a remote device
| Class| API| Description|
|  ----  |  ----  |  ----  |
| RdbStore | std::string ObtainDistributedTableName(const std::string& device, const std::string& table) | Obtains the distributed table name of a remote device based on the local table name. The distributed table name can be used to query the RDB store of the remote device.<br> - **device**: ID of the remote device. <br>- **table**: name of the local table.

### Synchronizing Data Between Devices

**Table 11** API for synchronizing data between devices
| Class| API| Description|
|  ----  |  ----  |  ----  |
| RdbStore | bool Sync(const SyncOption& option, const AbsRdbPredicates& predicate, const SyncCallback& callback) | Synchronizes data between devices. <br>- **option**: synchronization options, which include **mode** and **isBlock**. **mode** specifies how data is synchronized. The value **push** means to push data from the local device to the remote device; the value **pull** means to pull data from the remote device to the local device. **isBlock** specifies whether the invocation of this function is blocked. <br>- **callback**: callback used to return the result.

### Registering an RDB Store Observer

**Table 12** API for registering an observer
| Class| API| Description|
|  ----  |  ----  |  ----  |
| RdbStore | bool Subscribe(const SubscribeOption& option, RdbStoreObserver *observer) | Registers an observer for this RDB store to listen for distributed data changes. When data in the RDB store changes, a callback will be invoked to return the data changes. <br>- **option**: subscription type.<br>- **observer**: observer that listens for data changes in the RDB store.

### Unregistering an RDB Store Observer

**Table 13** API for unregistering an observer
| Class| API| Description|
|  ----  |  ----  |  ----  |
| RdbStore | bool UnSubscribe(const SubscribeOption& option, RdbStoreObserver *observer) | Unregisters the observer of the specified type. <br>- **option**: subscription type to unregister.<br>- **observer**: observer to unregister.

### Backing Up and Restoring an RDB Store

You can use the APIs provided by **rdbStore** to back up and restore local database files.

- Backing up an RDB store

  Call **int Backup()** to back up the current database file. **databasePath** specifies the name or path of the backup file to be generated. If the backup is successful, **0** is returned; otherwise, an error code is returned.

  Table 14 API for backing up an RDB store

  | Class| API| Description|
  |  ----  |  ----  |  ----  |
  | RdbStore | int Backup(const std::string databasePath, const std::vector&lt;uint8_t&gt; destEncryptKey) | Backs up the current database file.<br> - **databasePath**: name or path of the backup file to generate.<br> - **destEncryptKey**: key used to encrypt the RDB store. Currently, only non-encrypted RDB stores can be backed up. |

- Restoring an RDB store

  Call **int Restore()** to restore an RDB from the backup file. **backupPath** specifies the name or path of the backup file. If the restore is successful, **0** is returned; otherwise, an error code is returned.

  Table 15 API for restoring an RDB store

  | Class| API| Description|
  |  ----  |  ----  |  ----  |
  | RdbStore | int Restore(const std::string backupPath, const std::vector&lt;uint8_t&gt; &newKey) | Restore an RDB store.<br> - **backupPath**: name or path of the backup file.<br> - **newKey**: key used to encrypt the RDB store. Currently, only non-encrypted RDB stores can be restored. |

## Constraints

None.

## How to Develop

1. Create an RDB store.

    a. Configure the RDB store attributes, including the RDB store name, storage mode, and read-only mode.

    b. Initialize the table structure and related data in the RDB store.

    c. Create an RDB store.

    The sample code is as follows:
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

2. Insert data.

    a. Create a **ValuesBucket** to store the data you need to insert.

    b. Call the **insert()** method to insert data into the RDB store.

    c. Create an RDB store.

    The sample code is as follows:
    ```
    ValuesBucket values;

    values.PutInt("id", 1);
    values.PutString("name", std::string("Tom"));
    values.PutInt("age", 18);
    values.PutDouble("salary", 100.5);
    values.PutBlob("blobType", std::vector<uint8_t>{ 1, 2, 3 });
    store->Insert(id, "test", values);
    ```

3. Query data.

    a. Create a predicate that specifies query conditions.

    b. Specify the data columns to return in the result set.

    c. Call the **query()** method to query data.

    d. Call the **ResultSet** APIs to traverse data in the result set.

    The sample code is as follows:
    ```
    std::vector<std::string> columns = {"id", "name", "age", "salary"};

    RdbPredicates predicates("test");
    predicates.EqualTo("age", "25")->OrderByAsc("salary");
    std::unique_ptr<ResultSet> resultSet  = store->Query(predicates, columns)
    resultSet.goToNextRow();
    ```

4. Set the distributed tables to be synchronized.

    a. Call the **SetDistributedTables()** method to set the distributed tables to be synchronized.

    The sample code is as follows:

    ```
    store->SetDistributedTables("test");
    ```

5. Synchronize data.

    a. Set the data synchronization mode and block status.

    b. Constructs an **AbsPredicates** object to specify remote devices within the network to be synchronized.

    c. Call the **Sync()** method to synchronize data.

    The sample code is as follows:

    ```
    SyncOption option;
    option.mode = PUSH;
    option.isBlock = true;
    AbsRdbPredicates predicate("test");
    predicate.InAllDevices();
    store->Sync(option, predicate, [] (const SyncResult& result) {
        for (const auto& [device, status] : result) {
            LogI("device=%s status=%d", device.c_str(), status);
        }
    });
    ```

6. Subscribe to distributed data.

    a. Override the **OnChange()** function.

    b. Define the distributed data subscription type.

    c. Call APIs to subscribe to or unsubscribe from distributed data.

    The sample code is as follows:

    ```
    class MyObserver : public RdbStoreObserver {
    public:
        void OnChange(const std::vector<std::string>& devices) override {
            for (const auto& device : devices) {
                LOGI("device=%s data change", device.c_str());
            }
        }
    };

    SubscribeOption option;
    option.mode = SubscribeMode::REMOTE;
    MyObserver observer;
    store->Subscribe(option, &observer); // Subscribe to distributed data.

    store->UnSubscribe(option, &observer); // Unsubscribe from distributed data.
    ```

7. Query data across devices.

   a. Obtain the distributed table name for a remote device based on the local table name.

   b. Run SQL statements to query data in the RDB store of the remote device.

   The sample code is as follows:
   ```
    std::string tableName = store->ObtainDistributedTableName("123456789abcd", "test");
    auto resultSet = store->QuerySql("SELECT * from ?;", tableName);
   ```

8. Back up and restore an RDB store.

   a. Back up the current RDB store.

   b. Restore the RDB store from the specified backup file.

   The sample code is as follows:
   ```
    std::string backupName = "backup.db"; // Name of the database backup file to generate.
    std::vector<uint8_t> key; // Key used to encrypt the RDB store.
    int errno = store->Backup(backupName, key);
    errno = store->Restore(backupName, key);
   ```

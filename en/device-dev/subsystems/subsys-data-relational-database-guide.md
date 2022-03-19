# RDB Development

## When to Use

On the basis of the SQLite database, the RDB allows you to operate data with or without native SQL statements. In OpenHarmony, an RDB is also called RDB store.

## Available APIs
### Creating and Deleting an RDB Store

The following table describes APIs available for creating and deleting an RDB store.

**Table 1** APIs for creating and deleting an RDB store

| Class| API| Description|
|  ----  |  ----  |  ----  |
| RdbStoreConfig | RdbStoreConfig(const std::string &path, <br> StorageMode storageMode = StorageMode::MODE_DISK, <br> bool readOnly = false, <br> const std::vector<uint8_t> &encryptKey = std::vector<uint8_t>(), <br> const std::string &journalMode = "", <br> const std::string &syncMode = "", <br> const std::string &databaseFileType = "", <br> const std::string &databaseFileSecurityLevel = "") | Configures an RDB store, including setting the name, storage mode, log mode, synchronization mode, and read-only mode, and encrypting the RDB store.<br/> -&nbsp;**path**: path of the database.<br/> -&nbsp;**readOnly**: whether the database is read-only.<br/> -&nbsp; **storageMode**: storage mode.<br/> -&nbsp;**encryptKey**: key used for database encryption.<br/> -&nbsp;**journalMode**: database logging mode.<br/> -&nbsp;**syncMode**: data synchronization mode.<br/> -&nbsp;**databaseFileType**: database type.<br/> -&nbsp;**databaseFileSecurityLevel**: security level. |
| RdbOpenCallback | int OnCreate(RdbStore &rdbStore) | Called when an RDB store is created. You can add the method for initializing the table structure and add initialization data used by your application in the callback.|
| RdbOpenCallback | int OnUpgrade(RdbStore &rdbStore, int currentVersion, int targetVersion) | Called when the RDB store is upgraded.|
| RdbOpenCallback | int OnDowngrade(RdbStore &rdbStore, int currentVersion, int targetVersion) | Called when the RDB store is downgraded.|
| RdbHelper | std::shared_ptr\<RdbStore\> GetRdbStore(const RdbStoreConfig &config, int version, RdbOpenCallback &openCallback, int &errCode) | Creates or obtains an RDB store.|
| RdbHelper | int DeleteRdbStore(const std::string &path) | Deletes the specified RDB store.|

### Encrypting an RDB Store

The RDB provides the database encryption capability. When creating an RDB store, you can add a key for security purposes. After that, the RDB store can be accessed only with the correct key.

**Table 2** API for changing the key
| Class| API| Description|
|  ----  |  ----  |  ----  |
| RdbStore | int ChangeEncryptKey(const std::vector<uint8_t> &newKey) | Changes the encryption key for an RDB store. <br>Note: The encryption key can be changed only for an encrypted RDB store.|

### Using Predicates

The RDB provides **AbsRdbPredicates** for you to set database operation conditions. The **AbsRdbPredicates** has the following child classes:

- **RdbPredicates**: With this class, you do not need to write complex SQL statements. Instead, you can combine SQL statements simply by calling methods in this class, such as **equalTo**, **notEqualTo**, **groupBy**, **orderByAsc**, and **beginsWith**.
- **RawRdbPredicates**: With this class, you can set **whereClause** and **whereArgs**, but cannot call methods such as **equalTo**.

  **Table 3** APIs for RDB store predicates 
  | Class| API| Description|
  |  ----  |  ----  |  ----  |
  | RdbPredicates | AbsPredicates *EqualTo(std::string field, std::string value) | Sets the **AbsPredicates** to match the field that is equal to the specified value.|
  | RdbPredicates | AbsPredicates *NotEqualTo(std::string field, std::string value) | Sets the **AbsPredicates** to match the field that is not equal to the specified value.|
  | RdbPredicates | AbsPredicates *BeginsWith(std::string field, std::string value) | Sets the **AbsPredicates** to match the field that starts with the specified value.|
  | RdbPredicates | AbsPredicates *Between(std::string field, std::string low, std::string high) | Sets the **AbsPredicates** to match the field that is within the range specified by **low** and **high**.|
  | RdbPredicates | AbsPredicates *OrderByAsc(std::string field) | Sets the **AbsPredicates** to match the column with values sorted in ascending order.|
  | RdbPredicates | void SetWhereClause(std::string whereClause) | Sets **whereClause**.|
  | RdbPredicates | void SetWhereArgs(std::vector\<std::string\> whereArgs) | Sets **whereArgs**, which indicates the value of the placeholder in **whereClause**.|
  | RdbPredicates | AbsRdbPredicates *InDevices(std::vector<std::string>& devices) | Sets the **AbsPredicates** to specify the remote devices on the network with databases to be synchronized.|
  | RdbPredicates | AbsRdbPredicates *InAllDevices() | Sets the **AbsPredicates** to connect to all remote devices on the network when synchronizing distributed databases.|


### Managing Data in an RDB Store

The RDB provides APIs for inserting, deleting, updating, and querying data in the local RDB store.

- Inserting data

  The RDB provides an API for inserting data through **ValuesBucket** in a data table. If the data is added, the row number of the data inserted is returned; otherwise, **-1** is returned.

  **Table 4** APIs for inserting data tables

  | Class| API| Description|
  |  ----  |  ----  |  ----  |
  | RdbStore | int Insert(int64_t &outRowId, const std::string &table, const ValuesBucket &initialValues) | Inserts data based on the passed table name and data in **ValuesBucket**. <br/>-&nbsp;**table**: specifies the name of the target table.<br/> -&nbsp;**initialValues**: specifies the data, stored in **ValuesBucket**, to insert. A series of **put()** methods, such as **PutString(const std::string &columnName, const std::string &value)** and **PutDouble(const std::string &columnName, double value)**, are provided to add data to **ValuesBucket**. |

- Deleting data
  
  Call the **delete()** method to delete data meeting the conditions specified by **AbsRdbPredicates**. If the data is deleted, the row number of the deleted data is returned; otherwise, **0** is returned.

  **Table 5** API for deleting data
  | Class| API| Description|
  |  ----  |  ----  |  ----  |
  | RdbStore | int Delete(int &deletedRows, const AbsRdbPredicates &predicates) | Deletes data. <br/>-&nbsp;**deletedRows**: specifies the number of rows to delete.<br/> -&nbsp;**predicates**: specifies the table name and conditions for deleting the data.<br/>  **AbsRdbPredicates** has the following classes:<br/> -&nbsp;**RdbPredicates**: specifies update conditions by calling its methods, such as **equalTo**.<br/> -&nbsp;**RawRdbPredicates**: specifies the table name, **whereClause** and **whereArgs** only. |

- Updating data

  Call the **update()** method to modify data based on the passed data and the conditions specified by **AbsRdbPredicates**. If the data is updated, the row number of the updated data is returned; otherwise, **0** is returned.

  **Table 6** API for updating data
  | Class| API| Description|
  |  ----  |  ----  |  ----  |
  | RdbStore | int Update(int &changedRows, const ValuesBucket &values, const AbsRdbPredicates &predicates) | Updates the data that meets the conditions specified by predicates.<br/> -&nbsp;**changedRows**: specifies the number of rows to update.<br/> -&nbsp;**values**: specifies the new data stored in **ValuesBucket**.<br/> -&nbsp;**predicates**: specifies the table name and conditions for the update operation.  **AbsRdbPredicates** has the following classes: <br/>-&nbsp;**RdbPredicates**: specifies update conditions by calling its methods, such as **equalTo**.<br/> -&nbsp;**RawRdbPredicates**: specifies the table name, **whereClause** and **whereArgs** only. |

- Querying data

  You can query data in an RDB store in either of the following ways:

  - Call the **query()** method to query data based on the predicates, without passing any SQL statement.
  - Run the native SQL statement.

  **Table 7** APIs for querying data
  | Class| API| Description|
  |  ----  |  ----  |  ----  |
  | RdbStore | std::unique_ptr<AbsSharedResultSet> Query(const AbsRdbPredicates &predicates, const std::vector\<std::string\> columns) | Queries data. <br/>-&nbsp;**predicates**: specifies the query conditions.  **AbsRdbPredicates** has the following classes: <br/>-&nbsp;**RdbPredicates**: specifies update conditions by calling its methods, such as **equalTo**. <br/>-&nbsp;**RawRdbPredicates**: specifies the table name, **whereClause**, and **whereArgs** only. <br/>-&nbsp;**columns**: specifies the number of columns returned. |
  | RdbStore | std::unique_ptr<AbsSharedResultSet> QuerySql(const std::string &sql, const std::vector\<std::string\> &selectionArgs = std::vector\<std::string\>()) | Executes the native SQL statements to query data. <br/>-&nbsp;**sql**: specifies the native SQL statement. <br/>-&nbsp;**selectionArgs**: specifies the parameter values corresponding to the placeholders in the SQL statements. Set it to **null** if the **select** statement has no placeholder. |

### Using the Result Set

A result set can be regarded as rows of data in the queried results. It allows you to traverse and access the data you have queried. The following table describes the external APIs of **ResultSet**.

**Table 8** APIs for using the result set
| Class| API| Description|
|  ----  |  ----  |  ----  |
| ResultSet | int GoTo(int offset) | Moves the result set forwards or backwards by the specified offset relative to its current position.|
| ResultSet | int GoToRow(int position) | Moves the result set to the specified row.|
| ResultSet | int GoToNextRow() | Moves the result set to the next row.|
| ResultSet | int GoToPreviousRow() | Moves the result set to the previous row.|
| ResultSet | int IsStarted(bool &result) | Checks whether the result set has been moved.|
| ResultSet | int IsEnded(bool &result) | Checks whether the result set is moved after the last line.|
| ResultSet | int IsAtFirstRow(bool &result) | Checks whether the result set is located in the first row.|
| ResultSet | int IsAtLastRow(bool &result) | Checks whether the result set is located in the last row.|
| ResultSet | int GetRowCount(int &count) | Obtains the number of rows in the result set.|
| ResultSet | int GetColumnCount(int &count) | Obtains the number of columns in the result set.|
| ResultSet | int GetString(int columnIndex, std::string &value) | Obtains the values in the specified column of the current row, in strings.|
| ResultSet | int GetBlob(int columnIndex, std::vector\<uint8_t\> &blob) | Obtains the values in the specified column of the current row, in a byte array.|
| ResultSet | int GetDouble(int columnIndex, double &value) | Obtains the values in the specified column of the current row, in double.|

### Setting a List of Distributed Tables

You can set a list of distributed tables for data operations across devices.

**Table 9** API for setting a distributed table list
| Class| API| Description|
|  ----  |  ----  |  ----  |
| RdbStore | bool SetDistributedTables(const std::vector<std::string>& tables) | Sets a list of distributed tables.<br/> -&nbsp;**tables**: specifies the names of the distributed tables to set. |

### Obtaining the Distributed Table Name for a Remote Device

When querying the RDB store of a remote device, you need to use the distributed table name. You can obtain the distributed table name of a remote device based on the local table name.

**Table 10** API for obtaining the distributed table name of a remote device

| Class| API| Description|
|  ----  |  ----  |  ----  |
| RdbStore | std::string ObtainDistributedTableName(const std::string& device, const std::string& table) | Obtains the distributed table name of a remote device based on the local table name. The distributed table name can be used to query the RDB store of the remote device.<br> -&nbsp;**device**: specifies the ID of the remote device.<br/> -&nbsp;**table**: specifies the name of the local table. |

### Synchronizing Data Between Devices

**Table 11** API for cross-device data synchronization

| Class| API| Description|
|  ----  |  ----  |  ----  |
| RdbStore | bool Sync(const SyncOption& option, const AbsRdbPredicates& predicate, const SyncCallback& callback) | Synchronizes data between devices.<br/> -&nbsp;**option**: specifies synchronization options, which include the following: <br/>**mode**: specifies how data is synchronized. The value **push** means to push data from the local device to the remote device; the value **pull** means to pull data from the remote device to the local device. <br/>**isBlock**: specifies whether the invocation of this function is blocked. <br/>-&nbsp;**callback**: specifies the callback used to return the result. |

### Registering an RDB Store Observer

**Table 12** API for registering an observer

| Class| API| Description|
|  ----  |  ----  |  ----  |
| RdbStore | bool Subscribe(const SubscribeOption& option, RdbStoreObserver *observer) | Registers an observer for this RDB store to subscribe to distributed data changes. When data in the RDB store changes, a callback will be invoked to return the data changes.<br/> -&nbsp;**option**: specifies the subscription type.<br/>-&nbsp;**observer**: specifies the observer of data changes in the RDB store. |

### Unregistering an RDB Store Observer

**Table 13** API for unregistering an observer

| Class| API| Description|
|  ----  |  ----  |  ----  |
| RdbStore | bool UnSubscribe(const SubscribeOption& option, RdbStoreObserver *observer) | Unregisters the observer of the specified type to unsubscribe from distributed data changes.<br/> -&nbsp;**option**: specifies the subscription type to unregister.<br/>-&nbsp;**observer**: specifies the observer to unregister. |

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

    Call the **SetDistributedTables()** method to set the distributed tables to be synchronized.

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

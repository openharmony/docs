# Lightweight Data Store Development

## When to Use

The lightweight data store is ideal for storing lightweight and frequently used data, but not for storing a large amount of data or data with frequent changes. The application data is persistently stored on a device in the form of files. Note that the instance accessed by an application contains all data of the file. The data is always loaded to the memory of the device until the application removes it from the memory. The application can perform data operations using the Preferences APIs.

## Available APIs

The lightweight data store provides applications with data processing capability and allows applications to perform lightweight data storage and query. Data is stored in key-value pairs. Keys are of the string type, and values can be of the string, Boolean, integer, long integer, float, double, or string array type.

**Creating a Preferences Instance**

Create a **Preferences** instance for data operations. A **Preferences** instance is created after data is read from a specified file and loaded to the instance.

**Table 1** API for creating a Preferences instance

| Class| Method| Description|
| --- | ----- | ----|
| PreferencesHelper | static std::shared_ptr<Preferences> GetPreferences(const std::string &path, int &errCode); | Creates a **Preferences** instance. <br/>**path**: storage path of the application data. <br/>**errCode**: error code. <br/>Return value: **Preferences** instance created.|

**Writing Data**

Call the **put()** method to add or modify data in a **Preferences** instance.

**Table 2** APIs for writing data

| Class| Method| Description|
| --- | ----- | ----|
| Preferences | int PutInt(const std::string &key, int value); | **key**: key of the data to write. It cannot be empty. <br/>**value**: value of the data to write. <br/>Return value: error code.|
| Preferences | int PutString(const std::string &key, const std::string &value); | **key**: key of the data to write. It cannot be empty. <br/>**value**: value of the data to write. <br/>Return value: error code.|
| Preferences | int PutBool(const std::string &key, bool value); | **key**: key of the data to write. It cannot be empty. <br/>**value**: value of the data to write. <br/>Return value: error code.|
| Preferences | int PutLong(const std::string &key, int64_t value); | **key**: key of the data to write. It cannot be empty. <br/>**value**: value of the data to write. <br/>Return value: error code.|
| Preferences | int PutFloat(const std::string &key, float value); | **key**: key of the data to write. It cannot be empty. <br/>**value**: value of the data to write. <br/>Return value: error code.|
| Preferences | int PutDouble(const std::string &key, double value); | **key**: key of the data to write. It cannot be empty. <br/>**value**: value of the data to write. <br/>Return value: error code.|
| Preferences | int PutStringSet(const std::string &key, const std::set\<std::string\> &value); | **key**: key of the data to write. It cannot be empty. <br/>**value**: value of the data to write. <br/>Return value: error code.|

**Reading Data**

Call the **get()** method to read data from a **Preferences** instance.

**Table 3** APIs for reading data

| Class| Method| Description|
| --- | ----- | ----|
| Preferences | bool GetBool(const std::string &key, bool defValue); | **key**: key of the data to read. It cannot be empty. <br/>**defValue**: default value to return if the operation fails or the value does not exist. <br/>Return value: Returns the value read if the operation is successful; returns **defValue** otherwise.|
| Preferences | std::string GetString(const std::string &key, const std::string &defValue); | **key**: key of the data to read. It cannot be empty. <br/>**defValue**: default value to return if the operation fails or the value does not exist. <br/>Return value: Returns the value read if the operation is successful; returns **defValue** otherwise.|
| Preferences | bool GetBool(const std::string &key, bool defValue); | **key**: key of the data to read. It cannot be empty. <br/>**defValue**: default value to return if the operation fails or the value does not exist. <br/>Return value: Returns the value read if the operation is successful; returns **defValue** otherwise.|
| Preferences | float GetFloat(const std::string &key, float defValue); | **key**: key of the data to read. It cannot be empty. <br/>**defValue**: default value to return if the operation fails or the value does not exist. <br/>Return value: Returns the value read if the operation is successful; returns **defValue** otherwise.|
| Preferences | double GetDouble(const std::string &key, double defValue); | **key**: key of the data to read. It cannot be empty. <br/>**defValue**: default value to return if the operation fails or the value does not exist. <br/>Return value: Returns the value read if the operation is successful; returns **defValue** otherwise.|
| Preferences | int64_t GetLong(const std::string &key, int64_t defValue); | **key**: key of the data to read. It cannot be empty. <br/>**defValue**: default value to return if the operation fails or the value does not exist. <br/>Return value: Returns the value read if the operation is successful; returns **defValue** otherwise.|
| Preferences | std::set\<std::string\> GetStringSet(const std::string &key, std::set\<std::string\> &defValue); | **key**: key of the data to read. It cannot be empty. <br/>**defValue**: default value to return if the operation fails or the value does not exist. <br/>Return value: Returns the value read if the operation is successful; returns **defValue** otherwise.|

**Storing Data Persistently**

Call the **flush()** or **flushSync** method to write the cached data back to its text file for persistent storage.

**Table 4** APIs for data persistence

| Class| Method| Description|
| --- | ----- | ----|
| Preferences | void Flush(); | Writes data in the **Preferences** instance back to its file through an asynchronous thread.|
| Preferences | int FlushSync(); | Writes data in the **Preferences** instance back to its file through a synchronous thread.|

**Observing Data Changes**

Specify **PreferencesObserver** as the callback to subscribe to data changes. When the value of the subscribed key is changed and the **flush()** method is executed, **PreferencesObserver** will be invoked.

**Table 5** APIs for subscribing to data changes

| Class| Method| Description|
| --- | ----- | ----|
| Preferences | void RegisterObserver(std::shared_ptr<PreferencesObserver> preferencesObserver); | Subscribes to data changes. <br/>**preferencesObserver**: callback invoked to return the data changes.|
| Preferences | void UnRegisterObserver(std::shared_ptr<PreferencesObserver> preferencesObserver); | Unsubscribes from data changes. <br/>**preferencesObserver**: callback used to report data changes.|

**Deleting Data**

Use the following APIs to delete a **Preferences** instance or data file.

**Table 6** APIs for deleting data

| Class| Method| Description|
| --- | ----- | ----|
| PreferencesHelper | int DeletePreferences(const std::string &path); | Deletes a **Preferences** instance from the memory and deletes its file from the device. <br/>**path**: storage path of the application data. <br/>Return value: error code.|
| PreferencesHelper | int RemovePreferencesFromCache(const std::string &path); | Deletes a **Preferences** instance from the memory. <br/>**path**: storage path of the application data. <br/>Return value: error code.|

## How to Develop

1.  Import the Preferences module and related header files to the development environment.

    ``` C++
    Header file path: //distributeddatamgr_appdatamgr/interfaces/innerkits/native_preferences/include
    ```

2.  Create a **Preferences** instance.

    Read the specified file and load its data to the **Preferences** instance for data operations.

    ``` C++
    int errCode = E_OK;
    Preferences pref = PreferencesHelper::GetPreferences(PREF_TEST_PATH + "test.xml", errCode); // PREF_TEST_PATH must be the application sandbox path.
    EXPECT_EQ(errCode, E_OK);
    ```


3.  Write data.

    Use the **put()** method of the **Preferences** class to write data to the cached **Preferences** instance.

    ```C++
    pref->PutString("test", "remove");
    ```

4.  Read data.

    Use the **get()** method of the **Preferences** class to read data.

    ``` C++
    std::string ret = pref->GetString("test", "defaultValue");
    EXPECT_EQ(ret, "remove");
    ```


5. Store data persistently.

   Use the **flush()** or **flushSync()** method to flush data in the **Preferences** instance to its file.

    ```C++
    int err = pref->FlushSync();
    EXPECT_EQ(ret, E_OK);
    ```
   

6. Subscribe to data changes.

    Specify **PreferencesObserver** as the callback to subscribe to data changes for an application. When the value of the subscribed key is changed and the **flush()** or **flushSync()** method is executed, **PreferencesObserver** will be invoked. Unregister the **PreferencesObserver** when it is no longer required.

    Customize a class to implement the **PreferencesObserver**:
    ``` C++
    class PreferencesObserverCounter : public PreferencesObserver {
    public:
    virtual ~PreferencesObserverCounter();
    void OnChange(Preferences &preferences, const std::string &key) override;
    
        std::atomic_int notifyTimes;
        static const std::vector<std::string> NOTIFY_KEYS_VECTOR;
    };

    PreferencesObserverCounter::~PreferencesObserverCounter() {}
    
    void PreferencesObserverCounter::OnChange(Preferences &preferences, const std::string &key)
    {
        for (auto it = NOTIFY_KEYS_VECTOR.cbegin(); it != NOTIFY_KEYS_VECTOR.cend(); it++) {
            if (key.compare(*it)) {
                notifyTimes++;
                break;
            }
        }
    }

    const std::vector<std::string> PreferencesObserverCounter::NOTIFY_KEYS_VECTOR = { PreferencesTest::KEY_TEST_INT_ELEMENT,
        PreferencesTest::KEY_TEST_LONG_ELEMENT, PreferencesTest::KEY_TEST_FLOAT_ELEMENT,
        PreferencesTest::KEY_TEST_BOOL_ELEMENT, PreferencesTest::KEY_TEST_STRING_ELEMENT };
    ```

    Subscribe to data changes and invoke the callback:
    ``` C++
    std::shared_ptr<PreferencesObserver> counter =
        std::shared_ptr<PreferencesObserver>(new PreferencesObserverCounter());
    pref->RegisterObserver(counter); // Register a callback to return data changes.

    pref->PutString(PreferencesTest::KEY_TEST_STRING_ELEMENT, "test");
    pref->Flush(); // Trigger the onChanged callback of the counter.
    EXPECT_EQ(static_cast<PreferencesObserverCounter *>(counter.get())->notifyTimes, 1);

    /* same value */
    pref->PutInt(PreferencesTest::KEY_TEST_INT_ELEMENT, 2);
    pref->PutString(PreferencesTest::KEY_TEST_STRING_ELEMENT, "test");
    pref->Flush();
    EXPECT_EQ(static_cast<PreferencesObserverCounter *>(counter.get())->notifyTimes, 2);

    pref->UnRegisterObserver(counter); // Unregister the callback for data changes.
    ```


7.  Delete the specified file.

    Delete the **Preferences** singleton of the specified file from the memory, and delete the specified file, its backup file, and damaged files. After the specified files are deleted, the application cannot use that instance to perform any data operation. Otherwise, data inconsistency will occur. The deleted data and files cannot be restored.

    ``` C++
    pref = nullptr;
    int ret = PreferencesHelper::DeletePreferences("/data/test/test");
    EXPECT_EQ(ret, E_OK);
    ```

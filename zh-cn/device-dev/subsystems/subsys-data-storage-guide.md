# 轻量级数据存储开发指导

## 场景介绍

轻量级数据存储功能通常用于保存应用的一些常用配置信息，并不适合需要存储大量数据和频繁改变数据的场景。应用的数据保存在文件中，这些文件可以持久化地存储在设备上。需要注意的是，应用访问的实例包含文件所有数据，这些数据会一直加载在设备的内存中，直到应用主动从内存中将其移除前，应用可以通过Preferences的API进行数据操作。

## 接口说明

轻量级存储为应用提供key-value键值型的文件数据处理能力，支持应用对数据进行轻量级存储及查询。数据存储形式为键值对，键的类型为字符串型，值的存储数据类型包括字符串型、布尔型、整数型、长整型、浮点型、双精度类型和字符串数组。

**创建存储实例**

读取指定文件，将数据加载到Preferences实例，即可创建一个存储实例，用于数据操作。

**表 1**  轻量级数据存储实例创建接口

| 类名 | 方法名 | 描述 |
| --- | ----- | ----|
| PreferencesHelper | static std::shared_ptr<Preferences> GetPreferences(const std::string &path, int &errCode); | path：应用程序内部数据存储路径。<br/>errCode：错误码。<br/>返回值：轻量级存储实例。 |

**存入数据**

通过Put系列方法，可以增加或修改Preferences实例中的数据。

**表 2**  轻量级偏好数据库存入接口

| 类名 | 方法名 | 描述 |
| --- | ----- | ----|
| Preferences | int PutInt(const std::string &key, int value); | key：将要存储的key名称，不能为空。<br/>value：将要存储的value。<br/>返回值：错误码。 |
| Preferences | int PutString(const std::string &key, const std::string &value); | key：将要存储的key名称，不能为空。<br/>value：将要存储的value。<br/>返回值：错误码。 |
| Preferences | int PutBool(const std::string &key, bool value); | key：将要存储的key名称，不能为空。<br/>value：将要存储的value。<br/>返回值：错误码。 |
| Preferences | int PutLong(const std::string &key, int64_t value); | key：将要存储的key名称，不能为空。<br/>value：将要存储的value。<br/>返回值：错误码。 |
| Preferences | int PutFloat(const std::string &key, float value); | key：将要存储的key名称，不能为空。<br/>value：将要存储的value。<br/>返回值：错误码。 |
| Preferences | int PutDouble(const std::string &key, double value); | key：将要存储的key名称，不能为空。<br/>value：将要存储的value。<br/>返回值：错误码。 |
| Preferences | int PutStringSet(const std::string &key, const std::set\<std::string\> &value); | key：将要存储的key名称，不能为空。<br/>value：将要存储的。<br/>返回值：错误码。 |

**读取数据**

通过调用Get系列方法，可以读取Preferences中的数据。

**表 3**  轻量级数据读取接口

| 类名 | 方法名 | 描述 |
| --- | ----- | ----|
| Preferences | int GetInt(const std::string &key, const int defValue = {}); | key：要获取的存储key名称，不能为空。<br/>defValue：若获取失败或value不存在返回此默认值。<br/>返回值：value。 |
| Preferences | std::string GetString(const std::string &key, const std::string &defValue = {}); | key：要获取的存储key名称，不能为空。<br/>defValue：若获取失败或value不存在返回此默认值。<br/>返回值：value。 |
| Preferences | bool GetBool(const std::string &key, const bool defValue = {}); | key：要获取的存储key名称，不能为空。<br/>defValue：若获取失败或value不存在返回此默认值。<br/>返回值：value。 |
| Preferences | float GetFloat(const std::string &key, const float defValue = {}); | key：要获取的存储key名称，不能为空。<br/>defValue：若获取失败或value不存在返回此默认值。<br/>返回值：value。 |
| Preferences | double GetDouble(const std::string &key, const double defValue = {}); | key：要获取的存储key名称，不能为空。<br/>defValue：若获取失败或value不存在返回此默认值。<br/>返回值：value。 |
| Preferences | int64_t GetLong(const std::string &key, const int64_t defValue = {}); | key：要获取的存储key名称，不能为空。<br/>defValue：若获取失败或value不存在返回此默认值。<br/>返回值：value。 |
| Preferences | std::set\<std::string\> GetStringSet(const std::string &key, const std::set\<std::string\> &defValue = {}); | key：要获取的存储key名称，不能为空。<br/>defValue：若获取失败或value不存在返回此默认值。<br/>返回值：value。 |

**数据持久化**

通过执行Flush()或者FlushSync()方法，应用可以将缓存的数据再次写回文本文件中进行持久化存储。

**表 5**  轻量级数据数据持久化接口

| 类名 | 方法名 | 描述 |
| --- | ----- | ----|
| Preferences | void Flush(); | 将Preferences实例通过异步线程回写入文件中。 |
| Preferences | int FlushSync(); | 将Preferences实例通过同步线程回写入文件中，并返回错误码。 |

**订阅数据变化**

订阅数据变化需要指定PreferencesObserver作为回调方法。订阅的key的值发生变更后，当执行flush方法时，PreferencesObserver被回调。

**表 5**  轻量级数据变化订阅接口

| 类名 | 方法名 | 描述 |
| --- | ----- | ----|
| Preferences | void RegisterObserver(std::shared_ptr<PreferencesObserver> preferencesObserver); | preferencesObserver：需要订阅的回调对象实例。 |
| Preferences | void UnRegisterObserver(std::shared_ptr<PreferencesObserver> preferencesObserver); | preferencesObserver：需要注销订阅的回调对象实例。 |

**删除数据文件**

通过调用以下两种接口，可以删除数据实例或对应的文件。

**表 6**  轻量级数据存储删除接口

| 类名 | 方法名 | 描述 |
| --- | ----- | ----|
| PreferencesHelper | int DeletePreferences(const std::string &path); | 将Preferences实例从内存中移除，同时删除其在设备上的持久化文件。path：应用程序内部数据存储路径。<br/>返回值：错误码。 |
| PreferencesHelper | int RemovePreferencesFromCache(const std::string &path); | 仅将Preferences实例从内存中移除。path：应用程序内部数据存储路径。<br/>返回值：错误码。 |

## 开发步骤

1.  准备工作，引入preferences以及相关的头文件到开发环境。

    ``` C++
    头文件路径：//distributeddatamgr_appdatamgr/interfaces/innerkits/native_preferences/include
    ```

2.  获取Preferences实例。

    读取指定文件，将数据加载到Preferences实例，用于数据操作。

    ``` C++
    int errCode = E_OK;
    Preferences pref = PreferencesHelper::GetPreferences(PREF_TEST_PATH + "test.xml", errCode);  // PREF_TEST_PATH须为应用沙箱路径。
    EXPECT_EQ(errCode, E_OK);
    ```


3.  存入数据。

    使用Preferences put方法保存数据到缓存的实例中。

    ```C++
    pref->PutString("test", "remove");
    ```

4.  读取数据。

    使用Preferences get方法读取数据。

    ``` C++
    std::string ret = pref->GetString("test", "defaultValue");
    EXPECT_EQ(ret, "remove");
    ```


5. 数据持久化。

   应用存入数据到Preferences实例后，可以通过Flush()或者FlushSync()方法将Preferences实例回写到文件中。

    ```C++
    int err = pref->FlushSync();
    EXPECT_EQ(ret, E_OK);
    ```
   
6. 订阅数据变化。

    应用订阅数据变化需要指定PreferencesObserver作为回调方法。订阅的key的值发生变更后，当执行flush或者flushSync方法时，PreferencesObserver被触发回调。不再需要PreferencesObserver时请注销。

    自定义类，实现PreferencesObserver接口：
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

    订阅数据变化，并触发执行回调方法：
    ``` C++
    std::shared_ptr<PreferencesObserver> counter =
        std::make_shared<PreferencesObserverCounter>();
    pref->RegisterObserver(counter);  // 注册数据变化的回调。
    
    pref->PutString(PreferencesTest::KEY_TEST_STRING_ELEMENT, "test");
    pref->Flush();  // 触发执行counter的onChanged回调方法。
    EXPECT_EQ(static_cast<PreferencesObserverCounter *>(counter.get())->notifyTimes, 1);
    
    /* same value */
    pref->PutInt(PreferencesTest::KEY_TEST_INT_ELEMENT, 2);
    pref->PutString(PreferencesTest::KEY_TEST_STRING_ELEMENT, "test");
    pref->Flush();
    EXPECT_EQ(static_cast<PreferencesObserverCounter *>(counter.get())->notifyTimes, 2);
    
    pref->UnRegisterObserver(counter);  // 注销注册数据变化的回调。
    ```


7.  删除指定文件。

    从使用PreferencesHelper内存中移除指定文件对应的Preferences单实例，并删除指定文件及其备份文件、损坏文件。删除指定文件时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。删除后，数据及文件将不可恢复。

    ``` C++
    pref = nullptr;
    int ret = PreferencesHelper::DeletePreferences("/data/test/test");
    EXPECT_EQ(ret, E_OK);
    ```


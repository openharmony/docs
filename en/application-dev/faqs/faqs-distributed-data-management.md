# Data Management Development


## How do I encrypt an RDB store? (API version 9)

**Solution**

To encrypt an RDB store, set **encrypt** in **StoreConfig** to **true** when creating the RDB store.

**Reference**

[RDB Store](../reference/apis-arkdata/js-apis-data-relationalStore.md#storeconfig)


## What should I do if the table data in an RDB store cannot be cleared by using **TRUNCATE TABLE**? (API version 9)

**Symptom**

An error is reported when the **TRUNCATE TABLE** statement is used to clear table data.

**Solution**

The RDB store uses SQLite, which does not support the **TRUNCATE TABLE** statement. To clear a table in an RDB store, use the **DELETE** statement, for example, **DELETE FROM sqlite_sequence WHERE name = 'table_name'**.


## What data types are supported by an RDB store? (API version 9)

Applicable to: stage model

**Solution**

An RDB store supports data of the number, string, and Boolean types. The number type supports data of the Double, Long, Float, Int, or Int64 type, with a maximum precision of 17 decimal digits.


## How do I persistent application data? (API version 9)

**Solution**

You can use the **PersistentStorage** class to implement application data persistence. You can link the persistent data with specific tags to **AppStorage**, and invoke **AppStorage** APIs to access the persistent data. Persistent data is stored in a local XML file in **/data/app/el2/100/base/&lt;bundleName&gt;/haps/&lt;hapName&gt;/files/persistent_storage**.

Example:

```
AppStorage.Link('varA')
PersistentStorage.PersistProp("varA", "111");
@Entry
@Component
struct Index {
  @StorageLink('varA') varA: string = ''
  build() {
    Column() {
      Text('varA: ' + this.varA).fontSize(20)
      Button('Set').width(100).height(100).onClick(() => {
        this.varA += '333'
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

**Reference**

[ PersistentStorage: Application State Persistence](../quick-start/arkts-persiststorage.md)


## How do I save pixel map data to a database? (API version 9)

**Solution**

Convert the pixel map data into an **ArrayBuffer** and save the **ArrayBuffer** to your database.

**Reference**

[readPixelsToBuffer](../reference/apis-image-kit/js-apis-image.md#readpixelstobuffer7-1)


## How do I obtain RDB store files? (API version 9)

**Symptom**

Problem of obtaining RDB store files.

**Solution**

The RDB store files are stored in **/data/app/el2/100/database/*Bundle_name*/entry/rdb/**. You can use the hdc command to copy the file from the directory and use a SQLite tool to open the file.

Example:

```
 hdc file recv /data/app/el2/100/database/<bundleName>/entry/db/<tableName>  ./<path>
```


## Should I design a lock mechanism for databases in development? (API version 9)

**Symptom**

I do not know whether I need to design a lock mechanism for databases in development.   

**Solution**

The distributed data service (DDS), RDB store, and preferences provided by OpenHarmony have a lock mechanism. You do not need to bother with the lock mechanism during the development.


## What should I do if I failed to use get() to obtain the data saved by @ohos.data.storage put()? (API version 9)

**Symptom**

After @ohos.data.storage **put()** is called to save data, **get()** is called to obtain the data. However, the data fails to be obtained.

**Solution**

The **put()** method provided by **@ohos.data.storage** saves data in the memory. When the application exits, the data in the memory will be cleared. If you want to persist the data, you need to call **flush()** or **flushSync()** after **put()**. After data is persisted, you can use **get()** to obtain the data after the application is restarted.


## What should I do if a large text file fails to be saved in an RDB store? (API version 9)

**Symptom**

In API version 8, large text files cannot be saved in RDB stores.

**Solution**

In versions earlier than API version 9, the maximum length of a text file is 1024 bytes. If the text file exceeds 1024 bytes, it cannot be saved.

The limit on the text file size has been removed since API9 version.


## What should I do if "undefined" is returned by Preferences.get after Preferences.put is successful? (API version 9)

**Symptom**

Data is successfully saved using **Preferences.put()**, but fails to be obtained by **Preferences.get()**.

**Solution**

1. After **put()** is performed, use **flush()** to persist the data.

2. Call **get()**.


## Can I specify the in-memory database mode when using an RDB store? (API version 9)

**Solution**

RDB stores use SQLite. The default in-memory database mode is file, which cannot be changed.


## How do I obtain the size of an RDB store?

**Solution**

You can use [execute](../reference/apis-arkdata/js-apis-data-relationalStore.md#execute12) to obtain the size of an RDB store, for example, SELECT page_count * page_size AS size FROM pragma_page_count(), pragma_page_size().

## How do I obtain the path of an RDB store?

**Solution**

1. If you has the root permission, run the **find /data -name database_name** command.

2. You can use File Browser of DevEco Studio to obtain the database file path.

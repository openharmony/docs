# Data Management Development


## How do I encrypt an RDB store?

Applicable to: OpenHarmony 3.1 Beta 5 (API version 9)

**Solution**

To encrypt an RDB store, set **encrypt** in **StoreConfig** to **true** when creating the RDB store.

**Reference**

[RDB Store](../reference/apis/js-apis-data-relationalStore.md#storeconfig)

## What if I failed to clear a table in an RDB store using TRUNCATE TABLE?

Applicable to: OpenHarmony SDK 3.2.9.2 (API version 9)

**Symptom**

An error is reported when the **TRUNCATE TABLE** statement is used to clear table data.

**Solution**

The RDB store uses SQLite and does not support the **TRUNCATE TABLE** statement. To clear a table in an RDB store, use the **DELETE** statement, for example, **DELETE FROM sqlite\_sequence WHERE name = 'table\_name'**.



## What data types does an RDB store support?

Applicable to: OpenHarmony SDK 3.0 or later, API version 9 stage model

**Solution**

An RDB store supports data of the number, string, and Boolean types. The number type supports data of the Double, Long, Float, Int, or Int64 type, with a maximum precision of 17 decimal digits.

## How do I save pixel map data to a database? 

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Symptom**

Pixel map data fails to be stored.

**Solution**

Convert the pixel map data into an **ArrayBuffer** and save the **ArrayBuffer** to your database.

**Reference**

[readPixelsToBuffer](../reference/apis/js-apis-image.md#readpixelstobuffer7-1)

## How do I obtain RDB store files?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

The RDB store files are stored in **/data/app/el2/100/database/*Bundle_name*/entry/rdb/**. You can use the hdc command to copy the file from the directory and use a SQLite tool to open the file.

Example:

```
 hdc file recv /data/app/el2/100/database/<bundleName>/entry/db/<tableName>  ./<path>
```

## Do the OpenHarmony databases have a lock mechanism?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

The distributed data service (DDS), RDB store, and preferences provided OpenHarmony have a lock mechanism. You do not need to bother with the lock mechanism during the development.

## What if I failed to use get() to obtain the data saved by @ohos.data.storage put()?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Symptom**

After @ohos.data.storage **put()** is called to save data, **get()** is called to obtain the data. However, the data fails to be obtained.

**Solution**

The **put()** method provided by **@ohos.data.storage** saves data in the memory. When the application exits, the data in the memory will be cleared. If you want to persist the data, you need to call **flush()** or **flushSync()** after **put()**. After data is persisted, you can use **get()** to obtain the data after the application is restarted.


## What if a large text file fails to be saved in an RDB store?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Symptom**

In API version 8, large text files cannot be saved in RDB stores.

**Solution**

In versions earlier than API version 9, the maximum length of a text file is 1024 bytes. If the text file exceeds 1024 bytes, it cannot be saved.

The limit on the text file size has been removed since API9 version.

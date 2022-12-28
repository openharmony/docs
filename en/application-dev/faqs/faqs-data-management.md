# Data Management Development

## How Do I Save PixelMap Data to a Database?

Applicable to: OpenHarmony SDK 3.2.3.5

You can convert a **PixelMap** into an **ArrayBuffer** and save the **ArrayBuffer** to your database.

Reference: [readPixelsToBuffer](../reference/apis/js-apis-image.md#readpixelstobuffer7-1)

## How Do I Obtain RDB Store Files?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Run the hdc_std command to copy the .db, .db-shm, and .db-wal files in **/data/app/el2/100/database/*bundleName*/entry/db/**, and then use the SQLite tool to open the files.

Example:

```
 hdc_std file recv /data/app/el2/100/database/com.xxxx.xxxx/entry/db/test.db ./test.db
```

## Does the Database Has a Lock Mechanism?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

The distributed data service (DDS), relational database (RDB) store, and preferences provided OpenHarmony have a lock mechanism. You do not need to bother with the lock mechanism during the development.

## What Is a Transaction in an RDB Store?

Applicable to: all versions

When a large number of operations are performed in an RDB store, an unexpected exception may cause a failure of some data operations and loss of certain data. As a result, the application may become abnormal or even crash. 

A transaction is a group of tasks serving as a single logical unit. It eliminates the failure of some of the operations and loss of associated data.

## What Data Types Does an RDB Store Support?

Applicable to: OpenHarmony SDK 3.0 or later, stage model of API version 9

An RDB store supports data of the number, string, and Boolean types. The number array supports data of the Double, Long, Float, Int, or Int64 type, with a maximum precision of 17 decimal digits.

## How Do I View Database db Files?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

1. Run the **hdc_std shell** command.

2. Obtain the absolute path or sandbox path of the database. 
   
The absolute path is **/data/app/el2/<userId>/database/<bundleName>**. The default **<userId>** is **100**.
   
To obtain the sandbox path, run the **ps -ef | grep hapName** command to obtain the process ID of the application.
   
The database sandbox path is **/proc/<Application process ID>/root/data/storage/el2/database/**.
   
3. Run the **find ./ -name "\*.db"** command in the absolute path or sandbox path of the database.

## How Do I Store Long Text Data?

Applicable to: OpenHarmony SDK 3.2.5.5, API version 9

- Preferences support a string of up to 8192 bytes.

- The KV store supports a value of up to 4 MB.

Reference: [Preference Overview](../database/database-preference-overview.md) and [Distributed Data Service Overview](../database/database-mdds-overview.md)

## How Do I Develop DataShare on the Stage Model

Applicable to: OpenHarmony SDK 3.2.5.5, API version 9

The DataShare on the stage model cannot be used with the **DataAbility** for the FA model. The connected server application must be implemented by using **DataShareExtensionAbility**.

Reference: [DataShare Development](../database/database-datashare-guidelines.md)


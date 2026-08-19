# Access Control by Device and Data Level (C/C++)

<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @htt1997-->
<!--Tester: @logic42-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=21aa413cf1755b055fbf63fdc2c1e46117039e5c translatedAt=2026-08-15T01:42:29.739Z pushedAt=2026-08-15T06:21:27.244Z -->

## When to Use

The access control mechanism ensures secure data storage and sync across devices. When creating a database, you need to correctly set the security label based on the specifications to ensure the consistency between the database content and data labels.

Currently, only RDB stores (C/C++) support hierarchical access control.

## Basic Concepts

Distributed data management implements access control based on data security labels and device security levels.

A higher data security label and device security level indicate stricter encryption and access control measures and higher data security.

### Data Security Labels

The data can be rated into four security levels as below. For details, see [OH_Rdb_SecurityLevel](../reference/apis-arkdata/capi-relational-store-h.md#oh_rdb_securitylevel).

| Risk Level| Security Level| Definition| Example| 
| -------- | -------- | -------- | -------- |
| Critical| S4 | Special data types defined by industry laws and regulations, involving the most private individual information or data that may cause severe adverse impact on an individual or group once disclosed, tampered with, corrupted, or destroyed.| Political opinions, religious and philosophical belief, trade union membership, genetic data, biological information, health and sexual life status, sexual orientation, device authentication, and personal credit card information| 
| High| S3 | Data that may cause critical adverse impact on an individual or group once disclosed, tampered with, corrupted, or destroyed.| Individual real-time precise positioning information and movement trajectory| 
| Moderate| S2 | Data that may cause major adverse impact on an individual or group once disclosed, tampered with, corrupted, or destroyed.| Detailed addresses and nicknames of individuals| 
| Low| S1 | Data that may cause minor adverse impact on an individual or group once disclosed, tampered with, corrupted, or destroyed.| Gender, nationality, and user application records| 

### Device Security Levels

<!--RP1-->

Device security levels are classified into SL1 to SL5 based on devices' security capabilities, such as whether a Trusted Execution Environment (TEE) or a secure storage chip is available. For example, the development boards RK3568 and Hi3516 are SL1 (lower security) devices, and tablets are SL4 (higher security) devices.

After the devices are networked, you can run the `hidumper -s 3511` command to check the device security level. If no result is returned, run the `service_control start dslm_service` command to start the corresponding service, and then run the hidumper command again. The following figure shows the security level of an RK3568 device.

<!--RP1End-->
<!--Del-->

![Device-Security-Levels](figures/Device-Security-Levels.png)

<!--DelEnd-->

## Access Control Mechanism in Cross-Device Sync

In cross-device data sync, data access is controlled based on the device security level and data security labels. In principle, data can be synced only to the devices whose data security labels are not higher than the device's security level. The access control matrix is as follows.

|Device Security Level|Data Security Labels That Can Be Synced|
|---|---|
|SL1|S1|
|SL2|S1~S2|
|SL3|S1~S3|
|SL4|S1~S4|
|SL5|S1~S4| 

<!--RP2-->

The security level of development boards RK3568 and Hi3516 is SL1. The database with data security label S1 can be synced with RK3568 and Hi3516, but the databases with labels S2–S4 cannot.

<!--RP2End-->

## How to Develop

When creating an RDB store, call the **OH_Rdb_SetSecurityLevel** API to specify the security level of the RDB store. The following example shows how to create an RDB store with security level of SL3.

1. Add the following library to **CMakeLists.txt**.

    ```txt
    libnative_rdb_ndk.z.so
    ```

2. Include header files.

    <!-- @[encryption_include](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/RelationalStore/NativeDataEncryption/entry/src/main/cpp/napi_init.cpp) --> 

    ``` C++
    #include <cstring>
    #include "database/rdb/relational_store.h"
    #include "hilog/log.h"
    ```

3. Call **OH_Rdb_SetSecurityLevel** to set the database security level.

    <!-- @[SetSecurityLevelForRdbStore](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/RelationalStore/NativeDataEncryption/entry/src/main/cpp/napi_init.cpp) -->

    ``` C++
    OH_Rdb_ConfigV2 *config = OH_Rdb_CreateConfig();
    OH_Rdb_SetDatabaseDir(config, "/data/storage/el2/database");
    OH_Rdb_SetStoreName(config, "RdbTest.db");
    OH_Rdb_SetBundleName(config, "com.example.nativedemo");
    OH_Rdb_SetModuleName(config, "entry");
    // Set the security level of the database.
    OH_Rdb_SetSecurityLevel(config, OH_Rdb_SecurityLevel::S3);
    OH_Rdb_SetEncrypted(config, false);
    OH_Rdb_SetArea(config, RDB_SECURITY_AREA_EL2);
        
    int errCode = 0;
    OH_Rdb_Store *store_ = OH_Rdb_CreateOrOpen(config, &errCode);
    OH_Rdb_CloseStore(store_);
    store_ = nullptr;
    OH_Rdb_DestroyConfig(config);
    config = nullptr;
    ```
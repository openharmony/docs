# Sharing Data via Unified Data Channels (C/C++)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @jcwen-->
<!--Designer: @junathuawei1; @zph000-->
<!--Tester: @lj_liujing; @yippo; @logic42-->
<!--Adviser: @ge-yafang-->


## When to Use

In many-to-many data sharing across applications, a data channel needs to be provided to write data of different applications and share the data with other applications.

The Unified Data Management Framework (UDMF) provides unified data channels and standard APIs for writing and reading data across applications in different service scenarios.

## Definition and Implementation of Unified Data Channels

Unified data channels are used to write and read data across applications in various service scenarios. They can temporarily store unified data objects that need to be shared by applications and comply with unified data definitions, and provide the data objects for other applications to access. In addition, they can modify temporarily stored data, delete permissions, and manage lifecycles based on certain policies.

The unified data channel is implemented by the system ability provided by UDMF. When an application (data provider) needs to share data, it calls the **insertData()** method to write the data to the UDMF data channel, and calls **updateData()** or **deleteData()** to update or delete the data saved by the application. The target application (data consumer) can access the data by the APIs provided by UDMF.

Avoid using **unifiedDataChannel** APIs in multi-threaded calls.

The unified data object (**UnifiedData**) is uniquely identified by a URI in the UDMF data channel. The URI is in the **udmf://*intention*/*bundleName*/*groupId*** format, where:

+ **udmf**: protocol used to provide the data channel.

+ ***intention***: an enum of the data channel types supported by UDMF.

+ ***bundleName***: bundle name of the data source application.

+ ***groupId***: group ID used for batch data management.

Currently, UDMF provides the public data channel for cross-application data sharing.

The public data channel allows all applications to write data into it. When data is written, a unique identifier is generated, which can be used to update, delete, and query the specified data, or perform a full query. To read all data in the public data channel, set **Intention** to **DATA_HUB**. The public data channel is used only to transmit process data between applications and cannot be used to transmit permission-controlled data, such as files in sandbox directories. UDMF manages the data lifecycle in a unified manner and deletes the data that has been stored for more than one hour every hour.

## Available APIs

For details about the APIs, see [UDMF](../reference/apis-arkdata/capi-udmf-h.md).

| API                                                                                   | Description                                         |
|-----------------------------------------------------------------------------------------|---------------------------------------------|
| OH_UdsHyperlink* OH_UdsHyperlink_Create()                                           | Creates a pointer to an **OH_UdsHyperlink** instance.|
| int OH_UdsHyperlink_SetDescription(OH_UdsHyperlink* pThis, const char* description) | Sets the description parameter in an **OH_UdsHyperlink** instance.|
| OH_UdmfRecord* OH_UdmfRecord_Create()                        | Creates a pointer to an **OH_UdmfRecord** instance.              |
| int OH_UdmfRecord_AddHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink) | Adds hyperlink data to an **OH_UdmfRecord** instance.            |
| OH_UdmfData* OH_UdmfData_Create()                            | Creates a pointer to an **OH_UdmfData** instance.                |
| int OH_UdmfData_AddRecord(OH_UdmfData* pThis, OH_UdmfRecord* record) | Adds an **OH_UdmfRecord** to an **OH_UdmfData** instance.     |
| int OH_Udmf_SetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData *unifiedData, char *key, unsigned int keyLen)        | Sets an **OH_UdmfData** instance in the UDMF database.                         |
| void OH_UdsHyperlink_Destroy(OH_UdsHyperlink* pThis)         | Destroys the pointer to an **OH_UdsHyperlink** instance.|
| void OH_UdmfRecord_Destroy(OH_UdmfRecord* pThis)             | Destroys the pointer to an **OH_UdmfRecord** instance.                  |
| void OH_UdmfData_Destroy(OH_UdmfData* pThis)                 | Destroys the pointer to an **OH_UdmfData** instance.                    |
| char** OH_UdmfRecord_GetTypes(OH_UdmfRecord* pThis, unsigned int* count) | Obtains all data types from an **OH_UdmfRecord** instance.                    |
| int OH_UdmfRecord_GetHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink) | Obtains the hyperlink data from an **OH_UdmfRecord** instance.            |
| int OH_Udmf_GetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize) | Obtains an **OH_UdmfData** instance from the UDMF database based on the data channel type.         |
| int OH_Udmf_UpdateUnifiedData(OH_UdmfOptions* options, OH_UdmfData* unifiedData) | Updates an **OH_UdmfData** instance in the UDMF database.|
| int OH_Udmf_DeleteUnifiedData(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize) | Deletes an **OH_UdmfData** instance from the UDMF database.|
| bool OH_UdmfData_HasType(OH_UdmfData* pThis, const char* type) | Checks whether the specified type exists in an **OH_UdmfData** instance.              |
| OH_UdmfRecord** OH_UdmfData_GetRecords(OH_UdmfData* pThis, unsigned int* count) | Obtains all data records from an **OH_UdmfData** instance.                          |
| OH_UdmfRecordProvider* OH_UdmfRecordProvider_Create()        | Creates a pointer to the **OH_UdmfRecordProvider** instance.                         |
| int OH_UdmfRecordProvider_SetData(OH_UdmfRecordProvider* provider, void* context, const OH_UdmfRecordProvider_GetData callback, const UdmfData_Finalize finalize) | Sets a callback for the **OH_UdmfRecordProvider**.                             |
| int OH_UdmfRecord_SetProvider(OH_UdmfRecord* pThis, const char* const* types, unsigned int count, OH_UdmfRecordProvider* provider) | Sets **OH_UdmfRecordProvider** in an **OH_UdmfRecord** instance.   |
| OH_UdmfOptions* OH_UdmfOptions_Create()        | Creates a pointer to an **OH_UdmfOptions** instance.                         |
| void OH_UdmfOptions_Destroy(OH_UdmfOptions* pThis)  | Destroys the pointer to an **OH_UdmfOptions** instance.                         |


## Adding Dynamic Link Libraries

Add the following libraries to **CMakeLists.txt**.

```txt
libudmf.so, libhilog_ndk.z.so
```

## Including Header Files

```c
#include <cstdio>
#include <cstring>
#include <database/udmf/utd.h>
#include <database/udmf/uds.h>
#include <database/udmf/udmf.h>
#include <database/udmf/udmf_meta.h>
#include <database/udmf/udmf_err_code.h>
#include <hilog/log.h>

#undef LOG_TAG
#define LOG_TAG "MY_LOG"
```

## Writing UDS Data Using UDMF

To write the **OH_UdsHyperlink** data, perform the following steps:
1. Create a UDS data structure for hyperlink.
2. Set the URL and description for the hyperlink.
3. Create an **OH_UdmfRecord** object and add the hyperlink data to it.
4. Create an **OH_UdmfData** object and add **OH_UdmfRecord** to it.
5. Construct an **OH_UdmfOptions**.
6. Construct and write data to the database. The key of the data is returned.
7. Destroy all the pointers created.

```c
void createDataTest()
{
    // 1. Create a UDS data structure for hyperlink.
    OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
    // 2. Set the URL and description for the hyperlink.
    if (OH_UdsHyperlink_SetUrl(hyperlink, "www.demo.com") != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Hyperlink set url error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        return;
    }
    if (OH_UdsHyperlink_SetDescription(hyperlink, "This is the description.") != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Hyperlink set description error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        return;
    }
    // 3. Create an OH_UdmfRecord object and add the hyperlink data to it.
    OH_UdmfRecord* record = OH_UdmfRecord_Create();
    if (OH_UdmfRecord_AddHyperlink(record, hyperlink) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Add hyperlink to record error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        OH_UdmfRecord_Destroy(record);
        return;
    }
    // 4. Create an OH_UdmfData object and add OH_UdmfRecord to it.
    OH_UdmfData* data = OH_UdmfData_Create();
    if (OH_UdmfData_AddRecord(data, record) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Add record to data error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        OH_UdmfRecord_Destroy(record);
        OH_UdmfData_Destroy(data);
        return;
    }
    // 5. Construct an OH_UdmfOptions.
    OH_UdmfOptions* options = OH_UdmfOptions_Create();
    if (OH_UdmfOptions_SetIntention(options, Udmf_Intention::UDMF_INTENTION_DATA_HUB) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Set option error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        OH_UdmfRecord_Destroy(record);
        OH_UdmfData_Destroy(data);
        OH_UdmfOptions_Destroy(options);
        return;
    }
    // 6. Construct and write data to the database. The key of the data is returned.
    char key[UDMF_KEY_BUFFER_LEN] = {0};
    if (OH_Udmf_SetUnifiedDataByOptions(options, data, key, sizeof(key)) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Set data error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        OH_UdmfRecord_Destroy(record);
        OH_UdmfData_Destroy(data);
        OH_UdmfOptions_Destroy(options);
        return;
    }
    OH_LOG_INFO(LOG_APP, "key = %{public}s", key);
    // 7. Destroy all the pointers created.
    OH_UdsHyperlink_Destroy(hyperlink);
    OH_UdmfRecord_Destroy(record);
    OH_UdmfData_Destroy(data);
    OH_UdmfOptions_Destroy(options);
}
```

## Obtaining UDS Data Using UDMF

To obtain the **OH_UdsHyperlink** data, perform the following steps:
1. Construct an **OH_UdmfOptions**.
2. Obtain data through **OH_UdmfOptions**.
3. Check whether **OH_UdmfData** has the required data type.
4. Obtain data records and hyperlink data.
5. Destroy all the pointers created.

```c
void getDataTest()
{
    // 1. Construct an OH_UdmfOptions.
    OH_UdmfOptions* options = OH_UdmfOptions_Create();
    if (OH_UdmfOptions_SetIntention(options, Udmf_Intention::UDMF_INTENTION_DATA_HUB) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Set option error!");
        OH_UdmfOptions_Destroy(options);
        return;
    }
    // 2. Obtain data through OH_UdmfOptions.
    unsigned int dataSize = 0;
    OH_UdmfData* readData = nullptr;
    if (OH_Udmf_GetUnifiedDataByOptions(options, &readData, &dataSize) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Get Data error!");
        OH_UdmfOptions_Destroy(options);
        return;
    }
    OH_UdmfOptions_Destroy(options);
    OH_LOG_INFO(LOG_APP, "the size of data is %{public}u", dataSize);
    OH_UdmfData** dataArray = &readData;
    for (unsigned int i = 0; i < dataSize; i++) {
        OH_UdmfData* data = dataArray[i];
        // 3. Check whether OH_UdmfData has the required data type.
        if (!OH_UdmfData_HasType(data, UDMF_META_HYPERLINK)) {
            OH_LOG_INFO(LOG_APP, "There is no hyperlink type in data[%{public}u].", i);
            continue;
        }
        // 4. Obtain data records and hyperlink data.
        unsigned int recordsCount = 0;
        OH_UdmfRecord** records = OH_UdmfData_GetRecords(data, &recordsCount);
        OH_LOG_INFO(LOG_APP, "the count of records count is %{public}u", recordsCount);    // 5. Obtain elements from records.
        for (unsigned int j = 0; j < recordsCount; j++) {
            // Obtain the OH_UdmfRecord type list.
            unsigned int recordTypeIdCount = 0;
            char** typeIdsFromRecord = OH_UdmfRecord_GetTypes(records[i], &recordTypeIdCount);
            for (unsigned int k = 0; k < recordTypeIdCount; k++) {
                // Obtain the hyperlink data from OH_UdmfRecord.
                if (strcmp(typeIdsFromRecord[k], UDMF_META_HYPERLINK) == 0) {
                    // Create a UDS to hold the hyperlink data read from the unified record.
                    OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
                    if (OH_UdmfRecord_GetHyperlink(records[j], hyperlink) != Udmf_ErrCode::UDMF_E_OK) {
                        OH_LOG_ERROR(LOG_APP,"Fail get hyperlink from record!");
                        OH_UdsHyperlink_Destroy(hyperlink);
                        break;
                    }
                    // Read information in OH_UdsHyperlink.
                    OH_LOG_INFO(LOG_APP, "The hyperlink type id is : %{public}s", OH_UdsHyperlink_GetType(hyperlink));
                    OH_LOG_INFO(LOG_APP, "The hyperlink url is : %{public}s", OH_UdsHyperlink_GetUrl(hyperlink));
                    OH_LOG_INFO(LOG_APP, "The hyperlink description is : %{public}s", OH_UdsHyperlink_GetDescription(hyperlink));
                    OH_UdsHyperlink_Destroy(hyperlink);
                }
            }
        }
    }
    // 5. Destroy all the pointers created.
    OH_Udmf_DestroyDataArray(dataArray, dataSize);
}
```

## Updating UDS Data Using UDMF

To update the **OH_UdsHyperlink** data, perform the following steps:
1. Create a UDS data structure for hyperlink.
2. Set the URL and description for the hyperlink.
3. Create an **OH_UdmfRecord** object and add the hyperlink data to it.
4. Create an **OH_UdmfData** object and add **OH_UdmfRecord** to it.
5. Construct an **OH_UdmfOptions**.
6. Update data and write the data to the database.
7. Destroy all the pointers created.

```c
void updateDataTest()
{
    // 1. Create a UDS data structure for hyperlink.
    OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
    // 2. Set the URL and description for the hyperlink.
    if (OH_UdsHyperlink_SetUrl(hyperlink, "www.demo2.com") != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Hyperlink set url error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        return;
    }
    if (OH_UdsHyperlink_SetDescription(hyperlink, "This is the new description.") != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Hyperlink set description error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        return;
    }
    // 3. Create an OH_UdmfRecord object and add the hyperlink data to it.
    OH_UdmfRecord* record = OH_UdmfRecord_Create();
    if (OH_UdmfRecord_AddHyperlink(record, hyperlink) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Add hyperlink to record error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        OH_UdmfRecord_Destroy(record);
        return;
    }
    // 4. Create an OH_UdmfData object and add OH_UdmfRecord to it.
    OH_UdmfData* data = OH_UdmfData_Create();
    if (OH_UdmfData_AddRecord(data, record) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Add record to data error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        OH_UdmfRecord_Destroy(record);
        OH_UdmfData_Destroy(data);
        return;
    }
    // 5. Construct an OH_UdmfOptions.
    OH_UdmfOptions* options = OH_UdmfOptions_Create();
    // The key here is an example and cannot be directly used. The key must be the same as that returned by OH_Udmf_SetUnifiedDataByOptions.
    char key[] = "udmf://DataHub/com.ohos.test/0123456789";
    if (OH_UdmfOptions_SetIntention(options, Udmf_Intention::UDMF_INTENTION_DATA_HUB) != Udmf_ErrCode::UDMF_E_OK
        || OH_UdmfOptions_SetKey(options, key) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Set option error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        OH_UdmfRecord_Destroy(record);
        OH_UdmfData_Destroy(data);
        OH_UdmfOptions_Destroy(options);
        return;
    }
    // 6. Update data and write the data to the database.
    if (OH_Udmf_UpdateUnifiedData(options, data) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Update data error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        OH_UdmfRecord_Destroy(record);
        OH_UdmfData_Destroy(data);
        OH_UdmfOptions_Destroy(options);
        return;
    }
    OH_LOG_INFO(LOG_APP, "update data success");
    // 7. Destroy all the pointers created.
    OH_UdsHyperlink_Destroy(hyperlink);
    OH_UdmfRecord_Destroy(record);
    OH_UdmfData_Destroy(data);
    OH_UdmfOptions_Destroy(options);
}
```

## Deleting UDS Data Using UDMF

To delete the **OH_UdsHyperlink** data, perform the following steps:
1. Construct an **OH_UdmfOptions**.
2. Delete data through **OH_UdmfOptions**.
3. Check whether **OH_UdmfData** has the required data type.
4. Obtain data records and hyperlink data.
5. Obtain elements in data records.
6. Destroy all the pointers created.

```c
void deleteDataTest()
{
    // 1. Construct an OH_UdmfOptions.
    OH_UdmfOptions* options = OH_UdmfOptions_Create();
    if (OH_UdmfOptions_SetIntention(options, Udmf_Intention::UDMF_INTENTION_DATA_HUB) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Set option error!");
        OH_UdmfOptions_Destroy(options);
        return;
    }
    // 2. Delete data through OH_UdmfOptions.
    unsigned int dataSize = 0;
    OH_UdmfData* readData = nullptr;
    if (OH_Udmf_DeleteUnifiedData(options, &readData, &dataSize) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Delete Data error!");
        OH_UdmfOptions_Destroy(options);
        return;
    }
    OH_UdmfOptions_Destroy(options);
    OH_LOG_INFO(LOG_APP, "the size of data is %{public}u", dataSize);
    OH_UdmfData** dataArray = &readData;
    for (unsigned int i = 0; i < dataSize - 1; i++) {
        OH_UdmfData* data = dataArray[i];
        // 3. Check whether OH_UdmfData has the required data type.
        if (!OH_UdmfData_HasType(data, UDMF_META_HYPERLINK)) {
            OH_LOG_INFO(LOG_APP, "There is no hyperlink type in data[%{public}u].", i);
            continue;
        }
        // 4. Obtain data records and hyperlink data.
        unsigned int recordsCount = 0;
        OH_UdmfRecord** records = OH_UdmfData_GetRecords(data, &recordsCount);
        OH_LOG_INFO(LOG_APP, "the count of records count is %{public}u", recordsCount);    
        // 5. Obtain elements in data records.
        for (unsigned int j = 0; j < recordsCount; j++) {
            // Obtain the OH_UdmfRecord type list.
            unsigned int recordTypeIdCount = 0;
            char** typeIdsFromRecord = OH_UdmfRecord_GetTypes(records[i], &recordTypeIdCount);
            for (unsigned int k = 0; k < recordTypeIdCount; k++) {
                // Obtain the hyperlink data from OH_UdmfRecord.
                if (strcmp(typeIdsFromRecord[k], UDMF_META_HYPERLINK) == 0) {
                    // Create a UDS to hold the hyperlink data read from the unified record.
                    OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
                    if (OH_UdmfRecord_GetHyperlink(records[j], hyperlink) != Udmf_ErrCode::UDMF_E_OK) {
                        OH_LOG_ERROR(LOG_APP,"Fail get hyperlink from record!");
                        OH_UdsHyperlink_Destroy(hyperlink);
                        break;
                    }
                    // Read information in OH_UdsHyperlink.
                    OH_LOG_INFO(LOG_APP, "The hyperlink type id is : %{public}s", OH_UdsHyperlink_GetType(hyperlink));
                    OH_LOG_INFO(LOG_APP, "The hyperlink url is : %{public}s", OH_UdsHyperlink_GetUrl(hyperlink));
                    OH_LOG_INFO(LOG_APP, "The hyperlink description is : %{public}s", OH_UdsHyperlink_GetDescription(hyperlink));
                    OH_UdsHyperlink_Destroy(hyperlink);
                }
            }
        }
    }
    // 6. Destroy all the pointers created.
    OH_Udmf_DestroyDataArray(dataArray, dataSize);
}
```

## Writing UDS Data in Delayed Mode Using UDMF

### Defining a Function for Providing UDS Data

The following uses hyperlink data as an example to describe how to define a callback function that provides UDS data.
1. Define a data providing function for **OH_UdmfRecordProvider**.
2. Create a UDS of the hyperlink type in the data providing function.
3. Set the URL and description for the hyperlink.
4. Define a callback to be invoked when **OH_UdmfRecordProvider** is destroyed.

```c
// For better code readability, the operation result verification of each step is omitted in the following code. In actual development, you need to check whether each call is successful.
// 1. Define a callback to be invoked to return the UDS data obtained.
static void* GetDataCallback(void* context, const char* type) {
    if (strcmp(type, UDMF_META_HYPERLINK) == 0) {
        // 2. Create a UDS for hyperlink data.
        OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
        // 3. Set the URL and description for the hyperlink.
        OH_UdsHyperlink_SetUrl(hyperlink, "www.demo.com");
        OH_UdsHyperlink_SetDescription(hyperlink, "This is the description.");
        return hyperlink;
    }
    return nullptr;
}
// 4. Define a callback to be invoked when OH_UdmfRecordProvider is destroyed.
static void ProviderFinalizeCallback(void* context) { OH_LOG_INFO(LOG_APP, "OH_UdmfRecordProvider finalize."); }
```

### Writing UDS Data in Delayed Mode

The following uses hyperlink data as an example to describe how to use OH_UdmfRecordProvider and UDMF to write data in delayed mode. The hyperlink data is not written to the database until the **GetDataCallback** function is triggered when the data consumer obtains **OH_UdsHyperlink** from **OH_UdmfRecord**.

1. Create an **OH_UdmfRecordProvider** instance and set a data providing function for it and a callback to be invoked when this instance is destroyed.
2. Create an **OH_UdmfRecord** object and configure **OH_UdmfRecordProvider** in it.
3. Create an **OH_UdmfData** object and add **OH_UdmfRecord** to it.
4. Construct and write data to the database. The key of the data is returned.
5. Destroy all the pointers created.

```c
void providerSetDataTest()
{
    // For better code readability, the operation result verification of each step is omitted in the following code. In actual development, you need to check whether each call is successful.
    // 1. Create an OH_UdmfRecordProvider instance and set a data providing function for it and a callback to be invoked when this instance is destroyed.
    OH_UdmfRecordProvider* provider = OH_UdmfRecordProvider_Create();
    OH_UdmfRecordProvider_SetData(provider, (void* )provider, GetDataCallback, ProviderFinalizeCallback);

    // 2. Create an OH_UdmfRecord object and configure OH_UdmfRecordProvider in it.
    OH_UdmfRecord* record = OH_UdmfRecord_Create();
    const char* types[1] = {UDMF_META_HYPERLINK};
    OH_UdmfRecord_SetProvider(record, types, 1, provider);

    // 3. Create an OH_UdmfData object and add OH_UdmfRecord to it.
    OH_UdmfData* data = OH_UdmfData_Create();
    OH_UdmfData_AddRecord(data, record);

    // 4. Construct and write data to the database. The key of the data is returned.
    OH_UdmfOptions* options = OH_UdmfOptions_Create();
    if (OH_UdmfOptions_SetIntention(options, Udmf_Intention::UDMF_INTENTION_DATA_HUB) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Set option error!");
        OH_UdmfOptions_Destroy(options);
        return;
    }
    char key[UDMF_KEY_BUFFER_LEN] = {0};
    if (OH_Udmf_SetUnifiedDataByOptions(options, data, key, sizeof(key)) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Set data error!");
    }
    OH_LOG_INFO(LOG_APP, "key = %{public}s", key);

    // 5. Destroy all the pointers created.
    OH_UdmfRecord_Destroy(record);
    OH_UdmfData_Destroy(data);
    OH_UdmfOptions_Destroy(options);
}
```

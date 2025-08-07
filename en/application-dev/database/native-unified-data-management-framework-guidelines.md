# UDMF Development (C/C++)


## Introduction

The Unified Data Management Framework (UDMF) defines the language and data standards for cross-application and cross-device data interaction, improving data interaction efficiency. It also provides secure and standard data transmission channels and supports different levels of data access permissions and lifecycle management policies. It helps implement efficient data sharing across applications and devices.


## Basic Concepts

- UTD<br>A Uniform Type Descriptor (UTD) defines data of the same type to eliminate data type ambiguity. It contains the data type ID and types to which the current data type belongs. The UTD is generally used to filter or identify the data type in scenarios, such as file preview and file sharing.

- UDS<br> A uniform data struct (UDS) defines the data of a certain type (specified by a UTD). Uniform data structs allow unified parsing standards to be used in data interaction, which minimizes the adaptation workload. Uniform data structs are used for data interaction across applications and devices, such as, the drag-and-drop operations.

- Unified record<br>A unified record is abstract definition of a piece of data supported by the UDMF, for example, a text record or an image record.

- Unified data<br>A unified data object encapsulates multiple unified records.

- Unified data provider<br>The unified data provider is configured in a unified record to provide UDS data. It is usually used in delayed data transmission, in which the UDS data is transferred only when the data consumer obtains data from the unified data record.


## Constraints

- The UDMF supports management of batch data records. Each unified data object cannot exceed 200 MB. The maximum size of a single property in **PlainText**, **Hyperlink**, or **HTML** is 20 MB.
- The size of customized data to be added to a unified record cannot exceed 100 MB.
- When data is written to the UDMF database, the memory size of the unique identifier (key) must be greater than or equal to 512 bytes.

## Available APIs

For details about the APIs, see [UDMF](../reference/apis-arkdata/capi-udmf.md).

| API                                                    | Description                                                       |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| OH_Utd* OH_Utd_Create(const char* typeId)                    | Creates a pointer to an **OH_Utd** instance.               |
| void OH_Utd_Destroy(OH_Utd* pThis)                           | Destroys the pointer to an **OH_Utd** instance.                   |
| const char** OH_Utd_GetTypesByFilenameExtension(const char* extension, unsigned int* count) | Obtains the uniform data types by file name extension.                       |
| const char** OH_Utd_GetTypesByMimeType(const char* mimeType, unsigned int* count) | Obtains the uniform data types by MIME type.                         |
| bool OH_Utd_Equals(OH_Utd* utd1, OH_Utd* utd2)               | Checks whether two UTDs are the same.                           |
| void OH_Utd_DestroyStringList(const char** list, unsigned int count) | Destroys a UTD list.                                       |
| OH_UdsHyperlink* OH_UdsHyperlink_Create()                    | Creates a pointer to an **OH_UdsHyperlink** instance.|
| void OH_UdsHyperlink_Destroy(OH_UdsHyperlink* pThis)         | Destroys the pointer to an **OH_UdsHyperlink** instance.    |
| const char* OH_UdsHyperlink_GetType(OH_UdsHyperlink* pThis)  | Obtains the UTD ID from an **OH_UdsHyperlink** instance.                  |
| const char* OH_UdsHyperlink_GetUrl(OH_UdsHyperlink* pThis)   | Obtains the URL from an **OH_UdsHyperlink** instance.                           |
| const char* OH_UdsHyperlink_GetDescription(OH_UdsHyperlink* pThis) | Obtains the link description from an **OH_UdsHyperlink** instance.                      |
| int OH_UdsHyperlink_SetUrl(OH_UdsHyperlink* pThis, const char* url) | Sets the URL for an **OH_UdsHyperlink** instance.                           |
| int OH_UdsHyperlink_SetDescription(OH_UdsHyperlink* pThis, const char* description) | Sets the link description for an **OH_UdsHyperlink** instance.                      |
| OH_UdmfData* OH_UdmfData_Create()                            | Creates a pointer to an **OH_UdmfData** instance.                |
| void OH_UdmfData_Destroy(OH_UdmfData* pThis)                 | Destroys the pointer to an **OH_UdmfData** instance.                    |
| int OH_UdmfData_AddRecord(OH_UdmfData* pThis, OH_UdmfRecord* record) | Add an **OH_UdmfRecord** to an **OH_UdmfData** instance.             |
| bool OH_UdmfData_HasType(OH_UdmfData* pThis, const char* type) | Checks whether the specified type exists in an **OH_UdmfData** instance.              |
| OH_UdmfRecord** OH_UdmfData_GetRecords(OH_UdmfData* pThis, unsigned int* count) | Obtains all data records from an **OH_UdmfData** instance.                          |
| OH_UdmfRecord* OH_UdmfRecord_Create()                        | Creates a pointer to an **OH_UdmfRecord** instance.              |
| void OH_UdmfRecord_Destroy(OH_UdmfRecord* pThis)             | Destroys the pointer to an **OH_UdmfRecord** instance.                  |
| int OH_UdmfRecord_AddHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink) | Adds hyperlink data to an **OH_UdmfRecord** instance.                        |
| char** OH_UdmfRecord_GetTypes(OH_UdmfRecord* pThis, unsigned int* count) | Obtains all data types in an **OH_UdmfRecord** instance.                        |
| int OH_UdmfRecord_GetHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink) | Obtains the hyperlink data from an **OH_UdmfRecord** instance.                        |
| int OH_Udmf_GetUnifiedData(const char* key, Udmf_Intention intention, OH_UdmfData* unifiedData) | Obtains data from the UDMF database.                                   |
| int OH_Udmf_SetUnifiedData(Udmf_Intention intention, OH_UdmfData* unifiedData, char* key, unsigned int keyLen) | Sets data in the UDMF database.                                   |
| OH_UdmfRecordProvider* OH_UdmfRecordProvider_Create()        | Creates a pointer to the unified data provider instance.                         |
| int OH_UdmfRecordProvider_SetData(OH_UdmfRecordProvider* provider, void* context, const OH_UdmfRecordProvider_GetData callback, const UdmfData_Finalize finalize) | Sets a callback for the unified data provider.                             |
| int OH_UdmfRecord_SetProvider(OH_UdmfRecord* pThis, const char* const* types, unsigned int count, OH_UdmfRecordProvider* provider) | Sets the unified data provider in an **OH_UdmfRecord** instance.                    |


## Adding Dynamic Link Libraries

Add the following library to **CMakeLists.txt**.

```txt
libudmf.so
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
```
## Obtaining Plaintext Data in Different Ways

The following walks you through on how to use the UTD to obtain plaintext data.
1. Obtain **typeId** of the UTD based on the file name extension **.txt**.
2. Obtain **typeId** of the UTD based on the MIME type **text/plain**.
3. Use the **typeId**s obtained to create two UTD instances.
4. Check whether the two UTD instances are the same.
5. Destroy the pointers created.

```c
// 1. Obtain typeId of the UTD based on the file name extension .txt.
unsigned int typeIds1Count = 0;
const char** typeIds1 = OH_Utd_GetTypesByFilenameExtension(".txt", &typeIds1Count);
printf("the count of typeIds1 is %u", typeIds1Count);
// 2. Obtain typeId based on the MIME type.
unsigned int typeIds2Count = 0;
const char** typeIds2 = OH_Utd_GetTypesByMimeType("text/plain", &typeIds2Count);
printf("the count of typeIds2 is %u", typeIds2Count);
// 3. Use the typeIds obtained to create two UTD instances.
OH_Utd* utd1 = OH_Utd_Create(typeIds1[0]);
OH_Utd* utd2 = OH_Utd_Create(typeIds2[0]);
// 4. Check whether the two UTD instances are the same.
bool isEquals = OH_Utd_Equals(utd1, utd2);
if (isEquals) {
    printf("utd1 == utd2");
} else {
    printf("utd1 != utd2");
}
// 5. Destroy the pointers obtained by OH_Utd_GetTypesByFilenameExtension and OH_Utd_GetFilenameExtensions and the UTD pointers.
OH_Utd_DestroyStringList(typeIds1, typeIds1Count);
OH_Utd_DestroyStringList(typeIds2, typeIds2Count);
OH_Utd_Destroy(utd1);
OH_Utd_Destroy(utd2);
```

## Sending UDS Data

To send hyperlink data, perform the following steps:
1. Create a UDS for hyperlink data.
2. Set the URL and description for the hyperlink.
3. Write the hyperlink data into an **OH_UdmfRecord** instance.
4. Add the **OH_UdmfRecord** instance to an **OH_UdmfData** instance.
5. Save the data to the database. The key of the data saved to the database is returned.
6. Destroy the pointers created.

```c
// 1. Create a UDS for hyperlink data.
OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
// 2. Set the URL and description for the hyperlink.
if (OH_UdsHyperlink_SetUrl(hyperlink, "www.demo.com") != Udmf_ErrCode::UDMF_E_OK) {
    printf("Hyperlink set url error!");
}
if (OH_UdsHyperlink_SetDescription(hyperlink, "This is the description.") != Udmf_ErrCode::UDMF_E_OK) {
    printf("Hyperlink set description error!");
}
// 3. Create an OH_UdmfRecord object and add the hyperlink type data to the OH_UdmfRecord object.
OH_UdmfRecord* record = OH_UdmfRecord_Create();
if (OH_UdmfRecord_AddHyperlink(record, hyperlink) != Udmf_ErrCode::UDMF_E_OK) {
    printf("Add hyperlink to record error!");
}
// 4. Create an OH_UdmfData object and add OH_UdmfRecord to it.
OH_UdmfData* data = OH_UdmfData_Create();
if (OH_UdmfData_AddRecord(data, record) != Udmf_ErrCode::UDMF_E_OK) {
    printf("Add record to data error!");
}
// 5. Construct and write data to the database. The key of the data is returned.
char key[UDMF_KEY_BUFFER_LEN] = {0};
if (OH_Udmf_SetUnifiedData(Udmf_Intention::UDMF_INTENTION_DRAG, data, key, sizeof(key)) != Udmf_ErrCode::UDMF_E_OK) {
    printf("Set data error!");
}
printf("key = %s", key);
// 6. Destroy all the pointers created.
OH_UdsHyperlink_Destroy(hyperlink);
OH_UdmfRecord_Destroy(record);
OH_UdmfData_Destroy(data);
```

## Obtaining UDS Data

To obtain the UDS from a hyperlink instance, perform the following steps:
1. Create an **OH_UdmfData** instance to hold the data read from the database.
2. Obtain data from the database based on the key.
3. Check whether data of the hyperlink type exists.
4. Obtain a record from **OH_UdmfData**, and then obtain hyperlink data from the data record.
5. Obtain information in the hyperlink data.
6. Destroy the pointers created.

```c
// 1. Create an OH_UdmfData instance.
OH_UdmfData* readData = OH_UdmfData_Create();
// The key here is an example and cannot be directly used. The key must be the same as that returned by OH_Udmf_SetUnifiedData.
char key[] = {"udmf://Drag/com.ohos.test/0123456789"};
// 2. Obtain data from the database based on the key.
if (OH_Udmf_GetUnifiedData(key, Udmf_Intention::UDMF_INTENTION_DRAG, readData) != Udmf_ErrCode::UDMF_E_OK) {
    printf("Failed to get data.");
    return;
}
// 3. Check whether OH_UdmfData has hyperlink data.
if (!OH_UdmfData_HasType(readData, UDMF_META_HYPERLINK)) {
    printf("There is no hyperlink type in data.");
    return;
}
// 4. Obtain the data record and hyperlink data.
unsigned int recordsCount = 0;
OH_UdmfRecord** records = OH_UdmfData_GetRecords(readData, &recordsCount);
printf("the count of records count is %u", recordsCount);
// Create a UDS to hold the hyperlink data read from the unified record.
OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
// Obtain elements in records.
for (int i = 0; i < recordsCount; i++) {
    // Obtain the OH_UdmfRecord type list.
    unsigned int recordTypeIdCount = 0;
    char** typeIdsFromRecord = OH_UdmfRecord_GetTypes(records[i], &recordTypeIdCount);
    for (unsigned int j = 0; j < recordTypeIdCount; j++) {
        // Obtain the hyperlink type data from OH_UdmfRecord.
        if (strcmp(typeIdsFromRecord[j], UDMF_META_HYPERLINK) == 0) {
            // Obtain the hyperlink data.
            if (OH_UdmfRecord_GetHyperlink(records[i], hyperlink) != Udmf_ErrCode::UDMF_E_OK) {
                printf("Fail get hyperlink from record!");
            }
        }
    }
}
// 5. Read information in OH_UdsHyperlink.
printf("The hyperlink type id is : %s", OH_UdsHyperlink_GetType(hyperlink));
printf("The hyperlink url is : %s", OH_UdsHyperlink_GetUrl(hyperlink));
printf("The hyperlink description is : %s", OH_UdsHyperlink_GetDescription(hyperlink));
// 6. Destroy the pointers.
OH_UdsHyperlink_Destroy(hyperlink);
OH_UdmfData_Destroy(readData);
```

## Delaying UDS Data Sending

### Defining a Function for Providing UDS Data

The following uses hyperlink data as an example to describe how to define a callback function that provides UDS data.
1. Define a data providing function for **OH_UdmfRecordProvider**.
2. Create a UDS of the hyperlink type in the data providing function.
3. Set the URL and description for the hyperlink.
4. Define a callback function for destroying the **OH_UdmfRecordProvider** instance.

```c
// For better code readability, the operation result verification of each step is omitted in the following code. In actual development, you need to check whether each call is successful.
// 1. Define a callback to be invoked to return the UDS data obtained.
static void* GetDataCallback(void* context, const char* type) {
    if (strcmp(type, UDMF_META_PLAIN_TEXT)) {
        // 2. Create a UDS for hyperlink data.
        OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
        // 3. Set the URL and description for the hyperlink.
        OH_UdsHyperlink_SetUrl(hyperlink, "www.demo.com");
        OH_UdsHyperlink_SetDescription(hyperlink, "This is the description.");
        return hyperlink;
    }
    return nullptr;
}
// 4. Define a callback to be triggered when OH_UdmfRecordProvider is destroyed.
static void ProviderFinalizeCallback(void* context) { printf("OH_UdmfRecordProvider finalize."); }
```

### Delaying UDS Data Sending

To delay the sending of the hyperlink data, perform the following steps: The **GetDataCallback** function is triggered to obtain data only when the data consumer obtains **OH_UdsHyperlink** from **OH_UdmfRecord**.

1. Create an **OH_UdmfRecordProvider** instance and set a data providing function and a callback function for destroying it.
2. Create an **OH_UdmfRecord** object and configure **OH_UdmfRecordProvider** in this object.
3. Create an **OH_UdmfData** instance and add **OH_UdmfRecord** to it.
4. Construct and write data to the database. The key of the data is returned.
5. Destroy the pointers created.

```c
// For better code readability, the operation result verification of each step is omitted in the following code. In actual development, you need to check whether each call is successful.
// 1. Create a OH_UdmfRecordProvider instance and configure two callback functions for providing data and destroying the instance.
OH_UdmfRecordProvider* provider = OH_UdmfRecordProvider_Create();
OH_UdmfRecordProvider_SetData(provider, (void* )provider, GetDataCallback, ProviderFinalizeCallback);

// 2. Create an OH_UdmfRecord object and configure OH_UdmfRecordProvider in this object.
OH_UdmfRecord* record = OH_UdmfRecord_Create();
const char* types[1] = {UDMF_META_HYPERLINK};
OH_UdmfRecord_SetProvider(record, types, 1, provider);

// 3. Create an OH_UdmfData object and add OH_UdmfRecord to it.
OH_UdmfData* data = OH_UdmfData_Create();
OH_UdmfData_AddRecord(data, record);

// 4. Construct and write data to the database. The key of the data is returned.
char key[UDMF_KEY_BUFFER_LEN] = {0};
OH_Udmf_SetUnifiedData(Udmf_Intention::UDMF_INTENTION_DRAG, data, key, sizeof(key));
printf("key = %s", key);

// 5. Destroy all the pointers created.
OH_UdmfRecord_Destroy(record);
OH_UdmfData_Destroy(data);
```

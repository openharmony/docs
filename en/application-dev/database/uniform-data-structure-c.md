# Uniform Data Structs (C/C++)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @jcwen-->
<!--Designer: @junathuawei1; @zph000-->
<!--Tester: @lj_liujing; @yippo; @logic42-->
<!--Adviser: @ge-yafang-->


## When to Use

Uniform data structs are provided to define data of common [uniform data types](../reference/apis-arkdata/capi-utd-h.md). For example, the data struct for the system-defined home screen icon (whose uniform data type is **OH_UdsAppItem**) is provided to help you easily define the data.

Applications can directly use the uniform data structs in certain scenarios. For example, in the drag-and-drop operation across applications, you can write the data (encapsulated in a uniform struct) to be dragged to [DragEvent](../ui/ndk-drag-event.md). The target application (application requesting the data) reads the data from **DragEvent** and parses the data in the uniform data struct. Using uniform data structs for data interaction between applications effectively reduces the development workload in your application experience.

## Basic Concepts

- UDS<br> A uniform data struct (UDS) defines the data of a certain type (specified by a UTD). Uniform data structs allow unified parsing standards to be used in data interaction, which minimizes the adaptation workload. Uniform data structs are used for data interaction across applications and devices, such as, the drag-and-drop operations.

## Available APIs

For details about the APIs, see [uds.h](../reference/apis-arkdata/capi-uds-h.md).

| API                                                                                   | Description                                         | 
|-----------------------------------------------------------------------------------------|---------------------------------------------|
| OH_UdmfData* OH_UdmfData_Create()                                                       | Creates an **OH_UdmfData** instance and a pointer to it.|
| OH_UdmfRecord* OH_UdmfRecord_Create()                                                   | Creates an **OH_UdmfRecord** instance and a pointer to it.|
| OH_UdsPlainText* OH_UdsPlainText_Create()                                               | Creates an **OH_UdsPlainText** instance and a pointer to it.|
| int OH_UdmfRecord_GetPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText)        | Obtains **OH_UdsPlainText** data from an **OH_UdmfRecord** instance.    |
| int OH_UdsPlainText_SetContent(OH_UdsPlainText* pThis, const char* content)             | Sets the plaintext content for an **OH_UdsPlainText** instance. |
| int OH_UdmfRecord_AddPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText)        | Adds **OH_UdsPlainText** data to an **OH_UdmfRecord** instance.|
| int OH_UdmfData_AddRecord(OH_UdmfData* pThis, OH_UdmfRecord* record)                    | Adds **OH_UdmfRecord** data to an **OH_UdmfData** instance.  |
| OH_UdsFileUri* OH_UdsFileUri_Create()                                                   | Creates an **OH_UdsFileUri** instance and a pointer to it.|
| int OH_UdsFileUri_SetFileUri(OH_UdsFileUri* pThis, const char* fileUri)                 | Sets the URI information for an **OH_UdsFileUri** instance.|
| int OH_UdsFileUri_SetFileType(OH_UdsFileUri* pThis, const char* fileType)               | Sets the file type for an **OH_UdsFileUri** instance.|
| int OH_UdmfRecord_AddFileUri(OH_UdmfRecord* pThis, OH_UdsFileUri* fileUri)              | Adds **OH_UdsFileUri** data to an **OH_UdmfData** instance.|
| int OH_Udmf_SetUnifiedData(Udmf_Intention intention, OH_UdmfData* unifiedData,char* key, unsigned int keyLen) | Sets an **OH_UdmfData** instance in the UDMF database.|
| void OH_UdsPlainText_Destroy(OH_UdsPlainText* pThis)                                    | Destroys an **OH_UdsPlainText** instance.|
| void OH_UdmfData_Destroy(OH_UdmfData* pThis)                                            | Destroys an **OH_UdmfData** instance.|
| void OH_UdsFileUri_Destroy(OH_UdsFileUri* pThis)                                        | Destroys an **OH_UdsFileUri** instance.|

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

## Using the PlainText Data Struct

1. Create a pointer to an **PlainText** object.
2. Set content for the **PlainText** object.
3. Obtain data.
4. Destroy all the pointers created.

```c
// 1. Create a pointer to an PlainText object.
OH_UdmfRecord *plainTextRecord = OH_UdmfRecord_Create();
OH_UdsPlainText *plainText = OH_UdsPlainText_Create();
char content[] = "hello world";

// 2. Set content for the PlainText object.
OH_UdsPlainText_SetContent(plainText, content);
OH_UdmfRecord_AddPlainText(plainTextRecord, plainText);

// 3. Obtain PlainText data.
OH_UdsPlainText* plainText2 = OH_UdsPlainText_Create();
OH_UdmfRecord_GetPlainText(plainTextRecord, plainText2);
const char* content2 = OH_UdsPlainText_GetContent(plainText2);

OH_LOG_INFO(LOG_APP, "content = %{public}s.", content2);
// 4. Destroy all the pointers created.
OH_UdsPlainText_Destroy(plainText);
OH_UdmfRecord_Destroy(plainTextRecord);
OH_UdsPlainText_Destroy(plainText2);
```

## Using the fileUri Data Struct

1. Create a struct for the **fileUri** data.
2. Set the URL and description for the **fileUri**.
3. Create an **OH_UdmfRecord** object and set **fileUri** data to it.
4. Obtain the **fileUri** data.
5. Destroy all the pointers created.

```c
// 1. Create a struct for the fileUri data.
const char* uri = "https://xxx/xx/xx.jpg";
OH_UdsFileUri* fileUri = OH_UdsFileUri_Create();
// 2. Set the URL and description for the fileUri.
OH_UdsFileUri_SetFileUri(fileUri, uri);
OH_UdsFileUri_SetFileType(fileUri, UDMF_META_IMAGE);
// 3. Create an OH_UdmfRecord object and set fileUri data to it.
OH_UdmfRecord* record = OH_UdmfRecord_Create();
OH_UdmfRecord_AddFileUri(record, fileUri);
// 4. Obtain the fileUri data.
OH_UdsFileUri* fileUri1 = OH_UdsFileUri_Create();
OH_UdmfRecord_GetFileUri(record, fileUri1);
const char* fileUriStr = OH_UdsFileUri_GetFileUri(fileUri1);
OH_LOG_INFO(LOG_APP, "fileUri1 = %{public}s.", fileUriStr);
// 5. Destroy all the pointers created.
OH_UdsFileUri_Destroy(fileUri);
OH_UdmfRecord_Destroy(record);
OH_UdsFileUri_Destroy(fileUri1);
```

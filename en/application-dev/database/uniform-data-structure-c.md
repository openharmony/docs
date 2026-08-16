# Uniform Data Structs (C/C++)

<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @jcwen-->
<!--Designer: @junathuawei1; @zph000-->
<!--Tester: @lj_liujing; @yippo; @logic42-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=814e5538573180f4836543a1c6592fa1ff24a7c3 translatedAt=2026-08-15T01:43:23.525Z pushedAt=2026-08-15T06:29:40.661Z -->

## When to Use

Standardized data structures are provided for some common UTD standardized data types defined in [utd.h](../reference/apis-arkdata/capi-utd-h.md) to facilitate business use. For example, the system-defined home screen icon type (whose standardized data type identifier is `OH_UdsAppItem`) clearly defines the related description information.

In some scenarios, applications can directly use the standardized UTD data structs that we define, such as for cross-application drag-and-drop. The source application writes drag data to the [drag event](../ui/ndk-drag-event.md) by using the standardized data structs. The destination application reads the drag data from the drag event and parses it by using the same standardized data structs. This enables data exchange between applications to follow a common standard, significantly reducing the development effort required for cross-application data exchange.

## Basic Concepts

- UDS<br>A uniform data struct (UDS) defines the data of a certain type (specified by a UTD). Uniform data structs allow unified parsing standards to be used in data interaction, which minimizes the adaptation workload. Uniform data structs are used for data interaction across applications and devices, such as, the drag-and-drop operations.

## Available APIs

For details about the APIs, see the standardized data structure APIs defined in [uds.h](../reference/apis-arkdata/capi-uds-h.md).

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
| int OH_Udmf_SetUnifiedData(Udmf_Intention intention, OH_UdmfData* unifiedData,char* key, unsigned int keyLen) | Sets an **OH_UdmfData** instance in the UDMF database. |
| void OH_UdsPlainText_Destroy(OH_UdsPlainText* pThis)                                    | Destroys an **OH_UdsPlainText** instance.|
| void OH_UdmfData_Destroy(OH_UdmfData* pThis)                                            | Destroys an **OH_UdmfData** instance.|
| void OH_UdsFileUri_Destroy(OH_UdsFileUri* pThis)                                        | Destroys an **OH_UdsFileUri** instance.|

## Adding Dynamic Link Libraries

Add the following libraries to **CMakeLists.txt**.

```txt
libudmf.so, libhilog_ndk.z.so
```

## Including Header Files

<!-- @[import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Udmf/UniformDataStructure_C/entry/src/main/cpp/napi_init.cpp) -->

``` C++
#include <database/udmf/uds.h>
#include <database/udmf/udmf.h>
#include <database/udmf/udmf_meta.h>
#include <database/udmf/udmf_err_code.h>
#include <hilog/log.h>

#undef LOG_TAG
#define LOG_TAG "MY_LOG"
```

## Using the PlainText Data Struct

1. Create a pointer to a **PlainText** object.

2. Set content for the **PlainText** object.

3. Obtain data.

4. Destroy all the pointers created.

<!-- @[use_plaintext_datastructure](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Udmf/UniformDataStructure_C/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// 1. Create a pointer to an PlainText object.
OH_UdmfRecord *plainTextRecord = OH_UdmfRecord_Create();
if (plainTextRecord == nullptr) {
    return Udmf_ErrCode::UDMF_ERR;
}
OH_UdsPlainText *plainText = OH_UdsPlainText_Create();
if (plainText == nullptr) {
    OH_UdmfRecord_Destroy(plainTextRecord);
    return Udmf_ErrCode::UDMF_ERR;
}
char content[] = "hello world";

// 2. Set content for the PlainText object.
int32_t ret = OH_UdsPlainText_SetContent(plainText, content);
if (ret != Udmf_ErrCode::UDMF_E_OK) {
    OH_LOG_ERROR(LOG_APP, "OH_UdsPlainText_SetContent error!");
    OH_UdsPlainText_Destroy(plainText);
    OH_UdmfRecord_Destroy(plainTextRecord);
    return ret;
}
ret = OH_UdmfRecord_AddPlainText(plainTextRecord, plainText);
if (ret != Udmf_ErrCode::UDMF_E_OK) {
    OH_LOG_ERROR(LOG_APP, "OH_UdmfRecord_AddPlainText error!");
    OH_UdsPlainText_Destroy(plainText);
    OH_UdmfRecord_Destroy(plainTextRecord);
    return ret;
}

// 3. Obtain PlainText data.
OH_UdsPlainText *plainText2 = OH_UdsPlainText_Create();
ret = OH_UdmfRecord_GetPlainText(plainTextRecord, plainText2);
if (ret != Udmf_ErrCode::UDMF_E_OK) {
    OH_LOG_ERROR(LOG_APP, "OH_UdmfRecord_GetPlainText error!");
    OH_UdsPlainText_Destroy(plainText);
    OH_UdmfRecord_Destroy(plainTextRecord);
    OH_UdsPlainText_Destroy(plainText2);
    return ret;
}
const char *content2 = OH_UdsPlainText_GetContent(plainText2);
if (content2 != nullptr) {
    OH_LOG_INFO(LOG_APP, "content = %{public}s.", content2);
}
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

<!-- @[use_fileUri_datastructure](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Udmf/UniformDataStructure_C/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// 1. Create a struct for the fileUri data.
const char *uri = "https://xxx/xx/xx.jpg";
OH_UdsFileUri *fileUri = OH_UdsFileUri_Create();
if (fileUri == nullptr) {
    return Udmf_ErrCode::UDMF_ERR;
}
// 2. Set the URL and description for the fileUri.
int32_t ret = OH_UdsFileUri_SetFileUri(fileUri, uri);
if (ret != Udmf_ErrCode::UDMF_E_OK) {
    OH_UdsFileUri_Destroy(fileUri);
    return ret;
}
ret = OH_UdsFileUri_SetFileType(fileUri, UDMF_META_IMAGE);
if (ret != Udmf_ErrCode::UDMF_E_OK) {
    OH_UdsFileUri_Destroy(fileUri);
    return ret;
}
// 3. Create an OH_UdmfRecord object and set fileUri data to it.
OH_UdmfRecord *record = OH_UdmfRecord_Create();
if (record == nullptr) {
    OH_UdsFileUri_Destroy(fileUri);
    return Udmf_ErrCode::UDMF_ERR;
}
ret = OH_UdmfRecord_AddFileUri(record, fileUri);
if (ret != Udmf_ErrCode::UDMF_E_OK) {
    OH_UdsFileUri_Destroy(fileUri);
    OH_UdmfRecord_Destroy(record);
    return ret;
}
// 4. Obtain the fileUri data.
OH_UdsFileUri *fileUri1 = OH_UdsFileUri_Create();
if (fileUri1 == nullptr) {
    OH_UdsFileUri_Destroy(fileUri);
    OH_UdmfRecord_Destroy(record);
    return Udmf_ErrCode::UDMF_ERR;
}
ret = OH_UdmfRecord_GetFileUri(record, fileUri1);
if (ret != Udmf_ErrCode::UDMF_E_OK) {
    OH_UdsFileUri_Destroy(fileUri);
    OH_UdmfRecord_Destroy(record);
    OH_UdsFileUri_Destroy(fileUri1);
    return ret;
}
const char *fileUriStr = OH_UdsFileUri_GetFileUri(fileUri1);
if (fileUriStr != nullptr) {
    OH_LOG_INFO(LOG_APP, "fileUri1 = %{public}s.", fileUriStr);
}
// 5. Destroy all the pointers created.
OH_UdsFileUri_Destroy(fileUri);
OH_UdmfRecord_Destroy(record);
OH_UdsFileUri_Destroy(fileUri1);
```
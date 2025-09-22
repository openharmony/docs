# UTDs (C/C++)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @jcwen-->
<!--Designer: @junathuawei1; @zph000-->
<!--Tester: @lj_liujing; @yippo; @logic42-->
<!--Adviser: @ge-yafang-->


## When to Use

The Unified Data Management Framework (UDMF) provides standards for data interaction across applications and devices, defines a unified data language, and improves data interaction efficiency. With secure and unified data channels, UDMF supports data access permissions and lifecycle management policies at different levels, achieving efficient data sharing.


## Basic Concepts

- UTD<br> A uniform type descriptor (UTD) defines data of the same type to eliminate data type ambiguity. It contains the data type ID and types to which the current data type belongs. UTDs are generally used to filter or identify the data type in file preview and file sharing.


## Available APIs

For details about the APIs, see [utd.h](../reference/apis-arkdata/capi-utd-h.md).

| API                                                    | Description                                                       |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| OH_Utd* OH_Utd_Create(const char* typeId)                    | Creates a pointer to an **OH_Utd** instance.               |
| void OH_Utd_Destroy(OH_Utd* pThis)                           | Destroys the pointer to an **OH_Utd** instance.                   |
| const char** OH_Utd_GetTypesByFilenameExtension(const char* extension, unsigned int* count) | Obtains the uniform data types by file name extension.                       |
| const char** OH_Utd_GetTypesByMimeType(const char* mimeType, unsigned int* count) | Obtains the uniform data types by MIME type.                         |
| bool OH_Utd_Equals(OH_Utd* utd1, OH_Utd* utd2)               | Checks whether two UTDs are the same.                           |
| void OH_Utd_DestroyStringList(const char** list, unsigned int count) | Destroys a UTD list.                                       |
| bool OH_Utd_BelongsTo (const char *srcTypeId, const char *destTypeId) | Checks whether a UTD belongs to the target UTD.                 |
| bool OH_Utd_IsLower (const char* srcTypeId, const char* destTypeId ) | Checks whether a UTD is a lower-level type of the target UTD. For example, **TYPE_SCRIPT** is a lower-level type of **SOURCE_CODE**, and **TYPE_SCRIPT** and **SOURCE_CODE** are lower-level types of **PLAIN_TEXT**.      |
| bool OH_Utd_IsHigher (const char* srcTypeId, const char* destTypeId ) | Checks whether a UTD is a higher-level type of the target UTD. For example, **SOURCE_CODE** is a higher-level type of **TYPE_SCRIPT**, and **PLAIN_TEXT** is a higher-level type of **SOURCE_CODE** and **TYPE_SCRIPT**.      |


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
## Obtaining Different Types of Data and Comparing Their Relationships

The following walks you through on how to use the UTD to obtain plaintext data.
1. Obtain **typeId** of the UTD based on the file name extension **.txt**.
2. Obtain **typeId** of the UTD based on the MIME type **text/plain**.
3. Use the **typeId**s obtained to create two UTD instances.
4. Check whether the two UTD instances are the same.
5. Check whether a **typeId** belongs to another **typeId**.
6. Check whether **typeIds1[0]** is a lower-level type of **typeIds2[0]**.
7. Check whether **typeIds1[0]** is a higher-level type of **typeIds2[0]**.
8. Destroy the pointers created.

```c
// 1. Obtain typeId of the UTD based on the file name extension .txt.
unsigned int typeIds1Count = 0;
const char** typeIds1 = OH_Utd_GetTypesByFilenameExtension(".txt", &typeIds1Count);
OH_LOG_INFO(LOG_APP, "the count of typeIds1 is %{public}u", typeIds1Count);
// 2. Obtain typeId based on the MIME type.
unsigned int typeIds2Count = 0;
const char** typeIds2 = OH_Utd_GetTypesByMimeType("text/plain", &typeIds2Count);
OH_LOG_INFO(LOG_APP, "the count of typeIds2 is %{public}u", typeIds2Count);
// 3. Use the typeIds obtained to create two UTD instances.
OH_Utd* utd1 = OH_Utd_Create(typeIds1[0]);
OH_Utd* utd2 = OH_Utd_Create(typeIds2[0]);
// 4. Check whether the two UTD instances are the same.
bool isEquals = OH_Utd_Equals(utd1, utd2);
if (isEquals) {
    OH_LOG_INFO(LOG_APP, "utd1 == utd2");
} else {
    OH_LOG_INFO(LOG_APP, "utd1 != utd2");
}
// 5. Check whether a typeId belongs to another typeId.
bool isBelongsTo = OH_Utd_BelongsTo(typeIds1[0], typeIds2[0]);
if (isBelongsTo) {
    OH_LOG_INFO(LOG_APP, "typeIds1[0] Belongs To typeIds2[0]");
} else {
    OH_LOG_INFO(LOG_APP, "typeIds1[0] dont Belongs To typeIds2[0]");
}
// 6. Check whether typeIds1[0] is a lower-level type of typeIds2[0].
bool isLower = OH_Utd_IsLower(typeIds1[0], typeIds2[0]);
if (isLower) {
    OH_LOG_INFO(LOG_APP, "typeIds1[0] is Lower typeIds2[0]");
} else {
    OH_LOG_INFO(LOG_APP, "typeIds1[0] is not Lower typeIds2[0]");
}
// 7. Check whether typeIds1[0] is a higher-level type of typeIds2[0].
bool isHigher = OH_Utd_IsHigher(typeIds1[0], typeIds2[0]);
if (isHigher) {
    OH_LOG_INFO(LOG_APP, "typeIds1[0] is Higher typeIds2[0]");
} else {
    OH_LOG_INFO(LOG_APP, "typeIds1[0]  is not Higher typeIds2[0]");
}
// 8. Destroy the pointers obtained by OH_Utd_GetTypesByFilenameExtension and OH_Utd_GetTypesByMimeType and the UTD pointers.
OH_Utd_DestroyStringList(typeIds1, typeIds1Count);
OH_Utd_DestroyStringList(typeIds2, typeIds2Count);
OH_Utd_Destroy(utd1);
OH_Utd_Destroy(utd2);
```

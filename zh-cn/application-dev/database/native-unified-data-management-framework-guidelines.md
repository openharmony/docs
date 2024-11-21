# UDMF开发指导（C/C++）


## 场景介绍

统一数据管理框架（UDMF）：提供了数据跨应用、跨设备交互标准，定义了跨应用、跨设备数据交互过程中的数据语言，提升数据交互效率。提供安全、标准化数据流通通路，支持不同级别的数据访问权限与生命周期管理策略，实现高效的数据跨应用、跨设备共享。


## 基本概念

- **标准化数据类型**：Uniform Type Descriptor，简称UTD。主要针对同一种数据类型，提供统一定义，即标准数据类型描述符，定义了包括标识数据类型的ID、类型归属关系等相关信息，用于解决OpenHarmony系统中的类型模糊问题。一般用于过滤或者识别某一种数据类型的场景，比如文件预览、文件分享等。

- **标准化数据结构**：Uniform Type Structure，简称UDS。主要针对部分标准化数据类型定义了统一的数据内容结构，并明确了对应的描述信息。应用间使用标准化数据结构进行数据交互后，将遵从统一的解析标准，可有效减少适配相关的工作量。一般用于跨应用跨设备间的数据交互，比如拖拽。

- **统一数据记录**： Unified Record，对UDMF支持的数据内容的抽象定义，例如一条文本记录、一条图片记录等。

- **统一数据对象**： Unified Data，用于封装一组数据记录Unified Record。

- **统一数据提供者**: Unified Data Provider，配置到统一数据记录中，用来提供UDS数据。通常用于数据的延迟发送场景，让UDS数据在数据使用方从统一数据记录中实际获取时才发生数据的转移。


## 约束限制

- UDMF支持批量数据记录的分组管理，每个分组整体大小不超过200MB，其中PlainText、Hyperlink、HTML内单个属性值数据上限20MB。
- 向统一数据记录中添加用户自定义数据时，所添加的数据大小不超过100MB。
- 向UDMF数据库中写入数据时，定义的唯一标识符的内存大小不小于512字节。



## 接口说明

详细的接口说明请参考[UDMF接口文档](../reference/apis-arkdata/_u_d_m_f.md)。

| 接口名称                                                     | 描述                                                        |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| OH_Utd* OH_Utd_Create(const char* typeId)                    | 创建一个指向统一数据类型描述符OH_Utd的指针。                |
| void OH_Utd_Destroy(OH_Utd* pThis)                           | 销毁指向统一数据类型描述符OH_Utd的指针。                    |
| const char** OH_Utd_GetTypesByFilenameExtension(const char* extension, unsigned int* count) | 通过文件后缀名获取标准化数据类型ID。                        |
| const char** OH_Utd_GetTypesByMimeType(const char* mimeType, unsigned int* count) | 通过MIME类型获取标准化数据类型ID。                          |
| bool OH_Utd_Equals(OH_Utd* utd1, OH_Utd* utd2)               | 判断两种标准化数据类型是否相等。                            |
| void OH_Utd_DestroyStringList(const char** list, unsigned int count) | 销毁字符串列表数据。                                        |
| OH_UdsHyperlink* OH_UdsHyperlink_Create()                    | 创建一个指向标准化数据结构超链接类型OH_UdsHyperlink的指针。 |
| void OH_UdsHyperlink_Destroy(OH_UdsHyperlink* pThis)         | 销毁指向标准化数据结构超链接类型OH_UdsHyperlink的指针。     |
| const char* OH_UdsHyperlink_GetType(OH_UdsHyperlink* pThis)  | 获取OH_UdsHyperlink中的标准化数据类型ID。                   |
| const char* OH_UdsHyperlink_GetUrl(OH_UdsHyperlink* pThis)   | 获取OH_UdsHyperlink中的链接URL。                            |
| const char* OH_UdsHyperlink_GetDescription(OH_UdsHyperlink* pThis) | 获取OH_UdsHyperlink中的链接内容描述。                       |
| int OH_UdsHyperlink_SetUrl(OH_UdsHyperlink* pThis, const char* url) | 设置OH_UdsHyperlink中的链接URL。                            |
| int OH_UdsHyperlink_SetDescription(OH_UdsHyperlink* pThis, const char* description) | 设置OH_UdsHyperlink中的链接内容描述。                       |
| OH_UdmfData* OH_UdmfData_Create()                            | 创建一个指向统一数据对象OH_UdmfData的指针。                 |
| void OH_UdmfData_Destroy(OH_UdmfData* pThis)                 | 销毁指向统一数据对象OH_UdmfData的指针。                     |
| int OH_UdmfData_AddRecord(OH_UdmfData* pThis, OH_UdmfRecord* record) | 向OH_UdmfData中增加一条OH_UdmfRecord数据记录。              |
| bool OH_UdmfData_HasType(OH_UdmfData* pThis, const char* type) | 判断统一数据对象OH_UdmfData是否存在指定类型。               |
| OH_UdmfRecord** OH_UdmfData_GetRecords(OH_UdmfData* pThis, unsigned int* count) | 获取OH_UdmfData中全部的数据记录。                           |
| OH_UdmfRecord* OH_UdmfRecord_Create()                        | 创建一个指向统一数据记录OH_UdmfRecord的指针。               |
| void OH_UdmfRecord_Destroy(OH_UdmfRecord* pThis)             | 销毁指向统一数据记录OH_UdmfRecord的指针。                   |
| int OH_UdmfRecord_AddHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink) | 向OH_UdmfRecord添加超链接类型数据。                         |
| char** OH_UdmfRecord_GetTypes(OH_UdmfRecord* pThis, unsigned int* count) | 获取OH_UdmfRecord中全部的数据类型。                         |
| int OH_UdmfRecord_GetHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink) | 获取OH_UdmfRecord中超链接类型数据。                         |
| int OH_Udmf_GetUnifiedData(const char* key, Udmf_Intention intention, OH_UdmfData* unifiedData) | 从UDMF数据库中获取数据。                                    |
| int OH_Udmf_SetUnifiedData(Udmf_Intention intention, OH_UdmfData* unifiedData, char* key, unsigned int keyLen) | 向UDMF数据库中写入数据。                                    |
| OH_UdmfRecordProvider* OH_UdmfRecordProvider_Create()        | 创建一个指向统一数据提供者的指针。                          |
| int OH_UdmfRecordProvider_SetData(OH_UdmfRecordProvider* provider, void* context, const OH_UdmfRecordProvider_GetData callback, const UdmfData_Finalize finalize) | 设置统一数据提供者的回调函数。                              |
| int OH_UdmfRecord_SetProvider(OH_UdmfRecord* pThis, const char* const* types, unsigned int count, OH_UdmfRecordProvider* provider) | 将统一数据提供者配置到OH_UdmfRecord中。                     |


## 添加动态链接库

CMakeLists.txt中添加以下lib。

```txt
libudmf.so
```

## 引用头文件

```c
#include <cstdio>
#include <cstring>
#include <database/udmf/utd.h>
#include <database/udmf/uds.h>
#include <database/udmf/udmf.h>
#include <database/udmf/udmf_meta.h>
#include <database/udmf/udmf_err_code.h>
```
## 通过不同方式获取纯文本类型数据

下面以获取纯文本数据的查询场景为例，说明如何使用UTD。
1. 通过后缀名“.txt”获取UTD的typeId。
2. 通过MIME类型“text/plain”获取UTD的typeId。
3. 使用以上两个步骤获取到的typeId创建UTD实例对象。
4. 比较UTD实例对象是否相等。
5. 使用结束后，删除上述步骤中产生的指针。

```c
// 1. 通过文件后缀名获取纯文本类型的UTD的typeId
unsigned int typeIds1Count = 0;
const char** typeIds1 = OH_Utd_GetTypesByFilenameExtension(".txt", &typeIds1Count);
printf("the count of typeIds1 is %u", typeIds1Count);
// 2. 通过MIME类型获取typeId
unsigned int typeIds2Count = 0;
const char** typeIds2 = OH_Utd_GetTypesByMimeType("text/plain", &typeIds2Count);
printf("the count of typeIds2 is %u", typeIds2Count);
// 3. 使用以上两个步骤获取到的typeId创建UTD实例对象。
OH_Utd* utd1 = OH_Utd_Create(typeIds1[0]);
OH_Utd* utd2 = OH_Utd_Create(typeIds2[0]);
// 4. 比较两种方式获取到的typeId对应的UTD是否相同
bool isEquals = OH_Utd_Equals(utd1, utd2);
if (isEquals) {
    printf("utd1 == utd2");
} else {
    printf("utd1 != utd2");
}
// 5. 销毁OH_Utd_GetTypesByFilenameExtension与OH_Utd_GetFilenameExtensions函数获取到的指针，同时销毁UTD指针
OH_Utd_DestroyStringList(typeIds1, typeIds1Count);
OH_Utd_DestroyStringList(typeIds2, typeIds2Count);
OH_Utd_Destroy(utd1);
OH_Utd_Destroy(utd2);
```

## 使用UDMF发送UDS数据

下面以发送超链接hyperlink类型数据场景为例，说明如何使用UDS与UDMF。
1. 创建超链接hyperlink数据的UDS数据结构。
2. 设置hyperlink中的URL和描述信息。
3. 将hyperlink数据放入数据记录OH_UdmfRecord中。
4. 将数据记录OH_UdmfRecord添加到统一数据OH_UdmfData中。
5. 保存以上数据至数据库中，得到返回的key值。
6. 使用结束后，删除上述步骤中产生的指针。

```c
// 1. 创建超链接hyperlink数据的UDS数据结构。
OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
// 2. 设置hyperlink中的URL和描述信息。
if (OH_UdsHyperlink_SetUrl(hyperlink, "www.demo.com") != Udmf_ErrCode::UDMF_E_OK) {
    printf("Hyperlink set url error!");
}
if (OH_UdsHyperlink_SetDescription(hyperlink, "This is the description.") != Udmf_ErrCode::UDMF_E_OK) {
    printf("Hyperlink set description error!");
}
// 3. 创建OH_UdmfRecord对象，并向OH_UdmfRecord中添加超链接类型数据。
OH_UdmfRecord* record = OH_UdmfRecord_Create();
if (OH_UdmfRecord_AddHyperlink(record, hyperlink) != Udmf_ErrCode::UDMF_E_OK) {
    printf("Add hyperlink to record error!");
}
// 4. 创建OH_UdmfData对象，并向OH_UdmfData中添加OH_UdmfRecord。
OH_UdmfData* data = OH_UdmfData_Create();
if (OH_UdmfData_AddRecord(data, record) != Udmf_ErrCode::UDMF_E_OK) {
    printf("Add record to data error!");
}
// 5. 构建数据，将数据写入数据库中，得到返回的key值。
char key[UDMF_KEY_BUFFER_LEN] = {0};
if (OH_Udmf_SetUnifiedData(Udmf_Intention::UDMF_INTENTION_DRAG, data, key, sizeof(key)) != Udmf_ErrCode::UDMF_E_OK) {
    printf("Set data error!");
}
printf("key = %s", key);
// 6. 使用完成后销毁指针。
OH_UdsHyperlink_Destroy(hyperlink);
OH_UdmfRecord_Destroy(record);
OH_UdmfData_Destroy(data);
```

## 使用UDMF接收UDS数据

下面继续以获取超链接hyperlink类型数据场景为例，说明如何使用UDS与UDMF。
1. 创建统一数据OH_UdmfData，用来承载数据库中读取的数据。
2. 通过key值从数据库中获取到数据。
3. 判断数据中是否有hyperlink类型的数据。
4. 获取OH_UdmfData中的数据记录，并从数据记录中获取hyperlink数据。
5. 读取hyperlink数据中的各项信息。
6. 使用结束后，删除上述步骤中产生的指针。

```c
// 1. 创建统一数据OH_UdmfData。
OH_UdmfData* readData = OH_UdmfData_Create();
// 此处key为示例，不可直接使用，其值应与OH_Udmf_SetUnifiedData接口中获取到的key值保持一致。
char key[] = {"udmf://Drag/com.ohos.test/0123456789"};
// 2. 通过key值从数据库中获取到数据。
if (OH_Udmf_GetUnifiedData(key, Udmf_Intention::UDMF_INTENTION_DRAG, readData) != Udmf_ErrCode::UDMF_E_OK) {
    printf("Failed to get data.");
    return;
}
// 3. 判断OH_UdmfData是否有对应的类型。
if (!OH_UdmfData_HasType(readData, UDMF_META_HYPERLINK)) {
    printf("There is no hyperlink type in data.");
    return;
}
// 4. 获取数据记录和hyperlink数据。
unsigned int recordsCount = 0;
OH_UdmfRecord** records = OH_UdmfData_GetRecords(readData, &recordsCount);
printf("the count of records count is %u", recordsCount);
// 创建hyperlink的UDS，用来承载record中读取出来的hyperlink数据。
OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
// 获取records中的元素。
for (int i = 0; i < recordsCount; i++) {
    // 获取OH_UdmfRecord类型列表。
    unsigned int recordTypeIdCount = 0;
    char** typeIdsFromRecord = OH_UdmfRecord_GetTypes(records[i], &recordTypeIdCount);
    for (unsigned int j = 0; j < recordTypeIdCount; j++) {
        // 从OH_UdmfRecord中获取超链接类型数据。
        if (strcmp(typeIdsFromRecord[j], UDMF_META_HYPERLINK) == 0) {
            // 获取hyperlink数据。
            if (OH_UdmfRecord_GetHyperlink(records[i], hyperlink) != Udmf_ErrCode::UDMF_E_OK) {
                printf("Fail get hyperlink from record!");
            }
        }
    }
}
// 5. 读取OH_UdsHyperlink中的各项信息。
printf("The hyperlink type id is : %s", OH_UdsHyperlink_GetType(hyperlink));
printf("The hyperlink url is : %s", OH_UdsHyperlink_GetUrl(hyperlink));
printf("The hyperlink description is : %s", OH_UdsHyperlink_GetDescription(hyperlink));
// 6. 销毁指针。
OH_UdsHyperlink_Destroy(hyperlink);
OH_UdmfData_Destroy(readData);
```

## 使用UDMF延迟发送UDS数据

### 定义UDS数据提供函数

下面以超链接hyperlink类型数据场景为例，说明如何定义一个提供UDS数据的回调函数。
1. 定义OH_UdmfRecordProvider的数据提供函数。
2. 在数据提供函数中，创建hyperlink类型的UDS数据结构。
3. 设置hyperlink中的URL和描述信息。
4. 定义OH_UdmfRecordProvider实例注销回调函数。

```c
// 为了代码可读性，代码中省略了各个步骤操作结果的校验，实际开发中需要确认每次调用的成功。
// 1. 获取数据时触发的提供UDS数据的回调函数。
static void* GetDataCallback(void* context, const char* type) {
    if (strcmp(type, UDMF_META_PLAIN_TEXT)) {
        // 2. 创建超链接hyperlink数据的UDS数据结构。
        OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
        // 3. 设置hyperlink中的URL和描述信息。
        OH_UdsHyperlink_SetUrl(hyperlink, "www.demo.com");
        OH_UdsHyperlink_SetDescription(hyperlink, "This is the description.");
        return hyperlink;
    }
    return nullptr;
}
// 4. OH_UdmfRecordProvider销毁时触发的回调函数。
static void ProviderFinalizeCallback(void* context) { printf("OH_UdmfRecordProvider finalize."); }
```

### 延迟发送UDS数据

下面以延迟发送超链接hyperlink类型数据场景为例，说明如何使用OH_UdmfRecordProvider与UDMF。需要注意，此步骤完成后超链接类型数据并未真正写入数据库，只有当数据使用者从OH_UdmfRecord中获取OH_UdsHyperlink时，才会触发上文定义的`GetDataCallback`数据提供函数，从中得到数据。

1. 创建一个OH_UdmfRecordProvider，并设置它的数据提供函数和销毁时的回调函数。
2. 创建一个OH_UdmfRecord对象，并将OH_UdmfRecordProvider配置到其中。
3. 创建一个OH_UdmfData对象，并向OH_UdmfData中添加OH_UdmfRecord。
4. 构建数据，将数据写入数据库中，得到返回的Key值。
5. 使用结束后，删除上述步骤中产生的指针。

```c
// 为了代码可读性，代码中省略了各个步骤操作结果的校验，实际开发中需要确认每次调用的成功。
// 1. 创建一个统一数据提供者，并配置它提供数据、销毁时的两个回调函数。
OH_UdmfRecordProvider* provider = OH_UdmfRecordProvider_Create();
OH_UdmfRecordProvider_SetData(provider, (void* )provider, GetDataCallback, ProviderFinalizeCallback);

// 2. 创建一个OH_UdmfRecord对象，并将OH_UdmfRecordProvider配置到其中。
OH_UdmfRecord* record = OH_UdmfRecord_Create();
const char* types[1] = {UDMF_META_HYPERLINK};
OH_UdmfRecord_SetProvider(record, types, 1, provider);

// 3. 创建OH_UdmfData对象，并向OH_UdmfData中添加OH_UdmfRecord。
OH_UdmfData* data = OH_UdmfData_Create();
OH_UdmfData_AddRecord(data, record);

// 4. 构建数据，将数据写入数据库中，得到返回的Key值。
char key[UDMF_KEY_BUFFER_LEN] = {0};
OH_Udmf_SetUnifiedData(Udmf_Intention::UDMF_INTENTION_DRAG, data, key, sizeof(key));
printf("key = %s", key);

// 5. 使用完成后销毁指针。
OH_UdmfRecord_Destroy(record);
OH_UdmfData_Destroy(data);
```
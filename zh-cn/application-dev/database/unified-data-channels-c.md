# 通过标准化数据通路实现数据共享 (C/C++)


## 场景介绍

在多对多跨应用数据共享的场景下，需要提供一条数据通路，能够写入多个不同应用的数据，并共享给其他应用进行读取。

UDMF针对多对多跨应用数据共享的不同业务场景，提供了标准化的数据通路和数据写入与读取接口。

## 标准化数据通路的定义和实现

标准化数据通路是为各种业务场景提供的跨应用数据写入与读取通路。它能够暂存应用需要共享的、符合标准化数据定义的统一数据对象，并提供给其他应用访问。同时，它按照一定策略对暂存数据的修改、删除权限及生命周期进行管理。

标准化数据通路通过UDMF提供的系统服务实现。应用（数据提供方）需要共享公共数据时，可以通过UDMF提供的插入接口将数据写入UDMF的数据通路中，并且可以通过UDMF提供的更新和删除接口对已存入的数据进行更新和删除操作。目标应用（数据访问方）可以通过UDMF提供的读取接口访问数据。

标准化数据通路相关接口应不推荐多线程调用。

统一数据对象UnifiedData在UDMF数据通路中具有全局唯一URI标识，其定义为udmf://intention/bundleName/groupId，其中各组成部分的含义分别为：

+ **udmf:** 协议名，表示使用UDMF提供的数据通路。

+ **intention:** UDMF已经支持的数据通路类型枚举值，对应不同的业务场景。

+ **bundleName:** 数据来源应用的包名称。

+ **groupId:** 分组名称，支持批量数据分组管理。

当前UDMF中的跨应用数据共享通路有：**公共数据通路**

**公共数据通路**：应用共享的公用数据通路，所有应用均可向通路中写入数据。写入方可以根据写入数据时生成的数据唯一标识符进行数据的更新、删除、查询指定数据标识符或全量查询。数据读取方可以通过唯一标识符读取指定数据，也可以设置Intention枚举类型为DATA_HUB来读取当前数据通路中的全量数据。公共数据通路仅用于传输应用间的过程数据，不能用于传输沙箱目录下文件等有权限管控的数据。UDMF会统一对数据的生命周期进行管理，每小时定期清理存入时长超过一小时的数据。

## 接口说明

详细的接口说明请参考[UDMF接口文档](../reference/apis-arkdata/capi-udmf-h.md)。

| 接口名称                                                                                    | 描述                                          | 
|-----------------------------------------------------------------------------------------|---------------------------------------------|
| OH_UdsHyperlink* OH_UdsHyperlink_Create()                                           | 创建超链接类型对象的指针。 |
| int OH_UdsHyperlink_SetDescription(OH_UdsHyperlink* pThis, const char* description) | 设置超链接类型实例中的描述参数。 |
| OH_UdmfRecord* OH_UdmfRecord_Create()                        | 创建一个指向统一数据记录OH_UdmfRecord的指针。               |
| int OH_UdmfRecord_AddHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink) | 向OH_UdmfRecord添加超链接类型数据。             |
| OH_UdmfData* OH_UdmfData_Create()                            | 创建一个指向统一数据对象OH_UdmfData的指针。                 |
| int OH_UdmfData_AddRecord(OH_UdmfData* pThis, OH_UdmfRecord* record) | 向OH_UdmfData中增加一条OH_UdmfRecord数据记录。      |
| int OH_Udmf_SetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData *unifiedData, char *key, unsigned int keyLen)        | 从统一数据管理框架数据库中写入统一数据对象OH_UdmfData数据。                          |
| void OH_UdsHyperlink_Destroy(OH_UdsHyperlink* pThis)         | 销毁超链接类型指针指向的实例对象。 |
| void OH_UdmfRecord_Destroy(OH_UdmfRecord* pThis)             | 销毁指向统一数据记录OH_UdmfRecord的指针。                   |
| void OH_UdmfData_Destroy(OH_UdmfData* pThis)                 | 销毁指向统一数据对象OH_UdmfData的指针。                     |
| char** OH_UdmfRecord_GetTypes(OH_UdmfRecord* pThis, unsigned int* count) | 获取OH_UdmfRecord中全部的数据类型。                     |
| int OH_UdmfRecord_GetHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink) | 获取OH_UdmfRecord中超链接类型数据。             |
| int OH_Udmf_GetUnifiedDataByOptions(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize) | 通过数据通路类型从统一数据管理框架数据库中获取统一数据对象数据。          |
| int OH_Udmf_UpdateUnifiedData(OH_UdmfOptions* options, OH_UdmfData* unifiedData) | 对统一数据管理框架数据库中的统一数据对象数据进行数据更改。 |
| int OH_Udmf_DeleteUnifiedData(OH_UdmfOptions* options, OH_UdmfData** dataArray, unsigned int* dataSize) | 删除统一数据管理框架数据库中的统一数据对象数据。|
| bool OH_UdmfData_HasType(OH_UdmfData* pThis, const char* type) | 判断统一数据对象OH_UdmfData是否存在指定类型。               |
| OH_UdmfRecord** OH_UdmfData_GetRecords(OH_UdmfData* pThis, unsigned int* count) | 获取OH_UdmfData中全部的数据记录。                           |
| OH_UdmfRecordProvider* OH_UdmfRecordProvider_Create()        | 创建一个指向统一数据提供者的指针。                          |
| int OH_UdmfRecordProvider_SetData(OH_UdmfRecordProvider* provider, void* context, const OH_UdmfRecordProvider_GetData callback, const UdmfData_Finalize finalize) | 设置统一数据提供者的回调函数。                              |
| int OH_UdmfRecord_SetProvider(OH_UdmfRecord* pThis, const char* const* types, unsigned int count, OH_UdmfRecordProvider* provider) | 将统一数据提供者配置到OH_UdmfRecord中。    |
| OH_UdmfOptions* OH_UdmfOptions_Create()        | 创建一个指向数据操作选项的指针。                          |
| void OH_UdmfOptions_Destroy(OH_UdmfOptions* pThis)  | 销毁指向数据操作选项的指针。                          |


## 添加动态链接库

CMakeLists.txt中添加以下库。

```txt
libudmf.so, libhilog_ndk.z.so
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
#include <hilog/log.h>

#undef LOG_TAG
#define LOG_TAG "MY_LOG"
```

## 使用UDMF写入UDS数据

下面以写入超链接OH_UdsHyperlink类型数据场景为例，说明如何使用UDS与UDMF。
1. 创建hyperlink的UDS数据结构。
2. 设置hyperlink中的URL和描述信息。
3. 创建OH_UdmfRecord对象，并向OH_UdmfRecord中添加超链接类型数据。
4. 创建OH_UdmfData对象，并向OH_UdmfData中添加OH_UdmfRecord。
5. 构建数据操作选项。
6. 构建数据，将数据写入数据库中，得到返回的key值。
7. 使用完成后销毁指针。

```c
void createDataTest()
{
    // 1. 创建hyperlink的UDS数据结构。
    OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
    // 2. 设置hyperlink中的URL和描述信息。
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
    // 3. 创建OH_UdmfRecord对象，并向OH_UdmfRecord中添加超链接类型数据。
    OH_UdmfRecord* record = OH_UdmfRecord_Create();
    if (OH_UdmfRecord_AddHyperlink(record, hyperlink) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Add hyperlink to record error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        OH_UdmfRecord_Destroy(record);
        return;
    }
    // 4. 创建OH_UdmfData对象，并向OH_UdmfData中添加OH_UdmfRecord。
    OH_UdmfData* data = OH_UdmfData_Create();
    if (OH_UdmfData_AddRecord(data, record) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Add record to data error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        OH_UdmfRecord_Destroy(record);
        OH_UdmfData_Destroy(data);
        return;
    }
    // 5. 构建数据操作选项。
    OH_UdmfOptions* options = OH_UdmfOptions_Create();
    if (OH_UdmfOptions_SetIntention(options, Udmf_Intention::UDMF_INTENTION_DATA_HUB) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Set option error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        OH_UdmfRecord_Destroy(record);
        OH_UdmfData_Destroy(data);
        OH_UdmfOptions_Destroy(options);
        return;
    }
    // 6. 构建数据，将数据写入数据库中，得到返回的key值。
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
    // 7. 使用完成后销毁指针。
    OH_UdsHyperlink_Destroy(hyperlink);
    OH_UdmfRecord_Destroy(record);
    OH_UdmfData_Destroy(data);
    OH_UdmfOptions_Destroy(options);
}
```

## 使用UDMF获取UDS数据

下面继续以获取超链接OH_UdsHyperlink类型数据场景为例，说明如何使用UDS与UDMF。
1. 构建数据操作选项。
2. 通过数据操作选项获取数据。
3. 判断OH_UdmfData是否有对应的类型。
4. 获取数据记录和hyperlink数据。
5. 销毁指针。

```c
void getDataTest()
{
    // 1. 构建数据操作选项。
    OH_UdmfOptions* options = OH_UdmfOptions_Create();
    if (OH_UdmfOptions_SetIntention(options, Udmf_Intention::UDMF_INTENTION_DATA_HUB) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Set option error!");
        OH_UdmfOptions_Destroy(options);
        return;
    }
    // 2. 通过数据操作选项获取数据。
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
        // 3. 判断OH_UdmfData是否有对应的类型。
        if (!OH_UdmfData_HasType(data, UDMF_META_HYPERLINK)) {
            OH_LOG_INFO(LOG_APP, "There is no hyperlink type in data[%{public}u].", i);
            continue;
        }
        // 4. 获取数据记录和hyperlink数据。
        unsigned int recordsCount = 0;
        OH_UdmfRecord** records = OH_UdmfData_GetRecords(data, &recordsCount);
        OH_LOG_INFO(LOG_APP, "the count of records count is %{public}u", recordsCount);    // 5. 获取records中的元素。
        for (unsigned int j = 0; j < recordsCount; j++) {
            // 获取OH_UdmfRecord类型列表。
            unsigned int recordTypeIdCount = 0;
            char** typeIdsFromRecord = OH_UdmfRecord_GetTypes(records[i], &recordTypeIdCount);
            for (unsigned int k = 0; k < recordTypeIdCount; k++) {
                // 从OH_UdmfRecord中获取超链接类型数据。
                if (strcmp(typeIdsFromRecord[k], UDMF_META_HYPERLINK) == 0) {
                    // 创建hyperlink的UDS，用来承载record中读取出来的hyperlink数据。
                    OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
                    if (OH_UdmfRecord_GetHyperlink(records[j], hyperlink) != Udmf_ErrCode::UDMF_E_OK) {
                        OH_LOG_ERROR(LOG_APP,"Fail get hyperlink from record!");
                        OH_UdsHyperlink_Destroy(hyperlink);
                        break;
                    }
                    // 读取OH_UdsHyperlink中的各项信息。
                    OH_LOG_INFO(LOG_APP, "The hyperlink type id is : %{public}s", OH_UdsHyperlink_GetType(hyperlink));
                    OH_LOG_INFO(LOG_APP, "The hyperlink url is : %{public}s", OH_UdsHyperlink_GetUrl(hyperlink));
                    OH_LOG_INFO(LOG_APP, "The hyperlink description is : %{public}s", OH_UdsHyperlink_GetDescription(hyperlink));
                    OH_UdsHyperlink_Destroy(hyperlink);
                }
            }
        }
    }
    // 5. 销毁指针。
    OH_Udmf_DestroyDataArray(dataArray, dataSize);
}
```

## 使用UDMF更新UDS数据

下面以更新超链接OH_UdsHyperlink类型数据场景为例，说明如何使用UDS与UDMF。
1. 创建hyperlink的UDS数据结构。
2. 设置hyperlink中的URL和描述信息。
3. 创建OH_UdmfRecord对象，并向OH_UdmfRecord中添加超链接类型数据。
4. 创建OH_UdmfData对象，并向OH_UdmfData中添加OH_UdmfRecord。
5. 构建数据操作选项。
6. 更新数据，将数据写入数据库中。
7. 使用完成后销毁指针。

```c
void updateDataTest()
{
    // 1. 创建hyperlink的UDS数据结构。
    OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
    // 2. 设置hyperlink中的URL和描述信息。
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
    // 3. 创建OH_UdmfRecord对象，并向OH_UdmfRecord中添加超链接类型数据。
    OH_UdmfRecord* record = OH_UdmfRecord_Create();
    if (OH_UdmfRecord_AddHyperlink(record, hyperlink) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Add hyperlink to record error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        OH_UdmfRecord_Destroy(record);
        return;
    }
    // 4. 创建OH_UdmfData对象，并向OH_UdmfData中添加OH_UdmfRecord。
    OH_UdmfData* data = OH_UdmfData_Create();
    if (OH_UdmfData_AddRecord(data, record) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Add record to data error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        OH_UdmfRecord_Destroy(record);
        OH_UdmfData_Destroy(data);
        return;
    }
    // 5. 构建数据操作选项。
    OH_UdmfOptions* options = OH_UdmfOptions_Create();
    // 此处key为示例，不可直接使用，其值应与OH_Udmf_SetUnifiedDataByOptions接口中获取到的key值保持一致。
    char key[] = {"udmf://DataHub/com.ohos.test/0123456789"};
    if (OH_UdmfOptions_SetIntention(options, Udmf_Intention::UDMF_INTENTION_DATA_HUB) != Udmf_ErrCode::UDMF_E_OK
        || OH_UdmfOptions_SetKey(options, key) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Set option error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        OH_UdmfRecord_Destroy(record);
        OH_UdmfData_Destroy(data);
        OH_UdmfOptions_Destroy(options);
        return;
    }
    // 6. 更新数据，将数据写入数据库中。
    if (OH_Udmf_UpdateUnifiedData(options, data) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Update data error!");
        OH_UdsHyperlink_Destroy(hyperlink);
        OH_UdmfRecord_Destroy(record);
        OH_UdmfData_Destroy(data);
        OH_UdmfOptions_Destroy(options);
        return;
    }
    OH_LOG_INFO(LOG_APP, "update data success");
    // 7. 使用完成后销毁指针。
    OH_UdsHyperlink_Destroy(hyperlink);
    OH_UdmfRecord_Destroy(record);
    OH_UdmfData_Destroy(data);
    OH_UdmfOptions_Destroy(options);
}
```

## 使用UDMF删除UDS数据

下面继续以获取超链接OH_UdsHyperlink类型数据场景为例，说明如何使用UDS与UDMF。
1. 构建数据操作选项。
2. 通过数据操作选项删除数据。
3. 判断OH_UdmfData是否有对应的类型。
4. 获取数据记录和hyperlink数据。
5. 获取数据记录中的元素。
6. 销毁指针。

```c
void deleteDataTest()
{
    // 1. 构建数据操作选项。
    OH_UdmfOptions* options = OH_UdmfOptions_Create();
    if (OH_UdmfOptions_SetIntention(options, Udmf_Intention::UDMF_INTENTION_DATA_HUB) != Udmf_ErrCode::UDMF_E_OK) {
        OH_LOG_ERROR(LOG_APP, "Set option error!");
        OH_UdmfOptions_Destroy(options);
        return;
    }
    // 2. 通过数据操作选项删除数据。
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
        // 3. 判断OH_UdmfData是否有对应的类型。
        if (!OH_UdmfData_HasType(data, UDMF_META_HYPERLINK)) {
            OH_LOG_INFO(LOG_APP, "There is no hyperlink type in data[%{public}u].", i);
            continue;
        }
        // 4. 获取数据记录和hyperlink数据。
        unsigned int recordsCount = 0;
        OH_UdmfRecord** records = OH_UdmfData_GetRecords(data, &recordsCount);
        OH_LOG_INFO(LOG_APP, "the count of records count is %{public}u", recordsCount);    
        // 5. 获取数据记录中的元素。
        for (unsigned int j = 0; j < recordsCount; j++) {
            // 获取OH_UdmfRecord类型列表。
            unsigned int recordTypeIdCount = 0;
            char** typeIdsFromRecord = OH_UdmfRecord_GetTypes(records[i], &recordTypeIdCount);
            for (unsigned int k = 0; k < recordTypeIdCount; k++) {
                // 从OH_UdmfRecord中获取超链接类型数据。
                if (strcmp(typeIdsFromRecord[k], UDMF_META_HYPERLINK) == 0) {
                    // 创建hyperlink的UDS，用来承载record中读取出来的hyperlink数据。
                    OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
                    if (OH_UdmfRecord_GetHyperlink(records[j], hyperlink) != Udmf_ErrCode::UDMF_E_OK) {
                        OH_LOG_ERROR(LOG_APP,"Fail get hyperlink from record!");
                        OH_UdsHyperlink_Destroy(hyperlink);
                        break;
                    }
                    // 读取OH_UdsHyperlink中的各项信息。
                    OH_LOG_INFO(LOG_APP, "The hyperlink type id is : %{public}s", OH_UdsHyperlink_GetType(hyperlink));
                    OH_LOG_INFO(LOG_APP, "The hyperlink url is : %{public}s", OH_UdsHyperlink_GetUrl(hyperlink));
                    OH_LOG_INFO(LOG_APP, "The hyperlink description is : %{public}s", OH_UdsHyperlink_GetDescription(hyperlink));
                    OH_UdsHyperlink_Destroy(hyperlink);
                }
            }
        }
    }
    // 6. 销毁指针。
    OH_Udmf_DestroyDataArray(dataArray, dataSize);
}
```

## 使用UDMF延迟写入UDS数据

### 定义UDS数据提供函数

下面以超链接hyperlink类型数据场景为例，说明如何定义一个提供UDS数据的回调函数。
1. 定义OH_UdmfRecordProvider的数据提供函数。
2. 在数据提供函数中，创建hyperlink类型的UDS数据结构。
3. 设置hyperlink的URL和描述信息。
4. 定义OH_UdmfRecordProvider销毁时触发的回调函数。

```c
// 为了代码可读性，代码中省略了各个步骤操作结果的校验，实际开发中需要确认每次调用的成功。
// 1. 获取数据时触发的提供UDS数据的回调函数。
static void* GetDataCallback(void* context, const char* type) {
    if (strcmp(type, UDMF_META_HYPERLINK) == 0) {
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
static void ProviderFinalizeCallback(void* context) { OH_LOG_INFO(LOG_APP, "OH_UdmfRecordProvider finalize."); }
```

### 延迟写入UDS数据

下面以延迟写入超链接类型数据为例，说明如何使用OH_UdmfRecordProvider与UDMF。此步骤完成后，超链接类型数据并未真正写入数据库。只有当数据使用者从OH_UdmfRecord中获取OH_UdsHyperlink时，才会触发上文定义的`GetDataCallback`数据提供函数，从中获取数据。

1. 创建OH_UdmfRecordProvider对象，设置它的数据提供函数和销毁回调函数。
2. 创建OH_UdmfRecord对象，并配置OH_UdmfRecordProvider。
3. 创建OH_UdmfData对象，并向OH_UdmfData中添加OH_UdmfRecord。
4. 构建数据并写入数据库中，获取返回的Key值。
5. 使用完成后销毁指针。

```c
void providerSetDataTest()
{
    // 为了代码可读性，代码中省略了各个步骤操作结果的校验，实际开发中需要确认每次调用的成功。
    // 1. 创建一个OH_UdmfRecordProvider，设置它的数据提供函数和销毁回调函数。
    OH_UdmfRecordProvider* provider = OH_UdmfRecordProvider_Create();
    OH_UdmfRecordProvider_SetData(provider, (void* )provider, GetDataCallback, ProviderFinalizeCallback);

    // 2. 创建OH_UdmfRecord对象，并配置OH_UdmfRecordProvider。
    OH_UdmfRecord* record = OH_UdmfRecord_Create();
    const char* types[1] = {UDMF_META_HYPERLINK};
    OH_UdmfRecord_SetProvider(record, types, 1, provider);

    // 3. 创建OH_UdmfData对象，并向OH_UdmfData中添加OH_UdmfRecord。
    OH_UdmfData* data = OH_UdmfData_Create();
    OH_UdmfData_AddRecord(data, record);

    // 4. 构建数据并写入数据库中，获取返回的Key值。
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

    // 5. 使用完成后销毁指针。
    OH_UdmfRecord_Destroy(record);
    OH_UdmfData_Destroy(data);
    OH_UdmfOptions_Destroy(options);
}
```
# UDMF开发指导 (C/C++)


## 场景介绍

统一数据管理框架（UDMF）：提供了数据跨应用、跨设备交互标准，定义了跨应用、跨设备数据交互过程中的数据语言，提升数据交互效率。提供安全、标准化数据流通通路，支持不同级别的数据访问权限与生命周期管理策略，实现高效的数据跨应用、跨设备共享。


## 基本概念

- **标准化数据类型**：Uniform Type Descriptor，简称UTD。主要针对同一种数据类型，提供统一定义，即标准数据类型描述符，定义了包括标识数据类型的ID、类型归属关系等相关信息，用于解决OpenHarmony系统中的类型模糊问题。一般用于过滤或者识别某一种数据类型的场景，比如文件预览、文件分享等。

- **标准化数据结构**：Uniform Type Structure，简称UDS。主要针对部分标准化数据类型定义了统一的数据内容结构，并明确了对应的描述信息。应用间使用标准化数据结构进行数据交互后，将遵从统一的解析标准，可有效减少适配相关的工作量。一般用于跨应用跨设备间的数据交互，比如拖拽。

- **统一数据记录**： Unified Record，对UDMF支持的数据内容的抽象定义，例如一条文本记录、一条图片记录等。

- **统一数据对象**： Unified Data，用于封装一组数据记录UnifiedRecord。


## 约束限制

- UDMF支持批量数据记录的分组管理，每个分组整体大小不超过200MB，其中PlainText、Hyperlink、HTML内单个属性值数据上限20M。



## 接口说明

详细的接口说明请参考[暂未完成](../reference/apis-arkdata/_r_d_b.md)。

| 接口名称 | 描述                        |
| -------- |---------------------------|
| OH_Utd* OH_Utd_Create(const char* typeId) | 创建一个指向统一数据类型描述符OH_Utd的指针。 |
| void OH_Utd_Destroy(OH_Utd* pThis) | 销毁指向统一数据类型描述符OH_Utd的指针。 |
| const char* OH_Utd_GetTypeId(OH_Utd* pThis) | 获取OH_Utd中的标准化数据类型id。 |
| const char* OH_Utd_GetDescription(OH_Utd* pThis) | 获取OH_Utd中的描述参数。 |
| const char* OH_Utd_GetReferenceUrl(OH_Utd* pThis) | 获取OH_Utd中的参考链接URL。 |
| const char* OH_Utd_GetIconFile(OH_Utd* pThis) | 获取OH_Utd中的默认图标文件路径。 |
| const char** OH_Utd_GetBelongingToTypes(OH_Utd* pThis, unsigned int* count) | 获取OH_Utd中的默认图标文件路径。 |
| const char** OH_Utd_GetFilenameExtensions(OH_Utd* pThis, unsigned int* count) | 获取OH_Utd所关联的文件名后缀列表。 |
| const char** OH_Utd_GetMimeTypes(OH_Utd* pThis, unsigned int* count) | 获取OH_Utd所关联的web消息数据类型列表。 |
| const char** OH_Utd_GetTypesByFilenameExtension(const char* extension, unsigned int* count) | 通过文件后缀名获取标准化数据类型id。 |
| const char** OH_Utd_GetTypesByMimeType(const char* mimeType, unsigned int* count) | 通过web消息数据类型获取标准化数据类型id。 |
| bool OH_Utd_BelongsTo(const char* srcTypeId, const char* destTypeId) | 判断标准化数据类型是否归属于指定的标准化数据类型。 |
| bool OH_Utd_IsLower(const char* srcTypeId, const char* destTypeId) | 判断标准化数据类型是否是指定的标准化数据类型的低层级类型。 |
| bool OH_Utd_IsHigher(const char* srcTypeId, const char* destTypeId) | 判断标准化数据类型是否是指定的标准化数据类型的高层级类型。 |
| bool OH_Utd_Equals(OH_Utd* utd1, OH_Utd* utd2) | 判断两种标准化数据类型是否相等。 |
| void OH_Utd_DestroyStringList(const char** list, unsigned int count) | 销毁字符串列表数据。 |
| OH_UdsPlainText* OH_UdsPlainText_Create() | 创建一个指向标准化数据结构纯文本类型OH_UdsPlainText的指针。 |
| void OH_UdsPlainText_Destroy(OH_UdsPlainText* pThis) | 销毁指向标准化数据结构纯文本类型OH_UdsPlainText的指针。 |
| const char* OH_UdsPlainText_GetType(OH_UdsPlainText* pThis)  | 获取OH_UdsPlainText中的标准化数据类型id。 |
| const char* OH_UdsPlainText_GetContent(OH_UdsPlainText* pThis) | 获取OH_UdsPlainText中的纯文本内容。 |
| const char* OH_UdsPlainText_GetAbstract(OH_UdsPlainText* pThis) | 获取OH_UdsPlainText中的纯文本摘要。 |
| int OH_UdsPlainText_SetContent(OH_UdsPlainText* pThis, const char* content) | 设置OH_UdsPlainText中的纯文本内容。 |
| int OH_UdsPlainText_SetAbstract(OH_UdsPlainText* pThis, const char* abstract) | 设置OH_UdsPlainText中的纯文本摘要。 |
| OH_UdsHyperlink* OH_UdsHyperlink_Create() | 创建一个指向标准化数据结构超链接类型OH_UdsHyperlink的指针。 |
| void OH_UdsHyperlink_Destroy(OH_UdsHyperlink* pThis) | 销毁指向标准化数据结构超链接类型OH_UdsHyperlink的指针。 |
| const char* OH_UdsHyperlink_GetType(OH_UdsHyperlink* pThis) | 获取OH_UdsHyperlink中的标准化数据类型id。 |
| const char* OH_UdsHyperlink_GetUrl(OH_UdsHyperlink* pThis) | 获取OH_UdsHyperlink中的链接URL。 |
| const char* OH_UdsHyperlink_GetDescription(OH_UdsHyperlink* pThis) | 获取OH_UdsHyperlink中的链接内容描述。 |
| int OH_UdsHyperlink_SetUrl(OH_UdsHyperlink* pThis, const char* url) | 设置OH_UdsHyperlink中的链接URL。 |
| int OH_UdsHyperlink_SetDescription(OH_UdsHyperlink* pThis, const char* description) | 设置OH_UdsHyperlink中的链接内容描述。 |
| OH_UdsHtml* OH_UdsHtml_Create() | 创建一个指向标准化数据结构超文本标记语言数据类型OH_UdsHtml的指针。 |
| void OH_UdsHtml_Destroy(OH_UdsHtml* pThis) | 销毁指向标准化数据结构超文本标记语言数据类型OH_UdsHtml的指针。 |
| const char* OH_UdsHtml_GetType(OH_UdsHtml* pThis) | 获取OH_UdsHtml中的标准化数据类型id。 |
| const char* OH_UdsHtml_GetContent(OH_UdsHtml* pThis) | 获取OH_UdsHtml中的html格式内容。 |
| const char* OH_UdsHtml_GetPlainContent(OH_UdsHtml* pThis) | 获取OH_UdsHtml中的纯文本内容。 |
| int OH_UdsHtml_SetContent(OH_UdsHtml* pThis, const char* content) | 设置OH_UdsHtml中的html格式内容。 |
| int OH_UdsHtml_SetPlainContent(OH_UdsHtml* pThis, const char* plainContent) | 设置OH_UdsHtml中的纯文本内容。 |
| OH_UdsAppItem* OH_UdsAppItem_Create() | 创建一个指向标准化数据结构桌面图标类型OH_UdsAppItem的指针。 |
| void OH_UdsAppItem_Destroy(OH_UdsAppItem* pThis) | 销毁指向标准化数据结构桌面图标类型OH_UdsAppItem的指针。 |
| const char* OH_UdsAppItem_GetType(OH_UdsAppItem* pThis) | 获取OH_UdsAppItem中的标准化数据类型id。 |
| const char* OH_UdsAppItem_GetId(OH_UdsAppItem* pThis) | 获取OH_UdsAppItem中图标对应的应用id。 |
| const char* OH_UdsAppItem_GetName(OH_UdsAppItem* pThis) | 获取OH_UdsAppItem中图标对应的应用名。 |
| const char* OH_UdsAppItem_GetIconId(OH_UdsAppItem* pThis) | 获取OH_UdsAppItem中图标对应的图片id。 |
| const char* OH_UdsAppItem_GetLabelId(OH_UdsAppItem* pThis) | 获取OH_UdsAppItem中图标对应的标签id。 |
| const char* OH_UdsAppItem_GetBundleName(OH_UdsAppItem* pThis)  | 获取OH_UdsAppItem中图标对应的bundle名。 |
| const char* OH_UdsAppItem_GetAbilityName(OH_UdsAppItem* pThis) | 获取OH_UdsAppItem中图标对应的activity名。 |
| int OH_UdsAppItem_SetId(OH_UdsAppItem* pThis, const char* appId) | 设置OH_UdsAppItem中图标对应的应用id。 |
| int OH_UdsAppItem_SetName(OH_UdsAppItem* pThis, const char* appName) | 设置OH_UdsAppItem中图标对应的应用名。 |
| int OH_UdsAppItem_SetIconId(OH_UdsAppItem* pThis, const char* appIconId) | 设置OH_UdsAppItem中图标对应的图片id。 |
| int OH_UdsAppItem_SetLabelId(OH_UdsAppItem* pThis, const char* appLabelId) | 设置OH_UdsAppItem中图标对应的标签id。 |
| int OH_UdsAppItem_SetBundleName(OH_UdsAppItem* pThis, const char* bundleName) | 设置OH_UdsAppItem中图标对应的bundle名。 |
| int OH_UdsAppItem_SetAbilityName(OH_UdsAppItem* pThis, const char* abilityName) | 设置OH_UdsAppItem中图标对应的activity名。 |
| OH_UdmfData* OH_UdmfData_Create() | 创建一个指向统一数据对象OH_UdmfData的指针。 |
| void OH_UdmfData_Destroy(OH_UdmfData* pThis) | 销毁指向统一数据对象OH_UdmfData的指针。 |
| int OH_UdmfData_AddRecord(OH_UdmfData* pThis, OH_UdmfRecord* record) | 向OH_UdmfData中增加一条OH_UdmfRecord数据记录。 |
| bool OH_UdmfData_HasType(OH_UdmfData* pThis, const char* type) | 判断统一数据对象OH_UdmfData是否存在指定类型。 |
| char** OH_UdmfData_GetTypes(OH_UdmfData* pThis, unsigned int* count)  | 获取OH_UdmfData中全部的数据类型。 |
| OH_UdmfRecord** OH_UdmfData_GetRecords(OH_UdmfData* pThis, unsigned int* count) | 获取OH_UdmfData中全部的数据记录。 |
| OH_UdmfRecord* OH_UdmfRecord_Create() | 创建一个指向统一数据记录OH_UdmfRecord的指针。 |
| void OH_UdmfRecord_Destroy(OH_UdmfRecord* pThis) | 销毁指向统一数据记录OH_UdmfRecord的指针。 |
| int OH_UdmfRecord_AddGeneralEntry(OH_UdmfRecord* pThis, const char* typeId, unsigned char* entry, unsigned int count) | 向OH_UdmfRecord添加自定义类型数据。 |
| int OH_UdmfRecord_AddPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText) | 向OH_UdmfRecord添加纯文本类型数据。 |
| int OH_UdmfRecord_AddHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink) | 向OH_UdmfRecord添加超链接类型数据。 |
| int OH_UdmfRecord_AddHtml(OH_UdmfRecord* pThis, OH_UdsHtml* html) | 向OH_UdmfRecord添加超文本标记语言类型数据。 |
| int OH_UdmfRecord_AddAppItem(OH_UdmfRecord* pThis, OH_UdsAppItem* appItem) | 向OH_UdmfRecord添加桌面图标类型数据。 |
| char** OH_UdmfRecord_GetTypes(OH_UdmfRecord* pThis, unsigned int* count) | 获取OH_UdmfRecord中全部的数据类型。 |
| int OH_UdmfRecord_GetGeneralEntry(OH_UdmfRecord* pThis, const char* typeId, unsigned char** entry, unsigned int* count) | 获取OH_UdmfRecord中自定义类型数据。 |
| int OH_UdmfRecord_GetPlainText(OH_UdmfRecord* pThis, OH_UdsPlainText* plainText) | 获取OH_UdmfRecord中纯文本类型数据。 |
| int OH_UdmfRecord_GetHyperlink(OH_UdmfRecord* pThis, OH_UdsHyperlink* hyperlink) | 获取OH_UdmfRecord中超链接类型数据。 |
| int OH_UdmfRecord_GetHtml(OH_UdmfRecord* pThis, OH_UdsHtml* html) | 获取OH_UdmfRecord中超文本标记语言类型数据。 |
| int OH_UdmfRecord_GetAppItem(OH_UdmfRecord* pThis, OH_UdsAppItem* appItem) | 获取OH_UdmfRecord中桌面图标类型数据。 |
| OH_UdmfProperty* OH_UdmfProperty_Create(OH_UdmfData* unifiedData) | 通过OH_UdmfData创建一个指向统一数据记录属性OH_UdmfProperty的指针。 |
| void OH_UdmfProperty_Detroy(OH_UdmfProperty* pThis) | 销毁指向统一数据记录属性OH_UdmfProperty的指针。 |
| const char* OH_UdmfProperty_GetTag(OH_UdmfProperty* pThis) | 获取OH_UdmfProperty中用户自定义标签。 |
| int64_t OH_UdmfProperty_GetTimestamp(OH_UdmfProperty* pThis) | 获取OH_UdmfProperty中时间戳。 |
| Udmf_ShareOption OH_UdmfProperty_GetShareOption(OH_UdmfProperty* pThis) | 获取OH_UdmfProperty中支持的设备内使用范围。 |
| int OH_UdmfProperty_GetExtrasIntParam(OH_UdmfProperty* pThis, const char* key, int defaultValue) | 通过指定的key获取OH_UdmfProperty中整型类型的字典对象。 |
| const char* OH_UdmfProperty_GetExtrasStringParam(OH_UdmfProperty* pThis, const char* key) | 通过指定的key获取OH_UdmfProperty中字符串类型的字典对象。 |
| int OH_UdmfProperty_SetTag(OH_UdmfProperty* pThis, const char* tag) | 设置OH_UdmfProperty中用户自定义标签。 |
| int OH_UdmfProperty_SetShareOption(OH_UdmfProperty* pThis, Udmf_ShareOption option) | 设置OH_UdmfProperty中支持的设备内使用范围。 |
| int OH_UdmfProperty_SetExtrasIntParam(OH_UdmfProperty* pThis, const char* key, int param) | 设置OH_UdmfProperty中整型类型的字典对象。 |
| int OH_UdmfProperty_SetExtrasStringParam(OH_UdmfProperty* pThis, const char* key, const char* param) | 设置OH_UdmfProperty中字符串类型的字典对象。 |
| int OH_Udmf_GetUnifiedData(const char* key, Udmf_Intention intention, OH_UdmfData* unifiedData) | 从UDMF数据库中获取数据 |
| int OH_Udmf_SetUnifiedData(Udmf_Intention intention, OH_UdmfData* unifiedData, char* key, unsigned int keyLen) | 向UDMF数据库中写入数据 |



## 开发步骤

**添加动态链接库**

CMakeLists.txt中添加以下lib。

```txt
libudmf.so
```

**头文件**

```c
#include <database/udmf/utd.h>
#include <database/udmf/uds.h>
#include <database/udmf/udmf.h>
#include <database/udmf/udmf_meta.h>
#include <database/udmf/udmf_err_code.h>
```
**UTD代码使用示例**

1. 获取OH_Utd实例，并获取OH_Utd中的详细信息。其中针对OH_Utd_GetBelongingToTypes、OH_Utd_GetFilenameExtensions、OH_Utd_GetMimeTypes，使用第二个入参为所获取属性的数量。示例代码如下所示：

   ```c
    // 创建OH_Utd对象
    OH_Utd* utd = OH_Utd_Create(UDMF_META_PLAIN_TEXT);
    // 获取typeId
    const char* typeId = OH_Utd_GetTypeId(utd);
    // 获取description
    const char* desc = OH_Utd_GetDescription(utd);
    // 获取URL
    const char* url = OH_Utd_GetReferenceUrl(utd);
    // 获取iconFile
    const char* iconFile = OH_Utd_GetIconFile(utd);
    // 获取belongingToTypes
    unsigned int belongingToTypesCount = 0;
    const char** belongingToTypes = OH_Utd_GetBelongingToTypes(utd, &belongingToTypesCount);
    // 获取filesExtensions
    unsigned int filenameExtensionsCount = 0;
    const char** filenameExtensions = OH_Utd_GetFilenameExtensions(utd, &filenameExtensionsCount);
    // 获取mimeTypes
    unsigned int mimeTypesCount = 0;
    const char** mimeTypes = OH_Utd_GetMimeTypes(utd, &mimeTypesCount);
    // 销毁指针
    OH_Utd_Destroy(utd);
   ```

2. 通过文件后缀名和mimeTypes获取一到多个OH_Utd的typeId。函数出参均为typeId的二维数组，函数中使用第二个参数来表示所获取到的typeId数量。示例代码如下所示：

   ```c
    // 通过文件后缀名获取typeId
    unsigned int typeIds1Count = 0;
    const char** typeIds1 = OH_Utd_GetTypesByFilenameExtension(".txt", &typeIds1Count);
    // 通过mimeType获取typeId
    unsigned int typeIds2Count = 0;
    const char** typeIds2 = OH_Utd_GetTypesByMimeType("text/plain", &typeIds2Count);
    // 销毁OH_Utd_GetTypesByFilenameExtension与OH_Utd_GetFilenameExtensions函数获取到的指针
    OH_Utd_DestroyStringList(typeIds1, typeIds1Count);
    OH_Utd_DestroyStringList(typeIds2, typeIds2Count);
   ```

3. 比较两个UTD之间的关系。示例代码如下所示：

   ```c
    // 判断UDMF_META_PLAIN_TEXT是否归属于UDMF_META_TEXT
    bool result1 = OH_Utd_BelongsTo(UDMF_META_PLAIN_TEXT, UDMF_META_TEXT);
    // 判断UDMF_META_PLAIN_TEXT是否是UDMF_META_TEXT的低层级结构
    bool result2 = OH_Utd_IsLower(UDMF_META_PLAIN_TEXT, UDMF_META_TEXT);
    // 判断UDMF_META_TEXT是否是UDMF_META_PLAIN_TEXT的高层级结构
    bool result3 = OH_Utd_IsHigher(UDMF_META_TEXT, UDMF_META_PLAIN_TEXT);
    // 判断两个UTD是否相等
    OH_Utd* utd1 = OH_Utd_Create(UDMF_META_PLAIN_TEXT);
    unsigned int typeIdsCount = 0;
    const char** typeIds = OH_Utd_GetTypesByFilenameExtension(".txt", &typeIdsCount);
    OH_Utd* utd2 = OH_Utd_Create(typeIds[0]);
    bool result4 = OH_Utd_Equals(utd1, utd2);
    // 销毁指针
    OH_Utd_DestroyStringList(typeIds, typeIdsCount);
    OH_Utd_Destroy(utd1);
    OH_Utd_Destroy(utd2);
   ```

**UDS代码使用示例**

1. 获取OH_UdsPlainText实例，并获取OH_UdsPlainText中的内容信息。示例代码如下所示：

   ```c
    // 创建OH_UdsPlainText对象
    OH_UdsPlainText* plainText = OH_UdsPlainText_Create();
    // 获取OH_UdsPlainText的typeId
    const char* typeId1 = OH_UdsPlainText_GetType(plainText);
    // 设置OH_UdsPlainText的content
    int result = OH_UdsPlainText_SetContent(plainText, "This is the content.");
    // 设置OH_UdsPlainText的abstract
    result = OH_UdsPlainText_SetAbstract(plainText, "This is the abstract.");
    // 获取OH_UdsPlainText的content
    const char* content = OH_UdsPlainText_GetContent(plainText);
    // 获取OH_UdsPlainText的abstract
    const char* abstract = OH_UdsPlainText_GetAbstract(plainText);
    // 销毁指针
    OH_UdsPlainText_Destroy(plainText);
   ```

2. 获取OH_UdsHyperlink实例，并获取OH_UdsHyperlink中的内容信息。示例代码如下所示：

   ```c
    // 创建OH_UdsHyperlink对象
    OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
    // 获取OH_UdsHyperlink的typeId
    const char* typeId2 = OH_UdsHyperlink_GetType(hyperlink);
    // 设置OH_UdsHyperlink的URL
    int result = OH_UdsHyperlink_SetUrl(hyperlink, "This is the url.");
    // 设置OH_UdsHyperlink的description
    result = OH_UdsHyperlink_SetDescription(hyperlink, "This is the abstract.");
    // 获取OH_UdsHyperlink的URL
    const char* url = OH_UdsHyperlink_GetUrl(hyperlink);
    // 获取OH_UdsHyperlink的description
    const char* description = OH_UdsHyperlink_GetDescription(hyperlink);
    // 销毁指针
    OH_UdsHyperlink_Destroy(hyperlink);
   ```

3. 获取OH_UdsHtml实例，并获取OH_UdsHtml中的内容信息。示例代码如下所示：

   ```c
    // 创建OH_UdsHtml对象
    OH_UdsHtml* html = OH_UdsHtml_Create();
    // 获取OH_UdsHtml的typeId
    const char* typeId3 = OH_UdsHtml_GetType(html);
    // 设置OH_UdsHtml的content
    int result = OH_UdsHtml_SetContent(html, "This is the content.");
    // 设置OH_UdsHtml的plainContent
    result = OH_UdsHtml_SetPlainContent(html, "This is the plain content.");
    // 获取OH_UdsHtml的content
    const char* htmlContent = OH_UdsHtml_GetContent(html);
    // 获取OH_UdsHtml的plainContent
    const char* plainContent = OH_UdsHtml_GetPlainContent(html);
    // 销毁指针
    OH_UdsHtml_Destroy(html);
   ```

4. 获取OH_UdsAppItem实例，并获取OH_UdsAppItem中的内容信息。示例代码如下所示：

   ```c
    // 创建OH_UdsAppItem对象
    OH_UdsAppItem* appItem = OH_UdsAppItem_Create();
    // 获取OH_UdsAppItem的typeId
    const char* typeId4 = OH_UdsAppItem_GetType(appItem);
    // 设置OH_UdsAppItem的id
    int result = OH_UdsAppItem_SetId(appItem, "This is the app ID.");
    // 设置OH_UdsAppItem的appName
    result = OH_UdsAppItem_SetName(appItem, "This is the app name.");
    // 设置OH_UdsAppItem的iconId
    result = OH_UdsAppItem_SetIconId(appItem, "This is icon ID.");
    // 设置OH_UdsAppItem的labelId
    result = OH_UdsAppItem_SetLabelId(appItem, "This is the label ID.");
    // 设置OH_UdsAppItem的bundleName
    result = OH_UdsAppItem_SetBundleName(appItem, "This is the bundle name.");
    // 设置OH_UdsAppItem的abilityName
    result = OH_UdsAppItem_SetAbilityName(appItem, "This is the ability name.");
    // 获取OH_UdsAppItem的id
    const char* appId = OH_UdsAppItem_GetId(appItem);
    // 获取OH_UdsAppItem的appName
    const char* appName = OH_UdsAppItem_GetName(appItem);
    // 获取OH_UdsAppItem的iconId
    const char* iconId = OH_UdsAppItem_GetIconId(appItem);
    // 获取OH_UdsAppItem的labelId
    const char* labelId = OH_UdsAppItem_GetLabelId(appItem);
    // 获取OH_UdsAppItem的bundleName
    const char* bundleName = OH_UdsAppItem_GetBundleName(appItem);
    // 获取OH_UdsAppItem的abilityName
    const char* abilityName = OH_UdsAppItem_GetAbilityName(appItem);
    // 销毁指针
    OH_UdsAppItem_Destroy(appItem);
   ```

**UDMF代码使用示例**

1. 创建OH_UdmfData、OH_UdmfRecord实例，并向OH_UdmfRecord放入不同种类数据，最后放入OH_UdmfData中。示例代码如下所示：

   ```c
    // 创建OH_UdmfRecord对象
    OH_UdmfRecord* record = OH_UdmfRecord_Create();
    // 向OH_UdmfRecord中插入自定义数据
    unsigned char entry[]("demo");
    int returnStatus = OH_UdmfRecord_AddGeneralEntry(record, "demo.typeId", entry, sizeof(entry));
    // 向OH_UdmfRecord中添加纯文本类型数据
    OH_UdsPlainText* plainText = OH_UdsPlainText_Create();
    returnStatus = OH_UdmfRecord_AddPlainText(record, plainText);
    // 向OH_UdmfRecord中添加超链接类型数据
    OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
    returnStatus = OH_UdmfRecord_AddHyperlink(record, hyperlink);
    // 向OH_UdmfRecord中添加HTML类型数据
    OH_UdsHtml* html = OH_UdsHtml_Create();
    returnStatus = OH_UdmfRecord_AddHtml(record, html);
    // 向OH_UdmfRecord中添加appItem类型数据
    OH_UdsAppItem* appItem = OH_UdsAppItem_Create();
    returnStatus = OH_UdmfRecord_AddAppItem(record, appItem);
    // 创建OH_UdmfData对象
    OH_UdmfData* data = OH_UdmfData_Create();
    // 向OH_UdmfData中添加OH_UdmfRecord
    returnStatus = OH_UdmfData_AddRecord(data, record);
    // 销毁指针
    OH_UdsPlainText_Destroy(plainText);
    OH_UdsHyperlink_Destroy(hyperlink);
    OH_UdsHtml_Destroy(html);
    OH_UdsAppItem_Destroy(appItem);
    OH_UdmfRecord_Destroy(record);
    OH_UdmfData_Destroy(data);
   ```

2. 获取OH_UdmfData、OH_UdmfRecord中各种详细信息。示例代码如下所示：

   ```c
    // 创建OH_UdmfData对象，处省略设置record等，参考上一部示例代码
    OH_UdmfData* data = OH_UdmfData_Create();
    // 判断OH_UdmfData是否有对应的类型
    bool result = OH_UdmfData_HasType(data, UDMF_META_PLAIN_TEXT);
    // 获取OH_UdmfData类型列表
    unsigned int dataTypeIdCount = 0;
    char** typeIdsFromData = OH_UdmfData_GetTypes(data, &dataTypeIdCount);
    // 获取OH_UdmfData的记录
    unsigned int recordsCount = 0;
    OH_UdmfRecord** records = OH_UdmfData_GetRecords(data, &recordsCount);
    // 获取records中的元素
    for (int i = 0; i < recordsCount; i++) {
        // 获取OH_UdmfRecord类型列表
        unsigned int* recordTypeIdCount = 0;
        char** typeIdsFromRecord = OH_UdmfRecord_GetTypes(records[i], recordTypeIdCount);
        int returnStatus = Udmf_ErrCode::UDMF_E_OK;
        for (unsigned int j = 0; j < *recordTypeIdCount; j++) {
            // 获取OH_UdmfRecord自定义类型列表
            if (strcmp(typeIdsFromRecord[j], "demo.typeId")) {
                unsigned char* entryValue;
                unsigned int entryCount;
                returnStatus = OH_UdmfRecord_GetGeneralEntry(records[i], "demo.typeId", &entryValue, &entryCount);
            }
            // 从OH_UdmfRecord中获取纯文本类型数据
            if (strcmp(typeIdsFromRecord[j], UDMF_META_PLAIN_TEXT)) {
                OH_UdsPlainText* plainTextValue = OH_UdsPlainText_Create();
                returnStatus = OH_UdmfRecord_GetPlainText(records[i], plainTextValue);
                // 使用结束后销毁指针
                OH_UdsPlainText_Destroy(plainTextValue);
            }
            // 从OH_UdmfRecord中获取超链接类型数据
            if (strcmp(typeIdsFromRecord[j], UDMF_META_HYPERLINK)) {
                OH_UdsHyperlink* hyperlinkValue = OH_UdsHyperlink_Create();
                returnStatus = OH_UdmfRecord_GetHyperlink(records[i], hyperlinkValue);
                // 使用结束后销毁指针
                OH_UdsHyperlink_Destroy(hyperlinkValue);
            }
            // 从OH_UdmfRecord中获取HTML类型数据
            if (strcmp(typeIdsFromRecord[j], UDMF_META_HTML)) {
                OH_UdsHtml* htmlValue = OH_UdsHtml_Create();
                returnStatus = OH_UdmfRecord_GetHtml(records[i], htmlValue);
                // 使用结束后销毁指针
                OH_UdsHtml_Destroy(htmlValue);
            }
            // 从OH_UdmfRecord中获取appItem类型数据
            if (strcmp(typeIdsFromRecord[j], UDMF_META_OPENHARMONY_APP_ITEM)) {
                OH_UdsAppItem* appItemValue = OH_UdsAppItem_Create();
                returnStatus = OH_UdmfRecord_GetAppItem(records[i], appItemValue);
                // 使用结束后销毁指针
                OH_UdsAppItem_Destroy(appItemValue);
            }
        }
    }
    // 销毁指针
    OH_UdmfData_Destroy(data);
   ```

3. 获取UDMF proerties相关接口实现。示例代码如下所示：

   ```c
    // 创建OH_UdmfData对象
    OH_UdmfData* data = OH_UdmfData_Create();
    // 根据OH_UdmfData获取OH_UdmfProperty
    OH_UdmfProperty* property = OH_UdmfProperty_Create(data);
    // 获取OH_UdmfProperty中tag
    const char* tag = OH_UdmfProperty_GetTag(property);
    // 获取OH_UdmfProperty中时间戳
    int64_t timestamp = OH_UdmfProperty_GetTimestamp(property);
    // 获取OH_UdmfProperty中shareOption
    Udmf_ShareOption shareOption = OH_UdmfProperty_GetShareOption(property);
    // 获取OH_UdmfProperty中整型类型键值对
    int intValue = OH_UdmfProperty_GetExtrasIntParam(property, "intKey", -1);
    // 获取OH_UdmfProperty中字符类型键值对
    const char* charValue = OH_UdmfProperty_GetExtrasStringParam(property, "charKey");
    // 设置OH_UdmfProperty中tag
    int returnStatus = OH_UdmfProperty_SetTag(property, "tag");
    // 设置OH_UdmfProperty中shareOption
    returnStatus = OH_UdmfProperty_SetShareOption(property, Udmf_ShareOption::SHARE_OPTIONS_CROSS_APP);
    // 设置OH_UdmfProperty中整型类型键值对
    returnStatus = OH_UdmfProperty_SetExtrasIntParam(property, "intKey", 100);
    // 设置OH_UdmfProperty中字符类型键值对
    const char value[] = "value";
    returnStatus = OH_UdmfProperty_SetExtrasStringParam(property, "charKey", value);
    // 销毁指针
    OH_UdmfProperty_Destroy(property);
    OH_UdmfData_Destroy(data);
   ```

4. UDFM读、写数据。示例代码如下所示：

   ```c
    // 创建OH_UdmfData对象
    OH_UdmfData* data = OH_UdmfData_Create();
    // 构建数据，将数据写入数据库中
    char* key = new char[UDMF_KEY_BUFFER_LEN];
    int returnStatus = OH_Udmf_SetUnifiedData(Udmf_Intention::UDMF_INTENTION_DRAG, data, key, sizeof(key));
    // 从数据库中读取数据
    OH_UdmfData* readData = OH_UdmfData_Create();
    returnStatus = OH_Udmf_GetUnifiedData(key, Udmf_Intention::UDMF_INTENTION_DRAG, data);
    // 销毁指针
    delete[] key;
    OH_UdmfData_Destroy(data);
    OH_UdmfData_Destroy(readData);
   ```

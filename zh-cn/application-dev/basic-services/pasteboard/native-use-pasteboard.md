# 使用剪贴板进行复制粘贴 (C/C++)

## 场景介绍

剪贴板为开发者提供数据的复制粘贴能力。支持对纯文本、超文本、URI等内容的操作。

## 基本概念

- **OH_PasteboardObserver**：剪贴板数据变更观察者对象，用以监听剪贴板数据变更事件。
- **OH_Pasteboard**：剪贴板对象，用来进行查询、写入等操作。
- **OH_UdmfData**：统一数据对象，详见[UDMF开发指导 (C/C++)](../../database/native-unified-data-management-framework-guidelines.md)。

## 约束限制

- 剪贴板内容包含剪贴板系统服务元数据和应用设置的数据，总大小上限默认为128MB，PC/2in1设备可通过系统配置修改上限，有效范围为128MB~2GB。
- 为保证剪贴板数据的准确性，同一时间只能支持一个复制操作。
- 当前支持的数据类型：纯文本类型(OH_UdsPlainText)、超文本标记语言类型(OH_UdsHtml)、文件Uri类型(OH_UdsFileUri)、像素图片类型(OH_UdsPixelMap)、超链接类型(OH_UdsHyperlink)、桌面图标类型(OH_UdsAppItem)、自定义类型。JS接口与NDK接口支持数据类型不完全一致，使用时须匹配接口支持类型，详情见[JS接口与NDK接口数据类型对应关系](../pasteboard/use_pasteboard_to_copy_and_paste.md)。
- 自定义类型数据在复制粘贴时，指定的类型名称不能和已有的类型名称重复。
- API version 12及之后，系统为提升用户隐私安全保护能力，剪贴板读取接口增加[权限管控](get-pastedata-permission-guidelines.md)。
- API version 12中新增的复制、粘贴接口[setUnifiedData](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#setunifieddata12)/[getUnifiedData](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getunifieddata12)，和本文档中的复制、粘贴接口`OH_Pasteboard_SetData`/`OH_Pasteboard_GetData`，当前相互独立，进行写入、读取操作时请使用对应配套接口。

## 接口说明

详细接口见[Pasteboard文档](../../reference/apis-basic-services-kit/_pasteboard.md)。

| 接口名称                                                     | 描述                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------- |
| OH_PasteboardObserver* OH_PasteboardObserver_Create()        | 创建一个剪贴板数据变更观察者对象。                      |
| OH_PasteboardObserver_Destroy(OH_PasteboardObserver* observer) | 销毁剪贴板数据变更观察者对象。                          |
| int OH_PasteboardObserver_SetData(OH_PasteboardObserver* observer, void* context, const Pasteboard_Notify callback, const Pasteboard_Finalize finalize) | 将剪贴板变更回调函数设置到剪贴板数据变更观察者对象中。  |
| OH_Pasteboard* OH_Pasteboard_Create()                        | 创建一个剪贴板实例。                                    |
| void OH_Pasteboard_Destroy(OH_Pasteboard* pasteboard)        | 销毁剪贴板实例。                                        |
| int OH_Pasteboard_Subscribe(OH_Pasteboard* pasteboard, int type, const OH_PasteboardObserver* observer) | 订阅剪贴板的数据变更。                                  |
| int OH_Pasteboard_Unsubscribe(OH_Pasteboard* pasteboard, int type, const OH_PasteboardObserver* observer) | 取消对剪贴板数据变更的订阅。                            |
| bool OH_Pasteboard_IsRemoteData(OH_Pasteboard* pasteboard)   | 判断剪贴板中的数据是否来自远端设备。                    |
| int OH_Pasteboard_GetDataSource(OH_Pasteboard* pasteboard, char* source, unsigned int len) | 获取剪贴板中数据的数据源。                              |
| bool OH_Pasteboard_HasType(OH_Pasteboard* pasteboard, const char* type) | 判断剪贴板中是否有指定类型的数据。                      |
| bool OH_Pasteboard_HasData(OH_Pasteboard* pasteboard)        | 检查剪贴板中是否有数据。                                |
| OH_UdmfData* OH_Pasteboard_GetData(OH_Pasteboard* pasteboard, int* status) | 获取剪贴板中的数据。                                    |
| int OH_Pasteboard_SetData(OH_Pasteboard* pasteboard, OH_UdmfData* data) | 向剪贴板中写入数据。                                    |
| int OH_Pasteboard_ClearData(OH_Pasteboard* pasteboard)       | 清空剪贴板中的数据。                                    |
| void (\*Pasteboard_Notify)(void\* context, Pasteboard_NotifyType type) | 剪贴板中数据变更回调函数。                              |
| void (\*Pasteboard_Finalize)(void\* context)                 | 剪贴板数据变更观察者对象销毁时，释放context上下文资源。 |

## 开发步骤

1. 添加动态链接库。

   ```CMake
   # CMakeLists.txt中添加以下lib
   libudmf.so
   libpasteboard.so
   ```

2. 引用头文件。

   ```c
   #include <cstdio>
   #include <database/pasteboard/oh_pasteboard.h>
   #include <database/udmf/udmf.h>
   #include <database/udmf/uds.h>
   ```

3. 定义剪贴板变化监听的回调函数。

   ```c
   // 定义剪贴板数据内容变更时的通知回调函数
   static void Pasteboard_Notify_impl2(void* context, Pasteboard_NotifyType type)
   {
     printf("Pasteboard_NotifyType, type: %d", type);
   }
   // 定义剪贴板数据变更观察者对象销毁时的通知回调函数
   static void Pasteboard_Finalize_impl2(void* context)
   {
     printf("callback: Pasteboard_Finalize");
   }
   ```

4. 订阅剪贴板变化。

   ```c
   // 1. 创建一个剪贴板实例
   OH_Pasteboard* pasteboard = OH_Pasteboard_Create();
   // 2. 创建一个剪贴板数据变更观察者实例
   OH_PasteboardObserver* observer = OH_PasteboardObserver_Create();
   // 3. 将两个回调函数设置到观察者实例
   OH_PasteboardObserver_SetData(observer, (void* )pasteboard, Pasteboard_Notify_impl2, Pasteboard_Finalize_impl2);
   // 4. 设置对剪贴板本端数据变化的订阅
   OH_Pasteboard_Subscribe(pasteboard, NOTIFY_LOCAL_DATA_CHANGE, observer);
   ```

5. 向剪贴板写入数据。

   ```c
   // 1. 创建一个剪贴板实例
   OH_Pasteboard* pasteboard = OH_Pasteboard_Create();
   
   // 2. 创建OH_UdmfRecord对象，并向OH_UdmfRecord中添加文本类型数据
   OH_UdsPlainText* plainText = OH_UdsPlainText_Create();
   OH_UdsPlainText_SetContent(plainText, "Hello world!");
   OH_UdmfRecord* record = OH_UdmfRecord_Create();
   OH_UdmfRecord_AddPlainText(record, plainText);
   
   // 3. 创建OH_UdmfData对象，并向OH_UdmfData中添加OH_UdmfRecord
   OH_UdmfData* data = OH_UdmfData_Create();
   OH_UdmfData_AddRecord(data, record);
   
   // 4. 将数据写入剪贴板
   OH_Pasteboard_SetData(pasteboard, data);
   
   // 5. 使用完销毁指针
   OH_UdsPlainText_Destroy(plainText);
   OH_UdmfRecord_Destroy(record);
   OH_UdmfData_Destroy(data);
   OH_Pasteboard_Destroy(pasteboard);
   ```

6. 从剪贴板读取数据。

   ```c
   // 1. 创建一个剪贴板实例
   OH_Pasteboard* pasteboard = OH_Pasteboard_Create();
   // 2. 判断剪贴板中是否有文本类型数据
   bool hasPlainTextData = OH_Pasteboard_HasType(pasteboard, "text/plain");
   if (hasPlainTextData) {
     // 3. 从剪贴板中获取统一类型数据OH_UdmfData
     int ret = 0;
     OH_UdmfData* udmfData = OH_Pasteboard_GetData(pasteboard, &ret);
     // 4. 从OH_UdmfData中获取第一个数据记录
     OH_UdmfRecord* record = OH_UdmfData_GetRecord(udmfData, 0);
     // 5. 从数据记录中获取文本数据内容
     OH_UdsPlainText* plainText = OH_UdsPlainText_Create();
     OH_UdmfRecord_GetPlainText(record, plainText);
     const char* content = OH_UdsPlainText_GetContent(plainText);
     printf("Get plain text success. content: %s", content);
     // 5. 使用完销毁指针
     OH_UdsPlainText_Destroy(plainText);
     OH_UdmfData_Destroy(udmfData);
   }
   OH_Pasteboard_Destroy(pasteboard);
   ```

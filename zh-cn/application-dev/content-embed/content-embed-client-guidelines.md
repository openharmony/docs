# 客户端应用开发

<!--Kit: Content Embed Kit-->
<!--Subsystem: officeservice -->
<!--Owner: @qq_41146650-->
<!--Designer: @gcw_nDnzjzHO;@wei-guoning-->
<!--Tester: @sd_yinjian-->
<!--Adviser: @jinqiuheng-->

## 场景介绍

[OH_ContentEmbed](../reference/apis-content-embed-kit/capi-contentembed.md)内容嵌入模块提供对象编辑框架与技术，支持应用间文档嵌入与协同编辑。

OE客户端应用指嵌入其他文档的应用，通过调用OE框架层[content_embed_proxy.h](../reference/apis-content-embed-kit/capi-content-embed-proxy-h.md)提供的接口实现嵌入外部文档、展示文档快照，以及按需启动OE服务端应用编辑文档的功能。

典型应用场景包括：
- 在CAD文档中嵌入Excel表格，通过点击嵌入对象启动Excel应用进行编辑。
- 在文档编辑器中嵌入图片、表格等多种格式的文档。
- 在笔记应用中嵌入其他应用的文档，实现跨应用协作。

## 约束限制
在使用接口前，需先确认设备具备SystemCapability.ContentEmbed.ObjectEditor系统能力，判断方式请参阅[canIUse()](../reference/common/syscap__ndk_8h.md#caniuse)接口查询指定的系统能力是否被支持。并申请ohos.permission.CONNECT_OBJECTEDITOR_EXTENSION权限，配置方式请参阅[声明权限](../security/AccessToken/declare-permissions.md)。

## 接口说明

常用接口如下表所示。更多API说明请参考[OH_ContentEmbed](../reference/apis-content-embed-kit/capi-contentembed.md)。

**表1** 客户端主要接口

| 接口名称 | 功能描述 |
| ------- | ---- |
| OH_ContentEmbed_CreateDocumentByFile | 通过被嵌入文档路径创建[OE文档](content-embed-kit-terminology.md#oe文档)。|
| OH_ContentEmbed_CreateDocumentByOEId | 通过[OEID](content-embed-kit-terminology.md#oeid)创建OE文档。|
| OH_ContentEmbed_LoadDocumentFromFile | 通过已存在的[OE格式文件](content-embed-kit-terminology.md#oe格式文件)加载OE文档。|
| OH_ContentEmbed_CreateExtensionProxy | 创建[客户端OE对象](content-embed-kit-terminology.md#客户端oe对象)。|
| OH_ContentEmbed_DestroyExtensionProxy | 销毁客户端OE对象，释放相关资源。|
| OH_ContentEmbed_Proxy_RegisterOnUpdateFunc | 向客户端OE对象注册OE文档更新时的回调函数。|
| OH_ContentEmbed_Proxy_RegisterOnErrorFunc | 向客户端OE对象注册OE文档触发错误时的回调函数。|
| OH_ContentEmbed_Proxy_RegisterOnEditingFinishedFunc | 向客户端OE对象注册OE文档编辑完成时的回调函数。|
| OH_ContentEmbed_Proxy_RegisterOnExtensionStoppedFunc | 向客户端OE对象注册[OE Extension](content-embed-kit-terminology.md#oe-extension)停止时的回调函数。|
| OH_ContentEmbed_Proxy_StartWork | 客户端通过客户端OE对象与Object Editor服务跨进程通信，启动OE Extension组件，并创建服务端OE对象。|
| OH_ContentEmbed_Proxy_StopWork | 客户端通过客户端OE对象与Object Editor服务跨进程通信，销毁服务端OE对象，释放资源。|
| OH_ContentEmbed_Proxy_GetSnapshot | 从客户端OE对象获取当前OE文档的快照图像，用于预览或缩略图显示。|
| OH_ContentEmbed_Proxy_DoEdit | 客户端通过客户端OE对象与OE Extension组件跨进程通信，通知服务端启动UIAbility编辑OE文档。|
| OH_ContentEmbed_Proxy_GetDocument | 从客户端OE对象获取其关联的OE文档对象。|
| OH_ContentEmbed_Document_Read | 从OE文档中读取OE格式文件数据，存入buffer。|
| OH_ContentEmbed_DestroyDocument | 销毁OE文档对象，释放资源。|

## 开发步骤

以下演示使用Native API开发OE客户端应用的完整流程。

### 添加动态链接库
CMakeLists.txt中添加以下lib。

```text
# content embed
libcontent_embed_ndk.so
# hilog
libhilog_ndk.z.so
# ace
libace_napi.z.so
# piexlmap
libpixelmap.so
```

### 引用头文件

```cpp
#include <string>
#include <ContentEmbedKit/content_embed/content_embed_common.h>
#include <ContentEmbedKit/content_embed/content_embed_document.h>
#include <ContentEmbedKit/content_embed/content_embed_proxy.h>
#include <hilog/log.h>
#include <multimedia/image_framework/image/pixelmap_native.h>
```

### 查询当前设备支持的可嵌入文档信息

查询当前设备在指定语言下支持的所有可嵌入文档的信息。

```cpp
void QueryAllFormat(const std::string &locale)
{
    ContentEmbed_Info* contentEmbedInfo = nullptr;
    // 创建ContentEmbedInfo
    ContentEmbed_ErrorCode errCode = OH_ContentEmbed_CreateContentEmbedInfo(&contentEmbedInfo);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_CreateContentEmbedInfo failed, errCode: %{public}d.", errCode);
        return;
    }
    // 获取locale语言的ContentEmbedInfo信息
    errCode = OH_ContentEmbed_GetContentEmbedInfo(locale.c_str(), contentEmbedInfo);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_GetContentEmbedInfo failed, errCode: %{public}d.", errCode);
        // 查询失败销毁ContentEmbedInfo对象
        OH_ContentEmbed_DestroyContentEmbedInfo(contentEmbedInfo);
        return;
    }
    uint32_t count = 0;
    // 获取ContentEmbedInfo对象Format对象数量
    errCode = OH_ContentEmbed_GetFormatCountFromInfo(contentEmbedInfo, &count);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_GetFormatCountFromInfo failed, errCode: %{public}d.", errCode);
        // 查询失败销毁ContentEmbedInfo对象
        OH_ContentEmbed_DestroyContentEmbedInfo(contentEmbedInfo);
        return;
    }
    for (int i = 0; i < count; i++) {
        ContentEmbed_Format* ceFormat = nullptr;
        // 从ContentEmbedInfo对象获取索引为i的ContentEmbed_Format信息
        errCode = OH_ContentEmbed_GetFormatFromInfo(contentEmbedInfo, i, &ceFormat);
        if (errCode != CE_ERR_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_GetFormatFromInfo failed, errCode: %{public}d.", errCode);
            continue;
        }
        char oeid[MAX_OEID_LENGTH];
        // 获取OEID
        errCode = OH_ContentEmbed_GetOEidFromFormat(ceFormat, oeid);
        if (errCode != CE_ERR_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_GetOEidFromFormat failed, errCode: %{public}d.", errCode);
            continue;
        }
        char name[MAX_NAME_LENGTH];
        char description[MAX_DESCRIPTION_LENGTH];
        // 获取名称和描述
        errCode = OH_ContentEmbed_GetNameAndDescriptionFromFormat(ceFormat, name, description);
        if (errCode != CE_ERR_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_GetNameAndDescriptionFromFormat failed, errCode: %{public}d.", errCode);
            continue;
        }
        OH_PixelmapNative* pixelMap = nullptr;
        // 获取图标
        errCode = OH_ContentEmbed_GetIconFromFormat(ceFormat, &pixelMap);
        if (errCode != CE_ERR_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_GetIconFromFormat failed, errCode: %{public}d.", errCode);
            continue;
        }
        unsigned int count = 0;
        // 获取文件后缀
        char **fileNameExtensions = OH_ContentEmbed_GetFileNameExtensionsFromFormat(ceFormat, &count);
        if (fileNameExtensions == nullptr) {
            OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_GetFileNameExtensionsFromFormat failed");
            continue;
        }
    }
    // 销毁ContentEmbedInfo对象
    OH_ContentEmbed_DestroyContentEmbedInfo(contentEmbedInfo);
}
```

### 查询OEID对应的格式信息

```cpp
void QueryFormatByOEid(const std::string &oeid, const std::string &locale)
{
    ContentEmbed_Format* ceFormat = nullptr;
    // 创建ContentEmbed_Format
    ContentEmbed_ErrorCode errCode = OH_ContentEmbed_CreateContentEmbedFormat(&ceFormat);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_CreateContentEmbedFormat failed, errCode: %{public}d.", errCode);
        return;
    }
    errCode = OH_ContentEmbed_GetContentEmbedFormatByOEidAndLocale(oeid.c_str(), locale.c_str(), ceFormat);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_GetContentEmbedFormatByOEidAndLocale failed, errCode: %{public}d.", errCode);
        // 查询失败销毁ContentEmbed_Format对象
        OH_ContentEmbed_DestroyContentEmbedFormat(ceFormat);
        return;
    }
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    // 获取名称和描述
    errCode = OH_ContentEmbed_GetNameAndDescriptionFromFormat(ceFormat, name, description);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_GetNameAndDescriptionFromFormat failed, errCode: %{public}d.", errCode);
        return;
    }
    OH_PixelmapNative* pixelMap = nullptr;
    // 获取图标
    errCode = OH_ContentEmbed_GetIconFromFormat(ceFormat, &pixelMap);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_GetIconFromFormat failed, errCode: %{public}d.", errCode);
        return;
    }
    unsigned int count = 0;
    // 获取文件后缀
    char **fileNameExtensions = OH_ContentEmbed_GetFileNameExtensionsFromFormat(ceFormat, &count);
    if (fileNameExtensions == nullptr) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_GetFileNameExtensionsFromFormat failed");
        return;
    }
}
```

### 创建OE文档

1. 基于OEID创建OE文档

   ```cpp
   void CreateDocumentByOEid(const std::string &oeid)
   {
       ContentEmbed_Document* ceDocument = nullptr;
       // 基于OEID创建OE文件
       ContentEmbed_ErrorCode errCode = OH_ContentEmbed_CreateDocumentByOEid(oeid.c_str(), &ceDocument);
   }
   ```

2. 基于文件创建OE文档

   ```cpp
   void CreateDocumentByFile(std::string filePath)
   {
       // 基于文件创建OE文档
       ContentEmbed_Document *ceDocument = nullptr;
       // 是否以链接形式创建OE文档，当isLinking为true时，表示以链接方式创建OE文档；当isLinking为false时，表示以嵌入方式创建OE文档。
       bool isLinking = false;
       ContentEmbed_ErrorCode ret = OH_ContentEmbed_CreateDocumentByFile(filePath.c_str(), filePath.size(), isLinking, &ceDocument);
   }
   ```

3. 基于[OE格式文件](content-embed-kit-terminology.md#oe格式文件)加载OE文档，当OE格式文件为数据流存储时需先落盘至本地再使用此接口。

   ```cpp
   void LoadDocumentFromFile(std::string oeFormatFilePath)
   {
       ContentEmbed_Document *ceDocument = nullptr;
       // 基于OE格式文件
       ContentEmbed_ErrorCode ret = OH_ContentEmbed_LoadDocumentFromFile(oeFormatFilePath.c_str(), oeFormatFilePath.size(), &ceDocument);
   }
   ```

### 创建客户端OE对象

基于OE文档和当前上下文实例创建客户端OE对象，实现OE文档与客户端OE对象的关联，并用于与服务端通信。

```cpp
void ClientCallBack_OnUpdateFunc(ContentEmbed_ExtensionProxy *proxy)
{
    OH_LOG_INFO(LOG_APP, "Enter ClientCallBack_OnUpdateFunc");
    // 将OE文档数据写入客户端应用文档
    ContentEmbed_Document *document = nullptr;
    ContentEmbed_ErrorCode errCode = OH_ContentEmbed_Proxy_GetDocument(proxy, &document);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_Proxy_GetDocument failed, errCode: %{public}d.", errCode);
        return;
    }
    bool isLinking = false;
    ContentEmbed_ErrorCode ret = OH_ContentEmbed_Document_IsLinking(document, &isLinking);
    OH_LOG_INFO(LOG_APP, "ret: %{public}d, isLinking: %{public}d", ret, isLinking);
    if (ret == CE_ERR_OK && isLinking) {
        OH_LOG_INFO(LOG_APP, "linking document, No need to save to the sandbox");
        return;
    }
    const size_t CHUNK_SIZE = 4096; // 分块大小
    uint8_t *buffer = new (std::nothrow) uint8_t[CHUNK_SIZE + 1];
    if (!buffer)
        return;
    size_t offset = 0;
    size_t actualRead = 0;
    do {
        // 读取OE文档内容
        ret = OH_ContentEmbed_Document_Read(buffer, CHUNK_SIZE, document, offset, &actualRead);

        if (ret != CE_ERR_OK || actualRead == 0)
            break;

        // 自行处理buffer数据流
        // ...
        offset += actualRead;
    } while (true);

    delete[] buffer;
}

void ClientCallBack_OnErrorFunc(ContentEmbed_ExtensionProxy *proxy, ContentEmbed_ErrorCode error)
{
    OH_LOG_INFO(LOG_APP, "Enter ClientCallBack_OnErrorFunc, error: %{public}d", error);
}

void ClientCallBack_OnEditingFinishedFunc(ContentEmbed_ExtensionProxy *proxy, bool dataModified)
{
    OH_LOG_INFO(LOG_APP, "Enter ClientCallBack_OnEditingFinishedFunc, dataModified: %{public}d", dataModified);
    // 建议此时销毁OE文档和客户端OE对象，释放资源。
    ContentEmbed_Document *document = nullptr;
    ContentEmbed_ErrorCode errCode = OH_ContentEmbed_Proxy_GetDocument(proxy, &document);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_Proxy_GetDocument failed, errCode: %{public}d.", errCode);
        return;
    }
    // 销毁OE文档
    OH_ContentEmbed_DestroyDocument(document);
    // 销毁客户端OE对象
    OH_ContentEmbed_DestroyExtensionProxy(proxy);
}

void ClientCallBack_OnExtensionStoppedFunc(ContentEmbed_ExtensionProxy *proxy)
{
    OH_LOG_INFO(LOG_APP, "Enter ClientCallBack_OnExtensionStoppedFunc");
}

// contextPtr: 当前上下文实例
// oeDocument: OE文档
void CreateProxy(void* contextPtr, ContentEmbed_Document *oeDocument)
{
    ContentEmbed_ExtensionProxy* proxy;
    // 创建客户端OE对象
    ContentEmbed_ErrorCode errCode = OH_ContentEmbed_CreateExtensionProxy(oeDocument, &proxy, contextPtr);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_CreateExtensionProxy failed, errCode: %{public}d.", errCode);
        return;
    }
    // 注册回调：注册文档更新、错误、编辑结束等回调函数，回调函数注册顺序无要求，但不能遗漏。
    // 注册OE文档更新回调
    errCode = OH_ContentEmbed_Proxy_RegisterOnUpdateFunc(proxy, ClientCallBack_OnUpdateFunc);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_Proxy_RegisterOnUpdateFunc failed, errCode: %{public}d.", errCode);
        return;
    }
    // 注册OE文档发生错误回调
    errCode = OH_ContentEmbed_Proxy_RegisterOnErrorFunc(proxy, ClientCallBack_OnErrorFunc);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_Proxy_RegisterOnErrorFunc failed, errCode: %{public}d.", errCode);
        return;
    }
    // 注册OE文档编辑结束回调
    errCode = OH_ContentEmbed_Proxy_RegisterOnEditingFinishedFunc(proxy, ClientCallBack_OnEditingFinishedFunc);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_Proxy_RegisterOnEditingFinishedFunc failed, errCode: %{public}d.", errCode);
        return;
    }
    // 注册Extension实例关闭回调
    errCode = OH_ContentEmbed_Proxy_RegisterOnExtensionStoppedFunc(proxy, ClientCallBack_OnExtensionStoppedFunc);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_Proxy_RegisterOnExtensionStoppedFunc failed, errCode: %{public}d.", errCode);
        return;
    }
}
```

获取当前上下文实例。

```ts
// 获取UIAbility Context
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 调用Native接口，将Context传到C++侧处理
nativeModule.receiveContext(context);
```

```cpp
static napi_value ReceiveContext(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

    // 获取ArkTS传递的UIAbilityContext对象
    napi_value contextObj = argv[0];
    void* contextPtr = nullptr;
    napi_ref tmp = nullptr;
    // 创建强引用，引用计数+1，防止ArkTS垃圾回收把这个Context回收掉
    napi_create_reference(env, contextObj, 1, &tmp);
    // 把ArkTS对象解包为C++指针
    napi_status status = napi_unwrap(env, contextObj, &contextPtr);
  
    if (status != napi_ok || contextPtr == nullptr) {
        // 错误处理
        napi_throw_error(env, nullptr, "Failed to unwrap context");
        return nullptr;
    }
    // 记录contextPtr，后续使用
    // ...
    return nullptr;
}

// napi注册
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    napi_property_descriptor desc[] = {
        {"receiveContext", nullptr, ReceiveContext, nullptr, nullptr, nullptr, napi_default, nullptr},
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END
```

### 实现客户端OE对象和OE Extension交互

1. 启动OE Extension：启动OE Extension组件。
2. 查询OE Extension组件能力。
3. 编辑文档：通知OE服务端启动UIAbility编辑文档。
4. 查询OE文档编辑状态。
5. 获取OE文档快照。

```cpp
void HandleProxy(ContentEmbed_ExtensionProxy* proxy)
{
    ContentEmbed_ErrorCode errCode = CE_ERR_OK;
    // 启动OE Extension组件
    errCode = OH_ContentEmbed_Proxy_StartWork(proxy);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_Proxy_StartWork failed, errCode: %{public}d.", errCode);
        return;
    }
    uint32_t bitmask = 0;
    // 查询OE Extension组件能力
    errCode = OH_ContentEmbed_Proxy_GetCapability(proxy, &bitmask);
    if (errCode != CE_ERR_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_Proxy_GetCapability failed, errCode: %{public}d.", errCode);
        return;
    }
    if ((bitmask & CE_CAPABILITY_SUPPORT_DO_EDIT) != 0) {
        // 服务端支持编辑能力时，通知OE服务端编辑OE文档
        errCode = OH_ContentEmbed_Proxy_DoEdit(proxy);
        if (errCode != CE_ERR_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_ContentEmbed_Proxy_DoEdit failed, errCode: %{public}d.", errCode);
            return;
        }
    }
    // 主动查询OE文档的编辑状态
    bool isEditing = false;
    bool isModified = false;
    // 查询被嵌入文档编辑状态
    errCode = OH_ContentEmbed_Proxy_GetEditStatus(proxy, &isEditing, &isModified);
    if ((bitmask & CE_CAPABILITY_SUPPORT_SNAPSHOT) != 0) {
        // 服务端支持获取OE快照能力时，从OE服务端获取OE文档快照
        OH_PixelmapNative* pixelMap;
        // 获取OE文档快照
        errCode = OH_ContentEmbed_Proxy_GetSnapshot(proxy, &pixelMap);
    }
    // 当proxy不需要和服务端交互时
    OH_ContentEmbed_Proxy_StopWork(proxy);
}
```
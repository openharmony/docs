# 文件打印（C/C++）

<!--Kit: Basic Services Kit-->
<!--Subsystem: Print-->
<!--Owner: @guoshengbang-->
<!--Designer: @gcw_4D6e0BBd-->
<!--Tester: @guoshengbang-->
<!--Adviser: @RayShih-->

OS提供了两种打印方式：

[方式一](#3-方式一通过接口拉起系统打印预览界面下发任务)：应用通过接口拉起系统打印预览界面，传输渲染好的PDF文件进行打印任务下发。该方式适合有打印需求的应用使用系统能力快捷进行文件打印。

[方式二](#4-方式二通过打印接口自主进行打印设备的发现连接和打印任务的下发)：应用通过打印接口自主发现、连接打印设备并下发任务。该方式适合具有自己的打印预览界面的应用，可以通过接口打开打印设备发现、获取打印设备能力，构建打印预览界面需要的信息。

> **说明：**
>
> 使用打印服务，需[声明权限](../../security/AccessToken/declare-permissions.md)：ohos.permission.PRINT。
> 
> 当不再使用打印服务时，调用OH_Print_Release()释放打印客户端资源并取消事件订阅。

   

## 开发步骤

### 1. 引用头文件

```c++
#include <cstdint>
#include <cstdio>
#include <cwchar>
#include <vector>
#include <string>
#include "hilog/log.h"
#include "napi/native_api.h"
#include "BasicServicesKit/ohprint.h"
```

### 2. 在CMake脚本中添加动态链接库

```txt
target_link_libraries(entry PUBLIC
    libace_napi.z.so
    libhilog_ndk.z.so
    libohprint.so
)
```

### 3. 方式一：通过接口拉起系统打印预览界面下发任务

```ts
import { Context } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
    build() {
        Button("call native")
            .onClick(() => {
                let ctx = this.getUIContext().getHostContext();; // 获取 Ability 的 Context
                if (ctx === undefined) {
                    console.error('get fileUri or context failed');
                    return;
                }
                getContext(ctx);                                 // 传给 C++ 侧
            });
    }
}
```

```c++
// 使用系统打印下发打印任务
static void* context;
static char* currentJobId;

// 初始化打印服务
Print_ErrorCode ret = OH_Print_Init();

static napi_value getContext(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    // 假设 napi_get_cb_info 正常返回
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // 保存 context 于后续使用
    napi_status ret = napi_unwrap(env, argv[0], &context);
    return nullptr;
}

// 系统打印预览界面回调，首次拉起或用户修改打印参数时回调
static void StartLayoutWriteCb(const char *jobId,
                                uint32_t fd,
                                const Print_PrintAttributes *oldAttrs,
                                const Print_PrintAttributes *newAttrs,
                                Print_WriteResultCallback writeCallback)
{
    // 缓存任务Id，任务Id唯一
    currentJobId = jobId;
    // WriteFile 由开发者实现，获取当前用户修改前后的打印参数，渲染对应的打印文件写入fd。如黑白彩色，指定页码等。
    uint32_t retCode = WriteFile(fd, oldAttrs, newAttrs);
    // 通知打印系统文件写入完成
    writeCallback(jobId, retCode);
}

// 打印文件写入完成后，系统打印预览界面会进行预览，此时用户可以点击“开始打印”下发任务。
// 任务ID对应的打印状态变化的回调函数。
static void JobStateChangedCb(const char *jobId, uint32_t state)
{
    // 开发者根据任务id管理任务状态的逻辑
}

// 调用打印接口以拉起系统打印预览界面。
char printJobName[] = "fileName";
Print_PrintDocCallback printDocCallback = { StartLayoutWriteCb, JobStateChangedCb };
Print_ErrorCode ret = OH_Print_StartPrintByNative(printJobName, printDocCallback, context);

// 不再使用打印服务时释放资源
OH_Print_Release()
```

### 4. 方式二：通过打印接口自主进行打印设备的发现、连接和打印任务的下发

```c++
// 初始化打印服务
Print_ErrorCode ret = OH_Print_Init();

// 注册设备发现事件的回调，开始打印设备发现
static void PrinterDiscoveryCallback(Print_DiscoveryEvent event, const Print_PrinterInfo *printerInfo)
{
    // 发现一台打印设备，以设备Id作为唯一标识符
    if (printerInfo == nullptr) {
        OH_LOG_Print(LOG_APP, LOG_INFO, 0, "print c/c++", "printerInfo is nullptr");
        return;
    }
    // 开发者需根据具体业务场景实现以下回调逻辑
    switch (event) {
        // 发现打印设备事件
        case PRINTER_DISCOVERED:
            OnPrinterDiscovered(printerInfo);
            break;
        // 丢失打印设备事件
        case PRINTER_LOST:
            OnPrinterLost(printerInfo);
            break;
        // 打印机连接开始事件，由OH_Print_ConnectPrinter触发
        case PRINTER_CONNECTING:
            OnPrinterConnecting(printerInfo);
            break;
        // 打印机连接完成事件，由OH_Print_ConnectPrinter触发
        case PRINTER_CONNECTED:
            OnPrinterConnected(printerInfo);
            break;
        default:
            break;
    }
}
Print_PrinterDiscoveryCallback callback = PrinterDiscoveryCallback;
Print_ErrorCode ret = OH_Print_StartPrinterDiscovery(callback);

// 连接打印机，通过PrinterDiscoveryCallback获取到打印机属性，使用打印机ID进行连接
// 连接成功后会收到PRINTER_CONNECTED事件。
Print_ErrorCode ret = OH_Print_ConnectPrinter(printerInfo->printerId);

// 当不需要使用发现功能时，停止设备发现
Print_ErrorCode ret = OH_Print_StopPrinterDiscovery();

// 获取已添加的打印设备名称列表
Print_StringList addedPrinterList = {0};
Print_ErrorCode ret = OH_Print_QueryPrinterList(&addedPrinterList);
for (uint32_t index = 0; index < addedPrinterList.count; index++) {
    Print_PrinterInfo *printerInfo = nullptr;
    // 使用已添加的打印设备名称来获取打印设备属性。
    ret = OH_Print_QueryPrinterInfo(addedPrinterList[index], &printerInfo);
    // 业务代码
    // 打印设备属性使用完成后需要释放资源
    OH_Print_ReleasePrinterInfo(printerInfo);
}
// 在使用完打印设备名称列表后需要释放该列表资源。
OH_Print_ReleasePrinterList(&addedPrinterList);

// 下发打印任务
// 本例子使用默认选项 printerInfo->defaultValue 作为打印任务参数来下发任务。
std::vector<uint32_t> fdList = { 44, 45 };
Print_PrintJob* printJob = new Print_PrintJob{ jobName,
                                               fdList.data(),
                                               static_cast<uint32_t>(fdList.size()),
                                               printerInfo->printerId,
                                               1, // 打印份数
                                               printerInfo->defaultValue.defaultPaperSource,
                                               printerInfo->defaultValue.defaultMediaType,
                                               printerInfo->defaultValue.defaultPageSizeId,
                                               printerInfo->defaultValue.defaultColorMode,
                                               printerInfo->defaultValue.defaultDuplexMode,
                                               printerInfo->defaultValue.defaultResolution,
                                               printerInfo->defaultValue.defaultMargin,
                                               true,
                                               printerInfo->defaultValue.defaultOrientation,
                                               printerInfo->defaultValue.defaultPrintQuality,
                                               DOCUMENT_FORMAT_PDF,
                                               printerInfo->defaultValue.otherDefaultValues, };
Print_ErrorCode ret = OH_Print_StartPrintJob(printJob);
delete printJob;

// 不再使用打印服务时释放资源
OH_Print_Release()
```
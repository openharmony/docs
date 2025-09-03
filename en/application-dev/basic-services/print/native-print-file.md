# Printing Files (C/C++)

<!--Kit: Basic Services Kit-->
<!--Subsystem: Print-->
<!--Owner: @guoshengbang-->
<!--Designer: @gcw_4D6e0BBd-->
<!--Tester: @guoshengbang-->
<!--Adviser: @RayShih-->

The OS provides two printing methods:

[Method 1](#3-method-1-starting-the-print-preview-page-to-send-print-jobs): An application calls an API to start the system print preview page and sends a print job for the rendered PDF file to a printer. This method is suitable for applications that need to quickly print files using system capabilities.

[Method 2](#4-method-2-discovering-and-connecting-to-printers-to-send-print-jobs): An application calls the print APIs to discover and connect to printers and sends print jobs. This method is suitable for applications that have their own print preview pages. The applications can discover printers, obtain the printer capabilities, and construct a print job.

> **NOTE**
>
> To use the print service, declare the ohos.permission.PRINT permission. For details, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).
> 
> When the print service is no longer used, call **OH_Print_Release()** to release the print client resources and cancel event subscription.

   

## How to Develop

### 1. Including header files.

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

### 2. Adding dynamic link libraries to the CMake script.

```txt
target_link_libraries(entry PUBLIC
    libace_napi.z.so
    libhilog_ndk.z.so
    libohprint.so
)
```

### 3. Method 1: Starting the print preview page to send print jobs.

```ts
import { Context } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
    build() {
        Button("call native")
            .onClick(() => {
                let ctx = this.getUIContext().getHostContext();; // Obtain the context of the ability.
                if (ctx === undefined) {
                    console.error('get fileUri or context failed');
                    return;
                }
                getContext(ctx);                                 // Pass the context to the C++ side.
            });
    }
}
```

```c++
// Send the print task to the printer through system.
static void* context;
static char* currentJobId;

// Initialize the print service.
Print_ErrorCode ret = OH_Print_Init();

static napi_value getContext(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    // Assume that napi_get_cb_info is returned properly.
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // Save the context for future use.
    napi_status ret = napi_unwrap(env, argv[0], &context);
    return nullptr;
}

// Invoke the callback of the system print preview page when the page is started for the first time or the user changes the print parameters.
static void StartLayoutWriteCb(const char *jobId,
                                uint32_t fd,
                                const Print_PrintAttributes *oldAttrs,
                                const Print_PrintAttributes *newAttrs,
                                Print_WriteResultCallback writeCallback)
{
    // Cache the unique task ID.
    currentJobId = jobId;
    // Implement WriteFile() to obtain the print parameters before and after modification, render the file to be printed, and write data using a fd, for example, color mode or page number.
    uint32_t retCode = WriteFile(fd, oldAttrs, newAttrs);
    // Notify the system that the file has been written.
    writeCallback(jobId, retCode);
}

// After the file is written, the system displays the print preview page. You can click Print to send the print job.
// Callback used to listen for the print job state changes based on the task ID.
static void JobStateChangedCb(const char *jobId, uint32_t state)
{
    // Logic for managing the print job state based on the task ID.
}

// Call the print API to display the print preview page.
char printJobName[] = "fileName";
Print_PrintDocCallback printDocCallback = { StartLayoutWriteCb, JobStateChangedCb };
Print_ErrorCode ret = OH_Print_StartPrintByNative(printJobName, printDocCallback, context);

// Release resources when the print service is no longer used.
OH_Print_Release()
```

### 4. Method 2: Discovering and connecting to printers to send print jobs.

```c++
// Initialize the print service.
Print_ErrorCode ret = OH_Print_Init();

// Register the callback for the printer discovery event and start discovering printers.
static void PrinterDiscoveryCallback(Print_DiscoveryEvent event, const Print_PrinterInfo *printerInfo)
{
    // Discover a printer. The device ID is used as the unique identifier.
    if (printerInfo == nullptr) {
        OH_LOG_Print(LOG_APP, LOG_INFO, 0, "print c/c++", "printerInfo is nullptr");
        return;
    }
    // Implement the following callback logic based on the specific service scenario.
    switch (event) {
        // An event indicating that a printer is discovered.
        case PRINTER_DISCOVERED:
            OnPrinterDiscovered(printerInfo);
            break;
        // An event indicating that a printer is lost.
        case PRINTER_LOST:
            OnPrinterLost(printerInfo);
            break;
        // An event indicating that a printer is connecting, which is triggered by OH_Print_ConnectPrinter.
        case PRINTER_CONNECTING:
            OnPrinterConnecting(printerInfo);
            break;
        // An event indicating that a printer is connected, which is triggered by OH_Print_ConnectPrinter.
        case PRINTER_CONNECTED:
            OnPrinterConnected(printerInfo);
            break;
        default:
            break;
    }
}
Print_PrinterDiscoveryCallback callback = PrinterDiscoveryCallback;
Print_ErrorCode ret = OH_Print_StartPrinterDiscovery(callback);

// Obtain the printer properties through PrinterDiscoveryCallback and connect to the printer based on the printer ID.
// After the connection is successful, the PRINTER_CONNECTED event is received.
Print_ErrorCode ret = OH_Print_ConnectPrinter(printerInfo->printerId);

// Stop device discovery when this feature is not required.
Print_ErrorCode ret = OH_Print_StopPrinterDiscovery();

// Obtain the added printer list.
Print_StringList addedPrinterList = {0};
Print_ErrorCode ret = OH_Print_QueryPrinterList(&addedPrinterList);
for (uint32_t index = 0; index < addedPrinterList.count; index++) {
    Print_PrinterInfo *printerInfo = nullptr;
    // Obtain the printer properties using the name of an added printer.
    ret = OH_Print_QueryPrinterInfo(addedPrinterList[index], &printerInfo);
    // Service code.
    // Release resources after the printer properties are used.
    OH_Print_ReleasePrinterInfo(printerInfo);
}
// Release the added printer list.
OH_Print_ReleasePrinterList(&addedPrinterList);

// Send a print job.
// This example uses printerInfo->defaultValue as the print job parameter to send the task.
std::vector<uint32_t> fdList = { 44, 45 };
Print_PrintJob* printJob = new Print_PrintJob{ jobName,
                                               fdList.data(),
                                               static_cast<uint32_t>(fdList.size()),
                                               printerInfo->printerId,
                                               1, // Number of copies.
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

// Release resources when the print service is no longer used.
OH_Print_Release()
```

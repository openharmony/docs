# @ohos.print (Print)

<!--Kit: Basic Services Kit-->
<!--Subsystem: Print-->
<!--Owner: @guoshengbang-->
<!--Designer: @gcw_4D6e0BBd-->
<!--Tester: @guoshengbang-->
<!--Adviser: @RayShih-->

The **print** module provides APIs for basic print operations.

> **NOTE** 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { print } from '@kit.BasicServicesKit';
```

## PrintTask

Implements event listeners for print tasks.

### PrintTask.on

on(type: 'block', callback: Callback&lt;void&gt;): void

Registers a listener for the print task block event. This API uses a callback to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Listening type.<br>The value is fixed at **'block'**, indicating blocking of the print task. |
| callback | Callback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';
import { fileUri } from '@kit.CoreFileKit';

let filePath = '/data/storage/el2/base/haps/entry/files/test.pdf';
print.print([fileUri.getUriFromPath(filePath)]).then((printTask: print.PrintTask) => {
    printTask.on('block', () => {
        console.log('print state is block');
    })
    // ...
}).catch((error: BusinessError) => {
    console.error('print err ' + JSON.stringify(error));
})
```

### PrintTask.on

on(type: 'succeed', callback: Callback&lt;void&gt;): void

Registers a listener for the print task success event. This API uses a callback to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Listening type.<br>The value is fixed at **'succeed'**, indicating success of the print task. |
| callback | Callback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';
import { fileUri } from '@kit.CoreFileKit';

let filePath = '/data/storage/el2/base/haps/entry/files/test.pdf';
print.print([fileUri.getUriFromPath(filePath)]).then((printTask: print.PrintTask) => {
    printTask.on('succeed', () => {
        console.log('print state is succeed');
    })
    // ...
}).catch((error: BusinessError) => {
    console.error('print err ' + JSON.stringify(error));
})
```

### PrintTask.on

on(type: 'fail', callback: Callback&lt;void&gt;): void

Registers a listener for the print task failure event. This API uses a callback to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Listening type.<br>The value is fixed at **'fail'**, indicating failure of the print task. |
| callback | Callback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';
import { fileUri } from '@kit.CoreFileKit';

let filePath = '/data/storage/el2/base/haps/entry/files/test.pdf';
print.print([fileUri.getUriFromPath(filePath)]).then((printTask: print.PrintTask) => {
    printTask.on('fail', () => {
        console.log('print state is fail');
    })
    // ...
}).catch((error: BusinessError) => {
    console.error('print err ' + JSON.stringify(error));
})
```

### PrintTask.on

on(type: 'cancel', callback: Callback&lt;void&gt;): void

Registers a listener for the print task cancellation event. This API uses a callback to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Listening type.<br>The value is fixed at **'cancel'**, indicating cancellation of the print task. |
| callback | Callback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';
import { fileUri } from '@kit.CoreFileKit';

let filePath = '/data/storage/el2/base/haps/entry/files/test.pdf';
print.print([fileUri.getUriFromPath(filePath)]).then((printTask: print.PrintTask) => {
    printTask.on('cancel', () => {
        console.log('print state is cancel');
    })
    // ...
}).catch((error: BusinessError) => {
    console.error('print err ' + JSON.stringify(error));
})
```

### PrintTask.off

off(type: 'block', callback?: Callback&lt;void&gt;): void

Unregisters the listener for the print task block event. This API uses a callback to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Listening type.<br>The value is fixed at **'block'**, indicating blocking of the print task. |
| callback | Callback&lt;void&gt; | No| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';
import { fileUri } from '@kit.CoreFileKit';

let filePath = '/data/storage/el2/base/haps/entry/files/test.pdf';
print.print([fileUri.getUriFromPath(filePath)]).then((printTask: print.PrintTask) => {
    printTask.off('block', () => {
        console.log('unregister state block');
    })
    // ...
}).catch((error: BusinessError) => {
    console.error('print err ' + JSON.stringify(error));
})
```

### PrintTask.off

off(type: 'succeed', callback?: Callback&lt;void&gt;): void

Unregisters the listener for the print task success event. This API uses a callback to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Listening type.<br>The value is fixed at **'succeed'**, indicating success of the print task. |
| callback | Callback&lt;void&gt; | No| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';
import { fileUri } from '@kit.CoreFileKit';

let filePath = '/data/storage/el2/base/haps/entry/files/test.pdf';
print.print([fileUri.getUriFromPath(filePath)]).then((printTask: print.PrintTask) => {
    printTask.off('succeed', () => {
        console.log('unregister state succeed');
    })
    // ...
}).catch((error: BusinessError) => {
    console.error('print err ' + JSON.stringify(error));
})
```

### PrintTask.off

off(type: 'fail', callback?: Callback&lt;void&gt;): void

Unregisters the listener for the print task failure event. This API uses a callback to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Listening type.<br>The value is fixed at **'fail'**, indicating failure of the print task. |
| callback | Callback&lt;void&gt; | No| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';
import { fileUri } from '@kit.CoreFileKit';

let filePath = '/data/storage/el2/base/haps/entry/files/test.pdf';
print.print([fileUri.getUriFromPath(filePath)]).then((printTask: print.PrintTask) => {
    printTask.off('fail', () => {
        console.log('unregister state fail');
    })
    // ...
}).catch((error: BusinessError) => {
    console.error('print err ' + JSON.stringify(error));
})
```

### PrintTask.off

off(type: 'cancel', callback?: Callback&lt;void&gt;): void

Unregisters the listener for the print task cancellation event. This API uses a callback to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Listening type.<br>The value is fixed at **'cancel'**, indicating cancellation of the print task. |
| callback | Callback&lt;void&gt; | No| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';
import { fileUri } from '@kit.CoreFileKit';

let filePath = '/data/storage/el2/base/haps/entry/files/test.pdf';
print.print([fileUri.getUriFromPath(filePath)]).then((printTask: print.PrintTask) => {
    printTask.off('cancel', () => {
        console.log('unregister state cancel');
    })
    // ...
}).catch((error: BusinessError) => {
    console.error('print err ' + JSON.stringify(error));
})
```

## PrintDocumentAdapter<sup>11+</sup>

Provides information about the document to print. This API must be implemented by a third-party application.

### onStartLayoutWrite

onStartLayoutWrite(jobId: string, oldAttrs: PrintAttributes, newAttrs: PrintAttributes, fd: number, writeResultCallback: (jobId: string, writeResult: PrintFileCreationState) => void): void

Sends an empty PDF file descriptor to a third-party application. The third-party application updates the file with the new print attributes and then calls **writeResultCallback** to print the file.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobId | string | Yes| ID of the print job.|
| oldAttrs | [PrintAttributes](#printattributes11) | Yes| Old print attributes.|
| newAttrs | [PrintAttributes](#printattributes11) | Yes| New print attributes.|
| fd | number | Yes| PDF file descriptor sent to the API caller.|
| writeResultCallback | (jobId: string, writeResult: [PrintFileCreationState](#printfilecreationstate11)) => void | Yes| Callback used to print the updated file.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

class MyPrintDocumentAdapter implements print.PrintDocumentAdapter {
    onStartLayoutWrite(jobId: string, oldAttrs: print.PrintAttributes, newAttrs: print.PrintAttributes, fd: number,
        writeResultCallback: (jobId: string, writeResult: print.PrintFileCreationState) => void) {
        writeResultCallback(jobId, print.PrintFileCreationState.PRINT_FILE_CREATED);
    };
    onJobStateChanged(jobId: string, state: print.PrintDocumentAdapterState) {
        if (state == print.PrintDocumentAdapterState.PREVIEW_DESTROY) {
            console.log('PREVIEW_DESTROY');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_SUCCEED) {
            console.log('PRINT_TASK_SUCCEED');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_FAIL) {
            console.log('PRINT_TASK_FAIL');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_CANCEL) {
            console.log('PRINT_TASK_CANCEL');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_BLOCK) {
            console.log('PRINT_TASK_BLOCK');
        }
    }
}
```

### onJobStateChanged

onJobStateChanged(jobId: string, state: PrintDocumentAdapterState): void

Registers a listener for print job state changes.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobId | string | Yes| ID of the print job.|
| state | [PrintDocumentAdapterState](#printdocumentadapterstate11) | Yes| New state of the print job.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

class MyPrintDocumentAdapter implements print.PrintDocumentAdapter {
    onStartLayoutWrite(jobId: string, oldAttrs: print.PrintAttributes, newAttrs: print.PrintAttributes, fd: number,
        writeResultCallback: (jobId: string, writeResult: print.PrintFileCreationState) => void) {
        writeResultCallback(jobId, print.PrintFileCreationState.PRINT_FILE_CREATED);
    };
    onJobStateChanged(jobId: string, state: print.PrintDocumentAdapterState) {
        if (state == print.PrintDocumentAdapterState.PREVIEW_DESTROY) {
            console.log('PREVIEW_DESTROY');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_SUCCEED) {
            console.log('PRINT_TASK_SUCCEED');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_FAIL) {
            console.log('PRINT_TASK_FAIL');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_CANCEL) {
            console.log('PRINT_TASK_CANCEL');
        } else if (state == print.PrintDocumentAdapterState.PRINT_TASK_BLOCK) {
            console.log('PRINT_TASK_BLOCK');
        }
    }
}
```

## print.print

print(files: Array&lt;string&gt;, callback: AsyncCallback&lt;PrintTask&gt;): void

Prints files. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| files | Array&lt;string&gt; | Yes| List of files to print. Images (in .jpg, .png, .gif, .bmp, or .webp format) and PDF files are supported. You should save the files to the application sandbox, obtain the sandbox URI through **fileUri.getUriFromPath**, and then pass this URI as a parameter to this API.|
| callback | AsyncCallback&lt;[PrintTask](#printtask)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';
import { fileUri } from '@kit.CoreFileKit';

// Pass in the URIs of the files.
let filePath = '/data/storage/el2/base/haps/entry/files/test.pdf';
print.print([fileUri.getUriFromPath(filePath)], (err: BusinessError, printTask: print.PrintTask) => {
    if (err) {
        console.error('print err ' + JSON.stringify(err));
    } else {
        printTask.on('succeed', () => {
            console.log('print state is succeed');
        })
        // ...
    }
})
```

## print.print

print(files: Array&lt;string&gt;): Promise&lt;PrintTask&gt;

Prints files. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| files | Array&lt;string&gt; | Yes| List of files to print. Images (in .jpg, .png, .gif, .bmp, or .webp format) and PDF files are supported. You should save the files to the application sandbox, obtain the sandbox URI through **fileUri.getUriFromPath**, and then pass this URI as a parameter to this API.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;[PrintTask](#printtask)&gt; | Print result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';
import { fileUri } from '@kit.CoreFileKit';

// Pass in the URIs of the files.
let filePath = '/data/storage/el2/base/haps/entry/files/test.pdf';
print.print([fileUri.getUriFromPath(filePath)]).then((printTask: print.PrintTask) => {
    printTask.on('succeed', () => {
        console.log('print state is succeed');
    })
    // ...
}).catch((error: BusinessError) => {
    console.error('print err ' + JSON.stringify(error));
})
```

## print.print<sup>11+</sup>

print(files: Array&lt;string&gt;, context: Context, callback: AsyncCallback&lt;PrintTask&gt;): void

Prints files. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| files | Array&lt;string&gt; | Yes| List of files to print. Images (in .jpg, .png, .gif, .bmp, or .webp format) and PDF files are supported. You should save the files to the application sandbox, obtain the sandbox URI through **fileUri.getUriFromPath**, and then pass this URI as a parameter to this API.|
| context | Context | Yes| UIAbilityContext used to start the system print UI.|
| callback | AsyncCallback&lt;[PrintTask](#printtask)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';
import { fileUri } from '@kit.CoreFileKit';

@Entry
@Component
struct Index {
    build() {
        Scroll() {
            Column({ space: 10 }) {
                Button("Print").width('90%').height(50).onClick(() => {
                    let filePath = '/data/storage/el2/base/haps/entry/files/test.pdf';
                    let context = this.getUIContext().getHostContext();
                    print.print([fileUri.getUriFromPath(filePath)], context, (err: BusinessError, printTask: print.PrintTask) => {
                        if (err) {
                            console.error('print err ' + JSON.stringify(err));
                        } else {
                            printTask.on('succeed', () => {
                                console.log('print state is succeed');
                            })
                            // ...
                        }
                    })
                })
            }
            .justifyContent(FlexAlign.Center)
            .constraintSize({ minHeight: '100%' })
            .width('100%')
        }
        .height('100%')
    }
}
```

## print.print<sup>11+</sup>

print(files: Array&lt;string&gt;, context: Context): Promise&lt;PrintTask&gt;

Prints files. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| files | Array&lt;string&gt; | Yes| List of files to print. Images (in .jpg, .png, .gif, .bmp, or .webp format) and PDF files are supported. You should save the files to the application sandbox, obtain the sandbox URI through **fileUri.getUriFromPath**, and then pass this URI as a parameter to this API.|
| context | Context | Yes| UIAbilityContext used to start the system print UI.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;[PrintTask](#printtask)&gt; | Print result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';
import { fileUri } from '@kit.CoreFileKit';

@Entry
@Component
struct Index {
    build() {
        Scroll() {
            Column({ space: 10 }) {
                Button("Print").width('90%').height(50).onClick(() => {
                    let filePath = '/data/storage/el2/base/haps/entry/files/test.pdf';
                    let context = this.getUIContext().getHostContext();
                    print.print([fileUri.getUriFromPath(filePath)], context).then((printTask: print.PrintTask) => {
                        printTask.on('succeed', () => {
                            console.log('print state is succeed');
                        })
                        // ...
                    }).catch((error: BusinessError) => {
                        console.error('print err ' + JSON.stringify(error));
                    })
                })
            }
            .justifyContent(FlexAlign.Center)
            .constraintSize({ minHeight: '100%' })
            .width('100%')
        }
        .height('100%')
    }
}
```

## print.print<sup>11+</sup>

print(jobName: string, printAdapter: PrintDocumentAdapter, printAttributes: PrintAttributes, context: Context): Promise&lt;PrintTask&gt;

Prints a file. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| jobName | string | Yes| Name of the file to print, for example, **test.pdf**. The printer uses the [onStartLayoutWrite](#onstartlayoutwrite) API to send the **fd** of the empty PDF file to the API caller. The API caller uses the new print attributes to update the file to print.|
| printAdapter | [PrintDocumentAdapter](#printdocumentadapter11) | Yes| [PrintDocumentAdapter](#printdocumentadapter11) API instance implemented by a third-party application.|
| printAttributes | [PrintAttributes](#printattributes11) | Yes| Print attributes.|
| context | Context | Yes| UIAbilityContext used to start the system print UI.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;[PrintTask](#printtask)&gt; | Print result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

@Entry
@Component
struct Index {
    build() {
        Scroll() {
            Column({ space: 10 }) {
                Button("Print").width('90%').height(50).onClick(() => {
                    let jobName : string = "jobName";
                    let printAdapter : print.PrintDocumentAdapter | null = null;
                    let printAttributes : print.PrintAttributes = {
                        copyNumber: 1,
                        pageRange: {
                            startPage: 0,
                            endPage: 5,
                            pages: []
                        },
                        pageSize: print.PrintPageType.PAGE_ISO_A3,
                        directionMode: print.PrintDirectionMode.DIRECTION_MODE_AUTO,
                        colorMode: print.PrintColorMode.COLOR_MODE_MONOCHROME,
                        duplexMode: print.PrintDuplexMode.DUPLEX_MODE_NONE
                    }
                    let context = this.getUIContext().getHostContext();

                    print.print(jobName, printAdapter, printAttributes, context).then((printTask: print.PrintTask) => {
                        printTask.on('succeed', () => {
                            console.log('print state is succeed');
                        })
                        // ...
                    }).catch((error: BusinessError) => {
                        console.error('print err ' + JSON.stringify(error));
                    })
                })
            }
            .justifyContent(FlexAlign.Center)
            .constraintSize({ minHeight: '100%' })
            .width('100%')
        }
        .height('100%')
    }
}
```

## PrintAttributes<sup>11+</sup>

Defines the print attributes.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| copyNumber | number | No| Number of printed file copies. The default value is **1**.|
| pageRange | [PrintPageRange](#printpagerange11) | No| Page range of the file to print.|
| pageSize | [PrintPageSize](#printpagesize11) \| [PrintPageType](#printpagetype11) | No| Page size of the file to print.|
| directionMode | [PrintDirectionMode](#printdirectionmode11) | No| Print direction mode.|
| colorMode | [PrintColorMode](#printcolormode11) | No| Color mode of the files to print.|
| duplexMode | [PrintDuplexMode](#printduplexmode11) | No| Duplex mode of the files to print.|

## PrintPageRange<sup>11+</sup>

Defines the print range.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| startPage | number | No| Start page. The default value is **1**.|
| endPage | number | No| End page. The default value is the maximum number of pages of the file to be printed.|
| pages | Array&lt;number&gt; | No| Page range set of the file to print. The default value is empty.|


## PrintPageSize<sup>11+</sup>

Defines the size of the printed page.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| id | string | Yes| Paper size ID.|
| name | string | Yes| Paper size name.|
| width | number | Yes| Page width, in millimeters.|
| height | number | Yes| Page height, in millimeters.|



## PrintDirectionMode<sup>11+</sup>

Enumerates the print direction modes.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| DIRECTION_MODE_AUTO | 0 | Automatic.|
| DIRECTION_MODE_PORTRAIT | 1 | Portrait mode.|
| DIRECTION_MODE_LANDSCAPE | 2 | Landscape mode.|

## PrintColorMode<sup>11+</sup>

Enumerates the color modes.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| COLOR_MODE_MONOCHROME | 0 | Black and white.|
| COLOR_MODE_COLOR | 1 | Color.|

## PrintDuplexMode<sup>11+</sup>

Enumerates the duplex modes.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| DUPLEX_MODE_NONE | 0 | Simplex (single-sided).|
| DUPLEX_MODE_LONG_EDGE | 1 | Duplex (double-sided) with flipping on long edge.|
| DUPLEX_MODE_SHORT_EDGE | 2 | Duplex (double-sided) with flipping on short edge.|

## PrintPageType<sup>11+</sup>

Enumerates the print page types.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| PAGE_ISO_A3 | 0 | A3.|
| PAGE_ISO_A4 | 1 | A4.|
| PAGE_ISO_A5 | 2 | A5.|
| PAGE_JIS_B5 | 3 | B5.|
| PAGE_ISO_C5 | 4 | C5.|
| PAGE_ISO_DL | 5 | DL.|
| PAGE_LETTER | 6 | Letter.|
| PAGE_LEGAL | 7 | Legal.|
| PAGE_PHOTO_4X6 | 8 | 4 x 6 photo paper.|
| PAGE_PHOTO_5X7 | 9 | 5 x 7 photo paper.|
| PAGE_INT_DL_ENVELOPE | 10 | International envelope DL.|
| PAGE_B_TABLOID | 11 | B Tabloid.|

## PrintDocumentAdapterState<sup>11+</sup>

Enumerates the print job states.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| PREVIEW_DESTROY | 0 | The preview fails.|
| PRINT_TASK_SUCCEED | 1 | The print job is successful.|
| PRINT_TASK_FAIL | 2 | The print job is failed.|
| PRINT_TASK_CANCEL | 3 | The print job is canceled.|
| PRINT_TASK_BLOCK | 4 | The print job is blocked.|

## PrintFileCreationState<sup>11+</sup>

Enumerates the print file creation status.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| PRINT_FILE_CREATED | 0 | The print file is created successfully.|
| PRINT_FILE_CREATION_FAILED | 1 | The print file fails to be created.|
| PRINT_FILE_CREATED_UNRENDERED | 2 | The print file is successfully created but not rendered.|

## PrinterState<sup>14+</sup>

Enumerates the printer states.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| PRINTER_ADDED | 0 | A new printer is added.|
| PRINTER_REMOVED | 1 | The printer is removed.|
| PRINTER_CAPABILITY_UPDATED | 2 | The printer is updated.|
| PRINTER_CONNECTED | 3 | The printer is connected.|
| PRINTER_DISCONNECTED | 4 | The printer is disconnected.|
| PRINTER_RUNNING | 5 | The printer is running.|

## PrintJobState<sup>14+</sup>

Enumerates the print job states.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| PRINT_JOB_PREPARE | 0 | The printer is prepared for the print job.|
| PRINT_JOB_QUEUED | 1 | The print job is on the print queue of the printer.|
| PRINT_JOB_RUNNING | 2 | The print job is being executed.|
| PRINT_JOB_BLOCKED | 3 | The print job is blocked.|
| PRINT_JOB_COMPLETED | 4 | The print job is complete.|

## PrintJobSubState<sup>14+</sup>

Enumerates the print job substates.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| PRINT_JOB_COMPLETED_SUCCESS | 0 | The print job is successful.|
| PRINT_JOB_COMPLETED_FAILED | 1 | The print job is failed.|
| PRINT_JOB_COMPLETED_CANCELLED | 2 | The print job is canceled by user.|
| PRINT_JOB_COMPLETED_FILE_CORRUPTED | 3 | The print job is corrupted.|
| PRINT_JOB_BLOCK_OFFLINE | 4 | The printer is offline.|
| PRINT_JOB_BLOCK_BUSY | 5 | The printer is occupied by another process.|
| PRINT_JOB_BLOCK_CANCELLED | 6 | The print job is canceled due to a block.|
| PRINT_JOB_BLOCK_OUT_OF_PAPER | 7 | The printer is out of paper.|
| PRINT_JOB_BLOCK_OUT_OF_INK | 8 | The printer is out of ink.|
| PRINT_JOB_BLOCK_OUT_OF_TONER | 9 | The printer is out of toner.|
| PRINT_JOB_BLOCK_JAMMED | 10 | The printer is in a paper jam.|
| PRINT_JOB_BLOCK_DOOR_OPEN | 11 | The printer door is open.|
| PRINT_JOB_BLOCK_SERVICE_REQUEST | 12 | Print service request.|
| PRINT_JOB_BLOCK_LOW_ON_INK | 13 | The printer is low on ink.|
| PRINT_JOB_BLOCK_LOW_ON_TONER | 14 | The printer is low on toner.|
| PRINT_JOB_BLOCK_REALLY_LOW_ON_INK | 15 | The printer is extremely low on ink.|
| PRINT_JOB_BLOCK_BAD_CERTIFICATE | 16 | The print certificate is incorrect.|
| PRINT_JOB_BLOCK_DRIVER_EXCEPTION<sup>20+</sup> | 17 | The print driver is abnormal.|
| PRINT_JOB_BLOCK_ACCOUNT_ERROR | 18 | There is an error with the printer account.|
| PRINT_JOB_BLOCK_PRINT_PERMISSION_ERROR | 19 | There is an error with the printer permission.|
| PRINT_JOB_BLOCK_PRINT_COLOR_PERMISSION_ERROR | 20 | There is an error with the color printing permission.|
| PRINT_JOB_BLOCK_NETWORK_ERROR | 21 | The printer fails to connect to the network.|
| PRINT_JOB_BLOCK_SERVER_CONNECTION_ERROR | 22 | The printer fails to connect to the server.|
| PRINT_JOB_BLOCK_LARGE_FILE_ERROR | 23 | There is an error with a large file printing.|
| PRINT_JOB_BLOCK_FILE_PARSING_ERROR | 24 | There is an error with file parsing.|
| PRINT_JOB_BLOCK_SLOW_FILE_CONVERSION | 25 | The file conversion is slow.|
| PRINT_JOB_RUNNING_UPLOADING_FILES | 26 | The file is uploading.|
| PRINT_JOB_RUNNING_CONVERTING_FILES | 27 | The file is converting.|
| PRINT_JOB_BLOCK_FILE_UPLOADING_ERROR<sup>18+</sup> | 30 | The file fails to be uploaded.|
| PRINT_JOB_BLOCK_DRIVER_MISSING<sup>20+</sup> | 34 | The print driver is missing.|
| PRINT_JOB_BLOCK_INTERRUPT<sup>20+</sup> | 35 | The print job is interrupted.|
| PRINT_JOB_BLOCK_PRINTER_UNAVAILABLE<sup>20+</sup> | 98 | The printer is unavailable.|
| PRINT_JOB_BLOCK_UNKNOWN | 99 | There is an unknown error with the printer.|

## PrintErrorCode<sup>14+</sup>

Enumerates the print error codes.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| E_PRINT_NONE | 0 | No error.|
| E_PRINT_NO_PERMISSION | 201 | No permission.|
| E_PRINT_INVALID_PARAMETER | 401 | Invalid parameters.|
| E_PRINT_GENERIC_FAILURE | 13100001 | Printing failure.|
| E_PRINT_RPC_FAILURE | 13100002 | RPC failure.|
| E_PRINT_SERVER_FAILURE | 13100003 | Print service failure.|
| E_PRINT_INVALID_EXTENSION | 13100004 | Invalid printer extension.|
| E_PRINT_INVALID_PRINTER | 13100005 | Invalid printer.|
| E_PRINT_INVALID_PRINT_JOB | 13100006 | Invalid print job.|
| E_PRINT_FILE_IO | 13100007 | Incorrect file input/output.|
| E_PRINT_TOO_MANY_FILES<sup>18+</sup> | 13100010 | Excessive files. Maximum number: 99.|

## ApplicationEvent<sup>14+</sup>

Enumerates print application events.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| APPLICATION_CREATED | 0 | Starts the print application.|
| APPLICATION_CLOSED_FOR_STARTED | 1 | Closes the print application by clicking **Start**.|
| APPLICATION_CLOSED_FOR_CANCELED | 2 | Closes the print application by clicking **Cancel**.|

## print.addPrinterToDiscovery<sup>14+</sup>

addPrinterToDiscovery(printerInformation: PrinterInformation): Promise&lt;void&gt;

Adds a printer to the printer discovery list. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerInformation | [PrinterInformation](#printerinformation14) | Yes| The added printer.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Result of adding a printer to the printer discovery list.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerInformation : print.PrinterInformation = {
    printerId : 'testPrinterId',
    printerName : 'testPrinterName',
    printerStatus : 0,
    description : 'testDesc',
    uri : 'testUri',
    printerMake : 'testPrinterMake',
    options : 'testOps'
};
print.addPrinterToDiscovery(printerInformation).then(() => {
    console.log('addPrinterToDiscovery success');
}).catch((error: BusinessError) => {
    console.error('addPrinterToDiscovery error : ' + JSON.stringify(error));
})
```

## print.updatePrinterInDiscovery<sup>14+</sup>

updatePrinterInDiscovery(printerInformation: PrinterInformation): Promise&lt;void&gt;

Updates the printer capabilities to the printer discovery list. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerInformation | [PrinterInformation](#printerinformation14) | Yes| Printer whose capability is to be updated.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Result of updating the printer capabilities to the printer discovery list.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let testPageSize : print.PrintPageSize = {
    id : 'ISO_A4',
    name : 'iso_a4_210x297mm',
    width : 8268,
    height : 11692
};

let testCapability : print.PrinterCapabilities = {
    supportedPageSizes : [testPageSize],
    supportedColorModes : [print.PrintColorMode.COLOR_MODE_MONOCHROME],
    supportedDuplexModes : [print.PrintDuplexMode.DUPLEX_MODE_NONE],
    supportedMediaTypes : ['stationery'],
    supportedQualities : [print.PrintQuality.QUALITY_NORMAL],
    supportedOrientations : [print.PrintOrientationMode.ORIENTATION_MODE_PORTRAIT],
    options : 'testOptions'
};

let printerInformation : print.PrinterInformation = {
    printerId : 'testPrinterId',
    printerName : 'testPrinterName',
    printerStatus : 0,
    description : 'testDesc',
    capability : testCapability,
    uri : 'testUri',
    printerMake : 'testPrinterMake',
    options : 'testOptions'
};
print.updatePrinterInDiscovery(printerInformation).then(() => {
    console.log('updatePrinterInDiscovery success');
}).catch((error: BusinessError) => {
    console.error('updatePrinterInDiscovery error : ' + JSON.stringify(error));
})
```

## print.removePrinterFromDiscovery<sup>14+</sup>

removePrinterFromDiscovery(printerId: string): Promise&lt;void&gt;

Removes a printer from the printer discovery list. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer to remove.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Result of removing a printer from the printer discovery list.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId : string = 'testPrinterId';
print.removePrinterFromDiscovery(printerId).then(() => {
    console.log('removePrinterFromDiscovery success');
}).catch((error: BusinessError) => {
    console.error('removePrinterFromDiscovery error : ' + JSON.stringify(error));
})
```

## print.getPrinterInformationById<sup>14+</sup>

getPrinterInformationById(printerId: string): Promise&lt;PrinterInformation&gt;

Obtains printer information based on the printer ID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID used to obtain information.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;[PrinterInformation](#printerinformation14)&gt; | Printer information obtained based on the printer ID.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId : string = 'testPrinterId';
print.getPrinterInformationById(printerId).then((printerInformation : print.PrinterInformation) => {
    console.log('getPrinterInformationById data : ' + JSON.stringify(printerInformation));
}).catch((error: BusinessError) => {
    console.error('getPrinterInformationById error : ' + JSON.stringify(error));
})
```

## PrinterInformation<sup>14+</sup>

Defines the printer information.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|
| printerName | string | Yes| Printer name.|
| printerStatus | [PrinterStatus](#printerstatus14) | Yes| Printer state.|
| description | string | No| Printer description.|
| capability | [PrinterCapabilities](#printercapabilities14) | No| Printer capabilities.|
| uri | string | No| Printer URI.|
| printerMake | string | No| Printer model.|
| preferences<sup>18+</sup> | [PrinterPreferences](#printerpreferences18) | No| Printer preferences.|
| alias<sup>18+</sup> | string | No| Printer alias.|
| options | string | No| Printer details.|

## PrinterCapabilities<sup>14+</sup>

Defines the printer capabilities.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| supportedPageSizes | Array&lt;[PrintPageSize](#printpagesize11)&gt; | Yes| List of paper sizes supported by the printer.|
| supportedColorModes | Array&lt;[PrintColorMode](#printcolormode11)&gt; | Yes| List of color modes supported by the printer.|
| supportedDuplexModes | Array&lt;[PrintDuplexMode](#printduplexmode11)&gt; | Yes| List of single- and double-sided modes supported by the printer.|
| supportedMediaTypes | Array&lt;string&gt; | No| List of paper types supported by the printer.|
| supportedQualities | Array&lt;[PrintQuality](#printquality14)&gt; | No| List of print quality supported by the printer.|
| supportedOrientations | Array&lt;[PrintOrientationMode](#printorientationmode14)&gt; | No| List of print directions supported by the printer.|
| options | string | No| Printer capability details.|

## PrintQuality<sup>14+</sup>

Enumerates the print qualities.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| QUALITY_DRAFT | 3 | Draft|
| QUALITY_NORMAL | 4 | Standard|
| QUALITY_HIGH | 5 | High|

## PrintOrientationMode<sup>14+</sup>

Enumerates the print directions.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| ORIENTATION_MODE_PORTRAIT | 0 | Portrait mode.|
| ORIENTATION_MODE_LANDSCAPE | 1 | Landscape mode.|
| ORIENTATION_MODE_REVERSE_LANDSCAPE | 2 | Reverse landscape mode.|
| ORIENTATION_MODE_REVERSE_PORTRAIT | 3 | Reverse portrait mode.|
| ORIENTATION_MODE_NONE | 4 | Adaptive mode.|

## PrinterStatus<sup>14+</sup>

Enumerates the printer states.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| PRINTER_IDLE | 0 | The printer is idle.|
| PRINTER_BUSY | 1 | The printer is busy.|
| PRINTER_UNAVAILABLE | 2 | The printer is unavailable.|

## PrinterPreferences<sup>18+</sup>

Defines the printer preferences.

**System capability**: SystemCapability.Print.PrintFramework

**Attributes**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| defaultDuplexMode | [PrintDuplexMode](#printduplexmode11) | No| Default duplex mode.|
| defaultPrintQuality | [PrintQuality](#printquality14) | No| Default print quality.|
| defaultMediaType | string | No| Default paper type.|
| defaultPageSizeId | string | No| ID of the default paper size. The value can be a standard paper size defined by the International Organization for Standardization (ISO), for example, ISO_A4, or a non-standard paper size defined in the system, for example, Custom.178 × 254 mm.|
| defaultOrientation | [PrintOrientationMode](#printorientationmode14) | No| Default print orientation.|
| borderless | boolean | No| Whether to print without margins. The value **true** means to print without margins, and **false** means the opposite. The default value is **false**.|
| options | string | No| Other fields in the printer preferences. The fields are queried from the printer or obtained from the printer driver and stored in the string in JSON format.|

## PrinterEvent<sup>18+</sup>

Enumerates printer-related events.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| PRINTER_EVENT_ADDED | 0 | Printer added.|
| PRINTER_EVENT_DELETED | 1 | Printer deleted.|
| PRINTER_EVENT_STATE_CHANGED | 2 | Printer state changed.|
| PRINTER_EVENT_INFO_CHANGED | 3 | Printer information changed.|
| PRINTER_EVENT_PREFERENCE_CHANGED | 4 | Printer preferences changed.|
| PRINTER_EVENT_LAST_USED_PRINTER_CHANGED | 5 | The last used printer changed.|

## DefaultPrinterType<sup>18+</sup>

Enumerates default printer types.

**System capability**: SystemCapability.Print.PrintFramework

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| DEFAULT_PRINTER_TYPE_SET_BY_USER | 0 | The printer set by the user serves as the default printer.|
| DEFAULT_PRINTER_TYPE_LAST_USED_PRINTER | 1 | The printer used last time serves as the default printer.|

## print.getAddedPrinters<sup>18+</sup>

getAddedPrinters(): Promise&lt;Array&lt;string&gt;&gt;

Obtains the list of printers added to the system. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB or ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.getAddedPrinters().then((printers: string[]) => {
    console.log('getAddedPrinters success ' + JSON.stringify(printers));
    // ...
}).catch((error: BusinessError) => {
    console.error('failed to getAddedPrinters because ' + JSON.stringify(error));
})
```

## PrinterChangeCallback<sup>18+</sup>

type PrinterChangeCallback = (event: PrinterEvent, printerInformation: PrinterInformation) => void

Defines a callback that takes the printer event and printer information as parameters.

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| event | [PrinterEvent](#printerevent18) | Yes| Printer event.|
| printerInformation | PrinterInformation | Yes| Printer information.|

## print.on<sup>18+</sup>

on(type: 'printerChange', callback: PrinterChangeCallback): void

Registers a listener for the printer change events.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | 'printerChange' | Yes| Printer change event.|
| callback | [PrinterChangeCallback](#printerchangecallback18) | Yes| Callback to be invoked when the printer changes.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';

// Trigger this callback when an added printer is changed.
let onPrinterChange =
    (event: print.PrinterEvent, printerInformation: print.PrinterInformation) => {
        console.log('printerChange, event: ' + event + ', printerInformation: ' + JSON.stringify(printerInformation));
    };
print.on('printerChange', onPrinterChange);
```

## print.off<sup>18+</sup>

off(type: 'printerChange', callback?: PrinterChangeCallback): void

Unregisters the listener for printer state change events. This API uses a callback to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | 'printerChange' | Yes| Printer change event.|
| callback | [PrinterChangeCallback](#printerchangecallback18) | No| Callback to unregister.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';

// Trigger this callback when an added printer is changed.
let onPrinterChange =
    (event: print.PrinterEvent, printerInformation: print.PrinterInformation) => {
        console.log('printerChange, event: ' + event + ', printerInformation: ' + JSON.stringify(printerInformation));
    };
print.on('printerChange', onPrinterChange);
print.off('printerChange');
```

## print.startDiscoverPrinter<sup>20+</sup>

startDiscoverPrinter(extensionList: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Discovers printers by specifying the extension list. The discovered printers contain the specified print extension abilities. If an empty extension list is specified, all extension abilities are loaded. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB or ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| extensionList | Array&lt;string&gt; | Yes| List of [PrintExtensionAbilities](./js-apis-app-ability-PrintExtensionAbility.md) to be loaded. The list members are the bundle names of the applications with print extension abilities. An empty list indicates that all extension abilities are loaded.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

// Load all print extension abilities.
let extensionList: string[] = [];
// Specify the bundle name of your applications to load required print extension abilities during printer discovery.
// let extensionList: string[] = ['com.myapplication.test'];
print.startDiscoverPrinter(extensionList, (err: BusinessError) => {
    if (err) {
        console.error('failed to start Discover Printer because : ' + JSON.stringify(err));
    } else {
        console.log('start Discover Printer success');
    }
})
```

## print.startDiscoverPrinter<sup>20+</sup>

startDiscoverPrinter(extensionList: Array&lt;string&gt;): Promise&lt;void&gt;

Discovers printers by specifying the extension list. The discovered printers contain the specified print extension abilities. If an empty extension list is specified, all extension abilities are loaded. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB or ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| extensionList | Array&lt;string&gt; | Yes| List of [PrintExtensionAbilities](./js-apis-app-ability-PrintExtensionAbility.md) to be loaded. The list members are the bundle names of the applications with print extension abilities. An empty list indicates that all extension abilities are loaded.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

// Load all print extension abilities.
let extensionList: string[] = [];
// Specify the bundle name of your applications to load required print extension abilities during printer discovery.
// let extensionList: string[] = ['com.myapplication.test'];
print.startDiscoverPrinter(extensionList).then(() => {
    console.log('start Discovery success');
}).catch((error: BusinessError) => {
    console.error('failed to start Discovery because : ' + JSON.stringify(error));
})
```

## print.stopDiscoverPrinter<sup>20+</sup>

stopDiscoverPrinter(callback: AsyncCallback&lt;void&gt;): void

Stops discovering printers. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB or ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.stopDiscoverPrinter((err: BusinessError) => {
    if (err) {
        console.error('failed to stop Discover Printer because : ' + JSON.stringify(err));
    } else {
        console.log('stop Discover Printer success');
    }
})
```

## print.stopDiscoverPrinter<sup>20+</sup>

stopDiscoverPrinter(): Promise&lt;void&gt;

Stops discovering printers. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB or ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

print.stopDiscoverPrinter().then(() => {
    console.log('stop Discovery success');
}).catch((error: BusinessError) => {
    console.error('failed to stop Discovery because : ' + JSON.stringify(error));
})
```

## print.connectPrinter<sup>20+</sup>

connectPrinter(printerId: string, callback: AsyncCallback&lt;void&gt;): void

Connects to a printer by printer ID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB or ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId: string = 'printerId_32';
print.connectPrinter(printerId, (err: BusinessError) => {
    if (err) {
        console.error('failed to connect Printer because : ' + JSON.stringify(err));
    } else {
        console.log('start connect Printer success');
    }
})
```

## print.connectPrinter<sup>20+</sup>

connectPrinter(printerId: string): Promise&lt;void&gt;

Connects to a printer by printer ID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_PRINT_JOB or ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| printerId | string | Yes| Printer ID.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; |Promise used to return the result.|

**Error codes**

For details about the error codes, see [Error Codes of the Print Service](./errorcode-print.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | the application does not have permission to call this function. |

**Example**

```ts
import { print } from '@kit.BasicServicesKit';
import { BusinessError } from '@ohos.base';

let printerId: string = 'printerId_32';
print.connectPrinter(printerId).then(() => {
    console.log('start connect Printer success');
}).catch((error: BusinessError) => {
    console.error('failed to connect Printer because : ' + JSON.stringify(error));
})
```

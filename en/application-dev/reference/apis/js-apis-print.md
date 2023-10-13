# @ohos.print (Print)

The **print** module provides APIs for basic print operations.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import print from '@ohos.print';
```

## PrintTask

Implements event listener APIs for print tasks.

### on

on(type: 'block' | 'succeed' | 'fail' | 'cancel', callback: Callback&lt;void&gt;): void

Registers a listener for a print task event. This API uses a callback to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Listening type.<br>The value can be **'block'**, **'succeed'**, **'fail'**, or **'cancel'**, indicating blocking, success, failure, or canceling of the print task, respectively. |
| callback | Callback&lt;void&gt; | Yes| Callback used to return the result.|

**Return value**

| **Type** | **Description** |
| -------- | -------- |
| Promise&lt;PrintTask&gt; | Print result. |

**Example**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let file = ['file://data/print/a.png', 'file://data/print/b.png'];
print.print(file).then((printTask: print.PrintTask) => {
  printTask.on('succeed', () => {
    console.log('print state is succeed');
  })
  printTask.on('block', () => {
    console.log('print state is block');
  })
  printTask.on('succeed', () => {
    console.log('print state is succeed');
  })
  printTask.on('fail', () => {
    console.log('print state is fail');
  })
  printTask.on('cancel', () => {
    console.log('print state is cancel');
  })
  // ...
}).catch((error: BusinessError) => {
  console.log('print err ' + JSON.stringify(error));
})
```

### off

off(type: 'block' | 'succeed' | 'fail' | 'cancel', callback?: Callback&lt;void&gt;): void

Unregisters the listener for a print task event. This API uses a callback to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Listening type.<br>The value can be **'block'**, **'succeed'**, **'fail'**, or **'cancel'**, indicating blocking, success, failure, or canceling of the print task, respectively. |
| callback | Callback&lt;void&gt; | No| Callback used to return the result.|

**Return value**

| **Type** | **Description** |
| -------- | -------- |
| Promise&lt;PrintTask&gt; | Print result. |

**Example**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

let file = ['file://data/print/a.png', 'file://data/print/b.png'];
print.print(file).then((printTask: print.PrintTask) => {
  printTask.off('succeed', () => {
    console.log('unregister state succeed');
  })
  printTask.off('block', () => {
    console.log('unregister state block');
  })
  printTask.off('succeed', () => {
    console.log('unregister state succeed');
  })
  printTask.off('fail', () => {
    console.log('unregister state fail');
  })
  printTask.off('cancel', () => {
    console.log('unregister state cancel');
  })
  // ...
}).catch((error: BusinessError) => {
  console.log('print err ' + JSON.stringify(error));
})
```

## print

print(files: Array&lt;string&gt;, callback: AsyncCallback&lt;PrintTask&gt;): void

Prints files. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| file | Array&lt;string&gt; | Yes| List of files to print. Image (in .jpg, .png, .gif, .bmp, or .webp format) and PDF files are supported.|
| callback | AsyncCallback&lt;PrintTask&gt; | Yes| Callback used to return the result.|

**Example**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

// Pass in the URIs of the files.
let file = ['file://data/print/a.png', 'file://data/print/b.png'];
// Alternatively, pass in the FDs.
// let file = ['fd://1', 'fd://2'];
print.print(file, (err: BusinessError, printTask: print.PrintTask) => {
  if (err) {
    console.log('print err ' + JSON.stringify(err));
  } else {
    printTask.on('succeed', () => {
      console.log('print state is succeed');
    })
    // ...
  }
})
```

## print

print(files: Array&lt;string&gt;): Promise&lt;PrintTask&gt;

Prints files. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PRINT

**System capability**: SystemCapability.Print.PrintFramework

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| file | Array&lt;string&gt; | Yes| List of files to print. Image and PDF files are supported.|

**Return value**
| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;PrintTask&gt; | Print result.|

**Example**

```ts
import print from '@ohos.print';
import { BusinessError } from '@ohos.base';

// Pass in the URIs of the files.
let file = ['file://data/print/a.png', 'file://data/print/b.png'];
// Alternatively, pass in the FDs.
// let file = ['fd://1', 'fd://2'];
print.print(file).then((printTask: print.PrintTask) => {
  printTask.on('succeed', () => {
    console.log('print state is succeed');
  })
  // ...
}).catch((error: BusinessError) => {
  console.log('print err ' + JSON.stringify(error));
})
```

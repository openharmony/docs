# Setting the Security Level of a Distributed File

The security capabilities vary with devices. For example, small embedded devices provide fewer security capabilities than tablets. The security requirements also vary with data. For example, personal health information and bank card information are not expected to be accessed by devices of lower security levels. OpenHarmony provides a complete set of data and device classification standards and supports customization of data transfer policies for different devices. For details, see [Access Control by Device and Data Level](../database/access-control-by-device-and-data-level.md).

## Available APIs

For details about APIs, see [ohos.file.securityLabel](../reference/apis-core-file-kit/js-apis-file-securityLabel.md).

Table 1 Security level APIs

| API| Description| Category| Synchronous Programming| Asynchronous Programming|
| -------- | -------- | -------- | -------- | -------- |
| setSecurityLabel | Sets a security level for a file.| Method| Supported| Supported|
| getSecurityLabel | Obtains the security level of a file.| Method| Supported| Supported|

> **NOTE**
>
> 1. In distributed networking, a device can view the files that have a higher security level but cannot access them.
>
> 2. The default security level of the distributed file system data is S3. Applications can set the security level of files.

## Development Example

Obtain the sandbox path of a file and set the data security level. For details about how to obtain the context, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).


```ts
import { securityLabel } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { fileIo as fs } from '@kit.CoreFileKit';

// Obtain the sandbox path of the file where the device data level is to be obtained. Ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;
let filePath = pathDir + '/test.txt';

// Open a file.
let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
// Set the data level of the file to S0.
securityLabel.setSecurityLabel(filePath, 's0').then(() => {
  console.info('Succeeded in setSecurityLabeling.');
  fs.closeSync(file);
}).catch((err: BusinessError) => {
  console.error(`Failed to setSecurityLabel. Code: ${err.code}, message: ${err.message}`);
});
```

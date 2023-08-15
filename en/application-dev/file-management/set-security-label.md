# Setting the Security Level of a Distributed File

The security capabilities vary with devices. For example, small embedded devices provide fewer security capabilities than tablets. The security requirements also vary with data. For example, personal health information and bank card information are not expected to be accessed by devices of lower security levels. OpenHarmony provides a complete set of data and device classification standards and custom data transfer policies for different devices. For details, see [Access Control by Device and Data Level](../database/access-control-by-device-and-data-level.md).

## Available APIs

For details about the APIs, see [ohos.file.securityLabel](../reference/apis/js-apis-file-securityLabel.md).

**Table 1** APIs

| API| Description| Type| Synchronous Programming| Asynchronous Programming|
| -------- | -------- | -------- | -------- | -------- |
| setSecurityLabel | Sets a security label for a file.| Method| √ | √ |
| getSecurityLabel | Obtains the security label of a file.| Method| √ | √ |

> **NOTE**
>
> - In distributed networking, a device can view the files that do not match its security level but cannot access them.
>
> - The default security level of the distributed file system data is S3. Applications can set the security level of files.

## Development Example

Obtain the sandbox path of a file and set the data security label. For details about how to obtain the context, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).


```ts
import securityLabel from '@ohos.file.securityLabel';

// Obtain the sandbox path of the file.
let context =...; // Obtain UIAbilityContext information.
let pathDir = context.filesDir;
let filePath = pathDir + '/test.txt';

// Set the data level of the file to S0.
securityLabel.setSecurityLabel(filePath, 's0').then(() => {
  console.info('Succeeded in setSecurityLabeling.');
}).catch((err) => {
  console.error(`Failed to setSecurityLabel. Code: ${err.code}, message: ${err.message}`);
});
```

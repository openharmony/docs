# Setting the Security Level of a Distributed File

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--Designer: @gsl_1234; @wangke25-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=96b6842378a3034d6245f6b77a19ff25d0ceba9c translatedAt=2026-08-01T07:28:02.467Z pushedAt=2026-08-01T11:17:50.362Z -->

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
> - In distributed networking, a device can view the files that have a higher security level but cannot access them.
>
> - The default security level of the distributed file system data is S3. Applications can set the security level of files.

## Development Example

Obtain the sandbox path of a file and set the data security level. For details about how to obtain the context, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

```ts
import { securityLabel } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { fileIo } from '@kit.CoreFileKit';

```

<!--@[set_security_label](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/FileApiFileSample/entry/src/main/ets/pages/Index.ets)-->    

``` TypeScript
// Obtain the sandbox path of the file where the device data level is to be obtained. Ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;
let filePath = pathDir + '/test.txt';

// Open the file.
let file: fileIo.File | null = null;
try {
  file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  // Set the data level of the file to s0.
  securityLabel.setSecurityLabel(filePath, 's0').then(() => {
    console.info('Succeeded in setting security label.');
    fileIo.closeSync(file);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set security label. Code: ${err.code}, message: ${err.message}`);
    if (file) {
      try {
        fileIo.closeSync(file);
      } catch (closeErr) {
        console.error(`Failed to close file`);
      }
    }
  });
} catch (err) {
  console.error(`Failed to open file. Code: ${err.code}, message: ${err.message}`);
  if (file) {
    try {
      fileIo.closeSync(file);
    } catch (closeErr) {
      console.error(`Failed to close file`);
    }
  }
}
```
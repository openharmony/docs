# Sharing an Application File

An application can share its file with another application based on the file descriptor (FD) or uniform resource identifier (URI) of the file. However, if the FD of a shared file is closed, the file is no longer opened. Therefore, the FD-based file sharing is not recommended. This section describes how to share an application file based on its URI.

- You can use [wantConstant.Flags](../reference/apis/js-apis-app-ability-wantConstant.md#wantconstantflags) to share a single application file in read or read/write mode based on its URI with another application. The target application can use **open()** of the [ohos.file.fs](../reference/apis/js-apis-file-fs.md#fsopen) module to open the URI and then perform read and/or write operations based on the permissions granted. OpenHarmony API version 9 supports only temporary authorization. The permission on the shared file is revoked once the target application exits.

- You can also use **open()** of the ohos.file.fs module to share a single application file with the specified permissions to another application based on the FD. After parsing the FD from **Want**, the target application can read and write the file by using **read()** and **write()** APIs of ohos.file.fs.

You can use the related APIs to [share a file with another application](#sharing-a-file-with-another-application) or [use shared application files](#using-shared-files).

## File URI Specifications

The file URIs are in the following format:

  **file**://&lt;*bundleName*&gt;/&lt;*path*&gt;

- **file**: indicates a file URI.

- *bundleName*: specifies the owner of the file.

- *path*: specifies the application sandbox path of the file.

## Sharing a File with Another Application

Before sharing application files, you need to [obtain the application file path](../application-models/application-context-stage.md#obtaining-application-file-paths).

1. Obtain the application sandbox path of the file and convert it into the file URI.

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility';
   import fileuri from '@ohos.file.fileuri';
   import window from '@ohos.window';
   
   export default class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage: window.WindowStage) {
       // Obtain the application sandbox path of the file.
       let pathInSandbox = this.context.filesDir + "/test.txt";
       // Convert the application sandbox path into a URI.
       let uri = fileuri.getUriFromPath(pathInSandbox);
       // The obtained URI is file://com.example.demo/data/storage/el2/base/files/test.txt.
     }
   }
   ```

2. Set the target application, with which you want to share the file, and grant permissions on the file.
   Use [startAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability) to share the file with the target application. You need to pass in the obtained URI in **uri** of the **want** parameter, set the type of the file to share, set **action** to **ohos.want.action.sendData**, and set the granted permission on the file in **flags**. For details, see [Want](../reference/apis/js-apis-app-ability-want.md#attributes).

   > **NOTE**
   >
   > The write permission granted includes the read permission.

   ```ts
   import fileuri from '@ohos.file.fileuri';
   import window from '@ohos.window';
   import wantConstant from '@ohos.app.ability.wantConstant';
   import UIAbility from '@ohos.app.ability.UIAbility';
   
   export default class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage: window.WindowStage) {
       // Obtain the application sandbox path of the file.
       let filePath = this.context.filesDir + '/test.txt';
       // Convert the application sandbox path into a URI.
       let uri = fileuri.getUriFromPath(filePath);
       let want = {
         // Grant the read and write permissions on the shared file to the target application.
         flags: wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION | wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
         // Set the implicit startup rule for the application that shares the file.
         action: 'ohos.want.action.sendData',
         uri: uri,
         type: 'text/plain'
       }
       this.context.startAbility(want)
         .then(() => {
           console.info('Invoke getCurrentBundleStats succeeded.');
         })
         .catch((err) => {
           console.error(`Invoke startAbility failed, code is ${err.code}, message is ${err.message}`);
         });
     }
   
     ...
   }
   ```

## Using Shared Files

In the [**module.json5** file](../quick-start/module-configuration-file.md) of the application, which wants to use the shared file, set **actions** to **ohos.want.action.sendData** to allow the application to receive files shared by another application and set **uris** to the type of the URI to receive. In the following example, the application receives only .txt files with **scheme** of **file**.

```json
{
  "module": {
    ...
    "abilities": [
      {
        ...
        "skills": [
          {
            ...
            "actions": [
              "ohos.want.action.sendData"
            ],
            "uris": [
              {
                "scheme": "file",
                "type": "text/plain"
              }
           ]
          }
        ]
      }
    ]
  }
}
```

After **UIAbility** of the application starts, the application obtains **want** information from [**onCreate()**](../reference/apis/js-apis-app-ability-uiAbility.md#uiabilityoncreate) or [**onNewWant()**](../reference/apis/js-apis-app-ability-uiAbility.md#uiabilityonnewwant).

After obtaining the URI of the shared file from **want**, the application can call **fs.open()** to open the file, and then read and write the file after obtaining the related file object.

```ts
// xxx.ets
import fs from '@ohos.file.fs';

function getShareFile() {
  try {
    let want =...; // Obtain the want information sent from the application that shares the file.

    // Obtain the uri field from the want information.
    let uri = want.uri;
    if (uri == null || uri == undefined) {
      console.info('uri is invalid');
      return;
    }
    try {
      // Perform operations on the URI of the shared file as required. For example, open the URI to obtain the file object in read/write mode.
      let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
      console.info('open file successfully!');
    } catch (error) {
      console.error(`Invoke openSync failed, code is ${error.code}, message is ${error.message}`);
    }
  } catch (error) {
    console.error(`Invoke openSync failed, code is ${error.code}, message is ${error.message}`);
  }
}
```

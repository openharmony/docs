# DLP Service Development

The Data Loss Prevention (DLP) service is a system solution provided to prevent leakage of sensitive data. It provides a file format called DLP. A DLP file consists of the original file in ciphertext and the authorization credential, and ".dlp" is added to the end of the original file name (including the file name extension), for example, **test.docx.dlp**.

A DLP file can be accessed only after a device-cloud authentication (network connection required) is successful. The permissions for accessing a DLP file include the following:

- Read-only: The user can only view the file.
- Edit: The user can read and write the file, but cannot change the permission on the file.
- Full control: The user can read and write the file, change the permission on the file, and restore the plaintext of the file.

When an app accesses a DLP file, the system automatically installs a DLP sandbox app for the app. As a twin app of the app, the sandbox app inherits data and configuration from the app, but is isolated from the app. The twin app is running in a DLP sandbox, which is restricted from external access to prevent data leakage. Each time a DLP file is opened, a sandbox app is generated. The sandbox apps are also isolated from each other. When an app is closed, its sandbox app will be automatically uninstalled and the temporary data generated in the sandbox directory will be cleared.

Normally, the app is unaware of the sandbox and accesses the file in plaintext, like accessing a common file. However, the DLP sandbox restricts the app from accessing external resources (such as the network, clipboard, screenshot capturing, screen recording, and Bluetooth). For better user experience, you need to make adaptation for your app. For example, for a read-only file, you'd better hide the **Save** button and disable automatic network connection.

## Sandbox Restrictions

For an app in the DLP sandbox state, the permissions granted to the app are restricted based on the permission on the DLP file.

| App Permission | Description | Read-Only | Edit/Full Control |
| -------- | -------- | -------- | -------- |
| ohos.permission.USE_BLUETOOTH | Allows an app to use Bluetooth. | Unavailable | Unavailable |
| ohos.permission.INTERNET |Allows an app to access the Internet. |  Unavailable | Unavailable |
| ohos.permission.DISTRIBUTED_DATASYNC | Allows an app to exchange user data (such as images, music, videos, and app data) with another device. | Unavailable | Unavailable |
| ohos.permission.WRITE_MEDIA | Allows an app to read and write media files, such as images, videos, and audio clips. | Unavailable | Available |
| ohos.permission.NFC_TAG | Allows an app to use NFC. | Unavailable | Available |

## Available APIs

| API | Description |
| -------- | -------- |
| isDLPFile(fd: number): Promise&lt;boolean&gt; <br> isDLPFile(fd: number, callback: AsyncCallback&lt;boolean&gt;): void| Checks whether a file is a DLP file. |
| getDLPPermissionInfo(): Promise&lt;DLPPermissionInfo&gt; <br>getDLPPermissionInfo(callback: AsyncCallback&lt;DLPPermissionInfo&gt;): void  | Obtains the DLP permission information of this sandbox app. |
| getOriginalFileName(fileName: string): string | Obtains the original name of a DLP file. |
| getDLPSuffix(): string | Obtains the file name extension of this DLP file. |
| on(type: 'openDLPFile', listener: Callback&lt;AccessedDLPFileInfo&gt;): void | Subscribes to the file open event of DLP files. The app will be notified when a DLP file is opened. |
| off(type: 'openDLPFile', listener?: Callback&lt;AccessedDLPFileInfo&gt;): void | Unsubscribes from the file open event of DLP files. |
| isInSandbox(): Promise&lt;boolean&gt; <br>isInSandbox(callback: AsyncCallback&lt;boolean&gt;): void | Checks whether this app is running in a sandbox. |
| getDLPSupportedFileTypes(): Promise&lt;Array&lt;string&gt;&gt;<br>getDLPSupportedFileTypes(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void | Obtains the file name extension types that can be appended with .dlp. |
| setRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt; <br> setRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void | Sets the sandbox app retention state. If the retention state is set for a DLP file, the sandbox app will not be automatically uninstalled when the DLP file is closed. |
| cancelRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt;<br> cancelRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void | Cancels the sandbox app retention state. |
| getRetentionSandboxList(bundleName?: string): Promise&lt;Array&lt;RetentionSandboxInfo&gt;&gt; <br> getRetentionSandboxList(bundleName: string, callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void  <br> getRetentionSandboxList(callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void| Obtains the sandbox apps in the retention state. |
| getDLPFileAccessRecords(): Promise&lt;Array&lt;AccessedDLPFileInfo&gt;&gt; <br> getDLPFileAccessRecords(callback: AsyncCallback&lt;Array&lt;AccessedDLPFileInfo&gt;&gt;): void | Obtains the DLP files that are accessed recently. |
|setSandboxAppConfig(configInfo: string): Promise&lt;void&gt;|Sets sandbox app configuration.|
|getSandboxAppConfig(): Promise&lt;string&gt;|Obtains the sandbox app configuration.|
|cleanSandboxAppConfig(): Promise&lt;void&gt;|Clears the sandbox app configuration.|
| startDLPManagerForResult(context: common.UIAbilityContext, want: Want): Promise&lt;DLPManagerResult&gt; <br> | Starts the DLP manager app on the current UIAbility page in borderless mode (available only for the stage model). |

## How to Develop

1. Import the [dlpPermission](../../reference/apis-data-protection-kit/js-apis-dlppermission.md) module.

   ```ts
   import { dlpPermission } from '@kit.DataProtectionKit';
   ```

2. Open a DLP file. The system automatically installs a DLP sandbox app for your app. <br>Add the following code to your app:

    ```ts
    async OpenDlpFile(dlpUri: string, fileName: string, fd: number) {
      let want:Want = {
        "action": "ohos.want.action.viewData",
        "bundleName": "com.example.example_bundle_name",
        "abilityName": "exampleAbility",
        "uri": dlpUri,
        "parameters": {
          "fileName": {
            "name": fileName
          },
          "keyFd": {
            "type": "FD",
            "value": fd
          }
        }
      }

      try {
        console.log('openDLPFile:' + JSON.stringify(want));
        console.log('openDLPFile: delegator:' + JSON.stringify(this.context));
        this.context.startAbility(want);
      } catch (err) {
        console.error('openDLPFile startAbility failed', (err as BusinessError).code, (err as BusinessError).message);
        return;
      }
    }
    ```

    Add **ohos.want.action.viewData** to the **module.json5** file.

    ```json
      "skills":[
        {
          "entities":[
            ...
          ],
          "actions":[
            ...
            "ohos.want.action.viewData"
          ]
        }
      ]
    ```

3. Check whether the app is running in a sandbox.

   ```ts
   dlpPermission.isInSandbox().then((data)=> {
     console.log('isInSandbox, result: ' + JSON.stringify(data));
   }).catch((err:BusinessError) => {
     console.log('isInSandbox: ' + JSON.stringify(err));
   });
   ```

4. Obtain the permissions on the file. The permissions of the DLP sandbox app vary with the user's permission on the file. For more information, see [Sandbox Restrictions](#sandbox-restrictions).

   ```ts
   dlpPermission.getDLPPermissionInfo().then((data)=> {
     console.log('getDLPPermissionInfo, result: ' + JSON.stringify(data));
   }).catch((err:BusinessError) => {
     console.log('getDLPPermissionInfo: ' + JSON.stringify(err));
   });
   ```

5. Obtain information about the file name extension types that support the DLP solution. Based on the information obtained, you can learn what types of files can be used to generate DLP files.

   ```ts
   dlpPermission.getDLPSupportedFileTypes((err, result) => {
     console.log('getDLPSupportedFileTypes: ' + JSON.stringify(err));
     console.log('getDLPSupportedFileTypes: ' + JSON.stringify(result));
   });
   ```

6. Check whether the opened file is a DLP file.

   ```ts
   import { dlpPermission } from '@kit.DataProtectionKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
   let file = fileIo.openSync(uri);
   try {
     let res = dlpPermission.isDLPFile(file.fd);  // Check whether the file is a DLP file.
     console.info('res', res);
   } catch (err) {
     console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
   }
   fileIo.closeSync(file);
   ```

7. Subscribe to or unsubscribe from the DLP file open event.

   ```ts
   event(info: dlpPermission.AccessedDLPFileInfo) {
     console.info('openDlpFile event', info.uri, info.lastOpenTime)
   }
   unSubscribe() {
     try {
       dlpPermission.off('openDLPFile', this.event); // Unsubscribe from the file open event.
     } catch (err) {
       console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
     }
   }
   subscribe() {
     try {
       dlpPermission.on ('openDLPFile' , this.event); // Subscribe to the DLP file open event.
     } catch (err) {
       console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
     }
   }
   onCreate() {
    this.subscribe();
   }
   onDestroy() {
    this.unSubscribe();
   }
   ```

8. Obtain information about the DLP files that are recently accessed.

   ```ts
   async getDLPFileAccessRecords() {
     try {
       let res:Array<dlpPermission.AccessedDLPFileInfo> = await dlpPermission.getDLPFileAccessRecords(); // Obtain the list of recently accessed DLP files.
       console.info('res', JSON.stringify(res))
     } catch (err) {
       console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
     }
   }
   ```

9. Obtain information about the DLP sandbox apps in the retention state.

    ```ts
    async getRetentionSandboxList() {
      try {
        let res:Array<dlpPermission.RetentionSandboxInfo> = await dlpPermission.getRetentionSandboxList(); // Obtain the sandbox apps in the retention state.
        console.info('res', JSON.stringify(res))
      } catch (err) {
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
      }
    }
    ```

10. Set sandbox app configuration.

    ```ts
    async setSandboxAppConfig() {
      try {
        await dlpPermission.setSandboxAppConfig('configInfo'); // Set sandbox app configuration.
      } catch (err) {
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
      }
    }
    ```

11. Clear the sandbox app configuration.

    ```ts
    async cleanSandboxAppConfig() {
      try {
        await dlpPermission.cleanSandboxAppConfig(); // Clear the sandbox app configuration.
      } catch (err) {
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
      }
    }
    ```

12. Obtain the sandbox app configuration.

    ```ts
    async getSandboxAppConfig() {
      try {
        let res:string = await dlpPermission.getSandboxAppConfig(); // Obtain the sandbox app configuration.
        console.info('res', JSON.stringify(res))
      } catch (err) {
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
      }
    }
    ```

13. Start the DLP manager app in borderless mode. This API can be called only in the UIAbility context and supports only the stage model.

    ```ts
    import { dlpPermission } from '@kit.DataProtectionKit';
    import { common, UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    try {
      let context = getContext () as common.UIAbilityContext; // Obtain the UIAbility context.
      let want: Want = {
        "uri": "file://docs/storage/Users/currentUser/Desktop/1.txt",
        "parameters": {
          "displayName": "1.txt"
        }
      }; // Request parameters.
      dlpPermission.startDLPManagerForResult(context, want).then((res) => {
        console.info('res.resultCode', res.resultCode);
        console.info('res.want', JSON.stringify(res.want));
      }); // Start the DLP manager app.
    } catch (err) {
      console.error('error', err.code, err.message); // Report an error upon a failure.
    }
    ```

14. Check whether the current system provides the DLP feature.
    ```ts
    import { dlpPermission } from '@kit.DataProtectionKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    dlpPermission.isDLPFeatureProvided().then((res) => {
      console.info('res', JSON.stringify(res));
    }).catch((err: BusinessError) => {
      console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
    });
    ```

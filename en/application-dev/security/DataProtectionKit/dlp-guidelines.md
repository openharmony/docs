# DLP Service Development

The Data Loss Prevention (DLP) service is a system solution provided to prevent leakage of sensitive data. It provides a file format called DLP. A DLP file consists of the original file in ciphertext and the authorization credential, and ".dlp" is added to the end of the original file name (including the file name extension), for example, **test.docx.dlp**.

A DLP file can be accessed only after a device-cloud authentication (network connection required) is successful. The permissions for accessing a DLP file include the following:

- Read-only: The user can only view the file.
- Edit: The user can read and write the file, but cannot change the permission on the file.
- Full control: The user can read and write the file, change the permission on the file, and restore the plaintext of the file.

When an application accesses a DLP file, the system automatically installs a DLP sandbox application for the application. As a twin application of the application, the sandbox application inherits data and configuration from the application, but is isolated from the application. The twin application is running in a DLP sandbox, which is restricted from external access to prevent data leakage. Each time a DLP file is opened, a sandbox application is generated. The sandbox applications are also isolated from each other. When an application is closed, its sandbox application will be automatically uninstalled and the temporary data generated in the sandbox directory will be cleared.

Normally, the application is unaware of the sandbox and accesses the file in plaintext, like accessing a common file. However, the DLP sandbox restricts the application from accessing external resources (such as the network, clipboard, screenshot capturing, screen recording, and Bluetooth). For better user experience, you need to make adaptation for your application. For example, for a read-only file, you'd better hide the **Save** button and disable automatic network connection.

## Sandbox Restrictions

For an application in the DLP sandbox state, the permissions granted to the application are restricted based on the permission on the DLP file.

| Application Permission| Description| Read-Only| Edit/Full Control|
| -------- | -------- | -------- | -------- |
| ohos.permission.USE_BLUETOOTH | Allows an application to use Bluetooth.| Unavailable| Unavailable|
| ohos.permission.INTERNET |Allows an application to access the Internet.|  Unavailable| Unavailable|
| ohos.permission.DISTRIBUTED_DATASYNC | Allows an application to exchange user data (such as images, music, videos, and application data) with another device.| Unavailable| Unavailable|
| ohos.permission.WRITE_MEDIA | Allows an application to read and write media files, such as images, videos, and audio clips.| Unavailable| Available|
| ohos.permission.NFC_TAG | Allows an application to use NFC.| Unavailable| Available|

## Available APIs

| API| Description|
| -------- | -------- |
| isDLPFile(fd: number): Promise&lt;boolean&gt; <br> isDLPFile(fd: number, callback: AsyncCallback&lt;boolean&gt;): void| Checks whether a file is a DLP file.|
| getDLPPermissionInfo(): Promise&lt;DLPPermissionInfo&gt; <br>getDLPPermissionInfo(callback: AsyncCallback&lt;DLPPermissionInfo&gt;): void  | Obtains the DLP permission information of this sandbox application.|
| getOriginalFileName(fileName: string): string | Obtains the original name of a DLP file.|
| getDLPSuffix(): string | Obtains the file name extension of this DLP file.|
| on(type: 'openDLPFile', listener: Callback&lt;AccessedDLPFileInfo&gt;): void | Subscribes to the file open event of DLP files. The application will be notified when a DLP file is opened.|
| off(type: 'openDLPFile', listener?: Callback&lt;AccessedDLPFileInfo&gt;): void | Unsubscribes from the file open event of DLP files.|
| isInSandbox(): Promise&lt;boolean&gt; <br>isInSandbox(callback: AsyncCallback&lt;boolean&gt;): void | Checks whether this application is running in a sandbox.|
| getDLPSupportedFileTypes(): Promise&lt;Array&lt;string&gt;&gt;<br>getDLPSupportedFileTypes(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void | Obtains the file name extension types that can be appended with .dlp.|
| setRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt; <br> setRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void | Sets the sandbox application retention state. If the retention state is set for a DLP file, the sandbox application will not be automatically uninstalled when the DLP file is closed.|
| cancelRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt;<br> cancelRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void | Cancels the sandbox application retention state.|
| getRetentionSandboxList(bundleName?: string): Promise&lt;Array&lt;RetentionSandboxInfo&gt;&gt; <br> getRetentionSandboxList(bundleName: string, callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void  <br> getRetentionSandboxList(callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void| Obtains the sandbox applications in the retention state.|
| getDLPFileAccessRecords(): Promise&lt;Array&lt;AccessedDLPFileInfo&gt;&gt; <br> getDLPFileAccessRecords(callback: AsyncCallback&lt;Array&lt;AccessedDLPFileInfo&gt;&gt;): void | Obtains the DLP files that are accessed recently.|
|setSandboxAppConfig(configInfo: string): Promise&lt;void&gt;|Sets sandbox application configuration.|
|getSandboxAppConfig(): Promise&lt;string&gt;|Obtains the sandbox application configuration.|
|cleanSandboxAppConfig(): Promise&lt;void&gt;|Clears the sandbox application configuration.|
| startDLPManagerForResult(context: common.UIAbilityContext, want: Want): Promise&lt;DLPManagerResult&gt; <br>| Starts the DLP manager application on the current UIAbility page in borderless mode (available only for the stage model).|

## How to Develop

1. Import the [dlpPermission](../../reference/apis-data-protection-kit/js-apis-dlppermission.md) module.

   ```ts
   import { dlpPermission } from '@kit.DataProtectionKit';
   ```

2. Open a DLP file. 

    The system automatically installs a DLP sandbox application for your application. <br>Add the following code to your application:

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

3. Generate a .dlp file.

    Currently, the DLP feature supports the following file types: 

    ".doc", ".docm", ".docx", ".dot", ".dotm", ".dotx", ".odp", ".odt", ".pdf", ".pot", ".potm", ".potx", ".ppa", ".ppam", ".pps", ".ppsm", ".ppsx", ".ppt", ".pptm", ".pptx", ".rtf", ".txt", ".wps", ".xla", ".xlam", ".xls", ".xlsb", ".xlsm", ".xlsx", ".xlt", ".xltm", ".xltx", ".xlw", ".xml", ".xps"

    Before you start, ensure that a file of the supported type that can be accessed by the application is available. For example, a file in the **Files** directory. 

    Start the DLP manager application in borderless mode. This API can be called only in the UIAbility context and supports only the stage model. Run the following code to open the permission settings page of the DLP manager application, enter the account information, and tap **Save**. On the page started by file Picker, select the directory to save the DLP file. [You need to implement the cloud module yourself](../DataProtectionKit/dlp-overview.md).

    ```ts
      import { common, Want } from '@kit.AbilityKit';
      import { BusinessError } from '@kit.BasicServicesKit';
      try {
          let fileUri: string = "file://docs/storage/Users/currentUser/test.txt";
          let fileName: string = "test.txt";
          let context = getContext () as common.UIAbilityContext; // Obtain the UIAbility context.
          let want: Want = {
            'uri': fileUri,
            'parameters': {
              'displayName': fileName
            }
          }; // Request parameters.
          dlpPermission.startDLPManagerForResult(context, want).then((res: dlpPermission.DLPManagerResult) => {
            console.info('startDLPManagerForResult res.resultCode:' + res.resultCode);
            console.info('startDLPManagerForResult res.want:' + JSON.stringify(res.want));
          }); // Start the DLP permission manager application to set permissions.
        } catch (err) {
          console.error('startDLPManagerForResult error:' + (err as BusinessError).code + (err as BusinessError).message);
        }
    ```

4. Check whether the application is running in a sandbox.

   ```ts
   dlpPermission.isInSandbox().then((data)=> {
     console.log('isInSandbox, result: ' + JSON.stringify(data));
   }).catch((err:BusinessError) => {
     console.log('isInSandbox: ' + JSON.stringify(err));
   });
   ```

5. Obtain the permissions on the file. The permissions of the DLP sandbox application vary with the user's permission on the file. For more information, see [Sandbox Restrictions](#sandbox-restrictions).

   ```ts
   dlpPermission.getDLPPermissionInfo().then((data)=> {
     console.log('getDLPPermissionInfo, result: ' + JSON.stringify(data));
   }).catch((err:BusinessError) => {
     console.log('getDLPPermissionInfo: ' + JSON.stringify(err));
   });
   ```

6. Obtain information about the file name extension types that support the DLP solution. Based on the information obtained, you can learn what types of files can be used to generate DLP files.

   ```ts
   dlpPermission.getDLPSupportedFileTypes((err, result) => {
     console.log('getDLPSupportedFileTypes: ' + JSON.stringify(err));
     console.log('getDLPSupportedFileTypes: ' + JSON.stringify(result));
   });
   ```

7. Check whether the opened file is a DLP file.

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

8. Subscribe to or unsubscribe from the DLP file open event.

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

9. Obtain information about the DLP files that are recently accessed.

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

10. Obtain information about the DLP sandbox applications in the retention state.

    ```ts
    async getRetentionSandboxList() {
      try {
        let res:Array<dlpPermission.RetentionSandboxInfo> = await dlpPermission.getRetentionSandboxList(); // Obtain the sandbox applications in the retention state.
        console.info('res', JSON.stringify(res))
      } catch (err) {
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
      }
    }
    ```

11. Set sandbox application configuration.

     ```ts
     async setSandboxAppConfig() {
       try {
         await dlpPermission.setSandboxAppConfig('configInfo'); // Set sandbox application configuration.
       } catch (err) {
         console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
       }
     }
     ```

12. Clear the sandbox application configuration.

     ```ts
     async cleanSandboxAppConfig() {
       try {
         await dlpPermission.cleanSandboxAppConfig(); // Clear the sandbox application configuration.
       } catch (err) {
         console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
       }
     }
     ```

13. Obtain the sandbox application configuration.

     ```ts
     async getSandboxAppConfig() {
       try {
         let res:string = await dlpPermission.getSandboxAppConfig(); // Obtain the sandbox application configuration.
         console.info('res', JSON.stringify(res))
       } catch (err) {
         console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
       }
     }
     ```

14. Start the DLP manager application in borderless mode. This API can be called only in the UIAbility context and supports only the stage model.

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
       }); // Start the DLP manager application.
     } catch (err) {
       console.error('error', err.code, err.message); // Report an error upon a failure.
     }
     ```

15. Check whether the current system provides the DLP feature.
     ```ts
     import { dlpPermission } from '@kit.DataProtectionKit';
     import { BusinessError } from '@kit.BasicServicesKit';
     
     dlpPermission.isDLPFeatureProvided().then((res) => {
       console.info('res', JSON.stringify(res));
     }).catch((err: BusinessError) => {
       console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
     });
     ```

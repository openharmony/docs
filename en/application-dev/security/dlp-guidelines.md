# DLP Development

Data loss prevention (DLP) is a system solution provided by OpenHarmony to prevent data disclosure. It provides a file format called DLP. The DLP file name consists of the original file name including the file name extension and **.dlp**, for example, **test.docx.dlp**. The DLP file consists of the authorization credential and the original file in ciphertext.

The DLP file can be accessed only after a device-cloud synergy authentication (network connection required) is successful. The authorized user can have any of the following permissions on the file:

- Read-only: The user can read the file only.
- Edit: The user can read and write the file content, but cannot modify the permissions on the file.
- Full control: The user can read and write the file, modify the permissions on the file, and restore the plaintext of the file.

When an application needs to access a DLP file, the system automatically installs a DLP sandbox twin application for the application. The twin application is a completely independent application. It inherits data and configuration from the application, but is isolated from the application. The twin application is running in a DLP sandbox environment. External access permissions are restricted to prevent data leakage. Each time a new DLP file is opened, an application twin is generated. The sandbox applications are also isolated from each other. When an application is closed, the application twin is automatically uninstalled and the temporary data generated during the sandbox is cleared.

Normally, the application is unaware of the sandbox and accesses the file in plaintext, like accessing a common file. The DLP sandbox restricts access permissions (such as network access, clipboard, and Bluetooth). Your application needs to be adapted for better user experience. For example, hide the **Save** button and disable automatic network connection if a file is read-only.

## Sandbox Restrictions

When an application is in the DLP sandbox state, the available permissions are restricted based on the permission on the DLP file.

| Permission| Description| Read Only| Edit/Full Control|
| -------- | -------- | -------- | -------- |
| ohos.permission.USE_BLUETOOTH | Allows an application to use Bluetooth.| Forbidden| Forbidden|
| ohos.permission.INTERNET |Allows an application to access the Internet.|  Forbidden| Forbidden|
| ohos.permission.DISTRIBUTED_DATASYNC | Allows an application to exchange user data (such as images, music, videos, and application data) with another device.| Forbidden| Forbidden|
| ohos.permission.WRITE_MEDIA | Allows an application to read and write media files, such as video and audio clips and images.| Forbidden| Allowed|
| ohos.permission.CAPTURE_SCREEN | Allows an application to take screenshots.| Forbidden| Allowed|
| ohos.permission.NFC_TAG | Allows an application to use NFC.| Forbidden| Allowed|

## Available APIs

| API| Description|
| -------- | -------- |
| isDLPFile(fd: number): Promise&lt;boolean&gt; <br> isDLPFile(fd: number, callback: AsyncCallback&lt;boolean&gt;): void| Checks whether a file is a DLP file.|
| getDLPPermissionInfo(): Promise&lt;DLPPermissionInfo&gt; <br>getDLPPermissionInfo(callback: AsyncCallback&lt;DLPPermissionInfo&gt;): void  | Obtains the permission type of this sandbox application.|
| getOriginalFileName(fileName: string): string | Obtains the original name of a DLP file.|
| getDLPSuffix(): string | Obtains the file name extension of a DLP file.|
| on(type: 'openDLPFile', listener: Callback&lt;AccessedDLPFileInfo&gt;): void | Subscribes to a file open event of a DLP file. The application will be notified when the DLP file is opened.|
| off(type: 'openDLPFile', listener?: Callback&lt;AccessedDLPFileInfo&gt;): void | Unsubscribes from the file open event of a DLP file.|
| isInSandbox(): Promise&lt;boolean&gt; <br>isInSandbox(callback: AsyncCallback&lt;boolean&gt;): void | Checks whether this application is running in a sandbox.|
| getDLPSupportedFileTypes(): Promise&lt;Array&lt;string&gt;&gt;<br>getDLPSupportedFileTypes(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void | Obtains the file name extension types that can be added with the .dlp.|
| setRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt; <br> setRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void | Sets the sandbox retention state. |
| cancelRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt;<br> cancelRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void | Cancels the sandbox retention state. |
| getRetentionSandboxList(bundleName?: string): Promise&lt;Array&lt;RetentionSandboxInfo&gt;&gt; <br> getRetentionSandboxList(bundleName: string, callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void  <br> getRetentionSandboxList(callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void| Obtains the sandbox applications in the retention state.|
| getDLPFileAccessRecords(): Promise&lt;Array&lt;AccessedDLPFileInfo&gt;&gt; <br> getDLPFileAccessRecords(callback: AsyncCallback&lt;Array&lt;AccessedDLPFileInfo&gt;&gt;): void | Obtains the DLP files that are accessed recently.|

## How to Develop

Procedure

1. Import the [dlpPermission](../reference/apis/js-apis-dlppermission.md) module.

   ```ts
   import dlpPermission from '@ohos.dlpPermission';
   ```

2. Open a DLP file. The system automatically installs a DLP sandbox twin app of your application.

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
        console.log("openDLPFile:" + JSON.stringify(want));
        console.log("openDLPFile: delegator:" + JSON.stringify(CustomGlobal.context));
        CustomGlobal.context.startAbility(want);
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

3. Check whether the application is running in a sandbox.

   ```ts
   dlpPermission.isInSandbox().then((data)=> { 
     console.log('isInSandbox, result: ' + JSON.stringify(data));
   }).catch((err:BusinessError) => {
     console.log("isInSandbox: "  + JSON.stringify(err));
   });
   ```

4. Obtain the permissions on the file. For more information, see [Sandbox Restrictions](#sandbox- restrictions).

   ```ts
   dlpPermission.getDLPPermissionInfo().then((data)=> { 
     console.log('getDLPPermissionInfo, result: ' + JSON.stringify(data));
   }).catch((err:BusinessError) => {
     console.log("getDLPPermissionInfo: "  + JSON.stringify(err));
   });
   ```

5. Obtain information about the file name extension types that support the DLP solution. Based on the information obtained, you can learn the types of files that be used to generate DLP files.

   ```ts
   dlpPermission.getDLPSupportedFileTypes((err, result) => { 
     console.log("getDLPSupportedFileTypes: " + JSON.stringify(err));
     console.log('getDLPSupportedFileTypes: ' + JSON.stringify(result));
   });
   ```

6. Check whether the opened file is a DLP file.
  
   ```ts
   let file = fs.openSync(uri);
   try {
     let res = await dlpPermission.isDLPFile(file.fd); // Check whether the file is a DLP file.
     console.info('res', res);
   } catch (err) {
     console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
   }
   fs.closeSync(file);
   ```

6. Subscribe to and unsubscribe from the file open event for a DLP file.

   ```ts
   event(info: dlpPermission.AccessedDLPFileInfo) {
     console.info('openDlpFile event', info.uri, info.lastOpenTime)
   }
   unSubscribe() {
     try {
       dlpPermission.off('openDLPFile', this.event); // Unsubscribe from the file open event.
     } catch (err) {
       console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
     }
   }
   subscribe() {
     try {
       dlpPermission.on ('openDLPFile' , this.event); // Subscribe to a file open event.
     } catch (err) {
       console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
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
   async func() {
     try {
       let res:Array<dlpPermission.AccessedDLPFileInfo> = await dlpPermission.getDLPFileAccessRecords(); // Obtain the list of recently accessed DLP files.
       console.info('res', JSON.stringify(res))
     } catch (err) {
       console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
     }
   }
   ```

9. Obtain information about the DLP sandbox applications in the retention state.

   ```ts
   async func() {
     try {
       let res:Array<dlpPermission.RetentionSandboxInfo> = await dlpPermission.getRetentionSandboxList(); // Obtain the sandbox applications in the retention state.
       console.info('res', JSON.stringify(res))
     } catch (err) {
       console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
     }
   }
   ```

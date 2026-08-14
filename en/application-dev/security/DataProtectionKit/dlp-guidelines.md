# DLP Service Development (ArkTS)

<!--Kit: Data Protection Kit-->
<!--Subsystem: Security-->
<!--Owner: @winnieHuYu-->
<!--Designer: @QRF-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=ea89afb9ae1513bcb89f85eac0b35098803eb4b4 translatedAt=2026-08-11T01:57:10.247Z pushedAt=2026-08-11T02:20:43.826Z -->

<!--RP1-->

The Data Loss Prevention (DLP) service is a system solution provided to prevent leakage of sensitive data. It provides a file format called DLP. A DLP file consists of the original file in ciphertext and the authorization credential, and ".dlp" is added to the end of the original file name (including the file name extension), for example, **test.docx.dlp**.

A DLP file can be accessed only after successful device-cloud authentication (network connection required). The permissions for accessing a DLP file include the following:

- Read-only: The user can only read the file.

- Edit: The user can read and write the file, but cannot change the permission on the file.

- Full control: The user can read and write the file, change the permission on the file, and restore the plaintext of the file.

When an application accesses a DLP file, the system automatically installs a dual application. The dual application inherits the data and configuration of the original application, but they do not share data with each other. The dual application is running in a sandbox, which is restricted from external access to prevent data leakage. For simplicity, the dual application running in a sandbox is referred to as a sandbox application hereinafter. Each time a DLP file is opened, a sandbox application is generated. The sandbox applications are also isolated from each other. When an application is closed, its sandbox application will be automatically uninstalled and the temporary data generated in the sandbox directory will be cleared.

Under normal circumstances, an app does not perceive the existence of the sandbox and accesses decrypted plaintext, which is no different from accessing a regular file. However, the DLP sandbox restricts its permissions to access external resources (such as the network, clipboard, screenshots, screen recording, Bluetooth, etc.). For a better user experience, the app needs to be adapted. For example, when a file is read-only, the app should not display a **Save** button and should not proactively connect to the network.

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
| setRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt; <br> setRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void | Sets the retention state of the dual application.|
| cancelRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt;<br> cancelRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void | Cancels the retention state of the dual application.|
| getRetentionSandboxList(bundleName?: string): Promise&lt;Array&lt;RetentionSandboxInfo&gt;&gt; <br> getRetentionSandboxList(bundleName: string, callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void  <br> getRetentionSandboxList(callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void| Obtains the retention sandbox list.|
| getDLPFileAccessRecords(): Promise&lt;Array&lt;AccessedDLPFileInfo&gt;&gt; <br> getDLPFileAccessRecords(callback: AsyncCallback&lt;Array&lt;AccessedDLPFileInfo&gt;&gt;): void | Obtains the DLP files that are accessed recently.|
|setSandboxAppConfig(configInfo: string): Promise&lt;void&gt;|Sets sandbox application configuration.|
|getSandboxAppConfig(): Promise&lt;string&gt;|Obtains the sandbox application configuration.|
|cleanSandboxAppConfig(): Promise&lt;void&gt;|Clears the sandbox application configuration.|
| startDLPManagerForResult(context: common.UIAbilityContext, want: Want): Promise&lt;DLPManagerResult&gt; <br>| Starts the DLP manager application on the current UIAbility page in borderless mode (available only for the stage model).|
|setEnterprisePolicy(policy: EnterprisePolicy): void|Sets the protection policy for enterprise applications.|
| scanFile(filePath: string, identifyPolicies: Array&lt;Policy&gt;):  Promise&lt;Array&lt;MatchResult&gt;&gt;| Identifies sensitive content in a specified file.<br>This API is supported since API version 21.|

## How to Develop

This document provides API sample code. For details about how to create a project, see [Creating a Project](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-project).

1. Import the [dlpPermission](../../reference/apis-data-protection-kit/js-apis-dlppermission.md) module.

    <!-- @[dlp_include](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    import { dlpPermission } from '@kit.DataProtectionKit';
    import { identifySensitiveContent } from '@kit.DataProtectionKit';
    ```

2. Open an encrypted file. The system automatically installs a dual application for your application. <br>Add the following code to your application page ability: 

   Prerequisites for using This API: The DLP credential server has been connected. 

    <!-- @[dlp_prepareForOpenDlpFile](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    openDlpFile(dlpUri: string, fileName: string, fd: number) {
      let want:Want = {
        'action': 'ohos.want.action.viewData',
        'uri': dlpUri,
        'parameters' : {
          'fileName': {
            'name': fileName
          },
          'keyFd': {
            'type': 'FD',
            'value': fd
          }
        }
      }
    
      let context = new UIContext().getHostContext() as common.UIAbilityContext; // Obtain the current UIAbilityContext.
    
      try {
        console.info('openDLPFile:' + JSON.stringify(want));
        console.info('openDLPFile: delegator:' + JSON.stringify(context));
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'openDLPFile:' + JSON.stringify(want));
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'openDLPFile: delegator:' + JSON.stringify(context));
        context.startAbility(want);
      } catch (err) {
        console.error('openDLPFile startAbility failed' + (err as BusinessError).code);
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'openDLPFile startAbility failed' + (err as BusinessError).code);
        this.result = 'openDLPFile startAbility failed' + (err as BusinessError).code;
        return;
      }
    }
    
    prepareForOpenDlpFile() {
      let file = this.openFile(this.uri);
      if (!file) {
        return;
      }
      this.openDlpFile(this.uri, this.fileName, file.fd);
        
    }
    ```

    Add **ohos.want.action.viewData** to the **module.json5** file.

    ``` JSON5
    "skills": [
      {
        "entities": [
          "entity.system.home"
        ],
        "actions": [
          "action.system.home",
          "ohos.want.action.viewData"
       ]
      }
    ]
    ```

3. Generate an encrypted DLP file. 

   Prerequisites for using this API: The DLP credential server has been connected.

   [You need to set up the cloud module for this feature](../DataProtectionKit/dlp-overview.md) and configure a domain account environment.

    Currently, the DLP feature supports the following file types: ".doc", ".docm", ".docx", ".dot", ".dotm", ".dotx", ".odp", ".odt", ".pdf", ".pot", ".potm", ".potx", ".ppa", ".ppam", ".pps", ".ppsm", ".ppsx", ".ppt", ".pptm", ".pptx", ".rtf", ".txt", ".wps", ".xla", ".xlam", ".xls", ".xlsb", ".xlsm", ".xlsx", ".xlt", ".xltm", ".xltx", ".xlw", ".xml", ".xps"

    A file of the supported type that can be read or written by an application with DLP permissions is available. For example, a file in the **Files** directory. 

    Start the DLP manager application in borderless mode. This API can be called only in the UIAbility context and supports only the stage model. Run the following code to open the permission settings page of the DLP manager application, enter the account information, and tap **Save**. On the page started by file Picker, select the directory to save the DLP file.

    <!-- @[dlp_generateDlpFiles](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    generateDlpFiles() {
      try {
        let fileUri: string = this.uri;
        let fileName: string = this.fileName;
        let context = new UIContext().getHostContext() as common.UIAbilityContext; // Obtain the current UIAbilityContext.
        let want: Want = {
          'uri': fileUri,
          'parameters': {
            'displayName': fileName
          }
        };// Request parameters.
        dlpPermission.startDLPManagerForResult(context, want).then((res: dlpPermission.DLPManagerResult) => {
          this.result = 'startDLPManagerForResult result.resultCode:' + res.resultCode;
          console.info('startDLPManagerForResult res.resultCode:' + res.resultCode);
          console.info('startDLPManagerForResult res.want:' + JSON.stringify(res.want));
          hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'startDLPManagerForResult res.resultCode:' + res.resultCode);
          hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'startDLPManagerForResult res.want:' + JSON.stringify(res.want));
        });
      } catch (err) {
        this.result = 'startDLPManagerForResult error:' + (err as BusinessError).code + (err as BusinessError).message;
        console.error('startDLPManagerForResult error:' + (err as BusinessError).code + (err as BusinessError).message);
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'startDLPManagerForResult error:' + (err as BusinessError).code + (err as BusinessError).message);
      }
    }
    ```

4. Check whether the application is running in a sandbox.

   Prerequisites for using this API: The DLP file has been opened by the demo application.

    <!-- @[dlp_isInSandBox](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    isInSandbox() {
      dlpPermission.isInSandbox().then((data) => {
        this.result = 'isInSandbox result: ' + JSON.stringify(data);
        console.info('isInSandbox result: ' + JSON.stringify(data));
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'isInSandbox result: ' + JSON.stringify(data));
      }).catch((err:BusinessError) => {
        this.result = 'isInSandbox error: ' + JSON.stringify(err);
        console.error('isInSandbox error: ' + JSON.stringify(err));
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'isInSandbox error: ' + JSON.stringify(err));
      });
    }
    ```

5. Obtain the permissions on the file. The permissions of the DLP sandbox application vary with the user's permission on the file. For more information, see [Sandbox Restrictions](#sandbox-restrictions). 

   Prerequisites for using this API: The DLP file has been opened by the demo application.

    <!-- @[dlp_getDLPPermissionInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    getDLPPermissionInfo() {
      dlpPermission.getDLPPermissionInfo().then((data) => {
        this.result = 'getDLPPermissionInfo result: ' + JSON.stringify(data);
        console.info('getDLPPermissionInfo, result: ' + JSON.stringify(data));
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'getDLPPermissionInfo result: ' + JSON.stringify(data));
      }).catch((err:BusinessError) => {
        this.result = 'getDLPPermissionInfo error: ' + JSON.stringify(err);
        console.error('getDLPPermissionInfo: ' + JSON.stringify(err));
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'getDLPPermissionInfo error: ' + JSON.stringify(err));
      });
    }
    ```

6. Obtain the list of file name extension types that support the DLP solution. Based on the information obtained, you can learn what types of files can be used to generate DLP files.

    <!-- @[dlp_getDLPSupportedFileTypes](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    getDLPSupportedFileTypes() {
      dlpPermission.getDLPSupportedFileTypes((err, result) => {
        console.info('getDLPSupportedFileTypes: ' + JSON.stringify(err));
        console.info('getDLPSupportedFileTypes: ' + JSON.stringify(result));
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'getDLPSupportedFileTypes: ' + JSON.stringify(err));
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'getDLPSupportedFileTypes: ' + JSON.stringify(result));
        this.result = 'getDLPSupportedFileTypes result: ' + JSON.stringify(result);
      });
    }
    ```

7. Check whether the opened file is a DLP file.

   Prerequisites for using this API: The DLP file needs to be checked.

    <!-- @[dlp_isCurrentDlpFile](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->  

    ``` TypeScript
    isCurrentDlpFile() {
      let file = this.openFile(this.uri);
      if(!file) {
        this.result = 'Open a file.';
        return;
      }
      dlpPermission.isDLPFile(file.fd).then((res) => {
        if (res.valueOf()) {
          this.result = 'isDLPFile result: ' + JSON.stringify(res);
        } else {
          this.result = 'Open a DLP file.';
        }
        console.info('res', res);
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'res' + res);
      }).catch((err:BusinessError) => {
        this.result = 'isDLPFile error: ' + (err as BusinessError).code + (err as BusinessError).message;
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'error' + (err as BusinessError).code + (err as BusinessError).message);
      }).finally(() => {
        fileIo.closeSync(file);
      });
    }
    ```

8. Subscribe to or unsubscribe from the DLP file open event.

    <!-- @[dlp_subscribe](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    event(info: dlpPermission.AccessedDLPFileInfo) {
      console.info('openDlpFile event');
      hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'openDlpFile event');
    }
    
    unSubscribe() {
      try {
        dlpPermission.off('openDLPFile', this.event); // Unsubscribe from the file open event.
        this.result = 'unSubscribe result: Unsubscribed';
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'unSubscribe result: Unsubscribed');
      } catch (err) {
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'error' + (err as BusinessError).code + (err as BusinessError).message);
        this.result = 'unSubscribe error: Unsubscription failed.';
      }
    }
      
    subscribe() {
      try {
        dlpPermission.on('openDLPFile', this.event); // Subscribe to the DLP file open event.
        this.result = 'subscribe result: Subscribed';
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'subscribe result: Subscribed');
      } catch (err) {
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'error' + (err as BusinessError).code + (err as BusinessError).message);
        this.result = 'subscribe error: Subscription failed';
      }
    }
    ```

9. Obtain information about the DLP files that are recently accessed. 

   Prerequisites for using this API: The DLP file has been opened by the demo application.

    <!-- @[dlp_getDLPFileAccessRecords](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    getDLPFileAccessRecords() {
      dlpPermission.getDLPFileAccessRecords().then((res) => {
        this.result = 'getDLPFileAccessRecords result: ' + JSON.stringify(res);
        console.info('res', JSON.stringify(res));
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'res' + JSON.stringify(res));
      }).catch((err: BusinessError) => {
        this.result = 'getDLPFileAccessRecords error: ' + (err as BusinessError).code + (err as BusinessError).message;
        console.error('error:', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'error' + (err as BusinessError).code + (err as BusinessError).message);
      });
    }
    ```

10. Obtain information about the DLP sandbox applications in the retention state.

    Prerequisites for using this API: The DLP file has been opened by the demo application.

    <!-- @[dlp_getRetentionSandboxList](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    getRetentionSandboxList() {
      dlpPermission.getRetentionSandboxList().then((res) => {
        this.result = 'getRetentionSandboxList result: ' + JSON.stringify(res);
        console.info('res', JSON.stringify(res));
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'res' + JSON.stringify(res));
      }).catch((err: BusinessError) => {
        this.result = 'getRetentionSandboxList error' + (err as BusinessError).code + (err as BusinessError).message;
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'error' + (err as BusinessError).code + (err as BusinessError).message);
      });
    }
    ```

11. Set sandbox application configuration.

    <!-- @[dlp_setSandboxAppConfig](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    setSandboxAppConfig() {
      dlpPermission.setSandboxAppConfig('configInfo').then(() => {
        this.result = 'setSandboxAppConfig result: The sandbox app configuration is set successfully.';
        console.info('res', 'The sandbox app configuration is set successfully.');
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'setSandboxAppConfig result: The sandbox app configuration is set successfully.');
      }).catch((err: BusinessError) => {
        this.result = 'setSandboxAppConfig error: ' + (err as BusinessError).code + (err as BusinessError).message;
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'error' + (err as BusinessError).code + (err as BusinessError).message);
      });
    }
    ```

12. Clear the sandbox application configuration.

    <!-- @[dlp_cleanSandboxAppConfig](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    cleanSandboxAppConfig() {
      dlpPermission.cleanSandboxAppConfig().then(() => {
        this.result = 'cleanSandboxAppConfig result: Sandbox cleared successfully.';
        console.info('res', 'Sandbox cleared successfully.');
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'cleanSandboxAppConfig result: Sandbox cleared successfully.');
      }).catch((err: BusinessError) => {
        this.result = 'cleanSandboxAppConfig error: ' + (err as BusinessError).code + (err as BusinessError).message;
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'error' + (err as BusinessError).code + (err as BusinessError).message);
      });
    }
    ```

13. Obtain the sandbox application configuration.

    <!-- @[dlp_getSandboxAppConfig](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    getSandboxAppConfig() {
      dlpPermission.getSandboxAppConfig().then((res) => {
        this.result = 'getSandboxAppConfig result: ' + JSON.stringify(res);
        console.info('res', JSON.stringify(res));
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'getSandboxAppConfig result: ' + JSON.stringify(res));
      }).catch((err: BusinessError) => {
        this.result = 'getSandboxAppConfig error: ' + (err as BusinessError).code + (err as BusinessError).message;
        console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'error' + (err as BusinessError).code + (err as BusinessError).message);
      });
    }
    ```

14. Start the DLP manager application in borderless mode. This API can be called only in the UIAbility context and supports only the stage model. 

    Prerequisites for using this API: The DLP credential server has been connected.

    <!-- @[dlp_startDLPManagerForResult](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    startDLPManagerForResult() {
      try {
        let context = new UIContext().getHostContext() as common.UIAbilityContext; // Obtain the current UIAbilityContext.
        let want:Want = {
          'uri': this.uri,
          'parameters' : {
            'displayName': this.fileName
          }
        }; // Request parameters.
        dlpPermission.startDLPManagerForResult(context, want).then((res) => {
          this.result = 'startDLPManagerForResult resultCode: ' + res.resultCode;
          console.info('res.resultCode', res.resultCode);
          console.info('res.want', JSON.stringify(res.want));
          hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'res.resultCode' + res.resultCode);
          hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'res.want' + JSON.stringify(res.want));
        }); // Start the DLP manager application.
      } catch (err) {
        this.result = 'startDLPManagerForResult error' + err.code + err.message;
        console.error('error', err.code, err.message); // Report an error upon a failure.
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'error' + (err as BusinessError).code + (err as BusinessError).message);
      }
    }
    ```

15. Check whether the current system provides the DLP feature. 

    Prerequisites for using this API: The DLP credential server has been connected.

    <!-- @[dlp_isDLPFeature](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    isDLPFeature() {
      dlpPermission.isDLPFeatureProvided().then((res) => {
        this.result = 'isDLPFeatureProvided result: ' + JSON.stringify(res.valueOf());
        console.info('res', JSON.stringify(res.valueOf()));
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'isDLPFeatureProvided result: ' + JSON.stringify(res.valueOf()));
      }).catch((err: BusinessError) => {
        this.result = 'isDLPFeatureProvided error: ' + (err as BusinessError).code + (err as BusinessError).message;
        console.error('error:', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'error' + (err as BusinessError).code + (err as BusinessError).message);
      });
    }
    ```

16. Sets the protection policy for enterprise applications.  

    Prerequisites for using this API: The DLP credential server has been connected.

    16.1 Policy format

    | Field| Type| Description|
    | -------- | -------- | -------- |
    | rules | Array&lt;Rule&gt; | Rule list. A policy can contain a maximum of 32 rules.|
    | policyId |string | Policy name. The value can contain a maximum of 64 bytes and can contain only letters (case-sensitive), digits (0-9), and underscores (_).|
    | ruleConflictAlg | number | Rule conflict resolution algorithm. The value **0** indicates the first match, and the value **1** indicates the complete match.|

    16.2 Rule format

    | Field| Type| Description|
    | -------- | -------- | -------- |
    | ruleId |string | Rule name. The value can contain a maximum of 64 bytes and can contain only letters (case-sensitive), digits (0-9), and underscores (_).|
    | attributes | Array&lt;Attribute&gt; | List of specific attribute information. A rule can contain multiple attributes, with a maximum of 32. |

    16.3 Attribute format

    | Field| Type| Description|
    | -------- | -------- | -------- |
    | attributeId |string | Attribute name.|
    | attributeValues | Array&lt;string&gt; | Attribute value. A maximum of 32 attribute values is allowed.|
    | valueType | number | Attribute value type. The value** 0** indicates an integer, and the value **1** indicates a string.|
    | opt | number | Comparison method, which is used to compare the actual attribute with the policy attribute.|

    16.4 Supported attributes

    | Attribute Name| Attribute Value| Attribute Value Type| Scenario|
    | -------- | -------- | -------- | -------- |
    | DeviceHealthyStatus |1 <br> 2 <br> 3 <br> 4 | Integer| 1: The device health report is normal.<br>2: The device has health risks, but the risk factor is irrelevant to the root.<br> 3: The device has health risks, and the risk factor is relevant to the root.<br> 4: An exception occurs.|
    | NetStatus | InterNet <br> ExtraNet <br> NoNet | String| InterNet: The device is used inside the company.<br>ExtraNet: The device is used outside the company.<br>NoNet: The device is offline.|
    | DebugMode | 1 <br> 2 | Integer| 1: The debugging mode is enabled on the device.<br>2: The debugging mode is disabled on the device.|
    | AdvancedSecurityMode | 1 <br> 2 | Integer| 1: The advanced security mode is enabled on the device.<br>2: The advanced security mode is disabled on the device. |

    <!-- @[dlp_setDLPProtectPolicy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    setDLPProtectPolicy() {
      try {
        let attributeValues: string[] = [ '1' ];
        let attribute: Attribute = {
          attributeId: 'DeviceHealthyStatus',
          attributeValues: attributeValues,
          valueType: 0,
          opt: 2
        }; // Attribute information
        let rule: Rule = {
          ruleId: 'ruleId',
          attributes: [ attribute ]
        }; // Rule
        let policy: Policy = {
          rules: [ rule ],
          policyId: 'policyId',
          ruleConflictAlg: 0
        }; // Policy
        let enterprisePolicy: dlpPermission.EnterprisePolicy = {
          policyString: JSON.stringify(policy)
        };
        dlpPermission.setEnterprisePolicy(enterprisePolicy);
        console.info('set enterprise policy success');
        this.result = 'set enterprise policy success';
        hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'set enterprise policy success');
      } catch (err) {
        console.error('error:' + err.code + err.message); // Throw an error if the operation fails.
        this.result = 'error:' + err.code + err.message;
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'error' + (err as BusinessError).code + (err as BusinessError).message);
      }
    }
    ```

17. (Available since API version 21) Identify sensitive content in a specified file. 

    <!-- @[dlp_scanSensitiveInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/SystemFeature/Security/DLP/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    scanSensitiveInfo() {
      let filepath = this.uri;
      let policies: identifySensitiveContent.Policy[] = [
        {'sensitiveLabel':'1', 'keywords':[], 'regex':''}
      ];
      try {
        identifySensitiveContent.scanFile(filepath, policies).then(records => {
          console.info('scanFile finish');
          this.result = 'scanFile finish';
          hilog.info(HILOG_DLP_DOMAIN, HILOG_TAG, 'scanFile finish');
        }).catch((err:Error) => {
          console.error('error message', err.message);
          this.result = 'error message' + err.message;
          hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'error message' + err.message);
        })
      } catch (err) {
        console.error('error message', err.message);
        this.result = 'error message' + err.message;
        hilog.error(HILOG_DLP_DOMAIN, HILOG_TAG, 'error message' + err.message);
      }
    }
    ```

<!--RP1End-->
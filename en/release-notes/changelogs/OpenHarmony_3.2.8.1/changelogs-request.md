# Upload and Download Subsystem ChangeLog

Compared with OpenHarmony 3.2 Beta3, OpenHarmony 3.2.8.1 has the following changes in its upload and download subsystem:

## cl.request.1 Changes of Error Code Definitions and Some API Names

- The processing of the [upload and download error codes](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/errorcodes/errorcode-request.md) is added to the upload and download APIs.
- An error message is returned via **AsyncCallback** or the **error** object of **Promise**. An error message related to the parameter type or quantity is returned via an exception.
- Some APIs need to be replaced with new APIs, and the parameters remain unchanged.

**Change Impacts**

The application developed based on earlier versions needs to adapt the method for returning API error information. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

| Module        | Class                      | Method/Attribute/Enumeration/Constant                                         | Change Type|
| -------------- | -------------------------- | ------------------------------------------------------------ | -------- |
| ohos.request   | request                    | EXCEPTION_PERMISSION                                         | Added    |
| ohos.request   | request                    | EXCEPTION_PARAMCHECK                                         | Added    |
| ohos.request   | request                    | EXCEPTION_UNSUPPORTED                                        | Added    |
| ohos.request   | request                    | EXCEPTION_FILEIO                                             | Added    |
| ohos.request   | request                    | EXCEPTION_FILEPATH                                           | Added    |
| ohos.request   | request                    | EXCEPTION_SERVICE                                            | Added    |
| ohos.request   | request                    | EXCEPTION_OTHERS                                             | Added    |
| ohos.request   | request                    | ERROR_OFFLINE                                                | Added    |
| ohos.request   | request                    | ERROR_UNSUPPORTED_NETWORK_TYPE                               | Added    |
| ohos.request   | request                    | function downloadFile(context: BaseContext, config: DownloadConfig, callback: AsyncCallback<DownloadTask>): void; | Added    |
| ohos.request   | request                    | function downloadFile(context: BaseContext, config: DownloadConfig): Promise<DownloadTask>; | Added    |
| ohos.request   | request                    | function uploadFile(context: BaseContext, config: UploadConfig, callback: AsyncCallback<UploadTask>): void; | Added    |
| ohos.request   | request                    | function uploadFile(context: BaseContext, config: UploadConfig): Promise<UploadTask>; | Added    |
| ohos.request   | DownloadTask               | delete(callback: AsyncCallback<boolean>): void;              | Added    |
| ohos.request   | DownloadTask               | delete(): Promise<boolean>;                                  | Added    |
| ohos.request   | DownloadTask               | suspend(callback: AsyncCallback<boolean>): void;             | Added    |
| ohos.request   | DownloadTask               | suspend(): Promise<boolean>;                                 | Added    |
| ohos.request   | DownloadTask               | restore(callback: AsyncCallback<boolean>): void;             | Added    |
| ohos.request   | DownloadTask               | restore(): Promise<boolean>;                                 | Added    |
| ohos.request   | DownloadTask               | getTaskInfo(callback: AsyncCallback<DownloadInfo>): void;    | Added    |
| ohos.request   | DownloadTask               | getTaskInfo(): Promise<DownloadInfo>;                        | Added    |
| ohos.request   | DownloadTask               | getTaskMimeType(callback: AsyncCallback<string>): void;      | Added    |
| ohos.request   | DownloadTask               | getTaskMimeType(): Promise<string>;                          | Added    |
| ohos.request   | UploadTask                 | delete(callback: AsyncCallback<boolean>): void;              | Added    |
| ohos.request   | UploadTask                 | delete(): Promise<boolean>;                                  | Added    |
| ohos.request   | request                    | function download(config: DownloadConfig, callback: AsyncCallback<DownloadTask>): void;<br>Substitute API: function downloadFile(context: BaseContext, config: DownloadConfig, callback: AsyncCallback<DownloadTask>): void;| Deprecated    |
| ohos.request   | request                    | function download(config: DownloadConfig): Promise<DownloadTask>;<br>Substitute API: function downloadFile(context: BaseContext, config: DownloadConfig): Promise<DownloadTask>; | Deprecated    |
| ohos.request   | request                    | function download(context: BaseContext, config: DownloadConfig, callback: AsyncCallback<DownloadTask>): void;<br>Substitute API: function downloadFile(context: BaseContext, config: DownloadConfig, callback: AsyncCallback<DownloadTask>): void; | Deprecated    |
| ohos.request   | request                    | function download(context: BaseContext, config: DownloadConfig): Promise<DownloadTask>;<br>Substitute API: function downloadFile(context: BaseContext, config: DownloadConfig): Promise<DownloadTask>; | Deprecated    |
| ohos.request   | request                    | function upload(config: UploadConfig, callback: AsyncCallback<UploadTask>): void;<br>Substitute API: function uploadFile(context: BaseContext, config: UploadConfig, callback: AsyncCallback<UploadTask>): void; | Deprecated    |
| ohos.request   | request                    | function upload(config: UploadConfig): Promise<UploadTask>;<br>Substitute API: function uploadFile(context: BaseContext, config: UploadConfig): Promise<UploadTask>; | Deprecated    |
| ohos.request   | request                    | function upload(context: BaseContext, config: UploadConfig, callback: AsyncCallback<UploadTask>): void;<br>Substitute API: function uploadFile(context: BaseContext, config: UploadConfig, callback: AsyncCallback<UploadTask>): void; | Deprecated    |
| ohos.request   | request                    | function upload(context: BaseContext, config: UploadConfig): Promise<UploadTask>;<br>Substitute API: function uploadFile(context: BaseContext, config: UploadConfig): Promise<UploadTask>; | Deprecated    |
| ohos.request   | DownloadTask               | remove(callback: AsyncCallback<boolean>): void;<br>Substitute API: delete(callback: AsyncCallback<boolean>): void | Deprecated    |
| ohos.request   | DownloadTask               | remove(): Promise<boolean>;<br>Substitute API: delete(): Promise<boolean>; | Deprecated    |
| ohos.request   | DownloadTask               | pause(callback: AsyncCallback<boolean>): void;<br>Substitute API: suspend(callback: AsyncCallback<boolean>): void; | Deprecated    |
| ohos.request   | DownloadTask               | pause(): Promise<boolean>;<br>Substitute API: suspend(): Promise<boolean>; | Deprecated    |
| ohos.request   | DownloadTask               | resume(callback: AsyncCallback<boolean>): void;<br>Substitute API: restore(callback: AsyncCallback<boolean>): void; | Deprecated    |
| ohos.request   | DownloadTask               | resume(): Promise<boolean>;<br>Substitute API: restore(): Promise<boolean>; | Deprecated    |
| ohos.request   | DownloadTask               | query(callback: AsyncCallback<DownloadInfo>): void;<br>Substitute API: getTaskInfo(callback: AsyncCallback<DownloadInfo>): void; | Deprecated    |
| ohos.request   | DownloadTask               | query(): Promise<DownloadInfo>;<br>Substitute API: getTaskInfo(): Promise<DownloadInfo>; | Deprecated    |
| ohos.request   | DownloadTask               | queryMimeType(callback: AsyncCallback<string>): void;<br>Substitute API: getTaskMimeType(callback: AsyncCallback<string>): void; | Deprecated    |
| ohos.request   | DownloadTask               | queryMimeType(): Promise<string>;<br>Substitute API: getTaskMimeType(): Promise<string>; | Deprecated    |
| ohos.request   | UploadTask                 | remove(callback: AsyncCallback<boolean>): void;<br>Substitute API: delete(callback: AsyncCallback<boolean>): void; | Deprecated    |
| ohos.request   | UploadTask                 | remove(): Promise<boolean>;<br>Substitute API: delete(): Promise<boolean>; | Deprecated    |
| system.request | UploadResponse             | code                                                         | Deprecated    |
| system.request | UploadResponse             | data                                                         | Deprecated    |
| system.request | UploadResponse             | headers                                                      | Deprecated    |
| system.request | DownloadResponse           | token                                                        | Deprecated    |
| system.request | OnDownloadCompleteResponse | uri                                                          | Deprecated    |
| system.request | RequestFile                | filename                                                     | Deprecated    |
| system.request | RequestFile                | name                                                         | Deprecated    |
| system.request | RequestFile                | uri                                                          | Deprecated    |
| system.request | RequestFile                | type                                                         | Deprecated    |
| system.request | RequestData                | name                                                         | Deprecated    |
| system.request | RequestData                | value                                                        | Deprecated    |
| system.request | UploadRequestOptions       | url                                                          | Deprecated    |
| system.request | UploadRequestOptions       | data                                                         | Deprecated    |
| system.request | UploadRequestOptions       | files                                                        | Deprecated    |
| system.request | UploadRequestOptions       | header                                                       | Deprecated    |
| system.request | UploadRequestOptions       | description                                                  | Deprecated    |
| system.request | UploadRequestOptions       | success                                                      | Deprecated    |
| system.request | UploadRequestOptions       | fail                                                         | Deprecated    |
| system.request | UploadRequestOptions       | complete                                                     | Deprecated    |
| system.request | OnDownloadCompleteOptions  | token                                                        | Deprecated    |
| system.request | OnDownloadCompleteOptions  | success                                                      | Deprecated    |
| system.request | OnDownloadCompleteOptions  | fail                                                         | Deprecated    |
| system.request | OnDownloadCompleteOptions  | complete                                                     | Deprecated    |
| system.request | Request                    | static upload(options: UploadRequestOptions): void;          | Deprecated    |
| system.request | Request                    | static download(options: DownloadRequestOptions): void;      | Deprecated    |
| system.request | Request                    | static onDownloadComplete(options: OnDownloadCompleteOptions): void; | Deprecated    |


**Adaptation Guide**

The following uses **downloadFile** as an example to show how it is called in the new version:

```ts
try {
    request.downloadFile(globalThis.abilityContext, { url: 'https://xxxx/xxxxx.hap',
        filePath: 'xxx/xxxxx.hap'}, (err, data) => {
        if (err) {
            console.error('Failed to request the download. Cause: ' + JSON.stringify(err));
            return;
        }
    });
} catch (err) {
    console.log("downloadFile callback fail." + "errCode:" + err.code + ",errMessage:" + err.message);
}
```

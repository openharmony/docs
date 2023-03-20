# Upload and Download Subsystem Changelog


## cl.request.2 Upload and Download API Change

- Deleted the beta APIs in API version 9:
1. function download(context: BaseContext, config: DownloadConfig, callback: AsyncCallback<DownloadTask>): void;
2. function download(context: BaseContext, config: DownloadConfig): Promise<DownloadTask>;
3. function upload(context: BaseContext, config: UploadConfig, callback: AsyncCallback<UploadTask>): void;
4. function upload(context: BaseContext, config: UploadConfig): Promise<UploadTask>;

**Change Impact**

The application developed based on the Stage mode of earlier versions needs to be adapted. Otherwise, the service logic will be affected.

**Key API/Component Changes**

| Module         | Class          | Method/Attribute/Enumeration/Constant                                                                                                      | Change Type|
|--------------|--------------|-------------------------------------------------------------------------------------------------------------------|------|
| ohos.request | request      | function download(context: BaseContext, config: DownloadConfig, callback: AsyncCallback<DownloadTask>): void;     | Deleted.  |
| ohos.request | request      | function download(context: BaseContext, config: DownloadConfig): Promise<DownloadTask>;                           | Deleted.  |
| ohos.request | request      | function upload(context: BaseContext, config: UploadConfig, callback: AsyncCallback<UploadTask>): void;           | Deleted.  |
| ohos.request | request      | function upload(context: BaseContext, config: UploadConfig): Promise<UploadTask>;                                 | Deleted.  |


**Adaptation Guide**

The following sample code shows how to call **downloadFile** in the new version:

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

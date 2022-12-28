# 上传下载子系统ChangeLog

OpenHarmony 3.2.8.1版本相较于OpenHarmony 3.2.beta3版本，request子系统的API变更如下

## cl.request.1 错误码定义及API部分接口名称变更

- 新增上传下载接口的[错误码](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/errorcodes/errorcode-request.md)处理。
- 错误信息通过AsyncCallback或Promise的error对象返回。其中，参数类型和数量错误信息，通过抛出异常的方式返回。
- API部分接口需要用新的接口替换，参数不变。

**变更影响**

基于此前版本开发的应用，需适配变更后的新错误码和错误信息返回方式，否则会影响原有业务逻辑。

**关键的接口/组件变更**

| 模块名          | 类名           | 方法/属性/枚举/常量                                                                                                           | 变更类型      |
|--------------|--------------|-----------------------------------------------------------------------------------------------------------------------|-----------|
| ohos.request | request      | EXCEPTION_PERMISSION                                                                                                  | 新增 |
| ohos.request | request      | EXCEPTION_PARAMCHECK                                                                                                  | 新增 |
| ohos.request | request      | EXCEPTION_UNSUPPORTED                                                                                                 | 新增 |
| ohos.request | request      | EXCEPTION_FILEIO                                                                                                      | 新增 |
| ohos.request | request      | EXCEPTION_FILEPATH                                                                                                    | 新增 |
| ohos.request | request      | EXCEPTION_SERVICE                                                                                                     | 新增 |
| ohos.request | request      | EXCEPTION_OTHERS                                                                                                      | 新增 |
| ohos.request | request      | ERROR_OFFLINE                                                                                                         | 新增 |
| ohos.request | request      | ERROR_UNSUPPORTED_NETWORK_TYPE                                                                                        | 新增 |
| ohos.request | request      | function downloadFile(context: BaseContext, config: DownloadConfig, callback: AsyncCallback<DownloadTask>): void;     | 新增 |
| ohos.request | request      | function downloadFile(context: BaseContext, config: DownloadConfig): Promise<DownloadTask>;                           | 新增 |
| ohos.request | request      | function uploadFile(context: BaseContext, config: UploadConfig, callback: AsyncCallback<UploadTask>): void;           | 新增 |
| ohos.request | request      | function uploadFile(context: BaseContext, config: UploadConfig): Promise<UploadTask>;                                 | 新增 |
| ohos.request | DownloadTask | delete(callback: AsyncCallback<boolean>): void;                                                                       | 新增 |
| ohos.request | DownloadTask | delete(): Promise<boolean>;                                                                                           | 新增 |
| ohos.request | DownloadTask | suspend(callback: AsyncCallback<boolean>): void;                                                                      | 新增 |
| ohos.request | DownloadTask | suspend(): Promise<boolean>;                                                                                          | 新增 |
| ohos.request | DownloadTask | restore(callback: AsyncCallback<boolean>): void;                                                                      | 新增 |
| ohos.request | DownloadTask | restore(): Promise<boolean>;                                                                                          | 新增 |
| ohos.request | DownloadTask | getTaskInfo(callback: AsyncCallback<DownloadInfo>): void;                                                             | 新增 |
| ohos.request | DownloadTask | getTaskInfo(): Promise<DownloadInfo>;                                                                                 | 新增 |
| ohos.request | DownloadTask | getTaskMimeType(callback: AsyncCallback<string>): void;                                                               | 新增 |
| ohos.request | DownloadTask | getTaskMimeType(): Promise<string>;                                                                                   | 新增 |
| ohos.request | UploadTask | delete(callback: AsyncCallback<boolean>): void;                                                                       | 新增 |
| ohos.request | UploadTask | delete(): Promise<boolean>;                                                                                           | 新增 |
| ohos.request | request      | function download(config: DownloadConfig, callback: AsyncCallback<DownloadTask>): void;<br>代替接口：function downloadFile(context: BaseContext, config: DownloadConfig, callback: AsyncCallback<DownloadTask>): void; | 废弃 |
| ohos.request | request      | function download(config: DownloadConfig): Promise<DownloadTask>;<br>代替接口：function downloadFile(context: BaseContext, config: DownloadConfig): Promise<DownloadTask>; | 废弃 |
| ohos.request | request      | function download(context: BaseContext, config: DownloadConfig, callback: AsyncCallback<DownloadTask>): void;<br>代替接口：function downloadFile(context: BaseContext, config: DownloadConfig, callback: AsyncCallback<DownloadTask>): void; | 废弃 |
| ohos.request | request      | function download(context: BaseContext, config: DownloadConfig): Promise<DownloadTask>;<br>代替接口：function downloadFile(context: BaseContext, config: DownloadConfig): Promise<DownloadTask>; | 废弃 |
| ohos.request | request      | function upload(config: UploadConfig, callback: AsyncCallback<UploadTask>): void;<br>代替接口：function uploadFile(context: BaseContext, config: UploadConfig, callback: AsyncCallback<UploadTask>): void; | 废弃 |
| ohos.request | request      | function upload(config: UploadConfig): Promise<UploadTask>;<br>代替接口：function uploadFile(context: BaseContext, config: UploadConfig): Promise<UploadTask>; | 废弃 |
| ohos.request | request      | function upload(context: BaseContext, config: UploadConfig, callback: AsyncCallback<UploadTask>): void;<br>代替接口：function uploadFile(context: BaseContext, config: UploadConfig, callback: AsyncCallback<UploadTask>): void; | 废弃 |
| ohos.request | request      | function upload(context: BaseContext, config: UploadConfig): Promise<UploadTask>;<br>代替接口：function uploadFile(context: BaseContext, config: UploadConfig): Promise<UploadTask>; | 废弃 |
| ohos.request | DownloadTask | remove(callback: AsyncCallback<boolean>): void;<br>代替接口：delete(callback: AsyncCallback<boolean>): void                | 废弃 |
| ohos.request | DownloadTask | remove(): Promise<boolean>;<br>代替接口：delete(): Promise<boolean>;                                                       | 废弃 |
| ohos.request | DownloadTask | pause(callback: AsyncCallback<boolean>): void;<br>代替接口：suspend(callback: AsyncCallback<boolean>): void;               | 废弃 |
| ohos.request | DownloadTask | pause(): Promise<boolean>;<br>代替接口：suspend(): Promise<boolean>;                                                       | 废弃 |
| ohos.request | DownloadTask | resume(callback: AsyncCallback<boolean>): void;<br>代替接口：restore(callback: AsyncCallback<boolean>): void;              | 废弃 |
| ohos.request | DownloadTask | resume(): Promise<boolean>;<br>代替接口：restore(): Promise<boolean>;                                                      | 废弃 |
| ohos.request | DownloadTask | query(callback: AsyncCallback<DownloadInfo>): void;<br>代替接口：getTaskInfo(callback: AsyncCallback<DownloadInfo>): void; | 废弃 |
| ohos.request | DownloadTask | query(): Promise<DownloadInfo>;<br>代替接口：getTaskInfo(): Promise<DownloadInfo>;                                         | 废弃 |
| ohos.request | DownloadTask | queryMimeType(callback: AsyncCallback<string>): void;<br>代替接口：getTaskMimeType(callback: AsyncCallback<string>): void; | 废弃 |
| ohos.request | DownloadTask | queryMimeType(): Promise<string>;<br>代替接口：getTaskMimeType(): Promise<string>;                                         | 废弃 |
| ohos.request | UploadTask | remove(callback: AsyncCallback<boolean>): void;<br>代替接口：delete(callback: AsyncCallback<boolean>): void;               | 废弃 |
| ohos.request | UploadTask | remove(): Promise<boolean>;<br>代替接口：delete(): Promise<boolean>;                                                       | 废弃 |
| system.request | UploadResponse | code                                                                                                                  | 废弃 |
| system.request | UploadResponse | data                                                                                                                  | 废弃 |
| system.request | UploadResponse | headers                                                                                                               | 废弃 |
| system.request | DownloadResponse | token                                                                                                                 | 废弃 |
| system.request | OnDownloadCompleteResponse | uri                                                                                                                   | 废弃 |
| system.request | RequestFile | filename                                                                                                              | 废弃 |
| system.request | RequestFile | name                                                                                                                  | 废弃 |
| system.request | RequestFile | uri                                                                                                                   | 废弃 |
| system.request | RequestFile | type                                                                                                                  | 废弃 |
| system.request | RequestData | name                                                                                                                  | 废弃 |
| system.request | RequestData | value                                                                                                                 | 废弃 |
| system.request | UploadRequestOptions | url                                                                                                                   | 废弃 |
| system.request | UploadRequestOptions | data                                                                                                                  | 废弃 |
| system.request | UploadRequestOptions | files                                                                                                                 | 废弃 |
| system.request | UploadRequestOptions | header                                                                                                                | 废弃 |
| system.request | UploadRequestOptions | description                                                                                                           | 废弃 |
| system.request | UploadRequestOptions | success                                                                                                               | 废弃 |
| system.request | UploadRequestOptions | fail                                                                                                                  | 废弃 |
| system.request | UploadRequestOptions | complete                                                                                                              | 废弃 |
| system.request | OnDownloadCompleteOptions | token                                                                                                                 | 废弃 |
| system.request | OnDownloadCompleteOptions | success                                                                                                               | 废弃 |
| system.request | OnDownloadCompleteOptions | fail                                                                                                                  | 废弃 |
| system.request | OnDownloadCompleteOptions | complete                                                                                                              | 废弃 |
| system.request | Request | static upload(options: UploadRequestOptions): void;                                                                   | 废弃 |
| system.request | Request | static download(options: DownloadRequestOptions): void;                                                               | 废弃 |
| system.request | Request | static onDownloadComplete(options: OnDownloadCompleteOptions): void;                                                  | 废弃 |


**适配指导**

以downloadFile为例，在新版本上需要使用如下方式进行调用：

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
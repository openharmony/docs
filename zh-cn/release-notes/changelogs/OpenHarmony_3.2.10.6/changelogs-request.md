# 上传下载子系统ChangeLog


## cl.request.2 request上传下载接口变更

- 删除API9-beta接口：
1. function download(context: BaseContext, config: DownloadConfig, callback: AsyncCallback<DownloadTask>): void;
2. function download(context: BaseContext, config: DownloadConfig): Promise<DownloadTask>;
3. function upload(context: BaseContext, config: UploadConfig, callback: AsyncCallback<UploadTask>): void;
4. function upload(context: BaseContext, config: UploadConfig): Promise<UploadTask>;

**变更影响**

基于此前版本使用Stage模式开发的应用，需适配变更后的接口，否则会影响原有业务逻辑。

**关键的接口/组件变更**

| 模块名          | 类名           | 方法/属性/枚举/常量                                                                                                       | 变更类型 |
|--------------|--------------|-------------------------------------------------------------------------------------------------------------------|------|
| ohos.request | request      | function download(context: BaseContext, config: DownloadConfig, callback: AsyncCallback<DownloadTask>): void;     | 删除   |
| ohos.request | request      | function download(context: BaseContext, config: DownloadConfig): Promise<DownloadTask>;                           | 删除   |
| ohos.request | request      | function upload(context: BaseContext, config: UploadConfig, callback: AsyncCallback<UploadTask>): void;           | 删除   |
| ohos.request | request      | function upload(context: BaseContext, config: UploadConfig): Promise<UploadTask>;                                 | 删除   |


**适配指导**

以download为例，在新版本上需要使用downloadFile, 如下方式进行调用：

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
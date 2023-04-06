# request Switching


  | API in the FA Model| Corresponding d.ts File in the Stage Model| Corresponding API in the Stage Model| 
| -------- | -------- | -------- |
| [download(config: DownloadConfig, callback: AsyncCallback&lt;DownloadTask&gt;): void;](../reference/apis//js-apis-request.md#requestdownload-1)<br>[download(config: DownloadConfig): Promise&lt;DownloadTask&gt;;](../reference/apis/js-apis-request.md#requestdownload) | \@ohos.request.d.ts | [downloadFile(context: BaseContext, config: DownloadConfig, callback: AsyncCallback&lt;DownloadTask&gt;): void;](../reference/apis/js-apis-request.md#requestdownloadfile9-1)<br>[downloadFile(context: BaseContext, config: DownloadConfig): Promise&lt;DownloadTask&gt;;](../reference/apis/js-apis-request.md#requestdownloadfile9) |
| [upload(config: UploadConfig, callback: AsyncCallback&lt;UploadTask&gt;): void;](../reference/apis/js-apis-request.md#requestupload-1)<br>[upload(config: UploadConfig): Promise&lt;UploadTask&gt;;](../reference/apis/js-apis-request.md#requestupload) | \@ohos.request.d.ts | [uploadFile(context: BaseContext, config: UploadConfig, callback: AsyncCallback&lt;UploadTask&gt;): void;](../reference/apis/js-apis-request.md#requestuploadfile9-1)<br>[uploadFile(context: BaseContext, config: UploadConfig): Promise&lt;UploadTask&gt;;](../reference/apis/js-apis-request.md#requestuploadfile9) |

# 文件子系统ChangeLog

## cl.file.1 mediaLibrary相关接口变更

multimedia 部件 medialibrary 接口废弃原有相关接口，使用 FilePicker 替代。

**变更影响**

基于此前版本开发的应用，需注意废弃接口的迭代更新。替代的 FilePicker 应用是OpenHarmony中预置的系统应用，为用户提供文件选择及保存功能。

**关键接口/组件变更**

medialibrary 相关接口废弃，原接口位于 @ohos.multimedia.medialibrary；替代应用为 FilePicker，位于[@ohos.file.picker](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.file.picker.d.ts)

| 模块名                    | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------------------------------------------------ | -------- |
| medialibrary   |  **function** getMediaLibrary(): MediaLibrary; | 废弃     |
| medialibrary   |  **function** getMediaLibrary(context: Context): MediaLibrary; | 废弃     |
| medialibrary   |  **function** getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult\>): void | 废弃     |
| medialibrary   |  **function** getFileAssets(options: MediaFetchOptions): Promise\<FetchFileResult\> | 废弃     |
| medialibrary   |  **function** on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void\>): void | 废弃     |
| medialibrary   |  **function** off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void\>): void | 废弃     |
| medialibrary   |  **function** createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback\<FileAsset\>): void | 废弃     |
| medialibrary   |  **function** createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise\<FileAsset\> | 废弃     |
| medialibrary   |  **function** deleteAsset(uri: string): Promise\<void\> | 废弃     |
| medialibrary   |  **function** deleteAsset(uri: string, callback: AsyncCallback\<void\>): void | 废弃     |
| medialibrary   |  **function** getPublicDirectory(type: DirectoryType, callback: AsyncCallback\<string\>): void | 废弃     |
| medialibrary   |  **function** getPublicDirectory(type: DirectoryType): Promise\<string\> | 废弃     |
| medialibrary   |  **function** getAlbums(options: MediaFetchOptions, callback: AsyncCallback\<Array\<Album\>\>): void | 废弃     |
| medialibrary   |  **function** getAlbums(options: MediaFetchOptions): Promise\<Array\<Album\>\> | 废弃     |
| medialibrary   |  **function** release(callback: AsyncCallback\<void\>): void  | 废弃     | 
| medialibrary   |  **function** release(): Promise\<void\> | 废弃     |
| medialibrary   |  **function** storeMediaAsset(option: MediaAssetOption, callback: AsyncCallback\<string\>): void | 废弃     |
| medialibrary   |  **function** storeMediaAsset(option: MediaAssetOption): Promise\<string\> | 废弃     |
| medialibrary   |  **function** startImagePreview(images: Array\<string\>, index: number, callback: AsyncCallback\<void\>): void | 废弃     |
| medialibrary   |  **function** startImagePreview(images: Array\<string\>, callback: AsyncCallback\<void\>): void | 废弃     |
| medialibrary   |  **function** startImagePreview(images: Array\<string\>, index?: number): Promise\<void\> | 废弃     |
| medialibrary   |  **function** startMediaSelect(option: MediaSelectOption, callback: AsyncCallback\<Array\<string\>\>): void | 废弃     |
| medialibrary   |  **function** startMediaSelect(option: MediaSelectOption): Promise\<Array\<string\>\> | 废弃     |
| medialibrary   |  **function** getActivePeers(): Promise\<Array\<PeerInfo\>\>; | 废弃     |
| medialibrary   |  **function** getActivePeers(callback: AsyncCallback\<Array\<PeerInfo\>\>): void; | 废弃     |
| medialibrary   |  **function** getAllPeers(): Promise\<Array\<PeerInfo\>\>; | 废弃     |
| medialibrary   |  **function** FileAsset.isDirectory(callback: AsyncCallback\<boolean\>): void | 废弃     |
| medialibrary   |  **function** FileAsset.isDirectory():Promise\<boolean\> | 废弃     |
| medialibrary   |  **function** FileAsset.commitModify(callback: AsyncCallback\<void\>): void | 废弃     |
| medialibrary   |  **function** FileAsset.commitModify(): Promise\<void\> | 废弃     |
| medialibrary   |  **function** FileAsset.open(mode: string, callback: AsyncCallback\<number\>): void | 废弃     |
| medialibrary   |  **function** FileAsset.open(mode: string): Promise\<number\> | 废弃     |
| medialibrary   |  **function** FileAsset.close(fd: number, callback: AsyncCallback\<void\>): void | 废弃     |
| medialibrary   |  **function** FileAsset.close(fd: number): Promise\<void\> | 废弃     |
| medialibrary   |  **function** FileAsset.getThumbnail(callback: AsyncCallback\<image.PixelMap\>): void | 废弃     |
| medialibrary   |  **function** FileAsset.getThumbnail(size: Size, callback: AsyncCallback\<image.PixelMap\>): void | 废弃     |
| medialibrary   |  **function** FileAsset.getThumbnail(size?: Size): Promise\<image.PixelMap\> | 废弃     |
| medialibrary   |  **function** FileAsset.favorite(isFavorite: boolean, callback: AsyncCallback\<void\>): void | 废弃     |
| medialibrary   |  **function** FileAsset.favorite(isFavorite: boolean): Promise\<void\> | 废弃     |
| medialibrary   |  **function** FileAsset.isFavorite(callback: AsyncCallback\<boolean\>): void | 废弃     |
| medialibrary   |  **function** FileAsset.isFavorite():Promise\<boolean\>  | 废弃     |
| medialibrary   |  **function** FileAsset.trash(isTrash: boolean, callback: AsyncCallback\<void\>): void | 废弃     |
| medialibrary   |  **function** FileAsset.trash(isTrash: boolean): Promise\<void\> | 废弃     |
| medialibrary   |  **function** FileAsset.isTrash(callback: AsyncCallback\<boolean\>): void | 废弃     |
| medialibrary   |  **function** FileAsset.isTrash():Promise\<boolean\> | 废弃     |
| medialibrary   |  **function** FetchFileResult.getCount(): number | 废弃     |
| medialibrary   |  **function** FetchFileResult.isAfterLast(): boolean | 废弃     |
| medialibrary   |  **function** FetchFileResult.close(): void | 废弃     |
| medialibrary   |  **function** FetchFileResult.getFirstObject(callback: AsyncCallback\<FileAsset\>): void | 废弃     |
| medialibrary   |  **function** FetchFileResult.getFirstObject(): Promise\<FileAsset\> | 废弃     |
| medialibrary   |  **function** FetchFileResult.getNextObject(callback: AsyncCallback\<FileAsset\>): void | 废弃     |
| medialibrary   |  **function** FetchFileResult.getNextObject(): Promise\<FileAsset\> | 废弃     |
| medialibrary   |  **function** FetchFileResult.getLastObject(callback: AsyncCallback\<FileAsset\>): void | 废弃     |
| medialibrary   |  **function** FetchFileResult.getLastObject(): Promise\<FileAsset\> | 废弃     |
| medialibrary   |  **function** FetchFileResult.getPositionObject(index: number, callback: AsyncCallback\<FileAsset\>): void | 废弃     |
| medialibrary   |  **function** FetchFileResult.getPositionObject(index: number): Promise\<FileAsset\> | 废弃     |
| medialibrary   |  **function** FetchFileResult.getAllObject(callback: AsyncCallback\<Array\<FileAsset\>\>): void | 废弃     |
| medialibrary   |  **function** FetchFileResult.getAllObject(): Promise\<Array\<FileAsset\>\> | 废弃     |
| medialibrary   |  **function** Album.commitModify(callback: AsyncCallback\<void\>): void | 废弃     |
| medialibrary   |  **function** Album.commitModify(): Promise\<void\> | 废弃     |
| medialibrary   |  **function** Album.getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult\>): void | 废弃     |
| medialibrary   |  **function** Album.getFileAssets(options?: MediaFetchOptions): Promise\<FetchFileResult\> | 废弃     |
| medialibrary   |  **enum** DeviceType | 废弃     |
| medialibrary   |  **enum** FileKey | 废弃     |
| medialibrary   |  **enum** DirectoryType | 废弃     |
| medialibrary   |  **enum** MediaType | 废弃     |
| medialibrary   |  **interface** PeerInfo | 废弃     |
| medialibrary   |  **interface** Size  | 废弃     |
| medialibrary   |  **interface** MediaFetchOptions | 废弃     |
| medialibrary   |  **interface** MediaAssetOption | 废弃     |
| medialibrary   |  **interface** MediaSelectOption | 废弃     |
| medialibrary   |  **interface** FileAsset | 废弃     |

**适配指导**

以选取一张图片为例，在替代应用中如下方式进行调用：

```js
import picker from '@ohos.file.picker';

async function example() {
    try {  
        let PhotoSelectOptions = new picker.PhotoSelectOptions();
        PhotoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
        PhotoSelectOptions.maxSelectNumber = 1;
        let photoPicker = new picker.PhotoViewPicker();
        photoPicker.select(PhotoSelectOptions).then((PhotoSelectResult) => {
            if (PhotoSelectResult !== undefined) {
                console.info("PhotoViewPicker.select pass, PhotoSelectResult uri: " + JSON.stringify(PhotoSelectResult));
            } else {
                console.error("PhotoViewPicker.select PhotoSelectResult is undefined");
            }
        }).catch((err) => {
            console.error("PhotoViewPicker.select fail, err: " + err);
        });
    } catch (err) {
        console.error("PhotoViewPicker fail, err: " + err);
    }
}
```
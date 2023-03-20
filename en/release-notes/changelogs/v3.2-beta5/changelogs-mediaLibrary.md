# File Management Subsystem Changelog

## cl.file.1 mediaLibrary APIs Changed

The **MediaLibrary** class of the multimedia component is replaced by the **FilePicker** class.

**Change Impact**

For applications developed based on earlier versions, pay attention to the changes of APIs. **FilePicker** is a system application preset in OpenHarmony. You can use it to select and save files.

**Key API/Component Changes**

The APIs of **MediaLibrary**, located in **@ohos.multimedia.medialibrary**, are deprecated. The **FilePicker** class, located in [@ohos.file.picker](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.file.picker.d.ts) is used.

| Module                   | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------------------------------------------------ | -------- |
| medialibrary   |  **function** getMediaLibrary(): MediaLibrary; | Deprecated    |
| medialibrary   |  **function** getMediaLibrary(context: Context): MediaLibrary; | Deprecated    |
| medialibrary   |  **function** getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult\>): void | Deprecated    |
| medialibrary   |  **function** getFileAssets(options: MediaFetchOptions): Promise\<FetchFileResult\> | Deprecated    |
| medialibrary   |  **function** on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void\>): void | Deprecated    |
| medialibrary   |  **function** off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void\>): void | Deprecated    |
| medialibrary   |  **function** createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback\<FileAsset\>): void | Deprecated    |
| medialibrary   |  **function** createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise\<FileAsset\> | Deprecated    |
| medialibrary   |  **function** deleteAsset(uri: string): Promise\<void\> | Deprecated    |
| medialibrary   |  **function** deleteAsset(uri: string, callback: AsyncCallback\<void\>): void | Deprecated    |
| medialibrary   |  **function** getPublicDirectory(type: DirectoryType, callback: AsyncCallback\<string\>): void | Deprecated    |
| medialibrary   |  **function** getPublicDirectory(type: DirectoryType): Promise\<string\> | Deprecated    |
| medialibrary   |  **function** getAlbums(options: MediaFetchOptions, callback: AsyncCallback\<Array\<Album\>\>): void | Deprecated    |
| medialibrary   |  **function** getAlbums(options: MediaFetchOptions): Promise\<Array\<Album\>\> | Deprecated    |
| medialibrary   |  **function** release(callback: AsyncCallback\<void\>): void  | Deprecated    |
| medialibrary   |  **function** release(): Promise\<void\> | Deprecated    |
| medialibrary   |  **function** storeMediaAsset(option: MediaAssetOption, callback: AsyncCallback\<string\>): void | Deprecated    |
| medialibrary   |  **function** storeMediaAsset(option: MediaAssetOption): Promise\<string\> | Deprecated    |
| medialibrary   |  **function** startImagePreview(images: Array\<string\>, index: number, callback: AsyncCallback\<void\>): void | Deprecated    |
| medialibrary   |  **function** startImagePreview(images: Array\<string\>, callback: AsyncCallback\<void\>): void | Deprecated    |
| medialibrary   |  **function** startImagePreview(images: Array\<string\>, index?: number): Promise\<void\> | Deprecated    |
| medialibrary   |  **function** startMediaSelect(option: MediaSelectOption, callback: AsyncCallback\<Array\<string\>\>): void | Deprecated    |
| medialibrary   |  **function** startMediaSelect(option: MediaSelectOption): Promise\<Array\<string\>\> | Deprecated    |
| medialibrary   |  **function** getActivePeers(): Promise\<Array\<PeerInfo\>\>; | Deprecated    |
| medialibrary   |  **function** getActivePeers(callback: AsyncCallback\<Array\<PeerInfo\>\>): void; | Deprecated    |
| medialibrary   |  **function** getAllPeers(): Promise\<Array\<PeerInfo\>\>; | Deprecated    |
| medialibrary   |  **function** FileAsset.isDirectory(callback: AsyncCallback\<boolean\>): void | Deprecated    |
| medialibrary   |  **function** FileAsset.isDirectory():Promise\<boolean\> | Deprecated    |
| medialibrary   |  **function** FileAsset.commitModify(callback: AsyncCallback\<void\>): void | Deprecated    |
| medialibrary   |  **function** FileAsset.commitModify(): Promise\<void\> | Deprecated    |
| medialibrary   |  **function** FileAsset.open(mode: string, callback: AsyncCallback\<number\>): void | Deprecated    |
| medialibrary   |  **function** FileAsset.open(mode: string): Promise\<number\> | Deprecated    |
| medialibrary   |  **function** FileAsset.close(fd: number, callback: AsyncCallback\<void\>): void | Deprecated    |
| medialibrary   |  **function** FileAsset.close(fd: number): Promise\<void\> | Deprecated    |
| medialibrary   |  **function** FileAsset.getThumbnail(callback: AsyncCallback\<image.PixelMap\>): void | Deprecated    |
| medialibrary   |  **function** FileAsset.getThumbnail(size: Size, callback: AsyncCallback\<image.PixelMap\>): void | Deprecated    |
| medialibrary   |  **function** FileAsset.getThumbnail(size?: Size): Promise\<image.PixelMap\> | Deprecated    |
| medialibrary   |  **function** FileAsset.favorite(isFavorite: boolean, callback: AsyncCallback\<void\>): void | Deprecated    |
| medialibrary   |  **function** FileAsset.favorite(isFavorite: boolean): Promise\<void\> | Deprecated    |
| medialibrary   |  **function** FileAsset.isFavorite(callback: AsyncCallback\<boolean\>): void | Deprecated    |
| medialibrary   |  **function** FileAsset.isFavorite():Promise\<boolean\>  | Deprecated    |
| medialibrary   |  **function** FileAsset.trash(isTrash: boolean, callback: AsyncCallback\<void\>): void | Deprecated    |
| medialibrary   |  **function** FileAsset.trash(isTrash: boolean): Promise\<void\> | Deprecated    |
| medialibrary   |  **function** FileAsset.isTrash(callback: AsyncCallback\<boolean\>): void | Deprecated    |
| medialibrary   |  **function** FileAsset.isTrash():Promise\<boolean\> | Deprecated    |
| medialibrary   |  **function** FetchFileResult.getCount(): number | Deprecated    |
| medialibrary   |  **function** FetchFileResult.isAfterLast(): boolean | Deprecated    |
| medialibrary   |  **function** FetchFileResult.close(): void | Deprecated    |
| medialibrary   |  **function** FetchFileResult.getFirstObject(callback: AsyncCallback\<FileAsset\>): void | Deprecated    |
| medialibrary   |  **function** FetchFileResult.getFirstObject(): Promise\<FileAsset\> | Deprecated    |
| medialibrary   |  **function** FetchFileResult.getNextObject(callback: AsyncCallback\<FileAsset\>): void | Deprecated    |
| medialibrary   |  **function** FetchFileResult.getNextObject(): Promise\<FileAsset\> | Deprecated    |
| medialibrary   |  **function** FetchFileResult.getLastObject(callback: AsyncCallback\<FileAsset\>): void | Deprecated    |
| medialibrary   |  **function** FetchFileResult.getLastObject(): Promise\<FileAsset\> | Deprecated    |
| medialibrary   |  **function** FetchFileResult.getPositionObject(index: number, callback: AsyncCallback\<FileAsset\>): void | Deprecated    |
| medialibrary   |  **function** FetchFileResult.getPositionObject(index: number): Promise\<FileAsset\> | Deprecated    |
| medialibrary   |  **function** FetchFileResult.getAllObject(callback: AsyncCallback\<Array\<FileAsset\>\>): void | Deprecated    |
| medialibrary   |  **function** FetchFileResult.getAllObject(): Promise\<Array\<FileAsset\>\> | Deprecated    |
| medialibrary   |  **function** Album.commitModify(callback: AsyncCallback\<void\>): void | Deprecated    |
| medialibrary   |  **function** Album.commitModify(): Promise\<void\> | Deprecated    |
| medialibrary   |  **function** Album.getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult\>): void | Deprecated    |
| medialibrary   |  **function** Album.getFileAssets(options?: MediaFetchOptions): Promise\<FetchFileResult\> | Deprecated    |
| medialibrary   |  **enum** DeviceType | Deprecated    |
| medialibrary   |  **enum** FileKey | Deprecated    |
| medialibrary   |  **enum** DirectoryType | Deprecated    |
| medialibrary   |  **enum** MediaType | Deprecated    |
| medialibrary   |  **interface** PeerInfo | Deprecated    |
| medialibrary   |  **interface** Size  | Deprecated    |
| medialibrary   |  **interface** MediaFetchOptions | Deprecated    |
| medialibrary   |  **interface** MediaAssetOption | Deprecated    |
| medialibrary   |  **interface** MediaSelectOption | Deprecated    |
| medialibrary   |  **interface** FileAsset | Deprecated    |

**Adaptation Guide**

For example, refer to the code snippet below to call an API to select an image:

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

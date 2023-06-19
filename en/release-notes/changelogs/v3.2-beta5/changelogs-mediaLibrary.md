# File Subsystem Changelog

## cl.file.1 mediaLibrary APIs Changed

All APIs provided by the mediaLibrary module of the multimedia subsystem are deprecated.

**Change Impact**

All APIs described in [mediaLibrary](../../../application-dev/reference/apis/js-apis-medialibrary.md) are deprecated. Third-party applications can only select and save files in the public directory by calling the APIs of [FilePicker](../../../application-dev/reference/apis/js-apis-file-picker.md).
For applications developed based on earlier versions, pay attention to the changes of APIs.

**Key API/Component Changes**

The table below lists the **mediaLibrary** APIs that can be substituted by the **FilePicker** APIs.

| Module                   | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------------------------------------------------ | -------- |
| medialibrary   |  **function** getMediaLibrary(context: Context): MediaLibrary; | Deprecated    |
| medialibrary   |  **function** getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult\>): void | Deprecated    |
| medialibrary   |  **function** getFileAssets(options: MediaFetchOptions): Promise\<FetchFileResult\> | Deprecated    |
| medialibrary   |  **function** createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback\<FileAsset\>): void | Deprecated    |
| medialibrary   |  **function** createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise\<FileAsset\> | Deprecated    |
| medialibrary   |  **function** getPublicDirectory(type: DirectoryType, callback: AsyncCallback\<string\>): void | Deprecated    |
| medialibrary   |  **function** getPublicDirectory(type: DirectoryType): Promise\<string\> | Deprecated    |
| medialibrary   |  **function** release(callback: AsyncCallback\<void\>): void  | Deprecated    | 
| medialibrary   |  **function** release(): Promise\<void\> | Deprecated    |
| medialibrary   |  **function** FileAsset.open(mode: string, callback: AsyncCallback\<number\>): void | Deprecated    |
| medialibrary   |  **function** FileAsset.open(mode: string): Promise\<number\> | Deprecated    |
| medialibrary   |  **function** FileAsset.close(fd: number, callback: AsyncCallback\<void\>): void | Deprecated    |
| medialibrary   |  **function** FileAsset.close(fd: number): Promise\<void\> | Deprecated    |
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
| medialibrary   |  **function** Album.getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult\>): void | Deprecated    |
| medialibrary   |  **function** Album.getFileAssets(options?: MediaFetchOptions): Promise\<FetchFileResult\> | Deprecated    |
| medialibrary   |  **enum** FileKey | Deprecated    |
| medialibrary   |  **enum** DirectoryType | Deprecated    |
| medialibrary   |  **enum** MediaType | Deprecated    |
| medialibrary   |  **interface** MediaFetchOptions | Deprecated    |
| medialibrary   |  **interface** FileAsset | Deprecated    |

**Adaptation Guide**

**The following example shows how to use the mediaLibrary APIs to edit a file in the public directory:**

1. Call **getMediaLibrary** to obtain a **mediaLibrary** instance.
2. Create a **MediaFetchOptions** object, and call **getFileAssets** to obtain files in the public directory.
3. Call the **FetchFileResult** APIs to obtain the file asset of the target file.
4. Call **fileAsset.open** to open the file and obtain the FD.
5. Call [fs.writeSync](../../../application-dev/reference/apis/js-apis-file-fs.md#writesync) to edit the file through the FD.
6. After the edit, call **fileAsset.close** to close the FD of the file.
7. Call **fetchFileResult.close** to release the resources occupied by **getFileAssets**.
8. Call **release** to release the **mediaLibrary** instance.

**Example**

```js
import mediaLibrary from '@ohos.multimedia.mediaLibrary';
import fs from '@ohos.file.fs';

async function example() {
  try {
    let context = getContext(this);
    let media = mediaLibrary.getMediaLibrary(context);
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + ' DESC',
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const fileAsset = await fetchFileResult.getFirstObject();
    console.info('mediaLibrary fileAsset displayName: ' + fileAsset.displayName);
    let fd = await fileAsset.open('rw');
    console.info('mediaLibrary fileAsset open fd: ' + fd);
    let writeLen = fs.writeSync(fd, 'hello, world');
    console.info('write data to file succeed and size is: ' + writeLen);
    fileAsset.close(fd);
    fetchFileResult.close();
    media.release();
  } catch (err) {
    console.error('mediaLibrary fail, err: ' + err);
  }
}
```

**The following example shows how to use the FilePicker APIs to edit a file in the public directory:**

1. Obtain a **DocumentViewPicker** object.
2. Call **DocumentViewPicker.select** to select a file.
3. After a file is selected, a file URI is returned.
4. After the UI is returned from DocumentViewPicker, call [fs.openSync](../../../application-dev/reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD.
5. Call [fs.writeSync](../../../application-dev/reference/apis/js-apis-file-fs.md#writesync) to edit the file through the FD.
6. After the edit, call [fs.closeSync](../../../application-dev/reference/apis/js-apis-file-fs.md#closesync) to close the FD.

**Example**

```js
import mediaLibrary from '@ohos.multimedia.mediaLibrary';
import picker from '@ohos.file.picker';
import fs from '@ohos.file.fs';

let uri;

async function example() {
  try {
    let DocumentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.select(DocumentSelectOptions).then((DocumentSelectResult) => {
      console.info('DocumentViewPicker.select successfully, DocumentSelectResult uri: ' + JSON.stringify(DocumentSelectResult));
      uri = DocumentSelectResult[0];
    }).catch((err) => {
      console.error('DocumentViewPicker.select failed with err: ' + err);
    });
  } catch (err) {
    console.error('DocumentViewPicker failed with err: ' + err);
  }
}

async function writeFile() {
  try {
    let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
    console.info('DocumentViewPicker file fd: ' + file.fd);
    let writeLen = fs.writeSync(file.fd, 'hello, world');
    console.info('write data to file succeed and size is: ' + writeLen);
    fs.closeSync(file);
  } catch (err) {
    console.error('DocumentViewPicker fail, err: ' + err);
  }
}
```

**The following example shows how to use the mediaLibrary APIs to create a file in the public directory:**

1. Call **getMediaLibrary** to obtain a **mediaLibrary** instance.
2. Call **getPublicDirectory** to obtain the path of the public directory.
3. Call **createAsset** to create a file and obtain the file asset.
4. Call **fileAsset.open** to open the file and obtain the FD.
5. Call **fs.write** to edit the file through the FD.
6. After the edit, call **fileAsset.close** to close the FD.
7. Call **release** to release the **mediaLibrary** instance.

**Example**

```js
import mediaLibrary from '@ohos.multimedia.mediaLibrary';
import fs from '@ohos.file.fs';

async function example() {
  try {
    let context = getContext(this);
    let media = mediaLibrary.getMediaLibrary(context);
    let mediaType = mediaLibrary.MediaType.FILE;
    let DIR_DOWNLOAD = mediaLibrary.DirectoryType.DIR_DOWNLOAD;
    const path = await media.getPublicDirectory(DIR_DOWNLOAD);
    const fileAsset = await media.createAsset(mediaType, 'test.txt', path);
    console.info('mediaLibrary fileAsset displayName: ' + fileAsset.displayName);
    let fd = await fileAsset.open('rw');
    console.info('mediaLibrary fileAsset open fd: ' + fd);
    let writeLen = fs.writeSync(fd, 'hello, world');
    console.info('write data to file succeed and size is: ' + writeLen);
    fileAsset.close(fd);
    media.release();
  } catch (err) {
    console.error('mediaLibrary fail, err: ' + err);
  }
}
```

**The following example shows how to use the FilePicker APIs to create a file in the public directory:**

1. Obtain a **DocumentViewPicker** object.
2. Call **DocumentViewPicker.save** to create and save an empty file.
3. After the file is saved, a file URI is returned.
4. After the UI is returned from DocumentViewPicker, call [fs.openSync](../../../application-dev/reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD.
5. Call [fs.writeSync](../../../application-dev/reference/apis/js-apis-file-fs.md#writesync) to edit the file through the FD.
6. After the edit, call [fs.closeSync](../../../application-dev/reference/apis/js-apis-file-fs.md#closesync) to close the FD.

**Example**

```js
import mediaLibrary from '@ohos.multimedia.mediaLibrary';
import picker from '@ohos.file.picker';
import fs from '@ohos.file.fs';

let uri;

async function example() {
  try {
    let DocumentSaveOptions = new picker.DocumentSaveOptions();
    DocumentSaveOptions.newFileNames = ['DocumentViewPicker01.txt'];
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.save(DocumentSaveOptions).then((DocumentSaveResult) => {
      console.info('DocumentViewPicker.save successfully, DocumentSaveResult uri: ' + JSON.stringify(DocumentSaveResult));
      uri = DocumentSaveResult[0];
    }).catch((err) => {
      console.error('DocumentViewPicker.save failed with err: ' + err);
    });
  } catch (err) {
    console.error('DocumentViewPicker failed with err: ' + err);
  }
}

async function writeFile() {
  try {
    let file = fs.openSync(uri, fs.OpenMode.READ_WRITE);
    console.info('DocumentViewPicker file fd: ' + file.fd);
    let writeLen = fs.writeSync(file.fd, 'hello, world');
    console.info('write data to file succeed and size is: ' + writeLen);
    fs.closeSync(file);
  } catch (err) {
    console.error('DocumentViewPicker fail, err: ' + err);
  }
}
```

**Key API/Component Changes**

The table below lists the mediaLibrary APIs that are not open to third-party applications due to function control. There are no substitute APIs for them.

| Module                   | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------------------------------------------------ | -------- |
| medialibrary   |  **function** getMediaLibrary(): MediaLibrary; | Deprecated    |
| medialibrary   |  **function** on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void\>): void | Deprecated    |
| medialibrary   |  **function** off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void\>): void | Deprecated    |
| medialibrary   |  **function** deleteAsset(uri: string): Promise\<void\> | Deprecated    |
| medialibrary   |  **function** deleteAsset(uri: string, callback: AsyncCallback\<void\>): void | Deprecated    |
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
| medialibrary   |  **function** getAlbums(options: MediaFetchOptions, callback: AsyncCallback\<Array\<Album\>\>): void | Deprecated    |
| medialibrary   |  **function** getAlbums(options: MediaFetchOptions): Promise\<Array\<Album\>\> | Deprecated    |
| medialibrary   |  **function** Album.commitModify(callback: AsyncCallback\<void\>): void | Deprecated    |
| medialibrary   |  **function** Album.commitModify(): Promise\<void\> | Deprecated    |
| medialibrary   |  **enum** DeviceType | Deprecated    |
| medialibrary   |  **interface** PeerInfo | Deprecated    |
| medialibrary   |  **interface** Size  | Deprecated    |
| medialibrary   |  **interface** MediaAssetOption | Deprecated    |
| medialibrary   |  **interface** MediaSelectOption | Deprecated    |

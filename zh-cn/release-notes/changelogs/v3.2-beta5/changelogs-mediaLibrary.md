# 文件子系统ChangeLog

## cl.file.1 mediaLibrary相关接口变更

multimedia 部件 mediaLibrary所有接口废弃。

**变更影响**

[mediaLibrary](../../../application-dev/reference/apis/js-apis-medialibrary.md)所有接口废弃。系统只对三方应用开放公共目录下文件资源选择和保存功能，由[FilePicker](../../../application-dev/reference/apis/js-apis-file-picker.md)提供能力。
基于此前版本开发的应用，需注意废弃接口的迭代更新。

**关键接口/组件变更**

以下为可以使用FilePicker替代的接口。

| 模块名                    | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------------------------------------------------ | -------- |
| medialibrary   |  **function** getMediaLibrary(context: Context): MediaLibrary; | 废弃     |
| medialibrary   |  **function** getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult\>): void | 废弃     |
| medialibrary   |  **function** getFileAssets(options: MediaFetchOptions): Promise\<FetchFileResult\> | 废弃     |
| medialibrary   |  **function** createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback\<FileAsset\>): void | 废弃     |
| medialibrary   |  **function** createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise\<FileAsset\> | 废弃     |
| medialibrary   |  **function** getPublicDirectory(type: DirectoryType, callback: AsyncCallback\<string\>): void | 废弃     |
| medialibrary   |  **function** getPublicDirectory(type: DirectoryType): Promise\<string\> | 废弃     |
| medialibrary   |  **function** release(callback: AsyncCallback\<void\>): void  | 废弃     | 
| medialibrary   |  **function** release(): Promise\<void\> | 废弃     |
| medialibrary   |  **function** FileAsset.open(mode: string, callback: AsyncCallback\<number\>): void | 废弃     |
| medialibrary   |  **function** FileAsset.open(mode: string): Promise\<number\> | 废弃     |
| medialibrary   |  **function** FileAsset.close(fd: number, callback: AsyncCallback\<void\>): void | 废弃     |
| medialibrary   |  **function** FileAsset.close(fd: number): Promise\<void\> | 废弃     |
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
| medialibrary   |  **function** Album.getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult\>): void | 废弃     |
| medialibrary   |  **function** Album.getFileAssets(options?: MediaFetchOptions): Promise\<FetchFileResult\> | 废弃     |
| medialibrary   |  **enum** FileKey | 废弃     |
| medialibrary   |  **enum** DirectoryType | 废弃     |
| medialibrary   |  **enum** MediaType | 废弃     |
| medialibrary   |  **interface** MediaFetchOptions | 废弃     |
| medialibrary   |  **interface** FileAsset | 废弃     |

**适配指导**

**使用mediaLibrary接口编辑公共目录下的文件示例：**

1. 使用getMediaLibrary接口获取媒体库实例。
2. 创建MediaFetchOptions检索条件使用mediaLibrary实例调用getFileAssets接口获取公共目录下的文件。
3. 使用FetchFileResult相应接口获取目的文件的fileAsset。
4. 使用fileAsset.open接口打开这个文件得到fd。
5. 通过fd使用[fs.writeSync](../../../application-dev/reference/apis/js-apis-file-fs.md#writesync)接口对这个文件进行编辑修改。
6. 修改完成后使用fileAsset.close接口关闭这个文件的fd。
7. 使用fetchFileResult.close接口释放getFileAssets时占用的资源。
8. 使用release接口释放媒体库实例。

**示例：**

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

**使用FilePicker编辑公共目录下的文件示例：**

1. 获取DocumentViewPicker文件选择器对象。
2. 拉起DocumentViewPicker.select接口选择目的文件。
3. 用户选择完后返回目的文件的uri。
4. 待界面从DocumentViewPicker返回后在其他函数中使用[fs.openSync](../../../application-dev/reference/apis/js-apis-file-fs.md#fsopensync)接口通过uri打开这个文件得到fd。
5. 通过fd使用[fs.writeSync](../../../application-dev/reference/apis/js-apis-file-fs.md#writesync)接口对这个文件进行编辑修改。
6. 编辑修改完毕后使用[fs.closeSync](../../../application-dev/reference/apis/js-apis-file-fs.md#closesync)接口关闭这个fd。

**示例：**

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

**使用mediaLibrary接口在公共目录下创建文件示例：**

1. 使用getMediaLibrary接口获取媒体库实例。
2. 使用getPublicDirectory接口获取公共目录路径。
3. 使用createAsset接口创建文件得到这个文件的fileAsset。
4. 使用fileAsset.open接口打开这个文件得到fd。
5. 通过fd使用fs.write接口对这个文件进行编辑修改。
6. 修改完成后使用fileAsset.close接口关闭这个文件的fd。
7. 使用release接口释放媒体库实例。

**示例：**

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

**使用FilePicker在公共目录下创建文件示例：**

1. 获取DocumentViewPicker文件选择器对象。
2. 拉起DocumentViewPicker.save接口创建保存一个空的文件。
3. 用户保存完后返回目的文件的uri。
4. 待界面从DocumentViewPicker返回后在其他函数中使用[fs.openSync](../../../application-dev/reference/apis/js-apis-file-fs.md#fsopensync)接口通过uri打开这个文件得到fd。
5. 通过fd使用[fs.writeSync](../../../application-dev/reference/apis/js-apis-file-fs.md#writesync)接口对这个文件进行编辑修改。
6. 编辑修改完毕后使用[fs.closeSync](../../../application-dev/reference/apis/js-apis-file-fs.md#closesync)接口关闭这个fd。

**示例：**

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

**关键接口/组件变更**

medialibrary以下废弃接口由于功能管控，不对三方应用开放，无替代接口。

| 模块名                    | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------------------------------------------------ | -------- |
| medialibrary   |  **function** getMediaLibrary(): MediaLibrary; | 废弃     |
| medialibrary   |  **function** on(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback: Callback\<void\>): void | 废弃     |
| medialibrary   |  **function** off(type: 'deviceChange'\|'albumChange'\|'imageChange'\|'audioChange'\|'videoChange'\|'fileChange'\|'remoteFileChange', callback?: Callback\<void\>): void | 废弃     |
| medialibrary   |  **function** deleteAsset(uri: string): Promise\<void\> | 废弃     |
| medialibrary   |  **function** deleteAsset(uri: string, callback: AsyncCallback\<void\>): void | 废弃     |
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
| medialibrary   |  **function** getAlbums(options: MediaFetchOptions, callback: AsyncCallback\<Array\<Album\>\>): void | 废弃     |
| medialibrary   |  **function** getAlbums(options: MediaFetchOptions): Promise\<Array\<Album\>\> | 废弃     |
| medialibrary   |  **function** Album.commitModify(callback: AsyncCallback\<void\>): void | 废弃     |
| medialibrary   |  **function** Album.commitModify(): Promise\<void\> | 废弃     |
| medialibrary   |  **enum** DeviceType | 废弃     |
| medialibrary   |  **interface** PeerInfo | 废弃     |
| medialibrary   |  **interface** Size  | 废弃     |
| medialibrary   |  **interface** MediaAssetOption | 废弃     |
| medialibrary   |  **interface** MediaSelectOption | 废弃     |
# 文件子系统ChangeLog

## cl.file.1 mediaLibrary相关接口兼容性变更

mediaLibrary部分接口兼容性变更。

**变更影响**

[mediaLibrary](../../../application-dev/reference/apis/js-apis-medialibrary.md)部分接口兼容性变更。
基于此前版本开发的应用，需注意接口的迭代更新。

**关键接口/组件变更**

| 模块名                    | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------------------------------------------------ | -------- |
| medialibrary   |  **function** getFileAssets(options: MediaFetchOptions, callback: AsyncCallback&lt;FetchFileResult&gt;): void | 接口兼容性变更     |
| medialibrary   |  **function** getFileAssets(options: MediaFetchOptions): Promise&lt;FetchFileResult&gt; | 接口兼容性变更     |
| medialibrary   |  **function** createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback&lt;FileAsset&gt;): void| 接口兼容性变更     |
| medialibrary   |  **function** createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise&lt;FileAsset&gt;| 接口兼容性变更     |
| medialibrary   |  **function** getAlbums(options: MediaFetchOptions, callback: AsyncCallback&lt;Array&lt;Album&gt;&gt;): void | 接口兼容性变更     |
| medialibrary   |  **function** getAlbums(options: MediaFetchOptions): Promise&lt;Array&lt;Album&gt;&gt; | 接口兼容性变更     |
| medialibrary   |  **function** FileAsset.commitModify(callback: AsyncCallback&lt;void&gt;): void | 接口兼容性变更     |
| medialibrary   |  **function** FileAsset.commitModify(): Promise&lt;void&gt; | 接口兼容性变更     |
| medialibrary   |  **function** FileAsset.deleteAsset(uri: string, callback: AsyncCallback&lt;void&gt;): void | 接口兼容性变更     |
| medialibrary   |  **function** FileAsset.deleteAsset(uri: string): Promise&lt;void&gt; | 接口兼容性变更     |

**适配指导**

**getFileAssets接口获取文件资源兼容性影响：**

在API version 10上，摒弃了物理目录作为相册的设计，采用了逻辑相册的设计，一个相册中可以添加多个文件，一个文件也可以在多个相册中呈现。新的设计将带来parent、albumId、albumUri和albumName属性使用上的不兼容，无法作为MediaFetchOptions的参数在getFileAssets接口中使用。下面示例代码为错误示例：

1. 使用[getMediaLibrary](../../../application-dev/reference/apis/js-apis-medialibrary.md#medialibrarygetmedialibrary)接口获取媒体库实例。
2. 创建检索条件[MediaFetchOptions](../../../application-dev/reference/apis/js-apis-medialibrary.md#mediafetchoptions7)。
3. 调用[getFileAssets](../../../application-dev/reference/apis/js-apis-medialibrary.md#getfileassets7)接口获取文件资源。

**错误示例：**

```js
import mediaLibrary from '@ohos.multimedia.mediaLibrary';

async function example() {
  try {
    let context = getContext(this);
    let media = mediaLibrary.getMediaLibrary(context);
    let fileKeyObj = mediaLibrary.FileKey;
    let albumId = 1;
    let getImageOp = {
      selections: fileKeyObj.ALBUM_ID + '= ?', // 使用parent、albumId、albumUri和albumName属性查询均无法获取文件资源。
      selectionArgs: [albumId.toString()],
    };
    const fetchFileResult = await media.getFileAssets(getImageOp); // 查询失败，获取的fetchFileResult为空。
    const fileAsset = await fetchFileResult.getFirstObject();
    console.info('mediaLibrary fileAsset displayName: ' + fileAsset.displayName);
  } catch (err) {
    console.error('mediaLibrary fail, err: ' + err);
  }
}
```

推荐使用以下方式调用getFileAssets接口获取文件资源：

**正确示例：**

```js
import mediaLibrary from '@ohos.multimedia.mediaLibrary';

async function example() {
  try {
    let context = getContext(this);
    let media = mediaLibrary.getMediaLibrary(context);
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],  // 查询所有图片类型的文件。
    };
    const fetchFileResult = await media.getFileAssets(getImageOp); 
    const fileAsset = await fetchFileResult.getFirstObject();
    console.info('mediaLibrary fileAsset displayName: ' + fileAsset.displayName);
  } catch (err) {
    console.error('mediaLibrary fail, err: ' + err);
  }
}
```

**createAsset接口创建相册兼容性影响：**

由于API version 10的SDK上relativePath和相册没有关联关系，文件创建成功后，relativePath的最后一级目录不会作为相册呈现。

**getAlbums接口获取相册兼容性影响：**

由于API version 10的SDK上relativePath和相册没有关联关系，在使用getAlbums时不支持relativePath作为查询条件，并且ALBUM_NAME参数只能使用"Camera"和"Screenshots"。下面示例代码为错误示例：

1. 使用[getMediaLibrary](../../../application-dev/reference/apis/js-apis-medialibrary.md#medialibrarygetmedialibrary)接口获取媒体库实例。
2. 创建相册检索条件[MediaFetchOptions](../../../application-dev/reference/apis/js-apis-medialibrary.md#mediafetchoptions7)。
3. 调用[getAlbums](../../../application-dev/reference/apis/js-apis-medialibrary.md#getalbums7)接口获取相册。

**错误示例：**

```js
import mediaLibrary from '@ohos.multimedia.mediaLibrary';

async function example() {
  try {
    let context = getContext(this);
    let media = mediaLibrary.getMediaLibrary(context);
    let AlbumNoArgsfetchOp = {
      selections: mediaLibrary.FileKey.ALBUM_NAME + ' = ?',
      selectionArgs: ['新建相册1'], // 获取albumName为新建相册1的相册。
    };
    const albumList = await media.getAlbums(AlbumNoArgsfetchOp); // 查询失败，获取的fetchFileResult为空。
    for (let i = 0; i < albumList.length; i++) {
      console.info('mediaLibrary album albumName: ' + albumList[i].albumName);
    }
  } catch (err) {
    console.error('mediaLibrary fail, err: ' + err);
  }
}
```

使用如下示例代码可以获取Camera和Screenshots相册。

**正确示例：**

```js
import mediaLibrary from '@ohos.multimedia.mediaLibrary';

async function example() {
  try {
    let context = getContext(this);
    let media = mediaLibrary.getMediaLibrary(context);
    let AlbumNoArgsfetchOp = {
      selections: mediaLibrary.FileKey.ALBUM_NAME + ' = ? OR ' + mediaLibrary.FileKey.ALBUM_NAME + ' = ?',
      selectionArgs: ['Camera', 'Screenshots'], // 获取相机相册和截屏录屏相册。
    };
    const albumList = await media.getAlbums(AlbumNoArgsfetchOp);
    for (let i = 0; i < albumList.length; i++) {
      console.info('mediaLibrary album albumName: ' + albumList[i].albumName);
    }
  } catch (err) {
    console.error('mediaLibrary fail, err: ' + err);
  }
}
```

**FileAsset.commitModify接口获取相册兼容性影响：**

在API version 10的SDK上去掉了针对audio无意义的orientation属性，在使用commitModify接口时将无法对audio资源的orientation属性进行修改。

**FileAsset.deleteAsset接口删除媒体文件资源兼容性影响：**

修复了文件删除机制的已知问题。该问题会导致系统应用可以通过MediaLibrary.deleteAsset方法将一个没有进入回收站的文件直接彻底删除。

对于系统应用，彻底删除一个文件应该按照以下步骤进行操作：

1. 调用[getFileAssets](../../../application-dev/reference/apis/js-apis-medialibrary.md#getfileassets7)接口获取文件资源。
2. 然后调用[FileAsset.trash](../../../application-dev/reference/apis/js-apis-medialibrary.md#trash8)接口将文件放入回收站。
3. 最后调用[MediaLibrary.deleteAsset](../../../application-dev/reference/apis/js-apis-medialibrary.md#deleteasset8)方法将文件彻底删除。

**正确示例：**

```js
import mediaLibrary from '@ohos.multimedia.mediaLibrary';

async function example() {
  try {
    let context = getContext(this);
    let media = mediaLibrary.getMediaLibrary(context);
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
    };
    const fetchFileResult = await media.getFileAssets(getImageOp); 
    const fileAsset = await fetchFileResult.getFirstObject();
    // 将文件删除（放入系统图库的回收站）。
    await fileAsset.trash(true);
    // 将文件从系统中彻底删除。
    await media.deleteAsset(fileAsset.uri);
  } catch (err) {
    console.error('Failed to delete asset permanently from system, error: ' + err);
  }
}
```

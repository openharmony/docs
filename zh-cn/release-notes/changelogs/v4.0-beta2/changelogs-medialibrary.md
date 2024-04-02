# 文件管理Changelog


## cl.file.1 mediaLibrary部分接口兼容性变更

mediaLibrary部分接口兼容性变更。

**变更影响**

mediaLibrary部分接口兼容性变更。

基于此前版本开发的应用，需注意接口的迭代更新。

**关键接口/组件变更**

| 模块名 | 方法/属性/枚举/常量 | 变更类型 | 
| -------- | -------- | -------- |
| medialibrary | **function**&nbsp;getFileAssets(options:&nbsp;MediaFetchOptions,&nbsp;callback:&nbsp;AsyncCallback&lt;FetchFileResult&gt;):&nbsp;void | 接口兼容性变更 | 
| medialibrary | **function**&nbsp;getFileAssets(options:&nbsp;MediaFetchOptions):&nbsp;Promise&lt;FetchFileResult&gt; | 接口兼容性变更 | 
| medialibrary | **function**&nbsp;createAsset(mediaType:&nbsp;MediaType,&nbsp;displayName:&nbsp;string,&nbsp;relativePath:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;FileAsset&gt;):&nbsp;void | 接口兼容性变更 | 
| medialibrary | **function**&nbsp;createAsset(mediaType:&nbsp;MediaType,&nbsp;displayName:&nbsp;string,&nbsp;relativePath:&nbsp;string):&nbsp;Promise&lt;FileAsset&gt; | 接口兼容性变更 | 
| medialibrary | **function**&nbsp;getAlbums(options:&nbsp;MediaFetchOptions,&nbsp;callback:&nbsp;AsyncCallback&lt;Array&lt;Album&gt;&gt;):&nbsp;void | 接口兼容性变更 | 
| medialibrary | **function**&nbsp;getAlbums(options:&nbsp;MediaFetchOptions):&nbsp;Promise&lt;Array&lt;Album&gt;&gt; | 接口兼容性变更 | 
| medialibrary | **function**&nbsp;FileAsset.commitModify(callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 接口兼容性变更 | 
| medialibrary | **function**&nbsp;FileAsset.commitModify():&nbsp;Promise&lt;void&gt; | 接口兼容性变更 | 

**适配指导**

**getFileAssets接口获取文件资源兼容性影响：**

在API version 10上，摒弃了物理目录作为相册的设计，采用了逻辑相册的设计，一个相册中可以添加多个文件，一个文件也可以在多个相册中呈现。新的设计将带来parent、albumId、albumUri和albumName属性使用上的不兼容，无法作为MediaFetchOptions的参数在getFileAssets接口中使用。下面示例代码为错误示例：

1. 使用getMediaLibrary接口获取媒体库实例。

2. 创建检索条件MediaFetchOptions。

3. 调用getFileAssets接口获取文件资源。

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

1. 使用getMediaLibrary接口获取媒体库实例。

2. 创建相册检索条件MediaFetchOptions。

3. 调用getAlbums接口获取相册。

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

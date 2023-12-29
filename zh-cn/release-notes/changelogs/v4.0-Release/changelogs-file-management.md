# 文件管理变更说明

## cl.file.1 @ohos.file.storageStatistics和@ohos.file.volumeManager 文档错误码变更

[@ohos.file.storageStatistics](../../../application-dev/reference/apis/js-apis-file-storage-statistics.md#)和[@ohos.file.volumeManager](../../../application-dev/reference/apis/js-apis-file-volumemanager.md#)两个模块中所有接口Unknown error错误码变更, d.ts中记录的错误码与实际功能代码中返回的不相符。

变更前每个接口Unknown error的错误码为13900032。

变更后每个接口Unknown error的错误码为13900042。

**变更影响**

功能代码中，针对“Unknown error”从首版本开始一直返回13900042，仅接口定义d.ts文件与API文档记录错误。

对原来的“13900032 Unknown error”进行了特殊处理的应用，需要进行排查，并修改为139000342。

**关键接口/组件变更**

涉及@ohos.file.storageStatistics模块和@ohos.file.volumemanager模块中的所有接口。

**适配指导**

针对Unknown error进行特殊处理的应用需要将错误码更改为13900042。

## cl.file.2 userFileManager FileAsset属性变更

[userFileManager.FileAsset](../../../application-dev/reference/apis/js-apis-userFileManager.md#fileasset)属性变更。

变更前uri的格式为：

'file://media/\<file_type\>/\<file_id\>/?networkid=xxx'

变更后uri的格式为：

'file://media/Photo/\<id\>/IMG_datetime_0001/displayName.jpg'

**变更影响**

基于此前版本开发的应用，请排查是否对媒体库uri有依赖或者解析，如有依赖请尽快进行适配修改。file_id并不保证唯一，请不要对id进行解析，能使用id的地方都可以使用uri进行代替。

**关键接口/组件变更**

| 模块名                    | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------------------------------------------------ | -------- |
| userFileManager   |   **interface** FileAsset | 属性变更     |

**适配指导**

在API version 10上，对公共文件uri格式进行调整，实现通过uri获取文件名等文件基础信息。新的格式将会导致对uri进行解析的方式会存在无法达到预期效果的情况，例如对uri为 'file://media/image/8'进行解析获取uri结尾的id为8，采用变更后的格式有可能得到的是文件的displayName。推荐直接使用uri进行获取文件资源。

**正确示例：**

```js
import userFileManager from '@ohos.filemanagement.userFileManager';
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  let context = getContext(this);
  let mgr = userFileManager.getUserFileMgr(context);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let uri = 'file://media/Photo/1/IMG_datetime_0001/displayName.jpg' // 需保证此uri已存在。
  predicates.equalTo('uri', uri);
  let fetchOptions = {
    fetchColumns: ['uri'],
    predicates: predicates
  };

  mgr.getPhotoAssets(fetchOptions, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      console.info('fetchResult success');
      let fileAsset = await fetchResult.getFirstObject();
      if (fileAsset != undefined) {
        console.info('fileAsset.displayName : ' + fileAsset.displayName);
      }
    } else {
      console.error('fetchResult fail' + err);
    }
  });
}
```

## cl.file.3 photoAccessHelper PhotoAsset属性变更

[photoAccessHelper.PhotoAsset](../../../application-dev/reference/apis/js-apis-photoAccessHelper.md#photoasset)属性变更。

变更前uri的格式为：

'file://media/\<file_type\>/\<file_id\>/?networkid=xxx'

变更后uri的格式为：

'file://media/Photo/\<id\>/IMG_datetime_0001/displayName.jpg'

**变更影响**

基于此前版本开发的应用，请排查是否对媒体库uri有依赖或者解析，如有依赖请尽快进行适配修改。file_id并不保证唯一，请不要对id进行解析，能使用id的地方都可以使用uri进行代替。

**关键接口/组件变更**

| 模块名                    | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------------------------------------------------ | -------- |
| photoAccessHelper   |   **interface** PhotoAsset | 属性变更     |

**适配指导**

在API version 10上，对公共文件uri格式进行调整，实现通过uri获取文件名等文件基础信息。新的格式将会导致对uri进行解析的方式会存在无法达到预期效果的情况，例如对uri为 'file://media/image/8'进行解析获取uri结尾的id为8，采用变更后的格式有可能得到的是文件的displayName。推荐直接使用uri进行获取文件资源。

**正确示例：**

```js
import photoAccessHelper from '@ohos.file.photoAccessHelper';
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  let context = getContext(this);
  let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let uri = 'file://media/Photo/1/IMG_datetime_0001/displayName.jpg' // 需保证此uri已存在。
  predicates.equalTo('uri', uri);
  let fetchOptions = {
    fetchColumns: ['uri'],
    predicates: predicates
  };

  phAccessHelper.getAssets(fetchOptions, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      console.info('fetchResult success');
      let photoAsset = await fetchResult.getFirstObject();
      if (photoAsset != undefined) {
        console.info('photoAsset.displayName : ' + photoAsset.displayName);
      }
    } else {
      console.error('fetchResult fail' + err);
    }
  });
}
```

## cl.file.4 fileAccess模块变更

1. 文件访问框架管理的资源范围发生变化，不再支持访问媒体库管理的资源。目前文件访问框架支持以下目录：
   - 外部存储目录
   - Docs目录
   - Download目录
   - Desktop目录
   - Documents目录
   - Share共享盘目录

   fileAccess将不再支持获取缩略图和媒体资源的部分属性查询。

2. uri格式发生变化，开发者无需解析具体格式。

**变更影响**

基于此前版本开发的应用，请排查是否有使用媒体库的接口操作通过fileAccess获取的uri，将会无法达成预期结果。

**关键的接口/组件变更**

删除接口如下

| 类名           | 删除接口声明                                                 |
| -------------- | ------------------------------------------------------------ |
| fileAccessHelper | getThumbnail(uri: string, size: image.Size, callback: AsyncCallback<image.PixelMap>): void;|

枚举FileKey删除部分值：

| 枚举类型 | 删除的键值 |
| -------- | ---- |
| FileKey | DURATION = 'duration' |
| FileKey | WIDTH = 'width' |
| FileKey | HEIGHT = 'height' |

**适配指导**

fileAccess的接口调用无变化，但接口返回的uri可访问的资源发生变化。

如需获取文件名、路径等属性，请使用[fileuri接口](../../../application-dev/reference/apis/js-apis-file-fileuri.md)。

使用文件访问框架的接口获取的uri，推荐使用[fs接口](../../../application-dev/reference/apis/js-apis-file-fs.md)打开。


## cl.file.5 补充PhotoAccessHelper模块错误码

@ohos.file.photoAccessHelper.d.ts中补充错误码。错误码详细含义可参考[文件管理子系统错误码](../../../application-dev/reference/errorcodes/errorcode-filemanagement.md)

**变更影响**

本次补充了@ohos.file.photoAccessHelper.d.ts中部分接口可能抛出的错误码。只涉及补充jsdoc，不涉及代码逻辑修改。因此兼容性无影响。

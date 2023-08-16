# 文件子系统ChangeLog

## cl.file.1 userFileManager FileAsset属性变更

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

## cl.file.2 photoAccessHelper PhotoAsset属性变更

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

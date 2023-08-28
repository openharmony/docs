# File Subsystem Changelog

## cl.file.1 Change of the userFileManager FileAsset Attribute

Changed the [userFileManager.FileAsset](../../../application-dev/reference/apis/js-apis-userFileManager.md#fileasset) attribute.

URI format before the change:

'file://media/\<file_type\>/\<file_id\>/?networkid=xxx'

URI format after the change:

'file://media/Photo/\<id\>/IMG_datetime_0001/displayName.jpg'

**Change Impact**

For applications developed based on earlier versions, check whether the applications depend on or parse the media library URIs. If yes, make adaptation as required. The value of **file_id** is not unique. Do not parse the file ID. Use the URI instead.

**Key API/Component Changes**

| Module                   | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------------------------------------------------ | -------- |
| userFileManager   |   **interface** FileAsset | Attribute changed    |

**Adaptation Guide**

In API version 10, the URI format of user files is changed so that basic file information (such as the file name) can be obtained based on the URI. If the new format is used, the URI parsing may yield unexpected result. For example, before the change, the ID obtained from the URI **'file://media/image/8'** is 8. If the new URI format is used, the file **displayName** is obtained. You are advised to use the URI to obtain file information.

**Example**:

```js
import userFileManager from '@ohos.filemanagement.userFileManager';
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  let context = getContext(this);
  let mgr = userFileManager.getUserFileMgr(context);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let uri = 'file://media/Photo/1/IMG_datetime_0001/displayName.jpg' // The URI must exist.
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

## cl.file.2 Change of the photoAccessHelper PhotoAsset Attribute

Changed the [photoAccessHelper.PhotoAsset](../../../application-dev/reference/apis/js-apis-photoAccessHelper.md#photoasset) attribute.

URI format before the change:

'file://media/\<file_type\>/\<file_id\>/?networkid=xxx'

URI format after the change:

'file://media/Photo/\<id\>/IMG_datetime_0001/displayName.jpg'

**Change Impact**

For applications developed based on earlier versions, check whether the applications depend on or parse the media library URIs. If yes, make adaptation as required. The value of **file_id** is not unique. Do not parse the file ID. Use the URI instead.

**Key API/Component Changes**

| Module                   | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------------------------------------------------ | -------- |
| photoAccessHelper   |   **interface** PhotoAsset | Attribute changed    |

**Adaptation Guide**

In API version 10, the URI format of user files is changed so that basic file information (such as the file name) can be obtained based on the URI. If the new format is used, the URI parsing may yield unexpected result. For example, before the change, the ID obtained from the URI **'file://media/image/8'** is 8. If the new URI format is used, the file **displayName** is obtained. You are advised to use the URI to obtain file information.

**Example**:

```js
import photoAccessHelper from '@ohos.file.photoAccessHelper';
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  let context = getContext(this);
  let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let uri = 'file://media/Photo/1/IMG_datetime_0001/displayName.jpg' // The URI must exist.
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

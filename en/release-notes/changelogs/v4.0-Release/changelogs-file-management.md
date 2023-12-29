# File Management Changelog

## cl.file.1 Change of Error Codes in @ohos.file.storageStatistics and @ohos.file.volumeManager Documents

Changed the error code of "Unknown error" in all APIs in the API reference documents of the [@ohos.file.storageStatistics](../../../application-dev/reference/apis/js-apis-file-storage-statistics.md#) and [@ohos.file.volumeManager](../../../application-dev/reference/apis/js-apis-file-volumemanager.md#) modules. The error code returned is different from the error code in the d.ts file.

Before the change, the error code of "Unknown error" is **13900032**.

After the change, the error code of "Unknown error" is **13900042**.

**Change Impact**

In the code, **13900042** is returned for "Unknown error" from the first version. The error code of ""Unknown error" is incorrect in the d.ts file and API Reference documents.

For applications that have special processing on "13900032 Unknown error", change the error code to **13900042**.

**Key API/Component Changes**

All APIs in the @ohos.file.storageStatistics and @ohos.file.volumemanager modules are involved.

**Adaptation Guide**

For applications that have special processing on "Unknown error", change the error code to **13900042**.

## cl.file.2 Change of the userFileManager FileAsset Attribute

Changed the [userFileManager.FileAsset](../../../application-dev/reference/apis/js-apis-userFileManager.md#fileasset) attribute.

URI format before the change:

'file://media/\<file_type\>/\<file_id\>/?networkid=xxx'

URI format after the change:

'file://media/Photo/\<id\>/IMG_datetime_0001/displayName.jpg'

**Change Impact**

For applications developed based on earlier versions, check whether the applications depend on or parse the media library URIs. If yes, make adaptation as required. Do not parse **file_id**, which is not unique. Use the file URI instead.

**Key API/Component Changes**

| Module                   | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------------------------------------------------ | -------- |
| userFileManager   |   **interface** FileAsset | Attribute changed    |

**Adaptation Guide**

In API version 10, the user file URI format is changed so that basic file information (such as the file name) can be obtained based on the URI. If the new format is used, the URI parsing may yield unexpected result. For example, before the change, the ID obtained from the URI **'file://media/image/8'** is 8. If the new URI format is used, the file **displayName** is obtained. You are advised to use the URI to obtain file information.

**Example (correct)**:

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

## cl.file.3 Change of the photoAccessHelper PhotoAsset Attribute

Changed the [photoAccessHelper.PhotoAsset](../../../application-dev/reference/apis/js-apis-photoAccessHelper.md#photoasset) attribute.

URI format before the change:

'file://media/\<file_type\>/\<file_id\>/?networkid=xxx'

URI format after the change:

'file://media/Photo/\<id\>/IMG_datetime_0001/displayName.jpg'

**Change Impact**

For applications developed based on earlier versions, check whether the applications depend on or parse the media library URIs. If yes, make adaptation as required. Do not parse **file_id**, which is not unique. Use the file URI instead.

**Key API/Component Changes**

| Module                   | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------------------------------------------------ | -------- |
| photoAccessHelper   |   **interface** PhotoAsset | Attribute changed    |

**Adaptation Guide**

In API version 10, the user file URI format is changed so that basic file information (such as the file name) can be obtained based on the URI. If the new format is used, the URI parsing may yield unexpected result. For example, before the change, the ID obtained from the URI **'file://media/image/8'** is 8. If the new URI format is used, the file **displayName** is obtained. You are advised to use the URI to obtain file information.

**Example (correct)**:

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

## cl.file.4 Change of the fileAccess Module

1. Changed the assets that can be managed by the file access framework. The assets managed by the media library cannot be accessed by using the file access framework APIs. Currently, the file access framework supports the following directories:
   - External storage directory
   - **Docs** directory
   - **Download** directory
   - **Desktop** directory
   - **Documents** directory
   - **Share** directory of the shared disk

   The **fileAccess** module does not support query of some attributes of thumbnails and media assets.

2. Changed the URI format, which eliminates the need for parsing the URI format.

**Change Impact**

For applications developed based on earlier versions, check whether the URI is obtained by using the media library API through **fileAccess**. If yes, the URI cannot be obtained.

**Key API/Component Changes**

The following API is deleted.

| Class          | API                                                |
| -------------- | ------------------------------------------------------------ |
| fileAccessHelper | getThumbnail(uri: string, size: image.Size, callback: AsyncCallback<image.PixelMap>): void;|

The following values are deleted from **FileKey**.

| Enum| Deleted Value|
| -------- | ---- |
| FileKey | DURATION = 'duration' |
| FileKey | WIDTH = 'width' |
| FileKey | HEIGHT = 'height' |

**Adaptation Guide**

The invocation of the **fileAccess** APIs remains unchanged, but the assets corresponding to the URI returned change.

To obtain attributes such as the file name and path, use [fileuri](../../../application-dev/reference/apis/js-apis-file-fileuri.md).

To obtain the URI via a file access framework interface, use [fs](../../../application-dev/reference/apis/js-apis-file-fs.md).


## cl.file.5 New PhotoAccessHelper Error Codes

Added error codes to @ohos.file.photoAccessHelper.d.ts. For details, see [File Management Error Codes](../../../application-dev/reference/errorcodes/errorcode-filemanagement.md).

**Change Impact**

New error codes are added to @ohos.file.photoAccessHelper.d.ts. The new error codes do not involve any change in code logic. Therefore, there is no impact on compatibility.

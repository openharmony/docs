# @ohos.multimedia.medialibrary (Media Library Management) (System API)

> **NOTE**
>
> - The APIs of this module are supported since API version 6. Updates will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module are deprecated since API version 9. For details about the substitute APIs, see the API description.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.multimedia.medialibrary (Media Library Management)](js-apis-medialibrary.md).

## Modules to Import

```ts
import mediaLibrary from '@ohos.multimedia.mediaLibrary';
```

## MediaLibrary

### deleteAsset<sup>8+</sup>

deleteAsset(uri: string): Promise\<void>

Deletes a file asset. This API uses a promise to return the result.

Before calling this API, call [FileAsset.trash](js-apis-medialibrary.md#trash8) to move the file to the trash. Otherwise, the file will fail to be deleted.

> **NOTE**
>
> This API is deprecated since API version 9. Use [deleteAssets](js-apis-photoAccessHelper-sys.md#deleteassetsdeprecated-3) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description             |
| -------- | ---------------------------- | ---- | --------------- |
| uri | string | Yes   | URI of the file asset to delete.|

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let fileType = mediaLibrary.MediaType.FILE;
  let option: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [fileType.toString()],
  };
  const fetchFileResult = await media.getFileAssets(option);
  let asset = await fetchFileResult.getFirstObject();
  if (asset == undefined) {
    console.error('asset not exist');
    return;
  }
  media.deleteAsset(asset.uri).then(() => {
    console.info('deleteAsset successfully');
  }).catch((error: BusinessError) => {
    console.error('deleteAsset failed with error: ' + error);
  });
  fetchFileResult.close();
}
```

### deleteAsset<sup>8+</sup>

deleteAsset(uri: string, callback: AsyncCallback\<void>): void

Deletes a file asset. This API uses an asynchronous callback to return the result.

Before calling this API, call [FileAsset.trash](js-apis-medialibrary.md#trash8) to move the file to the trash. Otherwise, the file will fail to be deleted.

> **NOTE**
>
> This API is deprecated since API version 9. Use [deleteAssets](js-apis-photoAccessHelper-sys.md#deleteassetsdeprecated-2) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description             |
| -------- | ---------------------------- | ---- | --------------- |
| uri | string | Yes   | URI of the file asset to delete.|
|callback |AsyncCallback\<void>| Yes |Callback that returns no value.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let fileType = mediaLibrary.MediaType.FILE;
  let option: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [fileType.toString()],
  };
  const fetchFileResult = await media.getFileAssets(option);
  let asset = await fetchFileResult.getFirstObject();
  if (asset == undefined) {
    console.error('asset not exist');
    return;
  }
  media.deleteAsset(asset.uri, (error) => {
    if (error != undefined) {
      console.error('deleteAsset failed with error: ' + error);
    } else {
      console.info('deleteAsset successfully');
    }
  });
  fetchFileResult.close();
}
```

### getActivePeers<sup>8+</sup>

getActivePeers(): Promise\<Array\<PeerInfo>>;

Obtains information about online peer devices. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
|  Promise\<Array\<[PeerInfo](#peerinfo8)>> | Promise used to return the online peer devices, in an array of **PeerInfo** objects.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  media.getActivePeers().then((devicesInfo) => {
    if (devicesInfo != undefined) {
      console.info('get distributed info ' + JSON.stringify(devicesInfo));
    } else {
      console.info('get distributed info is undefined!');
    }
  }).catch((error: BusinessError) => {
    console.error('get distributed info failed with error: ' + error);
  });
}
```

### getActivePeers<sup>8+</sup>

getActivePeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;

Obtains information about online peer devices. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
| callback: AsyncCallback\<Array\<[PeerInfo](#peerinfo8)>> | Callback invoked to return the online peer devices, in an array of **PeerInfo** objects.|

**Example**

```ts
async function example() {
  media.getActivePeers((error, devicesInfo) => {
    if (devicesInfo != undefined) {
      console.info('get distributed info ' + JSON.stringify(devicesInfo));
    } else {
      console.error('get distributed failed with error: ' + error);
    }
  });
}
```

### getAllPeers<sup>8+</sup>

getAllPeers(): Promise\<Array\<PeerInfo>>;

Obtains information about all peer devices. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
|  Promise\<Array\<[PeerInfo](#peerinfo8)>> | Promise used to return all peer devices, in an array of **PeerInfo** objects.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  media.getAllPeers().then((devicesInfo) => {
    if (devicesInfo != undefined) {
      console.info('get distributed info ' + JSON.stringify(devicesInfo));
    } else {
      console.info('get distributed info is undefined!');
    }
  }).catch((error: BusinessError) => {
    console.error('get distributed info failed with error: ' + error);
  });
}
```

### getAllPeers<sup>8+</sup>

getAllPeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;

Obtains information about all peer devices. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
| callback: AsyncCallback\<Array\<[PeerInfo](#peerinfo8)>> | Callback invoked to return all peer devices, in an array of **PeerInfo** objects.|

**Example**

```ts
async function example() {
  media.getAllPeers((error, devicesInfo) => {
    if (devicesInfo != undefined) {
      console.info('get distributed info ' + JSON.stringify(devicesInfo));
    } else {
      console.error('get distributed failed with error: ' + error);
    }
  });
}
```

## PeerInfo<sup>8+</sup>

Defines information about a registered device.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

| Name      | Type                      | Readable| Writable| Description            |
| ---------- | -------------------------- | ---- | ---- | ---------------- |
| deviceName | string                     | Yes  | No  | Name of the registered device.  |
| networkId  | string                     | Yes  | No  | Network ID of the registered device.|
| deviceType | [DeviceType](#devicetype8) | Yes  | No  | Type of the registered device.        |
| isOnline   | boolean                    | Yes  | No  | Whether the registered device is online.        |

## DeviceType<sup>8+</sup>

Enumerates the device types.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

| Name        |  Value| Description      |
| ------------ | --- | ---------- |
| TYPE_UNKNOWN |  0 | Unknown.|
| TYPE_LAPTOP  |  1 | Laptop.|
| TYPE_PHONE   |  2 | Phone.      |
| TYPE_TABLET  |  3 | Tablet.  |
| TYPE_WATCH   |  4 | Smart watch.  |
| TYPE_CAR     |  5 | Vehicle-mounted device.  |
| TYPE_TV      |  6 | TV.  |

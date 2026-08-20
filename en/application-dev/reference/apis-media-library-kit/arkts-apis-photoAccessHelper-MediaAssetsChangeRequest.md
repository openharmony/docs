# Class (MediaAssetsChangeRequest)

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=064bb08ccf99717a1b68e90ff57938ff22079494 translatedAt=2026-08-17T10:27:08.320Z pushedAt=2026-08-19T07:51:23.239Z -->

MediaAssetsChangeRequest implements [MediaChangeRequest](arkts-apis-photoAccessHelper-i.md#mediachangerequest11).

Represents a request for changing multiple assets.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this class are supported since API version 26.0.0.

## Modules to Import

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
```

## constructor

constructor(assets: Array&lt;PhotoAsset&gt;)

Defines a constructor, which is used to initialize a request for changing multiple assets.

**Since**: 26.0.0

**System capability:** SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name   | Type                      | Mandatory | Description       |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)&gt; | Yes   | Assets to change. |

**Error codes**

For details about the error codes thrown by the API, see [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID | Error Message |
| -------- | ---------------------------------------- |
| 14000011       | System inner fail.          |

**Example**

For details about how to create a **phAccessHelper** instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('MediaAssetsChangeRequest constructorDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAssetList: Array<photoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();
  let assetsChangeRequest: photoAccessHelper.MediaAssetsChangeRequest = new photoAccessHelper.MediaAssetsChangeRequest(photoAssetList);
}
```

## setFavorite

setFavorite(favoriteState: boolean): void

Favorites or unfavorites multiple file assets.

**Since**: 26.0.0

**System capability:** SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name        | Type      | Mandatory   | Description                                 |
| ---------- | ------- | ---- | ---------------------------------- |
| favoriteState | boolean | Yes    | Whether to favorite the file asset. **true** to favorite, and **false** otherwise. |

**Error codes**

For details about the error codes, see [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID | Error Message |
| -------- | ---------------------------------------- |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a **phAccessHelper** instance, see the example in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('setFavoriteDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAssetList: Array<photoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();
  let assetsChangeRequest: photoAccessHelper.MediaAssetsChangeRequest = new photoAccessHelper.MediaAssetsChangeRequest(photoAssetList);
  assetsChangeRequest.setFavorite(true);
  phAccessHelper.applyChanges(assetsChangeRequest).then(() => {
    console.info('apply setFavorite successfully');
  }).catch((err: BusinessError) => {
    console.error(`apply setFavorite failed with error: ${err.code}, ${err.message}`);
  });
}
```
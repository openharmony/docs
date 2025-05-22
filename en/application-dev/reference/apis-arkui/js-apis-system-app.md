# @system.app (Application Context)

> **NOTE**
>
> The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```ts
import app, { AppResponse } from '@system.app';
```

## App

### getInfo

static getInfo(): AppResponse

Obtains the declared information in the **config.json** file of an application. In the stage model, this API returns **null**.

This API is deprecated since API version 9. You are advised to use [bundleManager.getBundleInfoForSelf](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself) instead.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

**Return value**

| Type| Description|
| -------- | -------- |
| [AppResponse](#appresponse) | Application response information.|

**Example**

```ts
import app, { AppResponse } from '@system.app';
export default class Info {
  getInfo() {
    let info:AppResponse = app.getInfo();
    console.log(JSON.stringify(info));
  }
}
```

### terminate

static terminate(): void

Terminates the current ability. In the stage model, this API has no effect.

This API is deprecated since API version 7. You are advised to use [@ohos.ability.featureAbility](../apis-ability-kit/js-apis-ability-featureAbility.md) instead.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Lite

**Example**

```ts
import app, { AppResponse } from '@system.app';
export default class TerM {
  terminate() {
    app.terminate();
  }
}
```
### setImageCacheCount<sup>7+</sup>

static setImageCacheCount(value: number): void

Sets the maximum number of decoded images that can be cached in the memory to speed up the loading of images from the same sources. If the input parameter is not set, the default value **0** is used, indicating that images are not cached. The built-in Least Recently Used (LRU) policy is used for caching. If the maximum number is exceeded, the images that have not been updated for the longest time will be removed. You are advised to set the parameter based on the application memory requirements. If the number of images is too large, the memory usage may be too high.

**setImageCacheCount** takes effect only when used in [onPageShow](../apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#onpageshow) or [aboutToAppear](../apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttoappear) on the page decorated by @Entry.

The **setImageCacheCount**, **setImageRawDataCacheSize**, and **setImageFileCacheSize** APIs are not flexible and will not be further evolved in future developments. In light of this, consider using [ImageKnife](https://gitee.com/openharmony-tpc/ImageKnife) for more complex scenarios.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Number of decoded images that are cached in the memory.|

**Example**

```ts
// xxx.ets
import app, { AppResponse } from '@system.app';

@Entry
@Component
struct Index {
  onPageShow() {
    // Set the maximum number of decoded images that can be cached in the memory to 100.
    app.setImageCacheCount(100);
    console.info('Application onPageShow');
  }
  onDestroy() {
    console.info('Application onDestroy');
  }

  build() {
    Row(){
      // xxxxxxxxxxxxx indicates the image address.
      Image('xxxxxxxxxxxxx')
        .width(200)
        .height(50)
    }.width('100%')
  }
}
```

### setImageRawDataCacheSize<sup>7+</sup>

static setImageRawDataCacheSize(value: number): void

Sets the maximum size (in bytes) of the image data cached in the memory before decoding to speed up the loading of images from the same sources. If the input parameter is not set, the default value **0** is used, indicating that images are not cached. The LRU policy is used for caching. If the maximum size is exceeded, the images that have not been updated for the longest time will be removed. You are advised to set the parameter based on the application memory requirements. If the image cache is too large, the memory usage may be too high.

**setImageRawDataCacheSize** takes effect only when used in [onPageShow](../apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#onpageshow) or [aboutToAppear](../apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttoappear) on the page decorated by @Entry.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Size of the image data cached before decoding, in bytes.|

**Example**

```ts
// xxx.ets
import app, { AppResponse } from '@system.app';

@Entry
@Component
struct Index {
  onPageShow() {
    // Set the upper limit of the memory for caching image data before decoding to 100 MB. (100 x 1024 x 1024 B =104857600 B = 100 MB).
    app.setImageRawDataCacheSize(104857600); 
    console.info('Application onPageShow');
  }
  onDestroy() {
    console.info('Application onDestroy');
  }

  build() {
    Row(){
      // xxxxxxxxxxxxx indicates the image address.
      Image('xxxxxxxxxxxxx')
        .width(200)
        .height(50)
    }.width('100%')
  }
}
```

### setImageFileCacheSize<sup>7+</sup>

static setImageFileCacheSize(value: number): void

Sets the maximum size of the image file cache (in bytes) to speed up the loading of images from the same sources, especially online image sources. If the input parameter is not set, the default value 100 MB is used. The LRU policy is used for caching. If the maximum size is exceeded, the images that have not been updated for the longest time will be removed. You are advised to set the parameter based on the application memory requirements. If the image cache is too large, the disk usage may be too high.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Size of the image file cache, in bytes.|

**Example**

```ts
// app.ets
import app, { AppResponse } from '@system.app';

export default class OnC {
  onCreate() {
    app.setImageFileCacheSize(209715200);
    // Set the upper limit of the image file cache to 200 MB. (200 x 1024 x 1024 B= 209715200 B = 200 MB).
    console.info('Application onCreate');
  }
  onDestroy() {
    console.info('Application onDestroy');
  }
}
```

### ScreenOnVisible<sup>(deprecated)</sup>

static screenOnVisible(options?: ScreenOnVisibleOptions): void

Defines whether to keep the application visible when the screen is woken up.

This API is deprecated since API version 8.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                             | Mandatory| Description                                                        |
| ------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [ScreenOnVisibleOptions](#screenonvisibleoptions) | No  | With keep-alive, the system is prevented from returning to the home screen when the screen is locked, so that the application is visible when the screen is woken up.|

### requestFullWindow<sup>(deprecated)</sup>

static requestFullWindow(options?: RequestFullWindowOptions): void

Requests the application to run in full window. You can call this API when the FA runs in a non-full window, for example, semi-modal FA. This API is invalid for an application already in full-window mode.

You are advised to use [@ohos.window](js-apis-window.md) since API version 7.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                 | Mandatory| Description                                                        |
| ------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [RequestFullWindowOptions](#requestfullwindowoptions) | No  | Duration for transition from the non-full window to the full window, in milliseconds. By default, the value is in direct proportion to the distance between the non-full window and the full window.|

**Example**

```ts
import app, { AppResponse } from '@system.app';
export default class Req {
  requestFullWindow() {
    app.requestFullWindow({
      duration: 200
    });
  }
} 
```

## AppResponse

Defines the application response information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: The items in the table below require different system capabilities. For details, see the table.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- |-------- |
| appID<sup>6+</sup> | string | Yes| Bundle name of an application. It uniquely identifies the application.<br> **System capability**: SystemCapability.ArkUI.ArkUI.Full|
| appName | string | Yes| Application name.<br> **System capability**: SystemCapability.ArkUI.ArkUI.Lite|
| versionName | string | Yes| Application version name.<br> **System capability**: SystemCapability.ArkUI.ArkUI.Lite|
| versionCode | number | Yes| Application version number.<br> **System capability**: SystemCapability.ArkUI.ArkUI.Lite|

## ScreenOnVisibleOptions

Defines the options of the visible interface on the screen.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| visible | boolean | No| Whether to keep the application visible. The default value is **false**.|
| success | () => void | No| Callback upon success.|
| fail | (data: string, code: number) => void | No| Callback upon failure.|
| complete | () => void | No| Called when the API call is complete.|

## RequestFullWindowOptions

Defines the options of the **RequestFullWindow** API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| duration | number | Yes| Duration of an animation, in milliseconds.|

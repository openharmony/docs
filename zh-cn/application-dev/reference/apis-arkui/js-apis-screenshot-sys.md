# @ohos.screenshot (屏幕截图)(系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @oh_wangxk-->
<!--Designer: @logn; @wulong158-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

本模块提供屏幕截图的能力，截取屏幕时支持设置截取的区域、大小等图像信息。可应用于屏幕内容分享、问题反馈或测试验证等场景，支持普通截图和HDR截图两种模式，具备区域选择、旋转处理、多屏支持和截屏通知等特性，帮助开发者灵活获取屏幕内容。

>  **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.screenshot](./js-apis-screenshot.md)。

## 导入模块

```ts
import { screenshot } from '@kit.ArkUI';
```

## ScreenshotOptions

设置截取图像的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                 | 类型          |  只读 |  可选 | 说明                                                         |
| ---------------------- | ------------- | ---- | ---- | ------------------------------------------------------------ |
| screenRect             | [Rect](js-apis-screenshot.md#rect) | 否  | 是 | 表示截取图像的区域，不传值默认返回displayId所在逻辑屏的区域。                       |
| imageSize              | [Size](#size) | 否 | 是  | 表示截取图像的大小，不传值默认为displayId所在逻辑屏的大小。若screenRect小于imageSize，图像会拉伸至imageSize，反之则压缩至imageSize的大小。                       |
| rotation               | number        | 否  | 是 | 表示截取图像后要旋转的角度，单位为度，当前仅支持0，默认值为0。传入其他值时将使用默认值。     |
| displayId<sup>8+</sup> | number        | 否 | 是  | 表示截取图像的显示设备[Display](js-apis-display.md#display)的ID号，该参数应为整数。默认为0。 |
| isNotificationNeeded<sup>14+</sup>| boolean        | 否  | 是 | 表示截取图像之后是否发送截屏通知，true表示发送截屏通知，false表示不发送截屏通知，默认值为true。截屏通知可以通过[captureStatusChange](js-apis-display.md#displayoncapturestatuschange12)接口监听。   |
| isCaptureFullOfScreen<sup>20+</sup> | boolean        | 否  | 是 | 表示是否截取当前Screen上的所有display。对于一个Screen上有多个display的场景，为true表示截取整个Screen，false则只截取displayId所在逻辑屏的区域，默认值为false。 |

## HdrScreenshotOptions<sup>20+</sup>

设置截取HDR图像的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                 | 类型          |  只读 |  可选 | 说明                                                         |
| ---------------------- | ------------- | --- | ---- | ------------------------------------------------------------ |
| displayId | number        | 否 | 是   | 表示截取图像的显示设备[Display](js-apis-display.md#display)的ID号，该参数应为整数。默认为0。 |
| isNotificationNeeded| boolean        | 否 | 是   | 表示截取图像之后是否发送截屏通知，true表示发送截屏通知，false表示不发送截屏通知，默认值为true。截屏通知可以通过[captureStatusChange](js-apis-display.md#displayoncapturestatuschange12)接口监听。   |
| isCaptureFullOfScreen | boolean        | 否 | 是   | 表示是否截取当前物理屏上所有displayId对应的逻辑屏。对于一个物理屏上有多个displayId的场景，true表示截取整个物理屏，false表示只截取displayId所在区域的逻辑屏。默认值为false。 |
| displayIntent | [DisplayIntentType](#displayintenttype)        | 否 | 是   | 表示截取HDR图像的渲染方式，不影响SDR图像效果。默认值为screenshot.DisplayIntentType.CANONICAL。<br>**起始版本：** 26.0.0 <br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## DisplayIntentType 

截取HDR图像的渲染方式枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| CANONICAL | 0 | 表示指定截图以标准HDR显示属性进行渲染，以优化截图在不同HDR显示器上的显示效果。|
| LOCAL | 1 | 表示指定截图以当前HDR显示属性进行渲染，以保证截图与当前被截图的显示器显示效果一致。|

## Size

表示截取图像的大小。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                 | 类型          |  只读 |  可选 | 说明                                                         |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| width  | number | 否   | 否   | 表示截取图像的宽度，单位为px，该参数应为整数。 |
| height | number | 否   | 否   | 表示截取图像的高度，单位为px，该参数应为整数。 |

## screenshot.save

save(options: ScreenshotOptions, callback: AsyncCallback&lt;image.PixelMap&gt;): void

获取屏幕截图，使用callback异步回调。

返回的PixelMap对象需要手动释放，使用完毕后必须调用[release()](../apis-image-kit/arkts-apis-image-PixelMap.md#release7)方法释放内存，否则可能导致内存泄漏。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**需要权限：**
- API版本26.0.0+：ohos.permission.CUSTOM_SCREEN_CAPTURE 或 ohos.permission.CAPTURE_SCREEN 或 ohos.permission.CUSTOM_SCREEN_RECORDING。
- API版本22-24：ohos.permission.CAPTURE_SCREEN 或 ohos.permission.CUSTOM_SCREEN_RECORDING。
- API版本7-21：ohos.permission.CAPTURE_SCREEN。

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [ScreenshotOptions](#screenshotoptions) | 是   | 要截取的图像信息。当指定截取屏幕为虚拟屏时，截取图像为白屏。 |
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt;     | 是   | 回调函数。返回一个PixelMap对象，其大小为指定的imageSize大小，若未指定默认为displayId所在逻辑屏的大小。                                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let screenshotOptions: screenshot.ScreenshotOptions = {
  screenRect: {
    left: 200,
    top: 100,
    width: 200,
    height: 200 },
  imageSize: {
    width: 300,
    height: 300 },
  rotation: 0,
  displayId: 0,
  isNotificationNeeded: true,
  isCaptureFullOfScreen: true
};
// 调用save方法获取屏幕截图
screenshot.save(screenshotOptions, (err: BusinessError, pixelMap: image.PixelMap) => {
  if (err) {
    console.error(`Failed to save screenshot. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in saving screenshot. Pixel bytes number: ${pixelMap.getPixelBytesNumber()}`);
  pixelMap.release(); // PixelMap使用完后及时释放内存
});
```

## screenshot.save

save(callback: AsyncCallback&lt;image.PixelMap&gt;): void

获取屏幕截图，使用callback异步回调。

返回的PixelMap对象需要手动释放，使用完毕后必须调用[release()](../apis-image-kit/arkts-apis-image-PixelMap.md#release7)方法释放内存，否则可能导致内存泄漏。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**需要权限：**
- API版本26.0.0+：ohos.permission.CUSTOM_SCREEN_CAPTURE 或 ohos.permission.CAPTURE_SCREEN 或 ohos.permission.CUSTOM_SCREEN_RECORDING。
- API版本22-24：ohos.permission.CAPTURE_SCREEN 或 ohos.permission.CUSTOM_SCREEN_RECORDING。
- API版本7-21：ohos.permission.CAPTURE_SCREEN。

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt;     | 是   | 回调函数。返回一个PixelMap对象。                                   |


**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

// 调用save方法获取屏幕截图
screenshot.save((err: BusinessError, pixelMap: image.PixelMap) => {
  if (err) {
    console.error(`Failed to save screenshot. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in saving screenshot. Pixel bytes number: ${pixelMap.getPixelBytesNumber()}`);
  pixelMap.release(); // PixelMap使用完后及时释放内存
});
```

## screenshot.save

save(options?: ScreenshotOptions): Promise&lt;image.PixelMap&gt;

获取屏幕截图，使用Promise异步回调。

返回的PixelMap对象需要手动释放，使用完毕后必须调用[release()](../apis-image-kit/arkts-apis-image-PixelMap.md#release7)方法释放内存，否则可能导致内存泄漏。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**需要权限：**
- API版本26.0.0+：ohos.permission.CUSTOM_SCREEN_CAPTURE 或 ohos.permission.CAPTURE_SCREEN 或 ohos.permission.CUSTOM_SCREEN_RECORDING。
- API版本22-24：ohos.permission.CAPTURE_SCREEN 或 ohos.permission.CUSTOM_SCREEN_RECORDING。
- API版本7-21：ohos.permission.CAPTURE_SCREEN。

**参数：**

| 参数名  | 类型                                    | 必填 | 说明                                                         |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [ScreenshotOptions](#screenshotoptions) | 否   | 要截取的图像信息。当指定截取屏幕为虚拟屏时，截取图像为白屏。 |

**返回值：**

| 类型                          | 说明                                            |
| ----------------------------- | ----------------------------------------------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Promise对象。返回一个PixelMap对象。其大小为指定的imageSize大小，若未指定默认为displayId所在逻辑屏的大小。 |


**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let screenshotOptions: screenshot.ScreenshotOptions = {
  screenRect: {
    left: 200,
    top: 100,
    width: 200,
    height: 200 },
  imageSize: {
    width: 300,
    height: 300 },
  rotation: 0,
  displayId: 0,
  isNotificationNeeded: true,
  isCaptureFullOfScreen: true
};
try {
  let promise = screenshot.save(screenshotOptions);
  promise.then((pixelMap: image.PixelMap) => {
    let pixelBytesNumber = pixelMap.getPixelBytesNumber();
    console.info(`Succeeded in saving screenshot. Pixel bytes number: ${pixelBytesNumber}`);
    pixelMap.release(); // PixelMap使用完后及时释放内存
  }).catch((err: BusinessError) => {
    console.error(`Failed to save screenshot. Code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to save screenshot. Code: ${exception.code}, message: ${exception.message}`);
}
```

## screenshot.saveHdrPicture<sup>20+</sup>

saveHdrPicture(options?: HdrScreenshotOptions): Promise&lt;Array&lt;image.PixelMap&gt;&gt;

获取屏幕截图，使用Promise异步回调。SDR为标准动态范围图，HDR为高动态范围图。
- 当物理屏存在HDR资源（包括HDR资源被遮挡）时，无论HDR是否开启，该接口返回一个包含SDR和HDR的PixelMap数组。
- 当物理屏不存在HDR资源时，与[save](#screenshotsave)接口返回一个SDR的PixelMap不同，该接口返回包含一个SDR的PixelMap数组。同时该接口不具备[save](#screenshotsave)接口的裁剪、拉伸、旋转功能。

返回的PixelMap对象数组中的每个PixelMap对象都需要手动释放，使用完毕后必须调用[release()](../apis-image-kit/arkts-apis-image-PixelMap.md#release7)方法释放内存，否则可能导致内存泄漏。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**需要权限：**
- API版本22+：ohos.permission.CAPTURE_SCREEN 或 ohos.permission.CUSTOM_SCREEN_RECORDING。
- API版本20-21：ohos.permission.CAPTURE_SCREEN。

**参数：**

| 参数名  | 类型                                    | 必填 | 说明                                                         |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [HdrScreenshotOptions](#hdrscreenshotoptions20) | 否   | 要截取的HDR图像信息。未传入该参数时各字段取默认值。 |

**返回值：**

| 类型                          | 说明                                            |
| ----------------------------- | ----------------------------------------------- |
| Promise&lt;Array&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt;&gt; | Promise对象。返回一个PixelMap对象数组。对于截取的区域存在HDR（包括HDR被遮挡）时，数组返回两个PixelMap，第一个为SDR的PixelMap，第二个为HDR的PixelMap。对于截取的区域不存在HDR时，数组返回一个SDR的PixelMap。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1400001  | Invalid display or screen. |
| 1400003  | This display manager service works abnormally. |
| 1400004  | Parameter error. Possible cause: 1. Invalid parameter range. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let hdrScreenshotOptions: screenshot.HdrScreenshotOptions = {
  displayId: 0,
  isNotificationNeeded: true,
  isCaptureFullOfScreen: true,
  displayIntent: screenshot.DisplayIntentType.CANONICAL
};
try {
  let promise = screenshot.saveHdrPicture(hdrScreenshotOptions);
  promise.then((pixelMapArray: Array<image.PixelMap>) => {
    for (let i = 0; i < pixelMapArray.length; i++) {
      const pixelMap = pixelMapArray[i];
      console.info(`succeeded in saving screenshot ${i}. Pixel bytes number: ${pixelMap.getPixelBytesNumber()}`);
      pixelMap.release();
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to save SDR and HDR screenshot. Code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to save SDR and HDR screenshot. Code: ${exception.code}, message: ${exception.message}`);
}
```

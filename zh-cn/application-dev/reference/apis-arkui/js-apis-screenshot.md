# @ohos.screenshot (屏幕截图)

本模块提供屏幕截图的能力。

>  **说明：**
>
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { screenshot } from '@kit.ArkUI';
```

## Rect

表示截取图像的区域。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| left   | number | 是   | 表示截取图像区域的左边界，单位为px，该参数应为整数。 |
| top    | number | 是   | 表示截取图像区域的上边界，单位为px，该参数应为整数。 |
| width  | number | 是   | 表示截取图像区域的宽度，单位为px，该参数应为整数。 |
| height | number | 是   | 表示截取图像区域的高度，单位为px，该参数应为整数。 |

## CaptureOption<sup>14+</sup>

设置截取图像的信息。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| displayId | number | 否 | 表示截取图像的显示设备[Display](js-apis-display.md#display)的ID号，默认为0，该参数应为大于或等于0的整数，非整数会报参数错误。 |

## PickInfo

截取图像的信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                 | 类型          | 必填 | 说明                                                         |
| -------------------- | ------------- | ---- | ------------------------------------------------------------ |
| pickRect             | [Rect](#rect) | 是   | 表示截取图像的区域。                       |
| pixelMap             | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)  | 是   | 表示截取的图像PixelMap对象。 |

## screenshot.pick

pick(): Promise&lt;PickInfo&gt;

获取屏幕截图。此接口仅可在2in1设备上使用。当前仅支持获取displayId为0的屏幕截图。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                          | 说明                                            |
| ----------------------------- | ----------------------------------------------- |
| Promise&lt;[PickInfo](#pickinfo)&gt; | Promise对象。返回一个PickInfo对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 801 | Capability not supported on this device. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = screenshot.pick();
  promise.then((pickInfo: screenshot.PickInfo) => {
    console.log('pick Pixel bytes number: ' + pickInfo.pixelMap.getPixelBytesNumber());
    console.log('pick Rect: ' + pickInfo.pickRect);
    pickInfo.pixelMap.release(); // PixelMap使用完后及时释放内存
  }).catch((err: BusinessError) => {
    console.log('Failed to pick. Code: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to pick Code: ' + JSON.stringify(exception));
};
```

## screenshot.capture<sup>14+</sup>

capture(options?: CaptureOption): Promise&lt;image.PixelMap&gt;

获取屏幕全屏截图，此接口仅支持在平板和2in1设备上使用。
此接口可以通过设置不同的displayId截取不同屏幕的截图，且只能截取全屏；[pick](#screenshotpick)接口可实现区域截屏。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**需要权限**：ohos.permission.CUSTOM_SCREEN_CAPTURE

**参数：**

| 参数名  | 类型                                    | 必填 | 说明                                                         |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [CaptureOption](#captureoption14) | 否 |  截取图像的相关信息。可包含设备ID，即displayId。 此参数不填时，默认截取displayId为0的屏幕截图。|

**返回值：**

| 类型                          | 说明                                            |
| ----------------------------- | ----------------------------------------------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Promise对象。返回一个PixelMap对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 801 | Capability not supported on this device.|
| 1400003 | This display manager service works abnormally.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let captureOption: screenshot.CaptureOption = {
  "displayId": 0
};
try {
  let promise = screenshot.capture(captureOption);
  promise.then((pixelMap: image.PixelMap) => {
    console.log('Succeeded in saving screenshot. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
    pixelMap.release(); // PixelMap使用完后及时释放内存
  }).catch((err: BusinessError) => {
    console.log('Failed to save screenshot. Code: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to save screenshot. Code: ' + JSON.stringify(exception));
};
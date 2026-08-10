# Functions
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

本模块提供图像处理相关功能，包括创建PixelMap、Picture、ImageSource、ImagePacker、ImageReceiver等图像对象，支持图像解码、编码、像素数据操作、图像变换等能力，适用于图像编辑、图像处理、相机预览截帧等场景。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { image } from '@kit.ImageKit';
```

## image.createPicture<sup>13+</sup>

createPicture(mainPixelmap : PixelMap): Picture

通过主图的PixelMap创建一个Picture对象。

由于图片占用内存较大，所以当Picture对象使用完成后，应主动调用[release](./arkts-apis-image-Picture.md#release13)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名       | 类型                | 必填 | 说明             |
| ------------ | ------------------- | ---- | ---------------- |
| mainPixelmap | [PixelMap](arkts-apis-image-PixelMap.md) | 是   | 主图的PixelMap。 |

**返回值：**

| 类型               | 说明              |
| ------------------ | ----------------- |
| [Picture](arkts-apis-image-Picture.md) | 返回Picture对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**示例：**

```ts
async function CreatePicture(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("test.jpg");
  let opts: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, opts);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  if (pictureObj != null) {
    console.info('Succeeded in creating picture');
  } else {
    console.error('Failed to create picture');
  }
}
```

## image.createPictureFromParcel<sup>13+</sup>

createPictureFromParcel(sequence: rpc.MessageSequence): Picture

从MessageSequence中获取Picture。

由于图片占用内存较大，所以当Picture对象使用完成后，应主动调用[release](./arkts-apis-image-Picture.md#release13)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                                                                | 必填 | 说明                                 |
| -------- | ------------------------------------------------------------------- | ---- | ------------------------------------ |
| sequence | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | 是   | 保存有Picture信息的MessageSequence。 |

**返回值：**

| 类型               | 说明              |
| ------------------ | ----------------- |
| [Picture](arkts-apis-image-Picture.md) | 返回Picture对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |
| 62980097 |  IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.                                        |

**示例：**

```ts
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MySequence implements rpc.Parcelable {
  picture: image.Picture | null = null;
  constructor(conPicture: image.Picture) {
    this.picture = conPicture;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    if(this.picture != null) {
      this.picture.marshalling(messageSequence);
      console.info('Succeeded in marshalling.');
      return true;
    } else {
      console.error('Failed to marshal.');
      return false;
    }
  }
  unmarshalling(messageSequence : rpc.MessageSequence) {
    this.picture = image.createPictureFromParcel(messageSequence);
    this.picture.getMainPixelmap().getImageInfo().then((imageInfo : image.ImageInfo) => {
      console.info(`Unmarshalling to get mainPixelmap information height:${imageInfo.size.height} width:${imageInfo.size.width}`);
    }).catch((error: BusinessError) => {
      console.error(`Unmarshalling failed error.code: ${error.code} ,error.message: ${error.message}`);
    });
    return true;
  }
}

async function marshallingUnmarshalling(context: Context) {
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("test.jpg");
  let opts: image.SourceOptions = {
    sourceDensity: 98,
  }
  let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer, opts);
  let commodityPixelMap: image.PixelMap = await imageSource.createPixelMap();
  let pictureObj: image.Picture = image.createPicture(commodityPixelMap);
  if (pictureObj != null) {
    let parcelable: MySequence = new MySequence(pictureObj);
    let data: rpc.MessageSequence = rpc.MessageSequence.create();
    // 序列化。
    data.writeParcelable(parcelable);
    let ret: MySequence = new MySequence(pictureObj);
    // 反序列化。
    data.readParcelable(ret);
  } else {
    console.error('PictureObj is null');
  }
}
```

## image.createPixelMapFromPixels

createPixelMapFromPixels(pixels: ArrayBuffer, param: InitializationOptions): Promise\<PixelMap\>

通过像素数据和图像属性创建PixelMap。传入的像素数据会进行拷贝并转换为[InitializationOptions](arkts-apis-image-i.md#initializationoptions8).pixelFormat指定的像素格式，用于初始化PixelMap的像素。使用Promise异步回调。

> **说明：**
>
> - 此接口不支持创建以下像素格式的PixelMap：RGBA_1010102、YCBCR_P010、YCRCB_P010和ASTC_4x4。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                                                             |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| pixels  | ArrayBuffer                                      | 是   | 图像像素数据的缓冲区，用于初始化PixelMap的像素。缓冲区内的像素数据必须紧密排列，不可以包含内存对齐填充字节。<br>缓冲区的像素格式需要由[InitializationOptions](arkts-apis-image-i.md#initializationoptions8).srcPixelFormat指定，否则默认缓冲区的像素格式为BGRA_8888。<br>**说明：** 缓冲区长度为：图像宽度 * 图像高度 * 每像素字节数。 |
| param | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | 是   | 创建图像的初始化属性，包括尺寸、像素格式、透明度类型、缩放模式和是否可编辑。<br>**说明：** 如果像素格式被指定为ASTC_4x4，则会使用默认的RGBA_8888格式。 |

**返回值：**

| 类型                             | 说明                                                                    |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)\> | Promise对象，返回创建的PixelMap对象，接口调用失败时会抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600206 | Invalid parameter. Possible cause: Size of the pixel data buffer does not match InitializationOptions.size. |
| 7600207 | Unsupported pixel format. |
| 7600301 | Failed to allocate memory. Possible causes: 1. The resulting PixelMap size is too large. 2. The system is out of memory. |
| 7600305 | Failed to create the PixelMap. Possible causes: 1. Failed to perform pixel format conversion. 2. Internal data is corrupted. Please check the logs for detailed information. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPixelMapFromPixels() {
  const size: image.Size = {
    width: 6,
    height: 4
  };
  const pixels = new ArrayBuffer(size.width * size.height * 4); // 4为RGBA类型像素格式的每像素字节数。
  const pixelsArr = new Uint8Array(pixels);
  for (let i = 0; i < pixelsArr.length; i += 4) {
    // RGBA_8888格式下，下列数组索引依次为：R通道、G通道、B通道、A通道。
    pixelsArr[i] = 0xFF;
    pixelsArr[i + 1] = 0x00;
    pixelsArr[i + 2] = 0x00;
    pixelsArr[i + 3] = 0xFF;
  }
  const config: image.InitializationOptions = {
    size,
    srcPixelFormat: image.PixelMapFormat.RGBA_8888, // 缓冲区内的源像素数据的像素格式。
    pixelFormat: image.PixelMapFormat.BGRA_8888, // 新创建的PixelMap的像素格式。
    editable: true
  };

  image.createPixelMapFromPixels(pixels, config)
    .then((pixelMap: image.PixelMap) => {
      console.info('Succeeded in creating the PixelMap.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to create the PixelMap. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## image.createPixelMapFromPixelsSync

createPixelMapFromPixelsSync(pixels: ArrayBuffer, param: InitializationOptions): PixelMap

通过像素数据和图像属性创建PixelMap。传入的像素数据会进行拷贝并转换为[InitializationOptions](arkts-apis-image-i.md#initializationoptions8).pixelFormat指定的像素格式，用于初始化PixelMap的像素。同步返回结果。

> **说明：**
>
> - 此接口不支持创建以下像素格式的PixelMap：RGBA_1010102、YCBCR_P010、YCRCB_P010和ASTC_4x4。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                                                             |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| pixels  | ArrayBuffer                                      | 是   | 图像像素数据的缓冲区，用于初始化PixelMap的像素。缓冲区内的像素数据必须紧密排列，不可以包含内存对齐填充字节。<br>缓冲区的像素格式需要由[InitializationOptions](arkts-apis-image-i.md#initializationoptions8).srcPixelFormat指定，否则默认缓冲区的像素格式为BGRA_8888。<br>**说明：** 缓冲区长度为：图像宽度 * 图像高度 * 每像素字节数。 |
| param | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | 是   | 创建图像的初始化属性，包括尺寸、像素格式、透明度类型、缩放模式和是否可编辑。<br>**说明：** 如果像素格式被指定为ASTC_4x4，则会使用默认的RGBA_8888格式。 |

**返回值：**

| 类型                             | 说明                                                                    |
| -------------------------------- | ----------------------------------------------------------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 返回创建的PixelMap对象，接口调用失败时会抛出异常。                    |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600206 | Invalid parameter. Possible cause: Size of the pixel data buffer does not match InitializationOptions.size. |
| 7600207 | Unsupported pixel format. |
| 7600301 | Failed to allocate memory. Possible causes: 1. The resulting PixelMap size is too large. 2. The system is out of memory. |
| 7600305 | Failed to create the PixelMap. Possible causes: 1. Failed to perform pixel format conversion. 2. Internal data is corrupted. Please check the logs for detailed information. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPixelMapFromPixelsSync() {
  const size: image.Size = {
    width: 6,
    height: 4
  };
  const pixels = new ArrayBuffer(size.width * size.height * 4); // 4为RGBA类型像素格式的每像素字节数。
  const pixelsArr = new Uint8Array(pixels);
  for (let i = 0; i < pixelsArr.length; i += 4) {
    // RGBA_8888格式下，下列数组索引依次为：R通道、G通道、B通道、A通道。
    pixelsArr[i] = 0xFF;
    pixelsArr[i + 1] = 0x00;
    pixelsArr[i + 2] = 0x00;
    pixelsArr[i + 3] = 0xFF;
  }
  const config: image.InitializationOptions = {
    size,
    srcPixelFormat: image.PixelMapFormat.RGBA_8888, // 缓冲区内的源像素数据的像素格式。
    pixelFormat: image.PixelMapFormat.BGRA_8888, // 新创建的PixelMap的像素格式。
    editable: true
  };

  try {
    const pixelMap = image.createPixelMapFromPixelsSync(pixels, config);
    console.info('Succeeded in creating the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## image.createEmptyPixelMap

createEmptyPixelMap(param: InitializationOptions): PixelMap

通过图像属性创建空白PixelMap。

> **说明：**
>
> - 此接口不支持创建以下像素格式的PixelMap：ASTC_4x4。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                                                             |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| param | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | 是   | 创建图像的属性，包括尺寸、像素格式、透明度类型、缩放模式和是否可编辑。<br>**说明：** 如果像素格式被指定为ASTC_4x4，则会使用默认的RGBA_8888格式。 |

**返回值：**

| 类型                             | 说明                                                                    |
| -------------------------------- | ----------------------------------------------------------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 返回创建的空白PixelMap对象，接口调用失败时会抛出异常。              |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------ | --------------------------------------------|
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible causes: 1. The resulting PixelMap size is too large. 2. The system is out of memory. |
| 7600305 | Failed to create the PixelMap. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createEmptyPixelMap() {
  const config: image.InitializationOptions = {
    size: { width: 6, height: 4 },
    pixelFormat: image.PixelMapFormat.RGBA_1010102, // 新创建的PixelMap的像素格式。
    editable: true
  };

  try {
    const pixelMap = image.createEmptyPixelMap(config);
    console.info('Succeeded in creating the empty PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create the empty PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## image.createPixelMap<sup>8+</sup>

createPixelMap(colors: ArrayBuffer, options: InitializationOptions): Promise\<PixelMap>

通过像素数据和图像属性创建PixelMap。传入的像素数据会进行拷贝并转换为[InitializationOptions](arkts-apis-image-i.md#initializationoptions8).pixelFormat指定的像素格式，用于初始化PixelMap的像素。使用Promise异步回调。

> **说明：**
>
> - 此接口不支持创建以下像素格式的PixelMap：RGBA_1010102、YCBCR_P010、YCRCB_P010和ASTC_4x4。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。
> - 从API版本26.0.0开始，建议使用[createPixelMapFromPixels](#imagecreatepixelmapfrompixels)代替，以获得更完善的异常处理能力。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                                                             |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | 是   | 图像像素数据的缓冲区，用于初始化PixelMap的像素。缓冲区内的像素数据必须紧密排列，不可以包含内存对齐填充字节。<br>缓冲区的像素格式需要由[InitializationOptions](arkts-apis-image-i.md#initializationoptions8).srcPixelFormat指定，否则默认缓冲区的像素格式为BGRA_8888。<br>**说明：** 缓冲区长度为：图像宽度 * 图像高度 * 每像素字节数。 |
| options | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | 是   | 创建图像的初始化属性，包括尺寸、像素格式、透明度类型、缩放模式和是否可编辑。<br>**说明：** 如果像素格式被指定为ASTC_4x4，则会使用默认的RGBA_8888格式。 |

**返回值：**

| 类型                             | 说明                                                                    |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise对象，返回创建的PixelMap。<br>当创建的PixelMap大小超过源像素数据所能表示的图像大小时，返回按源像素数据所能表示的图像大小创建的PixelMap。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPixelMap() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素缓冲区大小，取值为：width * height * 4。
  let opts: image.InitializationOptions = {
    size: { height: 4, width: 6 },
    srcPixelFormat: image.PixelMapFormat.RGBA_8888, // 缓冲区中的源像素数据的像素格式。
    pixelFormat: image.PixelMapFormat.BGRA_8888, // 新创建的PixelMap的像素格式。
    editable: true
  };
  image.createPixelMap(color, opts).then((pixelMap: image.PixelMap) => {
    console.info('Succeeded in creating the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to create the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## image.createPixelMap<sup>8+</sup>

createPixelMap(colors: ArrayBuffer, options: InitializationOptions, callback: AsyncCallback\<PixelMap>): void

通过像素数据和图像属性创建PixelMap。传入的像素数据会进行拷贝并转换为[InitializationOptions](arkts-apis-image-i.md#initializationoptions8).pixelFormat指定的像素格式，用于初始化PixelMap的像素。使用callback异步回调。

> **说明：**
>
> - 此接口不支持创建以下像素格式的PixelMap：RGBA_1010102、YCBCR_P010、YCRCB_P010和ASTC_4x4。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。
> - 从API版本26.0.0开始，建议使用[createPixelMapFromPixels](#imagecreatepixelmapfrompixels)代替，以获得更完善的异常处理能力。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                                             | 必填 | 说明                       |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| colors   | ArrayBuffer                                      | 是   | 图像像素数据的缓冲区，用于初始化PixelMap的像素。缓冲区内的像素数据必须紧密排列，不可以包含内存对齐填充字节。<br>缓冲区的像素格式需要由[InitializationOptions](arkts-apis-image-i.md#initializationoptions8).srcPixelFormat指定，否则默认缓冲区的像素格式为BGRA_8888。<br>**说明：** 缓冲区长度为：图像宽度 * 图像高度 * 每像素字节数。 |
| options  | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | 是   | 创建图像的初始化属性，包括尺寸、像素格式、透明度类型、缩放模式和是否可编辑。<br>**说明：** 如果像素格式被指定为ASTC_4x4，则会使用默认的RGBA_8888格式。 |
| callback | AsyncCallback\<[PixelMap](arkts-apis-image-PixelMap.md)>           | 是   | 回调函数，当创建PixelMap成功，err为undefined，data为获取到的PixelMap对象；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPixelMap() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素缓冲区大小，取值为：width * height * 4。
  let opts: image.InitializationOptions = {
    size: { height: 4, width: 6 },
    srcPixelFormat: image.PixelMapFormat.RGBA_8888, // 缓冲区中的源像素数据的像素格式。
    pixelFormat: image.PixelMapFormat.BGRA_8888, // 新创建的PixelMap的像素格式。
    editable: true
  };
  image.createPixelMap(color, opts, (err: BusinessError, pixelMap: image.PixelMap) => {
    if (err) {
      console.error(`Failed to create the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in creating the PixelMap.');
  });
}
```

## image.createPixelMapSync<sup>12+</sup>

createPixelMapSync(colors: ArrayBuffer, options: InitializationOptions): PixelMap

通过像素数据和图像属性创建PixelMap。传入的像素数据会进行拷贝并转换为[InitializationOptions](arkts-apis-image-i.md#initializationoptions8).pixelFormat指定的像素格式，用于初始化PixelMap的像素。同步返回结果。

> **说明：**
>
> - 此接口不支持创建以下像素格式的PixelMap：RGBA_1010102、YCBCR_P010、YCRCB_P010和ASTC_4x4。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。
> - 从API版本26.0.0开始，建议使用[createPixelMapFromPixelsSync](#imagecreatepixelmapfrompixelssync)代替，以获得更完善的异常处理能力。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                                                             |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | 是   | 图像像素数据的缓冲区，用于初始化PixelMap的像素。缓冲区内的像素数据必须紧密排列，不可以包含内存对齐填充字节。<br>缓冲区的像素格式需要由[InitializationOptions](arkts-apis-image-i.md#initializationoptions8).srcPixelFormat指定，否则默认缓冲区的像素格式为BGRA_8888。<br>**说明：** 缓冲区长度为：图像宽度 * 图像高度 * 每像素字节数。 |
| options | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | 是   | 创建图像的初始化属性，包括尺寸、像素格式、透明度类型、缩放模式和是否可编辑。<br>**说明：** 如果像素格式被指定为ASTC_4x4，则会使用默认的RGBA_8888格式。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 返回创建的PixelMap对象，接口调用失败时会抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPixelMapSync() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素缓冲区大小，取值为：width * height * 4。
  let opts: image.InitializationOptions = {
    size: { height: 4, width: 6 },
    srcPixelFormat: image.PixelMapFormat.RGBA_8888, // 缓冲区中的源像素数据的像素格式。
    pixelFormat: image.PixelMapFormat.BGRA_8888, // 新创建的PixelMap的像素格式。
    editable: true
  };
  try {
    let pixelMap: image.PixelMap = image.createPixelMapSync(color, opts);
    if (pixelMap == undefined) {
      console.error(`Failed to create the PixelMap.`);
      return;
    }
    console.info('Succeeded in creating the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## image.createPixelMapSync<sup>12+</sup>

createPixelMapSync(options: InitializationOptions): PixelMap

通过图像属性创建空白PixelMap。同步返回结果。

> **说明：**
>
> - 此接口不支持创建以下像素格式的PixelMap：ASTC_4x4。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。
> - 从API版本26.0.0开始，建议使用[createEmptyPixelMap](#imagecreateemptypixelmap)代替，以获得更完善的异常处理能力。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                                                             |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| options | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | 是   | 创建图像的属性，包括尺寸、像素格式、透明度类型、缩放模式和是否可编辑。<br>**说明：** 如果像素格式被指定为ASTC_4x4，则会使用默认的RGBA_8888格式。 |

**返回值：**
| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 返回创建的PixelMap对象，接口调用失败时会抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPixelMapSync() {
  let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_1010102, size: { height: 4, width: 6 } };
  try {
    let pixelMap: image.PixelMap = image.createPixelMapSync(opts);
    if (pixelMap == undefined) {
      console.error(`Failed to create the PixelMap.`);
      return;
    }
    console.info('Succeeded in creating the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## image.createPixelMapUsingAllocator<sup>20+</sup>

createPixelMapUsingAllocator(colors: ArrayBuffer, param: InitializationOptions, allocatorType?: AllocatorType): Promise\<PixelMap>

通过像素数据和图像属性创建PixelMap，可以指定内存类型。传入的像素数据会进行拷贝并转换为[InitializationOptions](arkts-apis-image-i.md#initializationoptions8).pixelFormat指定的像素格式，用于初始化PixelMap的像素。使用Promise异步回调。

> **说明：**
>
> - 此接口不支持创建以下像素格式的PixelMap：ASTC_4x4。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                                             | 必填 | 说明                       |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| colors   | ArrayBuffer                                      | 是   | 图像像素数据的缓冲区，用于初始化PixelMap的像素。缓冲区内的像素数据必须紧密排列，不可以包含内存对齐填充字节。<br>初始化前，必须通过[InitializationOptions](arkts-apis-image-i.md#initializationoptions8).srcPixelFormat指定缓冲区的像素格式，否则会创建失败。<br>**说明：** 缓冲区长度为：图像宽度 * 图像高度 * 每像素字节数。 |
| param  | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | 是   | 创建图像的初始化属性，包括尺寸、像素格式、透明度类型、缩放模式和是否可编辑。<br>**说明：** 如果像素格式被指定为ASTC_4x4，则会使用默认的RGBA_8888格式。 |
| allocatorType  | [AllocatorType](arkts-apis-image-e.md#allocatortype15)          | 否   | 指定创建PixelMap的内存类型，默认值为AllocatorType.AUTO。<br> 1. image.AllocatorType.AUTO：不支持该内存类型的格式有UNKNOWN、YCBCR_P010、YCRCB_P010和ASTC_4x4。RGBA_1010102默认申请DMA内存。其他格式（RGB_565、RGBA_8888、BGRA_8888和RGBA_F16）尺寸大于512*512像素默认申请DMA内存，否则申请共享内存。<br>2. image.AllocatorType.DMA：RGBA_1010102、RGB_565、RGBA_8888、BGRA_8888和RGBA_F16支持DMA内存类型，其余格式不支持。<br>3. image.AllocatorType.SHARE_MEMORY：UNKNOWN、RGBA_1010102、YCBCR_P010、YCRCB_P010和ASTC_4x4不支持共享内存，其余格式支持。 |

**返回值：**

| 类型                             | 说明                                                                    |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise对象，返回创建的PixelMap对象，接口调用失败时会抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  7600201    | Unsupported operation. |
|  7600301    | Memory alloc failed. |
|  7600302    | Memory copy failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPixelMapUsingAllocator() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素缓冲区大小，取值为：width * height * 4。
  let opts: image.InitializationOptions = {
    size: { height: 4, width: 6 },
    srcPixelFormat: image.PixelMapFormat.RGBA_8888, // 缓冲区中的源像素数据的像素格式。
    pixelFormat: image.PixelMapFormat.BGRA_8888, // 新创建的PixelMap的像素格式。
    editable: true
  };
  image.createPixelMapUsingAllocator(color, opts, image.AllocatorType.DMA).then((pixelMap: image.PixelMap) => {
    console.info('Succeeded in creating the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to create the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## image.createPixelMapUsingAllocatorSync<sup>20+</sup>

createPixelMapUsingAllocatorSync(colors: ArrayBuffer, param: InitializationOptions, allocatorType?: AllocatorType): PixelMap

通过像素数据和图像属性创建PixelMap，可以指定内存类型。传入的像素数据会进行拷贝并转换为[InitializationOptions](arkts-apis-image-i.md#initializationoptions8).pixelFormat指定的像素格式，用于初始化PixelMap的像素。同步返回结果。

> **说明：**
>
> - 此接口不支持创建以下像素格式的PixelMap：ASTC_4x4。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                                                             |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| colors  | ArrayBuffer                                      | 是   | 图像像素数据的缓冲区，用于初始化PixelMap的像素。缓冲区内的像素数据必须紧密排列，不可以包含内存对齐填充字节。<br>初始化前，必须通过[InitializationOptions](arkts-apis-image-i.md#initializationoptions8).srcPixelFormat指定缓冲区的像素格式，否则会创建失败。<br>**说明：** 缓冲区长度为：图像宽度 * 图像高度 * 每像素字节数。 |
| param | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | 是   | 创建图像的初始化属性，包括尺寸、像素格式、透明度类型、缩放模式和是否可编辑。<br>**说明：** 如果像素格式被指定为ASTC_4x4，则会使用默认的RGBA_8888格式。 |
| allocatorType  | [AllocatorType](arkts-apis-image-e.md#allocatortype15)          | 否   | 指定创建PixelMap的内存类型，默认值为AllocatorType.AUTO。<br> 1. image.AllocatorType.AUTO：不支持该内存类型的格式有UNKNOWN、YCBCR_P010、YCRCB_P010和ASTC_4x4。RGBA_1010102默认申请DMA内存。其他格式（RGB_565、RGBA_8888、BGRA_8888和RGBA_F16）尺寸大于512*512像素默认申请DMA内存，否则申请共享内存。<br>2. image.AllocatorType.DMA：RGBA_1010102、RGB_565、RGBA_8888、BGRA_8888和RGBA_F16支持DMA内存类型，其余格式不支持。<br>3. image.AllocatorType.SHARE_MEMORY：UNKNOWN、RGBA_1010102、YCBCR_P010、YCRCB_P010和ASTC_4x4不支持共享内存，其余格式支持。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 返回创建的PixelMap对象，接口调用失败时会抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  7600201    | Unsupported operation. |
|  7600301    | Memory alloc failed. |
|  7600302    | Memory copy failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPixelMapUsingAllocatorSync() {
  const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素缓冲区大小，取值为：width * height * 4。
  let opts: image.InitializationOptions = {
    size: { height: 4, width: 6 },
    srcPixelFormat: image.PixelMapFormat.RGBA_8888, // 缓冲区中的源像素数据的像素格式。
    pixelFormat: image.PixelMapFormat.BGRA_8888, // 新创建的PixelMap的像素格式。
    editable: true
  };
  try {
    let pixelMap: image.PixelMap = image.createPixelMapUsingAllocatorSync(color, opts, image.AllocatorType.DMA);
    if (pixelMap == undefined) {
      console.error(`Failed to create the PixelMap.`);
      return;
    }
    console.info('Succeeded in creating the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## image.createPixelMapUsingAllocatorSync<sup>20+</sup>

createPixelMapUsingAllocatorSync(param: InitializationOptions, allocatorType?: AllocatorType): PixelMap

通过图像属性创建空白PixelMap，可以指定内存类型。同步返回结果。

> **说明：**
>
> - 此接口不支持创建以下像素格式的PixelMap：ASTC_4x4。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                                                             |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| param | [InitializationOptions](arkts-apis-image-i.md#initializationoptions8) | 是   | 创建图像的初始化属性，包括尺寸、像素格式、透明度类型、缩放模式和是否可编辑。<br>**说明：** 如果像素格式被指定为ASTC_4x4，则会使用默认的RGBA_8888格式。 |
| allocatorType  | [AllocatorType](arkts-apis-image-e.md#allocatortype15)          | 否   | 指定创建PixelMap的内存类型，默认值为AllocatorType.AUTO。<br> 1. image.AllocatorType.AUTO：不支持该内存类型的格式有UNKNOWN、YCBCR_P010、YCRCB_P010和ASTC_4x4。RGBA_1010102默认申请DMA内存。其他格式（RGB_565、RGBA_8888、BGRA_8888和RGBA_F16）尺寸大于512*512像素默认申请DMA内存，否则申请共享内存。<br>2. image.AllocatorType.DMA：RGBA_1010102、RGB_565、RGBA_8888、BGRA_8888和RGBA_F16支持DMA内存类型，其余格式不支持。<br>3. image.AllocatorType.SHARE_MEMORY：UNKNOWN、RGBA_1010102、YCBCR_P010、YCRCB_P010和ASTC_4x4不支持共享内存，其余格式支持。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 返回创建的PixelMap对象，接口调用失败时会抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| -------- | --------------------------------------------|
| 7600201  | Unsupported operation. |
| 7600301  | Memory alloc failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPixelMapUsingAllocatorSync() {
  let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.BGRA_8888, size: { height: 4, width: 6 } };
  try {
    let pixelMap: image.PixelMap = image.createPixelMapUsingAllocatorSync(opts, image.AllocatorType.DMA);
    if (pixelMap == undefined) {
      console.error(`Failed to create the PixelMap.`);
      return;
    }
    console.info('Succeeded in creating the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## image.createPixelMapFromParcel<sup>11+</sup>

createPixelMapFromParcel(sequence: rpc.MessageSequence): PixelMap

从MessageSequence中反序列化并获取PixelMap。

> **说明：**
>
> 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型                                                  | 必填 | 说明                                     |
| ---------------------- | ----------------------------------------------------- | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | 是   | 保存了PixelMap序列化数据的MessageSequence。      |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 返回创建的PixelMap对象，接口调用失败时会抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980096 | The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.|
| 62980097 | IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.|
| 62980115 | Invalid input parameter.|
| 62980105 | Failed to get the data.|
| 62980177 | Abnormal API environment.|
| 62980178 | Failed to create the PixelMap.|
| 62980179 | Abnormal buffer size.|
| 62980180 | FD mapping failed. Possible cause: 1. Size and address does not match. 2. Memory map in memalloc failed.|
| 62980246 | Failed to read the PixelMap.|

**示例：**

```ts
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MySequence implements rpc.Parcelable {
  pixelMap: image.PixelMap;
  constructor(pixelMap: image.PixelMap) {
    this.pixelMap = pixelMap;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    this.pixelMap.marshalling(messageSequence);
    return true;
  }
  unmarshalling(messageSequence: rpc.MessageSequence) {
    try {
      this.pixelMap = image.createPixelMapFromParcel(messageSequence);
    } catch (e) {
      const err = e as BusinessError;
      console.error(`Failed to create the PixelMap from parcel. Code: ${err.code}, message: ${err.message}`);
      return false;
    }
    return true;
  }
}

async function createPixelMapFromParcel() {
  const color: ArrayBuffer = new ArrayBuffer(96);
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = 0x80;
  }
  let opts: image.InitializationOptions = {
    editable: true,
    pixelFormat: image.PixelMapFormat.BGRA_8888,
    size: { height: 4, width: 6 },
    alphaType: image.AlphaType.UNPREMUL
  };
  const pixelMap: image.PixelMap | undefined = await image.createPixelMap(color, opts);
  if (pixelMap != undefined) {
    // 序列化。
    let parcelable: MySequence = new MySequence(pixelMap);
    let data: rpc.MessageSequence = rpc.MessageSequence.create();
    data.writeParcelable(parcelable);

    // 反序列化rpc获取到data。
    let seq: MySequence = new MySequence(pixelMap);
    data.readParcelable(seq);

    // 获取到PixelMap。
    let newPixelMap = seq.pixelMap;
    if (newPixelMap != undefined) {
      console.info('Succeeded in getting the PixelMap.');
    }
  }
}
```

## image.createPixelMapFromSurface<sup>11+</sup>

createPixelMapFromSurface(surfaceId: string, region: Region): Promise\<PixelMap>

根据Surface ID和区域信息创建一个PixelMap对象。该区域的大小由[Region](arkts-apis-image-i.md#region8).size指定。使用Promise异步回调。

> **说明：**
>
> - 当设备为折叠屏，且折叠状态切换时，可能因Surface自带旋转角度导致接口创建失败。需根据Surface的旋转角度相应调整传入的宽高值（如旋转90°或270°时互换宽与高）。如果需要截取整个Surface的区域，推荐使用[image.createPixelMapFromSurface](#imagecreatepixelmapfromsurface15)。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型                 | 必填 | 说明                                     |
| ---------------------- | -------------       | ---- | ---------------------------------------- |
| surfaceId              | string              | 是   | 对应Surface的ID，可通过预览组件获取，如[XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)组件。 |
| region                 | [Region](arkts-apis-image-i.md#region8)  | 是   | 截取的画面区域。仅支持从画面左上角开始截取部分或整个画面，即Region中的x和y必须为0，Region.size中width和height的取值范围分别为[1, 预览流宽度]和[1, 预览流高度]。如需截取任意区域，可先使用[image.createPixelMapFromSurface](#imagecreatepixelmapfromsurface15)获取整个画面，再使用[applyCrop](arkts-apis-image-PixelMap.md#applycrop)截取所需区域。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise对象，返回创建的PixelMap对象，接口调用失败时会抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 62980115 | If the image parameter invalid.|
| 62980105 | Failed to get the data.|
| 62980178 | Failed to create the PixelMap.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPixelMapFromSurface(surfaceId: string) {
  let region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  image.createPixelMapFromSurface(surfaceId, region).then((pixelMap: image.PixelMap) => {
    console.info('Succeeded in creating the PixelMap from Surface.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to create the PixelMap from Surface. Code: ${err.code}, message: ${err.message}`);
  });
} 
```

## image.createPixelMapFromSurfaceSync<sup>12+</sup>

createPixelMapFromSurfaceSync(surfaceId: string, region: Region): PixelMap

根据Surface ID和区域信息创建一个PixelMap对象。该区域的大小由[Region](arkts-apis-image-i.md#region8).size指定。同步返回结果。

> **说明：**
>
> - 当设备为折叠屏，且折叠状态切换时，可能因Surface自带旋转角度导致接口创建失败。需根据Surface的旋转角度相应调整传入的宽高值（如旋转90°或270°时互换宽与高）。如果需要截取整个Surface的区域，推荐使用[image.createPixelMapFromSurfaceSync](#imagecreatepixelmapfromsurfacesync15)。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型                 | 必填 | 说明                                     |
| ---------------------- | -------------       | ---- | ---------------------------------------- |
| surfaceId              | string              | 是   | 对应Surface的ID，可通过预览组件获取，如[XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)组件。 |
| region                 | [Region](arkts-apis-image-i.md#region8)  | 是   | 截取的画面区域。仅支持从画面左上角开始截取部分或整个画面，即Region中的x和y必须为0，Region.size中width和height的取值范围分别为[1, 预览流宽度]和[1, 预览流高度]。如需截取任意区域，可先使用[image.createPixelMapFromSurfaceSync](#imagecreatepixelmapfromsurfacesync15)获取整个画面，再使用[applyCropSync](arkts-apis-image-PixelMap.md#applycropsync)截取所需区域。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 返回创建的PixelMap对象，接口调用失败时会抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 62980105 | Failed to get the data.|
| 62980178 | Failed to create the PixelMap.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPixelMapFromSurfaceSync(surfaceId: string) {
  let region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  try {
    let pixelMap: image.PixelMap = image.createPixelMapFromSurfaceSync(surfaceId, region);
    console.info('Succeeded in creating the PixelMap from Surface.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create the PixelMap from Surface. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## image.createPixelMapFromSurface<sup>15+</sup>

createPixelMapFromSurface(surfaceId: string): Promise\<PixelMap>

从Surface ID创建一个PixelMap对象。使用Promise异步回调。

> **说明：**
>
> - 如果Surface携带旋转或翻转的变换信息且需要校正方向，请使用[image.createPixelMapFromSurfaceWithTransformation](#imagecreatepixelmapfromsurfacewithtransformation23)。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型           | 必填 | 说明                                     |
| ---------------------- | ------------- | ---- | ---------------------------------------- |
| surfaceId              | string        | 是   | 对应Surface的ID，可通过预览组件获取，如[XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)组件。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise对象，返回创建的PixelMap对象，接口调用失败时会抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 62980105 | Failed to get the data. |
| 62980178 | Failed to create the PixelMap. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPixelMapFromSurface(surfaceId: string) {
  image.createPixelMapFromSurface(surfaceId).then((pixelMap: image.PixelMap) => {
    console.info('Succeeded in creating the PixelMap from Surface.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to create the PixelMap from Surface. Code: ${err.code}, message: ${err.message}`);
  });
} 
```

## image.createPixelMapFromSurfaceSync<sup>15+</sup>

createPixelMapFromSurfaceSync(surfaceId: string): PixelMap

从Surface ID创建一个PixelMap对象。同步返回结果。

> **说明：**
>
> - 如果Surface携带旋转或翻转的变换信息且需要校正方向，请使用[image.createPixelMapFromSurfaceWithTransformationSync](#imagecreatepixelmapfromsurfacewithtransformationsync23)。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型           | 必填 | 说明                                     |
| ---------------------- | ------------- | ---- | ---------------------------------------- |
| surfaceId              | string        | 是   | 对应Surface的ID，可通过预览组件获取，如[XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)组件。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 返回创建的PixelMap对象，接口调用失败时会抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 62980105 | Failed to get the data. |
| 62980178 | Failed to create the PixelMap. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPixelMapFromSurfaceSync(surfaceId: string) {
  try {
    let pixelMap: image.PixelMap = image.createPixelMapFromSurfaceSync(surfaceId);
    console.info('Succeeded in creating the PixelMap from Surface.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create the PixelMap from Surface. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## image.createPixelMapFromSurfaceWithTransformation<sup>23+</sup>

createPixelMapFromSurfaceWithTransformation(surfaceId: string, transformEnabled: boolean): Promise\<PixelMap\>

通过Surface的ID创建一个预览流画面的PixelMap对象。该Surface可能携带旋转或翻转的变换信息。使用Promise异步回调。

> **说明：**
>
> - 在API版本23之前，如果要获取无变换效果的PixelMap，可使用[@ohos.arkui.componentSnapshot (组件截图)](../apis-arkui/js-apis-arkui-componentSnapshot.md)能力，或者使用[image.createPixelMapFromSurface](#imagecreatepixelmapfromsurface15)截取后再调用[rotate](./arkts-apis-image-PixelMap.md#rotate9)/[flip](./arkts-apis-image-PixelMap.md#flip9)手动校正方向。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型           | 必填 | 说明                                     |
| ---------------------- | ------------- | ---- | ---------------------------------------- |
| surfaceId              | string        | 是   | 对应Surface的ID，可通过预览组件获取，如[XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)组件。 |
| transformEnabled       | boolean       | 是   | 是否对携带变换信息的Surface预先进行逆变换来消除PixelMap的旋转或翻转效果，即是否进行方向校正。如果Surface未携带变换信息，则本参数不生效。<br>true表示进行逆变换，变换的角度与Surface携带的角度一致且方向相反，输出的PixelMap无旋转或翻转效果。<br>false表示不进行逆变换，输出的PixelMap会根据Surface中的变换信息而带有旋转或翻转效果。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)\> | Promise对象，返回创建的PixelMap对象，接口调用失败时会抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 7600104 | Failed to get the data from Surface. |
| 7600201 | Unsupported operation, e.g. on cross-platform. |
| 7600206 | Invalid parameter. |
| 7600305 | Failed to create the PixelMap. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPixelMapFromSurfaceWithTransformation(surfaceId: string, transformEnabled: boolean) {
  image.createPixelMapFromSurfaceWithTransformation(surfaceId, transformEnabled).then((pixelMap: image.PixelMap) => {
    console.info('Succeeded in creating the PixelMap from Surface.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to create the PixelMap from Surface. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## image.createPixelMapFromSurfaceWithTransformationSync<sup>23+</sup>

createPixelMapFromSurfaceWithTransformationSync(surfaceId: string, transformEnabled: boolean): PixelMap

通过Surface的ID创建一个预览流画面的PixelMap对象。该Surface可能携带旋转或翻转的变换信息。同步返回结果。

> **说明：**
>
> - 在API版本23之前，如果要获取无变换效果的PixelMap，可使用[@ohos.arkui.componentSnapshot (组件截图)](../apis-arkui/js-apis-arkui-componentSnapshot.md)能力，或者使用[image.createPixelMapFromSurfaceSync](#imagecreatepixelmapfromsurfacesync15)截取后再调用[rotateSync](./arkts-apis-image-PixelMap.md#rotatesync12)/[flipSync](./arkts-apis-image-PixelMap.md#flipsync12)手动校正方向。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名                 | 类型           | 必填 | 说明                                     |
| ---------------------- | ------------- | ---- | ---------------------------------------- |
| surfaceId              | string        | 是   | 对应Surface的ID，可通过预览组件获取，如[XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)组件。 |
| transformEnabled       | boolean       | 是   | 是否对携带变换信息的Surface预先进行逆变换来消除PixelMap的旋转或翻转效果，即是否进行方向校正。如果Surface未携带变换信息，则本参数不生效。<br>true表示进行逆变换，变换的角度与Surface携带的角度一致且方向相反，输出的PixelMap无旋转或翻转效果。<br>false表示不进行逆变换，输出的PixelMap会根据Surface中的变换信息而带有旋转或翻转效果。 |

**返回值：**

| 类型                             | 说明                  |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | 返回创建的PixelMap对象，接口调用失败时会抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 7600104 | Failed to get the data from Surface. |
| 7600201 | Unsupported operation, e.g. on cross-platform. |
| 7600206 | Invalid parameter. |
| 7600305 | Failed to create the PixelMap. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPixelMapFromSurfaceWithTransformationSync(surfaceId: string, transformEnabled: boolean) {
  try {
    const pixelMap: image.PixelMap = image.createPixelMapFromSurfaceWithTransformationSync(surfaceId, transformEnabled);
    console.info('Succeeded in creating the PixelMap from Surface.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create the PixelMap from Surface. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## image.createPremultipliedPixelMap<sup>12+</sup>

createPremultipliedPixelMap(src: PixelMap, dst: PixelMap, callback: AsyncCallback\<void>): void

将PixelMap像素数据的透明度类型从非预乘模式转换为预乘模式，转换后的像素数据存入目标PixelMap。适用于图像渲染管线需要预乘Alpha格式的场景，例如使用OpenGL等图形接口进行图像合成时。使用callback异步回调。

> **说明：**
>
> - 该转换仅支持除RGBA_F16和ASTC_4x4之外其他包含Alpha通道的像素格式。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                                             | 必填 | 说明                       |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| src | [PixelMap](arkts-apis-image-PixelMap.md) | 是   | 源PixelMap对象，透明度类型需为非预乘模式（AlphaType.UNPREMUL），像素格式必须包含Alpha通道（RGBA_F16和ASTC_4x4除外）。 |
| dst | [PixelMap](arkts-apis-image-PixelMap.md) | 是   | 目标PixelMap对象，透明度类型需为预乘模式（AlphaType.PREMUL）且必须可编辑，其他属性（宽度、高度、像素格式等）必须与源PixelMap相同，转换后的像素数据将写入该对象。 |
| callback | AsyncCallback\<void> | 是   | 回调函数，当透明度类型转换成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401          | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  62980103     | The image data is not supported. |
|  62980246     | Failed to read the pixelMap. |
|  62980248     | Pixelmap not allow modify. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPremultipliedPixelMap() {
  const color: ArrayBuffer = new ArrayBuffer(16); // 16为需要创建的像素缓冲区大小，取值为：width * height * 4。
  let bufferArr = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i += 4) {
    bufferArr[i] = 255;
    bufferArr[i + 1] = 255;
    bufferArr[i + 2] = 122;
    bufferArr[i + 3] = 122;
  }
  let optsForUnpre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 }, alphaType: image.AlphaType.UNPREMUL};
  let srcPixelMap = image.createPixelMapSync(color, optsForUnpre);
  let optsForPre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 }, alphaType: image.AlphaType.PREMUL};
  let dstPixelMap = image.createPixelMapSync(optsForPre);
  image.createPremultipliedPixelMap(srcPixelMap, dstPixelMap, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to convert the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in converting the PixelMap.');
  });
}
```

## image.createPremultipliedPixelMap<sup>12+</sup>

createPremultipliedPixelMap(src: PixelMap, dst: PixelMap): Promise\<void>

将PixelMap像素数据的透明度类型从非预乘模式转换为预乘模式，转换后的像素数据存入目标PixelMap。适用于图像渲染管线需要预乘Alpha格式的场景，例如使用OpenGL等图形接口进行图像合成时。使用Promise异步回调。

> **说明：**
>
> - 该转换仅支持除RGBA_F16和ASTC_4x4之外其他包含Alpha通道的像素格式。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                                             | 必填 | 说明                       |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| src | [PixelMap](arkts-apis-image-PixelMap.md) | 是   | 源PixelMap对象，透明度类型需为非预乘模式（AlphaType.UNPREMUL），像素格式必须包含Alpha通道（RGBA_F16和ASTC_4x4除外）。 |
| dst | [PixelMap](arkts-apis-image-PixelMap.md) | 是   | 目标PixelMap对象，透明度类型需为预乘模式（AlphaType.PREMUL）且必须可编辑，其他属性（宽度、高度、像素格式等）必须与源PixelMap相同，转换后的像素数据将写入该对象。 |

**返回值：**

| 类型                             | 说明                                                                    |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401          | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  62980103     | The image data is not supported. |
|  62980246     | Failed to read the pixelMap. |
|  62980248     | Pixelmap not allow modify. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPremultipliedPixelMap() {
  const color: ArrayBuffer = new ArrayBuffer(16); // 16为需要创建的像素缓冲区大小，取值为：width * height * 4。
  let bufferArr = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i += 4) {
    bufferArr[i] = 255;
    bufferArr[i + 1] = 255;
    bufferArr[i + 2] = 122;
    bufferArr[i + 3] = 122;
  }
  let optsForUnpre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 }, alphaType: image.AlphaType.UNPREMUL};
  let srcPixelMap = image.createPixelMapSync(color, optsForUnpre);
  let optsForPre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 }, alphaType: image.AlphaType.PREMUL};
  let dstPixelMap = image.createPixelMapSync(optsForPre);
  image.createPremultipliedPixelMap(srcPixelMap, dstPixelMap).then(() => {
    console.info('Succeeded in converting the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to convert the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## image.createUnpremultipliedPixelMap<sup>12+</sup>

createUnpremultipliedPixelMap(src: PixelMap, dst: PixelMap, callback: AsyncCallback\<void>): void

将PixelMap像素数据的透明度类型从预乘模式转换为非预乘模式，转换后的像素数据存入目标PixelMap。适用于需要对像素原始颜色值进行直接处理的场景，例如图像编辑、像素级分析等。使用callback异步回调。

> **说明：**
>
> - 该转换仅支持除RGBA_F16和ASTC_4x4之外其他包含Alpha通道的像素格式。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名   | 类型                                             | 必填 | 说明                       |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| src | [PixelMap](arkts-apis-image-PixelMap.md) | 是   | 源PixelMap对象，透明度类型需为预乘模式（AlphaType.PREMUL），像素格式必须包含Alpha通道（RGBA_F16和ASTC_4x4除外）。 |
| dst | [PixelMap](arkts-apis-image-PixelMap.md) | 是   | 目标PixelMap对象，透明度类型需为非预乘模式（AlphaType.UNPREMUL）且必须可编辑，其他属性（宽度、高度、像素格式等）必须与源PixelMap相同，转换后的像素数据将写入该对象。 |
|callback | AsyncCallback\<void> | 是   | 回调函数，当透明度类型转换成功时，err为undefined；否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401          | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
|  62980103     | The image data is not supported. |
|  62980246     | Failed to read the pixelMap. |
|  62980248     | Pixelmap not allow modify. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createUnpremultipliedPixelMap() {
  const color: ArrayBuffer = new ArrayBuffer(16); // 16为需要创建的像素缓冲区大小，取值为：width * height * 4。
  let bufferArr = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i += 4) {
    bufferArr[i] = 255;
    bufferArr[i + 1] = 255;
    bufferArr[i + 2] = 122;
    bufferArr[i + 3] = 122;
  }
  let optsForPre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 }, alphaType: image.AlphaType.PREMUL};
  let srcPixelMap = image.createPixelMapSync(color, optsForPre);
  let optsForUnpre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 }, alphaType: image.AlphaType.UNPREMUL};
  let dstPixelMap = image.createPixelMapSync(optsForUnpre);
  image.createUnpremultipliedPixelMap(srcPixelMap, dstPixelMap, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to convert the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in converting the PixelMap.');
  });
}
```

## image.createUnpremultipliedPixelMap<sup>12+</sup>

createUnpremultipliedPixelMap(src: PixelMap, dst: PixelMap): Promise\<void>

将PixelMap像素数据的透明度类型从预乘模式转换为非预乘模式，转换后的像素数据存入目标PixelMap。适用于需要对像素原始颜色值进行直接处理的场景，例如图像编辑、像素级分析等。使用Promise异步回调。

> **说明：**
>
> - 该转换仅支持除RGBA_F16和ASTC_4x4之外其他包含Alpha通道的像素格式。
> - 由于图片占用内存较大，所以当PixelMap对象使用完成后，应主动调用[release](./arkts-apis-image-PixelMap.md#release7)方法及时释放内存。释放时应确保该对象的所有异步方法均执行完成，且后续不再使用该对象。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                                                             |
| ------- | ------------------------------------------------ | ---- | ---------------------------------------------------------------- |
| src | [PixelMap](arkts-apis-image-PixelMap.md) | 是   | 源PixelMap对象，透明度类型需为预乘模式（AlphaType.PREMUL），像素格式必须包含Alpha通道（RGBA_F16和ASTC_4x4除外）。 |
| dst | [PixelMap](arkts-apis-image-PixelMap.md) | 是   | 目标PixelMap对象，透明度类型需为非预乘模式（AlphaType.UNPREMUL）且必须可编辑，其他属性（宽度、高度、像素格式等）必须与源PixelMap相同，转换后的像素数据将写入该对象。 |

**返回值：**

| 类型                             | 说明                                                                    |
| -------------------------------- | ----------------------------------------------------------------------- |
| Promise\<void> |  Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
|  401         | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
|  62980103    | The image data is not supported. |
|  62980246    | Failed to read the pixelMap. |
|  62980248    | Pixelmap not allow modify. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createUnpremultipliedPixelMap() {
  const color: ArrayBuffer = new ArrayBuffer(16); // 16为需要创建的像素缓冲区大小，取值为：width * height * 4。
  let bufferArr = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i += 4) {
    bufferArr[i] = 255;
    bufferArr[i + 1] = 255;
    bufferArr[i + 2] = 122;
    bufferArr[i + 3] = 122;
  }
  let optsForPre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 }, alphaType: image.AlphaType.PREMUL};
  let srcPixelMap = image.createPixelMapSync(color, optsForPre);
  let optsForUnpre: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 2, width: 2 }, alphaType: image.AlphaType.UNPREMUL};
  let dstPixelMap = image.createPixelMapSync(optsForUnpre);
  image.createUnpremultipliedPixelMap(srcPixelMap, dstPixelMap).then(() => {
    console.info('Succeeded in converting the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to convert the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## image.createImageSource

createImageSource(uri: string): ImageSource

通过传入的uri创建ImageSource实例。

由于图片占用内存较大，所以当ImageSource实例使用完成后，应主动调用[release](./arkts-apis-image-ImageSource.md#release)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名 | 类型   | 必填 | 说明                               |
| ------ | ------ | ---- | ---------------------------------- |
| uri    | string | 是   | 图片路径，当前仅支持应用沙箱路径。<br>当前支持格式有：JPEG、PNG、GIF、BMP、WebP、DNG、HEIC<sup>12+</sup>、WBMP<sup>23+</sup>、HEIFS<sup>23+</sup>、TIFF<sup>23+</sup>、SVG<sup>10+</sup>（可参考[SVG标签说明](#svg标签说明)）、ICO<sup>11+</sup>。从API版本26.0.0开始，增加支持AVIF、AVIS格式。<br>部分格式的解码能力依赖于具体的设备硬件，建议在调用前使用[image.getImageSourceSupportedFormats](#imagegetimagesourcesupportedformats20)接口，动态查询当前设备上的解码能力。 |

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**
```ts
async function CreateImageSource(context : Context) {
  // 此处'test.jpg'仅作示例，请开发者自行替换。否则imageSource会创建失败，导致后续无法正常执行。
  const path: string = context.filesDir + "/test.jpg";
  const imageSourceObj: image.ImageSource = image.createImageSource(path);
}
```

## image.createImageSource<sup>9+</sup>

createImageSource(uri: string, options: SourceOptions): ImageSource

通过传入的uri创建ImageSource实例。

由于图片占用内存较大，所以当ImageSource实例使用完成后，应主动调用[release](./arkts-apis-image-ImageSource.md#release)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                            | 必填 | 说明                                |
| ------- | ------------------------------- | ---- | ----------------------------------- |
| uri     | string                          | 是   | 图片路径，当前仅支持应用沙箱路径（可参考[使用说明](../apis-core-file-kit/js-apis-file-fs.md#使用说明)）。<br>当前支持格式有：JPEG、PNG、GIF、BMP、WebP、DNG、HEIC<sup>12+</sup>、WBMP<sup>23+</sup>、HEIFS<sup>23+</sup>、TIFF<sup>23+</sup>、SVG<sup>10+</sup>（可参考[SVG标签说明](#svg标签说明)）、ICO<sup>11+</sup>。从API版本26.0.0开始，增加支持AVIF、AVIS格式。部分格式的解码能力依赖于具体的设备硬件，建议在调用前使用[image.getImageSourceSupportedFormats](#imagegetimagesourcesupportedformats20)接口，动态查询当前设备上的解码能力。 |
| options | [SourceOptions](arkts-apis-image-i.md#sourceoptions9) | 是   | 图片属性，包括图片像素密度、像素格式和图片尺寸。|

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

```ts
async function CreateImageSource(context : Context) {
  let sourceOptions: image.SourceOptions = { sourceDensity: 120 };
  // 此处'test.png'仅作示例，请开发者自行替换。否则imageSource会创建失败，导致后续无法正常执行。
  const path: string = context.filesDir + "/test.png";
  let imageSourceObj: image.ImageSource = image.createImageSource(path, sourceOptions);
}
```

## image.createImageSource<sup>7+</sup>

createImageSource(fd: number): ImageSource

通过传入文件描述符来创建ImageSource实例。

由于图片占用内存较大，所以当ImageSource实例使用完成后，应主动调用[release](./arkts-apis-image-ImageSource.md#release)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名 | 类型   | 必填 | 说明          |
| ------ | ------ | ---- | ------------- |
| fd     | number | 是   | 文件描述符fd。取值范围为[0，65535]。|

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

```ts
import { fileIo } from '@kit.CoreFileKit';

async function CreateImageSource(context : Context) {
  // 此处'test.jpg'仅作示例，请开发者自行替换，否则imageSource会创建失败导致后续无法正常执行。
  let filePath: string = context.filesDir + "/test.jpg";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  const imageSourceObj: image.ImageSource = image.createImageSource(file.fd);
}
```

## image.createImageSource<sup>9+</sup>

createImageSource(fd: number, options: SourceOptions): ImageSource

通过传入文件描述符来创建ImageSource实例。

由于图片占用内存较大，所以当ImageSource实例使用完成后，应主动调用[release](./arkts-apis-image-ImageSource.md#release)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                            | 必填 | 说明                                |
| ------- | ------------------------------- | ---- | ----------------------------------- |
| fd      | number                          | 是   | 文件描述符fd。取值范围为[0，65535]。                      |
| options | [SourceOptions](arkts-apis-image-i.md#sourceoptions9) | 是   | 图片属性，包括图片像素密度、像素格式和图片尺寸。|

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

```ts
import { fileIo } from '@kit.CoreFileKit';

async function CreateImageSource(context : Context) {
  let sourceOptions: image.SourceOptions = { sourceDensity: 120 };
  // 此处'test.jpg'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
  const filePath: string = context.filesDir + "/test.jpg";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  const imageSourceObj: image.ImageSource = image.createImageSource(file.fd, sourceOptions);
}
```

## image.createImageSource<sup>9+</sup>

createImageSource(buf: ArrayBuffer): ImageSource

通过缓冲区创建ImageSource实例。buf数据是未解码的数据，不可以传入类似于RGBA，YUV的像素buffer数据，如果想通过像素buffer数据创建pixelMap，可以调用[image.createPixelMapSync](./arkts-apis-image-f.md#imagecreatepixelmapsync12)这一类接口。

由于图片占用内存较大，所以当ImageSource实例使用完成后，应主动调用[release](./arkts-apis-image-ImageSource.md#release)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名 | 类型        | 必填 | 说明             |
| ------ | ----------- | ---- | ---------------- |
| buf    | ArrayBuffer | 是   | 图像缓冲区数组。 |

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

```ts
async function CreateImageSource() {
  const buf: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素缓冲区大小，取值为：width * height * 4。
  const imageSourceObj: image.ImageSource = image.createImageSource(buf);
}
```

## image.createImageSource<sup>9+</sup>

createImageSource(buf: ArrayBuffer, options: SourceOptions): ImageSource

通过缓冲区创建ImageSource实例。buf数据是未解码的数据，不可以传入类似于RGBA，YUV的像素buffer数据，如果想通过像素buffer数据创建pixelMap，可以调用[image.createPixelMapSync](./arkts-apis-image-f.md#imagecreatepixelmapsync12)这一类接口。

由于图片占用内存较大，所以当ImageSource实例使用完成后，应主动调用[release](./arkts-apis-image-ImageSource.md#release)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名 | 类型                             | 必填 | 说明                                 |
| ------ | -------------------------------- | ---- | ------------------------------------ |
| buf    | ArrayBuffer                      | 是   | 图像缓冲区数组。                     |
| options | [SourceOptions](arkts-apis-image-i.md#sourceoptions9) | 是   | 图片属性，包括图片像素密度、像素格式和图片尺寸。 |

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

```ts
async function CreateImageSource() {
  const data: ArrayBuffer = new ArrayBuffer(112);
  let sourceOptions: image.SourceOptions = { sourceDensity: 120 };
  const imageSourceObj: image.ImageSource = image.createImageSource(data, sourceOptions);
}
```

## image.createImageSource<sup>11+</sup>

createImageSource(rawfile: resourceManager.RawFileDescriptor, options?: SourceOptions): ImageSource

通过图像资源文件的RawFileDescriptor创建ImageSource实例。

由于图片占用内存较大，所以当ImageSource实例使用完成后，应主动调用[release](./arkts-apis-image-ImageSource.md#release)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名 | 类型                             | 必填 | 说明                                 |
| ------ | -------------------------------- | ---- | ------------------------------------ |
| rawfile | [resourceManager.RawFileDescriptor](../apis-localization-kit/js-apis-resource-manager.md#rawfiledescriptor9) | 是 | 图像资源文件的RawFileDescriptor。 |
| options | [SourceOptions](arkts-apis-image-i.md#sourceoptions9) | 否 | 图片属性，包括图片像素密度、像素格式和图片尺寸。 |

**返回值：**

| 类型                        | 说明                                         |
| --------------------------- | -------------------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | 返回ImageSource类实例，失败时返回undefined。 |

**示例：**

```ts
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';
  
async function CreateImageSource(context : Context) {
  // 获取resourceManager资源管理器。
  const resourceMgr: resourceManager.ResourceManager = context.resourceManager;
  // 此处'test.jpg'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
  resourceMgr.getRawFd('test.jpg').then((rawFileDescriptor: resourceManager.RawFileDescriptor) => {
    const imageSourceObj: image.ImageSource = image.createImageSource(rawFileDescriptor);
  }).catch((error: BusinessError) => {
    console.error(`Failed to get RawFileDescriptor.code is ${error.code}, message is ${error.message}`);
  })
}
```

## image.CreateIncrementalSource<sup>9+</sup>

CreateIncrementalSource(buf: ArrayBuffer): ImageSource

通过缓冲区以增量的方式创建ImageSource实例，IncrementalSource不支持读写Exif信息。

由于图片占用内存较大，所以当ImageSource实例使用完成后，应主动调用[release](./arkts-apis-image-ImageSource.md#release)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

以增量方式创建的ImageSource实例，仅支持使用以下功能，同步、异步callback、异步Promise均支持。

- 获取图片信息：指定序号-[getImageInfo](arkts-apis-image-ImageSource.md#getimageinfo)、直接获取-[getImageInfo](arkts-apis-image-ImageSource.md#getimageinfo-1)
- 获取图片中给定索引处图像的指定属性键的值：[getImageProperty](arkts-apis-image-ImageSource.md#getimageproperty11)
- 批量获取图片中的指定属性键的值：[getImageProperties](arkts-apis-image-ImageSource.md#getimageproperties12)
- 更新增量数据：[updateData](arkts-apis-image-ImageSource.md#updatedata9)
- 创建PixelMap对象：通过图片解码参数创建-[createPixelMap](arkts-apis-image-ImageSource.md#createpixelmap7)、通过默认参数创建-[createPixelMap](arkts-apis-image-ImageSource.md#createpixelmap7-1) 、通过图片解码参数-[createPixelMap](arkts-apis-image-ImageSource.md#createpixelmap7-2)
- 释放ImageSource实例：[release](arkts-apis-image-ImageSource.md#release)

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型        | 必填 | 说明      |
| ------- | ------------| ---- | ----------|
| buf     | ArrayBuffer | 是   | 增量数据。|

**返回值：**

| 类型                        | 说明                              |
| --------------------------- | --------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | 返回ImageSource，失败时返回undefined。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreateIncrementalImageSource(context : Context) {
  let imageArray = context.resourceManager.getMediaContentSync($r('app.media.startIcon').id); // 获取图像资源。
  // 此处'app.media.startIcon'仅作示例，请开发者自行替换，否则imageArray创建失败会导致后续无法正常执行。
  let splitBuff1 = imageArray.slice(0, imageArray.byteLength / 2);  // 分片。
  let splitBuff2 = imageArray.slice(imageArray.byteLength / 2);
  const imageSourceIncrementalSApi: image.ImageSource = image.CreateIncrementalSource(new ArrayBuffer(imageArray.byteLength));
  imageSourceIncrementalSApi.updateData(splitBuff1, false, 0, splitBuff1.byteLength).then(() => {
    imageSourceIncrementalSApi.updateData(splitBuff2, true, 0, splitBuff2.byteLength).then(() => {
      let pixelMap = imageSourceIncrementalSApi.createPixelMapSync();
      console.info('Succeeded in creating pixelMap');
    }).catch((error: BusinessError) => {
      console.error(`Failed to updateData error code is ${error.code}, message is ${error.message}`);
    })
  }).catch((error: BusinessError) => {
    console.error(`Failed to updateData error code is ${error.code}, message is ${error.message}`);
  })
}
```

## image.CreateIncrementalSource<sup>9+</sup>

CreateIncrementalSource(buf: ArrayBuffer, options?: SourceOptions): ImageSource

通过缓冲区以增量的方式创建ImageSource实例，IncrementalSource不支持读写Exif信息。

此接口支持的功能与[CreateIncrementalSource(buf: ArrayBuffer): ImageSource](#imagecreateincrementalsource9)所生成的实例支持的功能相同。

由于图片占用内存较大，所以当ImageSource实例使用完成后，应主动调用[release](./arkts-apis-image-ImageSource.md#release)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**参数：**

| 参数名  | 类型                            | 必填 | 说明                                 |
| ------- | ------------------------------- | ---- | ------------------------------------ |
| buf     | ArrayBuffer                     | 是   | 增量数据。                           |
| options | [SourceOptions](arkts-apis-image-i.md#sourceoptions9) | 否   | 图片属性，包括图片像素密度、像素格式和图片尺寸。 |

**返回值：**

| 类型                        | 说明                              |
| --------------------------- | --------------------------------- |
| [ImageSource](arkts-apis-image-ImageSource.md) | 返回ImageSource，失败时返回undefined。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function CreateIncrementalImageSource(context : Context) {
  let imageArray = context.resourceManager.getMediaContentSync($r('app.media.startIcon').id); // 获取图像资源。
  // 此处'app.media.startIcon'仅作示例，请开发者自行替换，否则imageArray创建失败会导致后续无法正常执行。
  let splitBuff1 = imageArray.slice(0, imageArray.byteLength / 2);  // 分片。
  let splitBuff2 = imageArray.slice(imageArray.byteLength / 2);
  let sourceOptions: image.SourceOptions = { sourceDensity: 120};

  const imageSourceIncrementalSApi: image.ImageSource = image.CreateIncrementalSource(new ArrayBuffer(imageArray.byteLength), sourceOptions);
  imageSourceIncrementalSApi.updateData(splitBuff1, false, 0, splitBuff1.byteLength).then(() => {
    imageSourceIncrementalSApi.updateData(splitBuff2, true, 0, splitBuff2.byteLength).then(() => {
      let pixelMap = imageSourceIncrementalSApi.createPixelMapSync();
      console.info('Succeeded in creating pixelMap');
    }).catch((error: BusinessError) => {
      console.error(`Failed to updateData error code is ${error.code}, message is ${error.message}`);
    })
  }).catch((error: BusinessError) => {
    console.error(`Failed to updateData error code is ${error.code}, message is ${error.message}`);
  })
}
```

## image.getImageSourceSupportedFormats<sup>20+</sup>

getImageSourceSupportedFormats(): string[]

获取支持解码的图片格式，图片格式以mime type表示。

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**返回值：**

| 类型     | 说明                                       |
| -------- | ------------------------------------------ |
| string[] | 支持解码的图片格式（mime type）列表。 |

**示例：**

```ts
async function GetImageSourceSupportedFormats() {
    let formats = image.getImageSourceSupportedFormats();
    console.info('formats:', formats);
}

async function IsSupportedTiffFormat() {
    let formats = image.getImageSourceSupportedFormats();
    return formats.includes("image/tiff");
}

```

## image.createImagePacker

createImagePacker(): ImagePacker

创建ImagePacker实例。

由于图片占用内存较大，所以当ImagePacker实例使用完成后，应主动调用[release](./arkts-apis-image-ImagePacker.md#release)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**返回值：**

| 类型                        | 说明                  |
| --------------------------- | --------------------- |
| [ImagePacker](arkts-apis-image-ImagePacker.md) | 返回ImagePacker实例。 |

**示例：**

```ts
async function CreateImagePacker() {
  const imagePackerObj: image.ImagePacker = image.createImagePacker();
}
```

## image.getImagePackerSupportedFormats<sup>20+</sup>

getImagePackerSupportedFormats(): string[]

获取支持编码的图片格式，图片格式以mime type表示。

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**返回值：**

| 类型     | 说明                                       |
| -------- | ------------------------------------------ |
| string[] | 支持编码的图片格式（mime type）列表。 |

**示例：**

```ts
async function GetImagePackerSupportedFormats() {
    let formats = image.getImagePackerSupportedFormats();
    console.info('formats:', formats);
}
```

## image.createAuxiliaryPicture<sup>13+</sup>

createAuxiliaryPicture(buffer: ArrayBuffer, size: Size, type: AuxiliaryPictureType): AuxiliaryPicture

通过ArrayBuffer图片数据、辅助图尺寸、辅助图类型创建AuxiliaryPicture实例。该接口仅支持传入BGRA的连续像素数据，会创建出RGBA的辅助图。

由于图片占用内存较大，所以当AuxiliaryPicture实例使用完成后，应主动调用[release](./arkts-apis-image-AuxiliaryPicture.md#release13)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 | 类型                                            | 必填 | 说明                         |
| ------ | ----------------------------------------------- | ---- | ---------------------------- |
| buffer | ArrayBuffer                                     | 是   | 以buffer形式存放的图像数据。  |
| size   | [Size](arkts-apis-image-i.md#size)                                   | 是   | 辅助图的尺寸。单位：像素（px）。    |
| type   | [AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13) | 是   | 辅助图类型。                 |

**返回值：**

| 类型                                    | 说明                                       |
| --------------------------------------- | ------------------------------------------ |
| [AuxiliaryPicture](arkts-apis-image-AuxiliaryPicture.md) | 如果操作成功，则返回AuxiliaryPicture实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

```ts
async function CreateAuxiliaryPicture(context: Context) {
  let funcName = "CreateAuxiliaryPicture";
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("hdr.jpg"); // 需要支持hdr的图片。
  let auxBuffer: ArrayBuffer = rawFile.buffer as ArrayBuffer;
  let auxSize: image.Size = {
    height: 180,
    width: 240
  };
  let auxType: image.AuxiliaryPictureType = image.AuxiliaryPictureType.GAINMAP;
  let auxPictureObj: image.AuxiliaryPicture | null = image.createAuxiliaryPicture(auxBuffer, auxSize, auxType);
  if(auxPictureObj != null) {
    let type: image.AuxiliaryPictureType = auxPictureObj.getType();
    console.info(funcName, `CreateAuxiliaryPicture succeeded this.Aux_picture.type ${type}`);
  } else {
    console.error(funcName, 'CreateAuxiliaryPicture failed');
  }
}
```

## image.createAuxiliaryPictureUsingAllocator<sup>24+</sup>

createAuxiliaryPictureUsingAllocator(auxiliaryPictureInfo: AuxiliaryPictureInfo, allocatorType?: AllocatorType, pixels?: ArrayBuffer): AuxiliaryPicture

使用指定的内存类型，根据辅助图信息和像素数据创建辅助图对象。

> **说明：**
>
> - 在处理此接口返回的AuxiliaryPicture时，需要考虑内存中每行像素所占的空间的影响。
> - 创建的辅助图像会使用输入的像素进行初始化。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.Core

**参数：**

| 参数名 |              类型             | 必填 | 说明                         |
| ------ | ----------------------------------------------- | ---- | ---------------------------- |
| auxiliaryPictureInfo | [AuxiliaryPictureInfo](arkts-apis-image-i.md#auxiliarypictureinfo13) | 是 | 辅助图图像信息。<br>- 输入的ArrayBuffer的pixelFormat和最终创建出的辅助图的实际pixelFormat需与auxiliaryPictureInfo中指定的pixelFormat保持一致。<br>- 当AuxiliaryPictureType为GAINMAP时，AllocatorType仅支持传入AUTO/DMA。<br>- 当传入SHARE_MEMORY时，返回错误码7600205。  |
| allocatorType | [AllocatorType](arkts-apis-image-e.md#allocatortype15) | 否 | 图像解码的内存类型，AUTO及默认情况下按照DMA处理。  |
| pixels | ArrayBuffer | 否 | 以buffer形式存放的图像数据。<br>当未提供ArrayBuffer参数时，默认创建空白辅助图。  |

**返回值：**

| 类型                                    | 说明                                       |
| --------------------------------------- | ------------------------------------------ |
| [AuxiliaryPicture](arkts-apis-image-AuxiliaryPicture.md) | 如果操作成功，则返回AuxiliaryPicture实例。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 7600205  | Unsupported allocator type,e.g., use shared memory to create a gainmap as only DMA supported hdr metadata. |
| 7600206  | Invalid parameter, size.height or size.width is less than or equal to 0. |
| 7600301  | Alloc memory failed. |

**示例：**

```ts
import { image } from '@kit.ImageKit';

function CreateAuxiliaryPictureUsingAllocator(info: image.AuxiliaryPictureInfo,  allocatorType?: image.AllocatorType, pixels?: ArrayBuffer ) {
  let res : image.AuxiliaryPicture;
  try {
    res = image.createAuxiliaryPictureUsingAllocator(info, allocatorType, pixels);
  } catch (error) {
    console.error(`Failed to create auxiliary picture using allocator=${allocatorType} and pixels=${pixels?.byteLength}.`);
  }
}
```

## image.createImageReceiver<sup>11+</sup>

createImageReceiver(size: Size, format: ImageFormat, capacity: number): ImageReceiver

通过图片大小、图片格式、容量创建ImageReceiver实例。ImageReceiver作为图片的接收方、消费者，它的参数属性实际上不会对接收到的图片产生影响。图片属性的配置应在发送方、生产者进行，如相机预览流[createPreviewOutput](../apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput)。

由于图片占用内存较大，所以当ImageReceiver实例使用完成后，应主动调用[release](./arkts-apis-image-ImageReceiver.md#release9)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| size    | [Size](arkts-apis-image-i.md#size)  | 是   | 图像的默认大小。单位：像素（px）。该参数不会影响接收到的图片大小，实际返回大小由生产者决定，如相机。       |
| format   | [ImageFormat](arkts-apis-image-e.md#imageformat9) | 是   | 图像格式，取值为[ImageFormat](arkts-apis-image-e.md#imageformat9)常量（目前仅支持 ImageFormat:JPEG，实际返回格式由生产者决定，如相机）。             |
| capacity | number | 是   | 同时访问的最大图像数。该参数仅作为期望值，实际capacity由设备硬件决定。 |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| [ImageReceiver](arkts-apis-image-ImageReceiver.md) | 如果操作成功，则返回ImageReceiver实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401| Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;   |

**示例：**

```ts
let size: image.Size = {
  height: 8192,
  width: 8192
}
let receiver: image.ImageReceiver = image.createImageReceiver(size, image.ImageFormat.JPEG, 8);
```

## image.createImageReceiver<sup>23+</sup>

createImageReceiver(options?: ImageReceiverOptions): ImageReceiver | undefined

通过ImageReceiverOptions创建ImageReceiver实例。ImageReceiver作为图片的接收方、消费者，其参数属性实际上不会对接收到的图片产生影响。图片属性的配置应在发送方、生产者进行，如相机预览流[createPreviewOutput](../apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput)。

由于图片占用内存较大，所以当ImageReceiver实例使用完成后，应主动调用[release](./arkts-apis-image-ImageReceiver.md#release9)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| options  | [ImageReceiverOptions](arkts-apis-image-i.md#imagereceiveroptions23)  | 否   | 创建ImageReceiver的属性，包括图片的默认大小和同时访问的最大图片数。<br>未传入options时，默认的size为1920*1080，单位为像素（px），表示期望接收宽为1920px，高为1080px的图片。<br>未传入options时，默认的capacity为3，表示期望同时最多有3张图片等待读取。       |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| [ImageReceiver](arkts-apis-image-ImageReceiver.md) \| undefined | 操作成功时返回ImageReceiver实例，否则返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[Image错误码](errorcode-image.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 7900201| Invalid parameter.   |

**示例：**

```ts
let options: image.ImageReceiverOptions = {
  size: { width: 480, height: 480 },
  capacity: 3
}
let receiver: image.ImageReceiver | undefined = image.createImageReceiver(options);
```

## image.createImageCreator<sup>11+</sup>

createImageCreator(size: Size, format: ImageFormat, capacity: number): ImageCreator

通过图片大小、图片格式、容量创建ImageCreator实例。

由于图片占用内存较大，所以当ImageCreator实例使用完成后，应主动调用[release](./arkts-apis-image-ImageCreator.md#release9)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**参数：**

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| size    | [Size](arkts-apis-image-i.md#size)  | 是   | 图像的默认大小。单位：像素（px）。       |
| format   | [ImageFormat](arkts-apis-image-e.md#imageformat9) | 是   | 图像格式，如YCBCR_422_SP，JPEG。             |
| capacity | number | 是   | 同时访问的最大图像数。该参数仅作为期望值，实际capacity由设备硬件决定。 |

**返回值：**

| 类型                           | 说明                                    |
| ------------------------------ | --------------------------------------- |
| [ImageCreator](arkts-apis-image-ImageCreator.md) | 如果操作成功，则返回ImageCreator实例。 |


**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401| Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;          |

**示例：**

```ts
let size: image.Size = {
  height: 8192,
  width: 8192
}
let creator: image.ImageCreator = image.createImageCreator(size, image.ImageFormat.JPEG, 8);
```

## image.createImageReceiver<sup>(deprecated)</sup>

createImageReceiver(width: number, height: number, format: number, capacity: number): ImageReceiver

通过宽、高、图片格式、容量创建ImageReceiver实例。ImageReceiver作为图片的接收方、消费者，它的参数属性实际上不会对接收到的图片产生影响。图片属性的配置应在发送方、生产者进行，如相机预览流[createPreviewOutput](../apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput)。

由于图片占用内存较大，所以当ImageReceiver实例使用完成后，应主动调用[release](./arkts-apis-image-ImageReceiver.md#release9)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

> **说明：**
>
> 从API version 9开始支持，从API version 11废弃，建议使用[createImageReceiver](#imagecreateimagereceiver11)代替。

**系统能力：** SystemCapability.Multimedia.Image.ImageReceiver

**参数：**

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| width    | number | 是   | 图像的默认宽度。单位：像素（px）。该参数不会影响接收到的图片宽度，实际宽度由生产者决定，如相机。       |
| height   | number | 是   | 图像的默认高度。单位：像素（px）。该参数不会影响接收到的图片高度，实际高度由生产者决定，如相机。       |
| format   | number | 是   | 图像格式，取值为[ImageFormat](arkts-apis-image-e.md#imageformat9)常量（目前仅支持 ImageFormat:JPEG，实际返回格式由生产者决定，如相机）。  |
| capacity | number | 是   | 同时访问的最大图像数。该参数仅作为期望值，实际capacity由设备硬件决定。 |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| [ImageReceiver](arkts-apis-image-ImageReceiver.md) | 如果操作成功，则返回ImageReceiver实例。 |

**示例：**

```ts
let receiver: image.ImageReceiver = image.createImageReceiver(8192, 8192, image.ImageFormat.JPEG, 8);
```

## image.createImageCreator<sup>(deprecated)</sup>

createImageCreator(width: number, height: number, format: number, capacity: number): ImageCreator

通过宽、高、图片格式、容量创建ImageCreator实例。

由于图片占用内存较大，所以当ImageCreator实例使用完成后，应主动调用[release](./arkts-apis-image-ImageCreator.md#release9)方法及时释放内存。释放时应确保该实例的所有异步方法均执行完成，且后续不再使用该实例。

> **说明：**
>
> 从API version 9开始支持，从API version 11废弃，建议使用[createImageCreator](#imagecreateimagecreator11)代替。

**系统能力：** SystemCapability.Multimedia.Image.ImageCreator

**参数：**

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| width    | number | 是   | 图像的默认宽度。单位：像素（px）。       |
| height   | number | 是   | 图像的默认高度。单位：像素（px）。       |
| format   | number | 是   | 图像格式，如YCBCR_422_SP，JPEG。             |
| capacity | number | 是   | 同时访问的最大图像数。该参数仅作为期望值，实际capacity由设备硬件决定。 |

**返回值：**

| 类型                           | 说明                                    |
| ------------------------------ | --------------------------------------- |
| [ImageCreator](arkts-apis-image-ImageCreator.md) | 如果操作成功，则返回ImageCreator实例。 |

**示例：**

```ts
let creator: image.ImageCreator = image.createImageCreator(8192, 8192, image.ImageFormat.JPEG, 8);
```

## SVG标签说明

从API version 10开始支持SVG标签，使用版本为(SVG) 1.1，SVG标签需设置width，height。SVG文件可添加xml声明，应以“<?xml”开头，当前支持的标签列表有：

- a
- circle
- clipPath
- defs
- ellipse
- feBlend
- feColorMatrix
- feComposite
- feDiffuseLighting
- feDisplacementMap
- feDistantLight
- feFlood
- feGaussianBlur
- feImage
- feMorphology
- feOffset
- fePointLight
- feSpecularLighting
- feSpotLight
- feTurbulence
- filter
- g
- image
- line
- linearGradient
- mask
- path
- pattern
- polygon
- polyline
- radialGradient
- rect
- stop
- svg
- text
- textPath
- tspan
- use
# Interface (PixelMap)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yaozhupeng-->
<!--Designer: @yaozhupeng-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @w_Machine_cc-->

The PixelMap class is used for reading or writing image data and retrieving image information. It also supports image transformations (scaling, translation, rotation, flipping, and cropping), opacity setting, alpha channel extraction, and color space configuration. It is suitable for scenarios such as image processing, image editing, and image display that require pixel-level data operations. Before calling the methods of PixelMap, you need to create a PixelMap object via [image.createPixelMapFromPixels](arkts-apis-image-f.md#imagecreatepixelmapfrompixels) or [image.createPixelMapUsingAllocator](arkts-apis-image-f.md#imagecreatepixelmapusingallocator20) by passing pixel data. Alternatively, you can decode an image using [ImageSource](arkts-apis-image-ImageSource.md) to create a PixelMap object. The maximum serialized size of a PixelMap is currently 128 MiB. Exceeding this limit may cause rendering failures. The size of a PixelMap is calculated as: width × height × bytes per pixel (for details, see [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7)).

Since API version 11, PixelMap supports cross-thread calls through [@ohos.worker (Starting the Worker)](../apis-arkts/js-apis-worker.md). If a PixelMap object is transferred across threads through Worker or [@ohos.taskpool (Starting the Task Pool)](../apis-arkts/js-apis-taskpool.md), all APIs of the PixelMap object in the original thread cannot be called. Otherwise, error 501 or 7600106 is reported. For details, see [Image Error Codes](errorcode-image.md).

To develop an atomic service, use [ImageSource](arkts-apis-image-ImageSource.md) to create a PixelMap object.

Images occupy a large amount of memory. When you finish using a PixelMap object, call [release](#release7) to free the memory promptly. Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 7.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## Properties

**System capability**: SystemCapability.Multimedia.Image.Core

| Name             | Type   | Read Only| Optional| Description                      |
| -----------------| ------- | ---- | ---- | -------------------------- |
| isEditable<sup>7+</sup>        | boolean | Yes  | No  | Whether the image pixels are editable. **true** if editable, **false** otherwise. The value **false** provides better image rendering and transmission performance.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 12.|
| isStrideAlignment<sup>11+</sup> | boolean | Yes  | No  | Whether the row data of the image is memory-aligned. **true**: The row data is memory-aligned. Padding bytes may be added at the end of each row to meet alignment requirements (if the data already meets alignment requirements, no padding bytes are added). **false**: The row data is not memory-aligned. Each row is tightly packed with no padding bytes at the end.|

## readAllPixelsToBuffer

readAllPixelsToBuffer(dst: ArrayBuffer): Promise\<void\>

Reads all pixel data of a PixelMap and writes it into the buffer according to the pixel format of the PixelMap. This API uses a promise to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                                                                 |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | Yes  | Target buffer to which the obtained pixel data will be copied. The pixel format in the buffer is the same as that of the PixelMap and does not contain memory-alignment padding bytes. The buffer size can be obtained via [getPixelBytesNumber](#getpixelbytesnumber7).|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise that returns no value.                       |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600206 | Invalid parameter. Possible cause: Size of the buffer is too small. |
| 7600302 | Failed to copy the memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readAllPixelsToBuffer(pixelMap: image.PixelMap) {
  const readBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());

  pixelMap.readAllPixelsToBuffer(readBuffer)
    .then(() => {
      console.info('Succeeded in reading pixel data from the PixelMap to readBuffer.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to read pixel data. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## readAllPixelsToBufferSync

readAllPixelsToBufferSync(dst: ArrayBuffer): void

Reads all pixel data of a PixelMap and writes it into the buffer according to the pixel format of the PixelMap. This API returns the result synchronously.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                                                                 |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | Yes  | Target buffer to which the obtained pixel data will be copied. The pixel format in the buffer is the same as that of the PixelMap and does not contain memory-alignment padding bytes. The buffer size can be obtained via [getPixelBytesNumber](#getpixelbytesnumber7).|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600206 | Invalid parameter. Possible cause: Size of the buffer is too small. |
| 7600302 | Failed to copy the memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readAllPixelsToBufferSync(pixelMap: image.PixelMap) {
  const readBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());

  try {
    pixelMap.readAllPixelsToBufferSync(readBuffer);
    console.info('Succeeded in reading pixel data from the PixelMap to readBuffer.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to read pixel data. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer): Promise\<void>

Reads all pixel data of a PixelMap and writes it into the buffer according to the pixel format of the PixelMap. This API uses a promise to return the result.

> **NOTE**
>
> Since API version 26.0.0, you are advised to use [readAllPixelsToBuffer](#readallpixelstobuffer) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description                                                                                                 |
| ------ | ----------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst    | ArrayBuffer | Yes  | Target buffer to which the obtained pixel data will be copied. The pixel format in the buffer is the same as that of the PixelMap and does not contain memory-alignment padding bytes. The buffer size can be obtained via [getPixelBytesNumber](#getpixelbytesnumber7).|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsToBuffer(pixelMap: image.PixelMap) {
  const readBuffer: ArrayBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  pixelMap.readPixelsToBuffer(readBuffer).then(() => {
    console.info('Succeeded in reading image pixel data.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to read image pixel data. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## readPixelsToBuffer<sup>7+</sup>

readPixelsToBuffer(dst: ArrayBuffer, callback: AsyncCallback\<void>): void

Reads all pixel data of a PixelMap and writes it into the buffer according to the pixel format of the PixelMap. This API returns the result asynchronously through a callback.

> **NOTE**
>
> Since API version 26.0.0, you are advised to use [readAllPixelsToBuffer](#readallpixelstobuffer) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                                                                 |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | Yes  | Target buffer to which the obtained pixel data will be copied. The pixel format in the buffer is the same as that of the PixelMap and does not contain memory-alignment padding bytes. The buffer size can be obtained via [getPixelBytesNumber](#getpixelbytesnumber7).|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsToBuffer(pixelMap: image.PixelMap) {
  const readBuffer: ArrayBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  pixelMap.readPixelsToBuffer(readBuffer, (err: BusinessError, res: void) => {
    if (err) {
      console.error(`Failed to read image pixel data. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in reading image pixel data.');
  });
}
```

## readPixelsToBufferSync<sup>12+</sup>

readPixelsToBufferSync(dst: ArrayBuffer): void

Reads all pixel data of a PixelMap and writes it into the buffer according to the pixel format of the PixelMap. This API returns the result synchronously.

> **NOTE**
>
> Since API version 26.0.0, you are advised to use [readAllPixelsToBufferSync](#readallpixelstobuffersync) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                                                                 |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| dst      | ArrayBuffer          | Yes  | Target buffer to which the obtained pixel data will be copied. The pixel format in the buffer is the same as that of the PixelMap and does not contain memory-alignment padding bytes. The buffer size can be obtained via [getPixelBytesNumber](#getpixelbytesnumber7).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsToBufferSync(pixelMap: image.PixelMap) {
  const readBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  try {
    pixelMap.readPixelsToBufferSync(readBuffer);
    console.info('Succeeded in reading image pixel data.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to read image pixel data. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## readPixelsToArea

readPixelsToArea(area: PositionArea): Promise\<void\>

Reads pixel data from the specified area of the PixelMap and writes it into the buffer. If the pixel format of the PixelMap is YUV, the data is written to the buffer in the original YUV format; otherwise, it is written in the BGRA_8888 format. This API uses a promise to return the result.

> **NOTE**
>
> The buffer size required for the **PositionArea** can be calculated using the following formulas:
>
> - RGBA format: number of pixels in the read region (Region.size {width × height}) × 4 (1 × R component + 1 × G component + 1 × B component + 1 × A component)
> - YUV format: number of pixels in the read region (Region.size {width × height}) × 1.5 (1 × Y component + 0.25 × U component + 0.25 × V component)

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                                                                 |
| -------- | ------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| area     | [PositionArea](arkts-apis-image-i.md#positionarea7) | Yes  | Area to read.<br>The area is specified by [PositionArea](arkts-apis-image-i.md#positionarea7).region. The retrieved pixel data is copied to the [PositionArea](arkts-apis-image-i.md#positionarea7).pixels buffer. If the pixel format of the PixelMap is YUV, the retrieved pixel data remains in the same format as the PixelMap; otherwise, it is converted to the BGRA_8888 format.|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise that returns no value.                       |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600206 | Invalid parameter. Possible causes: 1. PositionArea.pixels is too small. 2. PositionArea.region is out of range. |
| 7600302 | Failed to copy the memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsToAreaRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(24), // 24 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 4.
    offset: 0,
    stride: 8, // Stride, that is, the number of bytes occupied by pixels in each row. If no padding byte is added at the end of a row, the value is width × 4.
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };

  pixelMap.readPixelsToArea(area)
    .then(() => {
      console.info('Succeeded in reading pixel data from the specified area of the PixelMap to area.pixels.');
      console.info('BGRA data: ', new Uint8Array(area.pixels));
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to read pixel data. Code: ${err.code}, message: ${err.message}`);
    });
}

function readPixelsToAreaYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(9), // 9 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 1.5.
    offset: 0,
    stride: 2, // Stride, that is, the number of bytes occupied by pixels in each row. If no padding byte is added at the end of a row, the value is width × 1 (indicating 1 times the Y component).
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };

  pixelMap.readPixelsToArea(area)
    .then(() => {
      console.info('Succeeded in reading pixel data from the specified area of the PixelMap to area.pixels.');
      console.info('YUV data: ', new Uint8Array(area.pixels));
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to read pixel data. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## readPixelsToAreaSync

readPixelsToAreaSync(area: PositionArea): void

Reads pixel data from the specified area of the PixelMap and writes it into the buffer. If the pixel format of the PixelMap is YUV, the data is written to the buffer in the original YUV format; otherwise, it is written in the BGRA_8888 format. This API returns the result synchronously.

> **NOTE**
>
> The buffer size required for the **PositionArea** can be calculated using the following formulas:
>
> - RGBA format: number of pixels in the read region (Region.size {width × height}) × 4 (1 × R component + 1 × G component + 1 × B component + 1 × A component)
> - YUV format: number of pixels in the read region (Region.size {width × height}) × 1.5 (1 × Y component + 0.25 × U component + 0.25 × V component)

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                                                                 |
| -------- | ------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| area     | [PositionArea](arkts-apis-image-i.md#positionarea7) | Yes  | Area to read.<br>The area is specified by [PositionArea](arkts-apis-image-i.md#positionarea7).region. The retrieved pixel data is copied to the [PositionArea](arkts-apis-image-i.md#positionarea7).pixels buffer. If the pixel format of the PixelMap is YUV, the retrieved pixel data remains in the same format as the PixelMap; otherwise, it is converted to the BGRA_8888 format.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600206 | Invalid parameter. Possible causes: 1. PositionArea.pixels is too small. 2. PositionArea.region is out of range. |
| 7600302 | Failed to copy the memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsToAreaSyncRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(24), // 24 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 4.
    offset: 0,
    stride: 8, // Stride, that is, the number of bytes occupied by pixels in each row. If no padding byte is added at the end of a row, the value is width × 4.
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };

  try {
    pixelMap.readPixelsToAreaSync(area);
    console.info('Succeeded in reading pixel data from the specified area of the PixelMap to area.pixels.');
    console.info('BGRA data: ', new Uint8Array(area.pixels));
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to read pixel data. Code: ${err.code}, message: ${err.message}`);
  }
}

function readPixelsToAreaSyncYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(9), // 9 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 1.5.
    offset: 0,
    stride: 2, // Stride, that is, the number of bytes occupied by pixels in each row. If no padding byte is added at the end of a row, the value is width × 1 (indicating 1 times the Y component).
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };

  try {
    pixelMap.readPixelsToAreaSync(area);
    console.info('Succeeded in reading pixel data from the specified area of the PixelMap to area.pixels.');
    console.info('YUV data: ', new Uint8Array(area.pixels));
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to read pixel data. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## readPixels<sup>7+</sup>

readPixels(area: PositionArea): Promise\<void>

Reads pixel data from the specified area of the PixelMap and writes it into the buffer. If the pixel format of the PixelMap is YUV, the data is written to the buffer in the original YUV format; otherwise, it is written in the BGRA_8888 format. This API uses a promise to return the result.

> **NOTE**
>
> The buffer size required for the **PositionArea** can be calculated using the following formulas:
>
> - RGBA format: number of pixels in the read region (Region.size {width × height}) × 4 (1 × R component + 1 × G component + 1 × B component + 1 × A component)
> - YUV format: number of pixels in the read region (Region.size {width × height}) × 1.5 (1 × Y component + 0.25 × U component + 0.25 × V component)
>
> Since API version 26.0.0, you are advised to use [readPixelsToArea](#readpixelstoarea) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                          | Mandatory| Description                    |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [PositionArea](arkts-apis-image-i.md#positionarea7) | Yes  | Area to read.<br>The area is specified by [PositionArea](arkts-apis-image-i.md#positionarea7).region. The retrieved pixel data is copied to the [PositionArea](arkts-apis-image-i.md#positionarea7).pixels buffer. If the pixel format of the PixelMap is YUV, the retrieved pixel data remains in the same format as the PixelMap; otherwise, it is converted to the BGRA_8888 format.|

**Return value**

| Type          | Description                                               |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8), // 8 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 4.
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  pixelMap.readPixels(area).then(() => {
    console.info('Succeeded in reading the image data in the area from the specified area.');
    console.info('BGRA data: ', new Uint8Array(area.pixels));
  }).catch((err: BusinessError) => {
    console.error(`Failed to read the image data from the specified area. Code: ${err.code}, message: ${err.message}`);
  });
}

function readPixelsYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(6), // 6 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 1.5.
    offset: 0,
    stride: 8,
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
  };
  pixelMap.readPixels(area).then(() => {
    console.info('Succeeded in reading the image data in the area from the specified area.');
    console.info('YUV data: ', new Uint8Array(area.pixels));
  }).catch((err: BusinessError) => {
    console.error(`Failed to read the image data from the specified area. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## readPixels<sup>7+</sup>

readPixels(area: PositionArea, callback: AsyncCallback\<void>): void

Reads pixel data from the specified area of the PixelMap and writes it into the buffer. If the pixel format of the PixelMap is YUV, the data is written to the buffer in the original YUV format; otherwise, it is written in the BGRA_8888 format. This API returns the result asynchronously through a callback.

> **NOTE**
>
> The buffer size required for the **PositionArea** can be calculated using the following formulas:
>
> - RGBA format: number of pixels in the read region (Region.size {width × height}) × 4 (1 × R component + 1 × G component + 1 × B component + 1 × A component)
> - YUV format: number of pixels in the read region (Region.size {width × height}) × 1.5 (1 × Y component + 0.25 × U component + 0.25 × V component)
>
> Since API version 26.0.0, you are advised to use [readPixelsToArea](#readpixelstoarea) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                          | Mandatory| Description                          |
| -------- | ------------------------------ | ---- | ------------------------------ |
| area     | [PositionArea](arkts-apis-image-i.md#positionarea7) | Yes  | Area to read.<br>The area is specified by [PositionArea](arkts-apis-image-i.md#positionarea7).region. The retrieved pixel data is copied to the [PositionArea](arkts-apis-image-i.md#positionarea7).pixels buffer. If the pixel format of the PixelMap is YUV, the retrieved pixel data remains in the same format as the PixelMap; otherwise, it is converted to the BGRA_8888 format.|
| callback | AsyncCallback\<void>           | Yes  |  Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8), // 8 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 4.
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  pixelMap.readPixels(area, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to read the image data from the specified area. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in reading the image data from the specified area.');
    console.info('BGRA data: ', new Uint8Array(area.pixels));
  });
}

function readPixelsYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(6), // 6 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 1.5.
    offset: 0,
    stride: 8,
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
  };
  pixelMap.readPixels(area, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to read the image data from the specified area. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in reading the image data from the specified area.');
    console.info('YUV data: ', new Uint8Array(area.pixels));
  });
}
```

## readPixelsSync<sup>12+</sup>

readPixelsSync(area: PositionArea): void

Reads pixel data from the specified area of the PixelMap and writes it into the buffer. If the pixel format of the PixelMap is YUV, the data is written to the buffer in the original YUV format; otherwise, it is written in the BGRA_8888 format. This API returns the result synchronously.

> **NOTE**
>
> The buffer size required for the **PositionArea** can be calculated using the following formulas:
>
> - RGBA format: number of pixels in the read region (Region.size {width × height}) × 4 (1 × R component + 1 × G component + 1 × B component + 1 × A component)
> - YUV format: number of pixels in the read region (Region.size {width × height}) × 1.5 (1 × Y component + 0.25 × U component + 0.25 × V component)
>
> Since API version 26.0.0, you are advised to use [readPixelsToAreaSync](#readpixelstoareasync) instead for better exception handling.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                          | Mandatory| Description                    |
| ------ | ------------------------------ | ---- | ------------------------ |
| area   | [PositionArea](arkts-apis-image-i.md#positionarea7) | Yes  | Area to read.<br>The area is specified by [PositionArea](arkts-apis-image-i.md#positionarea7).region. The retrieved pixel data is copied to the [PositionArea](arkts-apis-image-i.md#positionarea7).pixels buffer. If the pixel format of the PixelMap is YUV, the retrieved pixel data remains in the same format as the PixelMap; otherwise, it is converted to the BGRA_8888 format.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function readPixelsSync(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8),
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  try {
    pixelMap.readPixelsSync(area);
    console.info('Succeeded in reading the image data from the specified area.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to read the image data from the specified area. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## writePixelsFromArea

writePixelsFromArea(area: PositionArea): Promise\<void\>

Writes pixel data in the buffer to the specified area of a PixelMap. If the pixel format of the PixelMap is YUV, the buffer data is parsed according to the pixel format of the PixelMap; otherwise, it is parsed as the BGRA_8888 format. This API uses a promise to return the result.

> **NOTE**
>
> The buffer size required for the **PositionArea** can be calculated using the following formulas:
>
> - RGBA format: number of pixels in the write area (Region.size {width × height}) × 4 (1 × R component + 1 × G component + 1 × B component + 1 × A component)
> - YUV format: number of pixels in the write area (Region.size {width × height}) × 1.5 (1 × Y component + 0.25 × U component + 0.25 × V component)

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                                                                 |
| -------- | ------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| area     | [PositionArea](arkts-apis-image-i.md#positionarea7) | Yes  | Area to which the data is written.<br>The area is specified by [PositionArea](arkts-apis-image-i.md#positionarea7).region, and the pixel data in the [PositionArea](arkts-apis-image-i.md#positionarea7).pixels buffer is written to this area of the PixelMap. If the pixel format of the PixelMap is YUV, the pixel data in the buffer must be in the same format as the PixelMap; otherwise, it must be in the BGRA_8888 format.|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise that returns no value.                       |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is not editable or is locked. |
| 7600206 | Invalid parameter. Possible causes: 1. PositionArea.pixels is too small. 2. PositionArea.region is out of range. |
| 7600302 | Failed to copy the memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writePixelsFromAreaRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(24), // 24 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 4.
    offset: 0,
    stride: 8, // Stride, that is, the number of bytes occupied by pixels in each row. If no padding byte is added at the end of a row, the value is width × 4.
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };
  const bufferArr = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i += 4) {
    // The data source format must be BGRA_8888. The array indices are in the following order: B channel, G channel, R channel, A channel.
    bufferArr[i] = 0xFF;
    bufferArr[i + 1] = 0x00;
    bufferArr[i + 2] = 0x00;
    bufferArr[i + 3] = 0xFF;
  }

  pixelMap.writePixelsFromArea(area)
    .then(() => {
      console.info('Succeeded in writing pixel data from area.pixels to the specified area of the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to write pixel data. Code: ${err.code}, message: ${err.message}`);
    });
}

function writePixelsFromAreaYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(9), // 9 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 1.5.
    offset: 0,
    stride: 2, // This variable is not used by the writePixelsFromArea function when the PixelMap is in YUV format.
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };
  const bufferArr = new Uint8Array(area.pixels);
  const ySize = area.region.size.width * area.region.size.height;
  for (let i = 0; i < ySize; i++) { // Y plane.
    bufferArr[i] = 0xFF;
  }
  for (let i = ySize; i < bufferArr.length; i++) { // UV interleaved plane.
    bufferArr[i] = 0x80;
  }

  pixelMap.writePixelsFromArea(area)
    .then(() => {
      console.info('Succeeded in writing pixel data from area.pixels to the specified area of the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to write pixel data. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## writePixelsFromAreaSync

writePixelsFromAreaSync(area: PositionArea): void

Writes pixel data in the buffer to the specified area of a PixelMap. If the pixel format of the PixelMap is YUV, the buffer data is parsed according to the pixel format of the PixelMap; otherwise, it is parsed as the BGRA_8888 format. This API returns the result synchronously.

> **NOTE**
>
> The buffer size required for the **PositionArea** can be calculated using the following formulas:
>
> - RGBA format: number of pixels in the write area (Region.size {width × height}) × 4 (1 × R component + 1 × G component + 1 × B component + 1 × A component)
> - YUV format: number of pixels in the write area (Region.size {width × height}) × 1.5 (1 × Y component + 0.25 × U component + 0.25 × V component)

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                                                                 |
| -------- | ------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| area     | [PositionArea](arkts-apis-image-i.md#positionarea7) | Yes  | Area to which the data is written.<br>The area is specified by [PositionArea](arkts-apis-image-i.md#positionarea7).region, and the pixel data in the [PositionArea](arkts-apis-image-i.md#positionarea7).pixels buffer is written to this area of the PixelMap. If the pixel format of the PixelMap is YUV, the pixel data in the buffer must be in the same format as the PixelMap; otherwise, it must be in the BGRA_8888 format.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is not editable or is locked. |
| 7600206 | Invalid parameter. Possible causes: 1. PositionArea.pixels is too small. 2. PositionArea.region is out of range. |
| 7600302 | Failed to copy the memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writePixelsFromAreaSyncRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(24), // 24 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 4.
    offset: 0,
    stride: 8, // Stride, that is, the number of bytes occupied by pixels in each row. If no padding byte is added at the end of a row, the value is width × 4.
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };
  const bufferArr = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i += 4) {
    // The data source format must be BGRA_8888. The array indices are in the following order: B channel, G channel, R channel, A channel.
    bufferArr[i] = 0xFF;
    bufferArr[i + 1] = 0x00;
    bufferArr[i + 2] = 0x00;
    bufferArr[i + 3] = 0xFF;
  }

  try {
    pixelMap.writePixelsFromAreaSync(area);
    console.info('Succeeded in writing pixel data from area.pixels to the specified area of the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to write pixel data. Code: ${err.code}, message: ${err.message}`);
  }
}

function writePixelsFromAreaSyncYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(9), // 9 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 1.5.
    offset: 0,
    stride: 2, // This variable is not used by the writePixelsFromAreaSync function when the PixelMap is in YUV format.
    region: {
      size: { width: 2, height: 3 },
      x: 0,
      y: 0
    }
  };
  const bufferArr = new Uint8Array(area.pixels);
  const ySize = area.region.size.width * area.region.size.height;
  for (let i = 0; i < ySize; i++) { // Y plane.
    bufferArr[i] = 0xFF;
  }
  for (let i = ySize; i < bufferArr.length; i++) { // UV interleaved plane.
    bufferArr[i] = 0x80;
  }

  try {
    pixelMap.writePixelsFromAreaSync(area);
    console.info('Succeeded in writing pixel data from area.pixels to the specified area of the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to write pixel data. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## writePixels<sup>7+</sup>

writePixels(area: PositionArea): Promise\<void>

Writes pixel data in the buffer to the specified area of a PixelMap. If the pixel format of the PixelMap is YUV, the buffer data is parsed according to the pixel format of the PixelMap; otherwise, it is parsed as the BGRA_8888 format. This API uses a promise to return the result.

> **NOTE**
>
> The buffer size required for the **PositionArea** can be calculated using the following formulas:
>
> - RGBA format: number of pixels in the write area (Region.size {width × height}) × 4 (1 × R component + 1 × G component + 1 × B component + 1 × A component)
> - YUV format: number of pixels in the write area (Region.size {width × height}) × 1.5 (1 × Y component + 0.25 × U component + 0.25 × V component)
>
> Since API version 26.0.0, you are advised to use [writePixelsFromArea](#writepixelsfromarea) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                          | Mandatory| Description                |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [PositionArea](arkts-apis-image-i.md#positionarea7) | Yes  | Area to which the data is written.<br>The area is specified by [PositionArea](arkts-apis-image-i.md#positionarea7).region, and the pixel data in the [PositionArea](arkts-apis-image-i.md#positionarea7).pixels buffer is written to this area of the PixelMap. If the pixel format of the PixelMap is YUV, the pixel data in the buffer must be in the same format as the PixelMap; otherwise, it must be in the BGRA_8888 format.|

**Return value**

| Type          | Description                                               |
| :------------- | :-------------------------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writePixelsRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8), // 8 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 4.
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  let bufferArr: Uint8Array = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  pixelMap.writePixels(area).then(() => {
    console.info('Succeeded in writing pixels into the specified area.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to write pixels into the specified area. Code: ${err.code}, message: ${err.message}`);
  });
}

function writePixelsYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(6), // 6 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 1.5.
    offset: 0,
    stride: 8, // This variable is not used by the writePixels function when the PixelMap is in YUV format.
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
  };
  let bufferArr: Uint8Array = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  pixelMap.writePixels(area).then(() => {
    console.info('Succeeded in writing pixels into the specified area.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to write pixels into the specified area. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## writePixels<sup>7+</sup>

writePixels(area: PositionArea, callback: AsyncCallback\<void>): void

Writes pixel data in the buffer to the specified area of a PixelMap. If the pixel format of the PixelMap is YUV, the buffer data is parsed according to the pixel format of the PixelMap; otherwise, it is parsed as the BGRA_8888 format. This API returns the result asynchronously through a callback.

> **NOTE**
>
> The buffer size required for the **PositionArea** can be calculated using the following formulas:
>
> - RGBA format: number of pixels in the write area (Region.size {width × height}) × 4 (1 × R component + 1 × G component + 1 × B component + 1 × A component)
> - YUV format: number of pixels in the write area (Region.size {width × height}) × 1.5 (1 × Y component + 0.25 × U component + 0.25 × V component)
>
> Since API version 26.0.0, you are advised to use [writePixelsFromArea](#writepixelsfromarea) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name   | Type                          | Mandatory| Description                          |
| --------- | ------------------------------ | ---- | ------------------------------ |
| area      | [PositionArea](arkts-apis-image-i.md#positionarea7) | Yes  | Area to which the data is written.<br>The area is specified by [PositionArea](arkts-apis-image-i.md#positionarea7).region, and the pixel data in the [PositionArea](arkts-apis-image-i.md#positionarea7).pixels buffer is written to this area of the PixelMap. If the pixel format of the PixelMap is YUV, the pixel data in the buffer must be in the same format as the PixelMap; otherwise, it must be in the BGRA_8888 format.|
| callback  | AsyncCallback\<void>           | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writePixelsRGBA(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8), // 8 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 4.
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  let bufferArr: Uint8Array = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  pixelMap.writePixels(area, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to write pixels into the specified area. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in writing pixels into the specified area.');
  });
}

function writePixelsYUV(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(6), // 6 indicates the size of the pixel buffer to create. The value is calculated as follows: width × height × 1.5.
    offset: 0,
    stride: 8, // This variable is not used by the writePixels function when the PixelMap is in YUV format.
    region: { size: { height: 2, width: 2 }, x: 0, y: 0 }
  };
  let bufferArr: Uint8Array = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  pixelMap.writePixels(area, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to write pixels into the specified area. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in writing pixels into the specified area.');
  });
}
```

## writePixelsSync<sup>12+</sup>

writePixelsSync(area: PositionArea): void

Writes pixel data in the buffer to the specified area of a PixelMap. If the pixel format of the PixelMap is YUV, the buffer data is parsed according to the pixel format of the PixelMap; otherwise, it is parsed as the BGRA_8888 format. This API returns the result synchronously.

> **NOTE**
>
> The buffer size required for the **PositionArea** can be calculated using the following formulas:
>
> - RGBA format: number of pixels in the write area (Region.size {width × height}) × 4 (1 × R component + 1 × G component + 1 × B component + 1 × A component)
> - YUV format: number of pixels in the write area (Region.size {width × height}) × 1.5 (1 × Y component + 0.25 × U component + 0.25 × V component)
>
> Since API version 26.0.0, you are advised to use [writePixelsFromAreaSync](#writepixelsfromareasync) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type                          | Mandatory| Description                |
| ------ | ------------------------------ | ---- | -------------------- |
| area   | [PositionArea](arkts-apis-image-i.md#positionarea7) | Yes  | Area to which the data is written.<br>The area is specified by [PositionArea](arkts-apis-image-i.md#positionarea7).region, and the pixel data in the [PositionArea](arkts-apis-image-i.md#positionarea7).pixels buffer is written to this area of the PixelMap. If the pixel format of the PixelMap is YUV, the pixel data in the buffer must be in the same format as the PixelMap; otherwise, it must be in the BGRA_8888 format.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writePixelsSync(pixelMap: image.PixelMap) {
  const area: image.PositionArea = {
    pixels: new ArrayBuffer(8),
    offset: 0,
    stride: 8,
    region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
  };
  let bufferArr: Uint8Array = new Uint8Array(area.pixels);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  try {
    pixelMap.writePixelsSync(area);
    console.info('Succeeded in writing pixels into the specified area.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to write pixels into the specified area. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## writeAllPixelsFromBuffer

writeAllPixelsFromBuffer(src: ArrayBuffer): Promise\<void\>

Writes pixel data from the buffer to the entire PixelMap. This API uses a promise to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| src      | ArrayBuffer          | Yes  | Source data buffer. The image pixel data in this buffer is written to the PixelMap. The pixel data in the buffer must cover the entire PixelMap and must be in the same pixel format as the PixelMap, without memory-alignment padding bytes. The buffer size can be obtained via [getPixelBytesNumber](#getpixelbytesnumber7).|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise that returns no value.                       |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is not editable or is locked. |
| 7600206 | Invalid parameter. Possible cause: Size of the buffer is too small. |
| 7600302 | Failed to copy the memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writeAllPixelsFromBuffer(pixelMap: image.PixelMap) {
  const writeBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  const bufferArr = new Uint8Array(writeBuffer);
  for (let i = 0; i < bufferArr.length; i += 4) {
    // Assuming the pixel format of pixelMap is RGBA_8888, the array indices are in the following order: R channel, G channel, B channel, A channel.
    bufferArr[i] = 0xFF;
    bufferArr[i + 1] = 0x00;
    bufferArr[i + 2] = 0x00;
    bufferArr[i + 3] = 0xFF;
  }

  pixelMap.writeAllPixelsFromBuffer(writeBuffer)
    .then(() => {
      console.info('Succeeded in writing pixel data from writeBuffer to the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to write pixel data. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## writeAllPixelsFromBufferSync

writeAllPixelsFromBufferSync(src: ArrayBuffer): void

Writes pixel data from the buffer to the entire PixelMap. This API returns the result synchronously.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                |
| -------- | -------------------- | ---- | ----------------------------------------------------------------------------------------------------- |
| src      | ArrayBuffer          | Yes  | Source data buffer. The image pixel data in this buffer is written to the PixelMap. The pixel data in the buffer must cover the entire PixelMap and must be in the same pixel format as the PixelMap, without memory-alignment padding bytes. The buffer size can be obtained via [getPixelBytesNumber](#getpixelbytesnumber7).|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is not editable or is locked. |
| 7600206 | Invalid parameter. Possible cause: Size of the buffer is too small. |
| 7600302 | Failed to copy the memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writeAllPixelsFromBufferSync(pixelMap: image.PixelMap) {
  const writeBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  const bufferArr = new Uint8Array(writeBuffer);
  for (let i = 0; i < bufferArr.length; i += 4) {
    // Assuming the pixel format of pixelMap is RGBA_8888, the array indices are in the following order: R channel, G channel, B channel, A channel.
    bufferArr[i] = 0xFF;
    bufferArr[i + 1] = 0x00;
    bufferArr[i + 2] = 0x00;
    bufferArr[i + 3] = 0xFF;
  }

  try {
    pixelMap.writeAllPixelsFromBufferSync(writeBuffer);
    console.info('Succeeded in writing pixel data from writeBuffer to the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to write pixel data. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## writeBufferToPixels<sup>7+</sup>

writeBufferToPixels(src: ArrayBuffer): Promise\<void>

Writes pixel data from the buffer to the entire PixelMap. This API uses a promise to return the result.

> **NOTE**
>
> Since API version 26.0.0, you are advised to use [writeAllPixelsFromBuffer](#writeallpixelsfrombuffer) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description          |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | Yes  | Source data buffer. The image pixel data in this buffer is written to the PixelMap. The pixel data in the buffer must cover the entire PixelMap and must be in the same pixel format as the PixelMap, without memory-alignment padding bytes. The buffer size can be obtained via [getPixelBytesNumber](#getpixelbytesnumber7).|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writeBufferToPixels(pixelMap: image.PixelMap) {
  const color: ArrayBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  pixelMap.writeBufferToPixels(color).then(() => {
    console.info('Succeeded in writing data from the buffer to the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to write data from the buffer to the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## writeBufferToPixels<sup>7+</sup>

writeBufferToPixels(src: ArrayBuffer, callback: AsyncCallback\<void>): void

Writes pixel data from the buffer to the entire PixelMap. This API returns the result asynchronously through a callback.

> **NOTE**
>
> Since API version 26.0.0, you are advised to use [writeAllPixelsFromBuffer](#writeallpixelsfrombuffer) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| src      | ArrayBuffer          | Yes  | Source data buffer. The image pixel data in this buffer is written to the PixelMap. The pixel data in the buffer must cover the entire PixelMap and must be in the same pixel format as the PixelMap, without memory-alignment padding bytes. The buffer size can be obtained via [getPixelBytesNumber](#getpixelbytesnumber7).|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the pixels in the buffer are successfully written to the PixelMap, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writeBufferToPixels(pixelMap: image.PixelMap) {
  const color: ArrayBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  pixelMap.writeBufferToPixels(color, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to write data from the buffer to the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in writing data from the buffer to the PixelMap.');
  });
}
```

## writeBufferToPixelsSync<sup>12+</sup>

writeBufferToPixelsSync(src: ArrayBuffer): void

Writes pixel data from the buffer to the entire PixelMap. This API returns the result synchronously.

> **NOTE**
>
> Since API version 26.0.0, you are advised to use [writeAllPixelsFromBufferSync](#writeallpixelsfrombuffersync) instead for better exception handling.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type       | Mandatory| Description          |
| ------ | ----------- | ---- | -------------- |
| src    | ArrayBuffer | Yes  | Source data buffer. The image pixel data in this buffer is written to the PixelMap. The pixel data in the buffer must cover the entire PixelMap and must be in the same pixel format as the PixelMap, without memory-alignment padding bytes. The buffer size can be obtained via [getPixelBytesNumber](#getpixelbytesnumber7).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function writeBufferToPixelsSync(pixelMap: image.PixelMap) {
  const color: ArrayBuffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
  let bufferArr: Uint8Array = new Uint8Array(color);
  for (let i = 0; i < bufferArr.length; i++) {
    bufferArr[i] = i + 1;
  }
  try {
    pixelMap.writeBufferToPixelsSync(color);
    console.info('Succeeded in writing data from the buffer to the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to write data from the buffer to the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## getImageInfo<sup>7+</sup>

getImageInfo(): Promise\<ImageInfo>

Obtains the image information of a PixelMap. This API uses a promise to return the result.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                             | Description                                                       |
| --------------------------------- | ----------------------------------------------------------- |
| Promise\<[ImageInfo](arkts-apis-image-i.md#imageinfo)> | Promise used to return the image information.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getImageInfo(pixelMap: image.PixelMap) {
  pixelMap.getImageInfo().then((imageInfo: image.ImageInfo) => {
    console.info(`Succeeded in obtaining information of the PixelMap with size ${imageInfo.size} and pixel format ${imageInfo.pixelFormat}.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to obtain information of the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## getImageInfo<sup>7+</sup>

getImageInfo(callback: AsyncCallback\<ImageInfo>): void

Obtains the image information of a PixelMap. This API returns the result asynchronously through a callback.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[ImageInfo](arkts-apis-image-i.md#imageinfo)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the image information obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getImageInfo(pixelMap: image.PixelMap) {
  pixelMap.getImageInfo((err: BusinessError, imageInfo: image.ImageInfo) => {
    if (err) {
      console.error(`Failed to obtain information of the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in obtaining information of the PixelMap with size ${imageInfo.size} and pixel format ${imageInfo.pixelFormat}.`);
  });
}
```

## getImageInfoSync<sup>12+</sup>

getImageInfoSync(): ImageInfo

Obtains the image information of a PixelMap. This API returns the result synchronously.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.ImageSource

**Return value**

| Type                             | Description                                                       |
| --------------------------------- | ----------------------------------------------------------- |
| [ImageInfo](arkts-apis-image-i.md#imageinfo)           | Image information.                         |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getImageInfoSync(pixelMap: image.PixelMap) {
  try {
    let imageInfo: image.ImageInfo = pixelMap.getImageInfoSync();
    console.info(`Succeeded in obtaining information of the PixelMap with size ${imageInfo.size} and pixel format ${imageInfo.pixelFormat}.`);
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to obtain information of the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## getBytesNumberPerRow<sup>7+</sup>

getBytesNumberPerRow(): number

Obtains the number of bytes per row of pixels in an image.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| number | Number of bytes per row. The unit is bytes.|

**Example**

```ts
function getBytesNumberPerRow(pixelMap: image.PixelMap) {
  let rowBytes: number = pixelMap.getBytesNumberPerRow();
}
```

## getPixelBytesNumber<sup>7+</sup>

getPixelBytesNumber(): number

Obtains the total number of bytes occupied by all pixels in an image, excluding memory-alignment padding bytes.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| number | Total number of bytes. The unit is bytes.|

**Example**

```ts
function getPixelBytesNumber(pixelMap: image.PixelMap) {
  let pixelBytesNumber: number = pixelMap.getPixelBytesNumber();
}
```

## getDensity<sup>9+</sup>

getDensity(): number

Obtains the pixel density of an image.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type  | Description           |
| ------ | --------------- |
| number | Pixel density of the image, in ppi (pixels per inch).|

**Example**

```ts
function getDensity(pixelMap: image.PixelMap) {
  let density: number = pixelMap.getDensity();
}
```

## setOpacity

setOpacity(value: number): Promise\<void\>

Sets the opacity of an PixelMap. The specified opacity value is applied to all pixels and overrides the original opacity of the image. Setting opacity is not supported for images in YUV format. This API uses a promise to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------- |
| value    | number               | Yes  | Opacity value. The value range is (0.0, 1.0], where **1.0** indicates that the image is completely opaque. A value closer to **0.0** indicates higher transparency.                          |

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise that returns no value.                       |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. Possible cause: The specified value is out of range. |
| 7600207 | Unsupported data format. Possible cause: Alpha type is not supported. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setOpacity(pixelMap: image.PixelMap) {
  const opacity: number = 0.5;
  pixelMap.setOpacity(opacity)
    .then(() => {
      console.info('Succeeded in setting opacity.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to set opacity. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## setOpacitySync

setOpacitySync(value: number): void

Sets the opacity of an PixelMap. The specified opacity value is applied to all pixels and overrides the original opacity of the image. Setting opacity is not supported for images in YUV format. This API returns the result synchronously.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------- |
| value    | number               | Yes  | Opacity value. The value range is (0.0, 1.0], where **1.0** indicates that the image is completely opaque. A value closer to **0.0** indicates higher transparency.                          |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. Possible cause: The specified value is out of range. |
| 7600207 | Unsupported data format. Possible cause: Alpha type is not supported. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setOpacitySync(pixelMap: image.PixelMap) {
  const opacity: number = 0.5;
  try {
    pixelMap.setOpacitySync(opacity);
    console.info('Succeeded in setting opacity.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to set opacity. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## opacity<sup>9+</sup>

opacity(rate: number, callback: AsyncCallback\<void>): void

Sets the opacity of an PixelMap. The specified opacity value is applied to all pixels and overrides the original opacity of the image. Setting opacity is not supported for images in YUV format. This API returns the result asynchronously through a callback.

> **NOTE**
>
> Since API version 26.0.0, you are advised to use [setOpacity](#setopacity) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| rate     | number               | Yes  | Opacity value. The value range is (0, 1]. The value **1.0** indicates completely opaque. A value closer to **0.0** indicates higher transparency. |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function opacity(pixelMap: image.PixelMap) {
  const rate: number = 0.5;
  pixelMap.opacity(rate, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to set opacity. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in setting opacity.");
  });
}
```

## opacity<sup>9+</sup>

opacity(rate: number): Promise\<void>

Sets the opacity of an PixelMap. The specified opacity value is applied to all pixels and overrides the original opacity of the image. Setting opacity is not supported for images in YUV format. This API uses a promise to return the result.

> **NOTE**
>
> Since API version 26.0.0, you are advised to use [setOpacity](#setopacity) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                       |
| ------ | ------ | ---- | --------------------------- |
| rate   | number | Yes  | Opacity value. The value range is (0, 1]. The value **1.0** indicates completely opaque. A value closer to **0.0** indicates higher transparency.|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function opacity(pixelMap: image.PixelMap) {
  const rate: number = 0.5;
  pixelMap.opacity(rate).then(() => {
    console.info('Succeeded in setting opacity.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set opacity. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## opacitySync<sup>12+</sup>

opacitySync(rate: number): void

Sets the opacity of an PixelMap. The specified opacity value is applied to all pixels and overrides the original opacity of the image. Setting opacity is not supported for images in YUV format. This API returns the result synchronously.

> **NOTE**
>
> Since API version 26.0.0, you are advised to use [setOpacitySync](#setopacitysync) instead for better exception handling.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| rate     | number               | Yes  | Opacity value. The value range is (0, 1]. The value **1.0** indicates completely opaque. A value closer to **0.0** indicates higher transparency.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function opacitySync(pixelMap: image.PixelMap) {
  const rate: number = 0.5;
  try {
    pixelMap.opacitySync(rate);
    console.info('Succeeded in setting opacity.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to set opacity. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## extractAlphaPixelMap

extractAlphaPixelMap(): Promise\<PixelMap\>

Extracts the Alpha channel data from the current PixelMap and generates a new PixelMap in the ALPHA_U8 format that contains only Alpha channel information. The newly generated PixelMap is non-editable and can be used for shadow effects. The YUV format is not supported by this API. This API uses a promise to return the result.

> **NOTE**
>
> If the original PixelMap format is ALPHA_F16, the newly generated PixelMap will retain the ALPHA_F16 format.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                                            |
| -------------- | ------------------------------------------------ |
| Promise\<PixelMap\> | Promise used to return the PixelMap in the ALPHA_U8 format that contains only Alpha channel information.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The current PixelMap has been released. |
| 7600106 | The current PixelMap has been passed across threads. |
| 7600305 | Failed to create the PixelMap. Possible cause: Current PixelMap data is corrupted. |
| 7600306 | Failed to convert the data. Possible causes: 1. Failed to perform pixel format conversion. 2. The system is out of memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function extractAlphaPixelMap(pixelMap: image.PixelMap) {
  pixelMap.extractAlphaPixelMap()
    .then((alphaMap: image.PixelMap) => {
      console.info('Succeeded in creating alpha PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to create alpha PixelMap. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## extractAlphaPixelMapSync

extractAlphaPixelMapSync(): PixelMap

Extracts the Alpha channel data from the current PixelMap and generates a new PixelMap in the ALPHA_U8 format that contains only Alpha channel information. The newly generated PixelMap is non-editable and can be used for shadow effects. The YUV format is not supported by this API. This API returns the result synchronously.

> **NOTE**
>
> If the original PixelMap format is ALPHA_F16, the newly generated PixelMap will retain the ALPHA_F16 format.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                                            |
| -------------- | ----------------------------------------------- |
| PixelMap       | PixelMap in the ALPHA_U8 format that contains only Alpha channel information. |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The current PixelMap has been released. |
| 7600106 | The current PixelMap has been passed across threads. |
| 7600305 | Failed to create the PixelMap. Possible cause: Current PixelMap data is corrupted. |
| 7600306 | Failed to convert the data. Possible causes: 1. Failed to perform pixel format conversion. 2. The system is out of memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function extractAlphaPixelMapSync(pixelMap: image.PixelMap) {
  try {
    const alphaMap = pixelMap.extractAlphaPixelMapSync();
    console.info('Succeeded in creating alpha PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create alpha PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## createAlphaPixelmap<sup>9+</sup>

createAlphaPixelmap(): Promise\<PixelMap>

Generates a PixelMap in the ALPHA_8 format that contains only Alpha channel data based on the Alpha channel information. The newly generated PixelMap is non-editable and can be used for shadow effects. The YUV format is not supported by this API. This API uses a promise to return the result.

> **NOTE**
>
> - If the original PixelMap format is ALPHA_F16, the newly generated PixelMap will retain the ALPHA_F16 format.
> - Since API version 26.0.0, you are advised to use [extractAlphaPixelMap](#extractalphapixelmap) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                            | Description                       |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise used to return the PixelMap in the ALPHA_8 format that contains only Alpha channel information.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createAlphaPixelmap(pixelMap: image.PixelMap) {
  pixelMap.createAlphaPixelmap().then((alphaPixelMap: image.PixelMap) => {
    console.info('Succeeded in creating alpha PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to create alpha PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## createAlphaPixelmap<sup>9+</sup>

createAlphaPixelmap(callback: AsyncCallback\<PixelMap>): void

Generates a PixelMap in the ALPHA_8 format that contains only Alpha channel data based on the Alpha channel information. The newly generated PixelMap is non-editable and can be used for shadow effects. The YUV format is not supported by this API. This API returns the result asynchronously through a callback.

> **NOTE**
>
> - If the original PixelMap format is ALPHA_F16, the newly generated PixelMap will retain the ALPHA_F16 format.
> - Since API version 26.0.0, you are advised to use [extractAlphaPixelMap](#extractalphapixelmap) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                    |
| -------- | ------------------------ | ---- | ------------------------ |
| callback | AsyncCallback\<[PixelMap](arkts-apis-image-PixelMap.md)> | Yes  |  Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the PixelMap object obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createAlphaPixelmap(pixelMap: image.PixelMap) {
  pixelMap.createAlphaPixelmap((err: BusinessError, alphaPixelMap: image.PixelMap) => {
    if (err) {
      console.error(`Failed to create alpha PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in creating alpha PixelMap.');
  });
}
```

## createAlphaPixelmapSync<sup>12+</sup>

createAlphaPixelmapSync(): PixelMap

Generates a PixelMap in the ALPHA_8 format that contains only Alpha channel data based on the Alpha channel information. The newly generated PixelMap is non-editable and can be used for shadow effects. The YUV format is not supported by this API. This API returns the result synchronously.

> **NOTE**
>
> - If the original PixelMap format is ALPHA_F16, the newly generated PixelMap will retain the ALPHA_F16 format.
> - Since API version 26.0.0, you are advised to use [extractAlphaPixelMapSync](#extractalphapixelmapsync) instead for better exception handling.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | If the operation is successful, the PixelMap object in the ALPHA_8 format that contains only Alpha channel information is returned. Otherwise, an exception is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createAlphaPixelmapSync(pixelMap: image.PixelMap) {
  try {
    let pixelmap: image.PixelMap = pixelMap.createAlphaPixelmapSync();
    console.info('Succeeded in creating alpha PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create alpha PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## applyScale

applyScale(x: number, y: number, level?: AntiAliasingLevel): Promise\<void\>

Scales a PixelMap by the specified scaling factors for width and height, using the specified anti-aliasing level. This API uses a promise to return the result.

> **NOTE**
>
> - It is advised to use positive scaling factors for width and height; otherwise, a flipped image may result.
> - The scaling factor is calculated as: scaled image size/original image size.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                          |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------- |
| x        | number               | Yes  | Scale factor of the width. The value cannot be **0**.                               |
| y        | number               | Yes  | Scale factor of the height. The value cannot be **0**.                               |
| level    | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | No  | Anti-aliasing level. This parameter does not take effect for PixelMaps in ASTC format. The default value is **AntiAliasingLevel.NONE**.|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise that returns no value.                       |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible causes: 1. The resulting PixelMap size is too large. 2. The system is out of memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyScale(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.5;
  pixelMap.applyScale(scaleX, scaleY, image.AntiAliasingLevel.LOW)
    .then(() => {
      console.info('Succeeded in scaling the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to scale the PixelMap. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## applyScaleSync

applyScaleSync(x: number, y: number, level?: AntiAliasingLevel): void

Scales a PixelMap by the specified scaling factors for width and height, using the specified anti-aliasing level. This API returns the result synchronously.

> **NOTE**
>
> - It is advised to use positive scaling factors for width and height; otherwise, a flipped image may result.
> - The scaling factor is calculated as: scaled image size/original image size.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                          |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------- |
| x        | number               | Yes  | Scale factor of the width. The value cannot be **0**.                               |
| y        | number               | Yes  | Scale factor of the height. The value cannot be **0**.                               |
| level    | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | No  | Anti-aliasing level. This parameter does not take effect for PixelMaps in ASTC format. The default value is **AntiAliasingLevel.NONE**.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible causes: 1. The resulting PixelMap size is too large. 2. The system is out of memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyScaleSync(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.5;
  try {
    pixelMap.applyScaleSync(scaleX, scaleY, image.AntiAliasingLevel.LOW);
    console.info('Succeeded in scaling the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to scale the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## scale<sup>9+</sup>

scale(x: number, y: number, callback: AsyncCallback\<void>): void

Scales this image based on the scale factors of the width and height. This API returns the result asynchronously through a callback.

> **NOTE**
>
> - It is advised to use positive scaling factors for width and height; otherwise, a flipped image may result.
> - Scale factors of the width and height = Width and height of the resized image/Width and height of the original image
> - Since API version 26.0.0, you are advised to use [applyScale](#applyscale) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                           |
| -------- | -------------------- | ---- | ------------------------------- |
| x        | number               | Yes  | Scale factor of the width. The value cannot be **0**.|
| y        | number               | Yes  | Scale factor of the height. The value cannot be **0**.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function scale(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.0;
  pixelMap.scale(scaleX, scaleY, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to scale the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in scaling the PixelMap.");
  });
}
```

## scale<sup>9+</sup>

scale(x: number, y: number): Promise\<void>

Scales this image based on the scale factors of the width and height. This API uses a promise to return the result.

> **NOTE**
>
> - It is advised to use positive scaling factors for width and height; otherwise, a flipped image may result.
> - Scale factors of the width and height = Width and height of the resized image/Width and height of the original image
> - Since API version 26.0.0, you are advised to use [applyScale](#applyscale) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scale factor of the width. The value cannot be **0**.|
| y      | number | Yes  | Scale factor of the height. The value cannot be **0**.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function scale(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.0;
  pixelMap.scale(scaleX, scaleY).then(() => {
    console.info('Succeeded in scaling the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to scale the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## scaleSync<sup>12+</sup>

scaleSync(x: number, y: number): void

Scales this image based on the scale factors of the width and height. This API returns the result synchronously.

> **NOTE**
>
> - It is advised to use positive scaling factors for width and height; otherwise, a flipped image may result.
> - Scale factors of the width and height = Width and height of the resized image/Width and height of the original image
> - Since API version 26.0.0, you are advised to use [applyScaleSync](#applyscalesync) instead for better exception handling.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scale factor of the width. The value cannot be **0**.|
| y      | number | Yes  | Scale factor of the height. The value cannot be **0**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function scaleSync(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.0;
  try {
    pixelMap.scaleSync(scaleX, scaleY);
    console.info('Succeeded in scaling the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to scale the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## scale<sup>12+</sup>

scale(x: number, y: number, level: AntiAliasingLevel): Promise\<void>

Scales this image based on the specified anti-aliasing level and the scale factors for the width and height. This API uses a promise to return the result.

> **NOTE**
>
> - It is advised to use positive scaling factors for width and height; otherwise, a flipped image may result.
> - Scale factors of the width and height = Width and height of the resized image/Width and height of the original image
> - Since API version 26.0.0, you are advised to use [applyScale](#applyscale) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scale factor of the width. The value cannot be **0**.|
| y      | number | Yes  | Scale factor of the height. The value cannot be **0**.|
| level  | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | Yes  | Anti-aliasing level. This parameter does not take effect for PixelMaps in ASTC format.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function scaleSync(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.0;
  pixelMap.scale(scaleX, scaleY, image.AntiAliasingLevel.LOW).then(() => {
    console.info('Succeeded in scaling the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to scale the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## scaleSync<sup>12+</sup>

scaleSync(x: number, y: number, level: AntiAliasingLevel): void

Scales this image based on the specified anti-aliasing level and the scale factors for the width and height. This API returns the result synchronously.

> **NOTE**
>
> - It is advised to use positive scaling factors for width and height; otherwise, a flipped image may result.
> - Scale factors of the width and height = Width and height of the resized image/Width and height of the original image
> - Since API version 26.0.0, you are advised to use [applyScaleSync](#applyscalesync) instead for better exception handling.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scale factor of the width. The value cannot be **0**.|
| y      | number | Yes  | Scale factor of the height. The value cannot be **0**.|
| level  | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | Yes  | Anti-aliasing level. This parameter does not take effect for PixelMaps in ASTC format.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function scaleSync(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.0;
  try {
    pixelMap.scaleSync(scaleX, scaleY, image.AntiAliasingLevel.LOW);
    console.info('Succeeded in scaling the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to scale the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## createScaledPixelMap<sup>18+</sup>

createScaledPixelMap(x: number, y: number, level?: AntiAliasingLevel): Promise\<PixelMap>

Creates a new scaled PixelMap based on the current PixelMap, using the specified scaling factors and anti-aliasing level. The newly generated PixelMap is non-editable. This API uses a promise to return the result.

> **NOTE**
>
> This API does not copy the HDR metadata or EXIF information from the original image.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scale factor of the width. The value cannot be **0**.|
| y      | number | Yes  | Scale factor of the height. The value cannot be **0**.|
| level  | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | No  | Anti-aliasing level. The default value is **AntiAliasingLevel.NONE**. This parameter does not take effect for PixelMaps in ASTC format.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise used to return the scaled PixelMap.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createScaledPixelMap(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.0;
  pixelMap.createScaledPixelMap(scaleX, scaleY, image.AntiAliasingLevel.LOW).then((scaledPixelMap: image.PixelMap) => {
    console.info('Succeeded in creating scaled PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to create scaled PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## createScaledPixelMapSync<sup>18+</sup>

createScaledPixelMapSync(x: number, y: number, level?: AntiAliasingLevel): PixelMap

Creates a new scaled PixelMap based on the current PixelMap, using the specified scaling factors and anti-aliasing level. The newly generated PixelMap is non-editable. This API returns the result synchronously.

> **NOTE**
>
> This API does not copy the HDR metadata or EXIF information from the original image.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| x      | number | Yes  | Scale factor of the width. The value cannot be **0**.|
| y      | number | Yes  | Scale factor of the height. The value cannot be **0**.|
| level  | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | No  | Anti-aliasing level. The default value is **AntiAliasingLevel.NONE**. This parameter does not take effect for PixelMaps in ASTC format.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | If the operation is successful, the scaled PixelMap is returned synchronously. Otherwise, an exception is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createScaledPixelMapSync(pixelMap: image.PixelMap) {
  const scaleX: number = 2.0;
  const scaleY: number = 1.0;
  try {
    let scaledPixelMap = pixelMap.createScaledPixelMapSync(scaleX, scaleY, image.AntiAliasingLevel.LOW);
    console.info('Succeeded in creating scaled PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create scaled PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## createCroppedAndScaledPixelMap<sup>22+</sup>

createCroppedAndScaledPixelMap(region: Region, x: number, y: number, level?: AntiAliasingLevel): Promise\<PixelMap\>

Creates a new PixelMap that is cropped and scaled based on the current PixelMap, using the specified crop region, scaling factors for width and height, and anti-aliasing level. This API uses a promise to return the result.

> **NOTE**
>
> This API does not copy the EXIF information from the original image.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | ------------------- | ---- | ----------------------------- |
| region   | [Region](arkts-apis-image-i.md#region8) | Yes  | Area to crop. The value must not exceed the width and height of the image. The unit is px.|
| x        | number | Yes  | Scale factor of the width. The value cannot be **0**.|
| y        | number | Yes  | Scale factor of the height. The value cannot be **0**.|
| level    | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | No  | Anti-aliasing level. The default value is **AntiAliasingLevel.NONE**. This parameter does not take effect for PixelMaps in ASTC format.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)\> | Promise used to return the cropped and scaled PixelMap.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 7600201 | The PixelMap has been released. |
| 7600204 | Invalid region. |
| 7600205 | Unsupported memory format or pixel format. |
| 7600301 | Memory alloc failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createCroppedAndScaledPixelMap(pixelMap: image.PixelMap) {
  const imageInfo = pixelMap.getImageInfoSync();
  const region: image.Region = {
    size: { width: imageInfo.size.width / 2, height: imageInfo.size.height / 2 },
    x: imageInfo.size.width / 4,
    y: imageInfo.size.height / 4
  };
  const scaleX: number = 2.0;
  const scaleY: number = 2.0;
  pixelMap.createCroppedAndScaledPixelMap(region, scaleX, scaleY, image.AntiAliasingLevel.HIGH)
    .then((croppedAndScaled: image.PixelMap) => {
      console.info('Succeeded in creating cropped and scaled PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to create cropped and scaled PixelMap. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## createCroppedAndScaledPixelMapSync<sup>22+</sup>

createCroppedAndScaledPixelMapSync(region: Region, x: number, y: number, level?: AntiAliasingLevel): PixelMap

Creates a new PixelMap that is cropped and scaled based on the current PixelMap, using the specified crop region, scaling factors for width and height, and anti-aliasing level. This API returns the result synchronously.

> **NOTE**
>
> This API does not copy the EXIF information from the original image.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | ------------------- | ---- | ----------------------------- |
| region   | [Region](arkts-apis-image-i.md#region8) | Yes  | Area to crop. The value must not exceed the width and height of the image. The unit is px.|
| x        | number | Yes  | Scale factor of the width. The value cannot be **0**.|
| y        | number | Yes  | Scale factor of the height. The value cannot be **0**.|
| level    | [AntiAliasingLevel](arkts-apis-image-e.md#antialiasinglevel12) | No  | Anti-aliasing level. The default value is **AntiAliasingLevel.NONE**. This parameter does not take effect for PixelMaps in ASTC format.|

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | If the operation is successful, the cropped and scaled PixelMap is returned synchronously. Otherwise, an exception is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 7600201 | The PixelMap has been released. |
| 7600204 | Invalid region. |
| 7600205 | Unsupported memory format or pixel format. |
| 7600301 | Memory alloc failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createCroppedAndScaledPixelMapSync(pixelMap: image.PixelMap) {
  const imageInfo = pixelMap.getImageInfoSync();
  const region: image.Region = {
    size: { width: imageInfo.size.width / 2, height: imageInfo.size.height / 2 },
    x: imageInfo.size.width / 4,
    y: imageInfo.size.height / 4
  };
  const scaleX: number = 2.0;
  const scaleY: number = 2.0;
  try {
    const croppedAndScaled = pixelMap.createCroppedAndScaledPixelMapSync(region, scaleX, scaleY, image.AntiAliasingLevel.HIGH);
    console.info('Succeeded in creating cropped and scaled PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to create cropped and scaled PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## clone<sup>18+</sup>

clone(): Promise\<PixelMap>

Copies the current PixelMap object. This API uses a promise to return the result.

> **NOTE**
>
> This API does not copy the EXIF information from the original image.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise used to return the copied PixelMap object.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 501 | Resource unavailable. |
| 62980102 | Image malloc abnormal. This status code is thrown when an error occurs during the process of copying data. |
| 62980103 | Image YUV And ASTC types are not supported. |
| 62980104 | Image initialization abnormal. This status code is thrown when an error occurs during the process of creating empty pixelmap. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function clone(pixelMap: image.PixelMap) {
  pixelMap.clone().then((clonedPixelMap: image.PixelMap) => {
    console.info('Succeeded in cloning the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to clone the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## cloneSync<sup>18+</sup>

cloneSync(): PixelMap

Copies the current PixelMap object. This API returns the result synchronously.

> **NOTE**
>
> This API does not copy the EXIF information from the original image.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------------- |
| [PixelMap](arkts-apis-image-PixelMap.md) | If the operation is successful, the copied PixelMap is returned synchronously. Otherwise, an exception is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 501 | Resource unavailable. |
| 62980102 | Image malloc abnormal. This status code is thrown when an error occurs during the process of copying data. |
| 62980103 | Image YUV And ASTC types are not supported. |
| 62980104 | Image initialization abnormal. This status code is thrown when an error occurs during the process of creating empty pixelmap. |
| 62980106 | The image data is too large. This status code is thrown when an error occurs during the process of checking size. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function cloneSync(pixelMap: image.PixelMap) {
  try {
    let clonedPixelMap: image.PixelMap = pixelMap.cloneSync();
    console.info('Succeeded in cloning the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to clone the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## applyTranslate

applyTranslate(x: number, y: number): Promise\<void\>

Translates a PixelMap by the specified horizontal and vertical distances. This API uses a promise to return the result.

> **NOTE**
>
> After translation, the image size becomes: width = original width + x, height = original height + y.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                          |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| x        | number               | Yes  | Horizontal translation distance. Positive values move the image to the right; negative values move it to the left. The value range is (-image width, +∞). The unit is px.<br>When the value is negative, the translation is equivalent to cropping x columns of pixels from the left side of the image.|
| y        | number               | Yes  | Vertical translation distance. Positive values move the image downward; negative values move it upward. The value range is (-image height, +∞). The unit is px.<br>When the value is negative, the translation is equivalent to cropping y rows of pixels from the top of the image.|

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise that returns no value.                       |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible causes: 1. The resulting PixelMap size is too large. 2. The system is out of memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyTranslate(pixelMap: image.PixelMap) {
  const translateX: number = 50.0;
  const translateY: number = 10.0;
  pixelMap.applyTranslate(translateX, translateY)
    .then(() => {
      console.info('Succeeded in translating the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to translate the PixelMap. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## applyTranslateSync

applyTranslateSync(x: number, y: number): void

Translates a PixelMap by the specified horizontal and vertical distances. This API returns the result synchronously.

> **NOTE**
>
> After translation, the image size becomes: width = original width + x, height = original height + y.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                          |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| x        | number               | Yes  | Horizontal translation distance. Positive values move the image to the right; negative values move it to the left. The value range is (-image width, +∞). The unit is px.<br>When the value is negative, the translation is equivalent to cropping x columns of pixels from the left side of the image.|
| y        | number               | Yes  | Vertical translation distance. Positive values move the image downward; negative values move it upward. The value range is (-image height, +∞). The unit is px.<br>When the value is negative, the translation is equivalent to cropping y rows of pixels from the top of the image.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible causes: 1. The resulting PixelMap size is too large. 2. The system is out of memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyTranslateSync(pixelMap: image.PixelMap) {
  const translateX: number = 50.0;
  const translateY: number = 10.0;
  try {
    pixelMap.applyTranslateSync(translateX, translateY);
    console.info('Succeeded in translating the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to translate the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## translate<sup>9+</sup>

translate(x: number, y: number, callback: AsyncCallback\<void>): void

Translates a PixelMap based on given coordinates. This API returns the result asynchronously through a callback.

> **NOTE**
>
> - After translation, the image size becomes: width = original width + x, height = original height + y.
> - Since API version 26.0.0, you are advised to use [applyTranslate](#applytranslate) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| x        | number               | Yes  | Horizontal translation distance. Positive values move the image to the right; negative values move it to the left. The value range is (-image width, +∞). The unit is px.<br>When the value is negative, the translation is equivalent to cropping x columns of pixels from the left side of the image.|
| y        | number               | Yes  | Vertical translation distance. Positive values move the image downward; negative values move it upward. The value range is (-image height, +∞). The unit is px.<br>When the value is negative, the translation is equivalent to cropping y rows of pixels from the top of the image.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function translate(pixelMap: image.PixelMap) {
  const translateX: number = 50.0;
  const translateY: number = 10.0;
  pixelMap.translate(translateX, translateY, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to translate the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in translating the PixelMap.");
  });
}
```

## translate<sup>9+</sup>

translate(x: number, y: number): Promise\<void>

Translates a PixelMap based on given coordinates. This API uses a promise to return the result.

> **NOTE**
>
> - After translation, the image size becomes: width = original width + x, height = original height + y.
> - Since API version 26.0.0, you are advised to use [applyTranslate](#applytranslate) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description       |
| ------ | ------ | ---- | ----------- |
| x        | number               | Yes  | Horizontal translation distance. Positive values move the image to the right; negative values move it to the left. The value range is (-image width, +∞). The unit is px.<br>When the value is negative, the translation is equivalent to cropping x columns of pixels from the left side of the image.|
| y        | number               | Yes  | Vertical translation distance. Positive values move the image downward; negative values move it upward. The value range is (-image height, +∞). The unit is px.<br>When the value is negative, the translation is equivalent to cropping y rows of pixels from the top of the image.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function translate(pixelMap: image.PixelMap) {
  const translateX: number = 50.0;
  const translateY: number = 10.0;
  pixelMap.translate(translateX, translateY).then(() => {
    console.info('Succeeded in translating the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to translate the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## translateSync<sup>12+</sup>

translateSync(x: number, y: number): void

Translates a PixelMap based on given coordinates. This API returns the result synchronously.

> **NOTE**
>
> - After translation, the image size becomes: width = original width + x, height = original height + y.
> - Since API version 26.0.0, you are advised to use [applyTranslateSync](#applytranslatesync) instead for better exception handling.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                           |
| -------- | -------------------- | ---- | ------------------------------- |
| x        | number               | Yes  | Horizontal translation distance. Positive values move the image to the right; negative values move it to the left. The value range is (-image width, +∞). The unit is px.<br>When the value is negative, the translation is equivalent to cropping x columns of pixels from the left side of the image.|
| y        | number               | Yes  | Vertical translation distance. Positive values move the image downward; negative values move it upward. The value range is (-image height, +∞). The unit is px.<br>When the value is negative, the translation is equivalent to cropping y rows of pixels from the top of the image.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function translateSync(pixelMap: image.PixelMap) {
  const translateX: number = 50.0;
  const translateY: number = 10.0;
  try {
    pixelMap.translateSync(translateX, translateY);
    console.info('Succeeded in translating the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to translate the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## applyRotate

applyRotate(angle: number): Promise\<void\>

Rotates a PixelMap by the specified angle. YUV formats support only rotation angles that are multiples of 90°. This API uses a promise to return the result.

> **NOTE**
>
> - The valid rotation angle range is [0, 360]. If the value is outside this range, it is automatically adjusted based on a 360° cycle. For example, -100° and 260° produce the same effect.
> - When the rotation angle is not a multiple of 90°, the image size expands to the bounding rectangle that accommodates the rotated content. For example, a square image rotated by 45° results in an output image with side lengths √2 times the original.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                          |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| angle    | number               | Yes  | Rotation angle. Positive values rotate the image clockwise; negative values rotate it counterclockwise. The unit is degrees (°).                                 |

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise that returns no value.                       |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible causes: 1. The resulting PixelMap size is too large. 2. The system is out of memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyRotate(pixelMap: image.PixelMap) {
  const angle: number = 90.0;
  pixelMap.applyRotate(angle)
    .then(() => {
      console.info('Succeeded in rotating the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to rotate the PixelMap. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## applyRotateSync

applyRotateSync(angle: number): void

Rotates a PixelMap by the specified angle. YUV formats support only rotation angles that are multiples of 90°. This API returns the result synchronously.

> **NOTE**
>
> - The valid rotation angle range is [0, 360]. If the value is outside this range, it is automatically adjusted based on a 360° cycle. For example, -100° and 260° produce the same effect.
> - When the rotation angle is not a multiple of 90°, the image size expands to the bounding rectangle that accommodates the rotated content. For example, a square image rotated by 45° results in an output image with side lengths √2 times the original.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                          |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| angle    | number               | Yes  | Rotation angle. Positive values rotate the image clockwise; negative values rotate it counterclockwise. The unit is degrees (°).                                 |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible causes: 1. The resulting PixelMap size is too large. 2. The system is out of memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyRotateSync(pixelMap: image.PixelMap) {
  const angle: number = 90.0;
  try {
    pixelMap.applyRotateSync(angle);
    console.info('Succeeded in rotating the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to rotate the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## rotate<sup>9+</sup>

rotate(angle: number, callback: AsyncCallback\<void>): void

Rotates an image by the specified angle. YUV formats support only rotation angles that are multiples of 90°. This API returns the result asynchronously through a callback.

> **NOTE**
>
> - The valid rotation angle range is [0, 360]. If the value is outside this range, it is automatically adjusted based on a 360° cycle. For example, -100° and 260° produce the same effect.
> - If the rotation angle is not an integer multiple of 90 degrees, the image size will change after rotation.
> - Since API version 26.0.0, you are advised to use [applyRotate](#applyrotate) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| angle    | number               | Yes  | Rotation angle. Positive values rotate the image clockwise; negative values rotate it counterclockwise. The unit is degrees (°).|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function rotate(pixelMap: image.PixelMap) {
  const angle: number = 90.0;
  pixelMap.rotate(angle, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to rotate the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in rotating the PixelMap.");
  });
}
```

## rotate<sup>9+</sup>

rotate(angle: number): Promise\<void>

Rotates an image by the specified angle. YUV formats support only rotation angles that are multiples of 90°. This API uses a promise to return the result.

> **NOTE**
>
> - The valid rotation angle range is [0, 360]. If the value is outside this range, it is automatically adjusted based on a 360° cycle. For example, -100° and 260° produce the same effect.
> - If the rotation angle is not an integer multiple of 90 degrees, the image size will change after rotation.
> - Since API version 26.0.0, you are advised to use [applyRotate](#applyrotate) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type  | Mandatory| Description                         |
| ------ | ------ | ---- | ----------------------------- |
| angle  | number | Yes  | Rotation angle. Positive values rotate the image clockwise; negative values rotate it counterclockwise. The unit is degrees (°).|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function rotate(pixelMap: image.PixelMap) {
  const angle: number = 90.0;
  pixelMap.rotate(angle).then(() => {
    console.info('Succeeded in rotating the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to rotate the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## rotateSync<sup>12+</sup>

rotateSync(angle: number): void

Rotates an image by the specified angle. YUV formats support only rotation angles that are multiples of 90°. This API returns the result synchronously.

> **NOTE**
>
> - The valid rotation angle range is [0, 360]. If the value is outside this range, it is automatically adjusted based on a 360° cycle. For example, -100° and 260° produce the same effect.
> - If the rotation angle is not an integer multiple of 90 degrees, the image size will change after rotation.
> - Since API version 26.0.0, you are advised to use [applyRotateSync](#applyrotatesync) instead for better exception handling.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| angle    | number               | Yes  | Rotation angle. Positive values rotate the image clockwise; negative values rotate it counterclockwise. The unit is degrees (°).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function rotateSync(pixelMap: image.PixelMap) {
  const angle: number = 90.0;
  try {
    pixelMap.rotateSync(angle);
    console.info('Succeeded in rotating the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to rotate the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## applyFlip

applyFlip(horizontal: boolean, vertical: boolean): Promise\<void\>

Flips an PixelMap based on the specified horizontal or vertical flip conditions. This API uses a promise to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                          |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| horizontal | boolean            | Yes  | Whether to flip horizontally. **true** to flip the image horizontally, **false** otherwise.                           |
| vertical   | boolean            | Yes  | Whether to flip vertically. **true** to flip the image vertically, **false** otherwise.                           |

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise that returns no value.                       |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible cause: The system is out of memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyFlip(pixelMap: image.PixelMap) {
  const horizontal: boolean = true;
  const vertical: boolean = false;
  pixelMap.applyFlip(horizontal, vertical)
    .then(() => {
      console.info('Succeeded in flipping the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to flip the PixelMap. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## applyFlipSync

applyFlipSync(horizontal: boolean, vertical: boolean): void

Flips an PixelMap based on the specified horizontal or vertical flip conditions. This API returns the result synchronously.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                          |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| horizontal | boolean            | Yes  | Whether to flip horizontally. **true** to flip the image horizontally, **false** otherwise.                           |
| vertical   | boolean            | Yes  | Whether to flip vertically. **true** to flip the image vertically, **false** otherwise.                           |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600206 | Invalid parameter. |
| 7600301 | Failed to allocate memory. Possible cause: The system is out of memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyFlipSync(pixelMap: image.PixelMap) {
  const horizontal: boolean = true;
  const vertical: boolean = false;
  try {
    pixelMap.applyFlipSync(horizontal, vertical);
    console.info('Succeeded in flipping the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to flip the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## flip<sup>9+</sup>

flip(horizontal: boolean, vertical: boolean, callback: AsyncCallback\<void>): void

Flips an image based on the specified horizontal or vertical flip conditions. This API returns the result asynchronously through a callback.

> **NOTE**
>
> Since API version 26.0.0, you are advised to use [applyFlip](#applyflip) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type                | Mandatory| Description                         |
| ---------- | -------------------- | ---- | ----------------------------- |
| horizontal | boolean              | Yes  | Whether to flip the image horizontally. **true** to flip the image horizontally, **false** otherwise.           |
| vertical   | boolean              | Yes  | Whether to flip the image vertically. **true** to flip the image vertically, **false** otherwise.           |
| callback   | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function flip(pixelMap: image.PixelMap) {
  const horizontal: boolean = true;
  const vertical: boolean = false;
  pixelMap.flip(horizontal, vertical, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to flip the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in flipping the PixelMap.");
  });
}
```

## flip<sup>9+</sup>

flip(horizontal: boolean, vertical: boolean): Promise\<void>

Flips an image based on the specified horizontal or vertical flip conditions. This API uses a promise to return the result.

> **NOTE**
>
> Since API version 26.0.0, you are advised to use [applyFlip](#applyflip) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type   | Mandatory| Description     |
| ---------- | ------- | ---- | --------- |
| horizontal | boolean              | Yes  | Whether to flip the image horizontally. **true** to flip the image horizontally, **false** otherwise.           |
| vertical   | boolean              | Yes  | Whether to flip the image vertically. **true** to flip the image vertically, **false** otherwise.           |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function flip(pixelMap: image.PixelMap) {
  const horizontal: boolean = true;
  const vertical: boolean = false;
  pixelMap.flip(horizontal, vertical).then(() => {
    console.info('Succeeded in flipping the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to flip the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## flipSync<sup>12+</sup>

flipSync(horizontal: boolean, vertical: boolean): void

Flips an image based on the specified horizontal or vertical flip conditions. This API returns the result synchronously.

> **NOTE**
>
> Since API version 26.0.0, you are advised to use [applyFlipSync](#applyflipsync) instead for better exception handling.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type                | Mandatory| Description                         |
| ---------- | -------------------- | ---- | ----------------------------- |
| horizontal | boolean              | Yes  | Whether to flip the image horizontally. **true** to flip the image horizontally, **false** otherwise.           |
| vertical   | boolean              | Yes  | Whether to flip the image vertically. **true** to flip the image vertically, **false** otherwise.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function flipSync(pixelMap: image.PixelMap) {
  const horizontal: boolean = true;
  const vertical: boolean = false;
  try {
    pixelMap.flipSync(horizontal, vertical);
    console.info('Succeeded in flipping the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to flip the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## applyCrop

applyCrop(region: Region): Promise\<void\>

Crops a PixelMap based on the specified region information. This API uses a promise to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                          |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| region   | [Region](arkts-apis-image-i.md#region8)   | Yes  | Cropping region. The region range cannot exceed the width and height of the image. The unit is px.             |

**Return value**

| Type          | Description                                           |
| -------------- | ----------------------------------------------- |
| Promise\<void\> | Promise that returns no value.                       |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600204 | The specified region is invalid or out of range. |
| 7600301 | Failed to allocate memory. Possible causes: 1. Failed to process pixel data. 2. The system is out of memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyCrop(pixelMap: image.PixelMap) {
  const currSize = pixelMap.getImageInfoSync().size;
  const region: image.Region = { // The cropping region is set to the central quarter of the image.
    x: currSize.width / 4,
    y: currSize.height / 4,
    size: {
      width: currSize.width / 2,
      height: currSize.height / 2
    }
  };

  pixelMap.applyCrop(region)
    .then(() => {
      console.info('Succeeded in cropping the PixelMap.');
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to crop the PixelMap. Code: ${err.code}, message: ${err.message}`);
    });
}
```

## applyCropSync

applyCropSync(region: Region): void

Crops a PixelMap based on the specified region information. This API returns the result synchronously.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                          |
| -------- | -------------------- | ---- | --------------------------------------------------------------------------------------- |
| region   | [Region](arkts-apis-image-i.md#region8)   | Yes  | Cropping region. The region range cannot exceed the width and height of the image. The unit is px.             |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------ | --------------------------------------------|
| 7600104 | Failed to get image data. Possible cause: Internal data is corrupted. Please check the logs for detailed information. |
| 7600105 | The PixelMap has been released. |
| 7600106 | The PixelMap has been passed to another thread. |
| 7600201 | Unsupported operation because the PixelMap is locked. |
| 7600204 | The specified region is invalid or out of range. |
| 7600301 | Failed to allocate memory. Possible causes: 1. Failed to process pixel data. 2. The system is out of memory. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function applyCropSync(pixelMap: image.PixelMap) {
  const currSize = pixelMap.getImageInfoSync().size;
  const region: image.Region = { // The cropping region is set to the central quarter of the image.
    x: currSize.width / 4,
    y: currSize.height / 4,
    size: {
      width: currSize.width / 2,
      height: currSize.height / 2
    }
  };

  try {
    pixelMap.applyCropSync(region);
    console.info('Succeeded in cropping the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to crop the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## crop<sup>9+</sup>

crop(region: Region, callback: AsyncCallback\<void>): void

Crops a PixelMap based on a given size. This API returns the result asynchronously through a callback.

> **NOTE**
>
> Since API version 26.0.0, you are advised to use [applyCrop](#applycrop) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| region   | [Region](arkts-apis-image-i.md#region8)   | Yes  | Cropping region, including the start coordinates, width, and height. The value cannot exceed the width or height of the image. The unit is px.|
| callback | AsyncCallback\<void> | Yes  |  Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function crop(pixelMap: image.PixelMap) {
  const region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  pixelMap.crop(region, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to crop the PixelMap. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in cropping the PixelMap.");
  });
}
```

## crop<sup>9+</sup>

crop(region: Region): Promise\<void>

Crops a PixelMap based on a given size. This API uses a promise to return the result.

> **NOTE**
>
> Since API version 26.0.0, you are advised to use [applyCrop](#applycrop) instead for better exception handling.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type              | Mandatory| Description       |
| ------ | ------------------ | ---- | ----------- |
| region | [Region](arkts-apis-image-i.md#region8) | Yes  | Cropping region, including the start coordinates, width, and height. The value cannot exceed the width or height of the image. The unit is px.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function crop(pixelMap: image.PixelMap) {
  const region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  pixelMap.crop(region).then(() => {
    console.info('Succeeded in cropping the PixelMap.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to crop the PixelMap. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## cropSync<sup>12+</sup>

cropSync(region: Region): void

Crops this image based on a given size. This API returns the result synchronously. This API returns the result synchronously.

> **NOTE**
>
> Since API version 26.0.0, you are advised to use [applyCropSync](#applycropsync) instead for better exception handling.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| region   | [Region](arkts-apis-image-i.md#region8)   | Yes  | Cropping region, including the start coordinates, width, and height. The value cannot exceed the width or height of the image. The unit is px.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  401    | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
|  501    | Resource Unavailable |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function cropSync(pixelMap: image.PixelMap) {
  const region: image.Region = { x: 0, y: 0, size: { height: 100, width: 100 } };
  try {
    pixelMap.cropSync(region);
    console.info('Succeeded in cropping the PixelMap.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to crop the PixelMap. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## getColorSpace<sup>10+</sup>

getColorSpace(): colorSpaceManager.ColorSpaceManager

Obtains the color space of an image.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type                               | Description            |
| ----------------------------------- | ---------------- |
| [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | Color space information of the image. If the image does not contain color space information, an exception is thrown.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| -------- | ------------------------------------------ |
| 62980101 | The image data is abnormal.                |
| 62980103 | The image data is not supported.           |
| 62980115 | Invalid image parameter.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getColorSpace(pixelMap: image.PixelMap) {
  try {
    const csm = pixelMap.getColorSpace();
    console.info(`Succeeded in getting color space: ${csm.getColorSpaceName()}.`);
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to get color space. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## setColorSpace<sup>10+</sup>

setColorSpace(colorSpace: colorSpaceManager.ColorSpaceManager): void

Sets the color space of an image. To simultaneously perform color space conversion on the pixel colors of the image, use [applyColorSpace](#applycolorspace11).

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name    | Type                               | Mandatory| Description           |
| ---------- | ----------------------------------- | ---- | --------------- |
| colorSpace | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | Yes  | Color space information of the image.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| -------- | --------------------------------------------|
| 62980111 | The image source data is incomplete.        |
| 62980115 | If the image parameter invalid.             |

**Example**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
import { BusinessError } from '@kit.BasicServicesKit';

function setColorSpace(pixelMap: image.PixelMap) {
  const colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
  const csm: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
  try {
    pixelMap.setColorSpace(csm);
    console.info('Succeeded in setting color space.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to set color space. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## applyColorSpace<sup>11+</sup>

applyColorSpace(targetColorSpace: colorSpaceManager.ColorSpaceManager, callback: AsyncCallback\<void>): void

Performs color space conversion on the pixel colors of an image according to the specified target color space. This API returns the result asynchronously through a callback.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description                         |
| -------- | -------------------- | ---- | ----------------------------- |
| targetColorSpace | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | Yes  | Target color space. SRGB, DCI_P3, DISPLAY_P3, and ADOBE_RGB_1998 are supported.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | ------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
| 62980104| Failed to initialize the internal object. |
| 62980108| Failed to convert the color space.       |
| 62980115| Invalid image parameter.            |

**Example**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
import { BusinessError } from '@kit.BasicServicesKit';

function applyColorSpace(pixelMap: image.PixelMap) {
  const colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
  const targetColorSpace: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
  pixelMap.applyColorSpace(targetColorSpace, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to apply color space. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in applying color space.');
  });
}
```

## applyColorSpace<sup>11+</sup>

applyColorSpace(targetColorSpace: colorSpaceManager.ColorSpaceManager): Promise\<void>

Performs color space conversion on the pixel colors of an image according to the specified target color space. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name| Type              | Mandatory| Description       |
| ------ | ------------------ | ---- | ----------- |
| targetColorSpace | [colorSpaceManager.ColorSpaceManager](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspacemanager) | Yes  | Target color space. SRGB, DCI_P3, DISPLAY_P3, and ADOBE_RGB_1998 are supported.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | ------------------------------------------|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed |
| 62980104| Failed to initialize the internal object. |
| 62980108| Failed to convert the color space.       |
| 62980115| Invalid image parameter.            |

**Example**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
import { BusinessError } from '@kit.BasicServicesKit';

function applyColorSpace(pixelMap: image.PixelMap) {
  const colorSpaceName = colorSpaceManager.ColorSpace.SRGB;
  const targetColorSpace: colorSpaceManager.ColorSpaceManager = colorSpaceManager.create(colorSpaceName);
  pixelMap.applyColorSpace(targetColorSpace).then(() => {
    console.info('Succeeded in applying color space.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to apply color space. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## toSdr<sup>12+</sup>

toSdr(): Promise\<void>

Converts a PixelMap from the HDR format to the SDR format. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980137 | Invalid image operation.              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function toSdr(context: Context) {
  // Replace app.media.startIcon with a local HDR image.
  let img = context.resourceManager.getMediaContentSync($r('app.media.startIcon').id);
  let imageSource = image.createImageSource(img.buffer.slice(0));
  let decodingOptions: image.DecodingOptions = {
    desiredDynamicRange: image.DecodingDynamicRange.AUTO
  };
  let pixelmap = imageSource.createPixelMapSync(decodingOptions);
  if (pixelmap != undefined) {
    console.info('Succeeded in creating the PixelMap object.');
    pixelmap.toSdr().then(() => {
      let imageInfo = pixelmap.getImageInfoSync();
      console.info("Succeeded in converting to SDR. imageInfo.isHdr: " + imageInfo.isHdr);
    }).catch((err: BusinessError) => {
      console.error(`Failed to convert to SDR. Code: ${err.code}, message: ${err.message}`);
    });
  } else {
    console.error('Failed to create the PixelMap.');
  }
}
```

## getMetadata<sup>12+</sup>

getMetadata(key: HdrMetadataKey): HdrMetadataValue

Obtains the HDR metadata from a PixelMap.

> **NOTE**
>
> This API supports only PixelMaps with DMA memory type. For details, please refer to [Allocating Memory for Image Decoding (ArkTS)](../../media/image/image-allocator-type.md).

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name       | Type                            | Mandatory| Description            |
| ------------- | -------------------------------- | ---- | ---------------- |
| key | [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12) | Yes  | Key of the HDR metadata.|

**Return value**

| Type                             | Description                             |
| --------------------------------- | --------------------------------- |
| [HdrMetadataValue](arkts-apis-image-t.md#hdrmetadatavalue12) | Value of the metadata with the given key.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401| Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.          |
| 501 | Resource unavailable.          |
| 62980173 | The DMA memory does not exist.          |
| 62980302 | Memory copy failed. Possibly caused by invalid metadata value.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getMetadata(context: Context) {
  // Replace app.media.startIcon with a local HDR image.
  let img = context.resourceManager.getMediaContentSync($r('app.media.startIcon').id);
  let imageSource = image.createImageSource(img.buffer.slice(0));
  let decodingOptions: image.DecodingOptions = {
    desiredDynamicRange: image.DecodingDynamicRange.AUTO
  };
  let pixelMap = imageSource.createPixelMapSync(decodingOptions);
  if (pixelMap != undefined) {
    console.info('Succeeded in creating the PixelMap object.');
    try {
      let staticMetadata = pixelMap.getMetadata(image.HdrMetadataKey.HDR_STATIC_METADATA);
      console.info('Succeeded in getting the metadata.');
    } catch (e) {
      const err = e as BusinessError;
      console.error(`Failed to get the metadata. Code: ${err.code}, message: ${err.message}`);
    }
  } else {
    console.error('Failed to create the PixelMap.');
  }
}
```

## setMetadata<sup>12+</sup>

setMetadata(key: HdrMetadataKey, value: HdrMetadataValue): Promise\<void>

Sets the HDR metadata for a PixelMap. This API uses a promise to return the result.

> **NOTE**
>
> This API supports only PixelMaps with DMA memory type. For details, please refer to [Allocating Memory for Image Decoding (ArkTS)](../../media/image/image-allocator-type.md).

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name       | Type                            | Mandatory| Description            |
| ------------- | -------------------------------- | ---- | ---------------- |
| key | [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12) | Yes  | Key of the HDR metadata.|
| value | [HdrMetadataValue](arkts-apis-image-t.md#hdrmetadatavalue12) | Yes  | Value of the metadata.|

**Return value**

| Type          | Description                 |
| -------------- | --------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401|  Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 501 | Resource unavailable.          |
| 62980173 | The DMA memory does not exist.          |
| 62980302 | Memory copy failed. Possibly caused by invalid metadata value.         |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setMetadata(pixelMap: image.PixelMap) { // The input parameter pixelMap must be of the DMA_ALLOC memory type. For details about how to create a PixelMap with DMA_ALLOC memory, see the preceding link.
  let staticMetadata: image.HdrStaticMetadata = {
    displayPrimariesX: [1.1, 1.1, 1.1],
    displayPrimariesY: [1.2, 1.2, 1.2],
    whitePointX: 1.1,
    whitePointY: 1.2,
    maxLuminance: 2.1,
    minLuminance: 1.0,
    maxContentLightLevel: 2.1,
    maxFrameAverageLightLevel: 2.1,
  };
  pixelMap.setMetadata(image.HdrMetadataKey.HDR_STATIC_METADATA, staticMetadata).then(() => {
    console.info('Succeeded in setting the metadata.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the metadata. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## setTransferDetached<sup>12+</sup>

setTransferDetached(detached: boolean): void

Sets whether a PixelMap detaches from the original thread reference after being transferred across threads. This is suitable for scenarios where the PixelMap needs to be released immediately.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type              | Mandatory| Description                         |
| ------- | ------------------ | ---- | ----------------------------- |
| detached | boolean   | Yes  | Whether to detach from the original thread. **true** to detach, **false** otherwise.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
|  501    | Resource Unavailable |

**Example**

```ts
// EntryAbility.ets
import { common } from '@kit.AbilityKit';
import { taskpool } from '@kit.ArkTS';

@Concurrent
// Child thread method.
async function loadPixelMap(rawFileDescriptor: number): Promise<image.PixelMap> {
  // Create an ImageSource.
  const imageSource = image.createImageSource(rawFileDescriptor);
  // Create a PixelMap.
  const pixelMap = imageSource.createPixelMapSync();
  // Release the ImageSource.
  imageSource.release();
  // Makes the PixelMap detach from the original thread reference after cross-thread transfer is complete.
  pixelMap.setTransferDetached(true);
  // Return the PixelMap to the main thread.
  return pixelMap;
}

@Entry
@Component
struct Demo {
  @State pixelMap: image.PixelMap | undefined = undefined;
  // Main thread method.
  private loadImageFromThread(): void {
    let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
    const resourceMgr = context.resourceManager;
    // 'example.jpg' is only an example. Replace it with the actual one in use. Otherwise, the creation fails, and subsequent operations cannot be performed.
    resourceMgr.getRawFd('example.jpg').then(rawFileDescriptor => {
      taskpool.execute(loadPixelMap, rawFileDescriptor).then(pixelMap => {
        if (pixelMap) {
          this.pixelMap = pixelMap as image.PixelMap;
          console.info('Succeeded in creating the PixelMap.');
          // The main thread releases the pixel map. Since setTransferDetached(true) has been called before the child thread returns the PixelMap, the PixelMap can be released immediately without waiting for the child thread to be destroyed.
          this.pixelMap.release();
        } else {
          console.error('Failed to create the PixelMap.');
        }
      });
    });
  }
  build() {
    // ...
  }
}
```

## marshalling<sup>10+</sup>

marshalling(sequence: rpc.MessageSequence): void

Marshals this PixelMap object and writes it to a MessageSequence object.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                                                 | Mandatory| Description                                    |
| ---------------------- | ------------------------------------------------------ | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9)  | Yes  | MessageSequence object.                |

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980115 | Invalid image parameter.              |
| 62980097 | IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.            |

**Example**

```ts
// EntryAbility.ets
import { rpc } from '@kit.IPCKit';

class MySequence implements rpc.Parcelable {
  pixelMap: image.PixelMap;
  constructor(pixelMap: image.PixelMap) {
    this.pixelMap = pixelMap;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    this.pixelMap.marshalling(messageSequence);
    console.info('Marshalled the PixelMap.');
    return true;
  }
  unmarshalling(messageSequence: rpc.MessageSequence) {
    image.createPixelMap(new ArrayBuffer(96), {size: { height: 4, width: 6 }}).then((pixelParcel: image.PixelMap) => {
      pixelParcel.unmarshalling(messageSequence).then(async (pixelMap: image.PixelMap) => {
        this.pixelMap = pixelMap;
        pixelMap.getImageInfo().then((imageInfo: image.ImageInfo) => {
          console.info(`Unmarshalled information: height = ${imageInfo.size.height}, width = ${imageInfo.size.width}.`);
        });
      });
    });
    return true;
  }
}

async function marshal() {
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
  let pixelMap: image.PixelMap | undefined = undefined;
  await image.createPixelMap(color, opts).then((srcPixelMap: image.PixelMap) => {
    pixelMap = srcPixelMap;
  })
  if (pixelMap != undefined) {
    // Implement serialization.
    let parcelable: MySequence = new MySequence(pixelMap);
    let data: rpc.MessageSequence = rpc.MessageSequence.create();
    data.writeParcelable(parcelable);

    // Implement deserialization to obtain data through the RPC.
    let seq: MySequence = new MySequence(pixelMap);
    data.readParcelable(seq);
  }
}
```

## unmarshalling<sup>10+</sup>

unmarshalling(sequence: rpc.MessageSequence): Promise\<PixelMap>

Deserializes and obtains a PixelMap from the MessageSequence. This API uses a promise to return the result.

> **NOTE**
>
> To deserialize and create a PixelMap object in synchronous mode, use [createPixelMapFromParcel](arkts-apis-image-f.md#imagecreatepixelmapfromparcel11).

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name                | Type                                                 | Mandatory| Description                                    |
| ---------------------- | ----------------------------------------------------- | ---- | ---------------------------------------- |
| sequence               | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | Yes  | MessageSequence object that stores the PixelMap information.     |

**Return value**

| Type                            | Description                 |
| -------------------------------- | --------------------- |
| Promise\<[PixelMap](arkts-apis-image-PixelMap.md)> | Promise used to return the deserialized PixelMap.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980115 | Invalid image parameter.              |
| 62980097 | IPC error. Possible cause: 1.IPC communication failed. 2. Image upload exception. 3. Decode process exception. 4. Insufficient memory.              |
| 62980096 | The operation failed. Possible cause: 1.Image upload exception. 2. Decoding process exception. 3. Insufficient memory.         |

**Example**

```ts
// EntryAbility.ets
import { rpc } from '@kit.IPCKit';

class MySequence implements rpc.Parcelable {
  pixelMap: image.PixelMap;
  constructor(pixelMap: image.PixelMap) {
    this.pixelMap = pixelMap;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    this.pixelMap.marshalling(messageSequence);
    console.info('Marshalled the PixelMap.');
    return true;
  }
  unmarshalling(messageSequence: rpc.MessageSequence) {
    image.createPixelMap(new ArrayBuffer(96), {size: { height: 4, width: 6 }}).then((pixelParcel: image.PixelMap) => {
      pixelParcel.unmarshalling(messageSequence).then(async (pixelMap: image.PixelMap) => {
        this.pixelMap = pixelMap;
        pixelMap.getImageInfo().then((imageInfo: image.ImageInfo) => {
          console.info(`Unmarshalled information: height = ${imageInfo.size.height}, width = ${imageInfo.size.width}.`);
        });
      });
    });
    return true;
  }
}

async function unmarshal() {
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
  let pixelMap: image.PixelMap | undefined = undefined;
  await image.createPixelMap(color, opts).then((srcPixelMap: image.PixelMap) => {
    pixelMap = srcPixelMap;
  })
  if (pixelMap != undefined) {
    // Implement serialization.
    let parcelable: MySequence = new MySequence(pixelMap);
    let data: rpc.MessageSequence = rpc.MessageSequence.create();
    data.writeParcelable(parcelable);

    // Implement deserialization to obtain data through the RPC.
    let seq: MySequence = new MySequence(pixelMap);
    data.readParcelable(seq);
  }
}
```

## release<sup>7+</sup>

release(): Promise\<void\>

Releases a PixelMap object. After the release, any attempt to access the internal data of this object will fail. This API uses a promise to return the result.

Images occupy a large amount of memory. When you finish using a PixelMap instance, call this API to free the memory promptly.

Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

> **NOTE**
>
> Release occurs when an ArkTS object relinquishes control over its associated native object. The memory occupied by the native object is reclaimed only after all managing ArkTS objects have relinquished their control.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type          | Description                           |
| -------------- | ------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function release(pixelMap: image.PixelMap) {
  pixelMap.release().then(() => {
    console.info('Succeeded in releasing the PixelMap object.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to release the PixelMap object. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## release<sup>7+</sup>

release(callback: AsyncCallback\<void\>): void

Releases a PixelMap object. After release, any method calls that access the internal data of the object will fail. This API returns the result asynchronously through a callback.

Images occupy a large amount of memory. When you finish using a PixelMap instance, call this API to free the memory promptly.

Before releasing the instance, ensure that all asynchronous operations associated with the instance have finished and the instance is no longer needed.

> **NOTE**
>
> Release occurs when an ArkTS object relinquishes control over its associated native object. The memory occupied by the native object is reclaimed only after all managing ArkTS objects have relinquished their control.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description              |
| -------- | -------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function release(pixelMap: image.PixelMap) {
  pixelMap.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the PixelMap object. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in releasing the PixelMap object.');
  });
}
```

## convertPixelFormat<sup>12+</sup>

convertPixelFormat(targetPixelFormat: PixelMapFormat): Promise\<void>

Converts between YUV and RGB formats. This API uses a promise to return the result.

The supported conversions are as follows: conversion between NV12/NV21 and RGB_888/RGBA_8888/RGB_565/BGRA_8888/RGBA_F16, and conversion between YCRCB_P010/YCBCR_P010 and RGBA_1010102.

Since API version 18, this API can also be used to convert the ASTC_4x4 format to the RGBA8888 format. Currently, only conversion from ASTC_4x4 to RGBA8888 is supported.

> **NOTE**
>
> Call this API to convert the format from ASTC_4x4 to RGBA_8888 only when you need to access pixels of images in ASTC_4x4 format. The conversion from ASTC_4x4 to RGBA_8888 is slow and is not recommended in other cases.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name  | Type                | Mandatory| Description              |
| -------- | -------------------- | ---- | ------------------ |
| targetPixelFormat | [PixelMapFormat](arkts-apis-image-e.md#pixelmapformat7) | Yes  | Target pixel format. Currently, only conversion between NV12/NV21 and RGB_888/RGBA_8888/RGB_565/BGRA_8888/RGBA_F16, conversion between YCRCB_P010/YCBCR_P010 and RGBA_1010102, and conversion from ASTC_4x4 to RGBA_8888 are supported.|

**Return value**

| Type          | Description                           |
| -------------- | ------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 62980111 | The image source data is incomplete. |
| 62980115 | Invalid input parameter.              |
| 62980178 | Failed to create the pixelmap. |
| 62980274 | The conversion failed |
| 62980276 | The type to be converted is an unsupported target pixel format|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function convertPixelFormat(pixelMap: image.PixelMap) {
  // Set the target pixel format to NV12.
  let targetPixelFormat = image.PixelMapFormat.NV12;
  pixelMap.convertPixelFormat(targetPixelFormat).then(() => {
    console.info('Succeeded in converting pixel format.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to convert pixel format. Code: ${err.code}, message: ${err.message}`);
  });
}
```

## setMemoryNameSync<sup>13+</sup>

setMemoryNameSync(name: string): void

Sets the memory identifier of a PixelMap to facilitate memory identification during debugging or issue troubleshooting.

**System capability**: SystemCapability.Multimedia.Image.Core

**Parameters**

| Name       | Type                            | Mandatory| Description            |
| ------------- | -------------------------------- | ---- | ---------------- |
| name | string | Yes  | PixelMap memory identifier. It can only be set for PixelMaps with DMA or SHARE_MEMORY memory types. For the DMA memory, the value length must be in the range [1, 255] bytes. For the SHARE_MEMORY memory, the value length must be in the range [1, 244] bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.The length of the input parameter is too long. 2.Parameter verification failed. |
| 501 | Resource unavailable. |
| 62980286 | Memory format not supported. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setMemoryNameSync(pixelMap: image.PixelMap) {
  try {
    pixelMap.setMemoryNameSync("PixelMapName Test");
    console.info('Succeeded in setting memory name.');
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to set memory name. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## getUniqueId<sup>22+</sup>

getUniqueId(): number

Obtains the unique ID of this PixelMap.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| number | Unique ID. The value is a positive integer.|

**Error codes**

For details about the error codes, see [Image Error Codes](errorcode-image.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 7600201 | The PixelMap has been released. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getUniqueId(pixelMap: image.PixelMap) {
  try {
    const uniqueId: number = pixelMap.getUniqueId();
    console.info(`Succeeded in getting the unique ID: ${uniqueId}.`);
  } catch (e) {
    const err = e as BusinessError;
    console.error(`Failed to get the unique ID. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## isReleased<sup>22+</sup>

isReleased(): boolean

Checks whether this PixelMap object is released. If released, any attempt to access the internal data of this object will fail.

> **NOTE**
>
> Release occurs when an ArkTS object relinquishes control over its associated native object. The memory occupied by the native object is reclaimed only after all managing ArkTS objects have relinquished their control.

**System capability**: SystemCapability.Multimedia.Image.Core

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| boolean | Check result for whether the PixelMap object is released. **true** if released; **false** otherwise.|

**Example**

```ts
async function isReleased(pixelMap: image.PixelMap) { // Unreleased PixelMap.
  pixelMap.isReleased(); // Return false.
  await pixelMap.release();
  pixelMap.isReleased(); // Return true.
}
```

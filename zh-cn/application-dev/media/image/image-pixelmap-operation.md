# 使用PixelMap完成位图操作

当需要对目标图片中的部分区域进行处理时，可以使用位图操作功能。此功能常用于图片美化等操作。

如下图所示，一张图片中，将指定的矩形区域像素数据读取出来，进行修改后，再写回原图片对应区域。

**图1** 位图操作示意图

![Bitmap operation](figures/bitmap-operation.png)

## 开发步骤

位图操作相关API的详细介绍请参见[API参考](../../reference/apis-image-kit/js-apis-image.md#pixelmap7)。

1. 完成[图片解码](image-decoding.md)，获取PixelMap位图对象。

2. 从PixelMap位图对象中获取信息。

   ```ts
   import { image } from '@kit.ImageKit';
   // 获取图像像素的总字节数
   let pixelBytesNumber : number = pixelMap.getPixelBytesNumber();
   // 获取图像像素每行字节数
   let rowCount : number = pixelMap.getBytesNumberPerRow();
   // 获取当前图像像素密度。像素密度是指每英寸图片所拥有的像素数量。像素密度越大，图片越精细。
   let getDensity : number = pixelMap.getDensity();
   ```

3. 读取并修改目标区域像素数据，写回原图。

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   // 场景一：将读取的整张图像像素数据结果写入ArrayBuffer中
   const readBuffer = new ArrayBuffer(pixelBytesNumber);
   pixelMap.readPixelsToBuffer(readBuffer).then(() => {
     console.info('Succeeded in reading image pixel data.');
   }).catch((error : BusinessError) => {
     console.error('Failed to read image pixel data. And the error is: ' + error);
   })
   
   // 场景二：读取指定区域内的图片数据，结果写入area.pixels中
   const area : image.PositionArea = {
     pixels: new ArrayBuffer(8),
     offset: 0,
     stride: 8,
     region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
   }
   pixelMap.readPixels(area).then(() => {
     console.info('Succeeded in reading the image data in the area.');
   }).catch((error : BusinessError) => {
     console.error('Failed to read the image data in the area. And the error is: ' + error);
   })
   
   // 对于读取的图片数据，可以独立使用（创建新的pixelMap），也可以对area.pixels进行所需修改
   // 将图片数据area.pixels写入指定区域内
   pixelMap.writePixels(area).then(() => {
     console.info('Succeeded to write pixelMap into the specified area.');
   })
   
   // 将图片数据结果写入pixelMap中
   const writeColor = new ArrayBuffer(96);
   pixelMap.writeBufferToPixels(writeColor, () => {});
   ```

## 开发示例-复制（深拷贝）一个新的PixelMap

1. 完成[图片解码](image-decoding.md)，获取PixelMap位图对象。

2. 复制（深拷贝）一个新的PixelMap。
   > **说明：** 若创建新 PixelMap 时指定的 srcPixelFormat 与被复制的 PixelMap 的像素格式不一致，则新 PixelMap 的图片色彩与被复制的 PixelMap 的图片色彩会不一致。

     ```ts
      /**
       *  复制（深拷贝）一个新的PixelMap
       *
       * @param pixelMap - 被复制的 PixelMap。
       * @param desiredPixelFormat - 新 PixelMap 的像素格式。如果不指定，则仍使用原 PixelMap 的像素格式。
       * @returns 新 PixelMap。
       **/
      clonePixelMap(pixelMap: PixelMap, desiredPixelFormat?: image.PixelMapFormat): PixelMap {
        // 获取当前 PixelMap 的图片信息
        const imageInfo = pixelMap.getImageInfoSync();
        // 读取当前 PixelMap 的图像像素数据，并按照当前 PixelMap 的像素格式写入缓冲区数组
        const buffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
        pixelMap.readPixelsToBufferSync(buffer);
        // 根据当前 PixelMap 的图片信息，生成初始化选项。
        const options: image.InitializationOptions = {
          // 当前 PixelMap 的像素格式
          srcPixelFormat: imageInfo.pixelFormat,
          // 新 PixelMap 的像素格式
          pixelFormat: desiredPixelFormat ?? imageInfo.pixelFormat,
          // 当前 PixelMap 的尺寸大小
          size: imageInfo.size
        };
        // 根据初始化选项和缓冲区数组，生成新 PixelMap
        return image.createPixelMapSync(buffer, options);
      }
     ```

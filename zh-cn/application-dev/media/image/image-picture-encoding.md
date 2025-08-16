# 使用ImagePacker完成多图对象编码
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

图片编码指将Picture多图对象编码成不同格式的图片文件（当前仅支持编码为JPEG 和 HEIF 格式），用于后续处理，如保存、传输等。

## 开发步骤

图片编码相关API的详细介绍请参见：[图片编码接口说明](../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md)。

### 图片编码进文件流

1. 创建图像编码ImagePacker对象。

   ```ts
   // 导入相关模块包。
   import { image } from '@kit.ImageKit';
   
   const imagePackerApi = image.createImagePacker();
   ```

2. 设置编码输出流和编码参数。

   format为图像的编码格式；quality为图像质量，范围从0-100，100为最佳质量

      > **说明：**
      > 根据MIME标准，标准编码格式为image/jpeg。当使用image编码时，PackingOption.format设置为image/jpeg，image编码后的文件扩展名可设为.jpg或.jpeg，可在支持image/jpeg解码的平台上使用。

      ```ts
      let packOpts: image.PackingOption = {
        format: "image/jpeg",
        quality: 98,
        bufferSize: 10,
        desiredDynamicRange: image.PackingDynamicRange.AUTO,
        needsPackProperties: true
      };
      ```

3. 进行图片编码，并保存编码后的图片。在进行编码前，需要先通过解码获取picture，可参考[使用ImageSource完成多图对象解码](./image-picture-decoding.md)。

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   // 调用以下编码接口时，请确保首先成功获取picture对象。
   imagePackerApi.packing(picture, packOpts).then( (data : ArrayBuffer) => {
     console.info('Succeeded in packing the image.'+ data);
   }).catch((error : BusinessError) => { 
     console.error('Failed to pack the image. And the error is: ' + error); 
   })
   ```

### 图片编码进文件

在编码时，开发者可以传入对应的文件路径，编码后的内存数据将直接写入文件。在进行编码前，需要先通过解码获取picture，可参考[使用ImageSource完成多图对象解码](./image-picture-decoding.md)。

  ```ts
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  const context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  const path : string = context.cacheDir + "/picture.jpg";
  let file = fileIo.openSync(path, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  // 调用以下编码接口时，请确保首先成功获取picture对象。
  imagePackerApi.packToFile(picture, file.fd, packOpts).then(() => {
    console.info('Succeeded in packing the image to file.');
  }).catch((error : BusinessError) => {
    console.error('Failed to pack the image. And the error is: ' + error);
  })
  ```

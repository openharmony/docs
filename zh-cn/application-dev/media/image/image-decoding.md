# 使用ImageSource完成图片解码

图片解码指将所支持格式的存档图片解码成统一的[PixelMap](image-overview.md)，以便在应用或系统中进行图片显示或[图片处理](image-transformation.md)。当前支持的存档图片格式包括JPEG、PNG、GIF、WebP、BMP、SVG、ICO、DNG、HEIF(不同硬件设备支持情况不同)。

## 开发步骤

图片解码相关API的详细介绍请参见：[图片解码接口说明](../../reference/apis-image-kit/js-apis-image.md#imagesource)。

1. 全局导入Image模块。

   ```ts
   import { image } from '@kit.ImageKit';
   ```

2. 获取图片。
   - 方法一：获取沙箱路径。具体请参考[获取应用文件路径](../../application-models/application-context-stage.md#获取应用文件路径)。应用沙箱的介绍及如何向应用沙箱推送文件，请参考[文件管理](../../file-management/app-sandbox-directory.md)。

      ```ts
      const context : Context = getContext(this);
      const filePath : string = context.cacheDir + '/test.jpg';
      ```

   - 方法二：通过沙箱路径获取图片的文件描述符。具体请参考[file.fs API参考文档](../../reference/apis-core-file-kit/js-apis-file-fs.md)。
      该方法需要先导入\@kit.CoreFileKit模块。

      ```ts
      import { fileIo as fs } from '@kit.CoreFileKit';
      ```

      然后调用fs.openSync()获取文件描述符。
  
      ```ts
      const context = getContext(this);
      const filePath = context.cacheDir + '/test.jpg';
      const file : fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
      const fd : number = file?.fd;
      ```

   - 方法三：通过资源管理器获取资源文件的ArrayBuffer。具体请参考[ResourceManager API参考文档](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfilecontent9-1)。

      ```ts
      // 导入resourceManager资源管理器。
      import { resourceManager } from '@kit.LocalizationKit';

      const context : Context = getContext(this);
      // 获取resourceManager资源管理器。
      const resourceMgr : resourceManager.ResourceManager = context.resourceManager;
      ```

      不同模型获取资源管理器的方式不同，获取资源管理器后，再调用resourceMgr.getRawFileContent()获取资源文件的ArrayBuffer。

      ```ts
      resourceMgr.getRawFileContent('test.jpg').then((fileData : Uint8Array) => {
         console.log("Succeeded in getting RawFileContent")
         // 获取图片的ArrayBuffer。
         const buffer = fileData.buffer.slice(0);
      }).catch((err : BusinessError) => {
         console.error("Failed to get RawFileContent")
      });
      
      ```

   - 方法四：通过资源管理器获取资源文件的RawFileDescriptor。具体请参考[ResourceManager API参考文档](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9-1)。

      ```ts
      // 导入resourceManager资源管理器。
      import { resourceManager } from '@kit.LocalizationKit';

      const context : Context = getContext(this);
      // 获取resourceManager资源管理器。
      const resourceMgr : resourceManager.ResourceManager = context.resourceManager;
      ```

      不同模型获取资源管理器的方式不同，获取资源管理器后，再调用resourceMgr.getRawFd()获取资源文件的RawFileDescriptor。

      ```ts
      
      resourceMgr.getRawFd('test.jpg').then((rawFileDescriptor : resourceManager.RawFileDescriptor) => {
         console.log("Succeeded in getting RawFileDescriptor")
      }).catch((err : BusinessError) => {
         console.error("Failed to get RawFileDescriptor")
      });
      ```

3. 创建ImageSource实例。

   - 方法一：通过沙箱路径创建ImageSource。沙箱路径可以通过步骤2的方法一获取。

      ```ts
      // path为已获得的沙箱路径。
      const imageSource : image.ImageSource = image.createImageSource(filePath);
      ```

   - 方法二：通过文件描述符fd创建ImageSource。文件描述符可以通过步骤2的方法二获取。

      ```ts
      // fd为已获得的文件描述符。
      const imageSource : image.ImageSource = image.createImageSource(fd);
      ```

   - 方法三：通过缓冲区数组创建ImageSource。缓冲区数组可以通过步骤2的方法三获取。

      ```ts
      const imageSource : image.ImageSource = image.createImageSource(buffer);
      ```

   - 方法四：通过资源文件的RawFileDescriptor创建ImageSource。RawFileDescriptor可以通过步骤2的方法四获取。

      ```ts
      const imageSource : image.ImageSource = image.createImageSource(rawFileDescriptor);
      ```

4. 设置解码参数DecodingOptions，解码获取pixelMap图片对象。
   - 设置期望的format进行解码：
      ```ts
      import { BusinessError } from '@kit.BasicServicesKit';
      import { image } from '@kit.ImageKit';

      let img = await getContext(this).resourceManager.getMediaContent($r('app.media.image'));
      let imageSource:image.ImageSource = image.createImageSource(img.buffer.slice(0));
      let decodingOptions : image.DecodingOptions = {
         editable: true,
         desiredPixelFormat: 3,
      }
      // 创建pixelMap。
      imageSource.createPixelMap(decodingOptions).then((pixelMap : image.PixelMap) => {
         console.log("Succeeded in creating PixelMap")
      }).catch((err : BusinessError) => {
         console.error("Failed to create PixelMap")
      });
      ```
   - HDR图片解码
      ```ts
      import { BusinessError } from '@kit.BasicServicesKit';
      import { image } from '@kit.ImageKit';

      let img = await getContext(this).resourceManager.getMediaContent($r('app.media.CUVAHdr'));
      let imageSource:image.ImageSource = image.createImageSource(img.buffer.slice(0));
      let decodingOptions : image.DecodingOptions = {
         //设置为AUTO会根据图片资源格式解码，如果图片资源为HDR资源则会解码为HDR的pixelmap。
         desiredDynamicRange: image.DecodingDynamicRange.AUTO,
      }
      // 创建pixelMap。
      imageSource.createPixelMap(decodingOptions).then((pixelMap : image.PixelMap) => {
         console.log("Succeeded in creating PixelMap")
         // 判断pixelmap是否为hdr内容。
         let info = pixelMap.getImageInfoSync();
         console.log("pixelmap isHdr:" + info.isHdr);
      }).catch((err : BusinessError) => {
         console.error("Failed to create PixelMap")
      });
      ```
   解码完成，获取到pixelMap对象后，可以进行后续[图片处理](image-transformation.md)。

5. 释放pixelMap和imageSource。

   需确认pixelMap和imageSource异步方法已经执行完成，不再使用该变量后可按需手动调用下面方法释放。
   ```ts
   pixelMap.release();
   imageSource.release();
   ```

## 开发示例-对资源文件中的图片进行解码

1. 获取resourceManager资源管理。

   ```ts
   // 导入resourceManager资源管理器。
   import { resourceManager } from '@kit.LocalizationKit';

   const context : Context = getContext(this);
   // 获取resourceManager资源管理。
   const resourceMgr : resourceManager.ResourceManager = context.resourceManager;
   ```

2. 创建ImageSource。
   - 方式一：通过rawfile文件夹下test.jpg的ArrayBuffer创建。

     ```ts
      import { BusinessError } from '@kit.BasicServicesKit';

      resourceMgr.getRawFileContent('test.jpg').then((fileData : Uint8Array) => {
         console.log("Succeeded in getting RawFileContent")
         // 获取图片的ArrayBuffer。
         const buffer = fileData.buffer.slice(0);
         const imageSource : image.ImageSource = image.createImageSource(buffer);
      }).catch((err : BusinessError) => {
         console.error("Failed to get RawFileContent")
      });
     ```

   - 方式二：通过rawfile文件夹下test.jpg的RawFileDescriptor创建。

     ```ts
      import { BusinessError } from '@kit.BasicServicesKit';

      resourceMgr.getRawFd('test.jpg').then((rawFileDescriptor : resourceManager.RawFileDescriptor) => {
         console.log("Succeeded in getting RawFd")
         const imageSource : image.ImageSource = image.createImageSource(rawFileDescriptor);
      }).catch((err : BusinessError) => {
         console.error("Failed to get RawFd")
      });
     ```

3. 创建pixelMap。

   ```ts
   imageSource.createPixelMap().then((pixelMap: image.PixelMap) => {
      console.log("Succeeded in creating PixelMap")
   }).catch((err : BusinessError) => {
      console.error("Failed to creating PixelMap")
   });
   ```

4. 释放pixelMap和imageSource。
   
   需确认pixelMap和imageSource异步方法已经执行完成，不再使用该变量后可按需手动调用下面方法释放。
   ```ts
   pixelMap.release();
   imageSource.release();
   ```

## 相关实例

针对图片解码开发，有以下相关实例可供参考：

- [图片编辑（ArkTS）](https://gitee.com/openharmony/codelabs/tree/master/Media/ImageEdit)

- [图片编辑（JS）](https://gitee.com/openharmony/codelabs/tree/master/Media/ImageEditorTemplate)

<!--RP1-->
<!--RP1End-->
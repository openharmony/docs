# 图片解码(ArkTS)

图片解码指将所支持格式的存档图片解码成统一的[PixelMap](image-overview.md)，以便在应用或系统中进行图片显示或[图片处理](image-transformation.md)。当前支持的存档图片格式包括JPEG、PNG、GIF、RAW、WebP、BMP、SVG。

## 开发步骤

图片解码相关API的详细介绍请参见：[图片解码接口说明](../reference/apis/js-apis-image.md#imagesource)。

1. 全局导入Image模块。
     
   ```ts
   import image from '@ohos.multimedia.image';
   ```

2. 获取图片。
   - 方法一：获取沙箱路径。具体请参考[获取应用文件路径](../application-models/application-context-stage.md#获取应用文件路径)。应用沙箱的介绍及如何向应用沙箱推送文件，请参考[文件管理](../file-management/app-sandbox-directory.md)。
        
      ```ts
      // Stage模型参考如下代码
      const context : Context = getContext(this);
      const filePath : string = context.cacheDir + '/test.jpg';
      ```

      ```ts
      // FA模型参考如下代码
      import featureAbility from '@ohos.ability.featureAbility';
      
      const context = featureAbility.getContext();
      const filePath = context.getCacheDir() + "/test.jpg";
      ```
   - 方法二：通过沙箱路径获取图片的文件描述符。具体请参考[file.fs API参考文档](../reference/apis/js-apis-file-fs.md)。
      该方法需要先导入\@ohos.file.fs模块。

      ```ts
      import fs from '@ohos.file.fs';
      ```

      然后调用fs.openSync()获取文件描述符。
  
      ```ts
      // Stage模型参考如下代码
      const context = getContext(this);
      const filePath = context.cacheDir + '/test.jpg';
      const file : fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
      const fd : number = file?.fd;
      ```

      ```ts
      // FA模型参考如下代码
      import featureAbility from '@ohos.ability.featureAbility';
      
      const context = featureAbility.getContext();
      const filePath = context.getCacheDir() + "/test.jpg";
      const file : fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
      const fd : number = file?.fd;
      ```
   - 方法三：通过资源管理器获取资源文件的ArrayBuffer。具体请参考[ResourceManager API参考文档](../reference/apis/js-apis-resource-manager.md#getrawfilecontent9-1)。
        
      ```ts
      // Stage模型
      const context : Context = getContext(this);
      // 获取resourceManager资源管理器
      const resourceMgr : resourceManager.ResourceManager = context.resourceManager;
      ```

      ```ts
      // FA模型
      // 导入resourceManager资源管理器
      import resourceManager from '@ohos.resourceManager';
      import {BusinessError} from '@ohos.base';
      resourceManager.getResourceManager().then((resourceMgr : resourceManager.ResourceManager) => {
         console.log("Succeeded in getting resourceManager")
      }).catch((err : BusinessError) => {
         console.error("Failed to get resourceManager")
      });
      ```

      不同模型获取资源管理器的方式不同，获取资源管理器后，再调用resourceMgr.getRawFileContent()获取资源文件的ArrayBuffer。

      ```ts
      resourceMgr.getRawFileContent('test.jpg').then((fileData : Uint8Array) => {
         console.log("Succeeded in getting RawFileContent")
         // 获取图片的ArrayBuffer
         const buffer = fileData.buffer;
      }).catch((err : BusinessError) => {
         console.error("Failed to get RawFileContent")
      });
      
      ```
   - 方法四：通过资源管理器获取资源文件的RawFileDescriptor。具体请参考[ResourceManager API参考文档](../reference/apis/js-apis-resource-manager.md#getrawfd9-1)。
        
      ```ts
      // Stage模型
      const context : Context = getContext(this);
      // 获取resourceManager资源管理器
      const resourceMgr : resourceManager.ResourceManager = context.resourceManager;
      ```

      ```ts
      // FA模型
      // 导入resourceManager资源管理器
      import resourceManager from '@ohos.resourceManager';
      import {BusinessError} from '@ohos.base';
      resourceManager.getResourceManager().then((resourceMgr : resourceManager.ResourceManager) => {
         console.log("Succeeded in getting resourceManager")
      }).catch((err : BusinessError) => {
         console.error("Failed to get resourceManager")
      });
      ```

      不同模型获取资源管理器的方式不同，获取资源管理器后，再调用resourceMgr.getRawFd()获取资源文件的RawFileDescriptor。

      ```ts
      
      resourceMgr.getRawFd('test.jpg').then((rawFileDescriptor : resourceManager.RawFileDescriptor) => {
         console.log("Succeeded in getting resourceManager")
      }).catch((err : BusinessError) => {
         console.error("Failed to get resourceManager")
      });
      ```


3. 创建ImageSource实例。
   - 方法一：通过沙箱路径创建ImageSource。沙箱路径可以通过步骤2的方法一获取。
        
      ```ts
      // path为已获得的沙箱路径
      const imageSource : image.ImageSource = image.createImageSource(filePath);
      ```
   - 方法二：通过文件描述符fd创建ImageSource。文件描述符可以通过步骤2的方法二获取。
        
      ```ts
      // fd为已获得的文件描述符
      const imageSource : image.ImageSource = image.createImageSource(fd);
      ```
   - 方法三：通过缓冲区数组创建ImageSource。缓冲区数组可以通过步骤2的方法三获取。
        
      ```ts
      const imageSource : image.ImageSource = image.createImageSource(buffer);
      ```
   - 方法四：通过资源文件的RawFileDescriptor创建ImageSource。RawFileDescriptor可以通过步骤2的方案四获取。
        
      ```ts
      const imageSource : image.ImageSource = image.createImageSource(rawFileDescriptor);
      ```

4. 设置解码参数DecodingOptions，解码获取PixelMap图片对象。
     
   ```ts
   import {BusinessError} from '@ohos.base';
   let decodingOptions : image.DecodingOptions = {
       editable: true,
       desiredPixelFormat: 3,
   }
   // 创建pixelMap并进行简单的旋转和缩放 
   imageSource.createPixelMap(decodingOptions).then((pixelMap : image.PixelMap) => {
      console.log("Succeeded in creating PixelMap")
   }).catch((err : BusinessError) => {
      console.error("Failed to create PixelMap")
   });
   ```

   解码完成，获取到PixelMap对象后，可以进行后续[图片处理](image-transformation.md)。

5. 释放pixelMap。
   ```ts
   pixelMap.release();
   ```

## 开发示例-对资源文件中的图片进行解码

1. 获取resourceManager资源管理。
     
   ```ts
   const context : Context = getContext(this);
   // 获取resourceManager资源管理
   const resourceMgr : resourceManager.ResourceManager = context.resourceManager;
   ```

2. 创建ImageSource。
   - 通过rawfile文件夹下test.jpg的ArrayBuffer创建。
     ```ts
      resourceMgr.getRawFileContent('test.jpg').then((fileData : Uint8Array) => {
         console.log("Succeeded in getting RawFileContent")
         // 获取图片的ArrayBuffer
         const buffer = fileData.buffer;
         const imageSource : image.ImageSource = image.createImageSource(buffer);
      }).catch((err : BusinessError) => {
         console.error("Failed to get RawFileContent")
      });
     ```

   - 通过rawfile文件夹下test.jpg的RawFileDescriptor创建。
     ```ts
      resourceMgr.getRawFd('test.jpg').then((rawFileDescriptor : resourceManager.RawFileDescriptor) => {
         console.log("Succeeded in getting RawFd")
         const imageSource : image.ImageSource = image.createImageSource(rawFileDescriptor);
      }).catch((err : BusinessError) => {
         console.error("Failed to get RawFd")
      });
     ```
3. 创建PixelMap。
     
   ```ts
   imageSource.createPixelMap().then((image.PixelMap) => {
      console.log("Succeeded in creating PixelMap")
      const imageSource : image.ImageSource = image.createImageSource(rawFileDescriptor);
   }).catch((err : BusinessError) => {
      console.error("Failed to creating PixelMap")
   });
   ```

4. 释放pixelMap。
   ```ts
   pixelMap.release();
   ```

## 相关实例

针对图片解码开发，有以下相关实例可供参考：

- [图片编辑（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/Media/ImageEdit)

- [图片编辑（JS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/Media/ImageEditorTemplate)
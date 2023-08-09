# 图片解码

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
      const context = getContext(this);
      const filePath = context.cacheDir + '/test.jpg';
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
      const file = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
      const fd = file?.fd;
      ```

      ```ts
      // FA模型参考如下代码
      import featureAbility from '@ohos.ability.featureAbility';
      
      const context = featureAbility.getContext();
      const filePath = context.getCacheDir() + "/test.jpg";
      const file = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
      const fd = file?.fd;
      ```
   - 方法三：通过资源管理器获取资源文件的ArrayBuffer。具体请参考[ResourceManager API参考文档](../reference/apis/js-apis-resource-manager.md#getrawfilecontent9-1)。
        
      ```ts
      // Stage模型
      const context = getContext(this);
      // 获取resourceManager资源管理器
      const resourceMgr = context.resourceManager;
      ```

      ```ts
      // FA模型
      // 导入resourceManager资源管理器
      import resourceManager from '@ohos.resourceManager';
      const resourceMgr = await resourceManager.getResourceManager();
      ```

      不同模型获取资源管理器的方式不同，获取资源管理器后，再调用resourceMgr.getRawFileContent()获取资源文件的ArrayBuffer。

      ```ts
      const fileData = await resourceMgr.getRawFileContent('test.jpg');
      // 获取图片的ArrayBuffer
      const buffer = fileData.buffer;
      ```

3. 创建ImageSource实例。
   - 方法一：通过沙箱路径创建ImageSource。沙箱路径可以通过步骤2的方法一获取。
        
      ```ts
      // path为已获得的沙箱路径
      const imageSource = image.createImageSource(filePath);
      ```
   - 方法二：通过文件描述符fd创建ImageSource。文件描述符可以通过步骤2的方法二获取。
        
      ```ts
      // fd为已获得的文件描述符
      const imageSource = image.createImageSource(fd);
      ```
   - 方法三：通过缓冲区数组创建ImageSource。缓冲区数组可以通过步骤2的方法三获取。
        
      ```ts
      const imageSource = image.createImageSource(buffer);
      ```

4. 设置解码参数DecodingOptions，解码获取PixelMap图片对象。
     
   ```ts
   let decodingOptions = {
       editable: true,
       desiredPixelFormat: 3,
   }
   // 创建pixelMap并进行简单的旋转和缩放 
   const pixelMap = await imageSource.createPixelMap(decodingOptions);
   ```

   解码完成，获取到PixelMap对象后，可以进行后续[图片处理](image-transformation.md)。

## 开发示例-对资源文件中的图片进行解码

1. 获取resourceManager资源管理。
     
   ```ts
   const context = getContext(this);
   // 获取resourceManager资源管理
   const resourceMgr = context.resourceManager;
   ```

2. 获取rawfile文件夹下test.jpg的ArrayBuffer。
     
   ```ts
   const fileData = await resourceMgr.getRawFileContent('test.jpg');
   // 获取图片的ArrayBuffer
   const buffer = fileData.buffer;
   ```

3. 创建imageSource。
     
   ```ts
   const imageSource = image.createImageSource(buffer);
   ```

4. 创建PixelMap。
     
   ```ts
   const pixelMap = await imageSource.createPixelMap();
   ```

## 相关实例

针对图片解码开发，有以下相关实例可供参考：

- [图片编辑（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/Media/ImageEdit)

- [图片编辑（JS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/Media/ImageEditorTemplate)

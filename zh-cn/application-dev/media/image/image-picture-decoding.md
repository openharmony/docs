# 使用ImageSource完成多图对象解码

图片解码指将所支持格式的存档图片解码成统一的[Picture](image-overview.md)。当前支持的存档图片格式包括JPEG、HEIF。

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
      import { fileIo } from '@kit.CoreFileKit';
      ```

      然后调用fileIo.openSync()获取文件描述符。
  
      ```ts
      const context = getContext(this);
      const filePath = context.cacheDir + '/test.jpg';
      const file : fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
      const fd : number = file?.fd;
      ```

   - 方法三：通过资源管理器获取资源文件的ArrayBuffer。具体请参考[ResourceManager API参考文档](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfilecontent9-1)。

      ```ts
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

4. 设置解码参数DecodingOptions，解码获取picture多图对象。

   设置期望的format进行解码：
      ```ts
      import { BusinessError } from '@kit.BasicServicesKit';
      import image from '@kit.ImageKit';
      let img = await getContext(this).resourceManager.getMediaContent($r('app.media.picture'));
      let imageSource:image.ImageSource = image.createImageSource(img.buffer.slice(0));
      let options: image.DecodingOptionsForPicture = {
         desiredAuxiliaryPictures: [image.AuxiliaryPictureType.GAINMAP] // GAINMAP为需要解码的辅助图类型。
      };
      // 创建picture。
      imageSource.createPicture(options).then((picture: image.Picture) => {
         console.log("Create picture succeeded.")
      }).catch((err: BusinessError) => {
         console.error("Create picture failed.")
      });
      ```

5. 对picture进行操作，如获取辅助图等。对于picture和辅助图的操作具体请参考[Image API参考文档](../../reference/apis-image-kit/js-apis-image.md#picture13)。

   ```ts
   // 获取辅助图对象。
   let type: image.AuxiliaryPictureType = image.AuxiliaryPictureType.GAINMAP;
   let auxPicture: image.AuxiliaryPicture | null = picture.getAuxiliaryPicture(type);
   // 获取辅助图信息。
   let auxinfo: image.AuxiliaryPictureInfo = auxPicture.getAuxiliaryPictureInfo();
   console.info('GetAuxiliaryPictureInfo Type: ' + auxinfo.auxiliaryPictureType +
      ' height: ' + auxinfo.size.height + ' width: ' + auxinfo.size.width +
      ' rowStride: ' +  auxinfo.rowStride +  ' pixelFormat: ' + auxinfo.pixelFormat +
      ' colorSpace: ' +  auxinfo.colorSpace);
   // 将辅助图数据读到ArrayBuffer。
   auxPicture.readPixelsToBuffer().then((pixelsBuffer: ArrayBuffer) => {
      console.info('Read pixels to buffer success.');
   }).catch((error: BusinessError) => {
      console.error('Read pixels to buffer failed error.code: ' + JSON.stringify(error.code) + ' ,error.message:' + JSON.stringify(error.message));
   });
   auxPicture.release();
   ```

6. 释放picture。

   ```ts
   picture.release();
   ```

## 开发示例-解码资源文件中的图片

1. 获取resourceManager资源管理。

   ```ts
   const context : Context = getContext(this);
   // 获取resourceManager资源管理。
   const resourceMgr : resourceManager.ResourceManager = context.resourceManager;
   ```

2. 创建ImageSource。
   - 通过rawfile文件夹下test.jpg的ArrayBuffer创建。

     ```ts
      resourceMgr.getRawFileContent('test.jpg').then((fileData : Uint8Array) => {
         console.log("Succeeded in getting RawFileContent")
         // 获取图片的ArrayBuffer。
         const buffer = fileData.buffer.slice(0);
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

3. 创建picture。

   ```ts
   let options: image.DecodingOptionsForPicture = {
      desiredAuxiliaryPictures: [image.AuxiliaryPictureType.GAINMAP] // GAINMAP为需要解码的辅助图类型。
   };
   imageSource.createPicture(options).then((picture: image.Picture) => {
      console.log("Create picture succeeded.")
   }).catch((err : BusinessError) => {
      console.error("Create picture failed.")
   });
   ```

4. 对picture进行操作，如获取辅助图等。对于picture和辅助图的操作具体请参考[Image API参考文档](../../reference/apis-image-kit/js-apis-image.md#picture13)。

   ```ts
   // 获取辅助图对象。
   let type: image.AuxiliaryPictureType = image.AuxiliaryPictureType.GAINMAP;
   let auxPicture: image.AuxiliaryPicture | null = picture.getAuxiliaryPicture(type);
   // 获取辅助图信息。
   let auxinfo: image.AuxiliaryPictureInfo = auxPicture.getAuxiliaryPictureInfo();
   console.info('GetAuxiliaryPictureInfo Type: ' + auxinfo.auxiliaryPictureType +
      ' height: ' + auxinfo.size.height + ' width: ' + auxinfo.size.width +
      ' rowStride: ' +  auxinfo.rowStride +  ' pixelFormat: ' + auxinfo.pixelFormat +
      ' colorSpace: ' +  auxinfo.colorSpace);
   // 将辅助图数据写入ArrayBuffer。
   auxPicture.readPixelsToBuffer().then((pixelsBuffer: ArrayBuffer) => {
      console.info('Read pixels to buffer success.');
   }).catch((error: BusinessError) => {
      console.error('Read pixels to buffer failed error.code: ' + JSON.stringify(error.code) + ' ,error.message:' + JSON.stringify(error.message));
   });
   auxPicture.release();
   ```

5. 释放picture。

   ```ts
   picture.release();
   ```
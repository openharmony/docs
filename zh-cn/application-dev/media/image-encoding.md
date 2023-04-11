# 图片编码

图片编码指将PixelMap编码成不同格式的存档图片（当前仅支持打包为JPEG和WebP格式），用于后续处理，如保存、传输等。

## 开发步骤

图片编码相关API的详细介绍请参见：[图片编码接口说明](../reference/apis/js-apis-image.md#imagepacker)。

1. 创建图像编码ImagePacker对象。
     
   ```ts
   // 导入相关模块包
   import image from '@ohos.multimedia.image';
   
   const imagePackerApi = image.createImagePacker();
   ```

2. 设置编码输出流和编码参数。
   
   format为图像的编码格式；quality为图像质量，范围从0-100，100为最佳质量。

   ```ts
   let packOpts = { format:"image/jpeg", quality:98 };
   ```

3. [创建PixelMap对象或创建ImageSource](image-decoding.md)对象。

4. 进行图片编码，并保存编码后的图片。
   
   方法一：通过PixelMap进行编码。

   ```ts
   imagePackerApi.packing(pixelMap, packOpts).then( data => {
     // data 为打包获取到的文件流，写入文件保存即可得到一张图片
   }).catch(error => { 
     console.error('Failed to pack the image. And the error is: ' + error); 
   })
   ```

   方法二：通过imageSource进行编码。

   ```ts
   imagePackerApi.packing(imageSource, packOpts).then( data => {
       // data 为打包获取到的文件流，写入文件保存即可得到一张图片
   }).catch(error => { 
     console.error('Failed to pack the image. And the error is: ' + error); 
   })
   ```

# 图片工具

图片工具当前主要提供图片EXIF信息的读取与编辑能力。

EXIF（Exchangeable image file format）是专门为数码相机的照片设定的文件格式，可以记录数码照片的属性信息和拍摄数据。当前仅支持JPEG格式图片。

在图库等应用中，需要查看或修改数码照片的EXIF信息。由于摄像机的手动镜头的参数无法自动写入到EXIF信息中或者因为相机断电等原因经常会导致拍摄时间出错，这时候就需要手动修改错误的EXIF数据，即可使用本功能。

OpenHarmony目前仅支持对部分EXIF信息的查看和修改，具体支持的范围请参见：[EIXF信息](../reference/apis/js-apis-image.md#propertykey7)。

## 开发步骤

EXIF信息的读取与编辑相关API的详细介绍请参见[API参考](../reference/apis/js-apis-image.md#getimageproperty7)。

1. 获取图片，创建图片源ImageSource。
     
   ```ts
   // 导入相关模块包
   import image from '@ohos.multimedia.image';
   
   // 获取沙箱路径创建ImageSource
   const fd = ...; // 获取需要被处理的图片的fd
   const imageSource = image.createImageSource(fd);
   ```

2. 读取、编辑EXIF信息。
     
   ```ts
   // 读取EXIF信息，BitsPerSample为每个像素比特数
   imageSource.getImageProperty('BitsPerSample', (error, data) => {
     if (error) {
       console.error('Failed to get the value of the specified attribute key of the image.And the error is: ' + error);
     } else {
       console.info('Succeeded in getting the value of the specified attribute key of the image ' + data);
     }
   })
   
   // 编辑EXIF信息
   imageSource.modifyImageProperty('ImageWidth', '120').then(() => {
     const width = imageSource.getImageProperty("ImageWidth");
     console.info('The new imageWidth is ' + width);
   })
   ```

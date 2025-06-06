# 如何处理HEIF图片

## HEIF图片介绍

HEIF图片（High Efficiency Image File Format，HEIF，也称高效图像文件格式），是一个用于单张图像或图像序列的文件格式。它由动态影像专家小组（MPEG）开发，并在MPEG-H Part 12（ISO/IEC 23008-12）中定义。

目前主流的HEIF图片格式均使用HEVC(H.265)编码，这也是系统支持的HEIF图片。

系统从API12开始支持HEIF图片的编解码与显示，如果应用基于系统Image Kit、ArkUI Image组件、ArkWeb等模块实现图片处理功能，则可以像处理JPEG、PNG等格式的图片一样，处理HEIF图片。

HEIF图片解码可参考：[图片解码指南（ArkTS）](../image-decoding.md)和[图片解码指南（C/C++）](../image-source-c.md)。

HEIF图片显示可参考：[ArkUI Image组件图片显示](../../../ui/arkts-graphics-display.md)。

HEIF图片编码可参考：[图片编码指南（ArkTS）](../image-encoding.md)和[图片编码指南（C/C++）](../image-packer-c.md)。

ArkWeb图片上传可参考：[使用Web组件上传文件](../../../web/web-file-upload.md)。

## 常见问题

### 上传HEIF图片时提示：“不支持的格式”

一般是由于应用对后缀名为.heic、.heif、.HEIC、.HEIF的图片文件做了过滤限制。

对于使用系统图片处理能力的应用，只需要解除过滤限制，即可正常上传、显示HEIF图片。

如果应用没有使用系统提供的图片处理能力，则可能需要做更多适配，一个可选的方案是将HEIF图片转码成JPEG图片。

### 担心使用HEIF格式图片存在兼容性问题，需使用JPEG或PNG格式的图片，如何操作

可以借助Image Kit的图片编解码能力，将HEIF图片转码成JPEG图片，示例代码如下：
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { image } from '@kit.ImageKit';


let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// 首先获取图片文件的fd，创建ImageSource。
let fd = 0; 
const imageSource : image.ImageSource = image.createImageSource(fd);
// 创建ImagePacker，以便调用图片编码接口。
const imagePackerApi = image.createImagePacker();
// 配置图片编码选项：
// format应使用标准的mimetype格式，如："image/jpeg"、"image/png"、"image/heic"；
// quality推荐设置为80，在保证较好的图片质量的同时，可以使编码后的图片文件体积更小；
// needsPackProperties参数设为true，编码时保存图片属性信息，如包含图片旋转方向的EXIF信息。
let packOpts : image.PackingOption = { format:"image/jpeg", quality:80, needsPackProperties:true };
// 指定图片编码文件的存放路径。
const filePath : string = context.cacheDir + "/result.jpg";
let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
imagePackerApi.packToFile(imageSource, file.fd, packOpts).then(() => {
    console.info('Succeed to pack the image.'); 
}).catch((error : BusinessError) => { 
    console.error('Failed to pack the image. And the error is: ' + error); 
}).finally(()=>{
    fs.closeSync(file.fd);
})
```
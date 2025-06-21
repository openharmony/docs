# 编辑图片EXIF信息

Image Kit提供图片EXIF信息的读取与编辑能力。

EXIF（Exchangeable image file format）是专门为数码相机的照片设定的文件格式，可以记录数码照片的属性信息和拍摄数据。当前仅支持JPEG格式图片。

在图库等应用中，需要查看或修改数码照片的EXIF信息。由于摄像机的手动镜头参数无法自动写入到EXIF信息中或者因为相机断电等原因会导致拍摄时间出错，这时需要手动修改错误的EXIF数据，即可使用本功能。

OpenHarmony目前仅支持对部分EXIF信息的查看和修改，具体支持的范围请参见：[Exif信息](../../reference/apis-image-kit/arkts-apis-image-e.md#propertykey7)。

## 开发步骤

EXIF信息的读取与编辑相关API的详细介绍请参见[API参考](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#getimageproperty11)。

获取图片，创建ImageSource。读取、编辑EXIF信息。示例代码如下：

    ```ts
    // 导入相关模块包。
    import { image } from '@kit.ImageKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    // 获取沙箱路径创建ImageSource。
    const fd : number = 0; // 获取需要被处理的图片的fd。
    const imageSourceApi : image.ImageSource = image.createImageSource(fd);

    // 读取EXIF信息，BitsPerSample为每个像素比特数。
    let options : image.ImagePropertyOptions = { index: 0, defaultValue: 'This key has no value!' };
    imageSourceApi.getImageProperty(image.PropertyKey.BITS_PER_SAMPLE, options).then((data : string) => {
        console.info('Succeeded in getting the value of the specified attribute key of the image.');
    }).catch((error : BusinessError) => {
        console.error('Failed to get the value of the specified attribute key of the image.');
    })

    // 编辑EXIF信息。
    imageSourceApi.modifyImageProperty(image.PropertyKey.IMAGE_WIDTH, "120").then(() => {
        imageSourceApi.getImageProperty(image.PropertyKey.IMAGE_WIDTH).then((width : string) => {
            console.info('The new imageWidth is ' + width);
        }).catch((error : BusinessError) => {
            console.error('Failed to get the Image Width.');
        })
    }).catch((error : BusinessError) => {
        console.error('Failed to modify the Image Width');
    })
    ```

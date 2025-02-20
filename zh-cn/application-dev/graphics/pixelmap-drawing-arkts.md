# 图片绘制（ArkTS）


位图是一种用于在内存中存储和表示图像的数据结构，它是一个未经过压缩的像素集合，而JPEG或PNG等格式的图片是压缩格式的，两者并不相同。如果需要将JPEG或PNG绘制到屏幕上，需要先解码成位图格式，具体可参考[图片处理服务（Image Kit）](../media/image/image-overview.md)图片解码相关章节。


目前Drawing（ArkTS）中位图绘制需要依赖PixelMap，它可以用于读取或写入图像数据以及获取图像信息。详细的API介绍请参考[PixelMap](../reference/apis-image-kit/js-apis-image.md#pixelmap7)。


1. 创建PixelMap。

   有多个API接口可以创建PixelMap，下文以createPixelMapSync()为例。更多创建方式和接口请见[@ohos.multimedia.image (图片处理)](../reference/apis-image-kit/js-apis-image.md)模块。

   createPixelMapSync()函数接受两个参数，第一个参数为图像像素数据的缓冲区，用于初始化PixelMap的像素。第二个参数为创建像素的属性，包括透明度、尺寸、缩略值、像素格式和是否可编辑。

   ```ts
   // 图片宽高
   let width = 600;
   let height = 400;
   // 字节长度，RGBA_8888每个像素占4字节
   let bytelength = width * height * 4;
   const color: ArrayBuffer = new ArrayBuffer(bytelength);
   let bufferArr = new Uint8Array(color);
   for (let i = 0; i < bufferArr.length; i += 4) {
     // 遍历并编辑每个像素，从而形成红绿蓝相间的条纹
     bufferArr[i] = 0x00;
     bufferArr[i+1] = 0x00;
     bufferArr[i+2] = 0x00;
     bufferArr[i+3] = 0xFF;
     let n = Math.floor(i / 80) % 3;
     if (n == 0) {
       bufferArr[i] = 0xFF;
     } else if (n == 1) {
       bufferArr[i+1] = 0xFF;
     } else {
       bufferArr[i+2] = 0xFF;
     }
   }
   // 设置像素属性
   let opts: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: height, width: width }}
   // 创建PixelMap
   let pixelMap : image.PixelMap = image.createPixelMapSync(color, opts);
   ```

2. （可选）编辑PixelMap中的像素。如果没有编辑像素的需求，此步骤可以省略。

   有多个API接口可以编辑PixelMap中的像素，下文以writePixelsSync()为例。更多方式和接口的使用可见[PixelMap](../reference/apis-image-kit/js-apis-image.md#pixelmap7)。

   ```ts
   // 设置编辑区域的宽高
   let inner_width = 400;
   let inner_height = 200;
   // 编辑区域的字节长度，RGBA_8888每个像素占4字节
   let inner_bytelength = inner_width * inner_height * 4;
   const inner_color: ArrayBuffer = new ArrayBuffer(inner_bytelength);
   let inner_bufferArr = new Uint8Array(inner_color);
   for (let i = 0; i < inner_bufferArr.length; i += 4) {
     // 编辑区域的像素都设置为黑白相间条纹
     let n = Math.floor(i / 80) % 2;
     if (n == 0) {
       inner_bufferArr[i] = 0x00;
       inner_bufferArr[i+1] = 0x00;
       inner_bufferArr[i+2] = 0x00;
     } else {
       inner_bufferArr[i] = 0xFF;
       inner_bufferArr[i+1] = 0xFF;
       inner_bufferArr[i+2] = 0xFF;
     }
     inner_bufferArr[i+3] = 0xFF;
   }
   // 设置编辑区域的像素、宽高、偏移量等
   const area: image.PositionArea = {
     pixels: inner_color,
     offset: 0,
     stride: inner_width * 4,
     region: { size: { height: inner_height, width: inner_width }, x: 100, y: 100 }
   };
   // 编辑位图，形成中间的黑白相间条纹
   pixelMap.writePixelsSync(area);
   ```

3. 绘制PixelMap。

   绘制PixelMap时需要通过Canva相关接口绘制位图，下文以drawImage()为例。更多方式和接口的使用请见[drawing.Canvas](../reference/apis-arkgraphics2d/js-apis-graphics-drawing.md#canvas)。

   drawImage()函数接受4个参数，第一个就是上文中创建的PixelMap，第二个是绘制图片位置的左上角x轴坐标，第三个是左上角y轴坐标，第四个为采样选项对象，默认为不使用任何参数构造的原始采样选项对象。

   ```ts
   canvas.drawImage(pixelMap, 300, 300);
   ```

   绘制效果如下：

   ![zh-cn_image_0000002158584414](figures/zh-cn_image_0000002158584414.png)

# 使用ImageReceiver完成图片接收
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

图片接收类ImageReceiver用于获取组件surface id，接收最新的图片和读取下一张图片，以及释放ImageReceiver实例。

> **说明：**
> Receiver作为消费者，需要有对应的生产者提供数据才能实现完整功能。常见的生产者是相机的拍照流或预览流。ImageReceiver只作为图片的接收方、消费者，在ImageReceiver设置的size、format等属性实际上并不会生效，图片createImageReceiver时传入的参数不产生实际影响。图片属性需要在发送方、生产者进行设置，如[相机创建预览流](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput)时配置[profile](../../reference/apis-camera-kit/arkts-apis-camera-i.md#profile)。

ImageReceiver可以接收相机预览流中的图片，实现[双路预览](../camera/camera-dual-channel-preview.md)。

ImageReceiver信息相关API的详细介绍请参见[API参考](../../reference/apis-image-kit/arkts-apis-image-ImageReceiver.md)。

## 开发步骤

创建ImageReceiver对象，获取SurfaceId创建预览流，注册图像监听，按需处理预览流每帧图像。

1. 创建ImageReceiver对象，通过ImageReceiver对象可获取预览流SurfaceId。

    ```ts
    import { image } from '@kit.ImageKit';
    let imageWidth: number = 1920; // 请使用设备支持profile的size的宽。
    let imageHeight: number = 1080; // 请使用设备支持profile的size的高。

    async function initImageReceiver():Promise<void>{
      // 创建ImageReceiver对象。createImageReceiver的参数不会对接收到的数据产生实际影响。
      let size: image.Size = { width: imageWidth, height: imageHeight };
      let imageReceiver = image.createImageReceiver(size, image.ImageFormat.JPEG, 8);
      // 获取预览流SurfaceId。
      let imageReceiverSurfaceId = await imageReceiver.getReceivingSurfaceId();
      console.info(`initImageReceiver imageReceiverSurfaceId:${imageReceiverSurfaceId}`);
    }
    ```

2. 注册监听处理预览流每帧图像数据：通过ImageReceiver组件中imageArrival事件监听获取底层返回的图像数据，详细的API说明请参考[Image API参考](../../reference/apis-image-kit/arkts-apis-image-ImageReceiver.md)。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { image } from '@kit.ImageKit';

    function onImageArrival(receiver: image.ImageReceiver): void {
      // 注册imageArrival监听。
      receiver.on('imageArrival', () => {
        // 获取图像。
        receiver.readNextImage((err: BusinessError, nextImage: image.Image) => {
          if (err || nextImage === undefined) {
            console.error('readNextImage failed');
            return;
          }
          // 解析图像内容。
          nextImage.getComponent(image.ComponentType.JPEG, async (err: BusinessError, imgComponent: image.Component) => {
            if (err || imgComponent === undefined) {
              console.error('getComponent failed');
            }
            if (imgComponent.byteBuffer) {
              // 详情见下方解析图片buffer数据参考，本示例以方式一为例。
              let width = nextImage.size.width; // 获取图片的宽。
              let height = nextImage.size.height; // 获取图片的高。
              let stride = imgComponent.rowStride; // 获取图片的stride。
              console.debug(`getComponent with width:${width} height:${height} stride:${stride}`);
              // stride与width一致。
              if (stride == width) {
                let pixelMap = await image.createPixelMap(imgComponent.byteBuffer, {
                  size: { height: height, width: width },
                  srcPixelFormat: 8,
                })
              } else {
                // stride与width不一致。
                const dstBufferSize = width * height * 1.5
                const dstArr = new Uint8Array(dstBufferSize)
                for (let j = 0; j < height * 1.5; j++) {
                  const srcBuf = new Uint8Array(imgComponent.byteBuffer, j * stride, width)
                  dstArr.set(srcBuf, j * width)
                }
                let pixelMap = await image.createPixelMap(dstArr.buffer, {
                  size: { height: height, width: width },
                  srcPixelFormat: 8,
                })
              }
            } else {
              console.error('byteBuffer is null');
            }
            // 确保当前buffer没有在使用的情况下，可进行资源释放。
            // 如果对buffer进行异步操作，需要在异步操作结束后再释放该资源（nextImage.release()）。
            nextImage.release();
          })
        })
      })
    }
    ```


    通过 [image.Component](../../reference/apis-image-kit/arkts-apis-image-i.md#component9) 解析图片buffer数据参考：

    > **注意：**
    > 需要确认图像的宽width是否与行距rowStride一致，如果不一致可参考以下方式处理：

    方式一：去除imgComponent.byteBuffer中stride数据，拷贝得到新的buffer，调用不支持stride的接口处理buffer。

    ```ts
    // 以NV21为例（YUV_420_SP格式的图片）YUV_420_SP内存计算公式：长x宽+(长x宽)/2。
    const dstBufferSize = width * height * 1.5;
    const dstArr = new Uint8Array(dstBufferSize);
    // 逐行读取buffer数据。
    for (let j = 0; j < height * 1.5; j++) {
      // imgComponent.byteBuffer的每行数据拷贝前width个字节到dstArr中。
      const srcBuf = new Uint8Array(imgComponent.byteBuffer, j * stride, width);
      dstArr.set(srcBuf, j * width);
    }
    let pixelMap = await image.createPixelMap(dstArr.buffer, {
      size: { height: height, width: width }, srcPixelFormat: 8
    });
    ```

    方式二：根据stride*height创建pixelMap，然后调用pixelMap的cropSync方法裁剪掉多余的像素。

    ```ts
    // 创建pixelMap，width宽传行距stride的值。
    let pixelMap = await image.createPixelMap(imgComponent.byteBuffer, {
      size:{height: height, width: stride}, srcPixelFormat: 8});
    // 裁剪多余的像素。
    pixelMap.cropSync({size:{width:width, height:height}, x:0, y:0});
    ```

    方式三：将原始imgComponent.byteBuffer和stride信息一起传给支持stride的接口处理。
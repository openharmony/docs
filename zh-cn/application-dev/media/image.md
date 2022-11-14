# 图片开发指导

## 场景介绍

图片开发的主要工作是将获取到的图片进行解码，将解码后的pixelmap编码成支持的格式，本文将对图片的解码、编码等场景开发进行介绍说明。

## 接口说明

详细API含义请参考：[图片处理API文档](../reference/apis/js-apis-image.md)

## 开发步骤

### 全流程场景

包含流程：创建实例、读取图片信息、读写pixelmap、更新数据、打包像素、释放资源等流程。

```js
const color = new ArrayBuffer(96); // 用于存放图像像素数据
let opts = { alphaType: 0, editable: true, pixelFormat: 4, scaleMode: 1, size: { height: 2, width: 3 } } // 图像像素数据

// 创建pixelmap对象
const color = new ArrayBuffer(96);
let opts = { alphaType: 0, editable: true, pixelFormat: 4, scaleMode: 1, size: { height: 2, width: 3 } }
image.createPixelMap(color, opts, pixelmap => {
    console.log('Succeeded in creating pixelmap.');
})

// 用于读像素
pixelmap.readPixels(area,(data) => {
    if(data !== null) {
        var bufferArr = new Uint8Array(area.pixels);
        var res = true;
        for (var i = 0; i < bufferArr.length; i++) {
            console.info(' buffer ' + bufferArr[i]);
            if(res) {
                if(bufferArr[i] == 0) {
                    res = false;
                    console.log('readPixels end.');
                    break;
                }
            }
        }
    }
})
 
// 用于存像素
const readBuffer = new ArrayBuffer(96);
pixelmap.readPixelsToBuffer(readBuffer,() => {
    var bufferArr = new Uint8Array(readBuffer);
    var res = true;
    for (var i = 0; i < bufferArr.length; i++) {
        if(res) {
            if (bufferArr[i] !== 0) {
                res = false;
                console.log('readPixelsToBuffer end.');
                break;
            }
        }
    }
})
    
// 用于写像素
pixelmap.writePixels(area,() => {
    const readArea = { pixels: new ArrayBuffer(20), offset: 0, stride: 8, region: { size: { height: 1, width: 2 }, x: 0, y: 0 }}
    pixelmap.readPixels(readArea,() => {
        var readArr = new Uint8Array(readArea.pixels);
        var res = true;
        for (var i = 0; i < readArr.length; i++) {
            if(res) {
                if (readArr[i] !== 0) {
                    res = false;
                    console.log('readPixels end.please check buffer');
                    break;
                }
            }
        }
    })
})
  
// 用于写像素到缓冲区
pixelmap.writeBufferToPixels(writeColor).then(() => {
    const readBuffer = new ArrayBuffer(96);
    pixelmap.readPixelsToBuffer(readBuffer).then (() => {
        var bufferArr = new Uint8Array(readBuffer);
        var res = true;
        for (var i = 0; i < bufferArr.length; i++) {
            if(res) {
                if (bufferArr[i] !== i) {
                    res = false;
                    console.log('readPixels end.please check buffer');
                    break;
                }
            }
        }
    })
})

// 用于获取图片信息
pixelmap.getImageInfo((error, imageInfo) => {
    if (imageInfo !== null) {
	    console.log('Succeeded in getting imageInfo');
    } 
})

// 用于释放pixelmap
pixelmap.release(()=>{
    console.log('Succeeded in releasing pixelmap');
})

// 用于创建imagesource(uri)
let path = '/data/local/tmp/test.jpg';
const imageSourceApi = image.createImageSource(path);

// 用于创建imagesource(fd)
let fd = 29;
const imageSourceApi = image.createImageSource(fd);

// 用于创建imagesource(data)
const data = new ArrayBuffer(96);
const imageSourceApi = image.createImageSource(data);

// 用于释放imagesource
imageSourceApi.release(() => {
    console.log('Succeeded in releasing imagesource');
})
    
// 用于编码
const imagePackerApi = image.createImagePacker();
const imageSourceApi = image.createImageSource(0);
let packOpts = { format:"image/jpeg", quality:98 };
imagePackerApi.packing(imageSourceApi, packOpts, data => {
    console.log('Succeeded in packing');
})
 
// 用于释放imagepacker
imagePackerApi.release();
```

### 解码场景

```js
let path = '/data/local/tmp/test.jpg'; // 设置创建imagesource的路径

// 用路径创建imagesource
const imageSourceApi = image.createImageSource(path); // '/data/local/tmp/test.jpg'

// 设置参数
let decodingOptions = {
    sampleSize:1, // 缩略图采样大小
    editable: true, // 是否可编辑
    desiredSize:{ width:1, height:2}, // 期望输出大小
    rotateDegrees:10, // 旋转角度
    desiredPixelFormat:2, // 解码的像素格式
    desiredRegion: { size: { height: 1, width: 2 }, x: 0, y: 0 }, // 解码的区域
    index:0 // 图片序号
    };
    
// 用于回调方式创建pixelmap
imageSourceApi.createPixelMap(decodingOptions, pixelmap => {
    console.log('Succeeded in creating pixelmap.');
})

// 用于promise创建pixelmap
imageSourceApi.createPixelMap().then(pixelmap => {
    console.log('Succeeded in creating pixelmap.');
})

// 函数调用发生异常时，捕捉错误信息
catch(error => {
    console.log('Failed in creating pixelmap.' + error);
})

// 用于获取像素每行字节数
pixelmap.getBytesNumberPerRow( num => {
    console.log('Succeeded in getting BytesNumber PerRow.');
})

// 用于获取像素总字节数
pixelmap.getPixelBytesNumber(num => {
    console.log('Succeeded in getting PixelBytesNumber.');
})

// 用于获取pixelmap信息
pixelmap.getImageInfo.then( imageInfo => {});

// 用于释放pixelmap
pixelmap.release(()=>{
    console.log('Succeeded in releasing pixelmap');
})    

// 用于捕捉释放失败信息
catch(error => {
    console.log('Failed in releasing pixelmap.' + error);
})
```

### 编码场景

```js
let path = '/data/local/tmp/test.png'; // 设置创建imagesource的路径

// 用于设置imagesource
const imageSourceApi = image.createImageSource(path); // '/data/local/tmp/test.png'
 
// 如果创建imagesource失败，打印错误信息
if (imageSourceApi == null) {
    console.log('Failed in creating imageSource.');
}
   
// 如果创建imagesource成功，则创建imagepacker
const imagePackerApi = image.createImagePacker();

// 如果创建失败，打印错误信息
if (imagePackerApi == null) {
    console.log('Failed in creating imagePacker.');
}

// 如果创建imagepacker成功，则设置编码参数
let packOpts = { format:["image/jpeg"], // 支持编码的格式为jpg
                 quality:98 } // 图片质量0-100

// 用于编码
imagePackerApi.packing(imageSourceApi, packOpts)
.then( data => {
    console.log('Succeeded in packing');
})
         
// 编码完成，释放imagepacker
imagePackerApi.release();

// 用于获取imagesource信息
imageSourceApi.getImageInfo((err, imageInfo) => {
    console.log('Succeeded in getting imageInfo');
})

// 用于更新增量数据
imageSourceIncrementalSApi.updateData(array, false, 0, 10,(error, data)=> {})

```

### ImageReceiver的使用

示例场景：camera作为客户端将拍照数据传给服务端

```js
public async init(surfaceId: any) {

    // 服务端代码，创建ImageReceiver
    var receiver = image.createImageReceiver(8 * 1024, 8, image.ImageFormat.JPEG, 1);

    // 获取Surface ID
    receiver.getReceivingSurfaceId((err, surfaceId) => {
        console.info("receiver getReceivingSurfaceId success");
    });
    // 注册Surface的监听，在surface的buffer准备好后触发
    receiver.on('imageArrival', () => {
        // 去获取Surface中最新的buffer
        receiver.readNextImage((err, img) => {
            img.getComponent(4, (err, component) => {
                // 消费component.byteBuffer，例如：将buffer内容保存成图片。
		    })
	    })
    })

    // 调用Camera方法将surfaceId传递给Camera。camera会通过surfaceId获取surface，并生产出surface buffer。
}
```

## 相关实例

针对图片开发，有以下相关实例可供参考：

- [`Image`：图片处理（ArkTS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/master/media/Image)
- [`GamePuzzle`：拼图（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/media/GamePuzzle)
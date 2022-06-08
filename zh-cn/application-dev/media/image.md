# 图片开发指导

## 场景介绍

图片开发的主要工作是将获取到的图片进行解码，将解码后的pixelmap编码成支持的格式，本文将对图片的解码、编码等场景开发进行介绍说明。

## 接口说明

详细API含义请参考：[图片处理API文档](../reference/apis/js-apis-image.md)

## 开发步骤

### 全流程场景

包含流程：创建实例，读取图片信息，读写pixelmap，更新数据，打包像素，释放资源等流程。

```js
const Color = new ArrayBuffer(96);//用于存放图像像素数据
let opts = { alphaType: 0, editable: true, pixelFormat: 4, scaleMode: 1, size: { height: 2, width: 3 } } //图像像素数据

//创建pixelmap对象
const Color = new ArrayBuffer(96);
let opts = { alphaType: 0, editable: true, pixelFormat: 4, scaleMode: 1, size: { height: 2, width: 3 } }
        image.createPixelMap(Color, opts, pixelmap => {
            expect(pixelmap !== null).assertTrue();
            console.info('TC_001-1 success');
            done();
        })
//用于读像素
 pixelmap.readPixels(area,(data) => {
 	if(data !== null) {
		var bufferArr = new Uint8Array(area.pixels);
        var res = true;
        for (var i = 0; i < bufferArr.length; i++) {
			console.info('TC_021-1 buffer ' + bufferArr[i]);
				if(res) {
					if(bufferArr[i] == 0) {
						res = false;
                        console.info('TC_021-1 Success');
                        expect(true).assertTrue();
                        done();
                        break;
                        }
                    }
                }
 
//用于存像素
const readBuffer = new ArrayBuffer(96);
pixelmap.readPixelsToBuffer(readBuffer,() => {
var bufferArr = new Uint8Array(readBuffer);
var res = true;
for (var i = 0; i < bufferArr.length; i++) {
     if(res) {
       if (bufferArr[i] !== 0) {
          res = false;
          console.info('TC_020-1 Success');
          expect(true).assertTrue();
          done();
          break;
          }
       }
    }
    
//用于写像素
pixelmap.writePixels(area,() => {
    const readArea = { pixels: new ArrayBuffer(20), offset: 0, stride: 8, region: { size: { height: 1, width: 2 }, x: 0, y: 0 }}
     pixelmap.readPixels(readArea,() => {
         var readArr = new Uint8Array(readArea.pixels);
         var res = true;
         for (var i = 0; i < readArr.length; i++) {
              if(res) {
                  if (readArr[i] !== 0) {
                      res = false;
                      console.info('TC_022-1 Success');
                      expect(true).assertTrue();
                      done();
                      break;
                    }
                 }
            }
  
//用于写像素到缓冲区
 pixelmap.writeBufferToPixels(writeColor).then(() => {
     const readBuffer = new ArrayBuffer(96);
     pixelmap.readPixelsToBuffer(readBuffer).then (() => {
    	var bufferArr = new Uint8Array(readBuffer);
     	var res = true;
     	for (var i = 0; i < bufferArr.length; i++) {
     		if(res) {
     			if (bufferArr[i] !== i) {
     				res = false;
                    console.info('TC_023 Success');
                    expect(true).assertTrue()
                    done();
                    break;
                }
            }
       }

//用于获取图片信息
pixelmap.getImageInfo( imageInfo => {
     if (imageInfo !== null) {
         console.info('TC_024-1 imageInfo is ready');
         expect(imageInfo.size.height == 4).assertTrue();
         expect(imageInfo.size.width == 6).assertTrue();
         expect(imageInfo.pixelFormat == 4).assertTrue();
         done();
      } 
 })

//用于释放pixelmap
pixelmap.release(()=>{
    expect(true).assertTrue();
    console.log('TC_027-1 suc');
    done();
})

//用于创建imagesource(uri)
const imageSourceApi = image.createImageSource(path);//'/data/local/tmp/test.jpg'

//用于创建imagesource(fd)
const imageSourceApi = image.createImageSource(29);

//用于创建imagesource(data)
const data = new ArrayBuffer(96);
const imageSourceApi = image.createImageSource(data);

//用于释放imagesource
imageSourceApi.release(() => {
    console.info('TC_044-1 Success');
    })
    
//用于编码
const imagePackerApi = image.createImagePacker();
imagePackerApi.packing(imageSourceApi, packOpts, data => {
    console.info('TC_062-1 finished');
    expect(data !== null).assertTrue();
    done();
 })
 
//用于释放imagepacker
imagePackerApi.release();
```

### 解码场景

```js
/data/local/tmp/test.jpg //设置创建imagesource的路径

//用路径创建imagesource
const imageSourceApi = image.createImageSource(path);//'/data/local/tmp/test.jpg'

//设置参数
let decodingOptions = {
    sampleSize:1,//缩略图采样大小
    editable: true, //是否可编辑
    desiredSize:{ width:1, height:2},//期望输出大小
    rotateDegrees:10,//旋转角度
    desiredPixelFormat:2,//解码的像素格式
    desiredRegion: { size: { height: 1, width: 2 }, x: 0, y: 0 },//解码的区域
    index:0//图片序号
    };
    
//用于回调方式创建pixelmap
imageSourceApi.createPixelMap(decodingOptions, pixelmap => {
    console.info('TC_050 createPixelMap ');
    expect(pixelmap !== null ).assertTrue();
    done();
    })
}  

//用于promise创建pixelmap
imageSourceApi.createPixelMap().then(pixelmap => {
   console.info('TC_050-11 createPixelMap ');
   expect(pixelmap !== null ).assertTrue();
   done();
})

//函数调用发生异常时，捕捉错误信息
catch(error => {
    console.log('TC_050-11 error: ' + error);
    expect().assertFail();
    done();
  })

//用于获取像素每行字节数
pixelmap.getBytesNumberPerRow( num => {
	console.info('TC_025-1 num is ' + num);
	expect(num == expectNum).assertTrue();
	done();
})

//用于获取像素总字节数
pixelmap.getPixelBytesNumber(num => {
        console.info('TC_026-1 num is ' + num);
        expect(num == expectNum).assertTrue();
        done();
    })

//用于获取pixelmap信息
 pixelmap.getImageInfo( imageInfo => {})
 
//用于打印获取失败信息
console.info('TC_024-1 imageInfo is empty');
expect(false).assertTrue()

//用于释放pixelmap
pixelmap.release(()=>{
            expect(true).assertTrue();
            console.log('TC_027-1 suc');
            done();
        })    

//用于捕捉释放失败信息
catch(error => {
            console.log('TC_027-1 error: ' + error);
            expect().assertFail();
            done();
        })
```

### 编码场景

```js
/data/local/tmp/test.png //设置创建imagesource的路径

//用于设置imagesource
 const imageSourceApi = image.createImageSource(path);//'/data/local/tmp/test.png'
 
//如果创建imagesource失败，打印错误信息
if (imageSourceApi == null) {
   console.info('TC_062 create image source failed');
   expect(false).assertTrue();
   done();
   }
   
//如果创建imagesource成功，则创建imagepacker
const imagePackerApi = image.createImagePacker();

//如果创建失败，打印错误信息
if (imagePackerApi == null) {
    console.info('TC_062 create image packer failed');
    expect(false).assertTrue();
    done();
    }

//如果创建imagepacker成功，则设置编码参数
let packOpts = { format:["image/jpeg"], //支持编码的格式为jpg
                 quality:98 }//图片质量0-100

//用于编码
imagePackerApi.packing(imageSourceApi, packOpts)
.then( data => {
         console.info('TC_062 finished');
         expect(data !== null).assertTrue();
         done();
        })
             
//编码完成，释放imagepacker
 imagePackerApi.release();

//用于获取imagesource信息
imageSourceApi.getImageInfo(imageInfo => {
     console.info('TC_045 imageInfo');
     expect(imageInfo !== null).assertTrue();
     done();
   })

//用于更新增量数据
imageSourceIncrementalSApi.updateData(array, false, 0, 10,(error,data )=> {})

```

### ImageReceivert的使用

```js
//创建ImageReceiver
var receiver = image.createImageReceiver(8 * 1024, 8, image.ImageFormat.JPEG, 1);

//获取Surface ID
var surfaceId = await receiver.getReceivingSurfaceId();

receiver.on('imageArrival', () => {
    //去获取Surface中的buffer的方法
    receiver.readNextImage((err, img) => {
	    img.getComponent(4, (err, componet) => {
			//操作componet.byteBuffer
		})
	})
})

//调用方法将surfaceId传递给消费端。
```
# Image Kit常见崩溃报错问题
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

本文档展示了Image Kit接口的典型错误用法案例，帮助开发者避免常见的开发问题，提高应用的稳定性和性能。

## 编码过程中PixelMap被释放/修改导致崩溃

**典型崩溃堆栈示例：**

``` text
Fault thread info:
Tid:5005, Name:OS_FFRT_3_0
#00 pc 000000000006d1f0 /system/lib64/platformsdk/libextplugin.z.so(OHOS::ImagePlugin::ExtWStream::write(void const*, unsigned long)+24)(300e33eb41735f2d3c8fe2259a671217)
#01 pc 0000000001828c94 /system/lib64/libskia_canvaskit.z.so(sk_empty_output_buffer(jpeg_compress_struct*)+48)(484139254f1cae74fd86fe798dbea128)
#02 pc 00000000010d1bb4 /system/lib64/libskia_canvaskit.z.so(encode_mcu_huff+692)(484139254f1cae74fd86fe798dbea128)
#03 pc 00000000010c8a88 /system/lib64/libskia_canvaskit.z.so(compress_output+384)(484139254f1cae74fd86fe798dbea128)
#04 pc 0000000000f8c4b0 /system/lib64/libskia_canvaskit.z.so(jpeg_finish_compress+220)(484139254f1cae74fd86fe798dbea128)
#05 pc 0000000000f8bf08 /system/lib64/libskia_canvaskit.z.so(SkJpegEncoderImpl::onEncodeRows(int)+384)(484139254f1cae74fd86fe798dbea128)
#06 pc 0000000000fd25ac /system/lib64/libskia_canvaskit.z.so(SkEncoder::encodeRows(int)+68)(484139254f1cae74fd86fe798dbea128)
#07 pc 0000000000fd2514 /system/lib64/libskia_canvaskit.z.so(SkJpegEncoder::Encode(SkWStream*, SkPixmap const&, SkJpegEncoder::Options const&)+64)(484139254f1cae74fd86fe798dbea128)
#08 pc 00000000000545dc /system/lib64/platformsdk/libextplugin.z.so(OHOS::ImagePlugin::ExtEncoder::SkEncodeImage(SkWStream*, SkBitmap const&, SkEncodedImageFormat, int)+188)(300e33eb41735f2d3c8fe2259a671217)
#09 pc 00000000000547a4 /system/lib64/platformsdk/libextplugin.z.so(OHOS::ImagePlugin::ExtEncoder::DoEncode(SkWStream*, SkBitmap const&, SkEncodedImageFormat const&)+204)(300e33eb41735f2d3c8fe2259a671217)
#10 pc 0000000000055464 /system/lib64/platformsdk/libextplugin.z.so(OHOS::ImagePlugin::ExtEncoder::EncodeImageByBitmap(SkBitmap&, bool, SkWStream&)+284)(300e33eb41735f2d3c8fe2259a671217)
#11 pc 0000000000055ad8 /system/lib64/platformsdk/libextplugin.z.so(OHOS::ImagePlugin::ExtEncoder::EncodeImageByPixelMap(OHOS::Media::PixelMap*, bool, SkWStream&)+1356)(300e33eb41735f2d3c8fe2259a671217)
#12 pc 0000000000053350 /system/lib64/platformsdk/libextplugin.z.so(OHOS::ImagePlugin::ExtEncoder::EncodeSdrImage(OHOS::ImagePlugin::ExtWStream&)+984)(300e33eb41735f2d3c8fe2259a671217)
#13 pc 0000000000052684 /system/lib64/platformsdk/libextplugin.z.so(OHOS::ImagePlugin::ExtEncoder::PixelmapEncode(OHOS::ImagePlugin::ExtWStream&)+184)(300e33eb41735f2d3c8fe2259a671217)
#14 pc 0000000000053a7c /system/lib64/platformsdk/libextplugin.z.so(OHOS::ImagePlugin::ExtEncoder::FinalizeEncode()+952)(300e33eb41735f2d3c8fe2259a671217)
#15 pc 00000000000b7d00 /system/lib64/platformsdk/libimage_native.z.so(std::__h::__function::__func<OHOS::Media::ImagePacker::FinalizePacking()::$_3, std::__h::allocator<OHOS::Media::ImagePacker::FinalizePacking()::$_3>, unsigned int (OHOS::ImagePlugin::AbsImageEncoder*)>::operator()(OHOS::ImagePlugin::AbsImageEncoder*&&)+28)(abee48eb37a365d523ba3560f087b63a)
#16 pc 00000000000b58b4 /system/lib64/platformsdk/libimage_native.z.so(OHOS::Media::ImagePacker::DoEncodingFunc(std::__h::function<unsigned int (OHOS::ImagePlugin::AbsImageEncoder*)>, bool)+272)(abee48eb37a365d523ba3560f087b63a)
#17 pc 00000000000b6de4 /system/lib64/platformsdk/libimage_native.z.so(OHOS::Media::ImagePacker::FinalizePacking(long&)+80)(abee48eb37a365d523ba3560f087b63a)
#18 pc 000000000009a5b8 /system/lib64/platformsdk/libimage_napi.z.so(OHOS::Media::PackToFileExec(napi_env__*, void*)+912)(1d95fd2a148829930aeec8cbeaf92976)
#19 pc 000000000006258c /system/lib64/platformsdk/libace_napi.z.so(NativeAsyncWork::AsyncWorkCallback(uv_work_s*)+264)(f5de54fc91f8cc9643b4846b808f9d4c)
#20 pc 0000000000013bd4 /system/lib64/platformsdk/libuv.so(uv__queue_work+48)(7dfe11681838c768af19f3408663affb)
 ...
 
```
**崩溃原因：**
编码过程中未使用`await`等待异步操作执行完毕，致使资源对象在异步操作完成前被提前释放或修改。

**解决措施：**

1. **异步操作的生命周期管理：** 在调用Image Kit的异步接口（如[packToData](../../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md#packtodata13)、[packToFile](../../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md#packtofile11)、[createPixelMap](../../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#createpixelmap7)等）时，必须确保传入的资源对象（如PixelMap、ImageSource）在异步操作完成之前不被释放或修改。

2. **使用await或Promise.then：** 推荐使用`await`等待异步操作完成，或者在`Promise.then()`的回调中释放资源，确保释放时机正确。

3. **页面生命周期管理：** 如果在页面中使用异步图片操作，需要在页面销毁时确保所有异步操作已经完成或取消，避免页面卸载后异步回调访问已销毁的资源。

**错误代码示例：**

``` TypeScript
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function wrongPackingExample(pixelMap: image.PixelMap, fd: number): Promise<void> {
  let imagePacker: image.ImagePacker | null = null;

  try {
    imagePacker = image.createImagePacker();
    let packOpts: image.PackingOption = { format: 'image/jpeg', quality: 95 };
    // 错误：异步编码执行过程中，对pixelMap进行修改。
    pixelMap.crop({x:1, y:1, size: {height:200, width:200}});
    
     // 错误：异步操作没有使用await。
    imagePacker.packToFile(pixelMap, fd, packOpts).then(() => {
      console.info('Succeeded in packing the image to file.');
    }).catch((error: BusinessError) => {
      console.error('Pack failed: ' + error);
    });

  } catch (error) {
    console.error('Pack failed: ' + error);
  } finally {    
    // 错误：异步编码未完成，直接释放PixelMap，触发应用闪退。
    pixelMap?.release();
    imagePacker?.release();
  }
}
```

**正确代码示例：**

``` TypeScript
import { image } from '@kit.ImageKit';

async function correctPackingExample(pixelMap: image.PixelMap, fd: number): Promise<void> {
  let imagePacker: image.ImagePacker | null = null;

  try {
    imagePacker = image.createImagePacker();
    let packOpts: image.PackingOption = { format: 'image/jpeg', quality: 95 };

    // 正确：对PixelMap做裁剪时，必须await等待操作完成。
    await pixelMap.crop({x:1, y:1, size: {height:200, width:200}});
    
    // 正确：使用await等待异步操作完成。
    await imagePacker.packToFile(pixelMap, fd, packOpts);
    console.info('Pack success');

  } catch (error) {
    console.error('Pack failed: ' + error)
  } finally {
    pixelMap?.release();
    imagePacker?.release();
  }
}
```

## 多个异步操作共享同一个ImageSource对象

**典型崩溃堆栈示例：**

``` text
Fault thread info:
Tid: 41048, Name: OS_FFRT_3_5
#00 pc 00000000000b0864 /system/lib64/platformsdk/libimage_napi.z.so(OHOS::Media::CreatePixelMapInner(OHOS::Media::ImageSourceNapi*, std::__h::shared_ptr<OHOS::Media::ImageSource>, unsigned int, OHOS::Media::DecodeOptions, unsigned int8)+116) (3a63d0a0dc3ac58d9e1a58a77ad194f9)
#01 pc 00000000000b1178 /system/lib64/platformsdk/libimage_napi.z.so(OHOS::Media::CreatePixelMapExecute(napi_env__*, void*) (.1167.cfi)+308) (3a63d0a0dc3ac58d9e1a58a77ad194f9)
#02 pc 000000000005c3c0 /system/lib64/platformsdk/libace_napi.z.so(NativeAsyncWork: :AsyncWorkCallback(uv_work_s*)+304) (68011f831ed16fa3d94d4f22664d2eaf)
#03 pc 0000000000013614 /system/lib64/platformsdk/libuv.so(uv__queue_work+60)(1399a989328aa340c8622e4a1d0ca961)
#04 pc 0000000000091794 /system/lib64/ndk/libffrt.so(ffrt::UVTask::Execute()+764) (7921196b695415b02aa2bódfb05c7deb)
#05
pc 000000000008d13c /system/lib64/ndk/libffrt.so(ffrt::ExecuteTask(ffrt::TaskBase*)+248) (7921196b695415b02aa2b6dfb05c7deb)
#06 pc 000000000002e054 /system/lib64/ndk/libffrt.so(ffrt::CPUWorker::RunTask(ffrt: :TaskBase*, ffrt::CPUWorker*)+84) (7921196b695415b02aa2bódfb05c7deb)
#07 pc 00000000000cóc58 /system/lib64/ndk/libffrt.so(7921196b695415b02aa2b6dfb05c7deb)
#08 pc 00000000001d8c5c /system/lib/ld-musl-aarch64.so.1(start+240)(05aecbbf0bdce12d75badb7b497d0f9f)
 ...
```
**崩溃原因：**
并发操作同一个ImageSource对象，引发资源竞态问题导致崩溃。

**解决措施：**

1. **避免并发访问：** 不要对同一个ImageSource实例并发执行多个异步操作，推荐按顺序执行，确保一个操作完成后再执行下一个操作。

2. **资源生命周期：** ImageSource的生命周期应该覆盖所有使用它的异步操作，只有在确认所有异步操作都完成后才能释放。

3. **性能考虑：** 虽然顺序执行可能会降低并发性能，但可以避免竞态条件和崩溃问题。如果确实需要并发处理，应该创建多个独立的ImageSource实例。


**错误代码示例：**

``` TypeScript
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function wrongSharedImageSourceExample(filePath: string, decodingOptions: Array<image.DecodingOptions>): Promise<Array<image.PixelMap>> {
  // 创建一个ImageSource实例。
  const imageSource = image.createImageSource(filePath);
  const pixelMaps: Array<image.PixelMap> = [];

  // 错误：for循环中并发启动多个解码操作，共享同一个ImageSource。
  for (const opts of decodingOptions) {
    imageSource.createPixelMap(opts).then((pixelMap: image.PixelMap) => {
      pixelMaps.push(pixelMap);
      console.info('PixelMap created');
    }).catch((error: BusinessError) => {
      console.error('Create pixelMap failed: ' + error);
    });
  }

  // 错误：立即释放ImageSource，此时异步操作可能还在执行。
  imageSource.release();
  return pixelMaps;
}
```

**正确代码示例：**

``` TypeScript
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function correctSharedImageSourceExample(filePath: string): Promise<void> {
  // 创建一个ImageSource实例。
  const imageSource = image.createImageSource(filePath);

  try {
    // 正确：按顺序执行异步操作，避免并发访问。
    const imageInfo = await imageSource.getImageInfo();
    console.info(`Image info: width=${imageInfo.size.width}, height=${imageInfo.size.height}`);

    const pixelMap1 = await imageSource.createPixelMap({ editable: true });
    console.info('First pixelMap created');

    const pixelMap2 = await imageSource.createPixelMap({ editable: false });
    console.info('Second pixelMap created');

    // 使用完成后释放资源。
    pixelMap1.release();
    pixelMap2.release();
  } catch (error) {
    console.error('Operation failed: ' + error);
  }

  // 所有操作完成后，安全地释放ImageSource。
  imageSource.release();
}
```

## 异步调用getComponent接口后尚未执行完成即被释放

**典型崩溃堆栈示例：**

``` text
Fault thread info:
Tid:9589, Name:OS_FFRT_2_0
#00 pc 00000000000a431c /system/lib64/platformsdk/libimage_native.z.so(OHOS::Media::NativeImage::GetComponent(int)+48)(915bf0936fb72b5d73478ab6f47e091f)
#01 pc 00000000000910e8 /system/lib64/platformsdk/libimage_napi.z.so(OHOS::Media::JsGetComponentExec(napi_env__, OHOS::Media::ImageAsyncContext)+44)(5aea949db77850d22719993f9fa30591)
#02 pc 0000000000061880 /system/lib64/platformsdk/libace_napi.z.so(NativeAsyncWork::AsyncWorkCallback(uv_work_s*)+264)(eb4e54d33bdc523abe3e5a5c8e57df7b)
#03 pc 0000000000014c80 /system/lib64/platformsdk/libuv.so(uv__queue_work+48)(d25bc8d4fd1cdf784a3645c9a4b124f6)
#04 pc 00000000000827d8 /system/lib64/ndk/libffrt.so(ffrt::UVTask::ExecuteImpl(ffrt::UVTask*, void ()(ffrt_executor_task, int))+148)(e135a1a6a62d4d06e957f3c7bf9fb095)
#05 pc 000000000007f5a4 /system/lib64/ndk/libffrt.so(ffrt::ExecuteTask(ffrt::TaskBase*)+184)(e135a1a6a62d4d06e957f3c7bf9fb095)
#06 pc 000000000004c270 /system/lib64/ndk/libffrt.so(ffrt::CPUWorker::RunTask(ffrt::TaskBase*, ffrt::CPUWorker*)+84)(e135a1a6a62d4d06e957f3c7bf9fb095)
#07 pc 000000000004c494 /system/lib64/ndk/libffrt.so(ffrt::CPUWorker::WorkerLooper()+268)(e135a1a6a62d4d06e957f3c7bf9fb095)
#08 pc 000000000004c0f8 /system/lib64/ndk/libffrt.so(ffrt::CPUWorker::Dispatch(ffrt::CPUWorker*)+152)(e135a1a6a62d4d06e957f3c7bf9fb095)
#09 pc 000000000004bedc /system/lib64/ndk/libffrt.so(ffrt::CPUWorker::WrapDispatch(void*)+52)(e135a1a6a62d4d06e957f3c7bf9fb095)
#10 pc 00000000001f8e00 /system/lib/ld-musl-aarch64.so.1(start+236)(d4dce499aee129fd4449af41d61ee794)
...
```
**崩溃原因：**
image.getComponent()是异步操作，而image.release()也是异步操作，其complete回调会删除（delete）底层原生ImageNapi对象。由于image.getComponent()还在执行，导致释放后使用（Use After Free）。

**解决措施：**

对同一Image对象，必须所有异步操作完成后，才能调用release()释放资源。


**错误代码示例：**

``` TypeScript
import { image } from '@kit.ImageKit';
import { camera } from '@kit.CameraKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { abilityAccessCtrl, common } from '@kit.AbilityKit';

/**
 * UAF写法：getComponent异步 + 立即release。
 * getComponent投递到FFRT线程，release不等待直接释放原生对象 → UAF崩溃。
 */
function onImageArrivalUAF(receiver: image.ImageReceiver): void {
  let frame = 0;
  receiver.on('imageArrival', () => {
    frame++;
    const cur = frame;
    receiver.readNextImage((err, img: image.Image) => {
      if (err || !img) {
        console.info(`[UAF] #${cur} readNextImage err: ${err?.code}`);
        return;
      }
      img.getComponent(image.ComponentType.JPEG).then(() => {
        console.info(`[UAF] #${cur} getComponent done`);
      }).catch((e: BusinessError) => {
        console.info(`[UAF] #${cur} getComponent err: ${e.code}`);
      });
      // BUG：不等待getComponent完成就release → UAF。
      img.release().catch(() => {});
    });
  });
}
```

**正确代码示例：**

``` TypeScript
import { image } from '@kit.ImageKit';
import { camera } from '@kit.CameraKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { abilityAccessCtrl, common } from '@kit.AbilityKit';

/**
 * 安全写法：getComponent完成后再release。
 * Promise链式调用保证顺序，不会UAF。
 */
function onImageArrivalSafe(receiver: image.ImageReceiver): void {
  let frame = 0;
  receiver.on('imageArrival', () => {
    frame++;
    const cur = frame;
    receiver.readNextImage((err, img: image.Image) => {
      if (err || !img) {
        console.info(`[Safe] #${cur} readNextImage err: ${err?.code}`);
        return;
      }
      // FIX：getComponent完成后再release。
      img.getComponent(image.ComponentType.JPEG).then(() => {
        console.info(`[Safe] #${cur} getComponent done`);
        return img.release();
      }).then(() => {
        console.info(`[Safe] #${cur} released`);
      }).catch((e: BusinessError) => {
        console.info(`[Safe] #${cur} err: ${e.code}`);
        img.release().catch(() => {});
      });
    });
  });
}
```
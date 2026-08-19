# Common Crash and Error Issues

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9ad5e24eaa1ac95d00b48a8436556bc45cf5aa32 translatedAt=2026-08-11T10:27:41.624Z pushedAt=2026-08-11T11:31:49.918Z -->

This section demonstrates typical misuse cases of Image Kit APIs, helping you avoid common development issues and improve app stability and performance.

## PixelMap Released or Modified During Encoding Causes a Crash

**Typical crash stack example:**

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

**Cause:**
During encoding, asynchronous operations are not properly awaited. As a result, resource objects are released or modified before the asynchronous operations are complete, causing a crash.

**Solution**

1. **Lifecycle management of asynchronous operations:** When calling asynchronous APIs of Image Kit (such as [packToData](../../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md#packtodata13), [packToFile](../../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md#packtofile11), [createPixelMap](../../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#createpixelmap7), etc.), ensure that the passed resource objects (such as `PixelMap` and `ImageSource`) are not released or modified before the asynchronous operation completes.

2. **await or Promise.then:** You are advised to use `await` to wait for the asynchronous operation to complete, or release resources in the `Promise.then()` callback to ensure correct release timing.

3. **Page lifecycle management:** If asynchronous image operations are used in a page, ensure that all asynchronous operations have completed or been canceled when the page is destroyed, to prevent asynchronous callbacks from accessing destroyed resources after the page is unloaded.

**Incorrect code example:**

``` TypeScript
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function wrongPackingExample(pixelMap: image.PixelMap, fd: number): Promise<void> {
  let imagePacker = image.ImagePacker | null = null;

  try {
    imagePacker = image.createImagePacker();
    let packOpts: image.PackingOption = { format: 'image/jpeg', quality: 95 };
    // Incorrect: The pixelMap is modified during asynchronous encoding.
    pixelMap.crop({x:1, y:1, size: {height:200, width:200}});
    
     // Incorrect: await is not used for the asynchronous operation.
    imagePacker.packToFile(pixelMap, fd, packOpts).then(() => {
      console.info('Succeeded in packing the image to file.');
    }).catch((error: BusinessError) => {
      console.error('Pack failed: ' + error);
    });

  } catch (error) {
    console.error('Pack failed: ' + error);
  } finally {    
    // Incorrect: The PixelMap is released before asynchronous encoding completes, causing the app to crash.
    pixelMap?.release();
    imagePacker?.release();
  }
}
```

**Correct code example:**

``` TypeScript
import { image } from '@kit.ImageKit';

async function correctPackingExample(pixelMap: image.PixelMap, fd: number): Promise<void> {
  let imagePacker = image.ImagePacker | null = null;

  try {
    imagePacker = image.createImagePacker();
    let packOpts: image.PackingOption = { format: 'image/jpeg', quality: 95 };

    // Correct: When cropping a PixelMap, await must be used to wait for the operation to complete.
    await pixelMap.crop({x:1, y:1, size: {height:200, width:200}});
    
    // Correct: Use await to wait for the asynchronous operation to complete.
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

## Multiple Asynchronous Operations Share the Same ImageSource Object

**Typical crash stack example:**

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

**Cause:**
Concurrent operations on the same `ImageSource` object cause resource race conditions, leading to a crash.

**Solution**

1. **Avoid concurrent access:** Do not perform multiple asynchronous operations concurrently on the same `ImageSource` instance. You are advised to execute them sequentially, ensuring that one operation completes before the next one starts.

2. **Manage resource lifecycle:** The lifecycle of an `ImageSource` should cover all asynchronous operations that use it. Release the `ImageSource` only after confirming that all asynchronous operations have completed.

3. **Consider performance:** Although sequential execution may reduce concurrency performance, it helps avoid race conditions and crashes. If concurrent processing is required, create multiple independent `ImageSource` instances.

**Incorrect code example:**

``` TypeScript
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function wrongSharedImageSourceExample(filePath: string, decodingOptions: Array<image.DecodingOptions>): Promise<Array<image.PixelMap>> {
  // Create an ImageSource instance.
  const imageSource = image.createImageSource(filePath);
  const pixelMaps: Array<image.PixelMap> = [];

  // Incorrect: Multiple decoding operations are started concurrently in the for loop, sharing the same ImageSource.
  for (const opts of decodingOptions) {
    imageSource.createPixelMap(opts).then((pixelMap: image.PixelMap) => {
      pixelMaps.push(pixelMap);
      console.info('PixelMap created');
    }).catch((error: BusinessError) => {
      console.error('Create pixelMap failed: ' + error);
    });
  }

  // Incorrect: The ImageSource is released immediately while asynchronous operations may still be in progress.
  imageSource.release();
  return pixelMaps;
}
```

**Correct code example:**

``` TypeScript
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function correctSharedImageSourceExample(filePath: string): Promise<void> {
  // Create an ImageSource instance.
  const imageSource = image.createImageSource(filePath);

  try {
    // Correct: Execute asynchronous operations sequentially to avoid concurrent access.
    const imageInfo = await imageSource.getImageInfo();
    console.info(`Image info: width=${imageInfo.size.width}, height=${imageInfo.size.height}`);

    const pixelMap1 = await imageSource.createPixelMap({ editable: true });
    console.info('First pixelMap created');

    const pixelMap2 = await imageSource.createPixelMap({ editable: false });
    console.info('Second pixelMap created');

    // Release resources after use.
    pixelMap1.release();
    pixelMap2.release();
  } catch (error) {
    console.error('Operation failed: ' + error);
  }

  // Safely release ImageSource after all operations are complete.
  imageSource.release();
}
```

## Image Object Released Before Asynchronous getComponent Call Completes

**Typical crash stack example:**

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

**Crash Cause:**
`image.getComponent()` is an asynchronous operation, and `image.release()` is also an asynchronous operation whose complete callback deletes the underlying native ImageNapi object. Because `image.getComponent()` is still executing, this results in Use After Free (UAF).

**Solution**

**Solution:**
For the same Image object, you must wait until all asynchronous operations are complete before calling `release()` to release resources.

**Incorrect code example:**

``` TypeScript
import { image } from '@kit.ImageKit';
import { camera } from '@kit.CameraKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { abilityAccessCtrl, common } from '@kit.AbilityKit';

/**
 * UAF pattern: getComponent async + immediate release.
 * getComponent is dispatched to the FFRT thread, while release directly frees the native object without waiting → UAF crash.*/
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
      // BUG: release is called without waiting for getComponent to complete → UAF.
      img.release().catch(() => {});
    });
  });
}
```

**Correct code example:**

``` TypeScript
import { image } from '@kit.ImageKit';
import { camera } from '@kit.CameraKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { abilityAccessCtrl, common } from '@kit.AbilityKit';

/**
 * Safe approach: Call release after getComponent completes.
 * Promise chaining ensures ordering and prevents UAF.*/
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
      // FIX: Call release after getComponent completes.
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
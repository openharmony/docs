# 性能提升方案（仅对系统应用开放）

相机启动性能受限于底层器件上点、流程Pipeline初始化等耗时操作影响，本文档将开发者提供更进一步的指导，提升相机启动速度以及拍照返回缩略图速度。相关能力与底层器件相关，开发者在使用前需确认是否支持相关特性。

​相关特性分别在打开相机设备过程、配流过程以及拍照过程中。本文档针对三个场景分别进行介绍。

## 延时配流

经典的相机启动过程经过“相机设备打开”、“配置数据流”、“启动数据流”等流程，而配流启流之前需要得到图形组件的surfaceId。

延时配流方案是把配流启流与surface解耦，在组件尚未给应用surface之前，可以先进行配流启流，只需要在启流结束之前提供surface，可以提升启动速度，防止影响其他启动优化方案的落地。

### 调用流程

### 接口说明

详细的API参考说明，请参考[Camera API文档](../reference/apis/js-apis-camera.md)。

| 接口 | 说明 |
| ---- | ---- |
| createDeferredPreviewOutput(profile: Profile): Promise\<PreviewOutput> | 创建延迟预览输出对象，在配流时替代普通的预览输出对象加入数据流。 |
| addDeferredSurface(surfaceId: string): Promise\<void> | 配置延迟预览的Surface，可以在session.commitConfig()配流和session.start()启流之后运行。 |

### 开发示例

```js
import camera from '@ohos.multimedia.camera';

function async preview(context: Context, cameraInfo: camera.Device, previewProfile: camera.Profile, photoProfile: camera.Profile, surfaceId: string): Promise<void> {
  const cameraManager: camera.CameraManager = camera.getCameraManager(context);
  const cameraInput camera.CameraInput = await cameraManager.createCameraInput(cameraInfo)
  const previewOutput: camera.PreviewOutput = await cameraManager.createDeferredPreviewOutput(previewProfile);
  const photoOutput: camera.PhotoOutput = await cameraManager.createPhotoOutput(photoProfile);
  const session: camera.CaptureSession  = await this.mCameraManager.createCaptureSession();
  await session.beginConfig();
  await session.addInput(cameraInput);
  await session.addOutput(previewOutput);
  await session.addOutput(photoOutput);
  await session.commitConfig();
  await session.start();
  await previewOutput.addDeferredSurface(surfaceId);
}
```

## 快速缩略图

相机拍照性能依赖算法处理的速度，算法链越复杂、效果就越好，但同时处理时间就越长。要能够从拍照流程上进行优化，既满足后处理算法处理的要求，又不要阻塞前台的拍照速度。

通过相机快速缩略图技术，相机拍照可单独输出拇指缩略图，在真图没有上来前，提前上报一张缩略图给应用去显示，提升shot2see用户感知拍照速度。

### 调用流程

### 接口说明

### 开发示例


## 预热启动
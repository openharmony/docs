# 媒体子系统变更说明

## cl.multimedia.1 Camera Kit缩略图回调返回值类型变更

**访问级别**

系统接口

**变更原因**

用户在连拍后，点击缩略图，所显示的由系统快速上报轻量处理的第一阶段图片与缩略图无法正确对应。
这是由于第一阶段图片回调顺序不一定正确，导致处理回调时第一阶段图片无法和缩略图正确对应。

**变更影响**

该变更为不兼容变更。

变更前：通过on('quickThumbnail')监听快速缩略图输出事件，回调返回image.PixelMap对象。

变更后：通过on('quickThumbnail')监听快速缩略图输出事件，回调返回QuickThumbnail对象。

**起始 API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.56 版本开始。

**变更的接口/组件**

@ohos.multimedia.camera下的
- on(type: 'quickThumbnail', callback: AsyncCallback\<image.PixelMap>): void
- off(type: 'quickThumbnail', callback?: AsyncCallback\<image.PixelMap>): void

**适配指导**

应用在取用框架返回的回调信息时需要按照QuickThumbnail的类来取用快速缩略图相关信息：

QuickThumbnail中包括两个字段，分别为：
- captureId:number，缩略图所对应的captureId。
- thumbnailImage:image.PixelMap，上报的缩略图。

使用方式例如：

 private async quickThumbnail(err, quickThumbnail: camera.QuickThumbnail): Promise\<void> {
    if (!quickThumbnail?.thumbnailImage) {
        hilog.info(TAG, 'SHOT2SEE quickThumbnail thumbnailImage is null.');
      return;
    }
    if (!quickThumbnail?.captureId) {
      hilog.info(TAG, 'SHOT2SEE quickThumbnail captureId is null.');
      return;
    }
    hilog.info(TAG, 'SHOT2SEE quickThumbnail success.');
    if (err) {
      const error = `Camera_quickThumbnail Error: ${err.code}}`;
      hilog.error(TAG, error);
      const pic: PictureCameraDuration = PictureCameraDuration.getInstance();
      pic.setSavePictureFailReason(error);
      workerCallback.onSavePictureFailed(pic.getPictureId(), pic.getPictureUri(), CaptureFailedType.THUMBNAIL, error);
      return;
    }
    PictureCameraDuration.getInstance().setQuickThumbEndTime(new Date().getTime());
    let mediaLibraryService = await modulesManager.getMediaLibrary();
    let resPixelMap: image.PixelMap =
      await mediaLibraryService.getQuickThumbnailWatermarkFilter(quickThumbnail.thumbnailImage, this.isInBurstCapture);
 
    try {
      workerCallback.quickThumbnail(resPixelMap, this.isDeferEnabled, quickThumbnail.captureId);
      if (this.mPickerInfo.isPicker) {
        const pickerService = await modulesManager.getPickerFileService();
        pickerService.resetPickerBuffer();
        return;
      }
      if (!this.isDeferEnabled) {
        const mediaLibrary = await modulesManager.getMediaLibrary();
        await mediaLibrary.saveThumbnail(quickThumbnail.thumbnailImage, this.savePhotoFormat); // 单段式需要保存
      }
    } catch (e) {
      const error = `onQuickThumbnail save error: ${JSON.stringify(e)}.`;
      hilog.error(TAG, error);
      const pic: PictureCameraDuration = PictureCameraDuration.getInstance();
      const errorReason = pic.getSavePictureFailReason();
      workerCallback.onSavePictureFailed(pic.getPictureId(), pic.getPictureUri(), CaptureFailedType.THUMBNAIL, errorReason);
      PictureCameraDuration.getInstance().setIsCaptureSuccess(false);
      PictureCameraDuration.getInstance().setPhotoCaptureFailReason(error);
      workerCallback.onUserBehaviorPhotoInterval();
    } finally {
      quickThumbnail?.thumbnailImage?.release();
      resPixelMap?.release();
    }
  }

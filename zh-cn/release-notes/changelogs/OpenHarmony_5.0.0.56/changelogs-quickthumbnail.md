# ArkTS方舟编程语言Changelog

## cl.ArkTS.1 对缩略图回调进行修改，返回QuickThumbnail类，其中包含captureId信息

**访问级别**

其他

**变更原因**

80分图回调顺序不一定正确，导致缩略图和80分图无法正确对应。为快速缩略图新增captureId，基于captureEnd推算80分图的captureId。 

**变更影响**

该变更为不兼容变更。

变更前： 快速缩略图得到的回调是image.PixelMap

变更后： 快速缩略图得到的回调是一个类QuickThumbnail

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.56 版本开始。

**变更的接口/组件**

不涉及

**适配指导**

应用在取用框架返回的回调信息时需要按照QuickThumbnail的类来取用快速缩略图相关信息：

quickthumbnail的类包含

captureId:number

thumbnailImage:image.PixelMap

使用方式例如：

 private async quickThumbnail(err, quickThumbnail: camera.QuickThumbnail): Promise<void> {
    if (!quickThumbnail?.thumbnailImage) {
         HiLog.i(TAG, 'SHOT2SEE quickThumbnail thumbnailImage is null.');
      return;
    }
    if (!quickThumbnail?.captureId) {
      HiLog.i(TAG, 'SHOT2SEE quickThumbnail captureId is null.');
      return;
    }
    HiLog.i(TAG, 'SHOT2SEE quickThumbnail success.');
    if (err) {
      const error = `Camera_quickThumbnail Error: ${err.code}}`;
      HiLog.e(TAG, error);
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
      HiLog.e(TAG, error);
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
本变更修复缩略图和80分图无法正确对应的问题。
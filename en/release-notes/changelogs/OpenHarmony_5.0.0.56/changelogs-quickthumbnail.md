# Multimedia Subsystem Changelog

## cl.multimedia.1 Changed the Return Value Type in the Thumbnail Callback of Camera Kit

**Access Level**

System API

**Reason for Change**

When a user touches a thumbnail after burst shooting, the first-phase image quickly reported by the system for lightweight processing does not match the thumbnail. This is because the image callback sequence in the first phase may be incorrect, resulting in a mismatch between these images and their corresponding thumbnails during callback handling.

**Change Impact**

This change is a non-compatible change.

Before change: The **on('quickThumbnail')** API is used to listen for thumbnail output events, and its callback returns an image.PixelMap object.

After change: The **on('quickThumbnail')** API is used to listen for thumbnail output events, and its callback returns a QuickThumbnail object.

**Start API Level**

10

**Change Since**

OpenHarmony SDK 5.0.0.56

**Key API/Component Changes**

APIs of @ohos.multimedia.camera
- on(type: 'quickThumbnail', callback: AsyncCallback\<image.PixelMap>): void
- off(type: 'quickThumbnail', callback?: AsyncCallback\<image.PixelMap>): void

**Adaptation Guide**

When obtaining the callback information from the framework, the application must obtain the quick thumbnail information based on the **QuickThumbnail** class.

**QuickThumbnail** contains the following fields:
- **captureId:number**: capture ID corresponding to the thumbnail.
- **thumbnailImage:image.PixelMap**: reported thumbnail.

The sample code is as follows:

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
        await mediaLibrary.saveThumbnail(quickThumbnail.thumbnailImage, this.savePhotoFormat); // Save the thumbnail in single-segment mode.
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

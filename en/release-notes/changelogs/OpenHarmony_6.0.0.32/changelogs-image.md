# Image Framework Changelog

## cl.image.1 Changed the Return Value of mimeType in ImageInfo

**Access Level**

Public API

**Reason for Change**

The interface is used for querying image information, and the current return values do not match the actual formats.
- For raw format images, the actual **mimeType** should reflect the true format. Since the current decoding of raw format images results in **previewImage** or **JpgFromRaw** fields, the incorrect value **image/jpeg** is returned.
- For icon format images, the standard name is not used in the return value.

**Impact of the Change**

This change requires application adaptation.

| Actual Format| Return Value Before Change| Return Value After Change| Decoding Support|Encoding Support|
| --- | --- | --- | --- | --- |
|jpeg|image/jpeg|image/jpeg|Supported|Supported|
|icon|image/ico|image/x-icon|Supported|Not supported|
|dng|image/jpeg|image/x-adobe-dng|Supported|Not supported|
|cr2|image/jpeg|image/x-canon-cr2|Decoding of preview supported|Not supported|
|raf|image/jpeg|image/x-fuji-raf|Decoding of preview supported|Not supported|
|nef|image/jpeg|image/x-nikon-nef|Decoding of preview supported|Not supported|
|nrw|image/jpeg|image/x-nikon-nrw|Decoding of preview supported|Not supported|
|orf|image/jpeg|image/x-olympus-orf|Decoding of preview supported|Not supported|
|rw2|image/jpeg|image/x-panasonic-rw2|Decoding of preview supported|Not supported|
|pef|image/jpeg|image/x-pentax-pef|Decoding of preview supported|Not supported|
|srw|image/jpeg|image/x-samsung-srw|Decoding of preview supported|Not supported|
|arw|image/jpeg|image/x-sony-arw|Decoding of preview supported|Not supported|


**Start API Level**

API 12

**Change Since**

OpenHarmony SDK 6.0.0.32

**Key API/Component Changes**

The return value of the **mimeType** parameter in the ImageInfo object is changed.

**Adaptation Guide**

The return value of the image information query interface has changed, but the calling method remains the same.
```js
const context: Context = getContext(this);
// 'test.dng' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
const path: string = context.filesDir + "/test.dng";
const imageSourceApi: image.ImageSource = image.createImageSource(path);
if (imageSourceApi != undefined) {
  imageSourceApi.getImageInfo().then((imageInfo: image.ImageInfo) => {
    console.info("Succeeded in obtaining the image mimeType information.");
    // No need to change the calling method. Update the condition here to match the new return value for actual raw formats.
    if (imageInfo.mimeType == "image/x-adobe-dng") {
      console.info("Image mimeType is image/x-adobe-dng.");
    }
  }).catch((error: BusinessError) => {
    console.error(`Failed to obtain the image information. code is ${error.code}, message is ${error.message}`);
  })
}
```

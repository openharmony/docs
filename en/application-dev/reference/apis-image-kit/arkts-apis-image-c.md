# Constants
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 23. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

## Constants

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Image.Core

| Name                              | Type  | Value  | Description                                                        |
| ---------------------------------- | ------ | ---- | ------------------------------------------------------------ |
| XMAGE_WATERMARK_MODE_AT_THE_BOTTOM | number | 9    | XMAGE watermark mode: The XMAGE watermark is fixed at the bottom center of the image.|
| XMAGE_WATERMARK_MODE_BORDER        | number | 10   | XMAGE watermark mode: The XMAGE watermark is automatically adjusted to a border position, and the system selects the most suitable border area based on the image content.|
| CAPTURE_MODE_PROFESSIONAL | number | 2    | Capture mode: professional.|
| CAPTURE_MODE_FRONT_LENS_NIGHT_VIEW | number | 7    | Capture mode: front camera night mode.|
| CAPTURE_MODE_PANORAMA | number | 8    | Capture mode: panorama.|
| CAPTURE_MODE_TAIL_LIGHT | number | 9 | Capture mode: tail light.|
| CAPTURE_MODE_LIGHT_GRAFFITI | number | 10   | Capture mode: light graffiti.|
| CAPTURE_MODE_SILKY_WATER | number | 11   | Capture mode: silky water flow.|
| CAPTURE_MODE_STAR_TRACK | number | 12   | Capture mode: star track.|
| CAPTURE_MODE_WIDEAPERTURE | number | 19   | Capture mode: wide-angle.|
| CAPTURE_MODE_MOVING_PHOTO | number | 20 | Capture mode: moving photo.|
| CAPTURE_MODE_PORTRAIT | number | 23   | Capture mode: portrait.|
| CAPTURE_MODE_REAR_LENS_NIGHT_VIEW | number | 42   | Capture mode: rear camera night mode.|
| CAPTURE_MODE_SUPER_MACRO | number | 47   | Capture mode: super-macro.|
| CAPTURE_MODE_SNAP_SHOT | number | 62   | Capture mode: snapshot.|
| XMP_BASIC   | [XMPNamespace](arkts-apis-image-i.md#xmpnamespace) | uri: "`http://ns.adobe.com/xap/1.0/`"<br>prefix: "xmp"              | XMP basic namespace.<br>**Since:** 26.0.0|
| XMP_RIGHTS  | [XMPNamespace](arkts-apis-image-i.md#xmpnamespace) | uri: "`http://ns.adobe.com/xap/1.0/rights/`"<br>prefix: "xmpRights" | XMP copyright and permission namespace.<br>**Since:** 26.0.0|
| EXIF        | [XMPNamespace](arkts-apis-image-i.md#xmpnamespace) | uri: "`http://ns.adobe.com/exif/1.0/`"<br>prefix: "exif"            | Exif metadata namespace.<br>**Since:** 26.0.0|
| DUBLIN_CORE | [XMPNamespace](arkts-apis-image-i.md#xmpnamespace) | uri: "`http://purl.org/dc/elements/1.1/`"<br>prefix: "dc"           | Dublin Core metadata namespace.<br>**Since:** 26.0.0|
| TIFF        | [XMPNamespace](arkts-apis-image-i.md#xmpnamespace) | uri: "`http://ns.adobe.com/tiff/1.0/`"<br>prefix: "tiff"            | Namespace of TIFF image format parameters.<br>**Since:** 26.0.0|

## **Example**

### XMAGE Watermark Mode

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function SetXmageWatermarkMode(imageSourceObj : image.ImageSource) {
  let makerNoteHuaweiMetadata = image.MakerNoteHuaweiMetadata.createInstance();
  // Set the XMAGE watermark mode to the bottom center.
  makerNoteHuaweiMetadata.xmageWatermarkMode = image.XMAGE_WATERMARK_MODE_AT_THE_BOTTOM;
  console.info(`Succeeded in setting the XMAGE watermark mode. Mode: ${makerNoteHuaweiMetadata.xmageWatermarkMode}.`);
  await imageSourceObj.writeImageMetadata({ makerNoteHuaweiMetadata: makerNoteHuaweiMetadata }).then(() => {
    console.info(`Succeeded in writing image metadata.`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to write image metadata. Code: ${error.code}, message: ${error.message}.`);
  });
}
```

### Camera Mode

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function SetCaptureMode(imageSourceObj : image.ImageSource) {
  let makerNoteHuaweiMetadata = image.MakerNoteHuaweiMetadata.createInstance();
  // Set the capture mode to professional.
  makerNoteHuaweiMetadata.captureMode = image.CAPTURE_MODE_PROFESSIONAL;
  console.info(`Succeeded in setting the capture mode. Mode: ${makerNoteHuaweiMetadata.captureMode}.`);
  await imageSourceObj.writeImageMetadata({ makerNoteHuaweiMetadata: makerNoteHuaweiMetadata }).then(() => {
    console.info(`Succeeded in writing image metadata.`);
  }).catch((error: BusinessError) => {
    console.error(`Failed to write image metadata. Code: ${error.code}, message: ${error.message}.`);
  });
}
```

### XMP Namespaces

For details about how to use these namespaces, see the examples of the [setValue](arkts-apis-image-XMPMetadata.md#setvalue) and [getTag](arkts-apis-image-XMPMetadata.md#gettag) methods in XMPMetadata.

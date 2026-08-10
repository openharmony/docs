# Module Description

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=786be29b65996bd8b478b081e6eb4fadc7989c4d translatedAt=2026-08-03T03:57:18.376Z pushedAt=2026-08-04T03:45:03.187Z -->

The module provides capabilities for image decoding, encoding, editing, metadata processing, and image receiving.

This module contains the following classes:

- [ImageSource](arkts-apis-image-ImageSource.md): provides the capabilities of obtaining [image information](arkts-apis-image-i.md#imageinfo), decoding images to PixelMaps or Pictures, and reading and modifying [image properties](arkts-apis-image-e.md#propertykey7). [Supported image formats for decoding](arkts-apis-image-ImageSource.md#properties) include png, jpeg, bmp, gif, webp, dng, heic<sup>12+</sup>, wbmp<sup>23+</sup>, heifs<sup>23+</sup>, and tiff<sup>23+</sup>.

- [ImagePacker](arkts-apis-image-ImagePacker.md): provides the capability of encoding images into compressed data streams or files. Encoding requires the ImageSource, PixelMap, or Picture of an image as the input. [Supported image formats for encoding](arkts-apis-image-ImagePacker.md#properties) include jpeg, webp, png, heic<sup>12+</sup>, and gif<sup>18+</sup>.

- [PixelMap](arkts-apis-image-PixelMap.md): contains pixel data and [image information](arkts-apis-image-i.md#imageinfo). It can be used for reading/writing pixel data and performing operations such as cropping, scaling, translating, rotating, and mirroring. It can also be directly passed to the [Image component](../apis-arkui/arkui-ts/ts-basic-components-image.md) for display. Additionally, it provides APIs for obtaining and setting the color gamut and HDR metadata of images.

- [Picture](arkts-apis-image-Picture.md): a multi-picture object composed of a main picture, auxiliary pictures, and metadata. The main picture contains the primary image information; auxiliary pictures store additional information related to the main picture; metadata stores other information related to the image. Picture provides methods for obtaining the main picture, compositing HDR images, obtaining and setting auxiliary pictures, and obtaining and setting metadata.

- [AuxiliaryPicture](arkts-apis-image-AuxiliaryPicture.md): used to display special information alongside the main picture, enriching the overall content of the image. The supported types of auxiliary pictures can be found in [AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13).

- [Metadata](arkts-apis-image-Metadata.md): stores image metadata in key-value format. The supported metadata types can be found in [MetadataType](arkts-apis-image-e.md#metadatatype13), including Exif metadata, fragment map metadata, and HEIF sequence image metadata. For details about the keys of Exif metadata, fragment map metadata, and HEIF sequence image metadata, see [PropertyKey](arkts-apis-image-e.md#propertykey7), [FragmentMapPropertyKey](arkts-apis-image-e.md#fragmentmappropertykey13), and [HeifsPropertyKey](arkts-apis-image-e.md#heifspropertykey23), respectively.

- [ExifMetadata](arkts-apis-image-ExifMetadata.md): stores Exif metadata of images in key-value format. For details about the keys of Exif metadata, see [PropertyKey](arkts-apis-image-e.md#propertykey7).

- [MakerNoteHuaweiMetadata](arkts-apis-image-MakerNoteHuaweiMetadata.md): stores photo metadata defined by Huawei cameras in key-value format. For details about keys of HUAWEI camera-defined photo metadata, see [PropertyKey](arkts-apis-image-e.md#propertykey7).

- [HeifsMetadata](arkts-apis-image-HeifsMetadata.md): stores HEIF sequence image metadata of images in key-value format. For details about keys of HEIF sequence image metadata, see [HeifsPropertyKey](arkts-apis-image-e.md#heifspropertykey23).

- [WebPMetadata](arkts-apis-image-WebPMetadata.md): stores WebP image metadata in key-value format. For details about keys in WebP image metadata, see [WebPPropertyKey](arkts-apis-image-e.md#webppropertykey24).

- [GifMetadata](arkts-apis-image-GifMetadata.md): stores GIF image metadata in key-value format. For details about keys in GIF image metadata, see [GifPropertyKey](arkts-apis-image-e.md#gifpropertykey20).

- [JfifMetadata](arkts-apis-image-JfifMetadata.md): stores JFIF image metadata in key-value format. For details about keys in JFIF image metadata, see [JfifPropertyKey](arkts-apis-image-e.md#jfifpropertykey).

- [TiffMetadata](arkts-apis-image-TiffMetadata.md): stores TIFF image metadata in key-value format. For details about keys in TIFF image metadata, see [TiffPropertyKey](arkts-apis-image-e.md#tiffpropertykey).

- [PngMetadata](arkts-apis-image-PngMetadata.md): stores PNG image metadata in key-value format. For details about keys in PNG image metadata, see [PngPropertyKey](arkts-apis-image-e.md#pngpropertykey).

- [AvisMetadata](arkts-apis-image-AvisMetadata.md): stores AVIS image metadata in key-value format. For details about keys in AVIS image metadata, see [AvisPropertyKey](arkts-apis-image-e.md#avispropertykey).

- [ImageReceiver](arkts-apis-image-ImageReceiver.md): acts as an image consumer to receive and read images from a surface.

- [ImageCreator](arkts-apis-image-ImageCreator.md): acts as an image producer to write images into a surface.

- [Image](arkts-apis-image-Image.md): used by ImageReceiver and ImageCreator for transferring image objects, with the actual content determined by the producer. For example, the image object provided by a camera preview stream contains YUV data, whereas the image object provided by a camera photo contains a JPEG file.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```
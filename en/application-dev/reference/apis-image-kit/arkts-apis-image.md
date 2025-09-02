# Module Description
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The module provides capabilities for image decoding, encoding, editing, metadata processing, and image receiving.

This module contains the following classes:

- [ImageSource](arkts-apis-image-ImageSource.md): provides the capabilities of obtaining [image information](arkts-apis-image-i.md#imageinfo), decoding images to PixelMaps or Pictures, and reading and modifying [image properties](arkts-apis-image-e.md#propertykey7). [Supported image formats for decoding](arkts-apis-image-ImageSource.md#properties) include png, jpeg, bmp, gif, webp, dng, and heic<sup>12+</sup>.

- [ImagePacker](arkts-apis-image-ImagePacker.md): provides the capability of encoding images into compressed data streams or files. Encoding requires the ImageSource, PixelMap, or Picture of an image as the input. [Supported image formats for encoding](arkts-apis-image-ImagePacker.md#properties) include jpeg, webp, png, heic<sup>12+</sup>, and gif<sup>18+</sup>.

- [PixelMap](arkts-apis-image-PixelMap.md): contains pixel data and [image information](arkts-apis-image-i.md#imageinfo). It can be used for reading/writing pixel data and performing operations such as cropping, scaling, translating, rotating, and mirroring. It can also be directly passed to the [Image component](../apis-arkui/arkui-ts/ts-basic-components-image.md) for display. Additionally, it provides APIs for obtaining and setting the color gamut and HDR metadata of images.

- [Picture](arkts-apis-image-Picture.md): a multi-picture object composed of a main picture, auxiliary pictures, and metadata. The main picture contains the primary image information; auxiliary pictures store additional information related to the main picture; metadata stores other information related to the image. Picture provides methods for obtaining the main picture, compositing HDR images, obtaining and setting auxiliary pictures, and obtaining and setting metadata.

- [AuxiliaryPicture](arkts-apis-image-AuxiliaryPicture.md): used to display special information alongside the main picture, enriching the overall content of the image. The supported types of auxiliary pictures can be found in [AuxiliaryPictureType](arkts-apis-image-e.md#auxiliarypicturetype13).

- [Metadata](arkts-apis-image-Metadata.md): used to store image metadata. The supported metadata types can be found in [MetadataType](arkts-apis-image-e.md#metadatatype13). It includes EXIF metadata and watermark cropping metadata, both stored in Key-Value pairs. The keys for EXIF metadata can be found in [PropertyKey](arkts-apis-image-e.md#propertykey7), and the keys for watermark cropping metadata can be found in [FragmentPropertyKey](arkts-apis-image-e.md#fragmentmappropertykey13).

- [ImageReceiver](arkts-apis-image-ImageReceiver.md): acts as a consumer of images, used for receiving and reading images from a surface.

- [ImageCreator](arkts-apis-image-ImageCreator.md): acts as a producer of images, used for writing images into a surface.

- [Image](arkts-apis-image-Image.md): used by ImageReceiver and ImageCreator for transferring image objects, with the actual content determined by the producer. For example, the Image object provided by a camera preview stream contains YUV data, whereas the Image object provided by a camera photo contains a JPEG file.

## Modules to Import

```ts
import { image } from '@kit.ImageKit';
```

# Types

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=c8ffbd9c829ae140605625a64c8182ad6cceaa74 translatedAt=2026-08-11T01:59:33.758Z pushedAt=2026-08-12T01:08:17.058Z -->

> **NOTE**
>
> The initial APIs of this module are supported since API version 23. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ImageType

type ImageType = image.Image | image.Picture

Defines the image container type, which is used to obtain full-quality images or uncompressed images (YUV).

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Type     | Description                                                           |
|---------|---------------------------------------------------------------|
| [image.Image](../apis-image-kit/arkts-apis-image-Image.md) | Image container type that obtains full-quality images.|
| [image.Picture](../apis-image-kit/arkts-apis-image-Picture.md) | Image container type that obtains uncompressed images (YUV).|
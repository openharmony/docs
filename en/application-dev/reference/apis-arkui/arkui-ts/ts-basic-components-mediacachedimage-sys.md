# MediaCachedImage (System API)

The **MediaCachedImage** component, with APIs that inherit from [Image](ts-basic-components-image.md) and the added capability of loading texture resources (for system applications only), is typically used to display images in applications.

> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## APIs

MediaCachedImage(src: PixelMap | ResourceStr | DrawableDescriptor | ASTCResource)

Obtains an image from the specified source for subsequent rendering and display.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                    | Mandatory| Description                                                    |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| src    | [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) \| [ResourceStr](ts-types.md#resourcestr) \| [DrawableDescriptor](../js-apis-arkui-drawableDescriptor.md#drawabledescriptor) \| [ASTCResource](#astcresource12) | Yes  | Data source of the image. Media library resources are supported. For details about how to reference an image of the PixelMap, ResourceStr, or DrawableDescriptor type, see [Loading Image Resources](../../../ui/arkts-graphics-display.md#loading-image-resources). The ASTCResource type is available for system applications only.|

## ASTCResource<sup>12+</sup>

Describes texture stitching.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type   | Description                                     |
| ------- | ----------------------------------------- |
| sources | URI array, indicating the textures to be stitched.|
| column  | Column size, indicating the number of textures to be stitched in each row.   |

## Example

 This example loads images of basic types.

```ts
@Entry
@Component
struct MediaCachedImageExample {
  build() {
    Column() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
        Row() {
          // Load a PNG image.
          MediaCachedImage($r('app.media.ic_camera_master_ai_leaf'))
            .width(110).height(110).margin(15)
            .overlay('png', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          // Load a GIF image.
          MediaCachedImage($r('app.media.loading'))
            .width(110).height(110).margin(15)
            .overlay('gif', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }
        Row() {
          // Load an SVG image.
          MediaCachedImage($r('app.media.ic_camera_master_ai_clouded'))
            .width(110).height(110).margin(15)
            .overlay('svg', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          // Load a JPG image.
          MediaCachedImage($r('app.media.ic_public_favor_filled'))
            .width(110).height(110).margin(15)
            .overlay('jpg', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }
      }
    }.height(320).width(360).padding({ right: 10, top: 10 })
  }
}
```

![en-us_image_0000001592882500](figures/en-us_image_0000001592882500.gif)

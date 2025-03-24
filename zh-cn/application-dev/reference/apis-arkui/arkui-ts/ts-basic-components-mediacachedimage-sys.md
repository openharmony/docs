# MediaCachedImage（系统接口）

MediaCachedImage继承自[Image](ts-basic-components-image.md)，新增了纹理资源的加载能力（仅限系统应用），常用于应用中显示图片。

> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 本模块为系统接口

## 接口

MediaCachedImage(src: PixelMap | ResourceStr | DrawableDescriptor | ASTCResource)

通过图片数据源获取图片，用于后续渲染展示。

**系统接口：** 此接口为系统接口

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 参数类型                                                     | 必填 | 参数描述                                                     |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| src    | [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7)&nbsp;\|&nbsp;[ResourceStr](ts-types.md#resourcestr)&nbsp;\|&nbsp;[DrawableDescriptor](../js-apis-arkui-drawableDescriptor.md#drawabledescriptor)&nbsp;\|&nbsp;[ASTCResource](#astcresource12) | 是   | 图片的数据源，支持媒体库资源，PixelMap、ResourceStr、DrawableDescriptor的引用方式可参考Image的[加载图片资源](../../../ui/arkts-graphics-display.md#加载图片资源)，ASTCResource为纹理资源，只支持系统应用。 |

## ASTCResource<sup>12+</sup>

纹理类型，用于设置纹理拼接的属性值。

**系统接口：** 此接口为系统接口

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型    | 说明                                      |
| ------- | ----------------------------------------- |
| sources | uri资源数组，表示进行拼接的纹理资源信息。 |
| column  | 列大小，表示每行要拼接的纹理资源个数。    |

## 示例

 加载基本类型图片

```ts
@Entry
@Component
struct MediaCachedImageExample {
  build() {
    Column() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
        Row() {
          // 加载png格式图片
          MediaCachedImage($r('app.media.ic_camera_master_ai_leaf'))
            .width(110).height(110).margin(15)
            .overlay('png', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          // 加载gif格式图片
          MediaCachedImage($r('app.media.loading'))
            .width(110).height(110).margin(15)
            .overlay('gif', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }
        Row() {
          // 加载svg格式图片
          MediaCachedImage($r('app.media.ic_camera_master_ai_clouded'))
            .width(110).height(110).margin(15)
            .overlay('svg', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          // 加载jpg格式图片
          MediaCachedImage($r('app.media.ic_public_favor_filled'))
            .width(110).height(110).margin(15)
            .overlay('jpg', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }
      }
    }.height(320).width(360).padding({ right: 10, top: 10 })
  }
}
```

![zh-cn_image_0000001592882500](figures/zh-cn_image_0000001592882500.gif)
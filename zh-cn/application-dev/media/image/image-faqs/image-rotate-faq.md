# 如何获取图片的旋转角度信息

## 图片旋转角度介绍

在数码摄影中，拍摄设备（如手机、相机）会将图片的旋转角度（方向）信息保存在图片的EXIF（Exchangeable Image File Format）数据的Orientation字段。该信息不会直接改变图片的像素内容，但会告诉图像查看器如何正确地显示图像方向。

EXIF标准定义了Orientation值，它们对应的字符串表示与操作说明如下表：

| 值     | 字符串表示      | 操作说明                        |
|--------|----------------|--------------------------------|
| 1      | "Top-left"     | 正常方向（无需旋转）。           |
| 2      | "Top-right"    | 水平镜像翻转。                   |
| 3      | "Bottom-right" | 旋转180°。                      |
| 4      | "Bottom-left"  | 垂直镜像翻转。                   |
| 5      | "Left-top"     | 先水平镜像翻转，再顺时针旋转270°。|
| 6      | "Right-top"    | 顺时针旋转90°。                 |
| 7      | "Right-bottom" | 先水平镜像翻转，再顺时针旋转90°。 |
| 8      | "Left-bottom"  | 顺时针旋转270°。                |

ArkTS场景下读取和编辑图片的旋转角度信息，可参考：[编辑图片EXIF信息(ArkTs)](../image-tool.md)，对应的propertyKey需要设置为：ORIENTATION。

C/C++场景下读取和编辑图片的旋转角度信息，可参考：[使用Image_NativeModule编辑图片EXIF信息](../image-tool-c.md)，对应的key需要设置为：OHOS_IMAGE_PROPERTY_ORIENTATION。

## 常见问题

### 读取图片旋转角度为空怎么办

部分图片可能没有EXIF数据，或者EXIF数据中没有写入Orientation字段，这些图片无需旋转（与Orientation值为1的情况保持一致）。

### 为什么会出现EXIF数据丢失

与图片来源有关，网络传输的图片可能进行了二次编码，在编码时未保存EXIF数据，导致无法获取旋转角度。

### 图片编码时，如何保存EXIF数据

在调用图片编码接口时，需要设置[packingOption](../../../reference/apis-image-kit/arkts-apis-image-i.md#packingoption)的needsPackProperties属性为true（该属性的默认值为false）。

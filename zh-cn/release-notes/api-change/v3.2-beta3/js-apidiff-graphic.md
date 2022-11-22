# 图形图像子系统JS API变更

OpenHarmony 3.2 Beta3版本相较于OpenHarmony 3.2 Beta2版本，图形图像子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.graphics.colorSpaceManager | colorSpaceManager   | function create(colorSpaceName: ColorSpace): ColorSpaceManager;<br>function create(primaries: ColorSpacePrimaries, gamma: number): ColorSpaceManager; | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpaceManager   | getGamma(): number;                                                                                                                                   | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpaceManager   | getWhitePoint(): Array\<number>;                                                                                                                      | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpaceManager   | getColorSpaceName(): ColorSpace;                                                                                                                      | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | whitePointY: number;                                                                                                                                  | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | whitePointX: number;                                                                                                                                  | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | blueY: number;                                                                                                                                        | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | blueX: number;                                                                                                                                        | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | greenY: number;                                                                                                                                       | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | greenX: number;                                                                                                                                       | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | redY: number;                                                                                                                                         | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | redX: number;                                                                                                                                         | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpace          | CUSTOM = 5                                                                                                                                            | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpace          | SRGB = 4                                                                                                                                              | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpace          | DISPLAY_P3 = 3                                                                                                                                        | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpace          | DCI_P3 = 2                                                                                                                                            | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpace          | ADOBE_RGB_1998 = 1                                                                                                                                    | 新增 |
| ohos.graphics.colorSpaceManager | ColorSpace          | UNKNOWN = 0                                                                                                                                           | 新增 |
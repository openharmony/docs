# JS API Changes of the Graphics Subsystem

The table below lists the APIs changes of the graphics subsystem in OpenHarmony 3.2 Beta3 over OpenHarmony 3.2 Beta2.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.graphics.colorSpaceManager | colorSpaceManager   | function create(colorSpaceName: ColorSpace): ColorSpaceManager;<br>function create(primaries: ColorSpacePrimaries, gamma: number): ColorSpaceManager; | Added|
| ohos.graphics.colorSpaceManager | ColorSpaceManager   | getGamma(): number;                                                                                                                                   | Added|
| ohos.graphics.colorSpaceManager | ColorSpaceManager   | getWhitePoint(): Array\<number>;                                                                                                                      | Added|
| ohos.graphics.colorSpaceManager | ColorSpaceManager   | getColorSpaceName(): ColorSpace;                                                                                                                      | Added|
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | whitePointY: number;                                                                                                                                  | Added|
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | whitePointX: number;                                                                                                                                  | Added|
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | blueY: number;                                                                                                                                        | Added|
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | blueX: number;                                                                                                                                        | Added|
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | greenY: number;                                                                                                                                       | Added|
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | greenX: number;                                                                                                                                       | Added|
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | redY: number;                                                                                                                                         | Added|
| ohos.graphics.colorSpaceManager | ColorSpacePrimaries | redX: number;                                                                                                                                         | Added|
| ohos.graphics.colorSpaceManager | ColorSpace          | CUSTOM = 5                                                                                                                                            | Added|
| ohos.graphics.colorSpaceManager | ColorSpace          | SRGB = 4                                                                                                                                              | Added|
| ohos.graphics.colorSpaceManager | ColorSpace          | DISPLAY_P3 = 3                                                                                                                                        | Added|
| ohos.graphics.colorSpaceManager | ColorSpace          | DCI_P3 = 2                                                                                                                                            | Added|
| ohos.graphics.colorSpaceManager | ColorSpace          | ADOBE_RGB_1998 = 1                                                                                                                                    | Added|
| ohos.graphics.colorSpaceManager | ColorSpace          | UNKNOWN = 0                                                                                                                                           | Added|

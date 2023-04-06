# 图形图像子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，图形图像子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.effectKit | effectKit | createColorPicker(source: image.PixelMap): Promise\<ColorPicker>;<br>function createColorPicker(source: image.PixelMap, callback: AsyncCallback\<ColorPicker>): void; | 新增 |
| ohos.effectKit | effectKit | createEffect(source: image.PixelMap): Filter; | 新增 |
| ohos.effectKit | Color | alpha: number; | 新增 |
| ohos.effectKit | Color | blue: number; | 新增 |
| ohos.effectKit | Color | green: number; | 新增 |
| ohos.effectKit | Color | red: number; | 新增 |
| ohos.effectKit | ColorPicker | getMainColorSync(): Color; | 新增 |
| ohos.effectKit | ColorPicker | getMainColor(): Promise\<Color>; | 新增 |
| ohos.effectKit | Filter | getPixelMap(): image.PixelMap; | 新增 |
| ohos.effectKit | Filter | grayscale(): Filter; | 新增 |
| ohos.effectKit | Filter | brightness(bright:number): Filter; | 新增 |
| ohos.effectKit | Filter | blur(radius:number): Filter; | 新增 |
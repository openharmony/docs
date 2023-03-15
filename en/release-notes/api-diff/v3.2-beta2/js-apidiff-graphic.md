# JS API Changes of the Graphics Subsystem

The table below lists the APIs changes of the graphics subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.effectKit | effectKit | createColorPicker(source: image.PixelMap): Promise\<ColorPicker>;<br>function createColorPicker(source: image.PixelMap, callback: AsyncCallback\<ColorPicker>): void; | Added|
| ohos.effectKit | effectKit | createEffect(source: image.PixelMap): Filter; | Added|
| ohos.effectKit | Color | alpha: number; | Added|
| ohos.effectKit | Color | blue: number; | Added|
| ohos.effectKit | Color | green: number; | Added|
| ohos.effectKit | Color | red: number; | Added|
| ohos.effectKit | ColorPicker | getMainColorSync(): Color; | Added|
| ohos.effectKit | ColorPicker | getMainColor(): Promise\<Color>; | Added|
| ohos.effectKit | Filter | getPixelMap(): image.PixelMap; | Added|
| ohos.effectKit | Filter | grayscale(): Filter; | Added|
| ohos.effectKit | Filter | brightness(bright:number): Filter; | Added|
| ohos.effectKit | Filter | blur(radius:number): Filter; | Added|

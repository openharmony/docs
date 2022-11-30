# Pixel Units

The framework provides four pixel units, with vp as the reference data unit.


| Name| Description                                                        |
| ---- | ------------------------------------------------------------ |
| px   | Physical pixel unit of the screen.                                          |
| vp   | Pixel unit specific to the screen density. Pixels in this unit are converted into physical pixels of the screen based on the screen pixel density. This unit is used for values whose unit is not specified.|
| fp   | Font pixel, which is similar to vp and varies according to the system font size.|
| lpx  | Logical pixel unit of the window. It is the ratio of the actual screen width to the logical width (configured by **[designWidth](../../quick-start/package-structure.md)**). For example, if **designWidth** is set to **720** (default value), then 1lpx is equal to 2px for a screen with an actual width of 1440 physical pixels.|


## Pixel Unit Conversion

Conversion between px and other pixel units is supported.

| API                                      | Description                    |
| ---------------------------------------- | ---------------------- |
| vp2px(value : number) : number | Converts a value in units of vp to a value in units of px. |
| px2vp(value : number) : number | Converts a value in units of px to a value in units of vp. |
| fp2px(value : number) : number | Converts a value in units of fp to a value in units of px. |
| px2fp(value : number) : number | Converts a value in units of px to a value in units of fp. |
| lpx2px(value : number) : number | Converts a value in units of lpx to a value in units of px.|
| px2lpx(value : number) : number | Converts a value in units of px to a value in units of lpx.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct Example {
  build() {
    Column() {
      Flex({ wrap: FlexWrap.Wrap }) {
        Column() {
          Text("width(220)")
            .width(220).height(40).backgroundColor(0xF9CF93)
            .textAlign(TextAlign.Center).fontColor(Color.White).fontSize('12vp')
        }.margin(5)
        Column() {
          Text("width('220px')")
            .width('220px').height(40).backgroundColor(0xF9CF93)
            .textAlign(TextAlign.Center).fontColor(Color.White)
        }.margin(5)
        Column() {
          Text("width('220vp')")
            .width('220vp').height(40).backgroundColor(0xF9CF93)
            .textAlign(TextAlign.Center).fontColor(Color.White).fontSize('12vp')
        }.margin(5)
        Column() {
          Text("width('220lpx') designWidth:720")
            .width('220lpx').height(40).backgroundColor(0xF9CF93)
            .textAlign(TextAlign.Center).fontColor(Color.White).fontSize('12vp')
        }.margin(5)
        Column() {
          Text("width(vp2px(220) + 'px')")
            .width(vp2px(220) + 'px').height(40).backgroundColor(0xF9CF93)
            .textAlign(TextAlign.Center).fontColor(Color.White).fontSize('12vp')
        }.margin(5)
        Column() {
          Text("fontSize('12fp')")
            .width(220).height(40).backgroundColor(0xF9CF93)
            .textAlign(TextAlign.Center).fontColor(Color.White).fontSize('12fp')
        }.margin(5)
      }.width('100%')
    }
  }
}
```

![en-us_image_0000001169582302](figures/en-us_image_0000001169582302.png)

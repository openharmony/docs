# Class (SwiperDynamicSyncScene)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Hu_ZeQi-->
<!--Designer: @jiangdayuan-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

提供Swiper组件相关帧率的配置。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 12开始支持。
>
> - SwiperDynamicSyncScene继承自[DynamicSyncScene](arkts-apis-uicontext-dynamicsyncscene.md)，对应Swiper的动态帧率场景。

## 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

| 名称       | 类型                                                      | 只读 | 可选 | 说明                                |
| --------- | --------------------------------------------------------- | ---- | ---- | ---------------------------------- |
| type<sup>12+</sup>      | [SwiperDynamicSyncSceneType](./arkts-apis-uicontext-e.md#swiperdynamicsyncscenetype12) | 是   | 否   | Swiper的动态帧率场景。             |

**示例：**

```ts
import { SwiperDynamicSyncSceneType, SwiperDynamicSyncScene } from '@kit.ArkUI';

@Entry
@Component
struct Frame {
  @State ANIMATION: ExpectedFrameRateRange = { min: 0, max: 120, expected: 90 };
  @State GESTURE: ExpectedFrameRateRange = { min: 0, max: 120, expected: 30};
  private scenes: SwiperDynamicSyncScene[] = [];

  build() {
    Column() {
      Text("动画"+ JSON.stringify(this.ANIMATION))
      Text("跟手"+ JSON.stringify(this.GESTURE))
      Row(){
        Swiper() {
          Text("one")
          Text("two")
          Text("three")
        }
        .width('100%')
        .height('300vp')
        .id("dynamicSwiper")
        .backgroundColor(Color.Blue)
        .autoPlay(true)
        .onAppear(()=>{
          let scenes = this.getUIContext().requireDynamicSyncScene("dynamicSwiper") as SwiperDynamicSyncScene[];
          if (scenes) {
            this.scenes = scenes;
          }
        })
      }

      Button("set frame")
        .onClick(() => {
          this.scenes.forEach((scenes: SwiperDynamicSyncScene) => {

            if (scenes.type == SwiperDynamicSyncSceneType.ANIMATION) {
              scenes.setFrameRateRange(this.ANIMATION);
            }

            if (scenes.type == SwiperDynamicSyncSceneType.GESTURE) {
              scenes.setFrameRateRange(this.GESTURE);
            }
          });
        })
    }
  }
}
```
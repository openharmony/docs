# @ohos.advertising.AdComponent (非全屏广告展示组件)

本模块提供展示非全屏广告的能力。

> **说明：**<br/>
> 本模块首批接口从API Version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { AdComponent } from '@kit.AdsKit';
```

## AdComponent

AdComponent(ads: advertising.Advertisement[], displayOptions: advertising.AdDisplayOptions, interactionListener: advertising.AdInteractionListener, @BuilderParam adRenderer?: () => void, @Prop rollPlayState?: number): void

展示非全屏广告。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名                      | 类型                                                                              | 必填 | 说明                                                                                              |
|-----------------------------|-----------------------------------------------------------------------------------|-----|-------------------------------------------------------------------------------------------------|
| ads                         | advertising.[Advertisement](js-apis-advertising.md#advertisement)[]               | 是   | 广告对象数组。<br/>原子化服务API：从API version 12开始，该接口支持在原子化服务中使用。                |
| displayOptions              | advertising.[AdDisplayOptions](js-apis-advertising.md#addisplayoptions)           | 是   | 广告展示参数。<br/>原子化服务API：从API version 12开始，该接口支持在原子化服务中使用。                |
| interactionListener         | advertising.[AdInteractionListener](js-apis-advertising.md#adinteractionlistener) | 是   | 广告状态变化回调。<br/>原子化服务API：从API version 12开始，该接口支持在原子化服务中使用。            |
| adRenderer<sup>12+</sup>    | () => void                                                                        | 否   | 应用自渲染广告样式。                                                                               |
| rollPlayState<sup>15+</sup> | number                                                                            | 否   | 用于对外提供贴片广告播放状态，设置1为播放，2为暂停，其他值为非法值，不改变之前的播放状态。不填默认为2。 |

**示例：**

```ts
import { AdComponent, advertising } from '@kit.AdsKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  // 请求到的广告内容
  private ads: advertising.Advertisement[] = [];
  // 广告展示参数
  private adDisplayOptions: advertising.AdDisplayOptions = {
    // 是否静音，默认不静音
    mute: false
  };

  build() {
    Column() {
      // AdComponent组件用于展示非全屏广告
      AdComponent({
        ads: this.ads,
        displayOptions: this.adDisplayOptions,
        interactionListener: {
          // 广告状态变化回调
          onStatusChanged: (status: string, ad: advertising.Advertisement, data: string) => {
            switch (status) {
              case 'onAdOpen':
                hilog.info(0x0000, 'testTag', 'onAdOpen');
                break;
              case 'onAdClick':
                hilog.info(0x0000, 'testTag', 'onAdClick');
                break;
              case 'onAdClose':
                hilog.info(0x0000, 'testTag', 'onAdClose');
                break;
            }
          }
        }
      })
        .width('100%')
        .height('100%')
    }
    .width('100%')
    .height('100%')
  }
}
```
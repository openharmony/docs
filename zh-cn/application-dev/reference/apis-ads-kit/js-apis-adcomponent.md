# @ohos.advertising.AdComponent (广告展示组件)

<!--Kit: Ads Kit-->
<!--Subsystem: Advertising-->
<!--Owner: @SukiEvas-->
<!--Designer: @zhansf1988-->
<!--Tester: @hongmei_may-->
<!--Adviser: @RayShih-->

本模块提供展示广告的能力。

> **说明：**<br/>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { AdComponent } from '@kit.AdsKit';
```

## AdComponent

```ts
AdComponent({
  ads: advertising.Advertisement[],
  displayOptions: advertising.AdDisplayOptions,
  interactionListener: advertising.AdInteractionListener,
  @BuilderParam adRenderer?: () => void,
  @Prop rollPlayState?: number
})
```

**装饰器类型：** @Component

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 名称                        | 类型                                                                              | 必填 | 装饰器类型    | 说明                                                                                                                |
|-----------------------------|-----------------------------------------------------------------------------------|-----|---------------|-------------------------------------------------------------------------------------------------------------------|
| ads                         | advertising.[Advertisement](js-apis-advertising.md#advertisement)[]               | 是   | -             | 广告对象数组。<br/>原子化服务API：从API version 12开始，该接口支持在原子化服务中使用。                                  |
| displayOptions              | advertising.[AdDisplayOptions](js-apis-advertising.md#addisplayoptions)           | 是   | -             | 广告展示参数。<br/>原子化服务API：从API version 12开始，该接口支持在原子化服务中使用。                                  |
| interactionListener         | advertising.[AdInteractionListener](js-apis-advertising.md#adinteractionlistener) | 是   | -             | 广告状态变化回调。<br/>原子化服务API：从API version 12开始，该接口支持在原子化服务中使用。                              |
| adRenderer<sup>12+</sup>    | () => void                                                                        | 否   | @BuilderParam | 应用自渲染广告样式。                                                                                                 |
| rollPlayState<sup>15+</sup> | number                                                                            | 否   | @Prop         | 用于对外提供贴片广告的播放状态。设置为1表示播放，设置为2表示暂停。默认值为2。其他值被视为非法值，不会改变当前的播放状态。 |

### build

build(): void

用于创建AdComponent对象的构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

## 示例

该示例代码实现了广告的展示。

```ts
import { AdComponent, advertising } from '@kit.AdsKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  // 请求到的广告内容
  private ads: advertising.Advertisement[] = [];
  // 广告展示参数
  private adDisplayOptions: advertising.AdDisplayOptions = {};

  build() {
    Column() {
      AdComponent({
        ads: this.ads,
        displayOptions: this.adDisplayOptions,
        interactionListener: {
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
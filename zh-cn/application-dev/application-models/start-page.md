# 启动指定页面

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @lidongrui-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

<!--deprecated_code_no_check-->

当PageAbility的启动模式设置为单例时（具体设置方法和典型场景示例见[PageAbility的启动模式](pageability-launch-type.md)，缺省情况下是单实例模式），若PageAbility已被拉起，再次启动PageAbility会触发onNewWant回调（即非首次拉起）。应用开发者可以通过want传递启动参数，例如开发者希望指定页面启动PageAbility，可以通过want中的parameters参数传递pages信息，具体示例代码如下：


调用方PageAbility的app.ets中或者page中，使用startAbility再次拉起PageAbility，通过want中的uri参数传递页面信息：

```ts
import featureAbility from '@ohos.ability.featureAbility';
import Want from '@ohos.app.ability.Want';
import hilog from '@ohos.hilog';

const TAG: string = 'PagePageAbilityFirst';
const domain: number = 0xFF00;
```
```ts
(async (): Promise<void> => {
  let wantInfo: Want = {
    bundleName: 'com.samples.famodelabilitydevelop',
    abilityName: 'com.samples.famodelabilitydevelop.PageAbilitySingleton',
    parameters: { page: 'pages/second' }
  };
  featureAbility.startAbility({ want: wantInfo }).then((data) => {
    hilog.debug(domain, TAG, `restartAbility success : ${data}`);
  });
})()
```


在目标端PageAbility的onNewWant回调中获取包含页面信息的want参数：

```ts
// GlobalContext.ts 构造单例对象
export class GlobalContext {
  private constructor() {
  }

  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}
```

```ts
import Want from '@ohos.app.ability.Want';
import featureAbility from '@ohos.ability.featureAbility';
import { GlobalContext } from '../utils/GlobalContext';

class PageAbilitySingleton {
  onNewWant(want: Want) {
    featureAbility.getWant().then((want) => {
      GlobalContext.getContext().setObject('newWant', want);
    })
  }
}

export default new PageAbilitySingleton();
```


在目标端页面的自定义组件中获取包含页面信息的want参数并根据uri做路由处理：

```ts
import Want from '@ohos.app.ability.Want';
import router from '@ohos.router';
import { GlobalContext } from '../../utils/GlobalContext';

@Entry
@Component
struct First {
  onPageShow() {
    let newWant = GlobalContext.getContext().getObject('newWant') as Want;
    if (newWant) {
      if (newWant.parameters) {
        if (newWant.parameters.page) {
          router.pushUrl({ url: newWant.parameters.page as string});
          GlobalContext.getContext().setObject("newWant", undefined)
        }
      }
    }
  }

  build() {
    Column() {
      Row() {
        Text('singleton_first_title')
          .fontSize(24)
          .fontWeight(FontWeight.Bold)
          .textAlign(TextAlign.Start)
          .margin({ top: 12, bottom: 11, right: 24, left: 24 })
      }
      .width('100%')
      .height(56)
      .justifyContent(FlexAlign.Start)

      Image('pic_empty')
        .width(120)
        .height(120)
        .margin({ top: 224 })

      Text('no_content')
        .fontSize(14)
        .margin({ top: 8, bottom: 317, right: 152, left: 152 })
        .fontColor('text_color')
        .opacity(0.4)
    }
    .width('100%')
    .height('100%')
    .backgroundColor('backGrounding')
  }
}
```


当PageAbility的启动模式设置为多实例模式或为首次启动单例模式的PageAbility时（具体设置方法和典型场景示例见[PageAbility的启动模式](pageability-launch-type.md)），在调用方PageAbility中，通过want中的parameters参数传递要启动的指定页面的pages信息，调用startAbility()方法启动PageAbility。被调用方可以在onCreate中使用featureAbility的getWant方法获取want，再通过调用router.pushUrl实现启动指定页面。


调用方的页面中实现按钮点击触发startAbility方法启动目标端PageAbility，startAbility方法的入参want中携带指定页面信息，示例代码如下：

```ts
import featureAbility from '@ohos.ability.featureAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
import fs from '@ohos.file.fs';
import promptAction from '@ohos.promptAction';
import worker from '@ohos.worker';
import hilog from '@ohos.hilog';

const TAG: string = 'PagePageAbilityFirst';
const domain: number = 0xFF00;

@Entry
@Component
struct PagePageAbilityFirst {
  build() {
    Column() {
      //...
      List({ initialIndex: 0 }) {
        //...
        ListItem() {
          Flex({ justifyContent: FlexAlign.SpaceBetween, alignContent: FlexAlign.Center }) {
          //...
          }
          .onClick(() => {
            let want: Want = {
              bundleName: 'com.samples.famodelabilitydevelop',
              abilityName: 'com.samples.famodelabilitydevelop.PageAbilityStandard',
              parameters: { page: 'pages/first' }
            };
            featureAbility.startAbility({ want: want }).then((data) => {
              hilog.info(domain, TAG, `startAbility finish:${data}`);
            }).catch((err: BusinessError) => {
              hilog.info(domain, TAG, `startAbility failed errcode:${err.code}`);
            })
          })
        }
        //...
        ListItem() {
          Flex({ justifyContent: FlexAlign.SpaceBetween, alignContent: FlexAlign.Center }) {
          //...
          }
          .onClick(() => {
            let want: Want = {
              bundleName: 'com.samples.famodelabilitydevelop',
              abilityName: 'com.samples.famodelabilitydevelop.PageAbilityStandard',
              parameters: { page: 'pages/second' }
            };
            featureAbility.startAbility({ want: want }).then((data) => {
              hilog.info(domain, TAG, `startAbility finish:${data}`);
            }).catch((err: BusinessError) => {
              hilog.info(domain, TAG, `startAbility failed errcode:${err.code}`);
            })
          })
        }
        //...
      }
      //...
    }
    //...
  }
}
```


目标端PageAbility的onCreate生命周期回调中通过featureAbility的getWant方法获取want，并对参数进行解析，实现指定页面拉起：

```ts
import featureAbility from '@ohos.ability.featureAbility';
import router from '@ohos.router';

class PageAbilityStandard {
  onCreate() {
    featureAbility.getWant().then((want) => {
      if (want.parameters) {
        if (want.parameters.page) {
          router.pushUrl({ url: want.parameters.page as string });
        }
      }
    })
  }
}

export default new PageAbilityStandard();
```

# Starting a Specified Page


When the launch type of a PageAbility is set to **singleton** (default), the **onNewWant()** callback is triggered if the PageAbility is not started for the first time. For details about the launch type, see [PageAbility Launch Type](pageability-launch-type.md). In this case, you can use the **want** parameter to transfer startup information. For example, if you want to start a PageAbility with a specified page, pass the pages information in **parameters** of **want**.


In **app.ets** or **page** of the caller PageAbility, use **startAbility()** to start the PageAbility again, with the page information passed in the **uri** parameter in **want**.

```ts
import featureAbility from '@ohos.ability.featureAbility';
import Want from '@ohos.app.ability.Want';
```
```ts
(async (): Promise<void> => {
  let wantInfo: Want = {
    bundleName: 'com.samples.famodelabilitydevelop',
    abilityName: 'com.samples.famodelabilitydevelop.PageAbilitySingleton',
    parameters: { page: 'pages/second' }
  };
  featureAbility.startAbility({ want: wantInfo }).then((data) => {
    Logger.debug(TAG, `restartAbility success : ${data}`);
  });
})()
```


Obtain the **want** parameter that contains the page information from the **onNewWant()** callback of the target PageAbility.

```ts
// Construct a singleton object in GlobalContext.ts.
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
import bundle from '@ohos.bundle';
import { GlobalContext } from '../utils/GlobalContext';
import Logger from '../utils/Logger';

const TAG: string = 'PageAbilitySingleton';

class PageAbilitySingleton {
  onCreate() {
    ...
    Logger.info(TAG, 'Application onCreate');
  }

  onDestroy() {
    Logger.info(TAG, 'Application onDestroy');
  }

  onNewWant(want: Want) {
    featureAbility.getWant().then((want) => {
      GlobalContext.getContext().setObject('newWant', want);
    })
  }
}

export default new PageAbilitySingleton();
```


Obtain the **want** parameter that contains the page information from the custom component of the target PageAbility and process the route based on the URI.

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
          router.push({ url: newWant.parameters.page as string});
          GlobalContext.getContext().setObject("newWant", undefined)
        }
      }
    }
  }

  build() {
    Column() {
      Row() {
        Text($r('app.string.singleton_first_title'))
          .fontSize(24)
          .fontWeight(FontWeight.Bold)
          .textAlign(TextAlign.Start)
          .margin({ top: 12, bottom: 11, right: 24, left: 24 })
      }
      .width('100%')
      .height(56)
      .justifyContent(FlexAlign.Start)

      Image($r('app.media.pic_empty'))
        .width(120)
        .height(120)
        .margin({ top: 224 })

      Text($r('app.string.no_content'))
        .fontSize(14)
        .margin({ top: 8, bottom: 317, right: 152, left: 152 })
        .fontColor($r('app.color.text_color'))
        .opacity(0.4)
    }
    .width('100%')
    .height('100%')
    .backgroundColor($r('app.color.backGrounding'))
  }
}
```


When a PageAbility in multiton mode is started or when the PageAbility in singleton mode is started for the first time, you can use the **parameters** parameter in **want** to transfer the pages information and use the **startAbility()** method to start the PageAbility. For details about the launch type, see [PageAbility Launch Type](pageability-launch-type.md). The target PageAbility can use the **featureAbility.getWant()** method in **onCreate** to obtain the **want** parameter, and then call **router.push** to start a specified page.


When a user touches the button on the page of the caller PageAbility, the **startAbility()** method is called to start the target PageAbility. The **want** parameter in **startAbility()** carries the specified page information.

```ts
import featureAbility from '@ohos.ability.featureAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
import fs from '@ohos.file.fs';
import promptAction from '@ohos.promptAction';
import worker from '@ohos.worker';
import Logger from '../../utils/Logger';

const TAG: string = 'PagePageAbilityFirst';

@Entry
@Component
struct PagePageAbilityFirst {
  build() {
    Column() {
      Row() {
        Flex({ justifyContent: FlexAlign.Start, alignContent: FlexAlign.Center }) {
          Text($r('app.string.pageAbility_first_button'))
            .fontSize(24)
            .fontWeight(FontWeight.Bold)
            .textAlign(TextAlign.Start)
            .margin({ top: 12, bottom: 11, right: 24, left: 24 })
        }
      }
      .width('100%')
      .height(56)
      .justifyContent(FlexAlign.Start)
      .backgroundColor($r('app.color.backGrounding'))

      List({ initialIndex: 0 }) {
        ...
        ListItem() {
          Flex({ justifyContent: FlexAlign.SpaceBetween, alignContent: FlexAlign.Center }) {
            Text($r('app.string.start_standard_first_button'))
              .textAlign(TextAlign.Start)
              .fontWeight(FontWeight.Medium)
              .margin({ top: 17, bottom: 17, left: 12, right: 92 })
              .fontSize(16)
              .width(232)
              .height(22)
              .fontColor($r('app.color.text_color'))
          }
          .onClick(() => {
            let want: Want = {
              bundleName: 'com.samples.famodelabilitydevelop',
              abilityName: 'com.samples.famodelabilitydevelop.PageAbilityStandard',
              parameters: { page: 'pages/first' }
            };
            featureAbility.startAbility({ want: want }).then((data) => {
              Logger.info(TAG, `startAbility finish:${data}`);
            }).catch((err: BusinessError) => {
              Logger.info(TAG, `startAbility failed errcode:${err.code}`);
            })
          })
        }
        .height(56)
        .backgroundColor($r('app.color.start_window_background'))
        .borderRadius(24)
        .margin({ top: 12, right: 12, left: 12 })

        ListItem() {
          Flex({ justifyContent: FlexAlign.SpaceBetween, alignContent: FlexAlign.Center }) {
            Text($r('app.string.start_standard_second_button'))
              .textAlign(TextAlign.Start)
              .fontWeight(FontWeight.Medium)
              .margin({ top: 17, bottom: 17, left: 12, right: 92 })
              .fontSize(16)
              .width(232)
              .height(22)
              .fontColor($r('app.color.text_color'))
          }
          .onClick(() => {
            let want: Want = {
              bundleName: 'com.samples.famodelabilitydevelop',
              abilityName: 'com.samples.famodelabilitydevelop.PageAbilityStandard',
              parameters: { page: 'pages/second' }
            };
            featureAbility.startAbility({ want: want }).then((data) => {
              Logger.info(TAG, `startAbility finish:${data}`);
            }).catch((err: BusinessError) => {
              Logger.info(TAG, `startAbility failed errcode:${err.code}`);
            })
          })
        }
        .height(56)
        .backgroundColor($r('app.color.start_window_background'))
        .borderRadius(24)
        .margin({ top: 12, right: 12, left: 12 })
        ...
      }
      .height('100%')
      .backgroundColor($r('app.color.backGrounding'))
    }
    .width('100%')
    .margin({ top: 8 })
    .backgroundColor($r('app.color.backGrounding'))
  }
}
```


In the **onCreate()** callback of the target PageAbility, use the **featureAbility.getWant()** method to obtain the **want** parameter, parse the parameter, and start the specified page.

```ts
import featureAbility from '@ohos.ability.featureAbility';
import router from '@ohos.router';

class PageAbilityStandard {
  onCreate() {
    featureAbility.getWant().then((want) => {
      if (want.parameters) {
        if (want.parameters.page) {
          router.push({ url: want.parameters.page as string });
        }
      }
    })
  }
}

export default new PageAbilityStandard();
```

# Starting a Specified Page


When the launch type of a PageAbility is set to **singleton** (default), the **onNewWant()** callback is triggered if the PageAbility is not started for the first time. For details about the launch type, see [PageAbility Launch Type](pageability-launch-type.md). In this case, you can use the **want** parameter to transfer startup information. For example, if you want to start a PageAbility with a specified page, pass the pages information in **parameters** of **want**.


In **app.ets** or **page** of the caller PageAbility, use **startAbility()** to start the PageAbility again, with the page information passed in the **uri** parameter in **want**.

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


When a PageAbility in multiton mode is started or when the PageAbility in singleton mode is started for the first time, you can use the **parameters** parameter in **want** to transfer the pages information and use the **startAbility()** method to start the PageAbility. For details about the launch type, see [PageAbility Launch Type](pageability-launch-type.md). The target PageAbility can use the **featureAbility.getWant()** method in **onCreate** to obtain the **want** parameter, and then call **router.pushUrl** to start a specified page.


When a user touches the button on the page of the caller PageAbility, the **startAbility()** method is called to start the target PageAbility. The **want** parameter in **startAbility()** carries the specified page information.

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


In the **onCreate()** callback of the target PageAbility, use the **featureAbility.getWant()** method to obtain the **want** parameter, parse the parameter, and start the specified page.

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

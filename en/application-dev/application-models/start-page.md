# Starting a Specified Page


When the launch type of a PageAbility is set to **singleton** (default), the **onNewWant()** callback is triggered if the PageAbility is not started for the first time. For details about the launch type, see [PageAbility Launch Type](pageability-launch-type.md). In this case, you can use the **want** parameter to transfer startup information. For example, if you want to start a PageAbility with a specified page, pass the pages information in **parameters** of **want**.


In **app.ets** or **page** of the caller PageAbility, use **startAbility()** to start the PageAbility again, with the page information passed in the **uri** parameter in **want**.

```ts
import featureAbility from '@ohos.ability.featureAbility';
import Want from '@ohos.app.ability.Want';

async function restartAbility() {
    let wantInfo: Want = {
        bundleName: "com.sample.MyApplication",
        abilityName: "EntryAbility",
        parameters: {
            page: "pages/second"
        }
    };
    featureAbility.startAbility({
        want: wantInfo
    }).then((data) => {
        console.info('restartAbility success.');
    });
}
```


Obtain the **want** parameter that contains the page information from the **onNewWant()** callback of the target PageAbility.

```ts
// Construct a singleton object in GlobalContext.ts.
export class GlobalContext {
  private constructor() {}
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
import Want from '@ohos.application.Want';
import { GlobalContext } from './GlobalContext';

class EntryAbility {  
  onNewWant(want: Want) { 
    GlobalContext.getContext().setObject("newWant", want);  
  }
}

export default new EntryAbility()
```


Obtain the **want** parameter that contains the page information from the custom component of the target PageAbility and process the route based on the URI.

```ts
import Want from '@ohos.application.Want';
import router from '@ohos.router';
import { GlobalContext } from '../GlobalContext';

@Entry
@Component
struct Index {
  @State message: string = 'Router Page'
  
  onPageShow() {
    console.info('Index onPageShow')
    let newWant = GlobalContext.getContext().getObject("newWant") as Want
    if (newWant.parameters) {
      if (newWant.parameters.page) {
        router.push({ url: newWant.parameters.page });
        GlobalContext.getContext().setObject("newWant", undefined)
      }
    }
  }

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```


When a PageAbility in multiton mode is started or when the PageAbility in singleton mode is started for the first time, you can use the **parameters** parameter in **want** to transfer the pages information and use the **startAbility()** method to start the PageAbility. For details about the launch type, see [PageAbility Launch Type](pageability-launch-type.md). The target PageAbility can use the **featureAbility.getWant()** method in **onCreate** to obtain the **want** parameter, and then call **router.push** to start a specified page.


When a user touches the button on the page of the caller PageAbility, the **startAbility()** method is called to start the target PageAbility. The **want** parameter in **startAbility()** carries the specified page information.

```ts
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  build() {
    Row() {
      Button("startAbility")
        .onClick(() => {
          featureAbility.startAbility({
            want: {
              bundleName: "com.exm.myapplication",
              abilityName: "com.exm.myapplication.EntryAbility",
              parameters: { page: "pages/page1" }
            }
          }).then((data) => {
            console.info("startAbility finish");
          }).catch((err: BusinessError) => {
            console.info("startAbility failed errcode:" + err.code)
          })
        })
      ...
      Button("page2")
        .onClick(() => {
          featureAbility.startAbility({
            want: {
              bundleName: "com.exm.myapplication",
              abilityName: "com.exm.myapplication.EntryAbility",
              parameters: { page: "pages/page2" }
            }
          }).then((data) => {
            console.info("startAbility finish");
          }).catch((err: BusinessError) => {
            console.info("startAbility failed errcode:" + err.code)
          })
        })
      ...
    }
    ...
  }
}
```


In the **onCreate()** callback of the target PageAbility, use the **featureAbility.getWant()** method to obtain the **want** parameter, parse the parameter, and start the specified page.

```ts
import featureAbility from '@ohos.ability.featureAbility';
import router from '@ohos.router';
import { BusinessError } from '@ohos.base';

class EntryAbility {
  onCreate() {
    featureAbility.getWant().then((want) => {
      if (want.parameters) {
        if (want.parameters.page) {
          router.pushUrl({
            url: want.parameters.page as string
          }, (error: BusinessError)=>{
            console.error(`error: ${JSON.stringify(error)}`);
          })
        }
      }
    })
  }
  onDestroy() {
    // ...
  }
}

export default new EntryAbility()
```

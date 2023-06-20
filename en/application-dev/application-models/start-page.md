# Starting a Specified Page


When the launch type of a PageAbility is set to **singleton** (default), the **onNewWant()** callback is triggered if the PageAbility is not started for the first time. For details about the launch type, see [PageAbility Launch Type](pageability-launch-type.md). In this case, you can use the **want** parameter to transfer startup information. For example, if you want to start a PageAbility with a specified page, pass the pages information in **parameters** of **want**.


In **app.ets** or **page** of the caller PageAbility, use **startAbility()** to start the PageAbility again, with the page information passed in the **uri** parameter in **want**.

```ts
import featureAbility from '@ohos.ability.featureAbility';

async function restartAbility() {
    let wantInfo = {
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
export default {  
    onNewWant(want) {    
        globalThis.newWant = want  
    }
}
```


Obtain the **want** parameter that contains the page information from the custom component of the target PageAbility and process the route based on the URI.

```ts
import router from '@ohos.router'
@Entry
@Component
struct Index {
  @State message: string = 'Router Page'
  newWant = undefined
  onPageShow() {
    console.info('Index onPageShow')
    let newWant = globalThis.newWant
    if (newWant.hasOwnProperty("page")) {
      router.push({ url: newWant.page });
      globalThis.newWant = undefined
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
import featureAbility from '@ohos.ability.featureAbility'
@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  build() {
    ...
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
        }).catch((err) => {
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
        }).catch((err) => {
          console.info("startAbility failed errcode:" + err.code)
        })
      })
    ...
  }
}
```


In the **onCreate()** callback of the target PageAbility, use the **featureAbility.getWant()** method to obtain the **want** parameter, parse the parameter, and start the specified page.

```ts
import featureAbility from '@ohos.ability.featureAbility';
import router from '@ohos.router';

export default {
  onCreate() {
    featureAbility.getWant().then((want) => {
      if (want.parameters.page) {
        router.push({
          url: want.parameters.page
        })
      }
    })
  },
  onDestroy() {
    ...
  },
}
```

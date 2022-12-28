# 启动指定页面


当PageAbility的启动模式设置为单例时（具体设置方法和典型场景示例见[PageAbility的启动模式](pageability-launch-type.md)，缺省情况下是单实例模式），若PageAbility已被拉起，再次启动PageAbility会触发onNewWant回调（即非首次拉起）。应用开发者可以通过want传递启动参数，例如开发者希望指定页面启动PageAbility，可以通过want中的parameters参数传递pages信息，具体示例代码如下：


调用方PageAbility的app.ets中或者page中，使用startAbility再次拉起PageAbility，通过want中的uri参数传递页面信息：

```ts
import featureAbility from '@ohos.ability.featureAbility';

async function restartAbility() {
    let wantInfo = {
        bundleName: "com.sample.MyApplication",
        abilityName: "MainAbility",
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


在目标端PageAbility的onNewWant回调中获取包含页面信息的want参数：

```ts
export default {  
    onNewWant(want) {    
        globalThis.newWant = want  
    }
}
```


在目标端页面的自定义组件中获取包含页面信息的want参数并根据uri做路由处理：

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


当PageAbility的启动模式设置为标准模式或为首次启动单例模式的PageAbility时（具体设置方法和典型场景示例见[PageAbility的启动模式](pageability-launch-type.md)），在调用方PageAbility中，通过want中的parameters参数传递要启动的指定页面的pages信息，调用startAbility()方法启动PageAbility。被调用方可以在onCreate中使用featrueAbility的getWant方法获取want，再通过调用router.push实现启动指定页面。


调用方的页面中实现按钮点击触发startAbility方法启动目标端PageAbility，startAbility方法的入参want中携带指定页面信息，示例代码如下：

```ts
import featureAbility from '@ohos.ability.featureAbility'
@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  build() {
    // ...
    Button("startAbility")
      .onClick(() => {
        featureAbility.startAbility({
          want: {
            bundleName: "com.exm.myapplication",
            abilityName: "com.exm.myapplication.MainAbility",
            parameters: { page: "pages/page1" }
          }
        }).then((data) => {
          console.info("startAbility finish");
        }).catch((err) => {
          console.info("startAbility failed errcode:" + err.code)
        })
      })
    // ...
    Button("page2")
      .onClick(() => {
        featureAbility.startAbility({
          want: {
            bundleName: "com.exm.myapplication",
            abilityName: "com.exm.myapplication.MainAbility",
            parameters: { page: "pages/page2" }
          }
        }).then((data) => {
          console.info("startAbility finish");
        }).catch((err) => {
          console.info("startAbility failed errcode:" + err.code)
        })
      })
    // ...
  }
}
```


目标端PageAbility的onCreate生命周期回调中通过featrueAbility的getWant方法获取want，并对参数进行解析，实现指定页面拉起：

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
    // ...
  },
}
```

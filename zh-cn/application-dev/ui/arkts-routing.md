# 页面路由 (@ohos.router)(不推荐)


页面路由指在应用程序中实现不同页面之间的跳转和数据传递。Router模块通过不同的url地址，可以方便地进行页面路由，轻松地访问不同的页面。本文将从[页面跳转](#页面跳转)、[页面返回](#页面返回)、[页面返回前增加一个询问框](#页面返回前增加一个询问框)和[命名路由](#命名路由)这几个方面，介绍如何通过Router模块实现页面路由。

>**说明：**
>
>[组件导航 (Navigation)](./arkts-navigation-navigation.md)具有更强的功能和自定义能力，推荐使用该组件作为应用的路由框架。Navigation和Router的差异可参考[Router切换Navigation](./arkts-router-to-navigation.md)指导。

## 页面跳转

页面跳转是开发过程中的一个重要组成部分。在使用应用程序时，通常需要在不同的页面之间跳转，有时还需要将数据从一个页面传递到另一个页面。

  **图1** 页面跳转  
![router-jump-to-detail](figures/router-jump-to-detail.gif)

Router模块提供了两种跳转模式，分别是[router.pushUrl](../reference/apis-arkui/js-apis-router.md#routerpushurl9)和[router.replaceUrl](../reference/apis-arkui/js-apis-router.md#routerreplaceurl9)。这两种模式决定了目标页面是否会替换当前页。

- router.pushUrl：目标页面不会替换当前页，而是压入页面栈。这样可以保留当前页的状态，并且可以通过返回键或者调用[router.back](../reference/apis-arkui/js-apis-router.md#routerback)方法返回到当前页。

- router.replaceUrl：目标页面会替换当前页，并销毁当前页。这样可以释放当前页的资源，并且无法返回到当前页。

>**说明：** 
>
>- 创建新页面时，请参考<!--RP1-->[构建第二个页面](../quick-start/start-with-ets-stage.md#构建第二个页面)<!--RP1End-->配置第二个页面的路由。
>
>
>- 页面栈的最大容量为32个页面。如果超过这个限制，可以调用[router.clear](../reference/apis-arkui/js-apis-router.md#routerclear)方法清空历史页面栈，释放内存空间。

同时，Router模块提供了两种实例模式，分别是Standard和Single。这两种模式决定了目标url是否会对应多个实例。

- Standard：多实例模式，也是默认情况下的跳转模式。目标页面会被添加到页面栈顶，无论栈中是否存在相同url的页面。

- Single：单实例模式。如果目标页面的url已经存在于页面栈中，则会将离栈顶最近的同url页面移动到栈顶，该页面成为新建页。如果目标页面的url在页面栈中不存在同url页面，则按照默认的多实例模式进行跳转。

在使用Router相关功能之前，需要在代码中先导入Router模块。


```ts
import { promptAction, router } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
```

- 场景一：有一个主页（Home）和一个详情页（Detail），希望从主页点击一个商品，跳转到详情页。同时，需要保留主页在页面栈中，以便返回时恢复状态。这种场景下，可以使用pushUrl方法，并且使用Standard实例模式（或者省略）。

  ```ts
  import { router } from '@kit.ArkUI';

  // 在Home页面中
  function onJumpClick(): void {
    router.pushUrl({
      url: 'pages/Detail' // 目标url
    }, router.RouterMode.Standard, (err) => {
      if (err) {
        console.error(`Invoke pushUrl failed, code is ${err.code}, message is ${err.message}`);
        return;
      }
      console.info('Invoke pushUrl succeeded.');
    });
  }
  ```

  >**说明：**
  >
  >多实例模式下，router.RouterMode.Standard参数可以省略。

- 场景二：有一个登录页（Login）和一个个人中心页（Profile），希望从登录页成功登录后，跳转到个人中心页。同时，销毁登录页，在返回时直接退出应用。这种场景下，可以使用replaceUrl方法，并且使用Standard实例模式（或者省略）。

  ```ts
  import { router } from '@kit.ArkUI';

  // 在Login页面中
  function onJumpClick(): void {
    router.replaceUrl({
      url: 'pages/Profile' // 目标url
    }, router.RouterMode.Standard, (err) => {
      if (err) {
        console.error(`Invoke replaceUrl failed, code is ${err.code}, message is ${err.message}`);
        return;
      }
      console.info('Invoke replaceUrl succeeded.');
    })
  }
  ```

  >**说明：**
  >
  >多实例模式下，router.RouterMode.Standard参数可以省略。

- 场景三：有一个设置页（Setting）和一个主题切换页（Theme），希望从设置页点击主题选项，跳转到主题切换页。同时，需要保证每次只有一个主题切换页存在于页面栈中，在返回时直接回到设置页。这种场景下，可以使用pushUrl方法，并且使用Single实例模式。

  ```ts
  import { router } from '@kit.ArkUI';

  // 在Setting页面中
  function onJumpClick(): void {
    router.pushUrl({
      url: 'pages/Theme' // 目标url
    }, router.RouterMode.Single, (err) => {
      if (err) {
        console.error(`Invoke pushUrl failed, code is ${err.code}, message is ${err.message}`);
        return;
      }
      console.info('Invoke pushUrl succeeded.');
    });
  }
  ```

- 场景四：有一个搜索结果列表页（SearchResult）和一个搜索结果详情页（SearchDetail），希望从搜索结果列表页点击某一项结果，跳转到搜索结果详情页。同时，如果该结果已经被查看过，则不需要再新建一个详情页，而是直接跳转到已经存在的详情页。这种场景下，可以使用replaceUrl方法，并且使用Single实例模式。

  ```ts
  import { router } from '@kit.ArkUI';

  // 在SearchResult页面中
  function onJumpClick(): void {
    router.replaceUrl({
      url: 'pages/SearchDetail' // 目标url
    }, router.RouterMode.Single, (err) => {
      if (err) {
        console.error(`Invoke replaceUrl failed, code is ${err.code}, message is ${err.message}`);
        return;
      }
      console.info('Invoke replaceUrl succeeded.');
    })
  }
  ```

以上是不带参数传递的场景。

如果需要在跳转时传递一些数据给目标页面，则可以在调用Router模块的方法时，添加一个params属性，并指定一个对象作为参数。例如：


```ts
import { router } from '@kit.ArkUI';

class DataModelInfo {
  age: number = 0;
}

class DataModel {
  id: number = 0;
  info: DataModelInfo | null = null;
}

function onJumpClick(): void {
  // 在Home页面中
  let paramsInfo: DataModel = {
    id: 123,
    info: {
      age: 20
    }
  };

  router.pushUrl({
    url: 'pages/Detail', // 目标url
    params: paramsInfo // 添加params属性，传递自定义参数
  }, (err) => {
    if (err) {
      console.error(`Invoke pushUrl failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info('Invoke pushUrl succeeded.');
  })
}
```

在目标页面中，可以通过调用Router模块的[getParams](../reference/apis-arkui/js-apis-router.md#routergetparams)方法来获取传递过来的参数。例如：


```ts
import { router } from '@kit.ArkUI';

class InfoTmp {
  age: number = 0
}

class RouTmp {
  id: object = () => {
  }
  info: InfoTmp = new InfoTmp()
}

const params: RouTmp = router.getParams() as RouTmp; // 获取传递过来的参数对象
const id: object = params.id // 获取id属性的值
const age: number = params.info.age // 获取age属性的值
```


## 页面返回

当用户在一个页面完成操作后，通常需要返回到上一个页面或者指定页面，这就需要用到页面返回功能。在返回的过程中，可能需要将数据传递给目标页面，这就需要用到数据传递功能。

  **图2** 页面返回  

![router-back-to-home](figures/router-back-to-home.gif)

在使用页面路由Router相关功能之前，需要在代码中先导入Router模块。


```ts
import { router } from '@kit.ArkUI';
```

可以使用以下几种方式返回页面：

- 方式一：返回到上一个页面。


  ```ts
  import { router } from '@kit.ArkUI';

  router.back();
  ```

  这种方式会返回到上一个页面，即上一个页面在页面栈中的位置。但是，上一个页面必须存在于页面栈中才能够返回，否则该方法将无效。

- 方式二：返回到指定页面。


  返回普通页面。

  ```ts
  import { router } from '@kit.ArkUI';

  router.back({
    url: 'pages/Home'
  });
  ```

  返回命名路由页面。

  ```ts
  import { router } from '@kit.ArkUI';

  router.back({
    url: 'myPage' //myPage为返回的命名路由页面别名
  });
  ```

  这种方式可以返回到指定页面，需要指定目标页面的路径。目标页面必须存在于页面栈中才能够返回。

- 方式三：返回到指定页面，并传递自定义参数信息。


  返回到普通页面。

  ```ts
  import { router } from '@kit.ArkUI';

  router.back({
    url: 'pages/Home',
    params: {
      info: '来自Home页'
    }
  });
  ```

  返回命名路由页面。

  ```ts
  import { router } from '@kit.ArkUI';

  router.back({
    url: 'myPage', //myPage为返回的命名路由页面别名
    params: {
      info: '来自Home页'
    }
  });
  ```

  这种方式不仅可以返回到指定页面，还可以在返回的同时传递自定义参数信息。这些参数信息可以在目标页面中通过调用router.getParams方法进行获取和解析。

在目标页面中，在需要获取参数的位置调用router.getParams方法即可，例如在[onPageShow](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#onpageshow)生命周期回调中：

> **说明：**
> 
> 直接使用router可能导致实例不明确的问题，建议使用[getUIContext](../reference/apis-arkui/js-apis-arkui-UIContext.md#uicontext)获取UIContext实例，并使用[getRouter](../reference/apis-arkui/js-apis-arkui-UIContext.md#getrouter)获取绑定实例的router。

```ts
@Entry
@Component
struct Home {
  @State message: string = 'Hello World';

  onPageShow() {
    const params = this.getUIContext().getRouter().getParams() as Record<string, string>; // 获取传递过来的参数对象
    if (params) {
      const info: string = params.info as string; // 获取info属性的值
    }
  }

  ...
}
```

>**说明：**
>
>当使用router.back方法返回到指定页面时，原栈顶页面（包括）到指定页面（不包括）之间的所有页面栈都将从栈中弹出并销毁。
>
> 另外，如果使用router.back方法返回到原来的页面，原页面不会被重复创建，因此使用\@State声明的变量不会重复声明，也不会触发页面的aboutToAppear生命周期回调。如果需要在原页面中使用返回页面传递的自定义参数，可以在需要的位置进行参数解析。例如，在onPageShow生命周期回调中进行参数解析。


## 页面返回前增加一个询问框

在开发应用时，为了避免用户误操作或者丢失数据，有时候需要在用户从一个页面返回到另一个页面之前，弹出一个询问框，让用户确认是否要执行这个操作。

本文将从[系统默认询问框](#系统默认询问框)和[自定义询问框](#自定义询问框)两个方面来介绍如何实现页面返回前增加一个询问框的功能。

  **图3** 页面返回前增加一个询问框  

![router-add-query-box-before-back](figures/router-add-query-box-before-back.gif)


### 系统默认询问框

为了实现这个功能，可以使用页面路由Router模块提供的两个方法：[router.showAlertBeforeBackPage](../reference/apis-arkui/js-apis-router.md#routershowalertbeforebackpage9)和[router.back](../reference/apis-arkui/js-apis-router.md#routerback)来实现这个功能。

在使用页面路由Router相关功能之前，需要在代码中先导入Router模块。


```ts
import { router } from '@kit.ArkUI';
```

如果想要在目标界面开启页面返回询问框，需要在调用[router.back](../reference/apis-arkui/js-apis-router.md#routerback)方法之前，通过调用[router.showAlertBeforeBackPage](../reference/apis-arkui/js-apis-router.md#routershowalertbeforebackpage9)方法设置返回询问框的信息。例如，在支付页面中定义一个返回按钮的点击事件处理函数：

```ts
import { router } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

// 定义一个返回按钮的点击事件处理函数
function onBackClick(): void {
  // 调用router.showAlertBeforeBackPage()方法，设置返回询问框的信息
  try {
    router.showAlertBeforeBackPage({
      message: '您还没有完成支付，确定要返回吗？' // 设置询问框的内容
    });
  } catch (err) {
    let message = (err as BusinessError).message
    let code = (err as BusinessError).code
    console.error(`Invoke showAlertBeforeBackPage failed, code is ${code}, message is ${message}`);
  }

  // 调用router.back()方法，返回上一个页面
  router.back();
}
```

其中，router.showAlertBeforeBackPage方法接收一个对象作为参数，该对象包含以下属性：

message：string类型，表示询问框的内容。
如果调用成功，则会在目标界面开启页面返回询问框；如果调用失败，则会抛出异常，并通过err.code和err.message获取错误码和错误信息。

当用户点击“返回”按钮时，会弹出确认对话框，询问用户是否确认返回。选择“取消”将停留在当前页目标页面；选择“确认”将触发router.back方法，并根据参数决定如何执行跳转。

### 自定义询问框

自定义询问框的方式，可以使用弹窗[promptAction.showDialog](../reference/apis-arkui/js-apis-promptAction.md#promptactionshowdialog)或者自定义弹窗实现。这样可以让应用界面与系统默认询问框有所区别，提高应用的用户体验度。本文以弹窗为例，介绍如何实现自定义询问框。

在使用页面路由Router相关功能之前，需要在代码中先导入Router模块。


```ts
import { router } from '@kit.ArkUI';
```

在事件回调中，调用弹窗的[promptAction.showDialog](../reference/apis-arkui/js-apis-promptAction.md#promptactionshowdialog)方法：

```ts
import { promptAction, router } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

function onBackClick() {
  // 弹出自定义的询问框
  promptAction.showDialog({
    message: '您还没有完成支付，确定要返回吗？',
    buttons: [
      {
        text: '取消',
        color: '#FF0000'
      },
      {
        text: '确认',
        color: '#0099FF'
      }
    ]
  }).then((result: promptAction.ShowDialogSuccessResponse) => {
    if (result.index === 0) {
      // 用户点击了“取消”按钮
      console.info('User canceled the operation.');
    } else if (result.index === 1) {
      // 用户点击了“确认”按钮
      console.info('User confirmed the operation.');
      // 调用router.back()方法，返回上一个页面
      router.back();
    }
  }).catch((err: Error) => {
    let message = (err as BusinessError).message
    let code = (err as BusinessError).code
    console.error(`Invoke showDialog failed, code is ${code}, message is ${message}`);
  })
}
```

当用户点击“返回”按钮时，会弹出自定义的询问框，询问用户是否确认返回。选择“取消”将停留在当前页目标页面；选择“确认”将触发router.back方法，并根据参数决定如何执行跳转。

## 命名路由

在开发中为了跳转到共享包[HAR](../quick-start/har-package.md)或者[HSP](../quick-start/in-app-hsp.md)中的页面（即共享包中路由跳转），可以使用[router.pushNamedRoute](../reference/apis-arkui/js-apis-router.md#routerpushnamedroute10)来实现。

  **图4** 命名路由跳转  

![(figures/router-add-query-box-before-back.gif)](figures/namedroute-jump-to-mypage.gif)

在使用页面路由Router相关功能之前，需要在代码中先导入Router模块。


```ts
import { router } from '@kit.ArkUI';
```

在想要跳转到的共享包[HAR](../quick-start/har-package.md)或者[HSP](../quick-start/in-app-hsp.md)页面里，给@Entry修饰的自定义组件[EntryOptions](../quick-start/arkts-create-custom-components.md#entryoptions10)命名：

```ts
// library/src/main/ets/pages/Index.ets
// library为新建共享包自定义的名字
@Entry({ routeName: 'myPage' })
@Component
export struct MyComponent {
  build() {
    Row() {
      Column() {
        Text('Library Page')
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

配置成功后需要在跳转的页面中引入命名路由的页面：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import '@ohos/library/src/main/ets/pages/Index'; // 引入共享包中的命名路由页面

@Entry
@Component
struct Index {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text('Hello World')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .margin({ top: 20 })
        .backgroundColor('#ccc')
        .onClick(() => { // 点击跳转到其他共享包中的页面
          try {
            this.getUIContext().getRouter().pushNamedRoute({
              name: 'myPage',
              params: {
                data1: 'message',
                data2: {
                  data3: [123, 456, 789]
                }
              }
            })
          } catch (err) {
            let message = (err as BusinessError).message
            let code = (err as BusinessError).code
            console.error(`pushNamedRoute failed, code is ${code}, message is ${message}`);
          }
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

>**说明：**
>
>使用命名路由方式跳转时，需要在当前应用包的oh-package.json5文件中配置依赖。例如：
>
>```ts
>"dependencies": {
>    "@ohos/library": "file:../library",
>    ...
> }
>```

## 相关实例

针对页面路由开发，有以下相关实例可供参考：

- [页面布局和连接（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/UI/ArkTsComponentCollection/DefiningPageLayoutAndConnection)
# 窗口

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import window from '@ohos.window';
```

## WindowType<sup>7+</sup><a name="windowtype"></a>

窗口类型。

| 名称              | 默认值 | 说明                                                         |
| ----------------- | ------ | ------------------------------------------------------------ |
| TYPE_APP          | 0      | 表示应用子窗口。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| TYPE_SYSTEM_ALERT | 1      | 表示系统告警窗口。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |

## AvoidAreaType<sup>7+</sup><a name="avoidareatype"></a>

窗口内容需要规避区域的类型。

| 名称        | 默认值 | 说明                                                         |
| ----------- | ------ | ------------------------------------------------------------ |
| TYPE_SYSTEM | 0      | 表示系统默认区域。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| TYPE_CUTOUT | 1      | 表示刘海屏区域。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |

## WindowMode<sup>7+</sup><a name="windowmode"></a>

窗口模式。

| 名称       | 默认值 | 说明                                                         |
| ---------- | ------ | ------------------------------------------------------------ |
| UNDEFINED  | 1      | 表示APP未定义窗口模式。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| FULLSCREEN | 2      | 表示APP全屏模式。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| PRIMARY    | 3      | 表示APP分屏多窗口主要模式。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| SECONDARY  | 4      | 表示APP分屏多窗口次要模式。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| FLOATING   | 5      | 表示APP自由悬浮形式窗口模式。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |

## SystemBarProperties<a name="systembarproperties"></a>

状态栏导航栏的属性。

| 名称                                   | 参数类型 | 可读 | 可写 | 说明                                                         |
| -------------------------------------- | -------- | ---- | ---- | ------------------------------------------------------------ |
| statusBarColor                         | string   | 是   | 是   | 状态栏背景颜色，为16进制RGB或ARGB颜色，例如"\#00FF00"或"\#FF00FF00"。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| isStatusBarLightIcon<sup>7+</sup>      | boolean  | 否   | 是   | 状态栏图标是否为高亮状态。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| statusBarContentColor<sup>8+</sup>     | string   | 否   | 是   | 状态栏文字颜色。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| navigationBarColor                     | string   | 是   | 是   | 导航栏背景颜色，为16进制RGB或ARGB颜色，例如"\#00FF00"或"\#FF00FF00"。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| isNavigationBarLightIcon<sup>7+</sup>  | boolean  | 否   | 否   | 导航栏图标是否为高亮状态。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| navigationBarContentColor<sup>8+</sup> | string   | 否   | 是   | 导航栏文字颜色。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |

## SystemBarRegionTint <sup>8+</sup><a name="systembartegiontint"></a>

单个导航栏或状态栏回调信息。

| 名称            | 参数类型                  | 可读 | 可写 | 说明                                                         |
| --------------- | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type            | [WindowType](#windowtype) | 是   | 是   | 当前属性改变的系统栏类型，仅支持类型为导航栏、状态栏的系统栏。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| isEnable        | boolean                   | 是   | 是   | 当前系统栏是否显示。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| region          | [Rect](#rect)             | 是   | 是   | 当前系统栏的位置及大小。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| backgroundColor | string                    | 是   | 是   | 系统栏背景颜色，为16进制RGB或ARGB颜色，例如"\#00FF00"或"\#FF00FF00"。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| contentColor    | string                    | 是   | 是   | 系统栏文字颜色。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |

## SystemBarTintState <sup>8+</sup><a name="systembartintstate"></a>

当前系统栏回调信息集合。

| 名称       | 参数类型                                           | 可读 | 可写 | 说明                                                         |
| ---------- | -------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| displayId  | number                                             | 是   | 否   | 当前物理屏幕id。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| regionTint | Array<[SystemBarRegionTint](#systembartegiontint)> | 是   | 是   | 当前改变所有的系统栏信息。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |

## Rect<sup>7+</sup><a name="rect"></a>

矩形。

| 名称   | 参数类型 | 可读 | 可写 | 说明                                                         |
| ------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| left   | number   | 是   | 是   | 矩形区域的左边界。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| top    | number   | 是   | 是   | 矩形区域的上边界。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| width  | number   | 是   | 是   | 矩形区域的宽度。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| height | number   | 是   | 是   | 矩形区域的高度。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |

## AvoidArea<sup>7+</sup><a name="avoidarea"></a>

表示窗口内容规避区域。

| 名称       | 参数类型      | 可读 | 可写 | 说明                                                         |
| ---------- | ------------- | ---- | ---- | ------------------------------------------------------------ |
| leftRect   | [Rect](#rect) | 是   | 是   | 屏幕左侧的矩形区。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| topRect    | [Rect](#rect) | 是   | 是   | 屏幕顶部的矩形区。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| rightRect  | [Rect](#rect) | 是   | 是   | 屏幕右侧的矩形区。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| bottomRect | [Rect](#rect) | 是   | 是   | 屏幕底部的矩形区。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |

## Size<sup>7+</sup><a name="size"></a>

窗口大小。

| 名称   | 参数类型 | 可读 | 可写 | 说明                                                         |
| ------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| width  | number   | 是   | 是   | 窗口宽度。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| height | number   | 是   | 是   | 窗口高度。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |

## WindowProperties<a name="windowproperties"></a>

窗口属性。

| 名称                            | 参数类型                  | 可读 | 可写 | 说明                                                         |
| ------------------------------- | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| windowRect<sup>7+</sup>         | [Rect](#rect)             | 是   | 是   | 窗口尺寸。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| type<sup>7+</sup>               | [WindowType](#windowtype) | 是   | 是   | 窗口类型。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| isFullScreen                    | boolean                   | 是   | 是   | 是否全屏，默认为false。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| isLayoutFullScreen<sup>7+</sup> | boolean                   | 是   | 是   | 窗口是否为沉浸式，默认为false。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| focusable<sup>7+</sup>          | boolean                   | 是   | 否   | 窗口是否可聚焦，默认为true。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| touchable<sup>7+</sup>          | boolean                   | 是   | 否   | 窗口是否可触摸，默认为true。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |

## ColorSpace<sup>8+</sup><a name="colorspace"></a>

色域模式。

| 名称       | 默认值 | 说明                                                         |
| ---------- | ------ | ------------------------------------------------------------ |
| DEFAULT    | 0      | 默认色域模式。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |
| WIDE_GAMUT | 1      | 广色域模式。<br/>**系统能力**：SystemCapability.WindowManager.WindowManager.Core |

## window.create<sup>7</sup><a name="window-create"></a>

create(id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void

创建子窗口，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                                   | 必填 | 说明                       |
  | -------- | -------------------------------------- | ---- | -------------------------- |
  | id       | string                                 | 是   | 窗口id。                   |
  | type     | [WindowType](#windowtype)              | 是   | 窗口类型。                 |
  | callback | AsyncCallback&lt;[Window](#window)&gt; | 是   | 回调返回创建的子窗口对象。 |

- 示例

  ```
   window.create("first", window.WindowType.TYPE_APP, (err, data) => {
      windowClass = data;
      if (err.code) {
          console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('SubWindow created. Data: ' + JSON.stringify(data))
      windowClass.resetSize(500, 1000);
  });
  ```

## window.create<sup>7</sup>

create(id: string, type: WindowType): Promise&lt;Window&gt;

创建子窗口，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名 | 类型                      | 必填 | 说明       |
  | ------ | ------------------------- | ---- | ---------- |
  | id     | string                    | 是   | 窗口id。   |
  | type   | [WindowType](#windowtype) | 是   | 窗口类型。 |

- 返回值

  | 类型                             | 说明                                              |
  | -------------------------------- | ------------------------------------------------- |
  | Promise&lt;[Window](#window)&gt; | 以Promise形式返回结果，返回当前创建的子窗口对象。 |

- 示例

  ```
   let promise = window.create("first", window.WindowType.TYPE_APP);
   promise.then((data)=> {
      console.info('SubWindow created. Data: ' + JSON.stringify(data))
   }).catch((err)=>{
      console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));
   });
  ```

## window.create<sup>8+</sup>

create(ctx: Context, id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void

当Context为[ServiceExtensionContext](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-service-extension-context.md)时，创建系统窗口，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                                                         | 必填 | 说明                                                  |
  | -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
  | ctx      | [Context](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-Context.md) | 是   | 当前应用上下文信息, 为ServiceExtensionContext的基类。 |
  | id       | string                                                       | 是   | 窗口id。                                              |
  | type     | [WindowType](#windowtype)                                    | 是   | 窗口类型。                                            |
  | callback | AsyncCallback&lt;[Window](#window)&gt;                       | 是   | 回调返回当前窗口对象。                                |

- 示例

  ```
   window.create(this.context, "alertWindow", window.WindowType.TYPE_SYSTEM_ALERT, (err, data) => {
      windowClass = data;
      if (err.code) {
          console.error('Failed to create the Window. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Window created. Data: ' + JSON.stringify(data))
      windowClass.resetSize(500, 1000);
  });
  ```

## window.create<sup>8+</sup>

function create(ctx: Context, id: string, type: WindowType): Promise&lt;Window&gt;

当Context为[ServiceExtensionContext](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-service-extension-context.md)时，创建系统窗口，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名 | 类型                                                         | 必填 | 说明                                                  |
  | ------ | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
  | ctx    | [Context](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-Context.md) | 是   | 当前应用上下文信息, 为ServiceExtensionContext的基类。 |
  | id     | string                                                       | 是   | 窗口id。                                              |
  | type   | [WindowType](#windowtype)                                    | 是   | 窗口类型。                                            |

- 返回值

  | 类型                             | 说明                                            |
  | -------------------------------- | ----------------------------------------------- |
  | Promise&lt;[Window](#window)&gt; | 以Promise形式返回结果，返回当前创建的窗口对象。 |

- 示例

  ```
   let promise = window.create(this.context, "alertWindow", window.WindowType.TYPE_SYSTEM_ALERT);
   promise.then((data)=> {
      console.info('Window created. Data: ' + JSON.stringify(data))
   }).catch((err)=>{
      console.error('Failed to create the Window. Cause: ' + JSON.stringify(err));
   });
  ```

## window.find<sup>7+</sup><a name="window-find"></a>

find(id: string, callback: AsyncCallback&lt;Window&gt;): void

查找id所对应的窗口，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                                   | 必填 | 说明                         |
  | -------- | -------------------------------------- | ---- | ---------------------------- |
  | id       | string                                 | 是   | 窗口id。                     |
  | callback | AsyncCallback&lt;[Window](#window)&gt; | 是   | 回调返回当前查找的窗口对象。 |

- 示例

  ```
   window.find("first", (err, data) => {
     if (err.code) {
         console.error('Failed to find the Window. Cause: ' + JSON.stringify(err));
         return;
     }
    console.info('window found. Data: ' + JSON.stringify(data))
    windowClass = data;
  });
  ```

## window.find<sup>7+</sup>

find(id: string): Promise&lt;Window&gt;

查找id所对应的窗口，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名 | 类型   | 必填 | 说明     |
  | ------ | ------ | ---- | -------- |
  | id     | string | 是   | 窗口id。 |

- 返回值

  | 类型                             | 说明                                            |
  | -------------------------------- | ----------------------------------------------- |
  | Promise&lt;[Window](#window)&gt; | 以Promise形式返回结果，返回当前查找的窗口对象。 |

- 示例

  ```
   let promise = window.find("first");
   promise.then((data)=> {
      console.info('window found. Data: ' + JSON.stringify(data))
   }).catch((err)=>{
      console.error('Failed to find the Window. Cause: ' + JSON.stringify(err));
   });
  ```

## window.getTopWindow<a name="window-gettopwindow"></a>

getTopWindow(callback: AsyncCallback&lt;Window&gt;): void

获取当前应用内最后显示的窗口，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                                   | 必填 | 说明                                   |
  | -------- | -------------------------------------- | ---- | -------------------------------------- |
  | callback | AsyncCallback&lt;[Window](#window)&gt; | 是   | 回调返回当前应用内最后显示的窗口对象。 |

- 示例

  ```
  window.getTopWindow((err, data) => {
      if (err.code) {
          console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
      windowClass = data;
  });
  ```

## window.getTopWindow

getTopWindow(): Promise&lt;Window&gt;

获取当前应用内最后显示的窗口，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 返回值

  | 类型                             | 说明                                                      |
  | -------------------------------- | --------------------------------------------------------- |
  | Promise&lt;[Window](#window)&gt; | 以Promise形式返回结果，返回当前应用内最后显示的窗口对象。 |

- 示例

  ```
   let promise = window.getTopWindow();
   promise.then((data)=> {
      console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data))
   }).catch((err)=>{
      console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
   })
  ```

## window.getTopWindow<sup>8+</sup>

getTopWindow(ctx: Context, callback: AsyncCallback&lt;Window&gt;): void

获取当前应用内最后显示的窗口，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                                                         | 必填 | 说明                                   |
  | -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
  | ctx      | [Context](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-Context.md) | 是   | 当前应用上下文信息。                   |
  | callback | AsyncCallback&lt;[Window](#window)&gt;                       | 是   | 回调返回当前应用内最后显示的窗口对象。 |

- 示例

  ```
  window.getTopWindow(this.context, (err, data) => {
      if (err.code) {
          console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
      windowClass = data;
  });
  ```

## window.getTopWindow<sup>8+</sup>

getTopWindow(ctx: Context): Promise&lt;Window&gt;

获取当前应用内最后显示的窗口，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名 | 类型                                                         | 必填 | 说明                 |
  | ------ | ------------------------------------------------------------ | ---- | -------------------- |
  | ctx    | [Context](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-Context.md) | 是   | 当前应用上下文信息。 |

- 返回值

  | 类型                             | 说明                                                      |
  | -------------------------------- | --------------------------------------------------------- |
  | Promise&lt;[Window](#window)&gt; | 以Promise形式返回结果，返回当前应用内最后显示的窗口对象。 |

- 示例

  ```
   let promise = window.getTopWindow(this.context);
   promise.then((data)=> {
      console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data))
   }).catch((err)=>{
      console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
   })
  ```

## on('systemBarTintChange')<sup>8+</sup>

on(type: 'systemBarTintChange', callback: Callback&lt;SystemBarTintState&gt;): void

注册状态栏、导航栏的监听函数。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                                                      | 必填 | 说明                                                         |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
  | type     | string                                                    | 是   | 设置监听类型。<br/>-&nbsp;type为'systemBarTintChange'时表示监听类型为导航栏、状态栏属性变化监听； |
  | callback | Callback&lt;[SystemBarTintState](#systembartintstate)&gt; | 是   | 回调返回监听到的信息。                                       |

- 示例

  ```
  var type = 'systemBarTintChange';
  windowClass.on(type, (data) => {
      console.info('Succeeded in enabling the listener for systemBarTint changes. Data: ' + JSON.stringify(data));
  });
  ```

## off('systemBarTintChange')<sup>8+</sup>

off(type: 'systemBarTintChange', callback?: Callback&lt;SystemBarTintState &gt;): void

关闭监听。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                                                      | 必填 | 说明                                                         |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
  | type     | string                                                    | 是   | 设置监听类型。<br/>-&nbsp;type为'systemBarTintChange'时表示监听类型为导航栏、状态栏属性变化监听； |
  | callback | Callback&lt;[SystemBarTintState](#systembartintstate)&gt; | 否   | 回调返回监听到的信息。                                       |

- 示例

  ```
  var type = 'systemBarTintChange';
  windowClass.off(type);
  ```

## Window

下列API示例中都需使用[getTopWindow()](#window-gettopwindow)、[create()](#window-create)、[find()](#window-find)等先获取到Window实例，再通过此实例调用对应方法。

### hide<sup>7+</sup>

hide (callback: AsyncCallback&lt;void&gt;): void

隐藏当前窗口，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                      | 必填 | 说明       |
  | -------- | ------------------------- | ---- | ---------- |
  | callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

- 示例

  ```
  windowClass.hide((err) => {
      if (err.code) {
          console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('window hidden.')
  })
  ```

### hide<sup>7+</sup>

hide(): Promise&lt;void&gt;;

隐藏当前窗口，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 返回值

  | 类型                | 说明                                            |
  | ------------------- | ----------------------------------------------- |
  | Promise&lt;void&gt; | 以Promise形式返回结果，返回当前函数执行的结果。 |

- 示例

  ```
   let promise = windowClass.hide();
   promise.then(()=> {
      console.info('window hidden.')
   }).catch((err)=>{
      console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
   })
  ```

### show<sup>7+</sup>

show(callback: AsyncCallback&lt;void&gt;): void

显示当前窗口，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                      | 必填 | 说明       |
  | -------- | ------------------------- | ---- | ---------- |
  | callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

- 示例

  ```
  windowClass.show((err) => {
      if (err.code) {
          console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in showing the window.')
  })
  ```

### show<sup>7+</sup>

show(): Promise&lt;void&gt;

显示当前窗口，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 返回值

  | 类型                | 说明                                            |
  | ------------------- | ----------------------------------------------- |
  | Promise&lt;void&gt; | 以Promise形式返回结果，返回当前函数执行的结果。 |

- 示例

  ```
   let promise = windowClass.show();
   promise.then(()=> {
      console.info('Succeeded in showing the window.')
   }).catch((err)=>{
      console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
   })
  ```

### destroy<sup>7+</sup>

destroy(callback: AsyncCallback&lt;void&gt;): void

销毁当前窗口，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                      | 必填 | 说明       |
  | -------- | ------------------------- | ---- | ---------- |
  | callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

- 示例

  ```
  windowClass.destroy((err) => {
      if (err.code) {
          console.error('Failed to destroy the window. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in destroying the window.')
  })
  ```

### destroy<sup>7+</sup>

destroy(): Promise&lt;void&gt;

销毁当前窗口，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 返回值

  | 类型                | 说明                                            |
  | ------------------- | ----------------------------------------------- |
  | Promise&lt;void&gt; | 以Promise形式返回结果，返回当前函数执行的结果。 |

- 示例

  ```
   let promise = windowClass.destroy();
   promise.then(()=> {
      console.info('Succeeded in destroying the window.')
   }).catch((err)=>{
      console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
   })
  ```

### moveTo<sup>7+</sup>

moveTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void

移动窗口位置，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                      | 必填 | 说明                                    |
  | -------- | ------------------------- | ---- | --------------------------------------- |
  | x        | number                    | 是   | 窗口在x轴方向移动的值，值为正表示右移。 |
  | y        | number                    | 是   | 窗口在y轴方向移动的值，值为正表示下移。 |
  | callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                              |

- 示例

  ```
  windowClass.moveTo(300, 300, (err)=>{
      if (err.code) {
          console.error('Failed to move the window. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Window moved.');
  
  });
  ```

### moveTo<sup>7+</sup>

moveTo(x: number, y: number): Promise&lt;void&gt;

移动窗口位置，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名 | 类型   | 必填 | 说明                                    |
  | ------ | ------ | ---- | --------------------------------------- |
  | x      | number | 是   | 窗口在x轴方向移动的值，值为正表示右移。 |
  | y      | number | 是   | 窗口在y轴方向移动的值，值为正表示下移。 |

- 返回值

  | 类型                | 说明                                            |
  | ------------------- | ----------------------------------------------- |
  | Promise&lt;void&gt; | 以Promise形式返回结果，返回当前函数执行的结果。 |

- 示例

  ```
   let promise = windowClass.moveTo(300, 300);
   promise.then(()=> {
      console.info('Window moved.')
   }).catch((err)=>{
      console.error('Failed to move the window. Cause: ' + JSON.stringify(err));
   })
  ```

### resetSize<sup>7+</sup>

resetSize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void

改变当前窗口大小，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                      | 必填 | 说明             |
  | -------- | ------------------------- | ---- | ---------------- |
  | width    | number                    | 是   | 目标窗口的宽度。 |
  | height   | number                    | 是   | 目标窗口的高度。 |
  | callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。       |

- 示例

  ```
  windowClass.resetSize(500, 1000, (err) => {
      if (err.code) {
          console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Window size changed.');
  });
  ```

### resetSize<sup>7+</sup>

resetSize(width: number, height: number): Promise&lt;void&gt;

改变当前窗口大小，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名 | 类型   | 必填 | 说明             |
  | ------ | ------ | ---- | ---------------- |
  | width  | number | 是   | 目标窗口的宽度。 |
  | height | number | 是   | 目标窗口的高度。 |

- 返回值

  | 类型                | 说明                                            |
  | ------------------- | ----------------------------------------------- |
  | Promise&lt;void&gt; | 以Promise形式返回结果，返回当前函数执行的结果。 |

- 示例

  ```
   let promise = windowClass.resetSize(500, 1000);
   promise.then(()=> {
      console.info('Window size changed.')
   }).catch((err)=>{
      console.error('Failed to change the window size. Cause: ' + JSON.stringify(err));
   });
  ```

### setWindowType<sup>7+</sup>

setWindowType(type: WindowType, callback: AsyncCallback&lt;void&gt;): void

设置窗口类型，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                      | 必填 | 说明       |
  | -------- | ------------------------- | ---- | ---------- |
  | type     | [WindowType](#windowtype) | 是   | 窗口类型。 |
  | callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

- 示例

  ```
  var type = window.TYPE_APP;
  windowClass.setWindowType(type, (err) => {
    if (err.code) {
        console.error('Failed to set the window type. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window type.')
  });
  ```

### setWindowType<sup>7+</sup>

setWindowType(type: WindowType): Promise&lt;void&gt;

设置窗口类型，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名 | 类型                      | 必填 | 说明       |
  | ------ | ------------------------- | ---- | ---------- |
  | type   | [WindowType](#windowtype) | 是   | 窗口类型。 |

- 返回值

  | 类型                | 说明                                            |
  | ------------------- | ----------------------------------------------- |
  | Promise&lt;void&gt; | 以Promise形式返回结果，返回当前函数执行的结果。 |

- 示例

  ```
   var type = window.TYPE_APP;
   let promise = windowClass.setWindowType(type);
   promise.then(()=> {
      console.info('Succeeded in setting the window type.')
   }).catch((err)=>{
      console.error('Failed to set the window type. Cause: ' + JSON.stringify(err));
   });
  ```

### getProperties

getProperties(callback: AsyncCallback&lt;WindowProperties&gt;): void

获取当前窗口的属性，使用callback方式作为异步方法返回WindowProperties。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                                                       | 必填 | 说明               |
  | -------- | ---------------------------------------------------------- | ---- | ------------------ |
  | callback | AsyncCallback&lt;[WindowProperties](#windowproperties)&gt; | 是   | 回调返回窗口属性。 |

- 示例

  ```
  windowClass.getProperties((err, data) => {
      if (err.code) {
          console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data));
  });
  ```

### getProperties

getProperties(): Promise&lt;WindowProperties&gt;

获取当前窗口的属性，使用promise方式作为异步方法返回WindowProperties。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 返回值

  | 类型                                                 | 说明                                  |
  | ---------------------------------------------------- | ------------------------------------- |
  | Promise&lt;[WindowProperties](#windowproperties)&gt; | 以Promise形式返回结果，返回窗口属性。 |

- 示例

  ```
   let promise = windowClass.getProperties();
   promise.then((data)=> {
      console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data))
   }).catch((err)=>{
      console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(err));
   });
  ```

### getAvoidArea<sup>7+</sup>

getAvoidArea(type: AvoidAreaType, callback: AsyncCallback&lt;AvoidArea&gt;): void

获取窗口内容规避的区域，如系统的系统栏区域、凹凸区域。使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                                         | 必填 | 说明                                                         |
  | -------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
  | type     | [AvoidAreaType](#avoidareatype)              | 是   | 表示规避区类型。type为TYPE_SYSTEM，表示系统默认区域。type为TYPE_CUTOUT，表示刘海屏区域。 |
  | callback | AsyncCallback&lt;[AvoidArea](#avoidarea)&gt; | 是   | 回调返回窗口内容规避区域。                                   |

- 示例

  ```
  var type = window.AvoidAreaType.TYPE_SYSTEM;
  windowClass.getAvoidArea(type, (err, data) => {
      if (err.code) {
          console.error('Failed to obtain the area. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data));
  });
  ```

### getAvoidArea<sup>7+</sup>

getAvoidArea(type: AvoidAreaType): Promise&lt;AvoidArea&gt;

获取窗口内容规避的区域，如系统的系统栏区域、凹凸区域。使用promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名 | 类型                            | 必填 | 说明                                                         |
  | ------ | ------------------------------- | ---- | ------------------------------------------------------------ |
  | type   | [AvoidAreaType](#avoidareatype) | 是   | 表示规避区类型。type为TYPE_SYSTEM，表示系统默认区域。type为TYPE_CUTOUT，表示刘海屏区域。 |

- 返回值

  | 类型                                   | 说明                                          |
  | -------------------------------------- | --------------------------------------------- |
  | Promise&lt;[AvoidArea](#avoidarea)&gt; | 以Promise形式返回结果，返回窗口内容规避区域。 |

- 示例

  ```
   let promise = windowClass.getAvoidArea();
   promise.then((data)=> {
      console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data))
   }).catch((err)=>{
      console.error('Failed to obtain the area. Cause:' + JSON.stringify(err));
   });
  ```

### setFullScreen

setFullScreen(isFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

设置是否为全屏状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名       | 类型                      | 必填 | 说明                                           |
  | ------------ | ------------------------- | ---- | ---------------------------------------------- |
  | isFullScreen | boolean                   | 是   | 是否设为全屏状态，且全屏状态隐藏状态栏导航栏。 |
  | callback     | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                     |

- 示例

  ```
  var isFullScreen = true;
  windowClass.setFullScreen(isFullScreen, (err) => {
      if (err.code) {
          console.error('Failed to enable the full-screen mode. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in enabling the full-screen mode.');
  });
  ```

### setFullScreen

setFullScreen(isFullScreen: boolean): Promise&lt;void&gt;

设置是否为全屏状态，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名       | 类型    | 必填 | 说明                                           |
  | ------------ | ------- | ---- | ---------------------------------------------- |
  | isFullScreen | boolean | 是   | 是否设为全屏状态，且全屏状态隐藏状态栏导航栏。 |

- 返回值

  | 类型                | 说明                                            |
  | ------------------- | ----------------------------------------------- |
  | Promise&lt;void&gt; | 以Promise形式返回结果，返回当前函数执行的结果。 |

- 示例

  ```
  var isFullScreen = true;
  let promise = windowClass.setFullScreen(isFullScreen);
  promise.then(()=> {
      console.info('Succeeded in enabling the full-screen mode.'))
  }).catch((err)=>{
      console.error('Failed to enable the full-screen mode. Cause: ' + JSON.stringify(err));
  });
  ```

### setLayoutFullScreen<sup>7+</sup>

setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口的布局是否为全屏显示状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名             | 类型                      | 必填 | 说明                                                         |
  | ------------------ | ------------------------- | ---- | ------------------------------------------------------------ |
  | isLayoutFullScreen | boolean                   | 是   | 窗口的布局是否为全屏显示状态，且全屏状态下状态栏、导航栏仍然显示。 |
  | callback           | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

- 示例

  ```
  var isLayoutFullScreen= true;
  windowClass.setLayoutFullScreen(isLayoutFullScreen, (err) => {
      if (err.code) {
          console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the window layout to full-screen mode.');
  });
  ```

### setLayoutFullScreen<sup>7+</sup>

setLayoutFullScreen(isLayoutFullScreen: boolean): Promise&lt;void&gt;

设置窗口的布局是否为全屏显示状态，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名             | 类型    | 必填 | 说明                                                         |
  | ------------------ | ------- | ---- | ------------------------------------------------------------ |
  | isLayoutFullScreen | boolean | 是   | 窗口的布局是否为全屏显示状态，且全屏状态下状态栏、导航栏仍然显示。 |

- 返回值

  | 类型                | 说明                                            |
  | ------------------- | ----------------------------------------------- |
  | Promise&lt;void&gt; | 以Promise形式返回结果，返回当前函数执行的结果。 |

- 示例

  ```
  var isLayoutFullScreen = true;
  let promise = windowClass.setLayoutFullScreen(isLayoutFullScreen);
  promise.then(()=> {
      console.info('Succeeded in setting the window layout to full-screen mode.'))
  }).catch((err)=>{
      console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
  });
  ```

### setSystemBarEnable<sup>7+</sup>

setSystemBarEnable(names: Array<'status' | 'navigation'>, callback: AsyncCallback&lt;void&gt;): void

设置导航栏、状态栏的可见模式，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                      | 必填 | 说明                                                         |
  | -------- | ------------------------- | ---- | ------------------------------------------------------------ |
  | names    | Array                     | 是   | 设置状态栏和导航栏是否显示。例如，需全部显示，该参数设置为["status",&nbsp;"navigation"], 不设置，则默认不显示。 |
  | callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

- 示例

  ```
  var names = ["status", "navigation"];
  windowClass.setSystemBarEnable(names, (err) => {
      if (err.code) {
          console.error('Failed to set the system bar to be visible. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the system bar to be visible.');
  });
  ```

### setSystemBarEnable<sup>7+</sup>

setSystemBarEnable(names: Array<'status' | 'navigation'>): Promise&lt;void&gt;

设置导航栏、状态栏的可见模式，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名 | 类型  | 必填 | 说明                                                         |
  | ------ | ----- | ---- | ------------------------------------------------------------ |
  | names  | Array | 是   | 设置状态栏和导航栏是否显示。例如，需全部显示，该参数设置为["status",&nbsp;"navigation"], 不设置，则默认不显示。 |

- 返回值

  | 类型                | 说明                                            |
  | ------------------- | ----------------------------------------------- |
  | Promise&lt;void&gt; | 以Promise形式返回结果，返回当前函数执行的结果。 |

- 示例

  ```
  var names = ["status", "navigation"];
  let promise = windowClass.setSystemBarEnable(names);
  promise.then(()=> {
      console.info('Succeeded in setting the system bar to be visible.'))
  }).catch((err)=>{
      console.error('Failed to set the system bar to be visible. Cause:' + JSON.stringify(err));
  });
  ```

### setSystemBarProperties

setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback&lt;void&gt;): void

设置窗口内导航栏、状态栏的属性，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名              | 类型                                        | 必填 | 说明                 |
  | ------------------- | ------------------------------------------- | ---- | -------------------- |
  | SystemBarProperties | [SystemBarProperties](#systembarproperties) | 是   | 导航栏状态栏的属性。 |
  | callback            | AsyncCallback&lt;void&gt;                   | 是   | 回调函数。           |

- 示例

  ```
  var SystemBarProperties={
      statusBarColor: '#ff00ff',
      navigationBarColor: '#00ff00',
      //以下两个属性从API Version7开始支持
      isStatusBarLightIcon: true,
      isNavigationBarLightIcon:false,
      //以下两个属性从API Version8开始支持
      statusBarContentColor:'#ffffff'
      navigationBarContentColor:'#00ffff'
  };
  windowClass.setSystemBarProperties(SystemBarProperties, (err) => {
      if (err.code) {
          console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the system bar properties.');
  });
  ```

### setSystemBarProperties

setSystemBarProperties(systemBarProperties: SystemBarProperties): Promise&lt;void&gt;

设置窗口内导航栏、状态栏的属性，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名              | 类型                                        | 必填 | 说明                 |
  | ------------------- | ------------------------------------------- | ---- | -------------------- |
  | SystemBarProperties | [SystemBarProperties](#systembarproperties) | 是   | 导航栏状态栏的属性。 |

- 返回值

  | 类型                | 说明                                            |
  | ------------------- | ----------------------------------------------- |
  | Promise&lt;void&gt; | 以Promise形式返回结果，返回当前函数执行的结果。 |

- 示例

  ```
  var SystemBarProperties={
      statusBarColor: '#ff00ff',
      navigationBarColor: '#00ff00',
      //以下两个属性从API Version7开始支持
      isStatusBarLightIcon: true,
      isNavigationBarLightIcon:false,
      //以下两个属性从API Version8开始支持
      statusBarContentColor:'#ffffff'
      navigationBarContentColor:'#00ffff'
  };
  let promise = windowClass.setSystemBarProperties(SystemBarProperties);
  promise.then(()=> {
      console.info('Succeeded in setting the system bar properties.'))
  }).catch((err)=>{
      console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
  });
  ```

### loadContent<sup>8+</sup>

loadContent(path: string, storage: ContentStorage, callback: AsyncCallback&lt;void&gt;): void

当前窗口加载具体页面内容，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                      | 必填 | 说明                 |
  | -------- | ------------------------- | ---- | -------------------- |
  | path     | string                    | 是   | 设置加载页面的路径。 |
  | storage  | ContentStorage            | 否   | 当前应用内的数据。   |
  | callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

- 示例

  ```
  windowClass.loadContent("pages/page2/page2", (err) => {
     if (err.code) {
           console.error('Failed to load the content. Cause:' + JSON.stringify(err));
           return;
     }
    console.info('Succeeded in loading the content.');
  });
  ```

### loadContent<sup>8+</sup>

loadContent(path: string, storage?: ContentStorage): Promise&lt;void&gt;

当前窗口加载具体页面内容，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名  | 类型           | 必填 | 说明                 |
  | ------- | -------------- | ---- | -------------------- |
  | path    | string         | 是   | 设置加载页面的路径。 |
  | storage | ContentStorage | 否   | 当前应用内的数据。   |

- 返回值

  | 类型                | 说明                                            |
  | ------------------- | ----------------------------------------------- |
  | Promise&lt;void&gt; | 以Promise形式返回结果，返回当前函数执行的结果。 |

- 示例

  ```
  let promise = windowClass.loadContent("pages/page2/page2");
  promise.then(()=> {
      console.info('Succeeded in loading the content.'))
  }).catch((err)=>{
      console.error('Failed to load the content. Cause: ' + JSON.stringify(err));
  });
  ```

### isShowing<sup>7+</sup>

isShowing(callback: AsyncCallback&lt;boolean&gt;): void

判断当前窗口是否已显示，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                         | 必填 | 说明                             |
  | -------- | ---------------------------- | ---- | -------------------------------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数返回是否显示子窗口结果。 |

- 示例

  ```
  windowClass.isShowing((err) => {
      if (err.code) {
          console.error('Failed to check whether the window is showing. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in checking whether the window is showing. Cause:')
  });
  ```

### isShowing<sup>7+</sup>

isShowing(): Promise&lt;boolean&gt;

判断当前窗口是否已显示，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 返回值

  | 类型                   | 说明                                                  |
  | ---------------------- | ----------------------------------------------------- |
  | Promise&lt;boolean&gt; | 以Promise形式返回结果，返回当前窗口是否已显示的结果。 |

- 示例

  ```
  let promise = windowClass.isShowing();
  promise.then(()=> {
      console.info('Succeeded in checking whether the window is showing.')
  }).catch((err)=>{
      console.error('Failed to check whether the window is showing. Cause: ' + JSON.stringify(err));
  });
  ```

### on('windowSizeChange'|'systemAvoidAreaChange')

on(type: 'windowSizeChange'|'systemAvoidAreaChange', callback: Callback&lt;AvoidArea | Size&gt;): void

开启监听。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                                                         | 必填 | 说明                                                         |
  | -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
  | type     | string                                                       | 是   | 设置监听类型。<br/>-&nbsp;type为'windowSizeChange'<sup>7+</sup>时表示监听类型为窗口尺寸变化监听；<br/>-&nbsp;type为'systemAvoidAreaChange'<sup>7+</sup>时表示监听类型为系统窗口规避区变化监听。 |
  | callback | Callback&lt;[AvoidArea](#avoidarea)&nbsp;\|&nbsp;[Size](#size)&gt; | 是   | 回调返回监听到的信息。                                       |

- 示例

  ```
  var type = 'windowSizeChange';
  windowClass.on(type, (data) => {
      console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data));
  });
  ```

### off('windowSizeChange'|'systemAvoidAreaChange')<sup>7+</sup>

off(type: 'windowSizeChange'|'systemAvoidAreaChange', callback?: Callback&lt;AvoidArea | Size &gt;): void

关闭监听。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                                                         | 必填 | 说明                                                         |
  | -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
  | type     | string                                                       | 是   | 设置监听类型。<br/>-&nbsp;type为'windowSizeChange'<sup>7+</sup>时表示监听类型为窗口尺寸变化监听；<br/>-&nbsp;type为'systemAvoidAreaChange'<sup>7+</sup>时表示监听类型为系统窗口规避区变化监听。 |
  | callback | Callback&lt;[AvoidArea](#avoidarea)&nbsp;\|&nbsp;[Size](#size)&gt; | 否   | 回调返回监听到的信息。                                       |

- 示例

  ```
  var type = 'windowSizeChange';
  windowClass.off(type);
  ```

### isSupportWideGamut<sup>8+</sup>

isSupportWideGamut(callback: AsyncCallback&lt;boolean&gt;): void

判断当前窗口是否支持广色域模式，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                         | 必填 | 说明                             |
  | -------- | ---------------------------- | ---- | -------------------------------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数返回是否支持广色域模式。 |

- 示例

  ```
  windowClass.isSupportWideGamut((err) => {
      if (err.code) {
          console.error('Failed to check whether the window support WideGamut. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in checking whether the window support WideGamut.')
  })
  ```

### isSupportWideGamut<sup>8+</sup>

isSupportWideGamut(): Promise&lt;boolean&gt;

判断当前窗口是否支持广色域模式，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 返回值

  | 类型                   | 说明                                                         |
  | ---------------------- | ------------------------------------------------------------ |
  | Promise&lt;boolean&gt; | 以Promise形式返回结果，返回当前窗口是否支持广色域模式的结果。 |

- 示例

  ```
  let promise = windowClass.isSupportWideGamut();
  promise.then(()=> {
      console.info('Succeeded in checking whether the window support WideGamut.')
  }).catch((err)=>{
      console.error('Failed to check whether the window support WideGamut. Cause: ' + JSON.stringify(err));
  });
  ```

### setColorSpace<sup>8+</sup>

setColorSpace(colorSpace:ColorSpace, callback: AsyncCallback&lt;void&gt;): void

设置当前窗口为广色域模式或默认色域模式，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名     | 类型                      | 必填 | 说明         |
  | ---------- | ------------------------- | ---- | ------------ |
  | colorSpace | [ColorSpace](#colorspace) | 是   | 设置色域模式 |
  | callback   | AsyncCallback&lt;void&gt; | 是   | 回调函数。   |

- 示例

  ```
  windowClass.setColorSpace(window.ColorSpace.WIDE_GAMUT, (err) => {
      if (err.code) {
          console.error('Failed to set window colorspace. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting window colorspace.')
  })
  ```

### setColorSpace<sup>8+</sup>

setColorSpace(colorSpace:ColorSpace): Promise&lt;void&gt;

设置当前窗口为广色域模式或默认色域模式，使用promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名     | 类型                      | 必填 | 说明         |
  | ---------- | ------------------------- | ---- | ------------ |
  | colorSpace | [ColorSpace](#colorspace) | 是   | 设置色域模式 |

- 返回值

  | 类型                | 说明                                            |
  | ------------------- | ----------------------------------------------- |
  | Promise&lt;void&gt; | 以Promise形式返回结果，返回当前函数执行的结果。 |

- 示例

  ```
  let promise = windowClass.isSupportWideGamut(window.ColorSpace.WIDE_GAMUT);
  promise.then(()=> {
      console.info('Succeeded in setting window colorspace.')
  }).catch((err)=>{
      console.error('Failed to set window colorspacet. Cause: ' + JSON.stringify(err));
  });
  ```

### getColorSpace<sup>8+</sup>

getColorSpace(callback: AsyncCallback&lt;ColorSpace&gt;): void

获取当前窗口色域模式，使用callback方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 参数

  | 参数名   | 类型                                           | 必填 | 说明                       |
  | -------- | ---------------------------------------------- | ---- | -------------------------- |
  | callback | AsyncCallback&lt;[ColorSpace](#colorspace)&gt; | 是   | 回调函数返回当前色域模式。 |

- 示例

  ```
  windowClass.getColorSpace((err, data) => {
      if (err.code) {
          console.error('Failed to get window color space. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in getting window color space. Cause:' + JSON.stringify(data))
  })
  ```

### getColorSpace<sup>8+</sup>

getColorSpace(): Promise&lt;ColorSpace&gt;

获取当前窗口色域模式，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

- 返回值

  | 类型                                     | 说明                                      |
  | ---------------------------------------- | ----------------------------------------- |
  | Promise&lt;[ColorSpace](#colorspace)&gt; | 以Promise形式返回结果，返回当前色域模式。 |

- 示例

  ```
  let promise = windowClass.getColorSpace();
  promise.then((data)=> {
      console.info('Succeeded in getting window color space. Cause:' + JSON.stringify(data))
  }).catch((err)=>{
      console.error('Failed to set window colorspacet. Cause: ' + JSON.stringify(err));
  });
  ```


# 窗口

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import window from '@ohos.window';
```


## 权限列表

ohos.permission.SYSTEM_FLOAT_WINDOW


## SystemBarProperties

状态栏导航栏的属性。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| statusBarColor | string | 是 | 是 | 状态栏颜色，为16进制颜色，例如"\#00FF00"或"\#FF00FF00"。 |
| isStatusBarLightIcon<sup>7+</sup> | boolean | 是 | 是 | 状态栏图标是否为高亮状态。 |
| navigationBarColor | string | 是 | 是 | 导航栏颜色，为16进制颜色，例如"\#00FF00"或"\#FF00FF00"。 |
| isNavigationBarLightIcon<sup>7+</sup> | boolean | 是 | 是 | 导航栏图标是否为高亮状态。 |


## Rect<sup>7+</sup><a name="rect"></a>

矩形。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| left | number | 是 | 是 | 矩形区域的左边界。 |
| top | number | 是 | 是 | 矩形区域的上边界。 |
| width | number | 是 | 是 | 矩形区域的宽度。 |
| height | number | 是 | 是 | 矩形区域的高度。 |


## AvoidArea<sup>7+</sup><a name="avoidarea"></a>

表示窗口内容规避区域。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| leftRect | [Rect](#rect) | 是 | 是 | 屏幕左侧的矩形区。 |
| topRect | [Rect](#rect) | 是 | 是 | 屏幕顶部的矩形区。 |
| rightRect | [Rect](#rect) | 是 | 是 | 屏幕右侧的矩形区。 |
| bottomRect | [Rect](#rect) | 是 | 是 | 屏幕底部的矩形区。 |


## Size<sup>7+</sup><a name="size"></a>

窗口大小。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| width | number | 是 | 是 | 窗口宽度。 |
| height | number | 是 | 是 | 窗口高度。 |


## WindowProperties

窗口属性。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| windowRect<sup>7+</sup> | [Rect](#rect) | 是 | 否 | 窗口尺寸。 |
| type<sup>7+</sup> | [WindowType](#windowtype) | 是 | 否 | 窗口类型。 |
| brightness | number | 是 | 是 | 屏幕亮度，取值范围为0~1，1表示最大亮度值。 |
| isTransparent<sup>7+</sup> | boolean | 是 | 是 | 窗口是否透明，默认为false。 |
| isFullScreen | boolean | 是 | 是 | 是否全屏，默认为false。 |
| isKeepScreenOn | boolean | 是 | 是 | 屏幕是否常亮，默认为false。 |
| dimBehindValue<sup>7+</sup> | number | 是 | 是 | 靠后的窗口的暗度值，取值范围为0~1，1表示最暗。 |
| isLayoutFullScreen<sup>7+</sup> | boolean | 是 | 是 | 窗口是否为沉浸式，默认为false。 |
| focusable<sup>7+</sup> | boolean | 是 | 是 | 窗口是否可聚焦，默认为true。 |
| touchable<sup>7+</sup> | boolean | 是 | 是 | 窗口是否可触摸，默认为true。 |
| isPrivacyMode<sup>7+</sup> | boolean | 是 | 是 | 隐私模式，默认为false。 |
| isRoundCorner<sup>7+</sup> | boolean | 是 | 是 | 窗口是否为圆角。 |


## SplitScreenBoundsInfo<sup>7+</sup><a name="splitscreenboundsinfo"></a>

分屏边界相关信息。

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| [splitMode](#splitmode) | number | 表示分屏模式。 |
| primaryBounds | [Rect](#rect) | 表示主要边界信息，返回Rect类实例。 |
| secondaryBounds | [Rect](#rect) | 表示次要边界信息，返回Rect类实例。 |


## window.getTopWindow<a name="window-gettopwindow"></a>

getTopWindow(callback: AsyncCallback&lt;Window&gt;): void

获取当前窗口，用于获取到window实例。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[Window](#window)&gt; | 是 | 回调返回当前窗口对象。 |

- 示例
  ```
  window.getTopWindow((err, data) => {
      if (err) {
          console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
      windowClass = data;
  });
  ```


## window.create<sup>7+</sup>

create(id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void

创建子窗口。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | string | 是 | 窗口id。 |
  | type | [WindowType](#windowtype) | 是 | 窗口类型。 |
  | callback | AsyncCallback&lt;[Window](#window)&gt; | 是 | 回调返回当前窗口对象。 |

- 示例


```
 window.create("first", 1, (err, data) => {
    windowClass = data;
    if (err) {
        console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('SubWindow created. Data: ' + JSON.stringify(data))
    windowClass.resetSize(500, 1000);
    windowClass.setOutsideTouchable(true);
    windowClass.loadContent("pages/index/index", (err, data) => {
   });
})
```


## window.find<sup>7+</sup>

find(id: string, callback: AsyncCallback&lt;Window&gt;): void

查找子窗口。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | string | 是 | 窗口id。 |
  | callback | AsyncCallback&lt;[Window](#window)&gt; | 是 | 回调返回当前窗口对象。 |

- 示例
  ```
   window.find("first", (err, data) => {
     if (err) {
         console.error('Failed to find the subWindow. Cause: ' + JSON.stringify(err));
         return;
     }
    console.info('SubWindow found. Data: ' + JSON.stringify(data))
    windowClass = data;
  })
  ```


## window.getAbilityWindowMode<sup>7+</sup>

getAbilityWindowMode(callback: AsyncCallback&lt;WindowMode&gt;): void

获取当前窗口模式。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WindowMode](#windowmode)&gt; | 是 | 回调返回当前窗口模式。 |

- 示例
  ```
  window.getAbilityWindowMode((err, data) => {
      if (err) {
          console.error(''Failed to obtain the window mode. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Window mode obtained. Data:' + JSON.stringify(data))
  
  });
  ```


## window.getSplitScreenBounds<sup>7+</sup>

getSplitScreenBounds(splitRatio: SplitRatio, callback: AsyncCallback&lt;SplitScreenBoundsInfo&gt;): void

获取分屏多窗口的位置和区域.。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | splitRatio | SplitRatio | 是 | 表示分屏比例，默认值为1:1，传值1表示1:2，传值2为2:1。 |
  | callback | AsyncCallback&lt;[SplitScreenBoundsInfo](#splitscreenboundsinfo)&gt; | 是 | 回调返回一个SplitScreenBoundsInfo对象，表示分屏边界相关信息。 |

- 示例
  ```
  var splitRatio = '1:1';
  window.getSplitScreenBounds(splitRatio, (err, data) => {
      if (err) {
          console.error('Failed to obtain the split-screen boundary information. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Split-screen boundary information obtained. Data: ' + JSON.stringify(data))
  
  });
  ```


## window.isFloatingAbilityWindowVisible<sup>7+</sup>

isFloatingAbilityWindowVisible(callback:AsyncCallback&lt;boolean&gt;): void

悬浮窗是否显示可见。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调返回一个boolean对象，表示悬浮窗是否可见。 |

- 示例
  ```
  window.isFloatingAbilityWindowVisible( (err, data) => {
      if (err) {
          console.error('Failed to check whether the floating window is visible. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in checking whether the floating window is visible. Data:' + JSON.stringify(data))
  
  });
  ```


## window.setSplitBarVisibility<sup>7+</sup>

setSplitBarVisibility(isVisibility: boolean, callback: AsyncCallback&lt;void&gt;): void

设置分屏线是否可见。

- 参数
  | 参数名 | 类型 | 说明 |
  | -------- | -------- | -------- |
  | isVisibility | boolean | 表示分屏线是否是否显示，true为显示，false为显示。 |
  | callback | AsyncCallback&lt;void&gt; | callback形式返回结果。 |

- 示例
  ```
  var isVisibility = false;
  window.setSplitBarVisibility(isVisibility , (err, data) => {
      if (err) {
          console.error('Failed to set the divider to be invisible. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the divider to be invisible. Data:' + JSON.stringify(data))
  });
  ```


## WindowType<sup>7+</sup><a name="windowtype"></a>

窗口类型。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| TYPE_APP | 0 | 表示应用窗口。 |
| TYPE_SYSTEM_ALERT | 1 | 表示系统弹窗。 |


## AvoidAreaType<sup>7+</sup><a name="avoidareatype"></a>

窗口内容需要规避区域的类型。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| TYPE_SYSTEM | 0 | 表示系统默认。 |
| TYPE_CUTOUT | 1 | 表示刘海屏区域。 |


## WindowMode<sup>7+</sup><a name="windowmode"></a>

窗口模式。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| UNDEFINED | 1 | 表示APP未定义窗口模式。 |
| FULLSCREEN | 2 | 表示APP全屏模式。 |
| PRIMARY | 3 | 表示APP分屏多窗口主要模式。 |
| SECONDARY | 4 | 表示APP分屏多窗口次要模式。 |
| FLOATING | 5 | 表示APP自由悬浮形式窗口模式。 |


## splitMode<sup>7+</sup><a name="splitmode"></a>

分屏模式。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| VERTICAL | 0 | 表示垂直上下分屏模式 |
| HORIZONTAL | 1 | 表示水平左右分屏模式 |


## Window

下列API示例中都需使用[getTopWindow()](#window-gettopwindow)先获取到Window实例，再通过此实例调用对应方法。


### setBrightness

setBrightness(brightness:number, callback: AsyncCallback&lt;void&gt;): void

设置屏幕亮度值。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | brightness | number | 是 | 屏幕亮度值，值为0-1之间。1表示最亮。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  var brightness = 10;
  windowClass.setBrightness(brightness, (err, data) => {
      if (err) {
          console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the brightness. Data: ' + JSON.stringify(data));
  });
  ```


### setBackgroundColor

setBackgroundColor(color: string, callback: AsyncCallback&lt;void&gt;): void

设置窗口的背景色。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | color | string | 是 | 需要设置的背景色，为16进制颜色，例如"\#00FF00"或"\#FF00FF00"。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  var color = '#00ff33';
  windowClass.setBackgroundColor(color, (err, data) => {
      if (err) {
          console.error('Failed to set the background color. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the background color. Data: ' + JSON.stringify(data));
  });
  ```

### setTransparent<sup>7+</sup>

setTransparent(isTransparent: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口是否透明。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | isTransparent | boolean | 是 | 窗口是否透明。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  var isTransparent = true;
  windowClass.setTransparent(isTransparent, (err, data) => {
      if (err) {
          console.error('Failed to set the window to be transparent. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the window to be transparent. Data: ' + JSON.stringify(data))
  });
  ```

### setFullScreen

setFullScreen(isFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

设置是否为全屏状态。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | isFullScreen | boolean | 是 | 是否设为全屏状态。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  var isFullScreen = true;
  windowClass.setFullScreen(isFullScreen, (err, data) => {
      if (err) {
          console.error('Failed to enable the full-screen mode. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in enabling the full-screen mode. Data: ' + JSON.stringify(data));
  });
  ```

### setKeepScreenOn

setKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback&lt;void&gt;): void

设置屏幕是否为常亮状态。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | isKeepScreenOn | boolean | 是 | 是否设置为屏幕常亮状态。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  var isKeepScreenOn = true;
  windowClass.setKeepScreenOn(isKeepScreenOn, (err, data) => {
      if (err) {
          console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the screen to be always on. Data: ' + JSON.stringify(data));
  });
  ```

### setWindowType<sup>7+</sup>

setWindowType(type: WindowType, callback: AsyncCallback&lt;void&gt;): void

设置窗口类型。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | [WindowType](#windowtype7) | 是 |窗口类型。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  var type = window.TYPE_APP;
  windowClass.setWindowType(type, (err, data) => {
    if (err) {
        console.error('Failed to set the window type. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window type. Data: ' + JSON.stringify(data))
  });
  ```

### setDimBehind<sup>7+</sup>

setDimBehind(dimBehindValue: number, callback: AsyncCallback&lt;void&gt;): void

窗口叠加时，设备有子窗口的情况下设置靠后的窗口的暗度值。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dimBehindValue | number | 是 | 表示靠后的窗口的暗度值，取值范围为0-1，1表示最暗。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  windowClass.setDimBehind(0.5, (err, data) => {
      if (err) {
          console.error('Failed to set the dimness. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the dimness. Data:' + JSON.stringify(data));
  });
  ```

### setLayoutFullScreen<sup>7+</sup>

setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口的布局是否为全屏显示状态。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | isLayoutFullScreen | boolean | 是 | 窗口的布局是否为全屏显示状态。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  var isLayoutFullScreen= true;
  windowClass.setLayoutFullScreen(isLayoutFullScreen, (err, data) => {
      if (err) {
          console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the window layout to full-screen mode. Data:' + JSON.stringify(data));
  });
  ```

### setFocusable<sup>7+</sup>

setFocusable(isFocusable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置点击时是否支持切换焦点窗口。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | isFocusable | boolean | 是 | 点击时是否支持切换焦点窗口。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  var isFocusable= true;
  windowClass.setFocusable(isFocusable, (err, data) => {
      if (err) {
          console.error('Failed to set the window to be focusable. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the window to be focusable. Data: ' + JSON.stringify(data));
  });
  ```

### setTouchable<sup>7+</sup>

setTouchable(isTouchable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口是否为可触状态。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | isTouchable | boolean | 是 | 窗口是否为可触状态。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  var isTouchable = true;
  windowClass.setTouchable(isTouchable, (err, data) => {
      if (err) {
          console.error('Failed to set the window to be touchable. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the window to be touchable. Data:' + JSON.stringify(data));
  
  });
  ```

### setPrivacyMode<sup>7+</sup>

setPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口是否为隐私模式。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | isPrivacyMode | boolean | 是 | 窗口是否为隐私模式。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  var isPrivacyMode = true;
  windowClass.setPrivacyMode(isPrivacyMode, (err, data) => {
      if (err) {
          console.error('Failed to set the window to privacy mode. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the window to privacy mode. Data:' + JSON.stringify(data));
  
  });
  ```

### setSystemBarEnable<sup>7+</sup>

setSystemBarEnable(names: Array, callback: AsyncCallback&lt;void&gt;): void

设置导航栏、状态栏的可见模式。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | names | Array | 是 | 设置状态栏和导航栏是否显示。例如，需全部显示，该参数设置为["status",&nbsp;"navigation"]。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  var names = ["status", "navigation"];
  windowClass.setSystemBarEnable(names, (err, data) => {
      if (err) {
          console.error('Failed to set the system bar to be visible. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the system bar to be visible. Data: ' + JSON.stringify(data));
  });
  ```

### setSystemBarProperties

setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback&lt;void&gt;): void

设置窗口内导航条状态栏的属性。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | SystemBarProperties | [SystemBarProperties](#systembarproperties) | 是 | 导航条状态栏的属性。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  var SystemBarProperties={
      statusBarColor: '#ff00ff',
      navigationBarColor: '#00ff00',
      //以下两个属性从API Version7开始支持
      isStatusBarLightIcon: true,
      isNavigationBarLightIcon:false
  };
  windowClass.setSystemBarProperties(SystemBarProperties, (err, data) => {
      if (err) {
          console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the system bar properties. Data: ' + JSON.stringify(data));
  });
  ```

### getProperties

getProperties(callback: AsyncCallback&lt;WindowProperties&gt;): void

获取当前窗口的属性，异步返回WindowProperties。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WindowProperties](#windowproperties)&gt; | 是 | 回调返回窗口属性。 |

- 示例
  ```
  windowClass.getProperties((err, data) => {
      if (err) {
          console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data));
  });
  ```

### getAvoidArea<sup>7+</sup>

getAvoidArea(type: AvoidAreaType, callback: AsyncCallback&lt;AvoidArea&gt;): void

获取窗口内容规避的区域。如系统的系统栏区域 、凹口区域。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | [AvoidAreaType](#avoidareatype) | 是 | 表示规避区类型。type为TYPE_SYSTEM，表示系统默认区域。type为TYPE_CUTOUT，表示刘海屏区域。 |
  | callback | AsyncCallback&lt;[AvoidArea](#avoidarea)&gt; | 是 | 回调返回窗口内容规避区域。 |

- 示例
  ```
  var type = window.AvoidAreaType.TYPE_SYSTEM;
  windowClass.getAvoidArea(type, (err, data) => {
      if (err) {
          console.error('Failed to obtain the area. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data));
  });
  ```

### moveTo<sup>7+</sup>

moveTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void

窗口位置移动。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | x | number | 是 | 窗口在x轴方向移动的值，值为正表示右移。 |
  | y | number | 是 | 窗口在y轴方向移动的值，值为正表示下移。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  windowClass.moveTo(300, 300, (err, data)=>{
      if (err) {
          console.error('Failed to move the window. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Window moved. Data:' + JSON.stringify(data));
  
  });
  ```

### resetSize<sup>7+</sup>

resetSize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void

改变当前窗口大小。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | width | number | 是 | 目标窗口的宽度。 |
  | height | number | 是 | 目标窗口的高度。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  windowClass.resetSize(500, 1000, (err, data) => {
      if (err) {
          console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Window size changed. Data:' + JSON.stringify(data));
  });
  ```

### loadContent<sup>7+</sup>

loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void

子窗口加载具体页面内容。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | path | string | 是 | 设置加载页面的代码路径。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  windowClass.loadContent("pages/page2/page2", (err, data) => {
     if (err) {
           console.error('Failed to load the content. Cause:' + JSON.stringify(err));
           return;
     }
    console.info('Succeeded in loading the content. Data:' + JSON.stringify(data));
  });
  ```

### hide<sup>7+</sup>

hide (callback: AsyncCallback&lt;void&gt;): void

隐藏子窗口。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  windowClass.hide((err, data) => {
      if (err) {
          console.error('Failed to hide the subwindow. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Subwindow hidden. Data:' + JSON.stringify(data))
  })
  ```

### show<sup>7+</sup>

show(callback: AsyncCallback&lt;void&gt;): void

显示子窗口。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  windowClass.show((err, data) => {
      if (err) {
          console.error('Failed to show the subwindow. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in showing the subwindow. Data: ' + JSON.stringify(data))
  })
  ```

### isShowing<sup>7+</sup>

isShowing(callback: AsyncCallback&lt;boolean&gt;): void

判断子窗口是否已显示。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数返回是否显示子窗口结果。 |

- 示例
  ```
  windowClass.isShowing((err, data) => {
      if (err) {
          console.error('Failed to check whether the subwindow is showing. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in checking whether the subwindow is showing. Cause:' + JSON.stringify(data))
  })
  ```

### destroy<sup>7+</sup>

destroy(callback: AsyncCallback&lt;void&gt;): void

销毁子窗口。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  windowClass.destroy((err, data) => {
      if (err) {
          console.error('Failed to destroy the subwindow. Cause:' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in destroying the subwindow. Data:' + JSON.stringify(data))
  })
  ```

### setOutsideTouchable<sup>7+</sup>

setOutsideTouchable(touchable: boolean, callback: AsyncCallback&lt;void&gt;): void;

设置是否允许可点击子窗口以外的区域。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | touchable | boolean | 是 | 设置是否可点击。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

- 示例
  ```
  windowClass.setOutsideTouchable(true, (err, data) => {
      if (err) {
          console.error('Failed to set the area to be touchable. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in setting the area to be touchable. Data: ' + JSON.stringify(data))
  })
  ```

### on('keyboardHeightChange')

on(type: string, callback: AsyncCallback&lt;number&gt;): void

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从 API Version 7 开始废弃。

开启监听键盘高度变化。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置监听类型为监听键盘高度变化，应设置type为'keyboardHeightChange'。 |
  | callback | AsyncCallback&lt;number&gt; | 是 | 回调返回监听到的键盘高度。 |

- 示例
  ```
  var type= 'keyboardHeightChange';
  windowClass.on(type, (err, data) => {
      if (err) {
          console.error('Failed to enable the listener for keyboard height changes. Cause: ' + JSON.stringify(err));
          return;
      }
      console.info('Succeeded in enabling the listener for keyboard height changes. Data: ' + JSON.stringify(data));
  });
  ```

### off('keyboardHeightChange')

off(type: string, callback?: AsyncCallback&lt;number&gt;): void

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从 API Version 7 开始废弃。

关闭监听键盘高度变化。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置监听类型为监听键盘高度变化，应设置type为'keyboardHeightChange'。 |
  | callback | AsyncCallback&lt;number&gt; | 否 | 回调返回监听到的键盘高度。 |

- 示例
  ```
  var type= 'keyboardHeightChange';
  windowClass.off(type);
  ```

### on('keyboardHeightChange'|'windowSizeChange'<sup>7+</sup>|'systemAvoidAreaChange'<sup>7+</sup>)

on(type: string, callback: Callback&lt;AvoidArea | Size | number&gt;): void

开启监听。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置监听类型。<br/>-&nbsp;type为'keyboardHeightChange'时表示监听类型为键盘高度变化监听；<br/>-&nbsp;type为'windowSizeChange'7+时表示监听类型为窗口尺寸变化监听；<br/>-&nbsp;type为'systemAvoidAreaChange'7+时表示监听类型为系统窗口规避区变化监听。 |
  | callback | Callback&lt;[AvoidArea](#avoidarea)&nbsp;\|&nbsp;[Size](#size)&nbsp;\|&nbsp;number&gt; | 是 | 回调返回监听到的信息。 |

- 示例
  ```
  var type = 'windowSizeChange';
  windowClass.on(type, (data) => {
      console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data));
  });
  ```

### off('keyboardHeightChange'|'windowSizeChange'<sup>7+</sup>|'systemAvoidAreaChange'<sup>7+</sup>)

off(type: string, callback?: Callback&lt;AvoidArea | Size | number&gt;): void

关闭监听。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置监听类型。<br/>-&nbsp;type为'keyboardHeightChange'时表示监听类型为键盘高度变化监听；<br/>-&nbsp;type为'windowSizeChange'7+时表示监听类型为窗口尺寸变化监听；<br/>-&nbsp;type为'systemAvoidAreaChange'7+时表示监听类型为系统窗口规避区变化监听。 |
  | callback | Callback&lt;[AvoidArea](#avoidarea)&nbsp;\|&nbsp;[Size](#size)&nbsp;\|&nbsp;number&gt; | 否 | 回调返回监听到的信息。 |

- 示例
  ```
  var type = 'windowSizeChange';
  windowClass.off(type);
  ```

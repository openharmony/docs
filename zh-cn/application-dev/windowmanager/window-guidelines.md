# 窗口开发指导

## 场景介绍
窗口的接口层在应用进程运行，负责对页面布局的加载，和提供应用程序接口。
通过调用窗口接口可以实现窗口创建与销毁，窗口的位置、大小布局，以及进入沉浸式等。

## 接口说明
窗口开放的能力如下：Window类，具体的API详见[接口文档](../reference/apis/js-apis-window.md)。

**表1** 窗口主要接口API

| 接口名                                                       | 描述                                           |
| :----------------------------------------------------------- | :--------------------------------------------- |
| create(id: string, type: WindowType, callback: AsyncCallback\<Window>): void | 创建子窗口。                                   |
| moveTo(x: number, y: number): Promise\<void>                 | 移动窗口位置，x值为正表示右移，y为正表示下移。 |
| resetSize(width: number, height: number): Promise\<void>     | 改变当前窗口大小。                             |
| hide(): Promise\<void>                                       | 隐藏当前窗口。                                 |
| destroy(): Promise\<void>                                    | 销毁当前窗口。                                 |

## 开发步骤

### 创建主窗口

在当前模型下，应用启动时会自动创建主窗口，由应用管理窗口的生命周期，隐藏及销毁由应用管理。
### 创建子窗口
当前可以通过`create`接口创建子窗口。具体示例代码如下：

```js
 import window from '@ohos.window';
 var windowClass = null;
 let promise = window.create("subWindow", window.WindowType.TYPE_APP);
 promise.then((data)=> {
 	windowClass = data;
    console.info('SubWindow created. Data: ' + JSON.stringify(data))
 }).catch((err)=>{
    console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));
 });
```

### 获取窗口对象

- 应用内可以通过`getTopWindow`来获取当前应用内最后显示的窗口。具体示例代码如下：

```js
 var windowClass = null;
 let promise = window.getTopWindow();
 promise.then((data)=> {
 	windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data))
 }).catch((err)=>{
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
 })
```

- 应用内也可以通过`Find`来获取已经创建的子窗口。具体示例代码如下：

```js
 var windowClass = null;
 let promise = window.find("subWindow");
 promise.then((data)=> {
 	windowClass = data;
    console.info('window found. Data: ' + JSON.stringify(data))
 }).catch((err)=>{
    console.error('Failed to find the Window. Cause: ' + JSON.stringify(err));
 });
```

### 窗口的隐藏和销毁

在已经获取到窗口对象的前提下，可以调用`hide`、`destroy`来隐藏和销毁已经创建的窗口对象。具体示例代码如下：

```js
 let promise = windowClass.hide();
 promise.then((data)=> {
    console.info('window hidden. Data: ' + JSON.stringify(data))
    windowClass.destroy((err, data) => {
        if (err.code) {
            console.error('Failed to destroy the window. Cause:' + JSON.stringify(err));
            return;
        }
    	console.info('Succeeded in destroying the window. Data: ' + JSON.stringify(data))
	})
 }).catch((err)=>{
    console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
 })
```

### 设置沉浸式窗口

在已经获取到应用窗口对象的前提下，调用`setFullScreen`来设置窗口进入全屏沉浸式。

示例代码如下：

```js
import window from '@ohos.window';
try {
  const win = await window.getTopWindow()
  await win.setFullScreen(true)
} catch (err) {
  console.log(`setFullScreen fail, code = ${err.code}`)
}
```

完整[示例工程](https://gitee.com/openharmony/windowmanager/tree/master/AppDemo/window/immersive)。


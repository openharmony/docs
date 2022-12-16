# 管理系统窗口（仅Stage模型支持）

## 管理系统窗口概述

在`Stage`模型下， 允许系统应用创建和管理系统窗口，包括音量条、壁纸、通知栏、状态栏、导航栏等。具体支持的系统窗口类型见[API参考-WindowType](../reference/apis/js-apis-window.md#windowtype7)。

> **说明：**
>
> 本文档涉及系统接口的使用，请使用full-SDK进行开发。具体使用可见[full-SDK替换指南](../quick-start/full-sdk-switch-guide.md)。


## 接口说明

更多API说明请参见[API参考](../reference/apis/js-apis-window.md)。

| 实例名 | 接口名 | 描述 |
| -------- | -------- | -------- |
| window静态方法 | createWindow(config: Configuration, callback: AsyncCallback\<Window>): void | 创建子窗口或系统窗口。<br/>-`config`：创建窗口时的参数。 |
| Window | resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | 改变当前窗口大小。 |
| Window | moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | 移动当前窗口位置。 |
| Window | SetUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void | 为当前窗口加载具体页面。 |
| Window | showWindow(callback: AsyncCallback\<void>): void | 显示当前窗口。 |
| Window | on(type: 'touchOutside', callback: Callback&lt;void&gt;): void | 开启本窗口区域外的点击事件的监听。 |
| Window | hide (callback: AsyncCallback\<void>): void | 隐藏当前窗口。此接口为系统接口。 |
| Window | destroyWindow(callback: AsyncCallback&lt;void&gt;): void | 销毁当前窗口。 |


## 开发步骤


本文以音量条窗口为例，介绍系统窗口的基本开发和管理步骤。


1. 创建系统窗口。

   在[ServiceExtensionContext](../reference/apis/js-apis-inner-application-serviceExtensionContext.md)下，使用`window.createWindow`接口创建音量条系统窗口。

2. 操作或设置系统窗口的属性。

   系统窗口创建成功后，可以改变其大小、位置等，还可以根据需要设置系统窗口的背景色、亮度等属性。

3. 加载显示系统窗口的具体内容。

   通过`SetUIContent`和`showWindow`接口加载显示音量条窗口的具体内容。

4. 隐藏/销毁系统窗口。

   当不再需要音量条窗口时，可根据具体实现逻辑，使用`hide`接口或`destroyWindow`接口对其进行隐藏或销毁。

```ts
import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
import window from '@ohos.window';

export default class ServiceExtensionAbility1 extends ExtensionContext {
    onCreate(want) {
        console.log("[Demo] MainAbility onCreate")
        globalThis.abilityWant = want;
        // 1.创建音量条窗口。
        let windowClass = null;
        let config = {name: "volume", windowType: window.WindowType.TYPE_VOLUME_OVERLAY, ctx: this.context};
        window.createWindow(config, (err, data) => {
            if (err.code) {
                console.error('Failed to create the volume window. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in creating the volume window.')
            windowClass = data;
            // 2.创建音量条窗口成功之后，可以改变其大小、位置或设置背景色、亮度等属性。
            windowClass.moveWindowTo(300, 300, (err) => {
                if (err.code) {
                    console.error('Failed to move the window. Cause:' + JSON.stringify(err));
                    return;
                }
                console.info('Succeeded in moving the window.');
            });
            windowClass.resize(500, 500, (err) => {
                if (err.code) {
                    console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
                    return;
                }
                console.info('Succeeded in changing the window size.');
            });
            // 3.为音量条窗口加载对应的目标页面。
            windowClass.setUIContent("pages/page_volume", (err) => {
                if (err.code) {
                    console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                    return;
                }
                console.info('Succeeded in loading the content.');
                // 3.显示音量条窗口。
                windowClass.showWindow((err) => {
                    if (err.code) {
                        console.error('Failed to show the window. Cause:' + JSON.stringify(err));
                        return;
                    }
                    console.info('Succeeded in showing the window.');
                });
            });
            // 4.隐藏/销毁音量条窗口。当不再需要音量条时，可根据具体实现逻辑，对其进行隐藏或销毁。
            // 此处以监听音量条区域外的点击事件为例实现音量条窗口的隐藏。
            windowClass.on('touchOutside', () => {
                console.info('touch outside');
                windowClass.hide((err) => {
                    if (err.code) {
                        console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
                        return;
                    }
                    console.info('Succeeded in hidinging the window.');
                });
            });
        });
    }
};
```

# System Window Development (Stage Model Only)

## Overview

In the stage model, system applications are allowed to create and manage system windows, including the volume bar, wallpaper, notification panel, status bar, and navigation bar. For details about the supported system window types, see [WindowType in Window](../reference/apis/js-apis-window.md#windowtype7).

> **NOTE**
>
> This document involves the use of system APIs. Use the full SDK for development. For details, see [Guide to Switching to Full SDK](../quick-start/full-sdk-switch-guide.md).


## Available APIs

For details, see [Window](../reference/apis/js-apis-window.md).

| Instance| API| Description|
| -------- | -------- | -------- |
| Window static method| create(ctx: Context, id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void | Creates a system window when **ctx** is [ServiceExtensionContext](../reference/apis/js-apis-service-extension-context.md).<br>- **ctx**: application context.  <br>- **type**: window type.|
| Window | resetSize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | Changes the window size.|
| Window | moveTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | Moves this window.|
| Window | loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void | Loads the page content to this window.|
| Window | show(callback: AsyncCallback\<void>): void | Shows this window.|
| Window | on(type: 'touchOutside', callback: Callback&lt;void&gt;): void | Enables listening for click events outside this window.|
| Window | hide (callback: AsyncCallback\<void>): void | Hides this window. This is a system API.|
| Window | destroy(callback: AsyncCallback&lt;void&gt;): void | Destroys this window.|


## How to Develop


This section uses the volume bar as an example to describe the steps for system window development.


1. Create a system window.

   In the case of [ServiceExtensionContext](../reference/apis/js-apis-service-extension-context.md), call **window.create** to create a system window of the volume bar type.

2. Set the properties of the system window.

   After the volume bar window is created, you can change its size and position, and set its properties such as the background color and brightness.

3. Load content for the system window and show it.

   You can call **loadContent** and **show** to load and display the content in the volume bar window.

4. Hide or destroy the system window.

   When the volume bar window is no longer needed, you can call **hide** or **destroy** to hide or destroy it.

```ts
import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
import window from '@ohos.window';

export default class ServiceExtensionAbility1 extends ExtensionContext {
    onCreate(want) {
        console.log("[Demo] MainAbility onCreate")
        globalThis.abilityWant = want;
        // 1. Create a volume bar window.
        let windowClass = null;
        window.create(this.context, "volume", window.WindowType.TYPE_VOLUME_OVERLAY, (err, data) => {
            if (err.code) {
                console.error('Failed to create the volume window. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in creating the volume window.')
            windowClass = data;
            // 2. Change the size and position of the volume bar window, or set its properties such as the background color and brightness.
            windowClass.moveTo(300, 300, (err, data) => {
                if (err.code) {
                    console.error('Failed to move the window. Cause:' + JSON.stringify(err));
                    return;
                }
                console.info('Succeeded in moving the window. Data: ' + JSON.stringify(data));
            });
            windowClass.resetSize(500, 1000, (err, data) => {
                if (err.code) {
                    console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
                    return;
                }
                console.info('Succeeded in changing the window size. Data: ' + JSON.stringify(data));
            });
            // 3. Load the page content to the volume bar window.
            windowClass.loadContent("pages/page_volume", (err, data) => {
                if (err.code) {
                    console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                    return;
                }
                console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
                // 3. Show the volume bar window.
                windowClass.show((err, data) => {
                    if (err.code) {
                        console.error('Failed to show the window. Cause:' + JSON.stringify(err));
                        return;
                    }
                    console.info('Succeeded in showing the window. Data: ' + JSON.stringify(data));
                });
            });
            // 4. Hide or destroy the volume bar window.
            // Hide the volume bar window when a click event outside the window is detected.
            windowClass.on('touchOutside', () => {
                console.info('touch outside');
                windowClass.hide((err, data) => {
                    if (err.code) {
                        console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
                        return;
                    }
                    console.info('Succeeded in hidinging the window. Data: ' + JSON.stringify(data));
                });
            });
        });
    }
};
```

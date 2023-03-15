# System Window Development (Stage Model Only)

## Overview

In the stage model, system applications are allowed to create and manage system windows, including the volume bar, wallpaper, notification panel, status bar, and navigation bar. For details about the supported system window types, see [WindowType in Window](../reference/apis/js-apis-window.md#windowtype7).

When a window is displayed, hidden, or switched, an animation is usually used to smooth the interaction process.

In OpenHarmony, the animation is the default behavior for application windows. You do not need to set or modify the code.

However, you can customize an animation to be played during the display or hiding of a system window.

> **NOTE**
>
> This document involves the use of system APIs. Use the full SDK for development. For details, see [Guide to Switching to Full SDK](../quick-start/full-sdk-switch-guide.md).


## Available APIs

For details, see [Window](../reference/apis/js-apis-window.md).

| Instance           | API                                                      | Description                                                        |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Window static method   | createWindow(config: Configuration, callback: AsyncCallback\<Window>): void | Creates a subwindow or system window.<br>**config** specifies the parameters used for creating the window.    |
| Window            | resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | Changes the window size.                                          |
| Window            | moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | Moves this window.                                          |
| Window            | SetUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void | Loads the page content to this window.                                    |
| Window            | showWindow(callback: AsyncCallback\<void>): void             | Shows this window.                                              |
| Window            | on(type: 'touchOutside', callback: Callback&lt;void&gt;): void | Enables listening for click events outside this window.                          |
| Window            | hide (callback: AsyncCallback\<void>): void                  | Hides this window. This is a system API.                            |
| Window            | destroyWindow(callback: AsyncCallback&lt;void&gt;): void     | Destroys this window.                                              |
| Window            | getTransitionController(): TransitionController              | Obtains the transition animation controller. This is a system API.                  |
| TransitionContext | completeTransition(isCompleted: boolean): void               | Completes the transition. This API can be called only after [animateTo()](../reference/arkui-ts/ts-explicit-animation.md) is executed. This is a system API.|
| Window            | showWithAnimation(callback: AsyncCallback\<void>): void      | Shows this window and plays an animation during the process. This is a system API.            |
| Window            | hideWithAnimation(callback: AsyncCallback\<void>): void      | Hides this window and plays an animation during the process. This is a system API.            |

## Developing a System Window

This section uses the volume bar as an example to describe how to develop a system window.

### How to Develop


1. Create a system window.

   In the case of [ServiceExtensionContext](../reference/apis/js-apis-inner-application-serviceExtensionContext.md), call **window.createWindow** to create a system window of the volume bar type.

2. Set the properties of the system window.

   After the volume bar window is created, you can change its size and position, and set its properties such as the background color and brightness.

3. Load content for the system window and show it.

   You can call **SetUIContent** and **showWindow** to load and display the content in the volume bar window.

4. Hide or destroy the system window.

   When the volume bar window is no longer needed, you can call **hide** or **destroyWindow** to hide or destroy it.

```ts
import ExtensionContext from '@ohos.app.ability.ServiceExtensionAbility';
import window from '@ohos.window';

export default class ServiceExtensionAbility1 extends ExtensionContext {
    onCreate(want) {
        globalThis.abilityWant = want;
        // 1. Create a volume bar window.
        let windowClass = null;
        let config = {name: "volume", windowType: window.WindowType.TYPE_VOLUME_OVERLAY, ctx: this.context};
        window.createWindow(config, (err, data) => {
            if (err.code) {
                console.error('Failed to create the volume window. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in creating the volume window.')
            windowClass = data;
            // 2. Change the size and position of the volume bar window, or set its properties such as the background color and brightness.
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
            // 3. Load the page content to the volume bar window.
            windowClass.setUIContent("pages/page_volume", (err) => {
                if (err.code) {
                    console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                    return;
                }
                console.info('Succeeded in loading the content.');
                // 3. Show the volume bar window.
                windowClass.showWindow((err) => {
                    if (err.code) {
                        console.error('Failed to show the window. Cause:' + JSON.stringify(err));
                        return;
                    }
                    console.info('Succeeded in showing the window.');
                });
            });
            // 4. Hide or destroy the volume bar window.
            // Hide the volume bar window when a click event outside the window is detected.
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

## Customizing an Animation to Be Played During the Display or Hiding of a System Window

You can determine whether to play an animation when a system window is showing or hiding.

### How to Develop

1. Obtain the transition animation controller.

   Call **getTransitionController** to obtain the controller, which completes subsequent animation operations.

2. Configure the animation to be played.

   Call [animateTo()](../reference/arkui-ts/ts-explicit-animation.md) to configure the animation attributes.

3. Complete the transition.

   Use **completeTransition(true)** to set the completion status of the transition. If **false** is passed in, the transition is canceled.

4. Show or hide the system window and play the animation during the process.

   Call **showWithAnimation** to show the window and play the animation. Call **hideWithAnimation** to hide the window and play the animation.

```ts
import ExtensionContext from '@ohos.app.ability.ServiceExtensionAbility';
import window from '@ohos.window';

export default class ServiceExtensionAbility1 extends ExtensionContext {
    onCreate(want) {
        globalThis.abilityWant = want;
        // Create a volume bar window.
        let windowClass = null;
        let config = {name: "volume", windowType: window.WindowType.TYPE_VOLUME_OVERLAY, ctx: this.context};
        window.createWindow(config, (err, data) => {
            if (err.code) {
                console.error('Failed to create the volume window. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in creating the volume window.')
            windowClass = data;
            // Customize an animation to be played during the display of the system window.
            // 1. Obtain the transition animation controller.
            let controller = windowClass.getTransitionController();
            // 2. Configure the animation to be played.
            controller.animationForShown = (context : window.TransitionContext) => {
                let toWindow = context.toWindow
                // Set the animation attributes.
                animateTo({
                    duration: 1000, // Animation duration.
                    tempo: 0.5, // Playback speed.
                    curve: Curve.EaseInOut, // Animation curve.
                    delay: 0, // Animation delay.
                    iterations: 1, // Number of playback times.
                    playMode: PlayMode.Normal // Animation playback mode.
                    onFinish: ()=> {
                        // 3. Complete the transition.
                        context.completeTransition(true)
                    }
                }, () => {
                    let obj : window.TranslateOptions = {
                        x : 100.0,
                        y : 0.0,
                        z : 0.0
                    }
                    toWindow.translate(obj);
                    console.info('toWindow translate end');
                })
                console.info('complete transition end');
            }

            windowClass.loadContent("pages/page_volume", (err) => {
                if (err.code) {
                    console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                    return;
                }
                console.info('Succeeded in loading the content.');
                // 4. Show the window and play the animation during the process.
                windowClass.showWithAnimation((err) => {
                    if (err.code) {
                        console.error('Failed to show the window with animation. Cause: ' + JSON.stringify(err));
                        return;
                    }
                    console.info('Succeeded in showing the window with animation.');
                })
            });
        });
    }
    onDestroy() {
        let windowClass = null;
        try {
            windowClass = window.findWindow('volume');
        } catch (exception) {
            console.error('Failed to find the Window. Cause: ' + JSON.stringify(exception));
        }
        // Customize an animation to be played during the hiding of the system window.
        // 1. Obtain the transition animation controller.
        let controller = windowClass.getTransitionController();
        // 2. Configure the animation to be played.
        controller.animationForHidden = (context : window.TransitionContext) => {
            let toWindow = context.toWindow
            // Set the animation attributes.
            animateTo({
                duration: 1000, // Animation duration.
                tempo: 0.5, // Playback speed.
                curve: Curve.EaseInOut, // Animation curve.
                delay: 0, // Animation delay.
                iterations: 1, // Number of playback times.
                playMode: PlayMode.Normal // Animation playback mode.
                onFinish: ()=> {
                    // 3. Complete the transition.
                    context.completeTransition(true)
                    windowClass.destroyWindow((err) => {
                        if (err.code) {
                            console.error('Failed to destroy the window. Cause:' + JSON.stringify(err));
                            return;
                        }
                        console.info('Succeeded in destroying the window.');
                    });
                }
            }, () => {
                toWindow.opacity(0.0);
                console.info('toWindow opacity end');
            })
            console.info('complete transition end');
        }
        // 4. Hide the window and play the animation during the process.
        windowClass.hideWithAnimation((err) => {
            if (err.code) {
                console.error('Failed to hide the window with animation. Cause: ' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in hiding the window with animation.');
        });
    }
};
```

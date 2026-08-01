# Using Display to Obtain Display Properties and Listen for Status Changes (ArkTS)

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @oh_wangxk-->
<!--Designer: @logn; @wulong158-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=5894207a89aa0ba2ff5ba646c58fe095f9c1b27c translatedAt=2026-08-01T02:50:46.018Z pushedAt=2026-08-01T06:47:52.289Z -->

## When to Use

[Display](../reference/apis-arkui/js-apis-display.md) provides APIs for managing displays, such as obtaining information about the default display, obtaining information about all displays, and listening for the addition and removal of displays. Applications may adjust their UI in response to changes in the display information, display status, and folding states.

Typical scenarios for utilizing display properties are as follows:

- Display information query: You can query the display resolution, physical pixel density, logical pixel density, refresh rate, dimensions, rotation direction, and rotation angle. For details, see [Display Properties](../reference/apis-arkui/js-apis-display.md#attributes).

- Display status monitoring: You can listen for changes in the rotation, resolution, and refresh rate of the display.

- Folding state monitoring: You can check whether the device is foldable and listen for changes in its folding state (whether it is unfolded or folded).

## Available APIs

The following table lists the common APIs related to display properties. For details, see [@ohos.display (Display)](../reference/apis-arkui/js-apis-display.md).

| API                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| getAllDisplays(): Promise<Array\<Display>>                   | Obtains all display objects. This API uses a promise to return the result.            |
| getDefaultDisplaySync(): Display                             | Obtains the default Display object.                                 |
| getDisplayByIdSync(displayId: number): Display               | Obtains a display object based on the display ID.                        |
| on(type: 'add'\|'remove'\|'change', callback: Callback\<number>): void | Subscribes to display change events.                                    |
| off(type: 'add'\|'remove'\|'change', callback?: Callback\<number>): void | Unsubscribes from display change events.                                    |
| on(type: 'captureStatusChange', callback: Callback\<boolean>): void | Subscribes to screen capture, casting, or recording status change events.                    |
| off(type: 'captureStatusChange', callback?: Callback\<boolean>): void | Unsubscribes from screen capture, casting, or recording status change events.                    |
| on(type: 'availableAreaChange', callback: Callback\<Rect>): void | Subscribes to change events of the available area on the display of the current device. This API uses an asynchronous callback to return the result.|
| off(type: 'availableAreaChange', callback?: Callback\<Rect>): void | Unsubscribes from change events of the available area on the display of the current device.                        |
| isFoldable(): boolean                                        | Checks whether the device is foldable. The value **true** means that the device is foldable, and **false** means the opposite.                         |
| on(type: 'foldStatusChange', callback: Callback\<FoldStatus>): void | Subscribes to fold status change events of the foldable device.                            |
| off(type: 'foldStatusChange', callback?: Callback\<FoldStatus>): void | Unsubscribes from fold status change events of the foldable device.                            |

## Obtaining a Display Object

The display object provides APIs to obtain display properties and listen for changes. You can use any of the following methods to obtain a display object, depending on your service requirements:

- Use **getDefaultDisplaySync()** to obtain the default display object.

- Use **getAllDisplays()** to obtain all display objects.

- Use **getDisplayByIdSync()** to obtain a display object with a specific display ID.

The following example demonstrates how to use **getDefaultDisplaySync()** to obtain the default display object:

<!-- @[get_display_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DisplayBasicSample/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();
  hilog.info(DOMAIN, 'DisplayTest', `The display info is: ${JSON.stringify(displayClass)}`);
} catch (exception) {
  hilog.error(DOMAIN, 'DisplayTest',
    `Failed to get default display. Code: ${exception.code}, message: ${exception.message}`);
}
```

## Obtaining Display Properties

1. After the display object is acquired, you can query the basic information about the display through its properties.

    <!-- @[get_display_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DisplayBasicSample/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    let displayClass: display.Display | null = null;
    try {
      displayClass = display.getDefaultDisplaySync();
      // Obtain the display ID.
      hilog.info(DOMAIN, 'DisplayTest', `The screen Id is ${displayClass.id}.`);
      // Obtain the refresh rate.
      hilog.info(DOMAIN, 'DisplayTest', `The screen is ${displayClass.refreshRate}.`);
      // Obtain the display width.
      hilog.info(DOMAIN, 'DisplayTest', `The screen width is ${displayClass.width}.`);
      // Obtain the display height.
      hilog.info(DOMAIN, 'DisplayTest', `The screen height is ${displayClass.height}.`);
      // ...
    } catch (exception) {
      hilog.error(DOMAIN, 'DisplayTest',
        `Failed to get default display. Code: ${exception.code}, message: ${exception.message}`);
    }
    ```

2. To enhance UI layout design, you can use **getCutoutInfo()** to obtain information about unusable areas of the display, including punch hole, notch, and curved area of a waterfall display. You can also use **getAvailableArea()** to obtain the available area of the display.

    <!-- @[get_cutoutInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DisplayBasicSample/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    let displayClass: display.Display | null = null;
    try {
      displayClass = display.getDefaultDisplaySync();
      displayClass.getCutoutInfo().then((cutoutInfo: display.CutoutInfo) => {
        // Process when there is cutout information.
        if (cutoutInfo.boundingRects.length > 0) {
          hilog.info(DOMAIN, 'DisplayTest', `cutoutInfo boundingRects: ${JSON.stringify(cutoutInfo.boundingRects)}`);
        } else {
          hilog.info(DOMAIN, 'DisplayTest', 'There is no cutout info on the screen.');
        }
        // Process area information on a waterfall display.
        hilog.info(DOMAIN, 'DisplayTest',
          `cutoutInfo waterfallDisplayAreaRects: ${JSON.stringify(cutoutInfo.waterfallDisplayAreaRects)}`);
      }).catch((err: BusinessError) => {
        hilog.error(DOMAIN, 'DisplayTest',
          `Failed to obtain the cutout info object. Code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      hilog.error(DOMAIN, 'DisplayTest',
        `Failed to get default display. Code: ${exception.code}, message: ${exception.message}`);
    }
    ```

3. Call **display.isCaptured()** to determine whether the device is engaged in activities such as screen capture, casting, or recording.

    <!-- @[get_display_captured](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DisplayBasicSample/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    try {
      hilog.info(DOMAIN, 'DisplayTest', `The screen is captured or not : ${display.isCaptured()}`);
    } catch (exception) {
      hilog.error(DOMAIN, 'DisplayTest',
        `Failed to get display isCaptured. Code: ${exception.code}, message: ${exception.message}`);
    }
    ```

## Listening for Display Status Changes

1. To listen for display changes, use **display.on('add'|'remove'|'change')** to subscribe to events such as the addition, removal, or alteration of displays. To unsubscribe from these events, call **display.off('add'|'remove'|'change')**.

    <!-- @[add_listen_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DisplayBasicSample/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    /**
     * The callback parameter used for subscription must be passed as an object.
     * If an anonymous function is used for registration, a new underlying object is created each time the function is called, causing memory leakage.
     */
    let callback1: Callback<number> = (displayId: number) => {
      hilog.info(DOMAIN, 'DisplayTest', `Listening enabled. displayId: ${displayId}`);
    };
    try {
      // The following uses the addition event as an example.
      display.on('add', callback1);
      hilog.info(DOMAIN, 'DisplayTest', `register add success`);
    
      // Unregister a single callback.
      display.off('add', callback1);
      hilog.info(DOMAIN, 'DisplayTest', `unregister add success`);
      // Unregister all the callbacks that have been registered through on().
      display.off('add');
      hilog.info(DOMAIN, 'DisplayTest', `unregister all add success`);
    } catch (exception) {
      hilog.error(DOMAIN, 'DisplayTest',
        `Failed to register/unregister callback. Code: ${exception.code}, message: ${exception.message}`);
    }
    ```

2. To listen for screen capture, casting, or recording status changes, call **display.on('captureStatusChange')**. To end the listening, call **display.off('captureStatusChange')**.

    <!-- @[capture_listen_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DisplayBasicSample/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    let callback2: Callback<boolean> = (captureStatus: boolean) => {
      // For captureStatus, the value true means that the device starts screen capture, casting, or recording, and false means that the device stops screen capture, casting, or recording.
      hilog.info(DOMAIN, 'DisplayTest', 'Listening capture status: ' + captureStatus);
    };
    
    try {
      // Listen for screen capture, casting, or recording status changes.
      display.on('captureStatusChange', callback2);
      hilog.info(DOMAIN, 'DisplayTest', `register captureStatusChange success`);
      // Stop listening for screen capture, casting, or recording status changes.
      display.off('captureStatusChange', callback2);
      hilog.info(DOMAIN, 'DisplayTest', `unregister captureStatusChange success`);
    } catch (exception) {
      hilog.error(DOMAIN, 'DisplayTest',
        `Failed to register/unregister callback. Code: ${exception.code}, message: ${exception.message}`);
    }
    ```

3. To listen for available area changes of the display, call **on('availableAreaChange')**. To end the listening, call **off('availableAreaChange')**.

    <!-- @[available_listen_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DisplayBasicSample/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    /**
     * The callback parameter used for subscription must be passed as an object.
     * If an anonymous function is used for registration, a new underlying object is created each time the function is called, causing memory leakage.
     */
    let callback3: Callback<display.Rect> = (data: display.Rect) => {
      hilog.info(DOMAIN, 'DisplayTest', 'Listening enabled. Data: ' + JSON.stringify(data));
    };
    let displayClass: display.Display | null = null;
    try {
      displayClass = display.getDefaultDisplaySync();
      // Listen for changes of the available area on the display.
      displayClass.on('availableAreaChange', callback3);
      hilog.info(DOMAIN, 'DisplayTest', `register availableAreaChange success`);
      // Stop listening for changes of the available area on the display.
      displayClass.off('availableAreaChange', callback3);
      hilog.info(DOMAIN, 'DisplayTest', `unregister availableAreaChange success`);
    } catch (exception) {
      hilog.error(DOMAIN, 'DisplayTest',
        `Failed to register/unregister callback. Code: ${exception.code}, message: ${exception.message}`);
    }
    ```

## Listening for Folding State Changes

1. Call **display.isFoldable()** to check whether the device is foldable.

    <!-- @[get_fold_device](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DisplayBasicSample/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    let isFoldableDevice: boolean = false;
    try {
      isFoldableDevice = display.isFoldable();
      // Print whether the device is foldable.
      hilog.info(DOMAIN, 'DisplayTest', `This device is foldable: ${isFoldableDevice}`);
    } catch (exception) {
      hilog.error(DOMAIN, 'DisplayTest',
        `Failed to get foldable message. Code: ${exception.code}, message: ${exception.message}`);
    }
    ```

2. If the device is a foldable device, call **display.on('foldStatusChange')** to listen for folding state changes. To end the listening, call **display.off('foldStatusChange')**.

    <!-- @[fold_device_listen](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DisplayBasicSample/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    /**
     * The callback parameter used for subscription must be passed as an object.
     * If an anonymous function is used for registration, a new underlying object is created each time the function is called, causing memory leakage.
     */
    let callback: Callback<display.FoldStatus> = (data: display.FoldStatus) => {
      hilog.info(DOMAIN, 'DisplayTest', 'Listening enabled. Data: ' + JSON.stringify(data));
    };
    try {
      display.on('foldStatusChange', callback);
      // Unregister all the callbacks that have been registered through on().
      hilog.info(DOMAIN, 'DisplayTest', `register foldStatusChange success`);
    
      // Unregister a single callback.
      display.off('foldStatusChange', callback);
      hilog.info(DOMAIN, 'DisplayTest', `unregister all foldStatusChange success`);
      // Unregister all the callbacks.
      display.off('foldStatusChange');
      hilog.info(DOMAIN, 'DisplayTest', `unregister foldStatusChange success`);
    } catch (exception) {
      hilog.error(DOMAIN, 'DisplayTest',
        `Failed to register/unregister callback. Code: ${exception.code}, message: ${exception.message}`);
    }
    ```
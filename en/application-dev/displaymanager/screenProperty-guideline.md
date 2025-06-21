# Using Display to Obtain Display Properties and Listen for Status Changes (ArkTS)

## When to Use

[Display](../reference/apis-arkui/js-apis-display.md) provides APIs for managing displays, such as obtaining information about the default display, obtaining information about all displays, and listening for the addition and removal of displays. Applications may adjust their UI in response to changes in the display information, display status, and folding states.

Typical scenarios for utilizing display properties are as follows:

- Display information query: You can query the display resolution, physical pixel density, logical pixel density, refresh rate, dimensions, rotation direction, and rotation angle. For details, see [Display Properties](../reference/apis-arkui/js-apis-display.md#properties).
- Display status monitoring: You can listen for changes in the rotation, resolution, and refresh rate of the display.
- Folding state monitoring: You can check whether the device is foldable and listen for changes in its folding state (whether it is unfolded or folded).

## Available APIs

The following table lists the common APIs related to display properties. For details, see [@ohos.display (Display)](../reference/apis-arkui/js-apis-display.md).

| API                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| getAllDisplays(): Promise<Array\<Display>>                   | Obtains all display objects. This API uses a promise to return the result.            |
| getDefaultDisplaySync(): Display                             | Obtains the default display object. This API uses an asynchronous callback to return the result.                                 |
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

```ts
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;
displayClass = display.getDefaultDisplaySync();
// Ensure that the display object, displayClass in this example, is obtained before the operations of querying the display properties and listening for events and status changes.
```

## Obtaining Display Properties

1. After the display object is acquired, you can query the basic information about the display through its properties.

   ```ts
   import { display } from '@kit.ArkUI';
   
   let displayClass: display.Display | null = null;
   displayClass = display.getDefaultDisplaySync();
   
   // Obtain the display ID.
   console.info(`The screen Id is ${displayClass.id}.`);
   // Obtain the refresh rate.
   console.info(`The screen is ${displayClass.refreshRate}.`);
   // Obtain the display width.
   console.info(`The screen width is ${displayClass.width}.`);
   // Obtain the display height.
   console.info(`The screen height is ${displayClass.height}.`);
   // ...
   ```

2. To enhance UI layout design, you can use **getCutoutInfo()** to obtain information about unusable areas of the display, including punch hole, notch, and curved area of a waterfall display. You can also use **getAvailableArea()** to obtain the available area of the display.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   
   displayClass.getCutoutInfo().then((cutoutInfo: display.CutoutInfo) => {
     console.info('Succeeded in getting cutoutInfo. Data: ' + JSON.stringify(cutoutInfo));
   }).catch((err: BusinessError) => {
     console.error(`Failed to obtain all the display objects. Code: ${err.code}, message: ${err.message}`);
   });
   
   displayClass.getAvailableArea().then((availableArea) => {
     console.info('Succeeded get the available area in this display. data: ' + JSON.stringify(availableArea));
   }).catch((err: BusinessError) => {
     console.error(`Failed to get the available area in this display. Code: ${err.code}, message: ${err.message}`);
   });
   ```

3. Call **display.isCaptured()** to determine whether the device is engaged in activities such as screen capture, casting, or recording.

   ```ts
   console.info(`The screen is captured or not : ${display.isCaptured()}`);
   ```

## Listening for Display Status Changes

1. To listen for display changes, use **display.on('add'|'remove'|'change')** to subscribe to events such as the addition, removal, or alteration of displays. To unsubscribe from these events, call **display.off('add'|'remove'|'change')**.

   ```ts
   import { display } from '@kit.ArkUI';
   import { Callback } from '@kit.BasicServicesKit';
   
   let callback1: Callback<number> = (data: number) => {
     console.info('Listening enabled. Data: ' + JSON.stringify(data));
   };
   // The following uses the addition event as an example.
   display.on("add", callback1);
   
   // Unregister all the callbacks that have been registered through on().
   display.off("add");
   // Unregister a single callback.
   display.off('add', callback1);
   ```

2. To listen for screen capture, casting, or recording status changes, call **display.on('captureStatusChange')**. To end the listening, call **display.off('captureStatusChange')**.

   ```ts
   let callback2: Callback<boolean> = (captureStatus: boolean) => {
       // For captureStatus, the value true means that the device starts screen capture, casting, or recording, and false means that the device stops screen capture, casting, or recording.
     console.info('Listening capture status: ' + captureStatus);
   };
   // Listen for screen capture, casting, or recording status changes.
   display.on('captureStatusChange', callback2);
   
   display.off('captureStatusChange', callback2);
   ```

3. To listen for available area changes of the display, call **on('availableAreaChange')**. To end the listening, call **off('availableAreaChange')**.

   ```ts
   import { Callback } from '@kit.BasicServicesKit';
   import { display } from '@kit.ArkUI';
   
   let callback3: Callback<display.Rect> = (data: display.Rect) => {
     console.info('Listening enabled. Data: ' + JSON.stringify(data));
   };
   let displayClass: display.Display | null = null;
   try {
     displayClass = display.getDefaultDisplaySync();
     // Listen for changes of the available area on the display.
     displayClass.on("availableAreaChange", callback3);
   } catch (exception) {
     console.error(`Failed to register callback. Code: ${exception.code}, message: ${exception.message}`);
   }
   // End the listening.
   displayClass.off("availableAreaChange", callback3);
   ```

## Listening for Folding State Changes

1. Call **display.isFoldable()** to check whether the device is foldable.

   ```
   import { display } from '@kit.ArkUI';
   
   let ret: boolean = false;
   ret = display.isFoldable();
   ```

2. If the device is a foldable device, call **display.on('foldStatusChange')** to listen for folding state changes. To end the listening, call **display.off('foldStatusChange')**.

   ```ts
   import { Callback } from '@kit.BasicServicesKit';
   
   /**
    * The callback parameter used for subscription must be passed as an object.
    * If an anonymous function is used for registration, a new underlying object is created each time the function is called, causing memory leakage.
   */
   let callback: Callback<display.FoldStatus> = (data: display.FoldStatus) => {
     console.info('Listening enabled. Data: ' + JSON.stringify(data));
   };
   display.on('foldStatusChange', callback);
   
   // Unregister all the callbacks that have been registered through on().
   display.off('foldStatusChange');
   // Unregister a single callback.
   display.off('foldStatusChange', callback);
   ```

# Mouse Pointer Development

## When to Use

Mouse pointer management provides the functions such as displaying or hiding the mouse pointer as well as querying and setting the pointer style. For example, you can determine whether to display or hide the mouse pointer when a user watches a video in full screen, and can switch the mouse pointer to a color picker when a user attempts color pickup.

## Modules to Import

```js
import inputDevice from '@ohos.multimodalInput.pointer';
```

## Available APIs

The following table lists the common APIs for mouse pointer management. For details about the APIs, see [ohos.multimodalInput.pointer](../reference/apis/js-apis-pointer.md).

| Instance | API                                                      | Description                                                        |
| ------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| pointer | function isPointerVisible(callback: AsyncCallback\<boolean>): void; | Checks the visible status of the mouse pointer.                                |
| pointer | function setPointerVisible(visible: boolean, callback: AsyncCallback\<void>): void; | Sets the visible status of the mouse pointer. This setting takes effect for the mouse pointer globally.|
| pointer | function setPointerStyle(windowId: number, pointerStyle: PointerStyle, callback: AsyncCallback\<void>): void; | Sets the mouse pointer style. This setting takes effect for the mouse pointer style of a specified window.        |
| pointer | function getPointerStyle(windowId: number, callback: AsyncCallback\<PointerStyle>): void; | Obtains the mouse pointer style.                                          |

## Hiding the Mouse Pointer

When watching a video in full-screen mode, a user can hide the mouse pointer for an improved user experience.

## How to Develop

1. Switch to the full-screen playback mode.
2. Hide the mouse pointer.
3. Exit the full-screen playback mode.
4. Display the mouse pointer.

```js
import pointer from '@ohos.multimodalInput.pointer';

// 1. Switch to the full-screen playback mode.
// 2. Hide the mouse pointer.
try {
  pointer.setPointerVisible(false, (error) => {
    if (error) {
      console.log(`Set pointer visible failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Set pointer visible success.`);
  });
} catch (error) {
  console.log(`The mouse pointer hide attributes is failed. ${JSON.stringify(error, [`code`, `message`])}`);
}

// 3. Exit the full-screen playback mode.
// 4. Display the mouse pointer.
try {
  pointer.setPointerVisible(true, (error) => {
    if (error) {
      console.log(`Set pointer visible failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Set pointer visible success.`);
  });
} catch (error) {
  console.log(`Set pointer visible failed, ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## Setting the Mouse Pointer Style

When designing a color picker, you can have the mouse pointer switched to the color picker style during color pickup and then switched to the default style on completion of color pickup. This setting takes effect for the pointer style of a specified window in the current application. A total of 39 pointer styles can be set. For details, see [Pointer Style](../reference/apis/js-apis-pointer.md#pointerstyle9).

### How to Develop

1. Enable the color pickup function.
2. Obtain the window ID.
3. Set the mouse pointer to the color picker style.
4. End color pickup.
5. Set the mouse pointer to the default style.

```js
import window from '@ohos.window';

// 1. Enable the color pickup function.
// 2. Obtain the window ID.
window.getTopWindow((error, windowClass) => {
  windowClass.getProperties((error, data) => {
    var windowId = data.id;
    if (windowId < 0) {
      console.log(`Invalid windowId`);
      return;
    }
    try {
      // 3. Set the mouse pointer to the color picker style.
      pointer.setPointerStyle(windowId, pointer.PointerStyle.COLOR_SUCKER).then(() => {
        console.log(`Successfully set mouse pointer style`);
      });
    } catch (error) {
      console.log(`Failed to set the pointer style, error=${JSON.stringify(error)}, msg=${JSON.stringify(message)}`);
    }
  });
});
// 4. End color pickup.
window.getTopWindow((error, windowClass) => {
  windowClass.getProperties((error, data) => {
    var windowId = data.id;
    if (windowId < 0) {
      console.log(`Invalid windowId`);
      return;
    }
    try {
      // 5. Set the mouse pointer to the default style.
      pointer.setPointerStyle(windowId, pointer.PointerStyle.DEFAULT).then(() => {
        console.log(`Successfully set mouse pointer style`);
      });
    } catch (error) {
      console.log(`Failed to set the pointer style, error=${JSON.stringify(error)}, msg=${JSON.stringify(message)}`);
    }
  });
});
```

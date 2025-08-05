# Preset Global Hotkey Development

## When to Use

You can use the preset global hotkeys to set the delay time for starting an ability. An example is to take a screenshot 5 seconds after the hotkey is pressed.

## Modules to Import

```js
import { shortKey } from '@kit.InputKit';
```

## Available APIs

The following table lists the common APIs provided by the **shortKey** module. For details, see [ohos.multimodalInput.shortKey](../../reference/apis-input-kit/js-apis-shortKey-sys.md).

| API | Description|
| ------------------------------------------------------------ | -------------------------- |
| setKeyDownDuration(businessKey: string, delay: number, callback: AsyncCallback&lt;void&gt;): void |Sets the delay for starting an ability using the hotkey.|

## How to Develop

The following describes how to take a screenshot five seconds after the hotkey is pressed.

```js
import { shortKey } from '@kit.InputKit';

try {
  shortKey.setKeyDownDuration("screenshot", 500, (error) => {// Set the delay to 5 seconds (500 ms)
    if (error) {
      console.error(`Set key down duration failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.info(`Set key down duration success`);
  });
} catch (error) {
  console.error(`Set key down duration failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

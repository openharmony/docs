# Screen Rotation Animation Enhancement

You can add fade-in and fade-out transition effects to a screen rotation animation, to create a seamless transition experience.

Below is the complete sample code and effect.

```ts
// xx.ets
import { display } from '@kit.ArkUI';

@Entry
@Component
struct rotation {
  @StorageLink('orientation') myOrientation: display.Orientation = display.Orientation.PORTRAIT;

  build() {
    Stack() {
      if (this.myOrientation == display.Orientation.PORTRAIT || this.myOrientation == display.Orientation.PORTRAIT_INVERTED) {
        Image($r('app.media.sky'))
          .size({ width: 100, height: 100 })
          .id('image1')
      } else {
        Image($r('app.media.tree'))
          .position({ x: 0, y: 0 })
          .size({ width: 200, height: 200 })
          .id('image2')
      }
    }
    .backgroundColor(Color.White)
    .size({ width: '100%', height: '100%' })
  }
}
```

In the **EntryAbility.ets** file, add processing logic to the **onWindowStageCreate** method to obtain the screen display orientation.
```ts
onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    let mainWindow: window.Window;
    try {
      mainWindow = windowStage.getMainWindowSync();
      let displayClass: display.Display = display.getDefaultDisplaySync();
      AppStorage.setOrCreate('orientation', displayClass.orientation);
      // Listen for the windowsSizeChange event, which is triggered when the screen is rotated.
      mainWindow.on('windowSizeChange', (data) => {
        console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data));
        let displayClass: display.Display | null = null;
        try {
          displayClass = display.getDefaultDisplaySync();
          console.info('display orientation is ' + JSON.stringify(displayClass.orientation));
          // Obtain the screen display orientation.
          AppStorage.set('orientation', displayClass.orientation);
        } catch {
          return;
        }
      })
    } catch {
      hilog.info(0x0000, 'testTag', '%{public}s', 'error');
      return;
    }

    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content.');
    });
}
```

In the **module.json5** file of the project, add **orientation** to the **abilities** list and set the ability to **auto_rotation**.
```json
"orientation": "auto_rotation",
```

![rotation-opacity](figures/rotation-opacity.gif)

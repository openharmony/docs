# 旋转屏动画增强

在原旋转屏动画基础上，可配置渐隐和渐现的转场效果。

完整的代码示例和效果如下。

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

需要在EntryAbility.ets文件的onWindowStageCreate方法中添加处理逻辑以获取屏幕的显示方向
```ts
onWindowStageCreate(windowStage: window.WindowStage): void {

    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    let mainWindow: window.Window;
    try {
      mainWindow = windowStage.getMainWindowSync();
      let displayClass: display.Display = display.getDefaultDisplaySync();
      AppStorage.setOrCreate('orientation', displayClass.orientation);
      // 监听窗口的windowsSizeChange事件，旋转屏时会触发该事件
      mainWindow.on('windowSizeChange', (data) => {
        console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data));
        let displayClass: display.Display | null = null;
        try {
          displayClass = display.getDefaultDisplaySync();
          console.info('display orientation is ' + JSON.stringify(displayClass.orientation));
          // 获取屏幕的显示方向
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

需要在项目的 module.json5 文件中的 abilities 列表里添加 "orientation"，指定为 "auto_rotation"
```json
"orientation": "auto_rotation",
```

![rotation-opacity](figures/rotation-opacity.gif)
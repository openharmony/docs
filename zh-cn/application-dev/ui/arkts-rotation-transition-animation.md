# 旋转屏动画
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @CCFFWW-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

旋转屏动画主要分为两类：[布局切换的旋转屏动画](#布局切换的旋转屏动画)和[透明度变化的旋转屏动画](#透明度变化的旋转屏动画)，旨在实现屏幕显示方向变化时的自然过渡。布局切换的旋转屏动画实现较为简便，例如在module.json5中配置自动旋转（或设置窗口显示方向）即可实现。而透明度变化的旋转屏动画则需在module.json5配置的基础上，预备两套视图，在屏幕旋转时，通过视图切换，使消失的视图呈现渐隐效果，新出现的视图则渐显，从而营造流畅的视觉体验。

## 布局切换的旋转屏动画

布局切换时的旋转屏动画，是在屏幕显示方向改变时，为窗口与应用视图同步旋转而设计的大小和位置过渡动画。这种布局切换的旋转屏动画是系统默认的，便于开发者实现。当屏幕显示方向变化时，系统会生成窗口旋转动画，并自动调整窗口大小以匹配旋转后的尺寸。在此过程中，窗口会通知对应的应用，要求其根据新的窗口大小重新布局，产生与窗口旋转动画参数相同的布局动画。

切换屏幕方向即可实现布局切换的旋转屏动画效果。

```ts
// xx.ets
@Entry
@Component
struct rotation {

  build() {
    Stack() {
      Image($r('app.media.tree'))
        .position({ x: 0, y: 0 })
        .size({ width: 100, height: 100 })
        .id('image1')
    }
    .backgroundColor(Color.White)
    .size({ width: '100%', height: '100%' })
  }
}
```

需要在项目的module.json5文件中的abilities列表里添加"orientation"，指定为"auto_rotation"。
```json
"orientation": "auto_rotation",
```

布局切换的旋转屏动画，会对同步旋转的窗口与应用视图做大小和位置的过渡。

![Alt text](figures/rotation.gif)

## 透明度变化的旋转屏动画

透明度变化的旋转屏动画在屏幕显示方向变化时启用，当窗口进行旋转动画时，为旋转过程中新增或删除的组件添加默认透明度转场，以实现组件的优雅出现和消失。此功能通过监听窗口旋转事件，在事件中切换组件的视图效果，如果消失视图的根节点和新出现视图的根节点未设置转场效果，会为其自动添加默认透明度转场（即[TransitionEffect](../reference/apis-arkui/arkui-ts/ts-transition-animation-component.md#transitioneffect10对象说明).OPACITY），展现出透明度的渐隐和渐显效果。

```ts
// xx.ets
import { display } from '@kit.ArkUI';

@Entry
@Component
struct rotation {

  // 获取通过监听窗口的windowsSizeChange事件得到的屏幕显示方向
  @StorageLink('orientation') myOrientation: display.Orientation = display.Orientation.PORTRAIT;

  build() {
    Stack() {

      // 当屏幕显示方向变化时，切换组件的视图效果
      if (this.myOrientation == display.Orientation.PORTRAIT || this.myOrientation == display.Orientation.PORTRAIT_INVERTED) {
        Image($r('app.media.sky'))
          .size({ width: 100, height: 100 })
          .id('image1')

          // 开发者也可以通过自行设置transition的TransitionEffect.OPACITY转场效果来实现旋转屏动画的透明度变化
          // .transition(TransitionEffect.OPACITY)
      } else {
        Image($r('app.media.tree'))
          .position({ x: 0, y: 0 })
          .size({ width: 200, height: 200 })
          .id('image2')
          
          // 开发者也可以通过自行设置transition的TransitionEffect.OPACITY来实现旋转屏动画的透明度变化
          // .transition(TransitionEffect.OPACITY)
      }
    }
    .backgroundColor(Color.White)
    .size({ width: '100%', height: '100%' })
  }
}
```

监听窗口旋转的同步事件windowsSizeChange来实现视图的切换。例如可在EntryAbility.ets文件的onWindowStageCreate方法中添加处理逻辑以获取屏幕的显示方向。
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
      hilog.error(0x0000, 'testTag', '%{public}s', 'error');
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

需要在项目的 module.json5 文件中的 abilities 列表里添加 "orientation"，指定为 "auto_rotation"。
```json
"orientation": "auto_rotation",
```

透明度变化的旋转屏动画，会对窗口做大小和位置的过渡，并同时对应用视图做切换过渡，且为消失隐藏的应用视图做渐隐效果，对新出现的视图做渐显的效果。

![rotation-opacity](figures/rotation-opacity.gif)
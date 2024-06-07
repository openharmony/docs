# 请求UI绘制帧率

如果开发者需要以独立的帧率绘制更新操作UI界面时，可以通过DisplaySync来实现。应用中绘制内容的帧率可以使用DisplaySync实例来控制，具体请查阅[@ohos.graphics.displaySync(可变帧率)](../reference/apis-arkgraphics2d/js-apis-graphics-displaySync.md)。

## 开发步骤

此处以不同帧率改变文件组件字体大小为例，来模拟不同UI绘制帧率的效果。

1. 导入模块。

   ```ts
   import { displaySync } from '@kit.ArkGraphics2D';
   ```

2. 定义和构建DisplaySync对象。

   ```ts
   @Entry
   @Component
   struct Index {
     // 定义两个DisplaySync变量，未初始化
     private backDisplaySyncSlow: displaySync.DisplaySync | undefined = undefined;
     private backDisplaySyncFast: displaySync.DisplaySync | undefined = undefined;
   }
   ```

3. 定义两个文本组件。

   ```ts
   @State drawFirstSize: number = 25;
   @State drawSecondSize: number = 25;
   @Builder doSomeRenderFirst() {
    Text('30')
      .fontSize(this.drawFirstSize)
   }
   
   @Builder doSomeRenderSecond() {
    Text('60')
      .fontSize(this.drawSecondSize)
   }
   ```

4. 通过DisplaySync实例设置帧率和注册订阅函数。

   > **说明：**
   >
   > 订阅函数运行于UI主线程，故涉及UI线程的耗时操作不应运行于订阅函数中，以免影响性能。

   ```ts
   CreateDisplaySyncSlow() {
       let range : ExpectedFrameRateRange = { // 创建和配置帧率参数
         expected: 30, // 设置期望绘制帧率为30hz
         min: 0, // 配置帧率范围
         max: 120 // 配置帧率范围
       };
   
       let draw30 = (intervalInfo: displaySync.IntervalInfo) => { // 订阅回调函数，字体大小在25到150之间变化
         if (this.isBigger_30) {
           this.drawFirstSize += 1;
           if (this.drawFirstSize > 150) {
             this.isBigger_30 = false;
           }
         } else {
           this.drawFirstSize -= 1;
           if (this.drawFirstSize < 25) {
             this.isBigger_30 = true;
           }
         }
       };
   
       this.backDisplaySyncSlow = displaySync.create(); // 创建DisplaySync实例
       this.backDisplaySyncSlow.setExpectedFrameRateRange(range); // 设置帧率
       this.backDisplaySyncSlow.on("frame", draw30); // 订阅frame事件和注册订阅函数
   }
   ```

5. 开始每帧回调。

   ```ts
   Button('Start')
     .id('CustomDrawStart')
     .fontSize(14)
     .fontWeight(500)
     .margin({ bottom: 10, left: 5 })
     .fontColor(Color.White)
     .onClick((): void => {
         if (this.backDisplaySyncSlow == undefined) {
           this.CreateDisplaySyncSlow();
         }
         if (this.backDisplaySyncFast == undefined) {
           this.CreateDisplaySyncFast();
         }
         if (this.backDisplaySyncSlow) {
           this.backDisplaySyncSlow.start();
         }
         if (this.backDisplaySyncFast) {
           this.backDisplaySyncFast.start();
         }
       })
       .width('20%')
       .height(40)
       .shadow(ShadowStyle.OUTER_DEFAULT_LG)
   ```

   > **说明：**
   >
   > 创建的DisplaySync实例在start使能后需要aboutToDisappear函数中进行stop操作并置空，避免内存泄漏问题。
   ```ts
   aboutToDisappear() {
     if (this.backDisplaySyncSlow) {
       this.backDisplaySyncSlow.stop();
       this.backDisplaySyncSlow = undefined;
     }
     if (this.backDisplaySyncFast) {
       this.backDisplaySyncFast.stop();
       this.backDisplaySyncFast = undefined;
     }
   }
   ```

6. 结束每帧回调。

   ```ts
   Button('Stop')
     .id('CustomDrawStop')
     .fontSize(14)
     .fontWeight(500)
     .margin({ bottom: 10, left: 5 })
     .fontColor(Color.White)
     .onClick((): void => {
       if (this.backDisplaySyncSlow) {
           this.backDisplaySyncSlow.stop();
       }
       if (this.backDisplaySyncFast) {
           this.backDisplaySyncFast.stop();
       }
     })
     .width('20%')
     .height(40)
     .shadow(ShadowStyle.OUTER_DEFAULT_LG)
   ```

## 完整示例
```ts
import { displaySync } from '@kit.ArkGraphics2D';

@Entry
@Component
struct Index {
  @State drawFirstSize: number = 25;
  @State drawSecondSize: number = 25;
  private backDisplaySyncSlow: displaySync.DisplaySync | undefined = undefined;
  private backDisplaySyncFast: displaySync.DisplaySync | undefined = undefined;
  private isBigger_30:boolean = true;
  private isBigger_60:boolean = true;

  @Builder doSomeRenderFirst() {
    Text('30')
      .fontSize(this.drawFirstSize)
  }

  @Builder doSomeRenderSecond() {
    Text('60')
      .fontSize(this.drawSecondSize)
  }

  CreateDisplaySyncSlow() {
    // 定义期望绘制帧率
    let range : ExpectedFrameRateRange = {
      expected: 30,
      min: 0,
      max: 120
    };

    let draw30 = (intervalInfo: displaySync.IntervalInfo) => {
      if (this.isBigger_30) {
        this.drawFirstSize += 1;
        if (this.drawFirstSize > 150) {
          this.isBigger_30 = false;
        }
      } else {
        this.drawFirstSize -= 1;
        if (this.drawFirstSize < 25) {
          this.isBigger_30 = true;
        }
      }
    };

    this.backDisplaySyncSlow = displaySync.create(); // 创建DisplaySync实例
    this.backDisplaySyncSlow.setExpectedFrameRateRange(range); // 设置帧率
    this.backDisplaySyncSlow.on("frame", draw30); // 订阅frame事件和注册订阅函数
  }

  CreateDisplaySyncFast() {
    // 定义期望绘制帧率
    let range : ExpectedFrameRateRange = {
      expected: 60,
      min: 0,
      max: 120
    };

    let draw60 = (intervalInfo: displaySync.IntervalInfo) => {
      if (this.isBigger_60) {
        this.drawSecondSize += 1;
        if (this.drawSecondSize > 150) {
          this.isBigger_60 = false;
        }
      } else {
        this.drawSecondSize -= 1;
        if (this.drawSecondSize < 25) {
          this.isBigger_60 = true;
        }
      }

    };

    this.backDisplaySyncFast= displaySync.create(); // 创建DisplaySync实例
    this.backDisplaySyncFast.setExpectedFrameRateRange(range); // 设置帧率
    this.backDisplaySyncFast.on("frame", draw60); // 订阅frame事件和注册订阅函数
  }

  aboutToDisappear() {
    if (this.backDisplaySyncSlow) {
      this.backDisplaySyncSlow.stop(); // DisplaySync失能关闭
      this.backDisplaySyncSlow = undefined; // 实例置空
    }
    if (this.backDisplaySyncFast) {
      this.backDisplaySyncFast.stop(); // DisplaySync失能关闭
      this.backDisplaySyncFast = undefined; // 实例置空
    }
  }

  build() {
    Column() {
      Row() {
        this.doSomeRenderFirst();
      }
      .height('40%')

      Row() {
        this.doSomeRenderSecond();
      }
      .height('40%')

      Row() {
        Button('Start')
          .id('CustomDrawStart')
          .fontSize(14)
          .fontWeight(500)
          .margin({ bottom: 10, left: 5 })
          .fontColor(Color.White)
          .onClick((): void => {
            if (this.backDisplaySyncSlow == undefined) {
              this.CreateDisplaySyncSlow();
            }
            if (this.backDisplaySyncFast == undefined) {
              this.CreateDisplaySyncFast();
            }
            if (this.backDisplaySyncSlow) {
              this.backDisplaySyncSlow.start(); // DisplaySync使能开启
            }
            if (this.backDisplaySyncFast) {
              this.backDisplaySyncFast.start(); // DisplaySync使能开启
            }
          })
          .width('20%')
          .height(40)
          .shadow(ShadowStyle.OUTER_DEFAULT_LG)

        Button('Stop')
          .id('CustomDrawStop')
          .fontSize(14)
          .fontWeight(500)
          .margin({ bottom: 10, left: 5 })
          .fontColor(Color.White)
          .onClick((): void => {
            if (this.backDisplaySyncSlow) {
              this.backDisplaySyncSlow.stop(); // DisplaySync失能关闭
            }
            if (this.backDisplaySyncFast) {
              this.backDisplaySyncFast.stop(); // DisplaySync失能关闭
            }
          })
          .width('20%')
          .height(40)
          .shadow(ShadowStyle.OUTER_DEFAULT_LG)
      }
      .width('100%')
      .justifyContent(FlexAlign.Center)
      .shadow(ShadowStyle.OUTER_DEFAULT_SM)
      .alignItems(VerticalAlign.Bottom)
      .layoutWeight(1)
    }
  }
}
```

## 相关实例

针对可变帧率的开发，有以下相关实例可供参考：

- [DisplaySync分级管控(ArkTS)(API11)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Graphics/DisplaySync)
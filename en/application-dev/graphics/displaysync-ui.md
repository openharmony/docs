# Requesting Frame Rates for UI Components

If you want to draw and update a UI component at an independent frame rate, you can call the APIs provided by the DisplaySync module. For details, see [@ohos.graphics.displaySync (Variable Frame Rate)](../reference/apis-arkgraphics2d/js-apis-graphics-displaySync.md).

## How to Develop

This section describes how to use different frame rates to change the font size of the **Text** component. This operation simulates the effect of different frame rates on the UI components.

1. Import the DisplaySync module.

   ```ts
   import { displaySync } from '@kit.ArkGraphics2D';
   ```

2. Define and create a **DisplaySync** instance.

   ```ts
   @Entry
   @Component
   struct Index {
     // Define two DisplaySync variables, which are not initialized.
     private backDisplaySyncSlow: displaySync.DisplaySync | undefined = undefined;
     private backDisplaySyncFast: displaySync.DisplaySync | undefined = undefined;
   }
   ```

3. Define two **Text** components.

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

4. Set the expected frame rate range and register a subscription function through the **DisplaySync** instance.

   > **NOTE**
   >
   > The subscription function runs in the UI main thread. To avoid adverse impact on the performance, time-consuming operations related to the UI thread should not run in the subscription function.

   ```ts
   CreateDisplaySyncSlow() {
       let range:ExpectedFrameRateRange = { // Create and configure the frame rate parameter.
         expected: 30, // Set the expected frame rate to 30 Hz.
         min: 0, // Set the frame rate range.
         max: 120 // Set the frame rate range.
       };
   
       let draw30 = (intervalInfo: displaySync.IntervalInfo) => { // Subscription function. The font size changes from 25 to 150.
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
   
       this.backDisplaySyncSlow = displaySync.create (); // Create a DisplaySync instance.
       this.backDisplaySyncSlow.setExpectedFrameRateRange(range); // Set the frame rate range.
       this.backDisplaySyncSlow.on("frame", draw30); // Subscribe to the frame event and register the subscription function.
   }
   ```

5. Start callback for each frame.

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

   > **NOTE**
   >
   > After **start()** is called, the **stop()** API must be performed and the **DisplaySync** instance must be set to null in the **aboutToDisappear** function to avoid memory leakage.
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

6. Stop callback for each frame.

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

## Sample Code
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
    // Define the expected frame rate range.
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

    this.backDisplaySyncSlow = displaySync.create (); // Create a DisplaySync instance.
    this.backDisplaySyncSlow.setExpectedFrameRateRange(range); // Set the frame rate range.
    this.backDisplaySyncSlow.on("frame", draw30); // Subscribe to the frame event and register the subscription function.
  }

  CreateDisplaySyncFast() {
    // Define the expected frame rate range.
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

    this.backDisplaySyncFast= displaySync.create(); // Create a DisplaySync instance.
    this.backDisplaySyncFast.setExpectedFrameRateRange(range); // Set the frame rate.
    this.backDisplaySyncFast.on("frame", draw60); // Subscribe to the frame event and register the subscription function.
  }

  aboutToDisappear() {
    if (this.backDisplaySyncSlow) {
      this.backDisplaySyncSlow.stop (); // DisplaySync disabled.
      this.backDisplaySyncSlow = undefined; // Set the DisplaySync instance to null.
    }
    if (this.backDisplaySyncFast) {
      this.backDisplaySyncFast.stop(); // DisplaySync disabled.
      this.backDisplaySyncFast = undefined; // Set the DisplaySync instance to null.
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
              this.backDisplaySyncSlow.start (); // DisplaySync enabled.
            }
            if (this.backDisplaySyncFast) {
              this.backDisplaySyncFast.start(); // DisplaySync enabled.
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
              this.backDisplaySyncSlow.stop (); // DisplaySync disabled.
            }
            if (this.backDisplaySyncFast) {
              this.backDisplaySyncFast.stop(); // DisplaySync disabled.
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

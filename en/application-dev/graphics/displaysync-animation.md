# Requesting Frame Rates for Animations

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @wh_qwe-->
<!--Designer: @wh_qwe-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=8274e2d7a391483e6c7c9de842768baf61c0596c translatedAt=2026-08-03T11:18:22.232Z pushedAt=2026-08-04T03:51:26.214Z -->

During application development, you can use the optional parameter [ExpectedFrameRateRange](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md#expectedframeraterange11) to set an expected frame rate range for a [property animation](../reference/apis-arkui/arkui-ts/ts-animatorproperty.md) or an [explicit animation](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md).

## Requesting a Frame Rate for a Property Animation

The code snippet below defines a property animation for the **Text** component and sets the frame rate to 60.

<!-- @[display_sync_property_animation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/ets/DisplaySync/PropertyAnimationDisplaySync.ets) -->

``` TypeScript
Text('60')
  // ...
  .animation({
    duration: 1200,
    iterations: 10,
    // ...
    expectedFrameRateRange: {
      expected: 60,
      min: 0,
      max: 120,
    },
  })
```

## Requesting a Frame Rate for an Explicit Animation

The code snippet below defines an explicit animation for the **Button** component and sets the frame rate to 30.

<!-- @[display_sync_explicit_animation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/ets/DisplaySync/PropertyAnimationDisplaySync.ets) -->

``` TypeScript
Button('Start')
  // ...
  .onClick(() => {
    // ...

    this.uiContext?.animateTo({
      duration: 1200,
      iterations: 10,
      // ...
      expectedFrameRateRange: {
        expected: 30,
        min: 0,
        max: 120,
      },
    }, () => {
      // ...
    })

    // ...
  })
```

<!--RP1-->

## Samples

- [DisplaySync (API14)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics2D/DisplaySync)

<!--RP1End-->
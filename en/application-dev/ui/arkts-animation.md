# Animation Overview

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=03e7ebde175519478419394081c9ffa3eece48e0 translatedAt=2026-07-29T12:41:45.300Z pushedAt=2026-07-30T01:12:26.917Z -->

The user interface (UI) is the interface through which users interact with devices, consisting of various visual components (such as buttons and lists). Attributes serve as interfaces for controlling component behavior, and changes in attribute values cause UI changes. Animations can add smooth transition effects when the UI changes, allowing attribute values to gradually change from the initial state to the final state, thereby avoiding the abruptness caused by instantaneous changes and maintaining the user's visual focus.

![en-us_image_20230822](figures/Animation-what.gif)

The purposes of animation include:

- Making interface transitions natural and smooth.

- Enhancing the sense of feedback and interactivity that users perceive from the interface.

- Increasing user patience during content loading and similar scenarios, alleviating the discomfort caused by waiting.

- Guiding users to understand and operate the device.

Animations can be used in any scenario where transitions need to be added to UI changes, such as device startup, app startup and exit, and pulling down to access the control center. These animations provide users with feedback on their actions and help keep their attention on the interface.

ArkUI provides a variety of animation interfaces (such as [attribute animation](arkts-attribute-animation-overview.md) and [transition animation](arkts-transition-overview.md)) for driving attribute values to gradually change from their initial values to final values according to the configured animation parameters. Although the parameter values are not absolutely continuous during the change process but rather discrete to some extent, the human eye experiences persistence of vision, so what is ultimately perceived is a "continuous" animation. Each UI change is referred to as an animation frame, which corresponds to one screen refresh. A key metric for determining animation smoothness is the frame rate (FPS), which is the number of animation frames per second — the higher the frame rate, the smoother the animation. In ArkUI, animation parameters include settings such as animation duration and [animation curve](arkts-traditional-curve.md). The animation curve, as a primary factor, determines how attribute values change over time. Taking a linear animation curve as an example, the attribute value changes from the start value to the end value at a constant speed over the animation duration. Changes that are too fast or too slow can result in a poor visual experience and negatively affect user experience. Therefore, animation parameters — especially the animation curve — must be designed and adjusted based on the specific scenario and curve characteristics.

Animation interfaces drive attribute values to transition continuously from the original state to a new state according to the rules determined by animation parameters, thereby producing a continuous visual effect on the UI. This document is organized as follows to provide usage methods and considerations for various animations, helping developers quickly learn animation.

- [Attribute Animation](arkts-attribute-animation-overview.md): The most fundamental animation type, which drives attribute changes frame by frame according to animation parameters to produce frame-by-frame animation effects. Except for custom attribute animation, the animation process is driven by the system, and the app side is unaware of the animation process.

- [Transition Animation](arkts-transition-overview.md): Adds transition animations when a component appears or disappears. To ensure animation consistency, some interface animation curves are built-in and do not support developer customization.

  - It is not recommended to use [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) to combine all pages within an app: UIAbility is a task that is displayed as an independent card in the recent tasks screen. Navigation between UIAbilities is equivalent to navigation between tasks. Taking the in-app image viewing scenario as an example, it is not recommended to call the gallery's UIAbility to open an image for full-screen viewing, because this causes task switching and the gallery's UIAbility will also appear in the recent tasks screen. The correct approach is to build a full-screen image component within the app and invoke it through a modal transition, so that all pages within a task are closed-loop within a single UIAbility.

  - In navigation transitions, the [Navigation](../reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md) component should be used to implement transition animations. The previous page + [router](../reference/apis-arkui/js-apis-router.md) approach has limited linkage animation effects during navigation transitions because pages are independent of each other. This not only tends to cause discontinuity between pages, but also does not support one-time development for multi-device deployment.

- [Particle Animation](arkts-particle-animation.md): Describes the principles and usage of particle animation.

- [Component Animation](arkts-component-animation.md): Components provide default animation effects (such as the scrolling animation effect of [List](../reference/apis-arkui/arkui-ts/ts-container-list.md)) for developers to use, and some components also support customized animation effects.

- [Animation Curve](arkts-traditional-curve.md): Describes the characteristics and usage of traditional curves and spring curves. Animation curves affect the motion pattern of attribute values, thereby determining the animation effect on the UI.

- [Animation Smoothing](arkts-animation-smoothing.md): Describes how to achieve natural transitions between animations and between gestures and animations.

- [Motion blur](arkts-blur-effect.md): Describes how to use advanced effect APIs such as blur, large shadows, and color gradients.

- [Frame Animation](arkts-animator.md): The system provides interpolation results during the animation process, and the developer modifies attribute values per frame to produce the animation. Compared with attribute animation, it offers the advantage of pausing, but has lower performance than attribute animation.

## Samples

The following related samples are available for animation development:

- [Animation Effect Sample (ArkTS) (API 9)](https://gitcode.com/openharmony/codelabs/tree/master/ETSUI/Animation)
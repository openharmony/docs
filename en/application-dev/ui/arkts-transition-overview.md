# Transition Animation Overview

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=fd87a3fabd6b3d582616cc6b10933b62b2152e9f translatedAt=2026-08-04T06:39:27.572Z pushedAt=2026-08-04T08:33:53.439Z -->

Transition animations are used to apply animation effects to components that are about to appear or disappear. For components that remain visible at all times, use [attribute animations](arkts-attribute-animation-overview.md). Transition animations are designed to simplify the management of component removal nodes. If you use attribute animations to implement component transitions, you must manually delete the component node in the animation end callback. In addition, a node that has been deleted before the animation ends may reappear, so you need to add logic in the callback to check the node state.

There are several types of transition animations:

- [Enter/Exit transition](arkts-enter-exit-transition.md): used on appearing and disappearing components. It is a basic type of transition.

- [Modal transition](arkts-modal-transition.md): achieved by a modal – a view that appears on top of the current view while the current view remains. The dialog box is a typical type of modal.

- [Shared element transition](arkts-shared-element-transition.md): achieved by animating the size and position between styles of the same or similar elements during page switching.

- [Rotation transition animation](arkts-rotation-transition-animation.md): designed to create seamless visual transitions when the screen display orientation changes. There are two approaches to choose from: [rotation transition animation with layout switching](arkts-rotation-transition-animation.md#rotation-transition-animation-with-layout-switching) and [rotation transition animation with opacity changing](arkts-rotation-transition-animation.md#rotation-transition-animation-with-opacity-changing).

- [Page transition animation](arkts-page-transition-animation.md): achieved by customizing the page transition effects through the **pageTransition** API. To achieve a better transition effect, you are advised to use the [navigation transition](./arkts-navigation-animation.md) and [modal transition](arkts-modal-transition.md).

- [Navigation transition](./arkts-navigation-animation.md): The route transition mode of the page corresponds to the animation effect when one page disappears and another page appears. For example, the level-1 menu of the setting application is switched to the level-2 page.
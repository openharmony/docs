# Transition Animation Overview


Compared with [property animations](arkts-attribute-animation-overview.md), which work for components that are always present, transition animations are applied to animate the appearing or disappearing components. With transition animations, you are freed from the burdensome tasks of disappearing component management, which are unavoidable if you use property animations instead. With property animations, in addition to deleting the component in the animation completion callback, you would also need to add logic to check the component status in the callback, in case that the component that has been deleted appears again before the animation ends.


Transition animations are classified into basic transition animations and advanced, template-based transition animations. They come in any of the following types:


- [Enter/Exit transition](arkts-enter-exit-transition.md): used on appearing and disappearing components. It is a basic type of transition.

- [Navigation transition](arkts-navigation-navigation.md): used during page navigation, where one page disappears and another page appears. For example, it can be used for switching from a level-1 menu page to a level-2 details page.

- [Modal transition](arkts-modal-transition.md): achieved by a modal – a view that appears on top of the current view while the current view remains. The dialog box is a typical type of modal.

- [Shared element transition](arkts-shared-element-transition.md): achieved by animating the size and position between styles of the same or similar elements during page switching.

- [Page transition animation (not recommended)](arkts-page-transition-animation.md): achieved by customizing the page transition effects through the **pageTransition** API. To achieve a better transition effect, you are advised to use the [Navigation](arkts-navigation-navigation.md) component and [modal transition](arkts-modal-transition.md).

- [Rotation transition animation](arkts-rotation-transition-animation.md): designed to create seamless visual transitions when the screen display orientation changes. There are two approaches to choose from: [rotation transition animation with layout switching](arkts-rotation-transition-animation.md#rotation-transition-animation-with-layout-switching) and [rotation transition animation with opacity changing](arkts-rotation-transition-animation.md#rotation-transition-animation-with-opacity-changing).

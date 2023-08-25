# Transition Animation Overview


Compared with [attribute animations](arkts-attribute-animation-overview.md), which work for components that are always present, transition animations are applied to animate the appearing or disappearing components. With transition animations, you are freed from the burdensome tasks of disappearing component management, which are unavoidable if you used attribute animations instead: deleting the component in the callback invoked when the animation is complete; checking the component status in the callback, in case that the component that has been deleted appears again before the animation ends.


Transition animations are classified into basic transition animations and advanced template-based transition animations. They come in any of the following types:


- [Enter/Exit transition](arkts-enter-exit-transition.md): used on appearing and disappearing components. It is a basic type of transition.

- [Navigation transition](arkts-navigation-transition.md): used during page navigation, where one page disappears and another page appears. For example, it can be used for switching from a level-1 menu page to a level-2 details page.

- [Modal transition](arkts-modal-transition.md): achieved by a modal – a view that appears on top of the current view while the current view remains. The dialog box is a typical type of modal.

- [Shared element transition](arkts-shared-element-transition.md): achieved by animating the size and position between styles of the same or similar elements during page switching.

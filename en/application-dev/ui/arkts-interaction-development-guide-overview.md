# Implementing Interaction Responses
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

The ArkUI framework offers a comprehensive set of APIs for handling input events from various peripherals. Beyond basic input handling, ArkUI also provides advanced APIs for responding to normalized user interactions such as gestures, drag and drop, and focus management.

Compared with raw input events, gestures are the preferred method for handling user interactions. Gestures abstract away device-specific differences and represent high-level interaction intent. For example, a tap gesture can be triggered by either a finger touch or a mouse click, and applications only need to bind to the tap gesture to support both input types seamlessly. To deepen your understanding of interaction handling in ArkUI, refer to the following guides:

[Interaction Mechanism Overview](arkts-interaction-basic-principles.md): explains the core concepts and principles behind ArkUI's interaction model.

[Input Devices and Events](arkts-interaction-development-guide-raw-input-event.md): covers raw input events from different devices and how to process them.

[Implementing Gesture Response](arkts-interaction-development-guide-support-gesture.md): demonstrates how to implement gesture-based interactions.

[Supporting Unified Drag-and-Drop](arkts-common-events-drag-event.md): guides you through implementing consistent drag and drop behavior across devices.

[Supporting Focus Processing](arkts-common-events-focus-event.md): shows how to manage component focus within the UI.

When developing UI components using the NDK, you can add interaction responses through the following resources:
- [Listening for Component Events](ndk-listen-to-component-events.md): Learn how to bind basic input events to components.
- [Binding Gesture Events](ndk-bind-gesture-events.md): Add gesture support to components for richer interaction.
- [Drag Event](ndk-drag-event.md): Implement unified drag and drop functionality using NDK APIs.

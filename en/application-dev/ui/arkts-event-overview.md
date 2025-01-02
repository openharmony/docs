# Interaction Event Overview


There are three types of events based on how they are triggered: touchscreen events, keyboard and mouse events, focus events, and drag events.


- [Touchscreen event](arkts-common-events-touch-screen-event.md): an event triggered by an operation (with a finger or a stylus) on the touchscreen.

- [Keyboard and mouse event](arkts-common-events-device-input-event.md): an event triggered by an operation on a peripheral mouse device, touchpad, or keyboard.
  - The mouse event refers to an event triggered by an operation performed with a peripheral mouse device or touchpad.
  - The keyboard event refers to an event triggered by an operation performed with a peripheral keyboard.

- [Focus event](arkts-common-events-focus-event.md): an event triggered when a component receives or loses focus.

- [Drag event](arkts-common-events-drag-event.md): an event initiated by touchscreen and keyboard/mouse events, including long-press dragging with a finger or stylus and mouse dragging.

- [Event distribution](arkts-common-events-distribute.md): a process of collecting hits in the response chain of touchscreen events (excluding key presses and focus).

The gesture event includes the gesture binding method and the bound gesture – a single or combined gesture.


- [Gesture binding method](arkts-gesture-events-binding.md): a method that binds a single or combined gesture to a component and declares the response priority of the bound gesture.

- [Single gesture](arkts-gesture-events-single-gesture.md): basic unit of gestures, which is part of all complex gestures.

- [Combined gesture](arkts-gesture-events-combined-gestures.md): a combination of single gestures brought together according to a declared type and a certain rule.

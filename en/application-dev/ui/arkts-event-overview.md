# Interaction Event Overview


Interaction events are classified into touchscreen events, keyboard and mouse events, and focus events based on trigger types.


- [Touchscreen event](arkts-common-events-touch-screen-event.md): single-finger or single-stroke operation performed by a finger or stylus on the touchscreen.

- [Keyboard and mouse event](arkts-common-events-device-input-event.md): includes operation events of the peripheral mouse or touchpad and key events of the peripheral keyboard.
  - The mouse event refers to an event responded to when an operation is performed with a peripheral mouse/touchpad.
  - The key event refer to an event responded to when an operation is performed with a peripheral keyboard.

- [Focus event](arkts-common-events-focus-event.md): controls the focusability and response events of the component in the preceding ways.


The gesture event includes the gesture binding method and the bound gesture. The bound gesture may be classified into two types: a single gesture and a combined gesture, and is distinguished according to complexity of the gesture.


- [Gesture binding](arkts-gesture-events-binding.md): binds a single gesture or a combination of gestures to a component and declares the response priority of the bound gesture.

- [Single gesture](arkts-gesture-events-single-gesture.md): basic unit of a gesture, which is a part of all complex gestures.

- [Combined gesture](arkts-gesture-events-combined-gestures.md): a combination of multiple single gestures. Multiple single gestures can be combined into a combined gesture according to a declared type and a certain rule, and the combined gesture can be used.

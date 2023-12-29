# Polymorphic Component Overview


As an integral part of an application that can run in multi-device scenarios, components must be able to run on different devices. Necessary adjustments must also be made to them in terms of visual, interaction, and animation to achieve optimal experience. A component that is displayed in different forms on different devices is referred to as a polymorphic component.

Polymorphic components have the following characteristics:

- Serving a variety of device forms, such as the default device, tablet, smart TV, telematics device, and smart wearable. (supported in OpenHarmony 3.2 and later versions)

- Providing consistent effect in different scenarios: Polymorphic components enable the visual, interaction, and animation to be consistent in different scenarios, although attributes may be identical or differential in the design.

- Enabling device-specific optimization: In addition to effect consistency, polymorphic components ensure that optimizations are made specific for different devices and the effects presented on the devices are optimal.

## Component Statuses

- Component statuses are visual presentations that show the current interaction phases of the components. The same state of different components should keep the same visual style, which must be clear and visible.

- An application may be deployed on different devices. Some devices support multiple input modes. For example, a tablet can be connected to a Bluetooth keyboard and mouse for text editing. In this case, the component must meet the interaction requirements of both the keyboard and mouse, and support the focused and hover states. If the component does not support these two states, when users move focus using the keyboard or mouse over a given element, the component cannot render the appropriate state to give the user the correct visual guidance. OpenHarmony provides the default implementation for components in multiple interaction modes to support multiple input modes and unified interaction events.

Common button statuses are as follows.


|![1_en-us_image_0000001568212890.png](figures/1_en-us_image_0000001568212890.png) | ![1_en-us_image_0000001568293053.png](figures/1_en-us_image_0000001568293053.png) | ![1_en-us_image_0000001568212892.png](figures/1_en-us_image_0000001568212892.png) |
| -------- | -------- | -------- |
|**Normal**<br>The component is interactive.|**Disabled**<br>The component is non-interactive.| **Pressed**<br>The component is being touched.<br>Operation: Touch the component with a finger or click the component with a mouse, and hold it. |
| ![1_en-us_image_0000001568212893.png](figures/1_en-us_image_0000001568212893.png) |  ![1_en-us_image_0000001568212894.png](figures/1_en-us_image_0000001568212894.png)  |  ![1_en-us_image_0000001568212895.png](figures/1_en-us_image_0000001568212895.png) |
|**Focused**<br>The component is focused. Operations:<br>- Use arrow keys on a keyboard or remote control to move the focus from one component over another.<br>- Use voice operations to allow a component to gain focus.| **Activated**<br>The component is activated. This state is used for the component that has multiple elements to be focused.<br>Operation: Click a focused subtab of a tab. Touch the tab to activate it.| **Hover**<br> The current component is hovered using a cursor.<br> Operation: Move the cursor over a component.|


# Component Lists

## Navigation

|![bottom-tab](figures/bottom-tab.png)| ![subtab-out-of-screen](figures/subtab-out-of-screen.png)| ![title-bar-common](figures/title-bar-common.png)|
| -------- | -------- | -------- |
|[Bottom tab](multimodal-bottom-tab.md)| [Subtab](multimodal-subtab.md)| [Title bar](multimodal-title-bar.md)|
| ![title-bar-common-backup](figures/title-bar-common-backup.png)|  ![stepper-default](figures/stepper-default.png)|  ![2_en-us_image_0000001568412869.png](figures/2_en-us_image_0000001568412869.png) |
|[Sidebar](multimodal-sidebar.md)| [Page indicator](multimodal-swiper.md)| [Stepper](multimodal-stepper.md)|


## Display Components

|![1_en-us_image_0000001568093257.png](figures/1_en-us_image_0000001568093257.png) | ![1_en-us_image_0000001568212898.png](figures/1_en-us_image_0000001568212898.png)| ![1_en-us_image_0000001568212899.png](figures/1_en-us_image_0000001568212899.png) |
| -------- | -------- | -------- |
|[Divider](multimodal-divider.md)|[Bubble](multimodal-bubble.md)|[Progress bar](multimodal-progress-bar.md)|
|![1_en-us_image_0000001517133790.png](figures/1_en-us_image_0000001517133790.png)| ![1_en-us_image_0000001568093233.png](figures/1_en-us_image_0000001568093233.png) |![1_en-us_image_0000001577319197.png](figures/1_en-us_image_0000001577319197.png) |
|[Badge](multimodal-badge.md)| [Instant tip](multimodal-instant-tip.md)|[Data panel](multimodal-data-panel.md)|
| ![text_sub_1](figures/text_sub_1.png)|  |  |
| [Text](multimodal-text.md)|  |  |


## Operation-related Components

|![2_en-us_image_0000001568212961.png](figures/2_en-us_image_0000001568212961.png) | ![1_en-us_image_0000001517452952.png](figures/1_en-us_image_0000001517452952.png)| ![1_en-us_image_0000001568293089.png](figures/1_en-us_image_0000001568293089.png)|
| -------- | -------- | -------- |
|[Button](multimodal-button.md) |[Drop-down list](multimodal-drop-down-menu.md)|[State button](multimodal-state-button.md)|
|![1_en-us_image_0000001517133794.png](figures/1_en-us_image_0000001517133794.png) |![1_en-us_image_0000001517133814.png](figures/1_en-us_image_0000001517133814.png) |![2_en-us_image_0000001517612920.png](figures/2_en-us_image_0000001517612920.png) |
|[Index bar](multimodal-index-bar.md)| [Scrollbar](multimodal-scrollbar.md)|[Pull to refresh](multimodal-pull-to-refresh.md)|
|![1_en-us_image_0000001568212945.png](figures/1_en-us_image_0000001568212945.png) |  |  |
|[Menu](multimodal-menu.md)|  |  |


## Input Components

|![1_en-us_image_0000001517452972.png](figures/1_en-us_image_0000001517452972.png) | ![1_en-us_image_0000001568093217.png](figures/1_en-us_image_0000001568093217.png) |
| -------- | -------- |
|[Text box](multimodal-text-box.md) |[Search box](multimodal-search-box.md)|  |

## Selection Components

|![1_en-us_image_0000001517133818.png](figures/1_en-us_image_0000001517133818.png) |![1_en-us_image_0000001517293384.png](figures/1_en-us_image_0000001517293384.png) |![1_en-us_image_0000001568093265.png](figures/1_en-us_image_0000001568093265.png) |
| -------- | -------- | -------- |
| [Tick box](multimodal-tick-box.md)| [Toggle](multimodal-toggle.md)| [Radio button](multimodal-radio-button.md)|
|![1_en-us_image_0000001517133778.png](figures/1_en-us_image_0000001517133778.png) | ![1_en-us_image_0000001517452964.png](figures/1_en-us_image_0000001517452964.png)|![3_en-us_image_0000001517133822.png](figures/3_en-us_image_0000001517133822.png) |
| [Check box](multimodal-check-box.md)|[Rating bar](multimodal-rating-bar.md)| [Slider](multimodal-slider.md)|
|![1_en-us_image_0000001517293372.png](figures/1_en-us_image_0000001517293372.png) | | |
|[Picker](multimodal-picker.md)|  |  |


## Container Components

|![2_en-us_image_0000001568212941.png](figures/2_en-us_image_0000001568212941.png) |![1_en-us_image_0000001568412877.png](figures/1_en-us_image_0000001568412877.png) |
| -------- | -------- |
|[Panel](multimodal-slidable-panel.md)| [Dialog](multimodal-dialog.md)|  |

# ArkTS Widget Working Principles


## Implementation Principles

**Figure 1** ArkTS widget implementation principles
![WidgetPrinciple](figures/WidgetPrinciple.png)

- Widget host: an application that displays the widget content and controls the widget location. Only the system application can function as a widget host.

- Widget provider: an application that provides the widget content to display and controls how widget components are laid out and how they interact with users.

- Widget Manager: a resident agent that manages widgets in the system. It provides [formProvider](../reference/apis-form-kit/js-apis-app-form-formProvider.md)<!--Del--> and [formHost](../reference/apis-form-kit/js-apis-app-form-formHost-sys.md)<!--DelEnd--> as well as the APIs for widget management, usage, and periodic updates. 

- Widget rendering service: a service that manages widget rendering instances. Widget rendering instances are bound to the <!--Del-->[<!--DelEnd-->FormComponent<!--Del-->](../reference/apis-arkui/arkui-ts/ts-basic-components-formcomponent-sys.md)<!--DelEnd--> on the widget host on a one-to-one basis. The widget rendering service runs the widget page code **widgets.abc** for rendering, and sends the rendered data to the corresponding <!--Del-->[<!--DelEnd-->FormComponent<!--Del-->](../reference/apis-arkui/arkui-ts/ts-basic-components-formcomponent-sys.md)<!--DelEnd--> on the widget host.

  **Figure 2** Working principles of the ArkTS widget rendering service
![WidgetRender](figures/WidgetRender.png)

Compared with dynamic widgets, static widgets have the same overall running framework and rendering process. The main difference is that after the widget rendering service renders the widget content, the widget host uses the last frame of rendered data as a static image, and the widget rendering instance releases all running resources of the widget to save memory. As such, frequent updating of static widgets causes continuous creation and destruction of resources, resulting in increased power consumption.<br>
Unlike JS widgets, ArkTS widgets support logic code execution. The widget page code **widgets.abc** is executed by the widget rendering service, which is managed by the Widget Manager. Each widget component of a widget host corresponds to a rendering instance in the widget rendering service. Rendering instances of a widget provider run in the same ArkTS virtual machine operating environment, and rendering instances of different widget providers run in different ArkTS virtual machine operating environments. In this way, the resources and state data are isolated between widgets of different widget providers. During development, pay attention to the use of the **globalThis** object. Use one **globalThis** object for widgets from the same widget provider, and different **globalThis** objects for widgets from different widget providers.


## Advantages of ArkTS Widgets

As a quick entry to applications, ArkTS widgets outperform JS widgets in the following aspects:

- Improved development experience and efficiency, thanks to the unified development paradigm
  
  ArkTS widgets share the same declarative UI development framework as application pages. This means that the page layouts can be directly reused in widgets, improving development experience and efficiency.
  
  **Figure 3** Comparison of widget project structures
  ![WidgetProject](figures/WidgetProject.png)
  
- More widget features
  - Animation: ArkTS widgets support the [property animation](../reference/apis-arkui/arkui-ts/ts-animatorproperty.md) and [explicit animation](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md) capabilities, which can be leveraged to deliver a more engaging experience.
  - Custom drawing: ArkTS widgets allow you to draw graphics with the [\<Canvas>](../reference/apis-arkui/arkui-ts/ts-components-canvas-canvas.md) component to present information more vividly.
  - Logic code execution: The capability to run logic code in widgets means that service logic can be self-closed in widgets, expanding the use cases of widgets.

## Constraints on ArkTS Widgets

Compared with JS widgets, ArkTS widgets provide more capabilities, but they are also more prone to malicious behavior. To account for the impact on the widget host – typically the home screen, ArkTS widgets are subject to the following restrictions:

- When importing modules, you can import only the modules marked with "supported in ArkTS widgets."

- [HAR](../quick-start/har-package.md) can be imported, but [HSP](../quick-start/in-app-hsp.md) cannot.

- The native programming language cannot be used for development.

- Only partial components, events, animations, data management, state management, and API capabilities of the [declarative paradigm](../ui/arkts-ui-development-overview.md) are supported.

- The event processing of the widget is independent of that of the widget host. To prevent gesture conflicts, avoid using swipers in the widget when the widget host supports left and right swipes.

In addition, ArkTS widgets do not support the following features:

- Instant preview

- Breakpoint debugging

- Hot reload

- **setTimeOut**

## Samples

The following samples are provided to help you better understand how to develop an ArkTS widget:


- [Communication Between JS and C++ for Stage Model Widgets (ArkTS, API version 10)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/FormGame)

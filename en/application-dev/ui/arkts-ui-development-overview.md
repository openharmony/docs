# UI Development (ArkTS-based Declarative Development Paradigm) Overview


Based on the ArkTS declarative development paradigm, the Ark development framework is a simplified, high-performance, and cross-device UI development framework. It provides the capabilities required for building the OpenHarmony application UI, including:


- **ArkTS**

  ArkTS is a UI development language extended based on TypeScript (TS) and is a superset of TS. Extension capabilities include various decorators, custom components, and UI description mechanisms. State data management provides clear page update and rendering processes and pipes through decorators with different functions. State management covers UI component states and application states. With these features, you are able to build an application-wide data update and UI rendering process. For details about the basic knowledge of ArkTS, see [Learning ArkTS] (../quick-start/arkts-get-started.md).

- **Layout**

  The layout is a necessary element of the UI. It defines the position of a component on the UI. The ArkUI framework provides multiple layout modes. In addition to the basic linear layout, cascading layout, elastic layout, relative layout, and grid layout, the ArkUI framework also provides relatively complex lists, grids, and rotation.

- **Component**

  Components are necessary elements of the UI and form the appearance of the UI. Components directly provided by the framework are called system components, and components defined by developers are called custom components. The built-in components of the system include buttons, option buttons, progress bars, and texts. Developers can set the rendering effect of built-in components in the system in chain invoking mode. You can combine system components to form custom components. In this way, page components are divided into independent UI units to implement independent creation, development, and reuse of different units on pages, making pages more engineering-oriented.

- Page Routing and Component Navigation

  An application may contain multiple pages. Page routing can be used to switch between pages. Navigation between components may exist on a page, for example, a typical column. You can use the navigation component to implement navigation between components.

- **Graph**

  The Ark development framework provides the display capability of multiple types of images and multiple customized drawing capabilities to meet developers' customized drawing requirements. It supports shape drawing, color filling, text drawing, deformation and cropping, and image embedding.

- **Animation**

  Animation is one of the important elements of the UI. Excellent animation design can greatly improve user experience. The framework provides rich animation capabilities, including attribute animation, explicit animation, customized transition animation, and animation APIs in addition to built-in animation effects of components, developers can customize animation tracks by encapsulating physical models or invoking animation capability APIs.

- Interaction Event

  Interaction events are necessary elements for the interaction between the UI and users. The Ark development framework provides multiple interaction events. In addition to common events such as touch events, mouse events, keyboard key events, and focus events, the Ark development framework also includes gesture events that are further recognized based on common events. The gesture event includes a single gesture such as a tap gesture, a touch and hold gesture, a drag gesture, a pinch gesture, a rotation gesture, a slide gesture, and a combined gesture event combined by using a single gesture event.


## Characteristics

- High development efficiency and good development experience
  - Simple code: The UI is described in a way close to natural semantics, and you do not need to care about how the framework implements UI drawing and rendering.
  - Data-driven UI change: Enables developers to focus on their own service logic processing. When the UI changes, developers do not need to compile the UI code for switching between different UIs. Instead, developers only need to compile the data that causes the UI change. The specific UI change is handed over to the framework.
  - Good development experience: The GUI is also code, which improves the programming experience of developers.

- High Performance
  - Declarative UI frontend and backend layering: The UI backend is constructed using the C++ language and provides basic components, layout, dynamic effects, interaction events, component status management, and rendering pipelines for the frontend.
  - Language compiler and runtime optimization: unified bytecode, efficient FFI-Foreign Function Interface, AOT-Ahead Of Time, engine minimization, and type optimization.

- The ecosystem is easy to promote quickly.
  Be able to leverage the mainstream language ecosystem to quickly promote the language. The language is relatively neutral and friendly. There are corresponding standard organizations that can gradually evolve.


## Architecture

  Figure 1 Overall architecture 

![arkui-arkts-framework](figures/arkui-arkts-framework.png)




- **Declarative UI frontend**
  Provides basic language specifications of the UI development paradigm, built-in UI components, layouts, and animations, and multiple state management mechanisms, with a wide array of APIs for you to call as required.

- **Language runtime**
  When the Ark language is used, the UI normal form syntax parsing capability, cross-language invoking capability, and TS high-performance running environment are provided.

- **Declarative UI backend engine**
  Provides UI rendering pipelines that are compatible with different development paradigms, multiple basic components, layout calculation, dynamic effects, and interaction events, with state management and drawing capabilities.

- **Render engine**
  Provides efficient drawing capabilities, which enable rendering instructions collected by the rendering pipeline to be drawn to the screen.

- **Porting layer**
  Provides abstract APIs to connect to different systems, such as system rendering pipelines and lifecycle scheduling.


## Development process

When the UI development framework is used to develop applications, the following development process is involved: Developers can understand the UI development process of the entire application by referring to the ../quick-start/start-with-ets-stage.md example.


| Task         | Introduction                                 | Guide                                    |
| ----------- | ----------------------------------- | ---------------------------------------- |
| Learning ArkTS    | The basic syntax, state management, and rendering control scenarios of ArkTS are introduced.        | - [Basic Syntax] (../quick-start/arkts-basic-syntax-overview.md)<br>- [Status Management] (../quick-start/arkts-state-management-overview.md)<br>- [Rendering Control] (../quick-start/arkts-rendering-control-overview.md)|
| Developing the Layout       | This section describes several common layout modes and how to improve layout performance.            | -&nbsp;[Common Layout](arkts-layout-development-overview.md)<br>-&nbsp;[Layout Performance](arkts-layout-development-performance-boost.md)|
| Add Component       | This topic describes common built-in components, custom components, and GUI elements supported by APIs.| -&nbsp;[Common Components](arkts-common-components-button.md)<br>- [Customized Component] (../quick-start/arkts-create-custom-components.md)<br>-&nbsp;[Bubble and Menu](arkts-popup-and-menu-components-popup.md)|
| Setting Page Routes and Component Navigation| This topic describes how to set page routes and navigation between components.               | -&nbsp;[Page Route] (arkts-routing.md)<br>-&nbsp;[Component Navigation] (arkts-navigation-navigation.md)|
| Display Chart       | Describes how to display images, draw custom geometry, and draw custom graphics using the canvas.  | -&nbsp; [image] (arkts-graphics-display.md)<br>-&nbsp;[geometric shape](arkts-geometric-shape-drawing.md)<br>-&nbsp;[Canvas](arkts-drawing-customization-on-canvas.md)|
| Using Animation       | This topic describes the typical scenarios of using animations on components and pages.                 | -&nbsp;[Animation on the page](arkts-layout-update-animation.md)<br>-&nbsp; [animation between pages] (arkts-zoom-animation.md)|
| Binding Events       | This topic describes the basic concepts of events and how to use common events and gesture events.          | -&nbsp;[Common Event](arkts-common-events-touch-screen-event.md)<br>-&nbsp;[Gesture event](arkts-gesture-events-binding.md)|

## Samples

For details about the declarative development paradigm based on ArkTS, see the following example:

[ArkTS component set] (https://gitee.com/openharmony/applications_app_samples/tree/master/code/UI/ArkTsComponentClollection/ComponentCollection): a set of components, common methods, animations, and global methods.

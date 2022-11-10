# Overview


The eTS-based declarative development paradigm of ArkUI is a simplified, high-performance UI development framework for cross-device applications.


## Basic Capabilities

In ArkUI that uses the eTS-based declarative development paradigm, the programming mode is closer to natural semantics. You can intuitively describe the UI without caring about how the framework implements UI drawing and rendering, leading to simplified and efficient development. The UI capabilities are provided from three dimensions: component, animation, and state management. System capability APIs are also provided to allow for effortless invocation of system capabilities.

For details about the UI components, see [Component Reference (eTS-based Declarative Development Paradigm)](../reference/arkui-ts/ts-universal-events-click.md).


- Out-of-the-box components
  
  A wide range of preset system components are provided. You can set the rendering effect of these components in method chaining mode. You can combine system components to form custom components. In this way, page components are divided into independent UI units to implement independent creation, development, and reuse of different units on pages, making pages more engineering-oriented.


- A diverse array of animation APIs
  
  By drawing from the standard SVG drawing capability and various open animation APIs, you can customize animation tracks by encapsulating physical models or calling the provided APIs.


- State and data management
  
  State data management provides clear page update and rendering processes and pipes through decorators with different functions. State management covers UI component states and application states. With these features, you are able to build an application-wide data update and UI rendering process.


- System capability APIs
  
  Development has never been so easy, with a diverse array of encapsulated system capability APIs, from UI design to system capability invoking.


## Overall Architecture



![en-us_image_0000001223287712](figures/en-us_image_0000001223287712.png)

- Declarative UI frontend
  
  Provides basic language specifications of the UI development paradigm, built-in UI components, layouts, and animations, and multiple state management mechanisms, with a wide array of APIs for you to call as required.
  
- Language runtime

  Provides the parsing capability for the UI paradigm syntax and allows for cross-language API calls for a high-performance running environment of the eTS language.

- Declarative UI backend engine

  Provides UI rendering pipelines that are compatible with different development paradigms, multiple basic components, layout calculation, dynamic effects, and interaction events, with state management and drawing capabilities.

- Render engine

  Provides efficient drawing capabilities, which enable rendering instructions collected by the rendering pipeline to be drawn to the screen.

- Porting layer

  Provides abstract APIs to connect to different systems, such as system rendering pipelines and lifecycle scheduling.
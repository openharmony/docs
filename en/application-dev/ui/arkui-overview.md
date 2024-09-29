# Introduction to ArkUI


ArkUI provides a comprehensive infrastructure for UI development of applications, including simple UI syntax, a diverse array of UI features (components, layouts, animations, and interaction events), and a powerful previewer.


## Basic Concepts

- **UI**: user interface. You can design multiple pages for your application, manage their files on a per-page basis, and schedule page redirection through [routing](arkts-routing.md) APIs, so as to implement decoupling of application functions.

- **Component**: the smallest unit for UI building and display, for example, a list, grid, button, radio button, progress indicator, and text. You build a UI that meets your needs through flexible combinations of components.


## Two Development Paradigms

ArkUI comes with two development paradigms: [ArkTS-based declarative development paradigm](arkts-ui-development-overview.md) (declarative development paradigm for short) and [JS-compatible web-like development paradigm](ui-js-overview.md) (web-like development paradigm for short). You can choose whichever development paradigm that aligns with your practice.

- **Declarative development paradigm**: uses [ArkTS](../quick-start/arkts-get-started.md) – a superset of TypeScript with declarative UI syntax, providing UI drawing capabilities from three dimensions: component, animation, and state management.

- **Web-like development paradigm**: uses the classical three-stage programming model, in which HML is used for building layouts, CSS for defining styles, and JS for adding processing logic. This development paradigm has a low learning curve for frontend web developers, allowing them to quickly transform existing web applications into ArkUI applications.

The declarative development paradigm is a better choice for building new application UIs for the following reasons:

- **Higher development efficiency**: In the declarative development paradigm, the programming mode used is closer to natural semantics. You can intuitively describe the UI without caring about how the framework implements UI drawing and rendering, leading to simplified and efficient development.

- **Higher application performance**: As shown below, the two development paradigms share the UI backend engine and language runtime. However, the declarative development paradigm does not require the JS framework for managing the page DOM. As such, it has more streamlined rendering and update links and less memory usage.

- **Future proof**: The declarative development paradigm will continue to develop as the preferred development paradigm, providing increasingly diverse and powerful capabilities.

  **Figure 1** ArkUI framework

  ![arkui-framework](figures/arkui-framework.png)


## Development Paradigm Support by Application Type

The supported development paradigm varies according to the [application model](../application-models/application-models.md) and page form. For details, see the following table.

  **Table 1** Supported development paradigms

| Application Model       | Page Form    | Supported Development Paradigm               |
| ----------- | -------- | ------------------------ |
| Stage model (recommended)| Application or service page| Declarative development paradigm (recommended)             |
|             | Widget      | Declarative development paradigm (recommended)<br>Web-like development paradigm|
| FA model       | Application or service page| Declarative development paradigm<br>Web-like development paradigm    |
|             | Widget      | Web-like development paradigm                |

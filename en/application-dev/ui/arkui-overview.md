# ArkUI Overview


## Introduction

ArkUI is a UI development framework that provides what you'll need to develop application UIs.


## Basic Concepts

- Component: the smallest unit for UI building and display. You build a UI that meets your needs through flexible combinations of components.

- Page: the smallest unit for ArkUI application scheduling. You can design multiple pages for your application, manage their files on a per-page basis, and schedule page redirection through routing APIs, so as to implement decoupling of application functions.


## Key Features

- UI components: In addition to a wide range of basic components, such as components for text display, image display, and keypress interaction, ArkUI provides media components that support video playback. Better yet, it also provides polymorphic components, which can adapt to styles of different devices.
- Layout: Creating a responsive UI in ArkUI is easy, with our carefully-designed layout approaches: Besides the classic flexible layout capability, you also have access to the list, grid, and atomic layouts that auto-adapt to screen resolutions.
- Animation: Apart from animations embedded in components, ArkUI offers additional animation features: attribute animation, transition animation, and custom animation.
- Drawing: ArkUI offers advanced drawing capabilities that allow you to draw custom shapes with a range of editors, from images to fill colors and texts.
- Interaction: ArkUI allows users to interact with your application UI properly, regardless of the system platform and input device. By default, the UI accepts input from touch gestures, remote controls, and mouse devices, with support for the event notification capability.
- Platform API channel: ArkUI provides an API extension mechanism through which platform capabilities are encapsulated to produce JavaScript APIs in a unified style.
- Two development paradigms: ArkUI comes with two development paradigms: eTS-based declarative development paradigm (declarative development paradigm for short) and JavaScript-compatible web-like development paradigm (web-like development paradigm for short). You can choose whichever development paradigm that aligns with your practice.

| Development Paradigm | Description | Applicable To | Intended Audience |
| -------- | -------- | -------- | -------- |
| Web-like development paradigm | Uses the classical three-stage programming model, in which OpenHarmony Markup Language (HML) is used for building layouts, CSS for defining styles, and JavaScript for adding processing logic. UI components are associated with data through one-way data-binding. This means that when data changes, the UI automatically updates with the new data. This development paradigm has a low learning curve for frontend web developers, allowing them to quickly transform existing web applications into ArkUI applications. | Small- and medium-sized applications and service widgets with simple UIs | Frontend web developers |
| Declarative development paradigm | Uses the TypeScript programming language and extends the declarative UI syntax, providing UI drawing capabilities from three dimensions: component, animation, and state management. The programming mode used is closer to natural semantics. You can intuitively describe the UI without caring about how the framework implements UI drawing and rendering, leading to simplified and efficient development. With type annotations in TypeScript, you can enforce type checking at compile time. | Applications involving technological sophistication and teamwork | Mobile application and system application developers |


### Framework Structure

![en-us_image_0000001267647869](figures/en-us_image_0000001267647869.png)

As shown above, the two development paradigms share the UI backend engine and language runtime. The UI backend engine implements the six basic capabilities of the ArkUI framework. The declarative development paradigm does not require the JS Framework for managing the page DOM. As such, it has more streamlined rendering and update links and less memory usage. This makes the declarative development paradigm a better choice for building application UIs.

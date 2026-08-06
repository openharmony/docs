# Glossary

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=6ac4ec266f1c1406b953d4c6e8f9d336d60e6c38 translatedAt=2026-08-03T02:28:51.636Z pushedAt=2026-08-03T07:38:40.572Z -->

## A

### ArkTS Widget

  A service widget developed using the declarative development paradigm of ArkTS. Compared with JS widgets, ArkTS widgets support capabilities such as running logic code, property animations, explicit animations, and custom drawing with the Canvas component. ArkTS widgets use the same development paradigm as application pages, allowing page layouts to be reused while providing a richer interactive experience.

## D

### Dynamic Widget

  A type of ArkTS widget that, in addition to supporting UI components and layout capabilities, also supports common event handling and custom animation capabilities, allowing application logic to run within the widget. It is suitable for scenarios requiring complex business logic and interactions, such as refreshing images or content in a widget. It supports **router**, **message**, and **call** interactions between the widget and the application through the **postCardAction** API.

## F

### Fun-based Widget

  A type of interactive widget that provides widget mini games. Users can launch the corresponding mini game by tapping the widget. It is suitable for scenarios that enhance user engagement and entertainment. Currently, this type is supported only for quick game-based development and is available only to developers who have implemented quick games.

## I

### Interactive Widget

  An ArkTS widget type that extends standard widgets with overflow animation capabilities. Supported since API version 20, interactive widgets are classified into fun-based widgets and scene-based widgets. They are suitable for scenarios requiring complex service logic, rich interactions, and immersive visual effects, such as desktop widget games and animated weather widgets.

## J

### JS Widget

  A service widget developed using the web-like paradigm (HML, CSS, and JSON). It supports both the FA and stage application models but does not support custom animations, custom drawing, or executable logic. Compared with ArkTS widgets, JS widgets provide more basic capabilities.

## N

### Normal Widget

  A widget type that remains on the host until it is removed or modified by the user. Most functional widgets are normal widgets. This concept is defined from the perspective of the widget host and is the counterpart of a temporary widget.

## O

### Overflow Animation

  An effect exclusive to interactive widgets that allows rendering beyond the widget boundary, creating the visual impression that the animation breaks out of the widget frame.

## S

### Scene-based Widget

  A type of interactive widget that supports effects triggered by specific events, such as scheduled data updates, point-in-time refreshes, or user interactions. It has active and inactive states. In the active state, the widget UI is rendered by the page associated with **LiveFormExtensionAbility**, enabling overflow animations. It is suitable for scenarios requiring rich notifications and lightweight interactions, and is available to both applications and atomic services.

### Shared Package

  One of the packaging modes for ArkTS widgets. The widget UI and application code reside in the same module and are packaged into the same HAP, making development and debugging easier. This is the traditional packaging mode for ArkTS widgets.

### Standalone Package

  One of the packaging modes for ArkTS widgets. The widget UI and application code reside in different modules and are packaged into separate widget and application packages. Supported since API version 20, this mode enables independent updates of widgets and applications. Ensure that the widget package and application package use the same version number.

### Static Widget

  A type of ArkTS widget that supports only UI components and layout capabilities. Interaction with the application is provided through the **FormLink** component. After rendering is complete, the Widget Rendering Service displays the last rendered frame as a static image and releases all runtime resources associated with the widget to reduce memory usage. Static widgets are suitable for displaying relatively fixed content while minimizing memory consumption.

## T

### Temporary Widget

  A widget type that is displayed temporarily in response to specific events or user actions and disappears automatically afterward. It is the counterpart of a normal widget. Temporary widgets are currently not used by widget hosts.

## W

### Widget Host

  The host application that displays widget content and interacts directly with users. It supports adding, removing, displaying, and positioning widgets. Currently, only system applications can act as widget hosts. The desktop application is a typical widget host.

### Widget Provider

  An application or atomic service that provides widget content. The widget provider is responsible for implementing the widget UI, updating data, handling user interactions, and implementing the FormExtensionAbility lifecycle to create, update, and delete widgets.

### Widget Manager

  A system service that manages widget information across the device and serves as the bridge between widget providers and widget hosts. It provides widget hosts with capabilities such as querying, adding, and removing widgets, and notifies widget providers when widgets are added, removed, refreshed, or clicked. It also manages widget objects and periodic widget refreshes.

### Widget Rendering Service

  A system service that manages widget rendering instances. Each rendering instance is bound to a widget component in a widget host. Based on the widget configuration in **form_config.json**, the service executes the widget page code in the **widget.abc** file, renders the widget, and sends the rendered output to the corresponding widget component in the host. Rendering instances belonging to the same widget provider run in the same ArkTS virtual machine, while instances belonging to different widget providers run in separate ArkTS virtual machines, ensuring resource and state isolation.
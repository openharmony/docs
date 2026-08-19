# Ability Kit Terminology

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @ccllee1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=d58ce0749bd78990b688a4afdb28e2899c292224 translatedAt=2026-08-19T02:51:21.139Z pushedAt=2026-08-19T02:56:10.361Z -->

## A

### AbilityStage

[AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md) is a component manager at the [module](../quick-start/application-package-overview.md#multi-module-design-mechanism) level.

### ArkTS Child Process

An ArkTS child process is where the system automatically sets up an ArkTS runtime environment when it starts.

### App Linking

App Linking is a technology that enables redirection between applications. It uses a URI (an HTTPS link) provided by the system to direct users to specific content within a target application. Users can access the content associated with the link regardless of whether the target application is installed. Compared to Deep Linking, this redirection method incorporates a domain verification mechanism, which helps prevent app spoofing and enhances security.

## C

### Candidate Master Process

When an application has multiple processes, the system automatically designates a master process at application startup. If you want the current process to be selected as the master process, you can add it to the candidate master process list. Processes in this list are considered candidate master processes. When the current master process is destroyed, the system sets the candidate master process at the head of the list as the new master process.

### Context

**Context** is the base context class in the Stage model, encapsulating the fundamental environment and capabilities required for an application to run. As the core bridge between the framework and application components, it provides general-purpose APIs for accessing the application's resources, retrieving application information, and managing the application lifecycle.

Within the Stage model, **Context** serves as the base class that defines the common capabilities shared by all contexts. Its subclasses, such as **ApplicationContext**, **AbilityStageContext**, **UIAbilityContext**, and **ExtensionContext**, extend this foundation with specialized functionality tailored to specific component levels or runtime scenarios. For example, **ApplicationContext** operates as the application-level context, offering application-wide control such as lifecycle monitoring, process management, and environment configuration. In contrast, **AbilityStageContext** serves as the contextual environment for **AbilityStage**, providing access to the corresponding **ModuleInfo** object and environment change objects.

## D

### Deep Linking

Deep Linking is a technology that launches a specific application via a link. Its key characteristic is that it allows developers to define a scheme in any format. However, because it lacks a domain ownership verification mechanism, this approach carries the risk of being spoofed by other applications. This stands in clear contrast to App Linking, which uses standard HTTPS links and enforces domain verification to ensure uniqueness and security.

### Multiton Mode

Multiton mode is a launch mode that allows multiple independent, concurrently running instances of the same application component (such as a UIAbility) to exist.

## F

### FA Model

The FA model is an early application model that provides essential components and runtime mechanisms for applications. In this model, each application component has its own ArkTS engine instance, making it suitable for developing simple applications. This model is no longer the primary recommendation, and it is advised to use the new Stage model for development.

## I

### Intent Provider Management

[Intent provider management](../reference/apis-ability-kit/js-apis-app-ability-insightIntentProvider.md) enables an application to integrate its service functions into the InsightIntent framework by declaring standard or custom intents.

## K

### Cross-Device Migration

Cross-device migration refers to migrating a UIAbility running on device A to device B. After the migration is complete, the UIAbility on device B continues the task, while the UIAbility on device A can decide whether to exit as needed.

## M

### Master Process

When an application has multiple processes and you need to dynamically assign different ability instances to specific processes, the system automatically designates a process to handle overall coordination and allocation at application startup. This designated process is the master process. By default, the system designates the first process launched by the application as the master process.

You can set the return value of [onNewProcessRequest](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onnewprocessrequest11) to allow the master process to determine which process will run the new ability instance based on the callback information received through this API.

## N

### Native Child Process

A native child process runs only C/C++ code. By default, the system does not create an ArkTS runtime environment for this type of child process.

## P

### PageAbility Component

A PageAbility is a UI-capable application component in the FA model that contains a user interface and is primarily used for user interaction.

## S

### Stage Model

The stage model is the currently recommended application model, providing essential components and runtime mechanisms for applications. This model introduces the AbilityStage component manager and the WindowStage window manager, which act as the stages for application components and windows, respectively, hence the name "stage model."

The stage model allows multiple application components to share a single ArkTS engine instance and supports state sharing and object invocation between components. This reduces memory overhead and enhances development efficiency, making it well-suited for complex application development.

## T

### Taihe

A cross-language API programming model. Developers define business interfaces by writing IDL files (with the `ohidl` extension) and use the Taihe compiler tool to automatically generate interface glue code in the target language, simplifying the development process.

### taihec

The compiler tool of Taihe, used to parse `ohidl` files and generate target code.

## U

### UIAbility

A UIAbility is an application component that contains a user interface (UI). It serves as the fundamental unit of system scheduling and provides a window for the application to render its interface.

### UIAbility Lifecycle

The UIAbility lifecycle refers to the complete process from creation to destruction of a UIAbility component. During this process, the system invokes corresponding callback functions at specific points. For example, when an application creates a UIAbility instance for the first time, the system calls the **onCreate()** callback.

### UIAbility Cold Start

A cold start occurs when a UIAbility instance is launched from a completely closed state. This means the system needs to fully load and initialize all the code and resources for that UIAbility. Subsequently, its lifecycle callbacks are triggered in the following order: **onCreate**, **onWindowStageCreate**, and **onForeground**.

### UIAbility Hot Start

A hot start happens when a previously launched UIAbility instance, having been switched to the background, is started again. Since the instance does not need to be completely reconstructed, the system can quickly restore its previous state. The lifecycle skips the initial creation phases and directly triggers the **onNewWant** callback, after which the UIAbility moves to the foreground and triggers the **onForeground** callback.

## X

### Explicit Want Launch

Explicit Want launch refers to the case where, when launching a target application component, the caller specifies abilityName and bundleName in the [want](../reference/apis-ability-kit/js-apis-app-ability-want.md) parameter. This is called explicit Want launch.

Explicit Want launch is a straightforward and effective way to start a target application component when the specific object to handle the request is known.

### System-Level so

An so provided by the system, which is part of the operating system and released with the system image.

## Y

### Implicit Want Launch

An implicit Want launch occurs when the caller does not specify the **abilityName** in the [want](../reference/apis-ability-kit/js-apis-app-ability-want.md) parameter when starting a target application component.

Implicit Want launch can be used when the target handler is not clearly defined. It allows the current application to directly invoke a capability provided by another application without needing to know which specific application provides that capability.

### App-Level so

An so independently developed by application developers through [Node-API](../napi/use-napi-process.md), which is part of the app and released with the app.
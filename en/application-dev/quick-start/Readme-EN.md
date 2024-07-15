# Quick Start
<!--Del-->
- Getting Started
  - [Before You Start](start-overview.md)
  - [Building the First ArkTS Application in Stage Model](start-with-ets-stage.md)
<!--DelEnd-->
- Development Fundamentals
  - Application Package Fundamentals
    - [Application Package Overview](application-package-overview.md)
    - Application Package Structure
      - [Application Package Structure in Stage Model](application-package-structure-stage.md)
      - [Application Package Structure in FA Model](application-package-structure-fa.md)
    - Application Package Development and Usage
      - [HAP](hap-package.md)
      - [HAR](har-package.md)
      - [HSP](in-app-hsp.md)
      - [Dynamic Import](arkts-dynamic-import.md)
      - [Lazy Import](arkts-lazy-import.md)
    - [Application Package Installation, Uninstall, and Update](application-package-install-uninstall.md)
  - Application Configuration Files in Stage Model
    - [Overview of Application Configuration Files in Stage Model](application-configuration-file-overview-stage.md)
    - [app.json5 Configuration File](app-configuration-file.md)
    - [module.json5 Configuration File](module-configuration-file.md)
  - Application Configuration Files in FA Model
    - [Overview of Application Configuration Files in FA Model](application-configuration-file-overview-fa.md)
    - [Structure of the app Tag](app-structure.md)
    - [Structure of the deviceConfig Tag](deviceconfig-structure.md)
    - [Structure of the module Tag](module-structure.md)

- [Resource Categories and Access](resource-categories-and-access.md)

- Learning ArkTS
  - [Getting Started with ArkTS](arkts-get-started.md)

  - [Introduction to ArkTS](introduction-to-arkts.md)
  - TypeScript to ArkTS Migration Guide
    - [ArkTS Migration Background](arkts-migration-background.md)
    - [TypeScript to ArkTS Cookbook](typescript-to-arkts-migration-guide.md)
    - [Adaptation Cases](arkts-more-cases.md)

  - [ArkTS Performant Programming Practices](arkts-high-performance-programming.md)

  - Basic Syntax of UI Paradigms
    - [Basic Syntax Overview](arkts-basic-syntax-overview.md)

    - [Declarative UI Description](arkts-declarative-ui-description.md)

    - CustomComponent
      - [Creating a Custom Component](arkts-create-custom-components.md)
      - [Page and Custom Component Lifecycle](arkts-page-custom-components-lifecycle.md)
      - [Custom Component Layout](arkts-page-custom-components-layout.md)
      - [Freezing a Custom Component](arkts-custom-components-freeze.md)
      - [Constraints on Access Modifiers of Custom Component Member Variables](arkts-custom-components-access-restrictions.md)

    - [\@Builder Decorator: Custom Builder Function](arkts-builder.md)

    - [\@BuilderParam Decorator: @Builder Function Reference](arkts-builderparam.md)

    - [wrapBuilder: Encapsulating a Global @Builder](arkts-wrapBuilder.md)

    - [\@Styles Decorator: Defining Reusable Styles](arkts-style.md)

    - [\@Extend Decorator: Extending Built-in Components](arkts-extend.md)

    - [stateStyles: Polymorphic Style](arkts-statestyles.md)

    - [\@AnimatableExtend Decorator: Defining Animatable Attributes](arkts-animatable-extend.md)

    - [\@Require Decorator: Validating Constructor Input Parameters](arkts-require.md)

  - State Management

    - [State Management Overview](arkts-state-management-overview.md)
    - State Management (V1 Stable Version)
      - Component State Management
        - [\@State Decorator: State Owned by Component](arkts-state.md)
        - [\@Prop Decorator: Creating a One-Way Synchronization from the Parent Component to Child Components](arkts-prop.md)
        - [\@Link Decorator: Creating a Two-Way Synchronization Between Parent and Child Components](arkts-link.md)
        - [\@Provide and \@Consume Decorators: Creating a Two-Way Synchronization with Descendant Components](arkts-provide-and-consume.md)
        - [\@Observed and \@ObjectLink Decorators: Observing Attribute Changes in Nested Class Objects](arkts-observed-and-objectlink.md)
      - Application State Management
        - [Application State Management Overview](arkts-application-state-management-overview.md)
        - [LocalStorage: Storing UI State](arkts-localstorage.md)
        - [AppStorage: Storing Application-wide UI State](arkts-appstorage.md)
        - [PersistentStorage: Persisting Application State](arkts-persiststorage.md)
        - [Environment: Querying Device Environment](arkts-environment.md)
      - Other State Management Features
        - [Overview of Other State Management Features](arkts-other-state-mgmt-functions-overview.md)
        - [\@Watch Decorator: Getting Notified of State Variable Changes](arkts-watch.md)
        - [$$ Syntax: Creating a Two-Way Synchronization with Built-in Components](arkts-two-way-sync.md)
        - [\@Track Decorator: Updating Class Object Properties](arkts-track.md)
      - [MVVM](arkts-mvvm.md)
      - [Best Practices for State Management](arkts-state-management-best-practices.md)
      - [Proper Use of State Management](properly-use-state-management-to-develope.md)

    - State Management (V2 Trial Version)
      - [\@ObservedV2 and \@Trace Decorators: Observing Class Property Changes](arkts-new-observedV2-and-trace.md)
      - [\@ComponentV2 Decorator: Custom Component](arkts-new-componentV2.md)
      - [\@Local Decorator: Representing the Internal State of Components](arkts-new-local.md)
      - [\@Param Decorator: Inputting External Parameters to Components](arkts-new-param.md)
      - [\@Once: Implementing Initialization Once](arkts-new-once.md)
      - [\@Event Decorator: Component Output](arkts-new-event.md)
      - [\@Monitor Decorator: Listening for Value Changes of the State Variables](arkts-new-monitor.md)
      - [\@Provider and \@Consumer Decorators: Synchronizing Across Component Levels in a Two-Way Manner](arkts-new-Provider-and-Consumer.md)
      - [\\@Computed Decorator: Computed Property](arkts-new-Computed.md)
      - [!! Syntax: Two-Way Binding](arkts-new-binding.md)
  - Rendering Control
      - [Rendering Control Overview](arkts-rendering-control-overview.md)
      - [if/else: Conditional Rendering](arkts-rendering-control-ifelse.md)
      - [ForEach: Rendering Repeated Content](arkts-rendering-control-foreach.md)
      - [LazyForEach: Lazy Data Loading](arkts-rendering-control-lazyforeach.md)
<!--no_check-->
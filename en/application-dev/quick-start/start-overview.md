# Before You Start

This document is intended for novices at developing OpenHarmony applications. It will introduce you to the OpenHarmony project directory structure and application development process, by walking you through a stripped-down, real-world example – building two pages and implementing redirection between them. The following figure shows how the pages look on the DevEco Studio Previewer.

![en-us_image_0000001364254729](figures/en-us_image_0000001364254729.png)

Before you begin, there are two basic concepts that will help you better understand OpenHarmony: UI framework and application model.


## Basic Concepts


### UI Framework

OpenHarmony provides a UI development framework, known as ArkUI. ArkUI provides a full range of capabilities you may need for application UI development, ranging from components to layout calculation, animation, UI interaction, and drawing capabilities.

ArkUI comes with two development paradigms: ArkTS-based declarative development paradigm (declarative development paradigm for short) and JavaScript-compatible web-like development paradigm (web-like development paradigm for short). You can choose whichever development paradigm that aligns with your practice.

| **Development Paradigm**| **Programming Language**| **UI Update Mode**| **Applicable To**                    | **Intended Audience**                          |
| ---------------- | ------------ | -------------- | -------------------------------- | -------------------------------------- |
| Declarative development paradigm  | ArkTS   | Data-driven  | Applications involving technological sophistication and teamwork| Mobile application and system application developers|
| Web-like development paradigm   | JavaScript      | Data-driven  | Applications and service widgets with simple UIs    | Frontend web developers                       |

For more details, see [UI Development](../ui/arkui-overview.md).

### Application Model

The application model is the abstraction of capabilities required by OpenHarmony applications. It provides necessary components and running mechanisms for applications. With application models, you can develop applications based on a unified set of models, making application development simpler and more efficient. For details, see [Elements of the Application Model](../application-models/application-model-composition.md).

Along its evolution, OpenHarmony has provided two application models:

- Feature Ability (FA) model. This model is supported by OpenHarmony API version 7 and 8. It is no longer recommended. For details about development based on the FA model, see [FA Model Development Overview](../application-models/fa-model-development-overview.md).
- Stage model. This model is supported since OpenHarmony API version 9. It is recommended and will evolve for a long time. In this model, classes such as **AbilityStage** and **WindowStage** are provided as the stage of application components and windows. That's why it is named stage model. For details about development based on the stage model, see [Stage Model Development Overview](../application-models/fa-model-development-overview.md).

For details about the differences between the FA model and stage model, see [Interpretation of the Application Model](../application-models/application-model-description.md).

To help you better understand the preceding basic concepts and application development process, **Getting Started** provides a development example that contains two pages in different programming languages and application models.


## Tool Preparation

1. Download the latest version of [DevEco Studio](https://developer.harmonyos.com/cn/develop/deveco-studio).

2. Install DevEco Studio and configure the development environment. For details, see [Setting Up the Development Environment](https://developer.harmonyos.com/en/docs/documentation/doc-guides-V3/environment_config-0000001052902427-V3).

When you are done, you can set out to build your first application in the stage or FA model. For details, see [Building the First ArkTS Application in Stage Model](start-with-ets-stage.md), [Building the First ArkTS Application in FA Model](start-with-ets-fa.md), and [Building the First JavaScript Application in FA Model](start-with-js-fa.md).

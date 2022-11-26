# Preparations

This document is intended for novices at developing OpenHarmony applications. It will introduce you to the OpenHarmony project directory structure and application development process, by walking you through a stripped-down, real-world example – building two pages and implementing redirection between them. The following figure shows how the pages look on the DevEco Studio Previewer.


![en-us_image_0000001364254729](figures/en-us_image_0000001364254729.png)


Before you begin, there are two basic concepts that will help you better understand OpenHarmony: UI framework and ability.


## Basic Concepts


### UI Framework

OpenHarmony provides a UI development framework, known as ArkUI. ArkUI provides a full range of capabilities you may need for application UI development, ranging from components to layout calculation, animation, UI interaction, and drawing capabilities.

ArkUI comes with two development paradigms: ArkTS-based declarative development paradigm (declarative development paradigm for short) and JavaScript-compatible web-like development paradigm (web-like development paradigm for short). You can choose whichever development paradigm that aligns with your practice.

| **Development Paradigm**| **Programming Language**| **UI Update Mode**| **Applicable To**| **Intended Audience**|
| -------- | -------- | -------- | -------- | -------- |
| Declarative development paradigm| ArkTS| Data-driven| Applications involving technological sophistication and teamwork| Mobile application and system application developers|
| Web-like development paradigm| JavaScript| Data-driven| Applications and service widgets with simple UIs| Frontend web developers|

For more details, see [UI Development](../ui/arkui-overview.md).


### Ability

An ability is the abstraction of a functionality that an application can provide. An application may provide various capabilities, and so it can have multiple abilities. These abilities can be deployed together or independently from each other.

The ability framework model has two forms:

- **FA model**: applies to application development using API version 8 and earlier versions. For details, see [FA Model Overview](../ability/fa-brief.md).

- **Stage model**: introduced since API version 9. For details, see [Stage Model Overview](../ability/stage-brief.md).

The project directory structure of the FA model is different from that of the stage model. The stage model only works with the ArkTS programming language.

For details about the differences between the FA model and stage model, see [Ability Framework Overview](../ability/ability-brief.md).

This document provides an ability with two pages. For more information about ability development, see [Ability Development](../ability/ability-brief.md).


## Tool Preparation

1. Download the latest version of [DevEco Studio](https://developer.harmonyos.com/cn/develop/deveco-studio#download).

2. Install DevEco Studio and configure the development environment. For details, see [Setting Up the Development Environment](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-setting-up-environment-0000001263160443).

When you are done, follow the instructions in [Getting Started with ArkTS in Stage Model](start-with-ets-stage.md), [Getting Started with ArkTS in FA Model](start-with-ets-fa.md), and [Getting Started with JavaScript in FA Model](start-with-js-fa.md).

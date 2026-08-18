# Ark Agentic Framework Overview

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wkljy-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=29b612003cb21cb86e324a970110ab8056e0ba6c translatedAt=2026-08-18T01:30:20.981Z pushedAt=2026-08-18T11:20:42.775Z -->

As system agents gradually become the new entry point for users to interact with the operating system, the way users interact is shifting from "opening an app" to "directly expressing their needs." By exposing capabilities and integrating into the system agent ecosystem, apps provide users with a more natural and convenient service experience, while expanding their reach scenarios and usage frequency.

ArkAF (Ark Agentic Framework) is an app capability development framework for the agent era. It provides three capability exposure mechanisms: the intent framework, the Skill framework, and the on-device A2A framework. These mechanisms help developers externalize app capabilities for system agents to invoke, enabling seamless collaboration between apps and agents.

## Basic Concepts

The following are key concepts in the ArkAF development process:

- **Intent**: A capability unit accessed through standardized intents. App developers can expose specific capabilities that can be awakened and executed by system agents by integrating intents.

- **Skill**: A capability unit integrated through standardized Skill integration. By publishing a Skill, app developers can have it recognized and invoked by the system agent, making it suitable for complex-scenario functions.

- **On-device agent**: An app agent. Developers build the app's agent through the on-device A2A framework, which collaborates with the system agent through conversations to complete complex system-level tasks.

## ArkAF Architecture

ArkAF provides three core capability frameworks, offering developers a standardized capability exposure mechanism.

**Figure 1** ArkAF architecture

![ArkAF architecture](figures/arkaf-architecture.png)

The workflow consists of four stages:

**Development and Integration**: Developers select the intent framework, Skill framework, or on-device A2A framework based on business requirements to encapsulate app capabilities in a standardized manner.

**System Registration**: App capabilities are registered with the ArkAF framework for the system agent to discover and index.

**Intelligent Matching**: A user sends a request to the system entry through natural language, and the system agent parses the intent and matches the best app capability.

**Capability Execution**: The system agent invokes the app capability through the ArkAF framework to execute the task and return the result, and then converts the result into natural language to feed back to the user.

## Available Capabilities

- Intent framework

  Provides standardized intent access and intent scheduling management capabilities. By integrating intents, app developers can expose specific capabilities that can be woken up and executed by the system agent. For details, see [Intent Framework Overview](insight-intent-overview.md).

- Skill framework

  Provides standardized Skill access and management capabilities. By publishing Skills, app developers can have their Skills recognized and invoked by the system agent. For details, see [Developing App Skills Based on ArkTS Scripts].

- On-device A2A framework

  Provides standardized agent access and agent scheduling management capabilities. App developers can use the agent framework to develop on-device agents for their apps, which collaborate with the system agent through conversations to complete complex tasks. For details, see [On-device A2A Framework Overview](agent-overview.md).

The three capability exposure mechanisms are compared as follows:

| Capability Type | Core Capability | Trigger Method | Applicable Scenario |
|---------|---------|---------|---------|
| Intent framework | Standardized intent access + intent scheduling management | Woken up and executed by the system agent | Single, explicit capability invocation (such as playing music or navigation) |
| Skill framework | Standardized Skill access + Skill management | Recognized and invoked after the Skill is published | Complex scenario functions (such as navigating home) |
| On-device A2A framework | Standardized agent access + agent scheduling management | Bidirectional communication and negotiation with the system agent | On-device agent development for apps (such as tracking stock information) |

## Features

ArkAF provides the following features to deliver a convenient and efficient development experience for developers:

- Standardized capability integration and management help developers quickly join the system agent ecosystem and reduce development costs.

- App capabilities can be intelligently scheduled by the system agent, providing users with convenient and intelligent service experiences in appropriate scenarios.
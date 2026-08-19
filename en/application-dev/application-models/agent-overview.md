# On-Device A2A Framework Overview

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=0b6e9d14333328189bcb8b2b26c76eff0aae7129 translatedAt=2026-08-18T01:28:27.389Z pushedAt=2026-08-18T03:22:29.734Z -->

## When to Use

As intelligence continues to evolve, an increasing number of apps need to support intelligent interaction and cross-app collaboration. Interactions between traditional apps usually require predefined tightly coupled interfaces, which incur high development costs and poor scalability. Starting from API version 24, the on-device agent framework (on-device A2A) provides a standardized communication and interaction mechanism for agents. This framework extends the on-device capabilities of HMAF (Harmony Agent Framework) and supports the unified A2A protocol specification and on-device-cloud interoperation.

Take the "travel planning" composite task scenario as an example. The collaboration process of each component is as follows:

- Client scheduling: The intelligent assistant, acting as the Agent client, captures the user intent (for example, "Help me plan tomorrow's travel itinerary").

- Dynamic service discovery: The system automatically discovers and connects to multiple Agent servers, such as "weather query", "flight booking", and "hotel recommendation".

- Multi-skill collaborative closed loop: Each server performs capability description, data exchange, and security authentication through the A2A protocol, without needing to know each other's implementation details in advance. Heterogeneous independent skills are dynamically combined to collaboratively complete complex end-to-end business loops.

## Basic Concepts

- Agent: An app component that can autonomously execute tasks and provide intelligent services.

- A2A protocol: An Agent-to-Agent open protocol that defines the specifications for standardized communication and collaboration between agents, including mechanisms such as capability description, data exchange, security authentication, and skill invocation.

- AgentCard: Describes the capabilities and skills of an agent. It contains the agent's basic information, capability description, and skill list.

- AgentSkill: Represents a specific function that an agent can execute. Each skill defines its purpose, tags, input/output patterns, and usage examples, and supports multi-skill composition.

Take the "travel planning" scenario as an example: a travel assistant agent can contain multiple agent skills such as "flight query", "hotel booking", and "attraction recommendation". Each skill describes its input/output specifications to other agents through the agent card. Other agents (such as a voice assistant) read the agent card through the A2A protocol to learn which skills the agent provides and how to invoke them, thereby achieving automated task coordination.

## Working Mechanism

The on-device agent framework adopts a client-server architecture and communicates and collaborates through the Agent management service based on the A2A protocol. The overall working mechanism is as follows:

- **Capability registration**: Developers configure the [AgentCard](../reference/apis-ability-kit/js-apis-inner-application-AgentCard.md) in [agent_config.json](./agent-extension-configuration.md) to describe the agent's name, description, skill list, input/output schema, and other information. The Agent management service manages this registration information.

- **Connection establishment**: A system app (Agent client) <!--Del-->connects to the [AgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md) component of the target agent (Agent server) through the [connectAgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentManager-sys.md#agentmanagerconnectagentextensionability) method of the Agent management service,<!--DelEnd--> establishing a communication channel.

- **A2A communication**: After the connection is established, the client and server perform bidirectional data communication through standardized interfaces. The client <!--Del-->sends requests through [AgentProxy](../reference/apis-ability-kit/js-apis-inner-application-agentProxy-sys.md).<!--DelEnd--> The server receives and processes data in the [onData()](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md#ondata) callback, and then sends data to the client through the [sendData()](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md#senddata) method of [AgentHostProxy](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md).

- **Security authentication** (optional): The client and server support bidirectional security authentication to ensure that both communicating parties are trusted. The client<!--Del--> initiates authentication through [authorize()](../reference/apis-ability-kit/js-apis-inner-application-agentProxy-sys.md#authorize)<!--DelEnd-->, and the server processes the authentication request in the [onAuth()](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md#onauth) callback, then replies to the client through the [authorize()](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md#authorize) method of [AgentHostProxy](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md).

- **Result rendering** (optional): The server can display the agent's UI in the client app through [AgentUIExtensionAbility](../reference/apis-ability-kit/js-apis-agent-agentUIExtensionAbility.md), delivering a rich interactive experience.

- **Disconnection**: After the task is complete, the client<!--Del--> calls [disconnectAgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentManager-sys.md#agentmanagerdisconnectagentextensionability)<!--DelEnd--> to disconnect from the server.

**Figure 1** Agent architecture diagram

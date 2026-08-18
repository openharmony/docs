# AgentExtensionAbility Configuration File

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=249c9154cca3bfd8d247bc281ba57ee999bfbe43 translatedAt=2026-08-18T01:30:06.969Z pushedAt=2026-08-18T11:06:22.495Z -->

[AgentCard](../reference/apis-ability-kit/js-apis-inner-application-AgentCard.md) serves as the "business card" of an Agent and is mainly used to describe the Agent's capabilities. The detailed configuration of an AgentCard is carried by the agent_config.json configuration file.

This configuration file is manually created by developers and is usually located in the `resources/base/profile/` directory of a Module. AgentExtensionAbility can reference this resource file in the metadata configuration item to bind the corresponding AgentCard. An agent_config.json file can be referenced by only one AgentExtensionAbility.

## Fields in the agent_config.json Configuration File

| Tag | Meaning | Data Type | Whether It Can Be Omitted |
| -------- | -------- | -------- | -------- |
| [agentCards](#agentcards) | List of AgentCard configuration information contained in the AgentExtensionAbility. | object array | No |

## agentCards

This tag describes the internal structure of an AgentCard object.

| Name | Meaning | Data Type | Whether It Can Be Omitted |
| -------- | -------- | -------- | -------- |
| agentId | Unique identifier of the Agent. It must be unique within the same app, with a maximum length of 64 bytes. | string | No |
| name | Name of the Agent, generally displayed to users in the UI, for example, "Recipe Assistant". The maximum length is 64 bytes. | string | No |
| description | Description of the Agent's functions. It should clearly describe the core functions and purpose of the Agent to help users understand what the Agent can do, for example, "Helps users search for recipes, plan menus, and provide cooking suggestions". The maximum length is 512 bytes. | string | No |
| [provider](#provider-tag) | Service provider information of the Agent, including the provider's organization name and official website URL, used to identify the source and copyright information of the Agent. | object | Omittable; defaults to empty. |
| version | Version number of the Agent, following the semantic versioning specification (for example, "1.0.0"). The format is defined by the provider. The version number is used to identify the function iteration and compatibility changes of the Agent. The maximum length is 32 bytes. | string | No |
| documentationUrl | URL of the Agent documentation, providing detailed usage documentation, API descriptions, examples, and best practice guides for the Agent to help developers better integrate and use the Agent. The maximum length is 512 bytes. | string | Omittable; defaults to empty. |
| [capabilities](#capabilities-tag) | Set of optional capabilities supported by the Agent, defining other optional capabilities supported by the Agent, such as streaming responses, push notifications, and status history queries. | object | Omittable; defaults to empty. |
| defaultInputModes | Set of input modes supported by the Agent across all [skills](#skills-tag), defining the supported input media types in MIME type format. For example, ["text/plain"] indicates plain text input, ["application/json"] indicates JSON structured data input, and ["image/png"] indicates image input. The inputModes at the [skill](#skills-tag) level override this default setting. The maximum length of each element in the array is 32 bytes. | string array | No |
| defaultOutputModes | Set of output modes supported by the Agent across all [skills](#skills-tag), defining the supported output media types in MIME type format. For example, ["text/plain"] indicates plain text output, ["application/html"] indicates HTML format output, and ["application/json"] indicates JSON data output. The outputModes at the [skill](#skills-tag) level override this default setting. The maximum length of each element in the array is 32 bytes. | string array | No |
| [skills](#skills-tag) | Set of functions provided by the Agent, describing the specific functions or skills that the Agent can perform. Each skill defines its specific purpose, tags, and usage examples. The Agent must contain at least one skill. | object array | No |
| iconUrl | URL of the Agent icon, providing a visual identifier icon for the Agent to be displayed in the UI, enhancing the recognizability and user experience of the Agent. The maximum length is 512 bytes.<br>**Note:** The system does not verify the content of this field. The user must verify the validity and security of iconUrl. | string | No |
| category | Category of the Agent, used to classify and manage Agents. Common categories include "productivity", "entertainment", "education", "finance", and "health". The maximum length is 64 bytes. | string | No |
| type | Type of the Agent card. Both numeric enums and string enum names are supported:<br>- 0: app type, which can also be represented by APP.<br>- 1: atomic service type, which can also be represented by ATOMIC_SERVICE.<!--Del--><br>- 2: low-code type, which can also be represented by LOW_CODE. This field applies only to system apps.<!--DelEnd--> <br>If not specified, the default is APP.<br>**Note:** Supported since API version 26.0.0. | integer or string | Omittable; defaults to 0 (APP). |
| extension | Extension configuration items of the Agent, used to store custom extension configuration information, such as the Agent opening remarks and version protocol number. The format is a JSON string, with a maximum length of 5120 bytes. | string | No |
| [appInfo](#appinfo-tag) | Information about the app where the Agent resides, including the Agent device type and the minimum runnable version, used to locate and manage the AgentExtensionAbility instance. | object | Omittable; see [appInfo](#appinfo-tag) for the default value. |

### provider Tag

This tag describes the internal structure of the provider object.

| Name | Meaning | Data Type | Whether It Can Be Omitted |
| -------- | -------- | -------- | -------- |
| organization | Organization name of the Agent provider, identifying the company, organization, or individual that develops or provides the Agent. The maximum length is 128 bytes. | String | No |
| url | URL of the Agent provider's website or related documentation, providing an HTTPS link to the provider's official website, product page, or related documentation for users to learn more or obtain support. The maximum length is 512 bytes. | String | No |

### capabilities Tag

This tag describes the internal structure of the capabilities object.

| Attribute Name | Meaning | Data Type | Whether It Can Be Omitted |
| -------- | -------- | -------- | -------- |
| streaming | Whether the agent supports streaming responses.<br>true: supported. SSE (Server-Sent Events) streaming responses are supported, and partial results can be returned in real time.<br>false: not supported. Only complete results are returned at once. | boolean value | Omittable. Defaults to false. |
| pushNotifications | Whether the agent supports sending push notifications for asynchronous task updates.<br>true: supported. When the status of a long-running task changes (for example, task completion, failure, or progress update), the agent can proactively push notifications to the client.<br>false: not supported. The client needs to poll to query the task status. | boolean value | Omittable. Defaults to false. |
| stateTransitionHistory | Whether the agent supports viewing the task status change history.<br>true: supported. The client can query the complete status transition records of a task from creation to completion (for example, pending->running->completed).<br>false: not supported. Status history query is not supported. | boolean value | Omittable. Defaults to false. |
| extendedAgentCard | Whether the agent supports providing an extended AgentCard during authentication.<br>true: supported. After authentication, the client can obtain an extended AgentCard that contains additional information (for example, private configuration and advanced capabilities).<br>false: only the basic AgentCard is provided. | boolean value | Omittable. Defaults to false. |
| extension | Protocol extensions supported by the agent, used to store custom extension capability configurations. The format is a JSON string, which can contain protocol-level extension parameters and custom fields agreed upon by the developer and the agent user. The maximum length is 2048 bytes. | string | No |

### skills Tag

This tag describes the internal structure of a skill object.

| Name | Description | Type | Whether It Can Be Omitted |
| -------- | -------- | -------- | -------- |
| id | Unique identifier of the skill. It must be unique within an AgentCard. It is recommended to use a semantic naming format (for example, "route-planner" or "recipe-search") to precisely specify the skill to use in API calls. The maximum length is 64 bytes. | String | No |
| name | Name of the skill, displayed in the UI, for example, "Route Planning" or "Recipe Search". The maximum length is 128 bytes. | String | No |
| description | Detailed description of the skill. It should clearly describe the specific functions, applicable scenarios, and problems that the skill can solve, for example, "Helps users plan travel routes between two points, providing multiple transportation options and real-time traffic information". The maximum length is 512 bytes. | String | No |
| tags | Keyword tags that describe the skill capabilities, used for skill classification, retrieval, and recommendation, for example, ["maps", "routing", "navigation"] or ["cooking", "recipe", "food"]. Tags should be concise and clear for easy understanding and searching. The maximum length of a single element is 32 bytes. | String array | No |
| examples | Example prompts or usage scenarios that the skill can handle. Providing specific examples helps users understand how to use the skill, for example, ["Plan a route from Shanghai to Beijing"]. The maximum length of a single element is 256 bytes. | String array | Omittable. Defaults to empty. |
| inputModes | Input modes supported by the skill, defined in MIME type format, for example, ["text/plain"]. If not set, the AgentCard-level defaultInputModes is used. This field allows customizing input types for a specific skill to override the default settings. The maximum length of each element in the array is 32 bytes. | String array | Omittable. Defaults to empty. |
| outputModes | Output modes supported by the skill, defined in MIME type format, for example, ["text/plain", "application/html", "video/mp4"]. If not set, the AgentCard-level defaultOutputModes is used. This field allows customizing output types for a specific skill to override the default settings. The maximum length of each element in the array is 32 bytes. | String array | Omittable. Defaults to empty. |
| extension | Extension configuration item of the skill, used to store custom extension configurations in JSON string format. It can contain skill-specific parameters and configuration information. The maximum length is 1024 bytes. | String | No |

### appInfo Tag

This tag describes the internal structure of the appInfo object.

| Name | Description | Type | Whether It Can Be Omitted |
| -------- | -------- | -------- | -------- |
| deviceTypes | List of device types supported by the Agent. For the value range, see [deviceTypes](../quick-start/module-configuration-file.md#devicetypes). The device type list configured for the Agent must be a subset of the device type list of the Module to which it belongs. Device types outside the Module are ignored by the system. | string array | Omittable. Defaults to the deviceTypes of the app. |
| minAppVersion | Minimum app version required for running the Agent, in the semantic versioning format (for example, "1.0.0"). It specifies the minimum app version required to run the Agent. Apps with a version lower than this value cannot load and run the Agent correctly. The maximum length is 32 bytes. | string | Omittable. Defaults to empty. |

## Example of the agent_config.json Configuration File

```json5
{
  "agentCards": [
    {
      "agentId": "weather_assistant_001",
      "name": "WeatherAssistant",
      "description": "An intelligent assistant that provides weather query and weather forecast services",
      "provider": {
        "organization": "Example Weather Inc.",
        "url": "https://example.com"
      },
      "version": "1.0.0",
      "documentationUrl": "https://example.com/docs/weather-agent",
      "capabilities": {
        "streaming": true,
        "pushNotifications": true,
        "stateTransitionHistory": true,
        "extendedAgentCard": false,
        "extension": "custom_protocol_v1"
      },
      "defaultInputModes": ["text/plain", "audio/wav"],
      "defaultOutputModes": ["text/plain", "application/json"],
      "skills": [
        {
          "id": "get_weather",
          "name": "Get Weather",
          "description": "Query the real-time weather information of a specified city",
          "tags": ["Weather", "Query", "Real-time"],
          "examples": [
            "What is the weather like in Beijing today",
            "Query the current weather in Shanghai",
            "Check the weather in Shenzhen today for me"
          ],
          "inputModes": ["text/plain"],
          "outputModes": ["text/plain", "application/json"],
          "extension": "custom_protocol_v1"
        },
        {
          "id": "weather_forecast",
          "name": "Weather Forecast",
          "description": "Obtains the weather forecast for a specified city in the coming days",
          "tags": ["Weather", "Forecast", "Future"],
          "examples": [
            "I need the weather forecast for Guangzhou for the next three days",
            "Tell me the weather in Hangzhou tomorrow"
          ],
          "inputModes": ["text/plain"],
          "outputModes": ["text/plain", "application/json"]
        }
      ],
      "iconUrl": "common/weather_icon.png",
      "category": "Life Services",
      "type": "APP", // String enum type
      // "type": "0", // Numeric enum type
      "extension": "custom_protocol_v1",
      "appInfo": {
        "deviceTypes": ["phone", "tablet"],
        "minAppVersion": "1.0.0"
      }
    }
  ]
}
```
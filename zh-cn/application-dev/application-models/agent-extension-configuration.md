# AgentExtensionAbility配置文件说明
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

[AgentCard](../reference/apis-ability-kit/js-apis-inner-application-AgentCard.md)作为Agent的“名片”，主要用于描述Agent的能力。AgentCard的详细配置信息需要通过agent_config.json配置文件来承载。

该配置文件由开发者手动创建，通常位于Module的`resources/base/profile/`目录下。AgentExtensionAbility可以在metadata配置项中引用该资源文件，来绑定对应的AgentCard。一个agent_config.json只能被一个AgentExtensionAbility引用。

## agent_config.json配置文件字段说明

| 标签 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| [agentCards](#agentcards标签) | AgentExtensionAbility所包含的AgentCard配置信息列表。 | 对象数组 | 否 |

## agentCards标签

本标签用于说明AgentCard对象的内部结构。

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| agentId | Agent的唯一标识符，在同一个应用下面agentId不可重复，最大长度为64字节。 | 字符串 | 否 |
| name | Agent的名称，使用方一般用于在UI界面中展示给用户，例如“Recipe Assistant”（食谱助手），最大长度为64字节。 | 字符串 | 否 |
| description | Agent功能的描述，该描述应清晰说明Agent的核心功能和用途，帮助用户理解Agent能做什么，例如“帮助用户搜索食谱、规划菜单并提供烹饪建议”，最大长度为512字节。 | 字符串 | 否 |
| [provider](#provider标签) | Agent的服务提供商信息，包含提供商的组织名称和官方网站URL，用于标识Agent的来源和版权信息。 | 对象 | 可缺省，缺省为空。 |
| version | Agent的版本号，遵循语义化版本规范（如“1.0.0”），格式由提供商定义，版本号用于标识Agent的功能迭代和兼容性变化，最大长度为32字节。 | 字符串 | 否 |
| documentationUrl | Agent文档的URL，提供详细的Agent使用文档、API说明、示例和最佳实践指南，帮助开发者更好地集成和使用该Agent，最大长度为512字节。 | 字符串 | 可缺省，缺省为空。 |
| [capabilities](#capabilities标签) | Agent支持的可选能力集合，定义Agent支持的其他可选能力，如流式响应、推送通知、状态历史查询等。 | 对象 | 可缺省，缺省为空。 |
| defaultInputModes | Agent在所有[skill](#skills标签)上支持的输入模式集，使用MIME类型格式定义支持的输入媒体类型，例如["text/plain"]表示纯文本输入，["application/json"]表示JSON结构化数据输入，["image/png"]表示图片输入。[skill](#skills标签)级别的inputModes会覆盖此默认设置，数组的每一个元素的最大长度为32字节。 | 字符串数组 | 否 |
| defaultOutputModes | Agent在所有[skill](#skills标签)上支持的输出模式集，使用MIME类型格式定义支持的输出媒体类型，例如["text/plain"]表示纯文本输出，["application/html"]表示HTML格式输出，["application/json"]表示JSON数据输出。[skill](#skills标签)级别的outputModes会覆盖此默认设置，数组的每一个元素的最大长度为32字节。 | 字符串数组 | 否 |
| [skills](#skills标签) | Agent提供的功能集合，描述Agent可以执行的特定功能或技能，每个技能定义了具体的用途、标签和使用示例，Agent必须至少包含一个技能。 | 对象数组 | 否 |
| iconUrl | Agent图标的URL，提供Agent的可视化标识图标，用于在UI界面中展示，增强Agent的辨识度和用户体验，最大长度为512字节。<br>**说明**：系统不校验该字段内容，使用方需自行验证iconUrl的合法性和安全性。 | 字符串 | 否 |
| category | Agent的类别，用于对Agent进行分类管理，常见的类别包括：“productivity”（生产力）、“entertainment”（娱乐）、“education”（教育）、“finance”（金融）、“health”（健康）等，最大长度为64字节。 | 字符串 | 否 |
| type | Agent卡片的类型。支持数值枚举和字符串枚举名称：<br>- 0：表示应用型，取值也可采用APP。<br>- 1：表示原子化服务型，取值也可采用ATOMIC_SERVICE。<!--Del--><br>- 2：表示低代码型，取值也可采用LOW_CODE。该字段仅适用于系统应用。<!--DelEnd--> <br>如果未指定，默认为APP类型。<br>**说明**：从API版本26.0.0开始支持。 | 整数或字符串 | 可缺省，缺省为0（APP）。 |
| extension | Agent的扩展配置项，用于存储自定义的扩展配置信息，如Agent开场白、版本协议号等，格式为JSON字符串，最大长度为5120字节。 | 字符串 | 否 |
| [appInfo](#appinfo标签) | Agent所在的应用信息，包含Agent设备类型和可运行的最低版本号，用于定位和管理AgentExtensionAbility实例。 | 对象 | 可缺省，缺省值见[appInfo](#appinfo标签)。 |

### provider标签

本标签用于说明provider对象的内部结构。

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| organization | Agent提供商的组织名称，标识开发或提供该Agent的公司、组织或个人名称，最大长度为128字节。 | 字符串 | 否 |
| url | Agent提供商的网站或相关文档的URL，提供指向提供商官方网站、产品页面或相关文档的HTTPS链接，用于用户了解更多信息或获取支持，最大长度为512字节。 | 字符串 | 否 |

### capabilities标签

本标签用于说明capabilities对象的内部结构。

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| streaming | Agent是否支持流式响应。<br>true：表示支持SSE（Server-Sent Events）流式响应，可以实时返回部分结果。<br>false：表示不支持流式，仅支持一次性返回完整结果。 | 布尔值 | 可缺省，缺省为false。 |
| pushNotifications | Agent是否支持为异步任务更新发送推送通知。<br>true：表示支持，当长时间运行的任务状态发生变化时（如任务完成、失败或进度更新），Agent可以主动推送通知给客户端。<br>false：表示不支持，客户端需要轮询查询任务状态。 | 布尔值 | 可缺省，缺省为false。 |
| stateTransitionHistory | Agent是否支持查看任务状态变化历史。<br>true：表示支持，客户端可以查询任务从创建到完成的完整状态转换记录（如pending->running->completed）。<br>false：表示不支持状态历史查询。 | 布尔值 | 可缺省，缺省为false。 |
| extendedAgentCard | Agent是否支持在认证时提供扩展的AgentCard。<br>true：表示支持，客户端在通过认证后可以获取包含额外信息（如私有配置、高级能力）的扩展AgentCard。<br>false：表示仅提供基础AgentCard。 | 布尔值 | 可缺省，缺省为false。 |
| extension | Agent支持的协议扩展，用于存储自定义的扩展能力配置，格式为JSON字符串，可以包含协议级别的扩展参数和自定义字段，由开发者和Agent使用方约定，最大长度为2048字节。 | 字符串 | 否 |

### skills标签

本标签用于说明skill对象的内部结构。

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| id | skill的唯一标识符，在一个AgentCard中必须唯一，建议使用具有语义的命名格式（如“route-planner”、“recipe-search”），用于在API调用中精确指定要使用的技能，最大长度为64字节。 | 字符串 | 否 |
| name | skill的名称，用于在UI界面中展示，例如“Route Planning”（路线规划）或“Recipe Search”（食谱搜索），最大长度为128字节。 | 字符串 | 否 |
| description | skill的详细描述，应清晰说明该技能的具体功能、适用场景和能解决的问题，例如“帮助用户规划两点之间的出行路线，提供多种交通方式选择和实时路况信息”，最大长度为512字节。 | 字符串 | 否 |
| tags | 描述skill能力的关键字标签，用于技能分类、检索和推荐，例如["maps", "routing", "navigation"]或["cooking", "recipe", "food"]，标签应简洁明了，便于用户理解和搜索，单个元素的最大长度为32字节。 | 字符串数组 | 否 |
| examples | skill可以处理的示例提示或使用场景，提供具体的示例可以帮助用户理解如何使用该技能，例如["规划从上海到北京的路线"]，单个元素的最大长度为256字节。 | 字符串数组 | 可缺省，缺省为空。 |
| inputModes | skill支持的输入模式，使用MIME类型格式定义，例如["text/plain"]。如果未设置，将使用AgentCard级别的defaultInputModes，该字段允许为特定技能自定义输入类型，覆盖默认设置，数组的每一个元素的最大长度为32字节。 | 字符串数组 | 可缺省，缺省为空。 |
| outputModes | skill支持的输出模式，使用MIME类型格式定义，例如["text/plain", "application/html", "video/mp4"]。如果未设置，将使用AgentCard级别的defaultOutputModes，该字段允许为特定技能自定义输出类型，覆盖默认设置，数组的每一个元素的最大长度为32字节。 | 字符串数组 | 可缺省，缺省为空。 |
| extension | skill的扩展配置项，用于存储自定义扩展配置，格式为JSON字符串，可以包含技能特有的参数和配置信息，最大长度为1024字节。 | 字符串 | 否 |

### appInfo标签

本标签用于说明appInfo对象的内部结构。

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| deviceTypes | Agent支持的设备类型列表，取值范围参考[deviceTypes](../quick-start/module-configuration-file.md#devicetypes标签)。Agent配置的设备类型列表需要为所属Module设备类型列表的一个子集，如果配置了Module之外的设备类型，系统将会忽略掉。 | 字符串数组 | 可缺省，缺省为应用的deviceTypes。 |
| minAppVersion | Agent运行的最低应用版本要求，使用语义化版本号格式（如“1.0.0”），指定运行该Agent所需的应用最低版本，低于此版本的应用将无法正确加载和运行该Agent，最大长度为32字节。 | 字符串 | 可缺省，缺省为空。 |

## agent_config.json配置文件示例

```json5
{
  "agentCards": [
    {
      "agentId": "weather_assistant_001",
      "name": "WeatherAssistant",
      "description": "提供天气查询和天气预报服务的智能助手",
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
          "name": "获取天气",
          "description": "查询指定城市的实时天气信息",
          "tags": ["天气", "查询", "实时"],
          "examples": [
            "今天北京天气怎么样",
            "查询上海当前的天气",
            "帮我看看深圳今天天气如何"
          ],
          "inputModes": ["text/plain"],
          "outputModes": ["text/plain", "application/json"],
          "extension": "custom_protocol_v1"
        },
        {
          "id": "weather_forecast",
          "name": "天气预报",
          "description": "获取指定城市未来几天的天气预报",
          "tags": ["天气", "预报", "未来"],
          "examples": [
            "我需要广州未来三天的天气预报",
            "告诉我杭州明天的天气"
          ],
          "inputModes": ["text/plain"],
          "outputModes": ["text/plain", "application/json"]
        }
      ],
      "iconUrl": "common/weather_icon.png",
      "category": "生活服务",
      "type": "APP", // 字符串枚举类型
      // "type": "0", // 数值枚举类型
      "extension": "custom_protocol_v1",
      "appInfo": {
        "deviceTypes": ["phone", "tablet"],
        "minAppVersion": "1.0.0"
      }
    }
  ]
}
```

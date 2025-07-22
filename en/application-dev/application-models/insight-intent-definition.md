# Intent Development Overview
There are two methods to define intents.

| Method| Description| Usage Scenario|
| --- | --- | --- |
| [Accessing Standard Intents](#accessing-standard-intents)| System-provided, predefined invocation specifications with unified definitions for intent parameter and execution result formats. The system matches intents based on the **schema** and **intentVersion** fields in the decorator, referencing a JSON Schema file stored in the SDK.| Use for common functions already defined in standard intents, such as playing music or navigation.|
| [Creating Custom Intents](#creating-custom-intents)| Developer-defined invocation specifications for scenarios not covered by standard intents.| Necessary when your application's feature is not included in the standard intents.|

## Accessing Standard Intents
If your application's feature aligns with predefined standard intents (for example, playing music or navigation), you can directly use the standard intents to avoid redundant definitions.

For the current standard intent specifications, see [Appendix: Standard Intent Access Specifications](insight-intent-access-specifications.md).

Each intent contains the following elements:
- Intent name: unique identifier of an intent.
- Intent version: for compatibility control.
- Parameter type definition: unified parameter format.
- Result type definition: unified execution result format.

## Creating Custom Intents
If standard intents do not cover your application's features, you can create custom intents. The system parses the intent descriptions and parameter specifications, triggering execution when it matches user semantics. Custom intents are defined via [IntentDecoratorInfo](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#intentdecoratorinfo) and its child classes, including:
- LLM description: a precise, comprehensive natural language description of the intent's function for semantic parsing. It should cover capabilities, definitions, and constraints.
- Parameter type definition: custom parameter format following the JSON Schema specification, including parameter descriptions, types, and whether they are mandatory or optional.
- Result type definition: custom execution result format following the JSON Schema specification, specifying the result type.

For example, for an application with weather query capabilities, the model description could be: "Query real-time weather conditions of a geographical location by inputting longitude and latitude coordinates."  

# JS API Reference Template

> *Writing Instructions*
>
> 0.1 - Delete all writing instructions after you finish the writing.
>
> 0.2 - Upload JS API reference documents to **docs/en/application-dev/reference/apis**. If these documents contain figures, upload the figures to the **figures** folder.
>
> 0.3 - Use a .d.ts file for a JS API reference document. **The file name must be in the following format: js-apis-<moduleName>.md**. Examples:
> 	For @ohos.multimedia.audio in the Media subsystem, the file name is **js-apis-audio.md**.
> 	For @ohos.telephony.sms in the Telephony subsystem, the file name is **js-apis-sms.md**.
>
> 0.4 - After uploading a JS API reference document, update the **Readme-EN.md** file in **docs/en/application-dev/reference/apis**.
>
> 0.5 - **Document Title**: Use phrases that summarize the module functionalities.
>
> 0.6 - Use the document title as the level-1 heading. Use the attributes, functions, classes, interfaces, enums, and types under the namespace as level-2 headings. Use the attributes and functions under classes as level-3 headings.
>
> **Version Description**
>
> 0.7 - **When introducing an API to an existing module, use the \<sup> tag to mark its earliest version.**
> 	Example: For an existing module of API 6, if an attribute is added in API 7, suffix the \<sup> tag to the name of the new attribute, for example, **newAttribute<sup>7+</sup>**.
> 	If a method is added, suffix the \<sup> tag to the method name, for example, **sim.getSimIccId<sup>7+</sup>**. The processing of new interfaces, classes, and enums is similar.
>
> 0.8 - **Deprecated content**: Do not delete the deprecated content directly from the document. Instead, suffix **deprecated** as a superscript to the content, and use the greater-than symbol (>) to introduce the substitute method plus the corresponding link.
> 	Example: abandonmentMethod<sup>(deprecated) </sup>
>
> > This APIs is no longer maintained since API version 7. You are advised to use [newMethod](#newMethod) instead.
>
> 0.9 - For **empty APIs that will be implemented only in the MR version**, add the following information to the interface description:
> This API is defined but not implemented in OpenHarmony 3.1 Release. It will be available for use in OpenHarmony 3.1 MR.
>
> **Required Permissions, System Capabilities, and System APIs**
>
> 0.10 - **Required permissions**: Maintain consistency with the code implementation. State the required permissions at the level of methods, enumerations, and attributes. Format:
>      (Permissions that can be requested by all applications) **Required permissions**: ohos.permission.xxxx  
>      (Permissions that can be requested only by system applications) **Required permissions**: ohos.permission.xxxx (available only to system applications)
>
> 0.11 - **System capabilities**:
>   Add the following information for each function: **System capability**: SystemCapability.xxx.xxx
>   There are two cases for the information about system capabilities added to each table (attributes, enums, constants, and variables).
>   Add the following description if all the items in a table require the same system capabilities:
>   SystemCapability.xxx.xxx
>   Add the following description if the items in a table require different system capabilities:
>   The items in the table below require different system capabilities. For details, see the table.
>
> 0.12 - **System APIs**: Add the following description for system APIs: This is a system API and cannot be called by third-party applications.
> The following describes the instructions for writing a specific API.

***
> *Writing Instructions*
>
> 1.1 - Use the greater-than symbol (>) to describe the initial version of an API.
>
> 1.2 - A module has only one initial version.
>
> 1.3 - Use the following sentence: "The initial APIs of this module are supported since API version ***x***. Newly added APIs will be marked with a superscript to indicate their earliest API version." Change ***x*** to the actual version.



> **Note**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

Describe the module from its functionalities, use cases, and use suggestions in this section.



## Modules to Import

> *Writing Instructions*
>
> 2.1 - Write the modules to import based on the actual conditions. Provide the **import** statement in the form of a code segment.
>
> 2.2 - If no module needs to be imported, change "Modules to Import" to "How to Use" and provide a usage description.
> 	Example of **How to Use**:
> 	Before using the **AbilityContext**, obtain the **Context** object through **[getContext()]**(***API-reference***.md).
>
> ```js
> import ability_featureAbility from '@ohos.ability.featureAbility';
> var context = ability_featureAbility.getContext();
> ```

```js
import call from '@ohos.telephony.call';
```


## Attributes

> *Writing Instructions*
>
> 4.1 - Optional. Delete this heading if there is no attribute.
>
> 4.2 - If an attribute is of a custom type, create a link to the corresponding interface or enum.
>
> 4.3 - For a readable attribute, if it has a limited number of values with special meanings, enumerate the values.
>
> 4.4 - For a writable attribute, if only fixed fields are supported, describe them.
>
> 4.5 - If the items in the table require different system capabilities, add the following description: The items in the table below require different system capabilities. For details, see the table. Then, describe the system capabilities for each item. See [Enums](#enums).

**System capability**: SystemCapability.xxx.xxx (Mandatory)

| Name            | Type                                     | Readable| Writable| Description                                      |
| ---------------- | ----------------------------------------- | ---- | ---- | ------------------------------------------ |
| pluggedType      | [BatteryPluggedType](#BatteryPluggedType) | Yes  | No  | Charger type of the current device.            |
| isBatteryPresent | boolean                                   | Yes  | No  | Whether the battery is supported or present.|

## Enums

> *Writing Instructions*
>
> 5.1 - Optional. Delete this heading if there is no enum. If there are multiple enums, describe them in separate level-2 headings. To create a level-2 heading, use two number signs (#).
>
> 5.2 - Use the actual enum name as the level-2 heading, for example, **BatteryHealthState**.

Provide a brief description of the enum type. Example: Enumerates charger types.

**System capability**: The items in the table below require different system capabilities. For details, see the table. (Mandatory)

| Name| Value  | Description                                                        |
| ---- | ---- | ------------------------------------------------------------ |
| NONE | 1    | Unknown type.<br>**System capability**: SystemCapability.xxx.xxx (mandatory)|

## Methods

> *Writing Instructions*
>
> 6.1 - Optional. Delete this heading if there is no method. If there are multiple methods, describe them in separate level-2 headings. To create a level-2 heading, use two number signs (#).
>
> 6.2 - Use the actual method name, in the format of ClassName.methodName, as the level-2 heading. For a subscription method, add the subscription event to the method name.
> 	Example of a common method: sim.getSimIccId
> 	Example of a subscription method: sim.on('exampleEvent')
>
> 6.3 - **Method calling mode**: The description must be the same as that in the .d.ts file. The description must include the parameter type, parameter name, and return value type.
> 	Example: getNetworkState(slotId: number, callback: AsyncCallback\<NetworkState>): void
> 	Note: The angle bracket (<>) may be identified as a label and not displayed. To ensure normal display, you can either add a backslash (\\) (in the format of "\\<>") or use escape characters \&lt; and \&gt;.
>
> 6.4.1 - **Method description**: Describe the features implemented by the method and include the prerequisites for using the method, the impact of the method, and the permissions and system capabilities required to use the method. (*Example of prerequisites: This method can be called only after the xx method is called; you must ensure that the connection to the Internet is normal. Example of impact: xx does not take effect after this method is called.*)
>
> 6.4.2 - **Asynchronous method**: If there are asynchronous methods, describe their return type in the method description. The return type can be a callback function or a **Promise** instance.
>
> 6.4.3 - **Line feed in a table**: Use \<br> for line feed.

Provide the method name in the following format: (**static** if it is a static method) methodName (parameterName1: parameterType1, parameterName2: parameterType2, ...): returnValueType

Describe the method. For details, see 6.4.1 and 6.4.2.

**Required permissions**: ohos.permission.xxx (Delete this part if no permission is involved. If a system permission is required, specify it.)

**System capability**: SystemCapability.xxx.xxx (mandatory)

**Parameters** (Optional. Delete this heading if there is no parameter.)

| Name      | Type                                         | Mandatory| Description                                                        |
| ------------ | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| parameterOne | number \| string \| [CustomType](#CustomType) | Yes  | Describe the parameter. Provide the value range and recommended value. If there is a fixed format, provide a format example, especially for the URI.<br>Provide a link for each custom parameter type.|
| callback     | Callback\<Array<[CustomType](#CustomType)>>   | No  | Describe the parameter. For an optional parameter, describe the consequences if it is not specified.<br>Example: If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.|

**Return value** (Optional. Delete this heading if there is no return value.)

| Type                                      | Description                                        |
| ------------------------------------------ | -------------------------------------------- |
| string                                     | Describe the return value, for example, what can be done after the return value is obtained.|
| Promise\<Array<[CustomType](#CustomType)>> | Describe the return value, for example, what is obtained through the **Promise** instance.         |

**Example**

```js
// This part is mandatory.
// Check all sample code provided in the example.
// Minor errors such as missing symbols and variable inconsistency are unacceptable.
// Declare all variables that are used.
// Write an actual case that can be easily used, rather than the parameter names themselves.
// Use comments to describe the content that are not user-defined.
// Example: var result = xxx.createExample(parameterOne); // parameterOne is automatically obtained by scanning.
```

## Classes/Interfaces

> *Writing Instructions*
>
> 7.1 - Optional. Delete this heading if there is no class or interface. If there are multiple classes or interfaces, describe them in multiple level-2 headings. To create a level-2 heading, use two number signs (#).
>
> 7.2 - Use the actual class or interface name as the level-2 heading.
>
> 7.3 - If the class or interface contains both attributes and methods, write the attributes above the methods. Write their actual names in separate level-3 headings.
> 	If the class of interface contains only attributes, you do not need to create a level-3 heading. Instead, use a table to display the attributes. For details, see [CustomType](#CustomType).

Describe the class or interface. If there are usage restrictions, describe them as well, for example, whether there is a prerequisite and whether an instance needs to be created by using any method.

### Attributes

> *Writing Instructions*
>
> Except that a level-3 heading is used, other instructions are the same as those listed under [Attributes](#Attributes).

### Methods in Classes/Interfaces

> *Writing Instructions*
>
> 7.4 - Use the actual method name as the level-3 heading. **Do not add a prefix**. For a subscription method, add the corresponding subscription event to the method name.
> 	Example of a common method: getSimIccId
> 	Example of a subscription method: on('exampleEvent')
> The other instructions are the same as those stipulated in [Methods](#Methods).

Describe the method calling mode. For details, see 6.3.

Describe the method. For details, see 6.4.1 and 6.4.2.

**Required permissions**: ohos.permission.xxx (Delete this part if no permission is involved. If a system permission is required, specify it.)

**System capability**: SystemCapability.xxx.xxx (mandatory)

**Parameters** (Optional. Delete this heading if there is no parameter.)

| Name      | Type                                         | Mandatory| Description                                                        |
| ------------ | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| parameterOne | number \| string \| [CustomType](#CustomType) | Yes  | Describe the parameter. Provide the value range and recommended value. If there is a fixed format, provide a format example, especially for the URI.<br>Provide a link for each custom parameter type.|
| callback     | Callback\<Array<[CustomType](#CustomType)>>   | No  | Describe the parameter. For an optional parameter, describe the consequences if it is not specified.<br>Example: If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.|

**Return value** (Optional. Delete this heading if there is no return value.)

| Type                                      | Description                                        |
| ------------------------------------------ | -------------------------------------------- |
| string                                     | Describe the return value, for example, what can be done after the return value is obtained.|
| Promise\<Array<[CustomType](#CustomType)>> | Describe the return value, for example, what is obtained through the **Promise** instance.         |

**Example**

```js
// This part is mandatory.
// Check all sample code provided in the example.
// Minor errors such as missing symbols and variable inconsistency are unacceptable.
// Declare all variables that are used.
// Write an actual case that can be easily used, rather than the parameter names themselves.
// Use comments to describe the content that are not user-defined.
// Example: var result = xxx.createExample(parameterOne); // parameterOne is automatically obtained by scanning.
```

## CustomType

The following is an example of the custom type of a key-value pair.
**System capability**: SystemCapability.xxx.xxx (Mandatory)

| Name        | Type               | Readable| Writable| Description                                                        |
| ------------ | ------------------- | ---- | ---- | ------------------------------------------------------------ |
| parameterUrl | string              | Yes  | Yes  | Media output URI. The following types of URIs are supported:<br>1. Relative path whose protocol type is internal. Examples:<br>Temporary directory: internal://cache/test.mp4<br><br>2. Absolute path. Examples:<br>file:///data/data/ohos.xxx.xxx/files/test.mp4<br> |
| parameterOne | [CustomEnum](#enums) | Yes  | Yes  | Describe the attributes. The requirements are similar to those for the parameter description.                              |


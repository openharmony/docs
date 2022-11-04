# API Reference Template

## General Writing Instructions
> **NOTE**
>
> Delete all writing instructions after you finish the writing.

|      | Item                           | Writing Instruction                                                        |
| ---- | --------------------------------- | ------------------------------------------------------------ |
| 1    | Customer-oriented mindset               | **Stand in the shoes of developers and provide the use cases, parameter selection principles, recommendations/tips, sample code, and anything else that a developer will need to develop the API.**|
| 2    | Upload path                         | Upload markdown files to `docs/en/application-dev/reference/apis`.<br>Upload images to `docs/en/application-dev/reference/apis/figures`. In addition, reference the image path in the markdown file as follows: `![](figures/exampleImage.jpg)`, `![](figures/exampleImage.png)`, or `![](figures/exampleImage.gif)`.|
| 3    | File name                         | Provide one JS API reference document for each d.ts file. Name the file in the format of `js-apis-exampleModule.md`, where `exampleModule` is a variable and must be the same as the actual module name.<br>Examples:<br>For @ohos.multimedia.audio in the Multimedia subsystem, the JS API file name is `js-apis-audio.md`.<br>For @ohos.telephony.sms in the Telephony subsystem, the JS API file name is `js-apis-sms.md`.|
| 4    | Directory update                         | After uploading an API reference document, update the `Readme-EN.md` file in `docs/en/application-dev/reference/apis`.|
| 5    | Document structure                         | - Module description<br>- Initial version description<br>- Modules to Import/Usage description<br>- API description (attributes, methods, enums, and custom types)<br>  The order in which APIs are described in the document must be consistent with that in which they appear in the code. If some APIs have a logical sequence, pay attention to their sequence in the API reference document.|
| 6    | Initial version description                     | 1. Use the greater-than sign (`>`) followed by a space to indent the description about the initial version of the module. Unless otherwise marked, all APIs in the module have the same initial version.<br>2. When introducing an API to an existing module, use the `<sup>` tag to mark its earliest version. The format is `<sup>versionNumber+</sup>`, for example, `<sup>7+</sup>`.<br>If an attribute is added to an existing module, suffix the `<sup>` tag to the new attribute name, for example, `newAttribute<sup>7+</sup>`.<br>If a method is added to an existing module, suffix the `<sup>` tag to the method name, for example, `sim.getSimIccId<sup>7+</sup>`. The same rule applies to new interfaces, classes, and enums. |
| 7    | Deprecated API description                     | Do not delete the deprecated content from the document. Instead, suffix `deprecated` as a superscript to the content, and use the greater-than sign (`>`) to introduce the substitute API plus a link to the API description.<br>Example: abandonmentMethod<sup>(deprecated)</sup><br>> This API is no longer maintained since API version 7. You are advised to use [newMethod]\(#newmethod) instead.|
| 8    | Permission description                         | Provide the same permission description as that defined in the code for each method, enum, and attribute.<br>1. If a specific permission required for using the API can be requested only by system applications, provide the description in the following format:<br>**Required permissions**: ohos.permission.examplePermission (available only to system applications)<br>2. If a specific permission required for using the API can be requested by all applications, provide the description in the following format:<br>**Required permissions**: ohos.permission.examplePermission<br>3. If multiple permissions are required for using the API, provide the permissions with `and` or `or` in the following format:<br>**Required permissions**: ohos.permission.examplePermissionA and ohos.permission.examplePermissionB<br>**Required permissions**: ohos.permission.examplePermissionA or ohos.permission.examplePermissionB|
| 9   | @syscap                           | 1. Provide a description for every API in the following format, wherein *A.B* indicates a specific system capability.<br>**System capability**: SystemCapability.*A.B*<br>2. There are two cases for adding system capability information to a table (of attributes, enums, constants, or variables).<br>1) If all the items in a table require the same system capability, add the following information to the front of the table:<br>**System capability**: SystemCapability.*A.B*<br>2) If the items in a table require different system capabilities, list the system capability for each item in the table. |
| 10   | @system api                       | 1. If all APIs of the module are system APIs, add the following sentence to the next line of the initial version description:<br>The APIs provided by this module are system APIs.<br>2. If an API is a system API that can be used only by original equipment manufacturers (OEMs), add the following sentence to the API description:<br>**System API**: This is a system API.|
| 11   | @FAModelOnly<br>@StageModelOnly  | 1. If a module is implemented only for a specific ability model, add the following sentence to the next line of the initial version description:<br>The APIs of this module can be used only in the FA model.<br>Or<br>The APIs of this module can be used only in the stage model.<br>2. If an API is implemented only for a specific ability model, add the following sentence to the API description:<br>**Model restriction**: This API can be used only in the FA model.<br/>Or<br/>**Model restriction**: This API can be used only in the stage model.|
| 12   | Asynchronous methods (callback and promise)| Use the following sentences for callback methods.<br>Method introduction: *Describe the method.* This API uses an asynchronous callback to return the result.<br>Parameter description:<br>**callback\<boolean>**: Callback used to return the result. The value `true` indicates *something*, and `false` indicates the opposite.<br>**callback\<Object>**: Callback used to return *something*. Example: Callback used to return the `AudioCapturer` object.   <br>**AsyncCallback\<void>**: Callback used to return the result. If the operation (or a specific operation description) is successful, `err` is `undefined`; otherwise, `err` is an `Error` object.<br>**AsyncCallback\<Object x>**: Callback used to return the result. If the operation (or a specific operation description) is successful, `err` is `undefined`, and `data` is the *x* object obtained; otherwise, `err` is an `Error` object.<br>Use the following sentences for promise methods.<br>Method introduction: *Describe the method.* This API uses a promise to return the result.<br>Parameter description:<br>**Promise\<boolean>**: Promise used to return the result. The value `true` indicates *something*, and `false` indicates the opposite.<br>**Promise\<Object>**: Promise used to return *something*. Example: Promise used to return the `AudioCapturer` object.   <br>**Promise\<void>**: Promise that returns no value.|
| 13   | Sample code programming language                     | Use code blocks to provide sample code and mark the programming language.<br>Use `js` as the mark if both JS and eTS can be used, and use `ts` if only eTS can be used.|
| 14   | Link                         | Link format: [Link text]\(Link content)<br>Cross-folder link format: [markdown file name]\(\.\./../xxx/xxx.md). One `./` indicates one upper-level folder.<br>Intra-topic link format: [Interface A<sup>7+</sup>]\(#xxxa7). The text in the intra-topic link must be the same as the title to be linked. In the link, all letters must be in lowercase, and no special character (except the hyphen) or tag is included.|

The following describes the instructions for writing a specific API reference document.

***

# Document Title

> *Writing Instructions*
>
> 1. **Document title**: Use phrases that summarize the module functionalities. Examples: `Ability` and `SIM Card Management`
> 2. **Heading levels**: Use the document title as the level-1 heading, which is prefixed with `#` followed by a space. Use the attributes, functions, classes, interfaces, enums, and types under the namespace as level-2 headings, which are prefixed with `##` followed by a space. Use the attributes and functions under classes as level-3 headings, which are prefixed with `###` followed by a space.
> 3. **Initial version description**: Use the greater-than symbol (`>`) to indent the description about the initial version of the module. Use a line break after **NOTE**. <br>Place the version description after the module description. A module has only one initial version. <br>Use the following sentence: "The initial APIs of this module are supported since API version *x*. Newly added APIs will be marked with a superscript to indicate their earliest API version." Change ***x*** to the actual version number.

Describe the module from its functionalities, use cases, and recommendations in this section. 

**Example 1**: description of the background task management module

This module provides background task management.
If a service needs to be continued when the application or service module is running in the background (not visible to users), the application or service module can request a transient task or continuous task for delayed suspension based on the service type.

**Example 2**: description of the call module

The call module provides call management functions, including making calls, redirecting to the dial screen, obtaining the call status, and formatting phone numbers.
To subscribe to the call state, use observer.on('callStateChange').

**Example 3**: description of the distributed data management module

The distributed data management module provides collaboration between databases of different devices for applications.
The APIs provided by distributed data management can be used to save data to the distributed database and perform operations such as adding, deleting, modifying, querying, and synchronizing data in the distributed database.

**Example 4**: description of the linear container ArrayList module

`ArrayList` is a linear data structure that is implemented based on arrays. `ArrayList` can dynamically adjust the capacity based on project requirements. It increases the capacity by 50% each time.
Similar to `ArrayList`, `Vector` is also implemented based on arrays and can dynamically adjust the capacity. It increases the capability by 100% each time.
When compared with `LinkedList`, `ArrayList` is more efficient in random access but less efficient in the addition or removal operation, because its addition or removal operation affects the position of other elements in the container.
You are advised to use `ArrayList` when elements in a container need to be frequently read.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

> *Writing Instructions*
>
> 1. Write the modules to import based on the actual conditions. Provide the **import** statement in the form of a code block.
>
> 2. If no module needs to be imported, change "Modules to Import" to "Usage" and provide a usage description. <br>Example of **Usage**:<br>
>    Before using the `AbilityContext`, obtain the `Context` object through \[getContext()]\(*API-reference*.md)\.
>
> ```js
>    import ability_featureAbility from '@ohos.ability.featureAbility';
>    var context = ability_featureAbility.getContext();
> ```

```js
import call from '@ohos.telephony.call';
```

## Attributes

> *Writing Instructions*
>
> 1. This section is optional. Delete it if there is no attribute.
>
> 2. If an attribute is of a custom type, create a link to the corresponding interface or enum.
>
> 3. For a readable attribute, if it has a limited number of values with special meanings, enumerate the values.
>
> 4. For a writable attribute, if only fixed fields are supported, describe them.

**System capability**: SystemCapability.*A.B* (This part is mandatory.)

| Name            | Type                                     | Readable| Writable| Description                                      |
| ---------------- | ----------------------------------------- | ---- | ---- | ------------------------------------------ |
| pluggedType      | [BatteryPluggedType]\(#batterypluggedtype) | Yes  | No  | Charger type of the current device.            |
| isBatteryPresent | boolean                                   | Yes  | No  | Whether the battery is supported or present.|

## Methods

> *Writing Instructions*
>
> 1. This section is optional. Delete it if there is no method. If there are multiple methods, describe them in separate level-2 headings, prefixed with `##` followed by a space.
>
> 2. Use the actual method name, in the format of ClassName.methodName, as the level-2 heading. For a subscription method, add the subscription event to the method name.
>
>    Example of a common method: sim.getSimIccId
>    Example of a subscription method: sim.on('exampleEvent')
>
> 3. **Method calling mode**: The description must be the same as that in the .d.ts file and include the parameter type, parameter name, and return value type.
>    Example: getNetworkState(slotId: number, callback: AsyncCallback\<NetworkState>): void
>    Note: The angle bracket (<>) may be identified as a label and not displayed. To ensure normal display, you can either add a backslash (\\) (in the format of "\\<>") or use escape characters \&lt; and \&gt;.
>
> 4. **Method description**: Describe the features implemented by the method and include the prerequisites for using the method, the impact of the method, and the permissions and system capabilities required to use the method. (*Example of prerequisites: This method can be called only after the xx method is called; you must ensure that the connection to the Internet is normal. Example of impact: xx does not take effect after this method is called.*)
>
> 5. **Asynchronous methods**: If there are asynchronous methods, describe their return type in the method description. For details, see item 14 in "General Writing Instructions."
>
> 6. **Line feed in a table**: Use \<br> for line feed.

Provide the method name in the following format: (`static` if it is a static method) methodName (parameterName1: parameterType1, parameterName2: parameterType2, ...): returnValueType

Describe the method. For details, see the fourth and fifth points in "Writing Instructions" above.

**Model restriction**: This API can be used only in the FA model. (Delete this part if it is not involved.)

**System API**: This is a system API. (Delete this part if it is not involved.)

**Required permissions**: ohos.permission.examplePermission (Delete this part if no permission is involved. If a system permission is required, specify it.)

**System capability**: SystemCapability.*A.B* (This part is mandatory.)

**Parameters** (This part is optional. Delete it if there is no parameter.)

| Name      | Type                                         | Mandatory| Description                                                        |
| ------------ | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| parameterOne | number \| string \| [CustomType](#customtype) | Yes  | Describe the parameter. Provide the value range and recommended value. If there is a fixed format, provide a format example, especially for the URI.<br>Provide a link for each custom parameter type.|
| callback     | Callback\<Array<[CustomType](#customtype)>>   | No  | Describe the parameter. For an optional parameter, describe the consequences if it is not specified.<br>Example: If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.<br>For details about how to write callback methods, see item 14 in "General Writing Instructions."|

**Return value** (This part is optional. Delete it if there is no return value.)

| Type                                      | Description                                           |
| ------------------------------------------ | ----------------------------------------------- |
| string                                     | Describe the return value, for example, what can be done after the return value is obtained.|
| Promise\<Array<[CustomType](#customtype)>> | Describe the return value. For details about how to write promise methods, see item 14 in "General Writing Instructions."|

**Error codes** (This part is optional. Delete it if no error code is thrown.)

For details about the error codes, see [moduleName Error Codes]\(link to the error code document of the corresponding module).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 1300001  | Repeated operation.               |
| 1300002  | This window state is abnormal.        |

**Example**

```js
// This part is mandatory.

// Check all sample code provided in the example.
// Minor errors such as missing symbols and variable inconsistency are unacceptable.
// Declare all variables that are used.

// Write an actual case that can be easily used, rather than the parameter names themselves. Use comments to describe the content that are not user-defined.
// Example: var result = xxx.createExample(parameterOne); // parameterOne is automatically obtained by scanning.

// Provide clear and concise comments in the following typical scenarios:
// 1. The meaning of a variable name or the code logic is not self-explanatory.
// 2. A complex algorithm or special syntax is involved.
```

## On and Off Subscription Methods

> *Writing Instructions*
>
> 1. The basic requirements are the same as those provided in [Methods](#methods). The following describes only the differences.
>
> 2. Use the actual method name, in the format of ClassName.methodName plus the subscription event, as the level-2 heading.
>    Examples: `sim.on(?exampleEvent?)` and `on('play' | 'pause' | 'stop' | 'reset')`
>
> 3. **Method calling mode**: The description must be the same as that in the .d.ts file and include the parameter type, event name, parameter name, and return value type.
>    Example: `on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void`
>    Note: The angle bracket (<>) may be identified as a label and not displayed. To ensure normal display, you can either add a backslash (\\) (in the format of "\\<>") or use escape characters \&lt; and \&gt;.

Provide the method name in the following format: (`static` if it is a static method) methodName (parameterName1: parameterType1, parameterName2: parameterType2, ...): returnValueType

Describe the method. For details, see the fourth and fifth points in "Writing Instructions" under [Methods](#methods).

**Model restriction**: This API can be used only in the FA model. (Delete this part if it is not involved.)

**System API**: This is a system API. (Delete this part if it is not involved.)

**Required permissions**: ohos.permission.examplePermission (Delete this part if no permission is involved. If a system permission is required, specify it.)

**System capability**: SystemCapability.*A.B* (This part is mandatory.)

**Parameters** (This part is optional. Delete it if there is no parameter.)

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                               | Yes  | Describe the event and when or how it will be triggered. If a method involves multiple events, describe them separately.<br>**Example 1 (single event):**<br>Type of the event. The `'play'` event is triggered when the `play()` API is called and audio playback starts.<br>**Example 2 (multiple events)**:<br>Type of the event. The following events are supported:<br/>- 'play': triggered when the play() API is called and audio playback starts.<br/>- 'dataLoad': triggered when the audio data is loaded, that is, when the `src` attribute is configured.<br/>- 'finish': triggered when the audio playback is finished. |
| callback | Callback\<[CustomType](#customtype)> | No  | Describe the parameter. The instructions are the same as those provided under [Methods](#methods).                         |

**Return value** (This part is optional. Delete it if there is no return value.)

| Type  | Description                                 |
| ------ | ------------------------------------- |
| string | Describe the return value. The instructions are the same as those provided under [Methods](#methods).|

**Example**

```js
// This part is mandatory. The instructions are the same as those provided under [Methods](#methods).

// Check all sample code provided in the example.
// Minor errors such as missing symbols and variable inconsistency are unacceptable.
// Declare all variables that are used.

// Write an actual case that can be easily used, rather than the parameter names themselves. Use comments to describe the content that are not user-defined.
// Example: var result = xxx.createExample(parameterOne); // parameterOne is automatically obtained by scanning.

// Provide clear and concise comments in the following typical scenarios:
// 1. The meaning of a variable name or the code logic is not self-explanatory.
// 2. A complex algorithm or special syntax is involved.
```

## Classes/Interfaces

> *Writing Instructions*
>
> 1. This section is optional. Delete it if there is no class or interface. If there are multiple classes or interfaces, describe them in multiple level-2 headings, prefixed with `##` followed by a space.
>
> 2. Use the actual class or interface name as the level-2 heading.
>
> 3. If the class or interface contains both attributes and methods, write the attributes above the methods. Write their actual names in separate level-3 headings.
>    If the class or interface contains only attributes, you do not need to create a level-3 heading. Instead, use a table to display the attributes. For details, see [CustomType](#customtype).

Describe the class or interface. If there are usage restrictions, describe them as well, for example, whether there is a prerequisite and whether an instance needs to be created by using any method.

### Attributes in Classes/Interfaces

> *Writing Instructions*
>
> Except that a level-3 heading is used for attributes in classes/interfaces, other instructions are the same as those provided under [Attributes](#attributes).

### Methods in Classes/Interfaces

> *Writing Instructions*
>
> 1. Use the actual method name as the **level-3 heading**. **Do not add a prefix.** For a subscription method, add the corresponding subscription event to the method name.
>    Example of a common method: getSimIccId
>    Example of a subscription method: on('exampleEvent')
> 2. Other instructions are the same as those provided under [Methods](#methods).

## Enums

> *Writing Instructions*
>
> 1. This section is optional. Delete it if there is no enum. If there are multiple enums, describe them in separate level-2 headings, prefixed with `##` followed by a space.
>
> 2. Use the actual enum name as the level-2 heading, for example, `BatteryHealthState`.

Provide a brief description of the enum type. Example: Enumerates the charger types.

**System capability**: SystemCapability.*A.B* (This part is mandatory.)

| Name| Value  | Description                      |
| ---- | ---- | -------------------------- |
| NONE | 1    | Unknown type.|

## CustomType

The following is an example of the custom type of a key-value pair.
**System capability**: SystemCapability.*A.B* (This part is mandatory.)

| Name        | Type               | Readable| Writable| Description                                                        |
| ------------ | ------------------- | ---- | ---- | ------------------------------------------------------------ |
| parameterUrl | string              | Yes  | Yes  | Media output URI. Supported:<br>1. Relative path whose protocol type is `internal`. Example: <br/>Temporary directory: internal://cache/test.mp4<br>2. Absolute path. Example:<br/>file:///data/data/ohos.xxx.xxx/files/test.mp4|
| parameterOne | [CustomEnum](#enums) | Yes  | Yes  | Describe the attributes. The requirements are similar to those for the parameter description.                              |

## Change History
| Change Description| Date|
| -------- | ---- |
| 1. Provided the general writing instructions in a table.<br>2. Added the description about how to reference an image in "Upload path".<br>3. Added the "Document structure" item to describe the sequence of nodes in the API reference document.<br>4. Added the description for multiple permissions in "Permission description".<br>5. Added the description of @FAModelOnly and @StageModelOnly in the API reference document.<br>6. Added the description of asynchronous methods (callback and promise).<br>7. Added the standards and specifications for the sample code programming language.<br>8. Added the standard format for links used in the API reference document.<br>9. Added examples for "Module description".<br>10. Added the description of on and off subscription methods.<br>11. Updated the description of @syscap.<br>12. Updated the description of @systemapi. Now only the sentence "This is a system API." is used.  <br>13. Deleted the MR version description.|2022-06-24|

<!--no_check-->

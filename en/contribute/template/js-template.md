# API Reference Template

## General Writing Instructions

> **NOTE**
>
> Delete all writing instructions after you finish the writing.

|      | Item                           | Writing Instruction                                                        |
| ---- | --------------------------------- | ------------------------------------------------------------ |
| 1    | Customer-oriented mindset               | **Stand in the shoes of developers and provide the use cases, parameter selection principles, recommendations/tips, sample code, and anything else that a developer will need to develop the API.**|
| 2    | Upload path                         | Upload markdown files to **docs/en/application-dev/reference/apis**.<br>Upload images to **docs/en/application-dev/reference/apis/figures**. In addition, reference the image path in the markdown file as follows: **\![]\(figures/exampleImage.jpg)**, **\![]\(figures/exampleImage.png)**, or **\![]\(figures/exampleImage.gif)**.|
| 3    | File name                         | Provide one JS API reference document for each d.ts file. Name the file in the format of **js-apis-exampleModule.md**, where **exampleModule** is a variable and must be the same as the actual module name.<br>Examples:<br>For @ohos.multimedia.audio in the Multimedia subsystem, the JS API file name is **js-apis-audio.md**.<br>For @ohos.telephony.sms in the Telephony subsystem, the JS API file name is **js-apis-sms.md**.|
| 4    | Directory update                         | After uploading an API reference document, update the **Readme-EN.md** file in **docs/en/application-dev/reference/apis**.<br>The directories are automatically arranged in alphabetical order.|
| 5    | Document structure                         | - Module description<br>- Initial version description<br>- Modules to Import/Usage description<br>- API description (properties, constants, methods, enums, and custom types)<br>  The order in which APIs are described in the document must be consistent with that in which they appear in the code. If some APIs have a logical sequence, pay attention to their sequence in the API reference document.|
| 6   | Asynchronous methods (callback and promise)| Use the following sentences for callback methods.<br>Method introduction: *Describe the method.* This API uses an asynchronous callback to return the result.<br>Parameter description:<br>**callback\<boolean>**: Callback used to return the result. The value **true** indicates *something*, and **false** indicates the opposite.<br>**callback\<Object>**: Callback used to return *something*. Example: Callback used to return the **AudioCapturer** object.   <br>**AsyncCallback\<void>**: Callback used to return the result. If the operation (or a specific operation description) is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>**AsyncCallback\<Object x>**: Callback used to return the result. If the operation (or a specific operation description) is successful, **err** is **undefined** and **data** is the *x* object obtained; otherwise, **err** is an error object.<br>Use the following sentences for promise methods.<br>Method introduction: *Describe the method.* This API uses a promise to return the result.<br>Parameter description:<br>**Promise\<boolean>**: Promise used to return the result. The value **true** indicates *something*, and **false** indicates the opposite.<br>**Promise\<Object>**: Promise used to return *something*. Example: Promise used to return the **AudioCapturer** object.<br>**Promise\<void>**: Promise that returns no value.|
| 7   | Sample code programming language                     | Use code blocks to provide sample code and mark the programming language.<br>Use `js` as the mark if both JS and eTS can be used, and use `ts` if only eTS can be used.|
| 8   | Link                         | Link format: [Link text]\(Link content)<br>Cross-folder link format: [markdown file name]\(\.\./../xxx/xxx.md). One `../` indicates one upper-level folder.<br>Intra-topic link format: [Interface A<sup>7+</sup>]\(#xxxa7). The text in the intra-topic link must be the same as the title to be linked. In the link, all letters must be in lowercase, and no special character (except the hyphen) or tag is included.|

## Mappings Between d.ts Tags and Document Fields

Except for @since, document fields mapping to the following tags must be provided under each API.

For a property or interface table, if a tag has the same value for all the items in the table, you can place the tag description above the table. Otherwise, place the tag under **NOTE** for each item.

| d.ts Tag| Description| Document Field|
| ---------- | ---- | ------- |
| @since | Version description| 1. Use the greater-than sign (>) followed by a space to indent the description about the initial version of the module. Unless otherwise marked, all APIs in the module have the same initial version.<br>2. When introducing an API to an existing module, use the `<sup>` tag to mark its earliest version. The format is `<sup>versionNumber+</sup>`, for example, `<sup>7+</sup>`.  <br>  <br> When introducing a property to an existing module, suffix the `<sup>` tag to the new property name, for example, `newProperty<sup>7+</sup>`.<br>When introducing a method to an existing module, suffix the `<sup>` tag to the method name, for example, `sim.getSimIccId<sup>7+</sup>`. The same rule applies to new interfaces, classes, and enums.<br>Due to the rectification of anonymous objects, the version number of the outer element of some APIs is later than that of the inner element. To avoid any confusion for developers, a uniform explanation should be added in the **Interface Description** section: To standardize the definition of anonymous objects, the element definitions have been modified in API version *XX*. The initial version information of the historical anonymous objects has been retained, which may result in the outer element's @since version number being later than the inner element's version number. However, this does not affect the use of the API.|
| @deprecated | Deprecated description| Do not delete the deprecated content from the document. Instead, suffix `deprecated` as a superscript to the content, and use the greater-than sign (>) to introduce the initial version and deprecated version.<br>Example: abandonmentMethod<sup>(deprecated)</sup><br>> This API is supported since API version 4 and deprecated since API version 7. You are advised to use [newMethod]\(#newmethod) instead.|
| @FAModelOnly / @StageModelOnly | Model restriction description| **Model restriction**: This API can be used only in the FA model. **Model restriction**: This API can be used only in the stage model.|
| @form | Widget capability description| **Widget capability**: Since API version *x*, this feature is supported in ArkTS widgets.|
| @atomicservice | Atomic service description| **Atomic service API**: This API can be used in atomic services since API version *x*.|
| @systemapi | System API description| **System API**: This is a system API.|
| @syscap | System capability description| **System capability**: SystemCapability.*A.B*|  1. If only one permission is required for using the API, use the following format:<br>    **Required permissions**: ohos.permission.examplePermission<br>2. If multiple permissions are required for using the API, provide the permissions with **and** or **or** in the following format:<br>    **Required permissions**: ohos.permission.examplePermissionA and ohos.permission.examplePermissionB<br>    **Required permissions**: ohos.permission.examplePermissionA or ohos.permission.examplePermissionB|
| @permission | Permission description|  1. If only one permission is required for using the API, use the following format:<br>    **Required permissions**: ohos.permission.examplePermission<br>2. If multiple permissions are required for using the API, provide the permissions with **and** or **or** in the following format:<br>    **Required permissions**: ohos.permission.examplePermissionA and ohos.permission.examplePermissionB<br>    **Required permissions**: ohos.permission.examplePermissionA or ohos.permission.examplePermissionB<br>3. When there is a version change involved, follow the current version's permission requirement after **Required permissions**, and describe the historical version's permission requirement in a new line as a list. Example:<br>**Required permissions**: ohos.permission.A<br>- ohos.permission.A and ohos.permission.B for API x-(y-1)<br>- ohos.permission.A from API y<br>4. When permissions are required only in certain fixed scenarios, follow the @permission in the .d.ts file consistently after **Required permissions**, and then supplement with a situation description. There are two types of situations. When the situation is relatively simple, use parentheses to add a description. When the situation is more complex, use a new line for the description.<br>Example 1:<br> **Required permissions**: ohos.permission.A (required only when the window type is **AA**.)<br>Example 2:<br> **Required permissions**: ohos.permission.A<br>- When the application is in situation xx, ohos.permission.B is also required.<br>- When the application is in situation yy, no permission is required.|
| @extends | Inheritance|  If the tag is carried or the extends relationship exists but the tag is not carried, clearly state the following information: *ExampleA* inherits from *ExampleB* (provide the link of *ExampleB*).|

The following describes the instructions for writing a specific API reference document.

***

# Document Title

> *Writing Instructions*
>
> - **Document title**: Use phrases that summarize the module functionalities. Examples: **Ability** and **SIM Card Management**
> - **Heading levels**: Use the document title as the level-1 heading, which is prefixed with `#` followed by a space. Use the properties, functions, classes, interfaces, enums, and types under the namespace as level-2 headings, which are prefixed with `##` followed by a space. Use the properties and functions under classes as level-3 headings, which are prefixed with `###` followed by a space.
> - **Initial version description**: Use the greater-than symbol (**>**) to indent the description about the initial version of the module. Use a line break after **NOTE**.<br>Place the version description after the module description. A module has only one initial version.<br>Use the following sentence: "The initial APIs of this module are supported since API version *x*. Newly added APIs will be marked with a superscript to indicate their earliest API version." Change ***x*** to the actual version number.

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

**ArrayList** is a linear data structure that is implemented based on arrays. **ArrayList** can dynamically adjust the capacity based on project requirements. It increases the capacity by 50% each time.

Similar to **ArrayList**, **Vector** is also implemented based on arrays and can dynamically adjust the capacity. It increases the capability by 100% each time.

When compared with **LinkedList**, **ArrayList** is more efficient in random access but less efficient in the addition or removal operation, because its addition or removal operation affects the position of other elements in the container.

You are advised to use **ArrayList** when elements in a container need to be frequently read.



> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

> *Writing Instructions*
>
> - Write the modules to import based on the actual conditions. Provide the `import` statement in the form of a code block.
>
> - If no module needs to be imported, change "Modules to Import" to "Usage" and provide a usage description.<br>Example of **Usage**:<br>
>    Before using the **AbilityContext**, obtain the **Context** object through \[getContext()]\(*API-reference*.md)\.
>
> ```js
>    import { featureAbility } from '@kit.AbilityKit';
>    let context = featureAbility.getContext();
> ```

```js
import { call } from '@kit.TelephonyKit';
```

## Properties

> *Writing Instructions*
>
> - This section is optional. Delete it if there is no property.
>
> - If a property is of a custom type, create a link to the corresponding interface or enum.
>
> - A read-only property is marked with `readonly` in d.ts files. If it has a limited number of values with special meanings, enumerate the values or provide a link to the corresponding enum.
>
> - For an optional property, if only fixed fields are supported, describe them. A property defined with a question mark (?) is optional.

**System capability**: SystemCapability.*A.B* (This part is mandatory.)

| Name            | Type                                     | Read Only| Optional| Description                                      |
| ---------------- | ----------------------------------------- | ---- | ---- | ------------------------------------------ |
| pluggedType      | [BatteryPluggedType]\(#batterypluggedtype) | Yes  | No  | Charger type of the current device.            |
| isBatteryPresent | boolean                                   | Yes  | No  | Whether the battery is supported or present.|

## Constants

> *Writing Instructions*
>
> - This section is optional. Delete it if there is no constant. It corresponds to `const` in the .d.ts file.
> - Some constants are used to define read-only variables and have no values. In this case, the table contains four columns: Name, Type, Read Only, and Description.
> - If a property is of a custom type, create a link to the corresponding interface or enum.

**System capability**: SystemCapability.*A.B* (This part is mandatory.)

| Name            | Type                               |  Value     | Description                                      |
| ---------------- | -----------------------------------| -------- | ------------------------------------------ |
| uid              | number                             | 1        | User identifier (UID) of a process.                          |
| pid              | number                             | 2        | Process ID (PID) of a process.                           |

## Methods

> *Writing Instructions*
>
> - This section is optional. Delete it if there is no method. If there are multiple methods, describe them in separate level-2 headings, prefixed with `##` followed by a space.
>
> - Use the actual method name, in the format of ClassName.methodName, as the level-2 heading. For a subscription method, add the subscription event to the method name.
>
>    Example of a common method: sim.getSimIccId
>    Example of a subscription method: sim.on('exampleEvent')
>
> - The method call mode is the same as that in .d.ts. The keywords (for example, `static`, `abstract`, `set`, and `get`), parameter types, parameter names, and return value types must be included.
>
>    Examples:
>    
>    getNetworkState(slotId: number, callback: AsyncCallback\<NetworkState>): void
>
>       abstract makeNode(uiContext: UIContext): FrameNode | null
>
>    Note 1: The angle bracket (<>) may be identified as a label and not displayed. To ensure normal display, you can either add a backslash (\\) (in the format of "\\<>") or use escape characters \&lt; and \&gt;.
>
>    Note 2: If the methods declared by the `set` and `get` keywords appear in pairs and have the same names, place them under the same title and describe the method call modes, tags, parameters, and return values in sequence. It is recommended that the `set` method be placed before the `get` method. For details, see [backgroundColor](../../application-dev/reference/apis-arkui/js-apis-arkui-renderNode.md#backgroundcolor).
>
> - **Method description**: Describe the features implemented by the method and include the prerequisites for using the method, the impact of the method, and the permissions and system capabilities required to use the method. (*Example of prerequisites: This method can be called only after the xx method is called; you must ensure that the connection to the Internet is normal. Example of impact: xx does not take effect after this method is called.*)
>
> - **Asynchronous methods**: If there are asynchronous methods, describe their return type in the method description. For details, see item 14 in "General Writing Instructions."
>
> - **Line feed in a table**: Use \<br> for line feed.

Provide the method call mode in the following format: (keyword, if available) methodName (parameterName1: parameterType1, parameterName2: parameterType2, ...): returnValueType

Describe the method. For details, see the fourth and fifth points in "Writing Instructions" above.

**Model restriction**: This API can be used only in the FA model. (Delete this part if it is not involved.)

**System API**: This is a system API. (Delete this part if it is not involved.)

**Required permissions**: ohos.permission.examplePermission (Delete this part if no permission is involved.)

**System capability**: SystemCapability.*A.B* (This part is mandatory.)

**Parameters** (This part is optional. Delete it if there is no parameter.)

| Name      | Type                                         | Mandatory| Description                                                        |
| ------------ | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| parameterOne | number \| string \| [CustomType](#classinterface) | Yes  | The parameter description must include the meaning and purpose of the parameter, the scenarios in which the parameter is used, suggestions for selection, and relationships between parameters.<br>The parameter value description must include the value range, unit, default value, principles for selection, or recommended value. If the boundary value involves restrictions/exceptions, describe the specific scenario. If there is a fixed format, provide a format example, especially for URIs.<br>Provide a link for each custom parameter type.|
| callback     | Callback\<Array<[CustomType](#classinterface)>>   | No  | Describe the parameter. For an optional parameter, describe the consequences if it is not specified.<br>Example: If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.<br>For details about how to write callback methods, see item 14 in "General Writing Instructions."|

**Return value** (This part is optional. Delete it if there is no return value.)

| Type                                      | Description                                           |
| ------------------------------------------ | ----------------------------------------------- |
| string                                     | Describe the return value from the following aspects:<br>1. What can be done after the return value is obtained.<br>2. If the return values can be enumerated, describe the meaning of the return values.<br>3. If the return value is a specific value or format, keep the value or format consistent with the actual implementation. |
| Promise\<Array<[CustomType](#classinterface)>> | Describe the return value. For details about how to write promise methods, see item 14 in "General Writing Instructions."|

**Error codes** (This part is optional. Delete it if no error code is thrown.)

For details about the error codes, see [moduleName Error Codes]\(link to the error code document of the corresponding module).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 1300001  | Repeated operation.               |
| 1300002  | This window state is abnormal.        |

**Example**

```js
// This part is mandatory.

// All example code must be self-checked to ensure that the execution results meet expectations.
// Minor errors such as missing symbols and variable inconsistency are unacceptable.
// Declare all variables that are used.
// When the interface parameters are abnormal, it is necessary to verify whether the code can catch the error and throw the corresponding error code.

// Write an actual case that can be easily used, rather than the parameter names themselves. Use comments to describe the content that are not user-defined.
// Example: let result = xxx.createExample(parameterOne); // parameterOne is automatically obtained by scanning.

// Provide clear and concise comments in the following typical scenarios:
// 1. The meaning of a variable name or the code logic is not self-explanatory.
// 2. A complex algorithm or special syntax is involved.
```

## On and Off Subscription Methods

> *Writing Instructions*
>
> - The basic requirements are the same as those provided in [Methods](#methods). The following describes only the differences.
>
> - Use the actual method name, in the format of ClassName.methodName plus the subscription event, as the level-2 heading.
>    Examples: **sim.on(?exampleEvent?)** and **on('play' | 'pause' | 'stop' | 'reset')**
>
> - **Method calling mode**: The description must be the same as that in the .d.ts file and include the parameter type, event name, parameter name, and return value type.
>    Example: **on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void**
>    Note: The angle bracket (<>) may be identified as a label and not displayed. To ensure normal display, you can either add a backslash (\\) (in the format of "\\<>") or use escape characters \&lt; and \&gt;.

Provide the method name in the following format: (`static` if it is a static method) methodName (parameterName1: parameterType1, parameterName2: parameterType2, ...): returnValueType

Describe the method. For details, see the fourth and fifth points in "Writing Instructions" under [Methods](#methods).

**Model restriction**: This API can be used only in the FA model. (Delete this part if it is not involved.)

**System API**: This is a system API. (Delete this part if it is not involved.)

**Required permissions**: ohos.permission.examplePermission (Delete this part if no permission is involved.)

**System capability**: SystemCapability.*A.B* (This part is mandatory.)

**Parameters** (This part is optional. Delete it if there is no parameter.)

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                               | Yes  | Describe the event and when or how it will be triggered. If a method involves multiple events, describe them separately.<br>**Example 1 (single event):**<br>Type of the event. The **'play'** event is triggered when the **play()** API is called and audio playback starts.<br>Example 2 (multiple events):<br>Type of the event. The following events are supported:|  | <br>- **'play'**: triggered when the **play()** API is called and audio playback starts.<br>- **'dataLoad'**: triggered when the audio data is loaded, that is, when the **src** property is configured.<br>- **'finish'**: triggered when the audio playback is finished.|
| callback | Callback\<[CustomType](#classinterface)> | No  | Describe the parameter. The instructions are the same as those provided under [Methods](#methods).                         |

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
// Example: let result = xxx.createExample(parameterOne); // parameterOne is automatically obtained by scanning.

// Provide clear and concise comments in the following typical scenarios:
// 1. The meaning of a variable name or the code logic is not self-explanatory.
// 2. A complex algorithm or special syntax is involved.
```

## Classes/Interfaces

> *Writing Instructions*
>
> - This section is optional. Delete it if there is no class or interface. If there are multiple classes or interfaces, describe them in separate level-2 headings, prefixed with `##` followed by a space.
>
> - Use the actual class or interface name as the level-2 heading.
>
> - If the class or interface contains both properties and methods, write the properties above the methods. Write their actual names in separate level-3 headings.
>    If the API contains only properties, you do not need to create a level-3 heading. Instead, use a table to display the properties.

Describe the class or interface. If there are usage restrictions, describe them as well, for example, whether there is a prerequisite and whether an instance needs to be created by using any method.

### Properties in Classes/Interfaces

> *Writing Instructions*
>
> Except that level-3 headings are used, other requirements are the same as those in [Properties](#properties). Write the interface name in the form of level-2 heading.

### Methods in Classes/Interfaces

> *Writing Instructions*
>
> - Use the actual method name as the **level-3 heading**. **Do not add a prefix.** For a subscription method, add the corresponding subscription event to the method name.
>    Example of a common method: getSimIccId
>    Example of a subscription method: on('exampleEvent')
> - Other instructions are the same as those provided under [Methods](#methods).

## Enums

> *Writing Instructions*
>
> - This section is optional. Delete it if there is no enum. If there are multiple enums, describe them in separate level-2 headings, prefixed with `##` followed by a space.
>
> - Use the actual enum name as the level-2 heading, for example, **BatteryHealthState**.

Provide a brief description of the enum type. Example: Enumerates the charger types.

**System capability**: SystemCapability.*A.B* (This part is mandatory.)

| Name| Value  | Description                      |
| ---- | ---- | -------------------------- |
| NONE | 1    | Unknown type.|

## Types

> *Writing Instructions*
>
> - This section is optional. Delete it if there is no type. It corresponds to `type` in the .d.ts file.
>
> - Currently, there are two templates, corresponding to two different scenarios.
>     
>    - When the type is union or intersection, the definition format is type Xxx = number | string | 'xxx' or type AB = InterfaceA & InterfaceB. For details, see [Template 1](#type-template-1).
>    - If the type is the alias of a function or interface, the definition format is type Xxx\<Aaa, Bbb> = (param1: number, param2: string) => void or type Xxx = (param1: number, param2: string). Explain the parameters based on the function or interface template and provide its definition before the list. For details, see [Template 2](#type-template-2).
>
> - If the value range is of a specific value, such as a fixed string or enumerated value, describe the data type and specified value. If the value range is of a specified type, describe whether any value of the type or a value range is used.
>
> - If a property is of a custom type, create a link to the corresponding interface or enum.


### Type-Template-1

type Xxx = number | string | 'xxx'  

Provide a brief description of the type. Example: Enumerates the value types.

Provide the logic for obtaining the actual value of this type. Example: The value type is the union set or intersection set in the following table.

**System capability**: SystemCapability.*A.B* (This part is mandatory.)

| Type     | Description                         |
| -----------| ---------------------------- |
| number     | The value can be any number.    |
| string     | The value can be any string.    |
| 'xxx'      | *Meaning of the value*. The value is a string fixed at *ExampleString*.    |

### Type Template 2

*(The function alias is used as an example.)*

(Provide the definition of the type here.) type Xxx\<Aaa, Bbb> = (param1: number, param2: string) => Interface1

**System capability**: SystemCapability.*A.B* (This part is mandatory.)

**Parameters** (This part is optional. Delete it if there is no parameter.)

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| param1    | number                              | Yes  | Describe the parameter. The instructions are the same as those provided under [Methods](#methods).         |
| param2 | string | No  | Describe the parameter. The instructions are the same as those provided under [Methods](#methods).                         |

**Return value** (This part is optional. Delete it if there is no return value.)

| Type  | Description                                 |
| ------ | ------------------------------------- |
| [Interface1](#interface1) | Describe the return value. The instructions are the same as those provided under [Methods](#methods).|

### Type Template 3

*(Here, an Interface alias containing multiple property fields is used as an example)*

*Provide the specific definition form of type here: type Xxx = { aaa: string; bbb?: number; }*

**System capability**: SystemCapability.*A.B* (This part is mandatory.)


| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| aaa | string | Yes| Describes the property.| 
| bbb | number | No| Describes the property.| 

## Change History

| Change Description                                                                | Date        |
| ----------------------------------------------------------------------- | ------------ |
| Streamlined the standard wording for Promise\<void>. New content should use the new wording. There is no need to actively revise existing content if it already conveys the intended meaning.	| 2025/06/10 |
| Added a standard wording for "Explanation of the @since version number for anonymous object rectification."| 2025/06/03 |
| Optimized the writing standards for permissions to cover various types of permission descriptions and meet the requirements of scanning tools.| 2025/03/12 |
| Added Type template 3, which includes an interface alias with multiple property fields.| 2025/03/04 |
| Added a requirement for example code to capture parameter exceptions.|  2025/03/03 |
| Added a template for read-only variables defined by constants.|   2024/12/31  |
| 1. Updated the method template by adding the description of methods carrying the declaration of keywords such as `static`.|  2024/05/16  |
| 1. Updated the type template. In addition to the union type, the intersection type and the type used as the alias of a function or interface were added.<br>2. Updated the property template to specify the rules for determining optional properties in the interfaces and interface definitions.|  2024/05/10  |
| 1. Changed the template for **Properties** from **Read**, **Write**, and **Mandatory** to **Read Only** and **Mandatory**.<br>2. Changed the template for **Types** by using **Value Range** and **Description**, and provided the related description.<br>3. Deleted the custom type, and incorporated the related description under **Classes/Interfaces**.|  2023/02/01  |
| 1. Provided the general writing instructions in a table.<br>2. Added the description about how to reference an image in "Upload path".<br>3. Added the "Document structure" item to describe the sequence of nodes in the API reference document.<br>4. Added the description for multiple permissions in "Permission description".<br>5. Added the description of @FAModelOnly and @StageModelOnly in the API reference document.<br>6. Added the description of asynchronous methods (callback and promise).<br>7. Added the standards and specifications for the sample code programming language.<br>8. Added the standard format for links used in the API reference document.<br>9. Added examples for "Module description".<br>10. Added the description of on and off subscription methods.<br>11. Updated the description of @syscap.<br>12. Updated the description of @systemapi. Now only the sentence "This is a system API." is used.  <br>13. Deleted the MR version description.                                                                |  2022/6/24  |
| Added the error code description.                                                         | 2022/10/11  |
| 1. Added the template for **constant** and **type**.<br> 2. Modified the table of the custom type **interface** by deleting the **Readable** and **Writable** columns and adding the **Mandatory** column, for consistency with the content of the .d.ts file.<br> 3. Added the deprecated description for APIs with both the initial version and deprecated version.                         |2022/11/22   |

<!--no_check-->

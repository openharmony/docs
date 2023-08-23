# TS Component Reference Template

## General Writing Instructions

>  **NOTE** 
>
> Delete all writing instructions after you finish the writing.

|      | Item        | Writing Instruction                                      |
| ---- | ----------- | ---------------------------------------- |
| 1    | Customer-oriented mindset  | **Stand in the shoes of developers and provide the use cases, parameter selection principles, recommendations/tips, sample code, and anything else that a developer will need to develop the component.**|
| 2    | Upload path       | Upload markdown files to `docs/en/application-dev/reference/arkui-ts`.<br>Upload images to **docs/en/application-dev/reference/arkui-ts/figures**. In addition, reference the image path in the markdown file as follows: **\![]\(figures/exampleImage.jpg)**, **\![]\(figures/exampleImage.png)**, or **\![]\(figures/exampleImage.gif)**.|
| 3    | File name       | Provide one TS component reference document for each .d.ts file. Name the file in the format of `ts-componentClassName-componentName.md`.<br>Examples:<br>For the basic component **\<text>**, the reference file name is `ts-basic-component-text.md`.<br>For the container component **\<list>**, the reference file name is `js-container-component-list.md`.|
| 4    | Directory update       | After uploading a TS component reference document, update the `Readme-EN.md` file in `docs/en/application-dev/reference/arkui-ts`.|
| 5    | Document structure       | - Component description<br>- Initial version description<br>- Modules to import/Usage description<br>- Permission description<br>- APIs, attributes, events, objects, enums, and custom types<br>The order in which APIs are described in the document must be consistent with that in which they appear in the code. If some APIs have a logical sequence, pay attention to their sequence in the document.|
| 6    | Initial version description     | 1. Use the greater-than sign (`>`) followed by a space to indent the description about the initial version of the component. Unless otherwise marked, all APIs in the component have the same initial version.<br>2. When introducing an API to an existing component, use the `<sup>` tag to mark its initial version. The format is `<sup>versionNumber+</sup>`, for example, `<sup>7+</sup>`.<br>When introducing an attribute to an existing API, use the `<sup>` tag to mark its initial version. The format is `newAttribute<sup>versionNumber+</sup>`, for example, `newAttribute<sup>7+</sup>`.|
| 7    | Deprecated API description     | Do not delete the deprecated content from the document. Instead, suffix `deprecated` as a superscript to the content, and use the greater-than sign (`>`) to introduce the substitute API plus a link to the API description.<br>Example: abandonmentMethod<sup>(deprecated)</sup><br>> This API is no longer maintained since API version 7. You are advised to use [newMethod]\(#newmethod) instead.|
| 8    | Permission description       | Use "Required Permissions" as a level-2 heading.<br>1. If a specific permission required for using the component can be requested only by system applications, provide the description in the following format:<br>ohos.permission.examplePermission (available only to system applications)<br>2. If a specific permission required for using the component can be requested by all applications, provide the description in the following format:<br>ohos.permission.examplePermission<br>3. If multiple permissions are required for using the component, provide the permissions with `and` or `or` in the following format:<br>ohos.permission.examplePermissionA and ohos.permission.examplePermissionB<br>ohos.permission.examplePermissionA or ohos.permission.examplePermissionB|
| 9   | @system api | 1. If all APIs of the component are system APIs, add the following sentence to the next line of the initial version description:<br>The APIs provided by this component are system APIs.<br>2. If an API is a system API that can be used only by original equipment manufacturers (OEMs), add the following sentence to the API description:<br>**System API**: This is a system API.|
| 10   | Sample code programming language     | Use code blocks to provide sample code, and mark the programming language ts by adding `// xxx.ets` at the beginning of every sample code block.|
| 11   | Link       | Link format: [Link text]\(Link content)<br>Cross-folder link format: [markdown file name]\(\.\./../xxx/xxx.md). One `./` indicates one upper-level folder.<br>Intra-topic link format: [Interface A<sup>7+</sup>]\(#xxxa7). The text in the intra-topic link must be the same as the title to be linked. In the link, all letters must be in lowercase, and no special character (except the hyphen) or tag is included.|

The following describes the instructions for writing a specific component reference document.

***

# Document Title

> *Writing Instructions:*
>
> 1. **Document title**: Use phrases that summarize the component functionalities. Examples: `Button` and `Slider`.
> 2. **Heading levels**: Use the document title as the level-1 heading, which is prefixed with `#` followed by a space. Use the functions, classes, interfaces, enums, and types as level-2 headings, which are prefixed with `##` followed by a space. Use the attributes and functions under classes as level-3 headings, which are prefixed with `###` followed by a space.
> 3. **Initial version description**: Use the greater-than symbol (`>`) to indent the description about the initial version of the component. Use a line break after **NOTE**. <br>Place the version description after the component description. A component has only one initial version. <br>Use the following sentence: "This component is supported since API version *x*. Newly added APIs will be marked with a superscript to indicate their earliest API version." Change ***x*** to the actual version number.

Describe the component from its functionalities, use cases, and recommendations in this section. 

**Example 1**: \<Marquee>

The **\<Marquee>** component is used to display a scrolling piece of text. The text is scrolled only when its width exceeds the width of the **\<Marquee>** component.

**Example 2**: \<SideBarContainer>

The **\<SideBarContainer>** component contains a sidebar and content area as its child components. The sidebar is the first child component and can be shown or hidden as needed. The content area is the second child component.

> **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

> *Writing Instructions:*
>
> 1. This section is optional. Delete it if the document is about a component or universal method.
> 2. This section is mandatory if the document is about an API to be imported.
> 3. Write the modules to import based on the actual conditions. Provide the **import** statement in the form of a code block.<br>**Example:**
>

```js
import Curves from '@ohos.curves'
```

## Required Permissions

> *Writing Instructions:*
>
> 1. This section is optional. Delete it if you do not need to apply for any permission to use the component.
> 2. If a specific permission required for using the component can be requested only by system applications, provide the description in the following format:
>    ohos.permission.examplePermission (available only to system applications)
> 3. If a specific permission required for using the component can be requested by all applications, provide the description in the following format:
>   ohos.permission.examplePermission
> 4. If multiple permissions are required for using the component, provide the permissions with `and` or `or` in the following format:<br>
>   ohos.permission.examplePermissionA and ohos.permission.examplePermissionB<br>
>   ohos.permission.examplePermissionA or ohos.permission.examplePermissionB

Example: ohos.permission.INTERNET<br>For details about how to apply for a permission, see [Permission Application Statement](../../application-dev/security/accesstoken-guidelines.md).

## Child Components

> *Writing Instructions:*
>
> 1. This section is mandatory if the document is about a built-in component that contains child components.
> 2. Delete this section if the document is about a non-built-in component or a built-in component that does not contain child components.

Example: Supported

## APIs

>*Writing Instructions:*
>
>1. This section is mandatory if the document is about a built-in component and the component has APIs.
>2. The description of the API calling mode must be the same as that in the .d.ts file and include the parameter type and parameter name. 
>3. Add a question mark (?) after the parameter name to mark an optional parameter.
>4. Use English symbols in the complete method name, and add a space after each colon (:).
>5. Do not use a semicolon (;) at the end of the complete method name.
>6. If a custom parameter type (such as object and enum) appears for the first time, describe the parameter type in an unordered list. If this type has been described in other places, use a relative link to reference it.
>7. Note: The angle bracket (<>) may be identified as a label and not displayed. To ensure normal display, you can either add a backslash (\\) (in the format of "\\<>") or use escape characters \&lt; and \&gt;.
>8. Note: The method in the component interface has no return value and is not presented in the form of level-2 or level-3 headings. It must also meet requirements described in [Methods](#methods).
>9. Note: The default value must be described in a separate line in the description.

If an API has two or more constructors, describe their differences.

Provide the method name in the following format: methodName (parameterName1: parameterType1, parameterName2: parameterType2, ...) <br>If an API involves multiple methods, describe the methods in sequence and add a sequence number before the methods, for example, **method 1:**.

Example: **Method 1**: Button(options?: { type?: ButtonType, stateEffect?: boolean })

Describe the function of the method. If there are usage restrictions, describe them in detail.

**options Parameters** (This part is optional. Delete it if there is no parameter.)

| Name        | Type      | Mandatory  | Description                                      |
| ----------- | ---------- | ---- | ---------------------------------------- |
| type        | ButtonType | No   | Button type.<br>Default value: ButtonType.Capsule         |
| stateEffect | boolean    | No   | Whether to enable the state switchover effect when a button is pressed. When the state is set to **false**, the state switchover effect is disabled.<br>Default value: true|

## Attributes

> *Writing Instructions:*
>
> 1. This section is optional. Delete it if there is no attribute.
> 2. Create a link for a custom type (such as object and enum) to the corresponding interface or enum.
> 3. Note: The default value must be described in a separate line in the description.

If the document is about a built-in component, specify whether the component supports universal attributes.

Example:

In addition to the [universal attributes]\(a relative link to the Universal Attributes topic), the following attributes are supported.

| Name        | Type             | Description                                      |
| ---------- | --------------- | ---------------------------------------- |
| alignItems | HorizontalAlign | Alignment mode of child components in the horizontal direction.<br>Default value: HorizontalAlign.Center|

## Events

> *Writing Instructions:*
>
> 1. This section is optional. Delete it if there is no event.
> 2. Create a link for a custom type (such as object and enum) to the corresponding interface or enum. If this type appears for the first time, describe it under the event in the form of a level-2 heading. If this type has been described in other places, use a relative link to reference it.

If the document is about a built-in component, specify whether the component supports universal events.

Example:

In addition to the [universal events]\(a relative link to the Universal Events topic), the following events are supported.

Provide the invoking mode of each event. The requirements are the same as those in [Methods](#methods).

### onSubmit

onSubmit(callback: (value: string) => void)

Triggered when users click the search icon or the search button, or touch the search button on a soft keyboard.

**Parameters**

| Name  | Type  | Mandatory| Description         |
| ----- | ------ | ---- | ----------- |
| value | string | Yes   | Current text input.|

## Methods

> *Writing Instructions:*
>
> 1. This section is optional. Delete it if there is no method. If there are multiple methods, describe them in separate level-2 headings, prefixed with `##` followed by a space.
>
> 2. Use the method name in the format of importedClassName.methodName as the level-2 heading.
>
>    Example: mediaquery.matchMediaSync
>
> 3. **Method calling mode**: The description must be the same as that in the .d.ts file and include the parameter type, parameter name, and return value type.
>
>    Example: matchMediaSync(condition: string): MediaQueryListener
>
> 4. The angle bracket (<>) may be identified as a label and not displayed. To ensure normal display, you can either add a backslash (\\) (in the format of "\\<>") or use escape characters \&lt; and \&gt;.
>
> 5. **Method description**: Describe the features implemented by the method and include the prerequisites for using the method, the impact of the method, and the permissions and system capabilities required to use the method. (*Example of prerequisites: This method can be called only after the xx method is called; you must ensure that the connection to the Internet is normal. Example of impact: xx does not take effect after this method is called.*)
>
> 6. **Line feed in a table**: Use \<br> for line feed.<br>

Provide the method name in the following format: (**static** if it is a static method) methodName (parameterName1: parameterType1, parameterName2: parameterType2, ...): returnValueType

Describe the method.

**Parameters** (This part is optional. Delete it if there is no parameter.)

| Name      | Type  | Mandatory  | Description        |
| --------- | ------ | ---- | ---------- |
| condition | string | Yes   | Matching condition of a media event.|

**Return value** (This part is optional. Delete it if there is no return value.)

| Type                | Description                    |
| ------------------ | ---------------------- |
| MediaQueryListener | Listening handle to a media event, which is used to register or deregister the listening callback.|

**Example**

```js
// This part is mandatory.

// Check all sample code provided in the example.
// Minor errors such as missing symbols and variable inconsistency are unacceptable.
// Declare all variables that are used.

// Write an actual case that can be easily used, rather than the parameter names themselves. Use comments to describe the content that are not user-defined.
// Example: var result = xxx.createExample(parameterOne); // parameterOne is automatically obtained by scanning.

// Provide clear and concise comments in the following typical scenarios:
// 1. The meaning of a variable name or the code logic is not clearly stated in the code.
// 2. A complex algorithm or special syntax is involved.
```

## Classes

> *Writing Instructions:*
>
> 1. This section is optional. Delete it if there is no class. If there are multiple classes, describe them in multiple level-2 headings, prefixed with `##` followed by a space.
> 2. Use the actual class name as the level-2 heading.
> 3. If the class contains both attributes and methods, write the attributes above the methods. Write their actual names in separate level-3 headings.
> 4. If the class contains only attributes, you do not need to create a level-3 heading. Instead, use a table to display the attributes.

Describe the functions, use cases, and restrictions of this class.

### Objects to Import

> *Writing Instructions:*
>
> This section is mandatory. Describes the class creation mode in the form of code segments.

Example:

```
patternLockController: PatternLockController = new PatternLockController()
```

### Attributes

> *Writing Instructions:*
>
> This section is optional. Except that a level-3 heading is used for attributes in classes/interfaces, other instructions are the same as those provided under [Attributes](#attributes).

### Methods in Classes

> *Writing Instructions:*
>
> 1. This section is optional. Use the actual method name as the level-3 heading. **Do not add a prefix.** Example: scrollTo
> 2. You do not need to provide the sample code and sample diagram. Other requirements are the same as those in [Methods](#methods).

## Enums

> *Writing Instructions:*
>
> This section is optional. Describe the enums in the form of level-2 headings.

### FlexDirection enums

| Name           | Description              |
| ------------- | ---------------- |
| Row           | The child components are arranged in the same direction as the main axis runs along the rows. |
| RowReverse    | Center aligned. This is the default alignment mode.    |
| Column        | The child components are arranged in the same direction as the main axis runs down the columns. |
| ColumnReverse | The child components are arranged opposite to the `Column` direction.|

## Objects

> *Writing Instructions:*
>
> 1. This section is optional. Describe the objects in the form of level-2 headings.

### MouseEvent

| Field     | Type  | Description                |
| --------- | ------ | ------------------ |
| timestamp | number | Timestamp when the event is triggered.        |
| screenX   | number | X-coordinate of the clicked point relative to the upper left corner of the screen.|
| screenY   | number | Y-coordinate of the clicked point relative to the upper left corner of the screen.|

## Example

Provide the display effect of the example.

> *Writing Instructions:*
>
> 1. This section is mandatory. Use a level-2 or level-3 heading, and provide sample codes and figures under the heading.
> 2. Use multiple level-3 headings to present the function of a component or module one by one, if the functions are complex.
>
> ```tsx
> // This part is mandatory.
>
> // Check all sample code provided in the example.
> // Minor errors such as missing symbols and variable inconsistency are unacceptable.
> // Declare all variables that are used.
> // Mark the programming language of the sample code.
>
> // Write an actual case that can be easily used, rather than the parameter names themselves. Use comments to describe the content that are not user-defined.
> // Example: var result = xxx.createExample(parameterOne); // parameterOne is automatically obtained by scanning.
>
> // The layout of the image must be clear, the color must be simple and elegant, and the image must be copyrighted.
>
> // Provide clear and concise comments in the following typical scenarios:
> // 1. The meaning of a variable name or the code logic is not self-explanatory.
> // 2. A complex algorithm or special syntax is involved.
> ```

Example:

```ts
// xxx.ets
@Entry
@Component
struct CheckboxExample {
  build() {
    Row() {
      // Generate a check box that is selected by default and can be clicked to display its status.
      Checkbox({name: 'checkbox1',  group: 'checkboxGroup'})
        .select(true)
        .selectedColor(0xed6f21)
        .onChange((value: boolean) => {
          console.info('Checkbox1 change is'+ value)
        })
      // Generate a check box that is not selected by default and can be clicked to display its status.
      Checkbox({name: 'checkbox2',  group: 'checkboxGroup'})
        .select(false)
        .selectedColor(0x39a2db)
        .onChange((value: boolean) => {
          console.info('Checkbox2 change is'+ value)
        })
    }
  }
}
```
<!--no_check-->

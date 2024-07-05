# TS Component Reference Template

## General Writing Instructions

|      | Item            | Writing Instruction                                                        |
| ---- | ------------------ | ------------------------------------------------------------ |
| 1    | Customer-oriented mindset| **Stand in the shoes of developers and provide the use cases, parameter selection principles, recommendations/tips, sample code, and anything else that a developer will need to develop the component.**|
| 2    | Upload path          | Upload markdown files to **docs/en/application-dev/reference/apis-*ExampleKit*-kit/**.<br>Upload images to **docs/en/application-dev/reference/apis-*ExampleKit*-kit/figures**. In addition, reference the image path in the markdown file as follows: **\![]\(figures/exampleImage.jpg)**, **\![]\(figures/exampleImage.png)**, or **\![]\(figures/exampleImage.gif)**.|
| 3    | File name          | Provide one TS component reference document for each .d.ts file. Name the file in the format of `ts-componentClassName-componentName.md`.<br>Examples:<br>For the basic component **\<Text>**, the reference file name is `ts-basic-component-text.md`.<br>For the container component **\<List>**, the reference file name is `ts-container-list.md`.|
| 4    | Directory update          | After uploading a TS component reference document, update the **Readme-EN.md** file in **docs/en/application-dev/reference/apis-*exampleKit*-kit**. |
| 5    | Document structure          | - Component description<br>- Initial version description<br>- Modules to import/Usage description<br>- Child components<br>- APIs, attributes, events, objects, enums, and custom types<br>  The order in which APIs are described in the document must be consistent with that in which they appear in the code. If some APIs have a logical sequence, pay attention to their sequence in the document. |
| 6   | Sample code programming language      | Use code blocks to provide sample code, and mark the programming language ts by adding `// xxx.ets` at the beginning of every sample code block.|
| 7   | Link          | Link format: [Link text]\(Link content)<br>Cross-folder link format: [markdown file name]\(\.\./../xxx/xxx.md). One `../` indicates one upper-level folder.<br>Intra-topic link format: [Interface A<sup>7+</sup>]\(#xxxa7). The text in the intra-topic link must be the same as the title to be linked. In the link, all letters must be in lowercase, and no special character (except the hyphen) or tag is included.|

## Mappings Between .d.ts Tags and Document Fields

Except for @since, document fields mapping to the following tags must be provided under each API.

For an attribute or interface table, if a tag has the same value for all the items in the table, you can place the tag description above the table. Otherwise, place the tag under **NOTE** for each item.

| .d.ts Tag                    | Description    | Document Field                                                    |
| ------------------------------ | -------- | ------------------------------------------------------------ |
| @since                         | Version description| 1. Use the greater-than sign (>) followed by a space to indent the description about the initial version of the component. Unless otherwise marked, all APIs in the component have the same initial version.<br>2. When introducing an API to an existing component, use the `<sup>` tag to mark its initial version. The format is `<sup>versionNumber+</sup>`, for example, `<sup>7+</sup>`.  <br>When introducing an attribute to an existing component, suffix the `<sup>` tag to the new attribute name, for example, `newAttribute<sup>7+</sup>`.<br>When introducing a method to an existing component, suffix the `<sup>` tag to the method name, for example, `getSimIccId<sup>7+</sup>`. The same rule applies to new interfaces, classes, and enums.|
| @deprecated                    | Deprecated description| Do not delete the deprecated content from the document. Instead, suffix `deprecated` as a superscript to the content, and use the greater-than sign (>) to introduce the initial version and deprecated version. If there is no substitute API, provide the substitute solution.<br>Example: abandonmentMethod<sup>(deprecated)</sup><br>> This API is supported since API version 4 and deprecated since API version 7. You are advised to use [newMethod]\(#newmethod) instead.|
| @FAModelOnly / @StageModelOnly | Model restriction description| **Model restriction**: This API can be used only in the FA model. **Model restriction**: This API can be used only in the stage model.|
| @form                          | Widget capability description| **Widget capability**: Since API version *x*, this feature is supported in ArkTS widgets.|
| @systemapi                     | System API description| **System API**: This is a system API.                           |
| @syscap                        | System capability description| **System capability**: SystemCapability.*A.B*                      |
| @permission                    | Permission    | 1. If only one permission is required for using the component, use the following format:<br>**Required permissions**: ohos.permission.examplePermission<br>2. If multiple permissions are required for using the component, provide the permissions with **and** or **or** in the following format:<br>**Required permissions**: ohos.permission.examplePermissionA and ohos.permission.examplePermissionB<br>**Required permissions**: ohos.permission.examplePermissionA or ohos.permission.examplePermissionB|
| @extends                       | Inheritance    | If the tag is carried or the extends relationship exists but the tag is not carried, clearly state the following information: *ExampleA* inherits from *ExampleB* (provide the link of *ExampleB*).|

The following describes the instructions for writing a specific component reference document.

***

# Document Title

> *Writing Instructions*
>
> 1. **Document title**: Use phrases that summarize the component functionalities. Examples: `Button` and `Slider`.
> 2. **Heading levels**: Use the document title as the level-1 heading, which is prefixed with `#` followed by a space. Use the functions, classes, interfaces, enums, and types as level-2 headings, which are prefixed with `##` followed by a space. Use the attributes and functions under classes as level-3 headings, which are prefixed with `###` followed by a space.
> 3. **Initial version description**: Use the greater-than symbol (>) to indent the description about the initial version of the component. Use a line break after **NOTE**.<br>Place the version description after the component description. A component has only one initial version.<br>Use the following sentence: "This component is supported since API version *x*. Newly added APIs will be marked with a superscript to indicate their earliest API version." Change ***x*** to the actual version number.

Describe the component from its functionalities, use cases, and recommendations in this section. 

**Example 1**: \<Marquee>

The **\<Marquee>** component is used to display a scrolling piece of text. The text is scrolled only when its width exceeds the width of the **\<Marquee>** component.

**Example 2**: \<SideBarContainer>

The **\<SideBarContainer>** component contains a sidebar and content area as its child components. The sidebar is the first child component and can be shown or hidden as needed. The content area is the second child component.

> **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

> *Writing Instructions*
>
> 1. This section is optional. Delete it if the document is about a component or universal method.
> 2. This section is mandatory if the document is about an API to be imported.
> 3. Write the modules to import based on the actual conditions. Provide the `import` statement in the form of a code block.<br>**Example:**
>

```js
import Curves from '@ohos.curves'
```

## Child Components

> *Writing Instructions*
>
> 1. This section is mandatory if the document is about a built-in component that contains child components.
> 3. If there are restrictions on the use of child components, describe them here.

Example: Supported

## APIs

>*Writing Instructions*
>
>1. This section is mandatory if the document is about a built-in component and the component has APIs.
>2. The description of the API calling mode must be the same as that in the .d.ts file and include the parameter type and parameter name. 
>3. Add a question mark (?) after the parameter name to mark an optional parameter.
>4. Use English symbols in the complete method name, and add a space after each colon (:).
>5. Do not use a semicolon (;) at the end of the complete method name.
>6. If a custom parameter type (such as object and enum) appears for the first time, describe the parameter type in an unordered list. If this type has been described in other places, use a relative link to reference it.
>7. Note: The angle bracket (<>) may be identified as a label and not displayed. To ensure normal display, you can either add a backslash (\\) (in the format of "\\<>") or use escape characters \&lt; and \&gt;.
>8. Note: The method in the component interface has no return value and is not presented in the form of level-2 or level-3 headings. It must also meet requirements described in [Methods](#methods).
>9. Note: The default value, unit, and value range must be described in a separate line in the description.

If an API has two or more constructors, describe their differences.

Provide the method name in the following format: methodName (parameterName1: parameterType1, parameterName2: parameterType2, ...)<br>If an API involves multiple methods, describe the methods in sequence and set each method name as a level-3 heading.

Examples:

Button(options: ButtonOptions)

Describe the function of the method. If there are usage restrictions, describe them in detail.

**Parameters**

| Name | Type                                   | Mandatory| Description                |
| ------- | --------------------------------------- | ---- | -------------------- |
| options | [ButtonOptions](#buttonoptions) | Yes  | Button settings.|


## Attributes

> *Writing Instructions*
>
> 1. This section is optional. Delete it if there is no attribute.
> 2. The description of the attribute method calling mode must be the same as that in the .d.ts file and include the parameter type and parameter name. 
> 3. Set the attribute method name as a level-3 heading.
> 4. Create a link for a custom type (such as object and enum) to the corresponding interface or enum.
> 5. Note: The default value, unit, and value range must be described in a separate line in the description.

If the document is about a built-in component, specify whether the component supports universal attributes.

Example:

type(value: ButtonType)

Sets the button type.

**Parameters**

| Name| Type                             | Mandatory| Description                                       |
| ------ | --------------------------------- | ---- | ------------------------------------------- |
| value  | [ButtonType](#buttontype) | Yes  | Button type.<br>Default value: ButtonType.Capsule|

## Events

> *Writing Instructions*
>
> 1. This section is optional. Delete it if there is no event.
> 2. The description of the event method calling mode must be the same as that in the .d.ts file and include the parameter type and parameter name. 
> 3. Create a link for a custom type (such as object and enum) to the corresponding interface or enum. If this type appears for the first time, describe it under the event in the form of a level-2 heading. If this type has been described in other places, use a relative link to reference it.

If the document is about a built-in component, specify whether the component supports universal events.

Example:

In addition to the [universal events]\(a relative link to the Universal Events topic), the following events are supported.

onSubmit(callback: (value: string) => void)

Triggered when users click the search icon or the search button, or touch the search button on a soft keyboard.

**Parameters**

| Name| Type| Mandatory| Description                  |
| ------ | -------- | -------- | ---------------------- |
| value  | string   | Yes      | Current text input.|

## Methods

> *Writing Instructions*
>
> 1. This section is optional. Delete it if there is no method. The writing requirements are the same as those provided in [Methods](js-template.md#methods).
> 2. No sample code is required.


## Classes

> *Writing Instructions*
>
> 1. This section is optional. Delete it if there is no class. If there are multiple classes, describe them in separate level-2 headings, prefixed with `##` followed by a space.
> 2. Use the actual class or interface name as the level-2 heading.
> 3. If the class or interface contains both attributes and methods, write the attributes above the methods. Write their actual names in separate level-3 headings. If the API contains only attributes, you do not need to create a level-3 heading. Instead, use a table to display the attributes.

### Attributes

> *Writing Instructions*
>
> This section is optional. Delete it if there is no attribute. The writing requirements are the same as those provided in [Attributes](js-template.md#attributes).

### Methods in Classes

> *Writing Instructions*
>
> 1. This section is optional. Delete it if there is no method in the class. The writing requirements are the same as those provided in [Methods](js-template.md#methods).

## Enums

> *Writing Instructions*
>
> 1. This section is optional. Delete it if there is no enum. The writing requirements are the same as those provided in [Enums](js-template.md#enums).

## Types

> *Writing Instructions*
>
> 1. This section is optional. Delete it if there is no type. The writing requirements are the same as those provided in [Types](js-template.md#types).


## Example

Provide the display effect of the example.

> *Writing Instructions*
>
> 1. This section is mandatory. Use a level-2 or level-3 heading, and provide sample codes and figures under the heading.
> 2. Use multiple level-3 headings to present the function of a component or module one by one, if the functions are complex.
>
> ```tsx
> // This section is mandatory.
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

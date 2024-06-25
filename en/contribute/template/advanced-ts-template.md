# Advanced TS Component Reference Template

## General Writing Instructions

|      | Item            | Writing Instruction                                                        |
| ---- | ------------------ | ------------------------------------------------------------ |
| 1    | Customer-oriented mindset| **Stand in the shoes of developers and provide the use cases, parameter selection principles, recommendations/tips, sample code, and anything else that a developer will need to develop the component.**|
| 2    | Upload path          | Upload markdown files to **docs/en/application-dev/reference/apis-*ExampleKit*-kit/**.<br>Upload images to **docs/en/application-dev/reference/apis-*ExampleKit*-kit/figures**. In addition, reference the image path in the markdown file as follows: **\![]\(figures/exampleImage.jpg)**, **\![]\(figures/exampleImage.png)**, or **\![]\(figures/exampleImage.gif)**.|
| 3    | File name          | Provide one advanced TS component reference document for each .d.ets file. Name the reference document the same as the .d.ets file name, except by changing the dots (.) to hyphens (-).<br>Example:<br>ohos-arkui-advanced-Chip.md |
| 4    | Directory update          | After uploading an advanced TS component reference document, update the **Readme-EN.md** file in **docs/en/application-dev/reference/apis-*exampleKit*-kit**.|
| 5    | Document structure          | - Component description<br>- Initial version description<br>- Modules to import/Usage description<br>- Child components<br>- API description (attributes, constants, methods, enums, and custom types)<br>The order in which APIs are described in the document must be consistent with that in which they appear in the code. If some APIs have a logical sequence, pay attention to their sequence in the document.|
| 6   | Sample code programming language      | Use code blocks to provide sample code, and mark the programming language ts by adding `// xxx.ets` at the beginning of every sample code block.|
| 7   | Link          | Link format: [Link text]\(Link content)<br>Cross-folder link format: [markdown file name]\(\.\./../xxx/xxx.md). One `../` indicates one upper-level folder.<br>Intra-topic link format: [Interface A<sup>7+</sup>]\(#xxxa7). The text in the intra-topic link must be the same as the title to be linked. In the link, all letters must be in lowercase, and no special character (except the hyphen) or tag is included.|

## Mappings Between .d.ets Tags and Document Fields

Except for @since, document fields mapping to the following tags must be provided under each API.

For an attribute or interface table, if a tag has the same value for all the items in the table, you can place the tag description above the table. Otherwise, place the tag under **NOTE** for each item.

| .d.ets Tag                    | Description    | Document Field                                                    |
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





**Example**: @ohos.arkui.advanced.EditableTitleBar (Editable Title Bar)

The editable title bar is a title bar that comes with button icons, typically **Cancel** on the left and **Confirm** on the right, on a multi-select or editing page.

## Modules to Import

> *Writing Instructions*
>
> This section is mandatory. Write the modules to import based on the actual conditions. Provide the `import` statement in the form of a code block.<br>**Example:**
>

```js
import { EditableTitleBar } from "@ohos.arkui.advanced.EditableTitleBar"
```

## Child Components

> *Writing Instructions*
>
> If there are restrictions on the use of child components, describe them here.

Example: The *ExampleA* component can contain the child component *ExampleB*.


## Attributes

> *Writing Instructions*
>
> This section is mandatory. Specify whether universal attributes are supported (with links provided).

Example:

Universal attributes are not supported.

## Events

> *Writing Instructions*
>
> 1. This section is mandatory. Specify whether universal events are supported (with links provided).

Example:

Universal events are not supported.

## Structs

> *Writing Instructions*
>
>  1. This section is optional. Delete it if there is no attribute. If there are multiple classes or interfaces, describe them in separate level-2 headings, prefixed with `##` followed by a space.
>  2. The writing requirements are the same as those provided in [Methods](js-template.md#methods).
>  3. Use the actual struct name as the level-2 heading.
>  4. If the struct or its parameters are modified by a decorator, specify the decorator type.

Example:

ComposeListItem({contentItem?: ContentItem, operateItem?: OperateItem})

**Decorator**: \@Component


**Parameters**


| Name       | Type                       | Mandatory| Decorator| Description                  |
| ----------- | --------------------------- | ---- | ---------- | ---------------------- |
| contentItem | [ContentItem](#contentitem) | No  | \@Prop     | Defines the left and middle elements.|
| operateItem | [OperateItem](#operateitem) | No  | \@Prop     | Defines the right element.        |

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

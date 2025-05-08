# Basic Syntax Overview


With a basic understanding of the ArkTS language, let's look into the composition of ArkTS through an example. As shown below, when the user clicks the button, the text content changes from **Hello World** to **Hello ArkUI**.


  **Figure 1** Example effect drawing 

![Video_2023-03-06_152548](figures/Video_2023-03-06_152548.gif)


In this example, the basic composition of ArkTS is as follows.


  **Figure 2** Basic composition of ArkTS 

![arkts-basic-grammar](figures/arkts-basic-grammar.png)


> **NOTE**
>
> The name of a custom variable cannot be the same as that of any universal attribute or event.


- Decorator: design pattern used to decorate classes, structs, methods, and variables to assign special meanings to them. In the preceding figure, the [@Component](arkts-create-custom-components.md#component) decorator indicates the custom component, the [@Entry](arkts-create-custom-components.md#entry) decorator indicates that the custom component is an entry component, and the [@State](arkts-state.md) decorator indicates the state variables in the component, whose changes trigger the UI re-render.

- [UI description](arkts-declarative-ui-description.md): declarative description of the UI structure, such as the code block of **build()**.

- [Custom component](arkts-create-custom-components.md): reusable UI unit, which can be used with other components, such as the struct **Hello** decorated by @Component.

- Built-in component: default basic or container component preset in ArkTS, which can be directly invoked, such as **Column**, **Text**, **Divider**, and **Button** components in the sample code.

- [Attribute method](../../reference/apis-arkui/arkui-ts/ts-component-general-attributes.md): A component can configure multiple attributes through chain calls, such as **fontSize()**, **width()**, **height()**, and **backgroundColor()**.

- [Event method](../../reference/apis-arkui/arkui-ts/ts-component-general-events.md): A component can set the response logic of multiple events through chain calls, for example, **onClick()** following **Button**.


ArkTS extends multiple syntax paradigms to make development a more enjoyable experience.


- [@Builder](arkts-builder.md)/[@BuilderParam](arkts-builderparam.md): special method for encapsulating UI descriptions. It enables UI descriptions to be encapsulated and reused in a fine-grained manner.

- [@Extend](arkts-extend.md)/[@Styles](arkts-style.md): decorator that extends built-in components and encapsulates attribute styles to combine built-in components more flexibly.

- [stateStyles](arkts-statestyles.md): polymorphic style, which can be set based on the internal state of the component.

##  

 

-  

-  

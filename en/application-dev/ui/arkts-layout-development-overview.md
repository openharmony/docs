# Layout Overview
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @fenglinbailu-->
<!--Designer: @lanshouren-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->


Components are systematically arranged according to layout specifications to construct application pages. In declarative UI, all pages consist of custom components. You can select appropriate layout approaches for page development based on specific requirements.


Layout involves managing the size and position of UI components on user pages using dedicated components or attributes. In practical development, follow this process to ensure overall layout effectiveness:


- Define the layout structure of the page.

- Analyze the composition of elements on the page.

- Select appropriate container components and attributes to control the position and size of each element on the page.


## Layout Structure

A layout is generally in a hierarchical structure. Below is a common page structure.

  **Figure 1** Common page structure

![common-page-structure](figures/common-page-structure.png)

To achieve the preceding effect, you need to declare the corresponding elements on the page. In the preceding information, Page indicates the root node of a page, and elements such as [Column](../reference/apis-arkui/arkui-ts/ts-container-column.md)/[Row](../reference/apis-arkui/arkui-ts/ts-container-row.md) are system components. ArkUI provides a wide variety of layout components, which you can draw on to implement different layouts. For example, you can use **Row** to implement a linear layout.


## Layout Elements

You can use layout-related container components to create a specific layout.

  **Figure 2** Layout elements

![layout-element-composition](figures/layout-element-omposition.png)

- Component area (blue block): size of the component, subject to the [width](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#width) and [height](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#height) attributes.

- Component content area (yellow block): size of the component area minus the [border](../reference/apis-arkui/arkui-ts/ts-universal-attributes-border.md#border) of the component. It serves as the layout constraint for calculating the size of the component content (or child component).

- Component content (green block): size of the component content, for example, size of the text content in the component. The component content may not match the component content area. For example, if fixed **width** and **height** values are set, the actual size of the component content area is determined by subtracting [padding](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#padding) and **border** values from the set size. However, the size of component content is calculated by the layout engine, which may be less than the component content area. In such cases, the component content may not fully occupy the space provided by the component content area. When the component content and component content area do not match, the [align](../reference/apis-arkui/arkui-ts/ts-universal-attributes-location.md#align) attribute takes effect, defining the alignment mode of the component content in the component content area, for example, center aligned.

- Component layout bounds (dotted lines): component area plus the [margins](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#margin) (if supplied). 


## Layout Selection

The declarative UI provides the following common layouts. Choose a layout that best suits the use case.

<!--Table: 30%; 70%-->
| Layout                                                        | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Linear layout](arkts-layout-development-linear.md) (Row and Column)| Use this layout when there are multiple child components and they can be arranged linearly.|
| [Stack layout](arkts-layout-development-stack-layout.md) (Stack)| Use this layout when you want to stack components. The stacking does not occupy or affect the layout space of other components in the same container. For example, when the [Panel](../reference/apis-arkui/arkui-ts/ts-container-panel.md) component is displayed as a child, superimposing it over other components makes more sense. In this case, the stack layout is preferred at the outer layer.|
| [Flex layout](arkts-layout-development-flex-layout.md) (Flex) | The flex layout is similar to the linear layout. However, it empowers the container to adjust the size of its child components to best fill the available space. Use this layout when you need elements to stretch or shrink to fit into the container.|
| [Relative layout](arkts-layout-development-relative-layout.md) (RelativeContainer)| The relative layout is a two-dimensional layout system. It does not need to comply with linear layout rules, and therefore exhibits more flexibility. You can set anchor rules ([AlignRules](../reference/apis-arkui/arkui-ts/ts-universal-attributes-location.md#alignrules9)) on child components to align their positions along the horizontal and vertical axes with the container or other child components within the container. Anchor rules support compression, stretching, stacking, and wrapping of child components. Use this layout when the distribution of elements is complex or when a linear layout may result in deeply nested components in the container.|
| [Responsive grid layout](arkts-layout-development-grid-layout.md) (GridRow and GridCol)| The responsive grid is an auxiliary positioning tool for a multi-device application, with capability of dividing space into rows and columns. Unlike the regular grid, the responsive grid is not allocating fixed-size space. Instead, it allows a layout to dynamically change based on the screen size. In this way, the design and development costs for adapting to different screen sizes are significantly reduced, and the overall design and development process is more orderly and rhythmic. In addition, the responsive grid offers a consistent display experience across devices. Use this layout when you are presenting the same content on different screen sizes.|
| [Dynamic layout](arkts-layout-development-dynamiclayout.md) (DynamicLayout)|**DynamicLayout** supports dynamically switching layout algorithms while preserving the state of child components (such as input field content, scroll position), making it suitable for responsive layout scenarios (for example, landscape/portrait switching). It should be prioritized when the UI page needs to switch between different layout effects at runtime (for example, list, grid, and stack). When implementing custom irregular layouts such as waterfall flow or tag cloud, the custom layout capability of the **DynamicLayout** component is the preferred choice. **DynamicLayout** is supported starting from API version 24.|
| [Container breakpoint (ContainerReader)](arkts-layout-development-container-reader.md)| **ContainerReader** is used to obtain breakpoint information based on the container size and perform responsive layout in dynamic scenarios. This component uses two-way binding to return the container size and breakpoints in real time, enabling you to create and lay out components based on the container size.|
| [Tabs](arkts-navigation-tabs.md)                  | The **Tabs** component can quickly switch between views on a page, improving information search efficiency and reducing the amount of information that users receive at a time.|


## Layout Position

Attributes such as **position** and **offset** affect the position of the layout container relative to itself or other components.

| Positioning Capability| Description                                                    | Implementation                                                    |
| -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Absolute positioning| Absolute positioning is poor in adaptability to devices of different sizes, and is prone to screen adaptation errors.| Use [position](../reference/apis-arkui/arkui-ts/ts-universal-attributes-location.md#position) to implement absolute positioning and set the offset position of the upper left corner of an element relative to the upper left corner of the parent container. When laying out components, this attribute does not affect the layout of the parent component. It only adjusts the component position during drawing.|
| Relative positioning| Relative positioning keeps an element in the normal document flow, while allowing you to move it around relative to its original location.| You can use [offset](../reference/apis-arkui/arkui-ts/ts-universal-attributes-location.md#offset) to implement relative positioning and set the offset of an element relative to itself. This attribute does not affect the layout of the parent component. It only adjusts the component position during drawing.|


## Constraints on Child Components

* Stretching: When the size of a container component changes, the increased or decreased amount of space is allocated to the specified area in the container component.

  [flexGrow](../reference/apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexgrow) and [flexShrink](../reference/apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexshrink) attributes:
  1. **flexGrow** defines the grow factor of a flex item.
  2. **flexShrink** defines the shrink factor of a flex item.

* Scaling: The width and height of a child component change with the container component, with its aspect ratio fixed at the preset value.

  The [aspectRatio](../reference/apis-arkui/arkui-ts/ts-universal-attributes-layout-constraints.md#aspectratio) attribute specifies the aspect ratio of the current component. The formula is as follows: aspectRatio = width/height.

* Proportion: The width and height of child components to adjust dynamically in response to changes in the size of the container component, according to the preset proportion value.

  Two implementation modes are available with the universal attributes:
  1. Set the width and height of child components using percentage values.

      | Parent and Ancestor Component Configuration| Child Component Reference Basis|
      |---|---|
      | The parent component sets the width or height, and the ancestor component does not specify the parent's width or height.| Parent component's actual width and height|
      | The parent component sets the width or height, and the ancestor component specifies the parent's width or height.| Parent component's width and height specified by the ancestor component|
      | The parent component does not set the width or height, and the ancestor component specifies the parent's width or height| Parent component's width and height specified by the ancestor component|
      | The parent component does not set the width or height, and the ancestor component does not specify the parent's width or height| Percentage reference inherited from the parent component. Since the parent component does not specify the width or height, this reference is passed down from the ancestor component.|
  2. Use the [layoutWeight](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#layoutweight) attribute to enable the child components to adaptively occupy the remaining space.

* Hiding: The child components in a container component are shown or hidden according to their preset display priority as the container component's size changes. Child components with the same display priority are shown or hidden at the same time.

  This feature is governed by the [displayPriority](../reference/apis-arkui/arkui-ts/ts-universal-attributes-layout-constraints.md#displaypriority) attribute, which dictates the visibility of components.

<!--Del-->## Samples

The following samples are provided to help you better understand the layout development:

- [Page Layout and Connection (ArkTS) (API9)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/UI/ArkTsComponentCollection/DefiningPageLayoutAndConnection)

- [Common Alignment Modes of ArkUI Layout Containers (ArkTS) (API9)](https://gitcode.com/openharmony/codelabs/tree/master/ETSUI/OHLayoutAlign)

- [Common Components and Layouts (ArkTS) (API9)](https://gitcode.com/openharmony/codelabs/tree/master/ETSUI/ArkTSComponents)<!--DelEnd-->

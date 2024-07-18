# Using the FrameNode Extension of ArkUI to Implement the Dynamic Layout Framework
## Overview
The dynamic layout framework is a lightweight framework that dynamically generates a native component tree. It can dynamically push new content to users without bringing applications online again based on operation requirements. The framework uses syntax similar to CSS to control the position, size, and alignment of a view by setting different style attributes. This article describes how to use the FrameNode extension of ArkUI to implement a dynamic layout class framework and its performance benefits.
## Advantages of Declarative Extension of ArkUI in Dynamic Framework Interconnection Scenarios
### Faster component creation
When the declarative front-end development mode is used, if the customized component of ArkUI is used to define each node in the node tree, the node creation efficiency is low. This is mainly because each node needs to allocate memory space in the JS engine to store the custom components and state variables of the application. In addition, during node creation, operations such as component ID, component closure, and dependency collection between state variables must be performed. In contrast, using the FrameNode extension of ArkUI avoids creating custom component objects and state variable objects and does not require dependency collection, significantly improving the speed of component creation.
### Faster component update
In the update scenario of the dynamic layout framework, there is usually a UI component tree TreeA created by the tree data structure ViewModelA. When the new data structure ViewModelB needs to be used to update TreeA, although the declarative front end can implement data-driven automatic update, this process is accompanied by a large number of diff operations. For the JS engine, when the diff algorithm is executed on a complex component tree (with a depth of more than 30 layers and containing 100 to 200 components), it is almost impossible to keep full frame running at a refresh rate of 120 Hz. However, with the FrameNode extension of ArkUI, the framework can independently control the update process and implement efficient on-demand pruning. Especially for dynamic layout frameworks that serve only a few specific businesses, this extension enables extremely rapid update operations.
### Directly operate the component tree.
When the declarative front end is used, it is difficult to update the component tree structure. For example, a subtree in the component tree is completely moved from the current child node to another child node, as shown in the following figure.
![](./figures/imperative_dynamic_layouts_component_tree.jpg)
The declarative front end cannot directly adjust the structure relationship of component instances. The preceding operations can be implemented only by re-rendering the entire component tree. If the FrameNode extension of ArkUI is used, you can operate the FrameNode to easily control the subtree and port the subtree to another node. In this way, only partial rendering and refreshing are performed, and the performance is better.
## Scenario Examples
The video home page is used as a scenario to describe how to use the FrameNode extension of ArkUI.
### Declarative Extension Usage of ArkUI
The DSL of a simplified dynamic layout framework generally uses data exchange formats such as JSON and XML to describe the UI. The following uses JSON as an example.
The following table describes the core fields in this case.
| Alpha tag.    | Description                                                                     |
|---------|---------------------------------------------------------------------------|
| type    |Type of a UI component, which corresponds to a native component or a component encapsulated by the framework based on native capabilities.|
| content |Content of Text and Image Components                                                        |
| css     |Describe the layout features of UI components.                                                         |

1. Define the UI description data of the video home page as follows:
```json
{
  "type": "Column",
  "css": {
    "width": "100%"
  },
  "children": [
    {
      "type": "Row",
      "css": {
        "width": "100%",
        "padding": {
          "left": 15,
          "right": 15
        },
        "margin": {
          "top": 5,
          "bottom": 5
        },
        "justifyContent": "FlexAlign.SpaceBetween"
      },
      "children": [
        {
          "type": "Text",
          "css": {
            "fontSize": 24,
            "fontColor": "#ffffff"
          },
          "content": "Homepage"
        },
        {
          "type": "Image",
          "css": {
            "width": 24,
            "height": 24
          },
          "content": "app.media.search"
        }
      ]
    },
    {
      "type": "Swiper",
      "css": {
        "width": "100%"
      },
      "children": [
        {
          "id": "Carousel",
          "type": "Image",
          "css": {
            "height": "40%",
            "width": "100%"
          },
          "content": "app.media.movie1"
        },
        {
          "id": "Carousel",
          "type": "Image",
          "css": {
            "height": "40%",
            "width": "100%"
          },
          "content": "app.media.movie2"
        },
        {
          "id": "Carousel",
          "type": "Image",
          "css": {
            "height": "40%",
            "width": "100%"
          },
          "content": "app.media.movie3"
        }
      ]
    },
    {
      "type": "Row",
      "css": {
        "width": "100%",
        "padding": {
          "left": 15,
          "right": 15
        },
        "margin": {
          "top": 15,
          "bottom": 15
        },
        "justifyContent": "FlexAlign.SpaceBetween"
      },
      "children": [
        {
          "type": "Text",
          "css": {
            "width": 75,
            "height": 40,
            "borderRadius": 60,
            "fontColor": "#000000",
            "backgroundColor": "#ffffff"
          },
          "content": "Featured"
        },
        {
          "type": "Text",
          "css": {
            "width": 75,
            "height": 40,
            "borderRadius": 60,
            "fontColor": "#000000",
            "backgroundColor": "#808080"
          },
          "content": "TV series"
        },
        {
          "type": "Text",
          "css": {
            "width": 75,
            "height": 40,
            "borderRadius": 60,
            "fontColor": "#000000",
            "backgroundColor": "#808080"
          },
          "content": "Movie"
        },
        {
          "type": "Text",
          "css": {
            "width": 75,
            "height": 40,
            "borderRadius": 60,
            "fontColor": "#000000",
            "backgroundColor": "#808080"
          },
          "content": "Variety show"
        }
      ]
    },
    {
      "type": "Row",
      "css": {
        "width": "100%",
        "padding": {
          "left": 15,
          "right": 15
        },
        "margin": {
          "top": 5,
          "bottom": 5
        },
        "justifyContent": "FlexAlign.SpaceBetween"
      },
      "children": [
        {
          "type": "Text",
          "css": {
            "fontSize": 24,
            "fontColor": "#ffffff"
          },
          "content": "Daily recommendation"
        },
        {
          "type": "Text",
          "css": {
            "fontSize": 20,
            "fontColor": "#ffffff",
            "opacity": 0.5
          },
          "content": "More"
        }
      ]
    },
    {
      "type": "Row",
      "css": {
        "width": "100%",
        "padding": {
          "left": 15,
          "right": 15
        },
        "margin": {
          "top": 5,
          "bottom": 5
        },
        "justifyContent": "FlexAlign.SpaceBetween"
      },
      "children": [
        {
          "type": "Column",
          "css": {
            "alignItems": "HorizontalAlign.Start"
          },
          "children": [
            {
              "type": "Image",
              "css": {
                "height": 120,
                "width": 170,
                "borderRadius": 10
              },
              "content": "app.media.movie4"
            },
            {
              "type": "Text",
              "css": {
                "fontColor": "#ffffff"
              },
              "content": "Volunteer Army: Male Soldiers"
            }
          ]
        },
        {
          "type": "Column",
          "css": {
            "alignItems": "HorizontalAlign.Start"
          },
          "children": [
            {
              "type": "Image",
              "css": {
                "height": 120,
                "width": 170,
                "borderRadius": 10
              },
              "content": "app.media.movie5"
            },
            {
              "type": "Text",
              "css": {
                "fontColor": "#ffffff"
              },
              "content": "King of Long Space"
            }
          ]
        }
      ]
    },
    {
      "id": "changeCarouselImageHeight",
      "type": "Text",
      "css": {
        "width": 180,
        "height": 40,
        "borderRadius": 60,
        "fontColor": "#ffffff",
        "backgroundColor": "#0000FF"
      },
      "content": "Change the height of the carousel image."
    }
  ]
}
```
2. Define the corresponding data structure to receive the UI description data as follows:
```ts
class VM {
  type?: string
  content?: string
  css?: ESObject
  children?: VM[]
  id?: string
}
```
3. Customize the DSL parsing logic and use carouselNodes to save carousel nodes to facilitate subsequent node update.
```ts
let carouselNodes: typeNode.Image[] = [];

function FrameNodeFactory(vm: VM, context: UIContext): FrameNode | null {
  if (vm.type === "Column") {
    let node = typeNode.createNode(context, "Column");
    setColumnNodeAttr(node, vm.css);
    vm.children?.forEach(kid => {
      let child = FrameNodeFactory(kid, context);
      node.appendChild(child);
    });
    return node;
  } else if (vm.type === "Row") {
    let node = typeNode.createNode(context, "Row");
    setRowNodeAttr(node, vm.css);
    vm.children?.forEach(kid => {
      let child = FrameNodeFactory(kid, context);
      node.appendChild(child);
    });
    return node;
  } else if (vm.type === "Swiper") {
    let node = typeNode.createNode(context, "Swiper");
    node.attribute.width(vm.css.width);
    node.attribute.height(vm.css.height);
    vm.children?.forEach(kid => {
      let child = FrameNodeFactory(kid, context);
      node.appendChild(child);
    });
    return node;
  } else if (vm.type === "Image") {
    let node = typeNode.createNode(context, "Image");
    node.attribute.width(vm.css.width);
    node.attribute.height(vm.css.height);
    node.attribute.borderRadius(vm.css.borderRadius);
    node.attribute.objectFit(ImageFit.Fill)
    node.initialize($r(vm.content));
    if (vm.id === "Carousel") {
      carouselNodes.push(node);
    }
    return node;
  } else if (vm.type === "Text") {
    let node = typeNode.createNode(context, "Text");
    node.attribute.fontSize(vm.css.fontSize);
    node.attribute.width(vm.css.width);
    node.attribute.height(vm.css.height);
    node.attribute.width(vm.css.width)
    node.attribute.borderRadius(vm.css.borderRadius)
    node.attribute.backgroundColor(vm.css.backgroundColor);
    node.attribute.fontColor(vm.css.fontColor);
    node.attribute.opacity(vm.css.opacity);
    node.attribute.textAlign(TextAlign.Center)
    //Add a click event to the button to control the height change of the carousel image.
    if (vm.id === 'changeCarouselImageHeight') {
      node.attribute.onClick(() => {
        carouselNodes[0].attribute.height('50%');
        carouselNodes[1].attribute.height('50%');
        carouselNodes[2].attribute.height('50%');
        node.attribute.visibility(Visibility.Hidden);
      })
    }
    node.initialize(vm.content);
    return node;
  }
  return null;
}

function setColumnNodeAttr(node: typeNode.Column, css: ESObject) {
  node.attribute.width(css.width);
  node.attribute.height(css.height);
  node.attribute.backgroundColor(css.backgroundColor);
  if (css.alignItems === "HorizontalAlign.Start") {
    node.attribute.alignItems(HorizontalAlign.Start)
  }
}

function setRowNodeAttr(node: typeNode.Row, css: ESObject) {
  node.attribute.width(css.width);
  if (css.padding !== undefined) {
    node.attribute.padding(css.padding as Padding)
  }
  if (css.margin !== undefined) {
    node.attribute.margin(css.margin as Padding)
  }
  node.attribute.justifyContent(FlexAlign.SpaceBetween)
}
```
4. Use the NodeContainer component to nest the FrameNode extension of ArkUI and the declarative syntax of ArkUI as follows:
```ts
class ImperativeController extends NodeController {
  makeNode(uiContext: UIContext): FrameNode | null {
    return FrameNodeFactory(data, uiContext);
  }
}

@Entry
@Component
struct Page2 {
  controller: ImperativeController = new ImperativeController();
  build() {
    Column() {
      NodeContainer(this.controller)
    }
    .height('100%')
    .width('100%')
    .backgroundColor(Color.Black)
  }
}
```
## Performance Comparison
The two solutions in the scenario example are used to capture trace messages for performance analysis and comparison.
1. The completion latency of the declarative front-end development mode is 9.8 ms. (The data varies depending on the device and scenario. The data is for reference only.) See the following figure.
![](./figures/imperative_dynamic_layouts_trace_1.png)
2. The completion latency in FrameNode expansion mode is 7.6 ms. (The data varies depending on the device and scenario. This data is for reference only.) The following figure shows the completion latency in FrameNode expansion mode.
![](./figures/imperative_dynamic_layouts_trace_2.png)
## Summary
To sum up, in dynamic layout scenarios, compared with declarative writing, FrameNode extension using ArkUI has more advantages and brings more performance benefits. Therefore, you are advised to use the FrameNode extension of ArkUI in dynamic layout framework scenarios.

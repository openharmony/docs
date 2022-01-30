# Stack<a name="EN-US_TOPIC_0000001237555083"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The  **<Stack\>**  component provides a stack container where child components are successively stacked and the latter one overwrites the previous one.

## Required Permissions<a name="section1073795814133"></a>

None

## Child Component<a name="section152511941148"></a>

The  **<Stack\>**  component can contain child components.

## APIs<a name="section13412231148"></a>

Stack\(value:\{alignContent?: Alignment\}\)

-   Parameters

    <a name="table4921710102813"></a>
    <table><thead align="left"><tr id="row16921106280"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p189271012814"><a name="p189271012814"></a><a name="p189271012814"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.580000000000002%" id="mcps1.1.6.1.2"><p id="p10925103287"><a name="p10925103287"></a><a name="p10925103287"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.67%" id="mcps1.1.6.1.3"><p id="p1592141092815"><a name="p1592141092815"></a><a name="p1592141092815"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.42%" id="mcps1.1.6.1.4"><p id="p392141012813"><a name="p392141012813"></a><a name="p392141012813"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.22%" id="mcps1.1.6.1.5"><p id="p1092710192810"><a name="p1092710192810"></a><a name="p1092710192810"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row119261002816"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p39218100280"><a name="p39218100280"></a><a name="p39218100280"></a>alignContent</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.580000000000002%" headers="mcps1.1.6.1.2 "><p id="p692141011284"><a name="p692141011284"></a><a name="p692141011284"></a><a href="ts-appendix-enums.md#section1145418513159">Alignment</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.3 "><p id="p392141018289"><a name="p392141018289"></a><a name="p392141018289"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.6.1.4 "><p id="p092141092820"><a name="p092141092820"></a><a name="p092141092820"></a>Center</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p id="p11923108283"><a name="p11923108283"></a><a name="p11923108283"></a>Alignment of child components in the container.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section11271205310156"></a>

```
@Entry
@Component
struct StackExample {
  build() {
    Stack({ alignContent: Alignment.Bottom }) {
      Text('First child, show in bottom').width('90%').height('100%').backgroundColor(0xd2cab3).align(Alignment.Top)
      Text('Second child, show in top').width('70%').height('60%').backgroundColor(0xc1cbac).align(Alignment.Top)
    }.width('100%').height(150).margin({ top: 5 })
  }
}
```

![](figures/stack.jpg)


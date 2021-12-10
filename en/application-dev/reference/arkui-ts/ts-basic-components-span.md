# Span<a name="EN-US_TOPIC_0000001112938338"></a>

The <Span\> component is used to display a paragraph of textual information. It can be used only as a child component in the  **<Text\>**  component.

## Required Permissions<a name="section6238143720229"></a>

None

## Child Components<a name="section163926568224"></a>

None

## APIs<a name="section769166122319"></a>

Span\(content: string\)

-   Parameters

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="13%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.869999999999997%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.01%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1093021911217"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>content</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.869999999999997%" headers="mcps1.1.6.1.4 "><p id="p421641117507"><a name="p421641117507"></a><a name="p421641117507"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p693016198212"><a name="p693016198212"></a><a name="p693016198212"></a>Text content.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section11378635172316"></a>

The universal attribute methods support only the common text style.

<a name="table952mcpsimp"></a>
<table><thead align="left"><tr id="row959mcpsimp"><th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.1"><p id="p961mcpsimp"><a name="p961mcpsimp"></a><a name="p961mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="26.009999999999998%" id="mcps1.1.5.1.2"><p id="p963mcpsimp"><a name="p963mcpsimp"></a><a name="p963mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="21.790000000000003%" id="mcps1.1.5.1.3"><p id="p965mcpsimp"><a name="p965mcpsimp"></a><a name="p965mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="36.199999999999996%" id="mcps1.1.5.1.4"><p id="p967mcpsimp"><a name="p967mcpsimp"></a><a name="p967mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row163041291058"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p63041596511"><a name="p63041596511"></a><a name="p63041596511"></a>decoration</p>
</td>
<td class="cellrowborder" valign="top" width="26.009999999999998%" headers="mcps1.1.5.1.2 "><p id="p531151195414"><a name="p531151195414"></a><a name="p531151195414"></a>{</p>
<p id="p790212415415"><a name="p790212415415"></a><a name="p790212415415"></a>type: <a href="ts-appendix-enums.md#section81063305178">TextDecorationType</a>,</p>
<p id="p7196189541"><a name="p7196189541"></a><a name="p7196189541"></a>color?: Color</p>
<p id="p4225174410519"><a name="p4225174410519"></a><a name="p4225174410519"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="21.790000000000003%" headers="mcps1.1.5.1.3 "><p id="p128501411541"><a name="p128501411541"></a><a name="p128501411541"></a>{</p>
<p id="p186271915542"><a name="p186271915542"></a><a name="p186271915542"></a>type: TextDecorationType.None</p>
<p id="p23053910513"><a name="p23053910513"></a><a name="p23053910513"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="36.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p12726144512611"><a name="p12726144512611"></a><a name="p12726144512611"></a>Style and color of the text decorative line.</p>
</td>
</tr>
<tr id="row2542164915718"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.1 "><p id="p1542849972"><a name="p1542849972"></a><a name="p1542849972"></a>textCase</p>
</td>
<td class="cellrowborder" valign="top" width="26.009999999999998%" headers="mcps1.1.5.1.2 "><p id="p1454214498717"><a name="p1454214498717"></a><a name="p1454214498717"></a><a href="ts-appendix-enums.md#section1276124151715">TextCase</a></p>
</td>
<td class="cellrowborder" valign="top" width="21.790000000000003%" headers="mcps1.1.5.1.3 "><p id="p85421449872"><a name="p85421449872"></a><a name="p85421449872"></a>Normal</p>
</td>
<td class="cellrowborder" valign="top" width="36.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p75429492719"><a name="p75429492719"></a><a name="p75429492719"></a>Text case.</p>
</td>
</tr>
</tbody>
</table>

## Events<a name="section1093554116361"></a>

Among all the universal events, only the click event is supported.

## Example<a name="section21711157202411"></a>

```
@Entry
@Component
struct SpanExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Basic Usage').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('This is the Span component').fontSize(12).textCase(TextCase.Normal)
          .decoration({ type: TextDecorationType.None, color: Color.Red })
      }

      Text('Text Decoration').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('I am Underline-span').decoration({ type: TextDecorationType.Underline, color: Color.Red }).fontSize(12)
      }
      Text() {
        Span('I am LineThrough-span').decoration({ type: TextDecorationType.LineThrough, color: Color.Red }).fontSize(12)
      }
      Text() {
        Span('I am Overline-span').decoration({ type: TextDecorationType.Overline, color: Color.Red }).fontSize(12)
      }

      Text('Text Case').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('I am Lower-span').textCase(TextCase.LowerCase).fontSize(12)
          .decoration({ type: TextDecorationType.None, color: Color.Red })
      }
      Text() {
        Span('I am Upper-span').textCase(TextCase.UpperCase).fontSize(12)
          .decoration({ type: TextDecorationType.None, color: Color.Red })
      }
    }.width('100%').height(250).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![](figures/span.gif)


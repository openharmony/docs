# Slelect<a name="ZH-CN_TOPIC_0000001193075098"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

提供下拉选择按钮，可以让用户在多个选项之间选择。

## 权限列表<a name="section781125411508"></a>

无

## 子组件<a name="section53281531154915"></a>

无

## 接口<a name="section1989913519718"></a>

Select(options: Array&lt;SelectOption</a>&gt;)

-   `SelectOption`参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="26.01%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.99%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.709999999999999%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.18%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p>string | <a href="https://gitee.com/superFat/docs/blob/qiyi_select_docs_0122/zh-cn/application-dev/ui/ts-types.md">Resource</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="11.99%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.709999999999999%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.18%" headers="mcps1.1.6.1.5 "><p>下拉选项内容。</p>
    </td>
    </tr>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" 
    headers="mcps1.1.6.1.1 "><p>icon</p>
    </td> 
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p>string | <a href="https://gitee.com/superFat/docs/blob/qiyi_select_docs_0122/zh-cn/application-dev/ui/ts-types.md">Resource</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="11.99%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.709999999999999%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.18%" headers="mcps1.1.6.1.5 "><p>下拉选项图片。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section18430105671014"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.72%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.33%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="17.62%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="47.33%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="18.72%" headers="mcps1.1.5.1.1 "><p>selected</p>
</td>
<td class="cellrowborder" valign="top" width="16.33%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="47.33%" headers="mcps1.1.5.1.4 "><p>设置下拉菜单选择项序号，从0开始。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.72%" headers="mcps1.1.5.1.1 "><p>value</p>
</td>
<td class="cellrowborder" valign="top" width="16.33%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="47.33%" headers="mcps1.1.5.1.4 "><p>设置下拉按钮本身的文本显示。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.72%" headers="mcps1.1.5.1.1 "><p>font</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>size?: Length,</p>
<p>weight?: number | <a href="ts-universal-attributes-text-style.md#li24391125115311">FontWeight</a>,</p>
<p>family?: string,</p>
<p>style?: <a href="ts-basic-components-textarea.md#table952mcpsimp">FontStyle</a></p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="43.28%" headers="mcps1.1.5.1.4 "><p>设置select文本样式：</p>
<ul><li>size: 设置文本尺寸，Length为number类型时，使用fp单位。</li><li>weight: 设置文本的字体粗细，number类型取值[100, 900]，取值间隔为100，默认为400，取值越大，字体越粗。</li><li>family: 设置文本的字体列表。使用多个字体，使用','进行分割，优先级按顺序生效。例如：'Arial, sans-serif'。</li><li>style: 设置文本的字体样式。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.72%" headers="mcps1.1.5.1.1 "><p>fontColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.33%" headers="mcps1.1.5.1.2 "><p>Color | <a href="https://gitee.com/superFat/docs/blob/qiyi_select_docs_0122/zh-cn/application-dev/ui/ts-types.md">Resource</a></p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="47.33%" headers="mcps1.1.5.1.4 "><p>设置下拉按钮本身的文本颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.72%" headers="mcps1.1.5.1.1 "><p>selectedOptionBgColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.33%" headers="mcps1.1.5.1.2 "><p>Color | <a href="https://gitee.com/superFat/docs/blob/qiyi_select_docs_0122/zh-cn/application-dev/ui/ts-types.md">Resource</a></p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="47.33%" headers="mcps1.1.5.1.4 "><p>设置下拉菜单选中项的背景色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.72%" headers="mcps1.1.5.1.1 "><p>selectedOptionFont</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>size?: Length,</p>
<p>weight?: number | <a href="ts-universal-attributes-text-style.md#li24391125115311">FontWeight</a>,</p>
<p>family?: string,</p>
<p>style?: <a href="ts-basic-components-textarea.md#table952mcpsimp">FontStyle</a></p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="43.28%" headers="mcps1.1.5.1.4 "><p>设置已选中option的文本样式：</p>
<ul><li>size: 设置文本尺寸，Length为number类型时，使用fp单位。</li><li>weight: 设置文本的字体粗细，number类型取值[100, 900]，取值间隔为100，默认为400，取值越大，字体越粗。</li><li>family: 设置文本的字体列表。使用多个字体，使用','进行分割，优先级按顺序生效。例如：'Arial, sans-serif'。</li><li>style: 设置文本的字体样式。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.72%" headers="mcps1.1.5.1.1 "><p>selectedOptionFontColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.33%" headers="mcps1.1.5.1.2 "><p>Color | <a href="https://gitee.com/superFat/docs/blob/qiyi_select_docs_0122/zh-cn/application-dev/ui/ts-types.md">Resource</a></p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="47.33%" headers="mcps1.1.5.1.4 "><p>设置下拉菜单选中项的文本颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.72%" headers="mcps1.1.5.1.1 "><p>optionBgColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.33%" headers="mcps1.1.5.1.2 "><p>Color | <a href="https://gitee.com/superFat/docs/blob/qiyi_select_docs_0122/zh-cn/application-dev/ui/ts-types.md">Resource</a></p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="47.33%" headers="mcps1.1.5.1.4 "><p>设置下拉菜单项的背景色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.72%" headers="mcps1.1.5.1.1 "><p>optionFont</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>size?: Length,</p>
<p>weight?: number | <a href="ts-universal-attributes-text-style.md#li24391125115311">FontWeight</a>,</p>
<p>family?: string,</p>
<p>style?: <a href="ts-basic-components-textarea.md#table952mcpsimp">FontStyle</a></p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="13.239999999999998%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="43.28%" headers="mcps1.1.5.1.4 "><p>设置option文本样式：</p>
<ul><li>size: 设置文本尺寸，Length为number类型时，使用fp单位。</li><li>weight: 设置文本的字体粗细，number类型取值[100, 900]，取值间隔为100，默认为400，取值越大，字体越粗。</li><li>family: 设置文本的字体列表。使用多个字体，使用','进行分割，优先级按顺序生效。例如：'Arial, sans-serif'。</li><li>style: 设置文本的字体样式。</li></ul>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.72%" headers="mcps1.1.5.1.1 "><p>optionFontColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.33%" headers="mcps1.1.5.1.2 "><p>Color | <a href="https://gitee.com/superFat/docs/blob/qiyi_select_docs_0122/zh-cn/application-dev/ui/ts-types.md">Resource</a></p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="47.33%" headers="mcps1.1.5.1.4 "><p>设置下拉菜单项的文本颜色。</p>
</td>
</tr>
</tbody>
</table>


## 事件<a name="section449664852016"></a>

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onSelected(callback: (index: number, value?:string) =&gt; void）</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>下拉菜单选中某一项的回调。</p>
<p>index：选中项的索引。</p>
<p>value：选中项的值。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section13800193662114"></a>

```
@Entry
@Component
struct SliderExample {
  @State index: number = 0
  build() {
    Column() {
      Select([{value:'aaa',icon: "/common/1.png"},
              {value:'bbb',icon: "/common/2.png"},
              {value:'ccc',icon: "/common/3.png"},
              {value:'ddd',icon: "/common/4.png"}])
        .selected(2)
        .value('TTT')
        .font({size: 30, weight:900, family: 'serif', style: FontStyle.Normal })
        .selectedOptionFont({size: 30, weight: 900, family: 'serif', style: FontStyle.Normal })
        .optionFont({size: 30, weight: 900, family: 'serif', style: FontStyle.Normal })
        .onSelected((index:number)=>{
          console.info("Select:" + index)
        })
    }
  }
}
```

![](figures/select.png)
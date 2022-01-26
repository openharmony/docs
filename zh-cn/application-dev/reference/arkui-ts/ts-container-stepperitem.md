# StepperItem<a name="ZH-CN_TOPIC_0000001192755138"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

步骤导航器元素。


## 权限列表<a name="section53281531154915"></a>

无

## 子组件<a name="section5989144051714"></a>

支持单个子组件。

## 接口<a name="section97451749121712"></a>

StepperItem\(\)

## 属性<a name="section17430171102911"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.851785178517854%" id="mcps1.1.5.1.1"><p>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="10.501050105010503%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="21.192119211921195%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="50.455045504550455%" id="mcps1.1.5.1.4"><p>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="17.851785178517854%" headers="mcps1.1.5.1.1 "><p>prevLabel</p>
</td>
<td class="cellrowborder" valign="top" width="10.501050105010503%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="21.192119211921195%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.455045504550455%" headers="mcps1.1.5.1.4 "><p>当步骤导航器大于一页，除第一页默认值都为"返回"。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.851785178517854%" headers="mcps1.1.5.1.1 "><p>nextLabel</p>
</td>
<td class="cellrowborder" valign="top" width="10.501050105010503%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="21.192119211921195%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.455045504550455%" headers="mcps1.1.5.1.4 "><p>步骤导航器大于一页时，最后一页默认值为"开始"，其余页默认值为"下一步"。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.851785178517854%" headers="mcps1.1.5.1.1 "><p>status</p>
</td>
<td class="cellrowborder" valign="top" width="10.501050105010503%" headers="mcps1.1.5.1.2 "><p><a href="#li1343015152912">ItemState</a></p>
</td>
<td class="cellrowborder" valign="top" width="21.192119211921195%" headers="mcps1.1.5.1.3 "><p>ItemState.Normal</p>
</td>
<td class="cellrowborder" valign="top" width="50.455045504550455%" headers="mcps1.1.5.1.4 "><p>步骤导航器元素的状态。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li1343015152912"></a>ItemState枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="28.360000000000003%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="71.64%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="28.360000000000003%" headers="mcps1.1.3.1.1 "><p>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.64%" headers="mcps1.1.3.1.2 "><p>正常状态，右侧文本按钮正常显示，可点击进入下一个StepperItem。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="28.360000000000003%" headers="mcps1.1.3.1.1 "><p>Disabled</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.64%" headers="mcps1.1.3.1.2 "><p>不可用状态，右侧文本按钮灰度显示，不可点击进入下一个StepperItem。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="28.360000000000003%" headers="mcps1.1.3.1.1 "><p>Waiting</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.64%" headers="mcps1.1.3.1.2 "><p>等待状态，右侧文本按钮不显示，使用等待进度条，不可点击进入下一个StepperItem。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="28.360000000000003%" headers="mcps1.1.3.1.1 "><p>Skip</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.64%" headers="mcps1.1.3.1.2 "><p>跳过状态，表示跳过当前步骤, 进入下一个StepperItem。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section1131255321814"></a>

见[Stepper](ts-container-stepper.md)。


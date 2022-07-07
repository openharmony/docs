# IInputInterface<a name="ZH-CN_TOPIC_0000001290840932"></a>

## **概述**<a name="section303822826083932"></a>

**所属模块:**

[Input](_input.md)

## **汇总**<a name="section1950616075083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table2078121164083932"></a>
<table><thead align="left"><tr id="row578515794083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p262872430083932"><a name="p262872430083932"></a><a name="p262872430083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p492835527083932"><a name="p492835527083932"></a><a name="p492835527083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1929987271083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p486929283083932"><a name="p486929283083932"></a><a name="p486929283083932"></a><a href="_i_input_interface.md#a539baf2f3554b901abd4820e521ac0ea">iInputManager</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry827647027083932p0"><a name="entry827647027083932p0"></a><a name="entry827647027083932p0"></a>input设备的设备管理接口。</p>
</td>
</tr>
<tr id="row58691697083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p143458959083932"><a name="p143458959083932"></a><a name="p143458959083932"></a><a href="_i_input_interface.md#a0da92e255529827b823c19071f50fa27">iInputController</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1610430680083932p0"><a name="entry1610430680083932p0"></a><a name="entry1610430680083932p0"></a>input设备的业务控制接口。</p>
</td>
</tr>
<tr id="row1057280210083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1599743099083932"><a name="p1599743099083932"></a><a name="p1599743099083932"></a><a href="_i_input_interface.md#a592d65e0a8ad8e9bc0241a0be50669d0">iInputReporter</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry850915605083932p0"><a name="entry850915605083932p0"></a><a name="entry850915605083932p0"></a>input设备的数据上报接口。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1236984387083932"></a>

定义用于提供输入设备驱动能力的接口。

## **类成员变量说明**<a name="section106886465083932"></a>

## iInputController<a name="a0da92e255529827b823c19071f50fa27"></a>

```
[InputController](_input_controller.md)* IInputInterface::iInputController
```

**描述：**

input设备的业务控制接口

## iInputManager<a name="a539baf2f3554b901abd4820e521ac0ea"></a>

```
[InputManager](_input_manager.md)* IInputInterface::iInputManager
```

**描述：**

input设备的设备管理接口

## iInputReporter<a name="a592d65e0a8ad8e9bc0241a0be50669d0"></a>

```
[InputReporter](_input_reporter.md)* IInputInterface::iInputReporter
```

**描述：**

input设备的数据上报接口


# IInputInterface<a name="ZH-CN_TOPIC_0000001055039518"></a>

-   [Overview](#section978084790165631)
-   [Summary](#section421144492165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section2072978642165631)
-   [Field](#section789099418165631)
-   [iInputController](#a0da92e255529827b823c19071f50fa27)
-   [iInputManager](#a539baf2f3554b901abd4820e521ac0ea)
-   [iInputReporter](#a592d65e0a8ad8e9bc0241a0be50669d0)

## **Overview**<a name="section978084790165631"></a>

**Related Modules:**

[Input](Input.md)

**Description:**

Defines interfaces for providing driver capabilities of input devices. 

## **Summary**<a name="section421144492165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1943846920165631"></a>
<table><thead align="left"><tr id="row1393890447165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1937412979165631"><a name="p1937412979165631"></a><a name="p1937412979165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p277154764165631"><a name="p277154764165631"></a><a name="p277154764165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row446477856165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p168402172165631"><a name="p168402172165631"></a><a name="p168402172165631"></a><a href="IInputInterface.md#a539baf2f3554b901abd4820e521ac0ea">iInputManager</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p311464088165631"><a name="p311464088165631"></a><a name="p311464088165631"></a><a href="InputManager.md">InputManager</a> * </p>
</td>
</tr>
<tr id="row2079227654165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p901512404165631"><a name="p901512404165631"></a><a name="p901512404165631"></a><a href="IInputInterface.md#a0da92e255529827b823c19071f50fa27">iInputController</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1113516124165631"><a name="p1113516124165631"></a><a name="p1113516124165631"></a><a href="InputController.md">InputController</a> * </p>
</td>
</tr>
<tr id="row1787316139165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p335538921165631"><a name="p335538921165631"></a><a name="p335538921165631"></a><a href="IInputInterface.md#a592d65e0a8ad8e9bc0241a0be50669d0">iInputReporter</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1912667535165631"><a name="p1912667535165631"></a><a name="p1912667535165631"></a><a href="InputReporter.md">InputReporter</a> * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section2072978642165631"></a>

## **Field **<a name="section789099418165631"></a>

## iInputController<a name="a0da92e255529827b823c19071f50fa27"></a>

```
[InputController](InputController.md)* IInputInterface::iInputController
```

 **Description:**

[Service](Service.md)  control interface for input devices 

## iInputManager<a name="a539baf2f3554b901abd4820e521ac0ea"></a>

```
[InputManager](InputManager.md)* IInputInterface::iInputManager
```

 **Description:**

Device management interface for input devices 

## iInputReporter<a name="a592d65e0a8ad8e9bc0241a0be50669d0"></a>

```
[InputReporter](InputReporter.md)* IInputInterface::iInputReporter
```

 **Description:**

Data reporting interface for input devices 


# IPowerEventListener<a name="EN-US_TOPIC_0000001055358112"></a>

-   [Overview](#section189942363165632)
-   [Summary](#section338740721165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section840861603165632)
-   [Field](#section602228592165632)
-   [Resume](#ad8501d377d185a998803ad84cacf80d7)
-   [Suspend](#a42104ba0f92462db12a13e6b40c40d52)

## **Overview**<a name="section189942363165632"></a>

**Related Modules:**

[Core](core.md)

**Description:**

Defines the power management functions provided by the HDF for the driver. 

To use the power management mechanism provided by the HDF, implement operations of  **[IPowerEventListener](ipowereventlistener.md)**  and invoke \{@linkHdfDeviceRegisterPowerListener\} to register the operations with the HDF.

**Since:**

1.0

## **Summary**<a name="section338740721165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table2082300765165632"></a>
<table><thead align="left"><tr id="row1659540734165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p99820178165632"><a name="p99820178165632"></a><a name="p99820178165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1671421424165632"><a name="p1671421424165632"></a><a name="p1671421424165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row277597391165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1459367904165632"><a name="p1459367904165632"></a><a name="p1459367904165632"></a><a href="ipowereventlistener.md#ad8501d377d185a998803ad84cacf80d7">Resume</a> )(struct <a href="hdfdeviceobject.md">HdfDeviceObject</a> *deviceObject)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1672936865165632"><a name="p1672936865165632"></a><a name="p1672936865165632"></a>void(* </p>
</td>
</tr>
<tr id="row958796193165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p757561708165632"><a name="p757561708165632"></a><a name="p757561708165632"></a><a href="ipowereventlistener.md#a42104ba0f92462db12a13e6b40c40d52">Suspend</a> )(struct <a href="hdfdeviceobject.md">HdfDeviceObject</a> *deviceObject)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2014919113165632"><a name="p2014919113165632"></a><a name="p2014919113165632"></a>void(* </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section840861603165632"></a>

## **Field **<a name="section602228592165632"></a>

## Resume<a name="ad8501d377d185a998803ad84cacf80d7"></a>

```
void(* IPowerEventListener::Resume) (struct [HdfDeviceObject](hdfdeviceobject.md) *deviceObject)
```

 **Description:**

Wakes up the driver device. The driver developer implements the operation. 

## Suspend<a name="a42104ba0f92462db12a13e6b40c40d52"></a>

```
void(* IPowerEventListener::Suspend) (struct [HdfDeviceObject](hdfdeviceobject.md) *deviceObject)
```

 **Description:**

Hibernates the driver device. The driver developer implements the operation. 


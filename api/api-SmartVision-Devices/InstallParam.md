# InstallParam<a name="ZH-CN_TOPIC_0000001057187349"></a>

-   [Overview](#section361803001165632)
-   [Summary](#section557240139165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section1016664112165632)
-   [Field](#section48621244165632)
-   [installLocation](#a6cc65611251ffed3269766afc02d5913)
-   [keepData](#acb4b2f60f9c8fc37ad72331b7e75807c)

## **Overview**<a name="section361803001165632"></a>

**Related Modules:**

[BundleManager](BundleManager.md)

**Description:**

Defines parameters used for application installation, update, or uninstallation. 

## **Summary**<a name="section557240139165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table430140217165632"></a>
<table><thead align="left"><tr id="row1834774824165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p473733335165632"><a name="p473733335165632"></a><a name="p473733335165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2145622987165632"><a name="p2145622987165632"></a><a name="p2145622987165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1458481590165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p942277211165632"><a name="p942277211165632"></a><a name="p942277211165632"></a><a href="InstallParam.md#a6cc65611251ffed3269766afc02d5913">installLocation</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p413603955165632"><a name="p413603955165632"></a><a name="p413603955165632"></a>int32_t </p>
</td>
</tr>
<tr id="row1043392601165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1365987633165632"><a name="p1365987633165632"></a><a name="p1365987633165632"></a><a href="InstallParam.md#acb4b2f60f9c8fc37ad72331b7e75807c">keepData</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1598240375165632"><a name="p1598240375165632"></a><a name="p1598240375165632"></a>bool </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1016664112165632"></a>

## **Field **<a name="section48621244165632"></a>

## installLocation<a name="a6cc65611251ffed3269766afc02d5913"></a>

```
int32_t InstallParam::installLocation
```

 **Description:**

Installation or update path of the application 

## keepData<a name="acb4b2f60f9c8fc37ad72331b7e75807c"></a>

```
bool InstallParam::keepData
```

 **Description:**

Whether to retain particular data during application uninstallation 


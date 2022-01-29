# StepperItem<a name="EN-US_TOPIC_0000001192755138"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

The **<StepperItem\>** component provides an element for the **<Stepper\>** component.

## Applicable Devices<a name="section322851519172"></a>

<a name="table857714145377"></a>
<table><thead align="left"><tr id="row55778146373"><th class="cellrowborder" valign="top" width="23.66106080206986%" id="mcps1.1.5.1.1"><p id="p7577141417376"><a name="p7577141417376"></a><a name="p7577141417376"></a>Phone</p>
</th>
<th class="cellrowborder" valign="top" width="26.3130659767141%" id="mcps1.1.5.1.2"><p id="p487719816463"><a name="p487719816463"></a><a name="p487719816463"></a>Tablet</p>
</th>
<th class="cellrowborder" valign="top" width="24.63130659767141%" id="mcps1.1.5.1.3"><p id="p135771614203720"><a name="p135771614203720"></a><a name="p135771614203720"></a>Smart TV</p>
</th>
<th class="cellrowborder" valign="top" width="25.39456662354463%" id="mcps1.1.5.1.4"><p id="p25772014133712"><a name="p25772014133712"></a><a name="p25772014133712"></a>Wearable</p>
</th>
</tr>
</thead>
<tbody><tr id="row8578151423715"><td class="cellrowborder" valign="top" width="23.66106080206986%" headers="mcps1.1.5.1.1 "><p id="p65782014203718"><a name="p65782014203718"></a><a name="p65782014203718"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="26.3130659767141%" headers="mcps1.1.5.1.2 "><p id="p148771182469"><a name="p148771182469"></a><a name="p148771182469"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="24.63130659767141%" headers="mcps1.1.5.1.3 "><p id="p45783141377"><a name="p45783141377"></a><a name="p45783141377"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="25.39456662354463%" headers="mcps1.1.5.1.4 "><p id="p11578161443718"><a name="p11578161443718"></a><a name="p11578161443718"></a>No</p>
</td>
</tr>
</tbody>
</table>

## Required Permissions<a name="section53281531154915"></a>

None

## Child Components<a name="section5989144051714"></a>

This component supports only one child component.

## APIs<a name="section97451749121712"></a>

StepperItem\(\)

## Attributes<a name="section17430171102911"></a>

<a name="table144301017298"></a>
<table><thead align="left"><tr id="row5430101192912"><th class="cellrowborder" valign="top" width="17.851785178517854%" id="mcps1.1.5.1.1"><p id="p2430111297"><a name="p2430111297"></a><a name="p2430111297"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.501050105010503%" id="mcps1.1.5.1.2"><p id="p043019119291"><a name="p043019119291"></a><a name="p043019119291"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="21.192119211921195%" id="mcps1.1.5.1.3"><p id="p643017119296"><a name="p643017119296"></a><a name="p643017119296"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="50.455045504550455%" id="mcps1.1.5.1.4"><p id="p18430161132917"><a name="p18430161132917"></a><a name="p18430161132917"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1543013119293"><td class="cellrowborder" valign="top" width="17.851785178517854%" headers="mcps1.1.5.1.1 "><p id="p7430191152915"><a name="p7430191152915"></a><a name="p7430191152915"></a>prevLabel</p>
</td>
<td class="cellrowborder" valign="top" width="10.501050105010503%" headers="mcps1.1.5.1.2 "><p id="p114302013292"><a name="p114302013292"></a><a name="p114302013292"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="21.192119211921195%" headers="mcps1.1.5.1.3 "><p id="p1643012152918"><a name="p1643012152918"></a><a name="p1643012152918"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.455045504550455%" headers="mcps1.1.5.1.4 "><p id="p134301219293"><a name="p134301219293"></a><a name="p134301219293"></a>When the stepper contains more than one page, the default value for all pages except the first page is **Back**.</p>
</td>
</tr>
<tr id="row144301119292"><td class="cellrowborder" valign="top" width="17.851785178517854%" headers="mcps1.1.5.1.1 "><p id="p443051132914"><a name="p443051132914"></a><a name="p443051132914"></a>nextLabel</p>
</td>
<td class="cellrowborder" valign="top" width="10.501050105010503%" headers="mcps1.1.5.1.2 "><p id="p143010116295"><a name="p143010116295"></a><a name="p143010116295"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="21.192119211921195%" headers="mcps1.1.5.1.3 "><p id="p64301512295"><a name="p64301512295"></a><a name="p64301512295"></a>-</p>
</td>
If the <td class="cellrowborder" valign="top" width="50.455045504550455%" headers="mcps1.1.5.1.4 "><p id="p143012117294"><a name="p143012117294"></a><a name="p143012117294"></a>When the stepper contains more than one page, the default value for the last page is **Start**, and the default value for other pages is **Next**.</p>
</td>
</tr>
<tr id="row3430019294"><td class="cellrowborder" valign="top" width="17.851785178517854%" headers="mcps1.1.5.1.1 "><p id="p184306118294"><a name="p184306118294"></a><a name="p184306118294"></a>status</p>
</td>
<td class="cellrowborder" valign="top" width="10.501050105010503%" headers="mcps1.1.5.1.2 "><p id="p94309117299"><a name="p94309117299"></a><a name="p94309117299"></a><a href="#li1343015152912">ItemState</a></p>
</td>
<td class="cellrowborder" valign="top" width="21.192119211921195%" headers="mcps1.1.5.1.3 "><p id="p154301913298"><a name="p154301913298"></a><a name="p154301913298"></a>ItemState.Normal</p>
</td>
<td class="cellrowborder" valign="top" width="50.455045504550455%" headers="mcps1.1.5.1.4 "><p id="p04300152911"><a name="p04300152911"></a><a name="p04300152911"></a>Status of the stepper item.</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li1343015152912"></a>ItemState enums

    <a name="table1843110115292"></a>
    <table><thead align="left"><tr id="row8431181122913"><th class="cellrowborder" valign="top" width="28.360000000000003%" id="mcps1.1.3.1.1"><p id="p443111116295"><a name="p443111116295"></a><a name="p443111116295"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="71.64%" id="mcps1.1.3.1.2"><p id="p20431318294"><a name="p20431318294"></a><a name="p20431318294"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row64311018291"><td class="cellrowborder" valign="top" width="28.360000000000003%" headers="mcps1.1.3.1.1 "><p id="p1243113117294"><a name="p1243113117294"></a><a name="p1243113117294"></a>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.64%" headers="mcps1.1.3.1.2 "><p id="p194315115292"><a name="p194315115292"></a><a name="p194315115292"></a>Normal state, in which the text button on the right is displayed properly and can be clicked to go to the next stepper item.</p>
    </td>
    </tr>
    <tr id="row10431012290"><td class="cellrowborder" valign="top" width="28.360000000000003%" headers="mcps1.1.3.1.1 "><p id="p843191172910"><a name="p843191172910"></a><a name="p843191172910"></a>Disabled</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.64%" headers="mcps1.1.3.1.2 "><p id="p194315115292"><a name="p194315115292"></a><a name="p194315115292"></a>Disabled state, in which the text button on the right is dimmed and cannot be clicked to go to the next stepper item.</p>
    </td>
    </tr>
    <tr id="row84318116296"><td class="cellrowborder" valign="top" width="28.360000000000003%" headers="mcps1.1.3.1.1 "><p id="p443110172913"><a name="p443110172913"></a><a name="p443110172913"></a>Waiting</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.64%" headers="mcps1.1.3.1.2 "><p id="p1943117142918"><a name="p1943117142918"></a><a name="p1943117142918"></a>Waiting state, in which a waiting progress bar instead of the text button on the right is displayed. The progress bar cannot be clicked to go to the next stepper item.</p>
    </td>
    </tr>
    <tr id="row243101102916"><td class="cellrowborder" valign="top" width="28.360000000000003%" headers="mcps1.1.3.1.1 "><p id="p17431319294"><a name="p17431319294"></a><a name="p17431319294"></a>Skip</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.64%" headers="mcps1.1.3.1.2 "><p id="p843112111298"><a name="p843112111298"></a><a name="p843112111298"></a>Skipped state, in which the current step item is skipped and the next step item is performed.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section1131255321814"></a>

See [Stepper](ts-container-stepper.md).

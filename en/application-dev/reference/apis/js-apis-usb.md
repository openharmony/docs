# USB<a name="EN-US_TOPIC_0000001221951993"></a>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="section290293011431"></a>

```
import usb from "@ohos.usb";
```

## Required Permissions<a name="section41119174207"></a>

None.

## usb.getDevices<a name="section1885592111287"></a>

usb.getDevices\(\): Array<Readonly<USBDevice\>\>

Obtains the USB device list.

-   Return values

    <a name="table5556114015311"></a>
    <table><thead align="left"><tr id="row962564023111"><th class="cellrowborder" valign="top" width="33.03%" id="mcps1.1.3.1.1"><p id="p176257409317"><a name="p176257409317"></a><a name="p176257409317"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="66.97%" id="mcps1.1.3.1.2"><p id="p9626124033116"><a name="p9626124033116"></a><a name="p9626124033116"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row26267406318"><td class="cellrowborder" valign="top" width="33.03%" headers="mcps1.1.3.1.1 "><p id="p462612404313"><a name="p462612404313"></a><a name="p462612404313"></a>Array&lt;Readonly&lt;<a href="#section14936845182012">USBDevice</a>&gt;&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.97%" headers="mcps1.1.3.1.2 "><p id="p136871212173"><a name="p136871212173"></a><a name="p136871212173"></a>USB device list.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let devicesList = usb.getDevices();
    console.log(`devicesList = ${JSON.stringify(devicesList)}`);
    // devicesList is a list of USB devices.
    // A simple example of devicesList is provided as follows:
    [
      {
        name: "1-1",
        serial: "",
        manufacturerName: "",
        productName: "",
        version: "",
        vendorId: 7531,
        productId: 2,
        clazz: 9,
        subclass: 0,
        protocol: 1,
        devAddress: 1,
        busNum: 1,
        configs: [
          {
            id: 1,
            attributes: 224,
            isRemoteWakeup: true,
            isSelfPowered: true,
            maxPower: 0,
            name: "1-1",
            interfaces: [
              {
                id: 0,
                protocol: 0,
                clazz: 9,
                subclass: 0,
                alternateSetting: 0,
                name: "1-1",
                endpoints: [
                  {
                    address: 129,
                    attributes: 3,
                    interval: 12,
                    maxPacketSize: 4,
                    direction: 128,
                    number: 1,
                    type: 3,
                    interfaceId: 0,
                  },
                ],
              },
            ],
          },
        ],
      },
    ]
    ```


## usb.connectDevice<a name="section910254722918"></a>

usb.connectDevice\(device: USBDevice\): Readonly<USBDevicePipe\>

Connects to a USB device.

Before you do this, call  [usb.getDevices](#section1885592111287)  to obtain the USB device list, and then call  [usb.requestRight](#section1865915394353)  to request the device access permission.

-   Parameters

    <a name="table1976541515341"></a>
    <table><thead align="left"><tr id="row1082510155348"><th class="cellrowborder" valign="top" width="25.28%" id="mcps1.1.5.1.1"><p id="p18825111523414"><a name="p18825111523414"></a><a name="p18825111523414"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.04%" id="mcps1.1.5.1.2"><p id="p382591520343"><a name="p382591520343"></a><a name="p382591520343"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.8%" id="mcps1.1.5.1.3"><p id="p6903111114518"><a name="p6903111114518"></a><a name="p6903111114518"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.88%" id="mcps1.1.5.1.4"><p id="p88251015153417"><a name="p88251015153417"></a><a name="p88251015153417"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row88257157342"><td class="cellrowborder" valign="top" width="25.28%" headers="mcps1.1.5.1.1 "><p id="p118251715183416"><a name="p118251715183416"></a><a name="p118251715183416"></a>device</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.1.5.1.2 "><p id="p9890655145619"><a name="p9890655145619"></a><a name="p9890655145619"></a><a href="#section14936845182012">USBDevice</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="15.8%" headers="mcps1.1.5.1.3 "><p id="p1490311119453"><a name="p1490311119453"></a><a name="p1490311119453"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.88%" headers="mcps1.1.5.1.4 "><p id="p1825181523413"><a name="p1825181523413"></a><a name="p1825181523413"></a>USB device information.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table1769515193412"></a>
    <table><thead align="left"><tr id="row1582561511345"><th class="cellrowborder" valign="top" width="34.33%" id="mcps1.1.3.1.1"><p id="p1482531520343"><a name="p1482531520343"></a><a name="p1482531520343"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="65.67%" id="mcps1.1.3.1.2"><p id="p10825161516342"><a name="p10825161516342"></a><a name="p10825161516342"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17825215183414"><td class="cellrowborder" valign="top" width="34.33%" headers="mcps1.1.3.1.1 "><p id="p8825915103420"><a name="p8825915103420"></a><a name="p8825915103420"></a>Readonly&lt;<a href="#section353972413263">USBDevicePipe</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.67%" headers="mcps1.1.3.1.2 "><p id="p19983105110183"><a name="p19983105110183"></a><a name="p19983105110183"></a>USB device pipe for data transfer.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let devicepipe= usb.connectDevice(device);
    console.log(`devicepipe = ${JSON.stringify(devicepipe)}`);
    ```


## usb.hasRight<a name="section101116197338"></a>

usb.hasRight\(deviceName: string\): boolean

Checks whether the user has the permission to access the device.

-   Parameters

    <a name="table1627841318363"></a>
    <table><thead align="left"><tr id="row23342137360"><th class="cellrowborder" valign="top" width="24.037596240375965%" id="mcps1.1.5.1.1"><p id="p5334161317368"><a name="p5334161317368"></a><a name="p5334161317368"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.287571242875714%" id="mcps1.1.5.1.2"><p id="p1334151323610"><a name="p1334151323610"></a><a name="p1334151323610"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.328767123287673%" id="mcps1.1.5.1.3"><p id="p461519310468"><a name="p461519310468"></a><a name="p461519310468"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="39.346065393460655%" id="mcps1.1.5.1.4"><p id="p18334131303615"><a name="p18334131303615"></a><a name="p18334131303615"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row03342013143611"><td class="cellrowborder" valign="top" width="24.037596240375965%" headers="mcps1.1.5.1.1 "><p id="p3334413143611"><a name="p3334413143611"></a><a name="p3334413143611"></a>deviceName</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.287571242875714%" headers="mcps1.1.5.1.2 "><p id="p83341613183610"><a name="p83341613183610"></a><a name="p83341613183610"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.328767123287673%" headers="mcps1.1.5.1.3 "><p id="p17615131104611"><a name="p17615131104611"></a><a name="p17615131104611"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.346065393460655%" headers="mcps1.1.5.1.4 "><p id="p17334151314361"><a name="p17334151314361"></a><a name="p17334151314361"></a>Device name.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1828213131367"></a>
    <table><thead align="left"><tr id="row1833491363614"><th class="cellrowborder" valign="top" width="34.260000000000005%" id="mcps1.1.3.1.1"><p id="p6334713113616"><a name="p6334713113616"></a><a name="p6334713113616"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="65.74%" id="mcps1.1.3.1.2"><p id="p13341013193612"><a name="p13341013193612"></a><a name="p13341013193612"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row203344138361"><td class="cellrowborder" valign="top" width="34.260000000000005%" headers="mcps1.1.3.1.1 "><p id="p533431318360"><a name="p533431318360"></a><a name="p533431318360"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.74%" headers="mcps1.1.3.1.2 "><p id="p61806241379"><a name="p61806241379"></a><a name="p61806241379"></a>Returns <strong id="b374713583399"><a name="b374713583399"></a><a name="b374713583399"></a>true</strong> if the user has the permission to access the device; returns <strong id="b73287154014"><a name="b73287154014"></a><a name="b73287154014"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let divicesName="1-1";
    let bool = usb.hasRight(divicesName);
    console.log(bool);
    ```


## usb.requestRight<a name="section1865915394353"></a>

usb.requestRight\(deviceName: string\): Promise<boolean\>

Requests the temporary permission for the application to access the USB device.

-   Parameters

    <a name="table1708355374"></a>
    <table><thead align="left"><tr id="row913310351370"><th class="cellrowborder" valign="top" width="24.037596240375965%" id="mcps1.1.5.1.1"><p id="p1813473563715"><a name="p1813473563715"></a><a name="p1813473563715"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.287571242875714%" id="mcps1.1.5.1.2"><p id="p81341335203716"><a name="p81341335203716"></a><a name="p81341335203716"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.6987301269873%" id="mcps1.1.5.1.3"><p id="p1766139124716"><a name="p1766139124716"></a><a name="p1766139124716"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="38.976102389761024%" id="mcps1.1.5.1.4"><p id="p1113403513712"><a name="p1113403513712"></a><a name="p1113403513712"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12134143515377"><td class="cellrowborder" valign="top" width="24.037596240375965%" headers="mcps1.1.5.1.1 "><p id="p7134153523716"><a name="p7134153523716"></a><a name="p7134153523716"></a>deviceName</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.287571242875714%" headers="mcps1.1.5.1.2 "><p id="p813403512376"><a name="p813403512376"></a><a name="p813403512376"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.6987301269873%" headers="mcps1.1.5.1.3 "><p id="p15662129104713"><a name="p15662129104713"></a><a name="p15662129104713"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.976102389761024%" headers="mcps1.1.5.1.4 "><p id="p20134133519371"><a name="p20134133519371"></a><a name="p20134133519371"></a>Device name.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table176113513719"></a>
    <table><thead align="left"><tr id="row1313473573718"><th class="cellrowborder" valign="top" width="34.83%" id="mcps1.1.3.1.1"><p id="p51341535113717"><a name="p51341535113717"></a><a name="p51341535113717"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="65.16999999999999%" id="mcps1.1.3.1.2"><p id="p111344359372"><a name="p111344359372"></a><a name="p111344359372"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row191341535163710"><td class="cellrowborder" valign="top" width="34.83%" headers="mcps1.1.3.1.1 "><p id="p1113493516378"><a name="p1113493516378"></a><a name="p1113493516378"></a>Promise&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.16999999999999%" headers="mcps1.1.3.1.2 "><p id="p566294711195"><a name="p566294711195"></a><a name="p566294711195"></a>Returns <strong id="b146408591491"><a name="b146408591491"></a><a name="b146408591491"></a>true</strong> if the temporary device access permissions are granted; returns <strong id="b10640195924911"><a name="b10640195924911"></a><a name="b10640195924911"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let divicesName="1-1";
    usb.requestRight(divicesName).then((ret) => {
      console.log(`requestRight = ${JSON.stringify(ret)}`);
    });
    ```


## usb.claimInterface<a name="section41056254494"></a>

usb.claimInterface\(pipe: USBDevicePipe, iface: USBInterface, force?: boolean\): number

Claims a USB interface.

Before you do this, call  [usb.getDevices](#section1885592111287)  to obtain the USB device list and USB interfaces, call  [usb.requestRight](#section1865915394353)  to request the device access permission, and call  [usb.connectDevice](#section910254722918)  to obtain  **devicepipe**  as an input parameter.

-   Parameters

    <a name="table360031617529"></a>
    <table><thead align="left"><tr id="row2717141635213"><th class="cellrowborder" valign="top" width="24.647535246475353%" id="mcps1.1.5.1.1"><p id="p1571741685211"><a name="p1571741685211"></a><a name="p1571741685211"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.527647235276476%" id="mcps1.1.5.1.2"><p id="p5717201614526"><a name="p5717201614526"></a><a name="p5717201614526"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.078792120787922%" id="mcps1.1.5.1.3"><p id="p1588651017122"><a name="p1588651017122"></a><a name="p1588651017122"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="39.74602539746026%" id="mcps1.1.5.1.4"><p id="p187171716125217"><a name="p187171716125217"></a><a name="p187171716125217"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14717141619529"><td class="cellrowborder" valign="top" width="24.647535246475353%" headers="mcps1.1.5.1.1 "><p id="p10717316125218"><a name="p10717316125218"></a><a name="p10717316125218"></a>pipe</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.527647235276476%" headers="mcps1.1.5.1.2 "><p id="p47171916145212"><a name="p47171916145212"></a><a name="p47171916145212"></a><a href="#section353972413263">USBDevicePipe</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.078792120787922%" headers="mcps1.1.5.1.3 "><p id="p5886510181211"><a name="p5886510181211"></a><a name="p5886510181211"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.74602539746026%" headers="mcps1.1.5.1.4 "><p id="p17171016185216"><a name="p17171016185216"></a><a name="p17171016185216"></a>Device pipe, which is used to determine the bus number and device address.</p>
    </td>
    </tr>
    <tr id="row1371741605211"><td class="cellrowborder" valign="top" width="24.647535246475353%" headers="mcps1.1.5.1.1 "><p id="p20718101605218"><a name="p20718101605218"></a><a name="p20718101605218"></a>iface</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.527647235276476%" headers="mcps1.1.5.1.2 "><p id="p7718316125210"><a name="p7718316125210"></a><a name="p7718316125210"></a><a href="#section1564414611311">USBInterface</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.078792120787922%" headers="mcps1.1.5.1.3 "><p id="p7148101941217"><a name="p7148101941217"></a><a name="p7148101941217"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.74602539746026%" headers="mcps1.1.5.1.4 "><p id="p2718316195211"><a name="p2718316195211"></a><a name="p2718316195211"></a>USB interface, which is used to determine the index of the interface to claim.</p>
    </td>
    </tr>
    <tr id="row57181716175213"><td class="cellrowborder" valign="top" width="24.647535246475353%" headers="mcps1.1.5.1.1 "><p id="p147201616165219"><a name="p147201616165219"></a><a name="p147201616165219"></a>force</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.527647235276476%" headers="mcps1.1.5.1.2 "><p id="p27204168526"><a name="p27204168526"></a><a name="p27204168526"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.078792120787922%" headers="mcps1.1.5.1.3 "><p id="p972311911127"><a name="p972311911127"></a><a name="p972311911127"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.74602539746026%" headers="mcps1.1.5.1.4 "><p id="p1720161611526"><a name="p1720161611526"></a><a name="p1720161611526"></a>Optional parameter that determines whether to forcibly claim the USB interface. The default value is <strong id="b2873547174813"><a name="b2873547174813"></a><a name="b2873547174813"></a>false</strong>, indicating not to forcibly claim the USB interface.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table16612191616524"></a>
    <table><thead align="left"><tr id="row872011167525"><th class="cellrowborder" valign="top" width="34.72%" id="mcps1.1.3.1.1"><p id="p197201516185220"><a name="p197201516185220"></a><a name="p197201516185220"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="65.28%" id="mcps1.1.3.1.2"><p id="p072015164522"><a name="p072015164522"></a><a name="p072015164522"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row207202016115212"><td class="cellrowborder" valign="top" width="34.72%" headers="mcps1.1.3.1.1 "><p id="p372011619524"><a name="p372011619524"></a><a name="p372011619524"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="65.28%" headers="mcps1.1.3.1.2 "><p id="p20467115711241"><a name="p20467115711241"></a><a name="p20467115711241"></a>Returns <strong id="b28948816529"><a name="b28948816529"></a><a name="b28948816529"></a>0</strong> if the USB interface is successfully claimed; returns an error code otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let ret = usb.claimInterface(devicepipe, interfaces);
    console.log(`claimInterface = ${ret}`);
    ```


## usb.releaseInterface<a name="section2833910171512"></a>

usb.releaseInterface\(pipe: USBDevicePipe, iface: USBInterface\): number

Releases a USB interface.

Before you do this, ensure that you have claimed the interface by calling  [usb.claimInterface](#section41056254494).

-   Parameters

    <a name="table177891914155420"></a>
    <table><thead align="left"><tr id="row15877111410542"><th class="cellrowborder" valign="top" width="21.42%" id="mcps1.1.5.1.1"><p id="p487715148541"><a name="p487715148541"></a><a name="p487715148541"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.2"><p id="p108771914155418"><a name="p108771914155418"></a><a name="p108771914155418"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.02%" id="mcps1.1.5.1.3"><p id="p6580122916129"><a name="p6580122916129"></a><a name="p6580122916129"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="38.519999999999996%" id="mcps1.1.5.1.4"><p id="p28771814195419"><a name="p28771814195419"></a><a name="p28771814195419"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row687771420549"><td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.1 "><p id="p13877111414546"><a name="p13877111414546"></a><a name="p13877111414546"></a>pipe</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.2 "><p id="p28779145542"><a name="p28779145542"></a><a name="p28779145542"></a><a href="#section353972413263">USBDevicePipe</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="p15581142917129"><a name="p15581142917129"></a><a name="p15581142917129"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p198771214185413"><a name="p198771214185413"></a><a name="p198771214185413"></a>Device pipe, which is used to determine the bus number and device address.</p>
    </td>
    </tr>
    <tr id="row1587761475419"><td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.5.1.1 "><p id="p5877181495418"><a name="p5877181495418"></a><a name="p5877181495418"></a>iface</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.2 "><p id="p787718147544"><a name="p787718147544"></a><a name="p787718147544"></a><a href="#section1564414611311">USBInterface</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="p15811929101211"><a name="p15811929101211"></a><a name="p15811929101211"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p13877181420547"><a name="p13877181420547"></a><a name="p13877181420547"></a>USB interface, which is used to determine the index of the interface to release.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table2796111415545"></a>
    <table><thead align="left"><tr id="row8877141485413"><th class="cellrowborder" valign="top" width="42.86%" id="mcps1.1.3.1.1"><p id="p1787821435416"><a name="p1787821435416"></a><a name="p1787821435416"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.14%" id="mcps1.1.3.1.2"><p id="p7878714105418"><a name="p7878714105418"></a><a name="p7878714105418"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row48786144548"><td class="cellrowborder" valign="top" width="42.86%" headers="mcps1.1.3.1.1 "><p id="p18878151416543"><a name="p18878151416543"></a><a name="p18878151416543"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.14%" headers="mcps1.1.3.1.2 "><p id="p18243112172516"><a name="p18243112172516"></a><a name="p18243112172516"></a>Returns <strong id="b142281811260"><a name="b142281811260"></a><a name="b142281811260"></a>0</strong> if the USB interface is successfully released; returns an error code otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let ret = usb.releaseInterface(devicepipe, interfaces);
    console.log(`releaseInterface = ${ret}`);
    ```


## usb.setConfiguration<a name="section12776101611419"></a>

usb.setConfiguration\(pipe: USBDevicePipe, config: USBConfig\): number

Sets the device configuration.

Before you do this, call  [usb.getDevices](#section1885592111287)  to obtain the USB device list and device configuration, call  [usb.requestRight](#section1865915394353)  to request the device access permission, and call  [usb.connectDevice](#section910254722918)  to obtain  **devicepipe**  as an input parameter.

-   Parameters

    <a name="table538417303578"></a>
    <table><thead align="left"><tr id="row19516133020578"><th class="cellrowborder" valign="top" width="18.001800180018%" id="mcps1.1.5.1.1"><p id="p0516193016578"><a name="p0516193016578"></a><a name="p0516193016578"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.79197919791979%" id="mcps1.1.5.1.2"><p id="p1516123013571"><a name="p1516123013571"></a><a name="p1516123013571"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.51165116511651%" id="mcps1.1.5.1.3"><p id="p7727955141210"><a name="p7727955141210"></a><a name="p7727955141210"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.69456945694569%" id="mcps1.1.5.1.4"><p id="p1516173035716"><a name="p1516173035716"></a><a name="p1516173035716"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18516630135712"><td class="cellrowborder" valign="top" width="18.001800180018%" headers="mcps1.1.5.1.1 "><p id="p8516193025718"><a name="p8516193025718"></a><a name="p8516193025718"></a>pipe</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.79197919791979%" headers="mcps1.1.5.1.2 "><p id="p051683011572"><a name="p051683011572"></a><a name="p051683011572"></a><a href="#section353972413263">USBDevicePipe</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="16.51165116511651%" headers="mcps1.1.5.1.3 "><p id="p137271955111215"><a name="p137271955111215"></a><a name="p137271955111215"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.69456945694569%" headers="mcps1.1.5.1.4 "><p id="p115161830195710"><a name="p115161830195710"></a><a name="p115161830195710"></a>Device pipe, which is used to determine the bus number and device address.</p>
    </td>
    </tr>
    <tr id="row95168301573"><td class="cellrowborder" valign="top" width="18.001800180018%" headers="mcps1.1.5.1.1 "><p id="p1051623012575"><a name="p1051623012575"></a><a name="p1051623012575"></a>config</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.79197919791979%" headers="mcps1.1.5.1.2 "><p id="p7516630175710"><a name="p7516630175710"></a><a name="p7516630175710"></a><a href="#section1172111051715">USBConfig</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="16.51165116511651%" headers="mcps1.1.5.1.3 "><p id="p372725591214"><a name="p372725591214"></a><a name="p372725591214"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.69456945694569%" headers="mcps1.1.5.1.4 "><p id="p19423154254612"><a name="p19423154254612"></a><a name="p19423154254612"></a>USB configuration to set.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table14393133015577"></a>
    <table><thead align="left"><tr id="row5516163014574"><th class="cellrowborder" valign="top" width="32.75%" id="mcps1.1.3.1.1"><p id="p65171130125710"><a name="p65171130125710"></a><a name="p65171130125710"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="67.25%" id="mcps1.1.3.1.2"><p id="p1251713005712"><a name="p1251713005712"></a><a name="p1251713005712"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row65171430195716"><td class="cellrowborder" valign="top" width="32.75%" headers="mcps1.1.3.1.1 "><p id="p251713303578"><a name="p251713303578"></a><a name="p251713303578"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.25%" headers="mcps1.1.3.1.2 "><p id="p1516442172518"><a name="p1516442172518"></a><a name="p1516442172518"></a>Returns <strong id="b9415254392"><a name="b9415254392"></a><a name="b9415254392"></a>0</strong> if the USB configuration is successfully set; returns an error code otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let ret = usb.setConfiguration(devicepipe, config);
    console.log(`setConfiguration = ${ret}`);
    ```


## usb.setInterface<a name="section6384134161914"></a>

usb.setInterface\(pipe: USBDevicePipe, iface: USBInterface\): number

Sets a USB interface.

Before you do this, call  [usb.getDevices](#section1885592111287)  to obtain the USB device list and interfaces, call  [usb.requestRight](#section1865915394353)  to request the device access permission, and call  [usb.connectDevice](#section910254722918)  to obtain  **devicepipe**  as an input parameter.

-   Parameters

    <a name="table20322125145912"></a>
    <table><thead align="left"><tr id="row84505254594"><th class="cellrowborder" valign="top" width="24.84%" id="mcps1.1.5.1.1"><p id="p164505254594"><a name="p164505254594"></a><a name="p164505254594"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.41%" id="mcps1.1.5.1.2"><p id="p15451182585917"><a name="p15451182585917"></a><a name="p15451182585917"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.35%" id="mcps1.1.5.1.3"><p id="p1181912019130"><a name="p1181912019130"></a><a name="p1181912019130"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="39.4%" id="mcps1.1.5.1.4"><p id="p4451425105910"><a name="p4451425105910"></a><a name="p4451425105910"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row745172516599"><td class="cellrowborder" valign="top" width="24.84%" headers="mcps1.1.5.1.1 "><p id="p14451725145919"><a name="p14451725145919"></a><a name="p14451725145919"></a>pipe</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.41%" headers="mcps1.1.5.1.2 "><p id="p114511925105913"><a name="p114511925105913"></a><a name="p114511925105913"></a><a href="#section353972413263">USBDevicePipe</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.35%" headers="mcps1.1.5.1.3 "><p id="p64522511138"><a name="p64522511138"></a><a name="p64522511138"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.4%" headers="mcps1.1.5.1.4 "><p id="p64511725195917"><a name="p64511725195917"></a><a name="p64511725195917"></a>Device pipe, which is used to determine the bus number and device address.</p>
    </td>
    </tr>
    <tr id="row7451182565917"><td class="cellrowborder" valign="top" width="24.84%" headers="mcps1.1.5.1.1 "><p id="p7451142575911"><a name="p7451142575911"></a><a name="p7451142575911"></a>iface</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.41%" headers="mcps1.1.5.1.2 "><p id="p4451102516593"><a name="p4451102516593"></a><a name="p4451102516593"></a><a href="#section1564414611311">USBInterface</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.35%" headers="mcps1.1.5.1.3 "><p id="p16348192741317"><a name="p16348192741317"></a><a name="p16348192741317"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.4%" headers="mcps1.1.5.1.4 "><p id="p177742954713"><a name="p177742954713"></a><a name="p177742954713"></a>USB interface to set.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table113321625185917"></a>
    <table><thead align="left"><tr id="row545112514593"><th class="cellrowborder" valign="top" width="41.730000000000004%" id="mcps1.1.3.1.1"><p id="p1445182555911"><a name="p1445182555911"></a><a name="p1445182555911"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.269999999999996%" id="mcps1.1.3.1.2"><p id="p12451102535913"><a name="p12451102535913"></a><a name="p12451102535913"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row54513256596"><td class="cellrowborder" valign="top" width="41.730000000000004%" headers="mcps1.1.3.1.1 "><p id="p17451525185912"><a name="p17451525185912"></a><a name="p17451525185912"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.269999999999996%" headers="mcps1.1.3.1.2 "><p id="p14451925205917"><a name="p14451925205917"></a><a name="p14451925205917"></a>Returns <strong id="b1789672118129"><a name="b1789672118129"></a><a name="b1789672118129"></a>0</strong> if the USB interface is successfully set; returns an error code otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let ret = usb.setInterface(devicepipe, interfaces);
    console.log(`setInterface = ${ret}`);
    ```


## usb.getRawDescriptor<a name="section59071538192112"></a>

usb.getRawDescriptor\(pipe: USBDevicePipe\): Uint8Array

Obtains the raw USB descriptor.

Before you do this, call  [usb.getDevices](#section1885592111287)  to obtain the USB device list, call  [usb.requestRight](#section1865915394353)  to request the device access permission, and call  [usb.connectDevice](#section910254722918)  to obtain  **devicepipe**  as an input parameter.

-   Parameters

    <a name="table93729510116"></a>
    <table><thead align="left"><tr id="row849211510110"><th class="cellrowborder" valign="top" width="24.65%" id="mcps1.1.5.1.1"><p id="p849213514112"><a name="p849213514112"></a><a name="p849213514112"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.16%" id="mcps1.1.5.1.2"><p id="p34921651119"><a name="p34921651119"></a><a name="p34921651119"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.97%" id="mcps1.1.5.1.3"><p id="p6837936151310"><a name="p6837936151310"></a><a name="p6837936151310"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="37.22%" id="mcps1.1.5.1.4"><p id="p14921052112"><a name="p14921052112"></a><a name="p14921052112"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1149215111"><td class="cellrowborder" valign="top" width="24.65%" headers="mcps1.1.5.1.1 "><p id="p17492951910"><a name="p17492951910"></a><a name="p17492951910"></a>pipe</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.16%" headers="mcps1.1.5.1.2 "><p id="p1549218516111"><a name="p1549218516111"></a><a name="p1549218516111"></a><a href="#section353972413263">USBDevicePipe</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.97%" headers="mcps1.1.5.1.3 "><p id="p776924071314"><a name="p776924071314"></a><a name="p776924071314"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.22%" headers="mcps1.1.5.1.4 "><p id="p184921456112"><a name="p184921456112"></a><a name="p184921456112"></a>Device pipe, which is used to determine the bus number and device address.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table10380451216"></a>
    <table><thead align="left"><tr id="row449235617"><th class="cellrowborder" valign="top" width="40.02%" id="mcps1.1.3.1.1"><p id="p4493358117"><a name="p4493358117"></a><a name="p4493358117"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.98%" id="mcps1.1.3.1.2"><p id="p114931553111"><a name="p114931553111"></a><a name="p114931553111"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row174931751115"><td class="cellrowborder" valign="top" width="40.02%" headers="mcps1.1.3.1.1 "><p id="p749313513115"><a name="p749313513115"></a><a name="p749313513115"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.98%" headers="mcps1.1.3.1.2 "><p id="p13394152132720"><a name="p13394152132720"></a><a name="p13394152132720"></a>Raw descriptor data.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let ret = usb.getRawDescriptor(devicepipe);
    ```


## usb.getFileDescriptor<a name="section140131942517"></a>

usb.getFileDescriptor\(pipe: USBDevicePipe\): number

Obtains the file descriptor.

Before you do this, call  [usb.getDevices](#section1885592111287)  to obtain the USB device list, call  [usb.requestRight](#section1865915394353)  to request the device access permission, and call  [usb.connectDevice](#section910254722918)  to obtain  **devicepipe**  as an input parameter.

-   Parameters

    <a name="table1629917301824"></a>
    <table><thead align="left"><tr id="row140716301722"><th class="cellrowborder" valign="top" width="24.54%" id="mcps1.1.5.1.1"><p id="p124071130625"><a name="p124071130625"></a><a name="p124071130625"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.05%" id="mcps1.1.5.1.2"><p id="p54070307211"><a name="p54070307211"></a><a name="p54070307211"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.08%" id="mcps1.1.5.1.3"><p id="p633174617132"><a name="p633174617132"></a><a name="p633174617132"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.33%" id="mcps1.1.5.1.4"><p id="p12407630028"><a name="p12407630028"></a><a name="p12407630028"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row440733012218"><td class="cellrowborder" valign="top" width="24.54%" headers="mcps1.1.5.1.1 "><p id="p154077301026"><a name="p154077301026"></a><a name="p154077301026"></a>pipe</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.05%" headers="mcps1.1.5.1.2 "><p id="p8407730628"><a name="p8407730628"></a><a name="p8407730628"></a><a href="#section353972413263">USBDevicePipe</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="13.08%" headers="mcps1.1.5.1.3 "><p id="p13598849101319"><a name="p13598849101319"></a><a name="p13598849101319"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.33%" headers="mcps1.1.5.1.4 "><p id="p84082301210"><a name="p84082301210"></a><a name="p84082301210"></a>Device pipe, which is used to determine the bus number and device address.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1130373018216"></a>
    <table><thead align="left"><tr id="row154085304213"><th class="cellrowborder" valign="top" width="32.879999999999995%" id="mcps1.1.3.1.1"><p id="p1640863013216"><a name="p1640863013216"></a><a name="p1640863013216"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="67.12%" id="mcps1.1.3.1.2"><p id="p104084307219"><a name="p104084307219"></a><a name="p104084307219"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2408930321"><td class="cellrowborder" valign="top" width="32.879999999999995%" headers="mcps1.1.3.1.1 "><p id="p940873019219"><a name="p940873019219"></a><a name="p940873019219"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.12%" headers="mcps1.1.3.1.2 "><p id="p4422166132810"><a name="p4422166132810"></a><a name="p4422166132810"></a>File descriptor of the USB device.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let ret = usb.getFileDescriptor(devicepipe);
    ```


## usb.controlTransfer<a name="section19888724142710"></a>

usb.controlTransfer\(pipe: USBDevicePipe, contrlparam: USBControlParams, timeout?: number\): Promise<number\>

Performs control transfer.

Before you do this, call  [usb.getDevices](#section1885592111287)  to obtain the USB device list, call  [usb.requestRight](#section1865915394353)  to request the device access permission, and call  [usb.connectDevice](#section910254722918)  to obtain  **devicepipe**  as an input parameter.

-   Parameters

    <a name="table25941645933"></a>
    <table><thead align="left"><tr id="row27771345932"><th class="cellrowborder" valign="top" width="24.05%" id="mcps1.1.5.1.1"><p id="p1777814513315"><a name="p1777814513315"></a><a name="p1777814513315"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.97%" id="mcps1.1.5.1.2"><p id="p177783451439"><a name="p177783451439"></a><a name="p177783451439"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.74%" id="mcps1.1.5.1.3"><p id="p298316551133"><a name="p298316551133"></a><a name="p298316551133"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="41.24%" id="mcps1.1.5.1.4"><p id="p2077819451734"><a name="p2077819451734"></a><a name="p2077819451734"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row67782451636"><td class="cellrowborder" valign="top" width="24.05%" headers="mcps1.1.5.1.1 "><p id="p177782452313"><a name="p177782452313"></a><a name="p177782452313"></a>pipe</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.1.5.1.2 "><p id="p87797455312"><a name="p87797455312"></a><a name="p87797455312"></a><a href="#section353972413263">USBDevicePipe</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.74%" headers="mcps1.1.5.1.3 "><p id="p1856912599132"><a name="p1856912599132"></a><a name="p1856912599132"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.24%" headers="mcps1.1.5.1.4 "><p id="p8779145936"><a name="p8779145936"></a><a name="p8779145936"></a>USB device pipe, which is used to determine the USB device.</p>
    </td>
    </tr>
    <tr id="row7779124516310"><td class="cellrowborder" valign="top" width="24.05%" headers="mcps1.1.5.1.1 "><p id="p977924519311"><a name="p977924519311"></a><a name="p977924519311"></a>contrlparam</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.1.5.1.2 "><p id="p97791345337"><a name="p97791345337"></a><a name="p97791345337"></a><a href="#section124996013327">USBControlParams</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.74%" headers="mcps1.1.5.1.3 "><p id="p134595013149"><a name="p134595013149"></a><a name="p134595013149"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.24%" headers="mcps1.1.5.1.4 "><p id="p127794453311"><a name="p127794453311"></a><a name="p127794453311"></a>Control transfer parameters.</p>
    </td>
    </tr>
    <tr id="row5779164511317"><td class="cellrowborder" valign="top" width="24.05%" headers="mcps1.1.5.1.1 "><p id="p1779144512310"><a name="p1779144512310"></a><a name="p1779144512310"></a>timeout</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.1.5.1.2 "><p id="p1377920454313"><a name="p1377920454313"></a><a name="p1377920454313"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.74%" headers="mcps1.1.5.1.3 "><p id="p498315552139"><a name="p498315552139"></a><a name="p498315552139"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.24%" headers="mcps1.1.5.1.4 "><p id="p87791245533"><a name="p87791245533"></a><a name="p87791245533"></a>Timeout duration. This parameter is optional. The default value is <strong id="b11780926132116"><a name="b11780926132116"></a><a name="b11780926132116"></a>0</strong>, indicating no timeout.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table16622345438"></a>
    <table><thead align="left"><tr id="row167799451331"><th class="cellrowborder" valign="top" width="36.21%" id="mcps1.1.3.1.1"><p id="p1377994514318"><a name="p1377994514318"></a><a name="p1377994514318"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="63.79%" id="mcps1.1.3.1.2"><p id="p67790451532"><a name="p67790451532"></a><a name="p67790451532"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row677910451035"><td class="cellrowborder" valign="top" width="36.21%" headers="mcps1.1.3.1.1 "><p id="p10779114514315"><a name="p10779114514315"></a><a name="p10779114514315"></a>Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="63.79%" headers="mcps1.1.3.1.2 "><p id="p340635120499"><a name="p340635120499"></a><a name="p340635120499"></a>Returns the size of the transmitted or received data block if the control transfer is successful; returns <strong id="b19451442152714"><a name="b19451442152714"></a><a name="b19451442152714"></a>-1</strong> if an exception occurs.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    usb.controlTransfer(devicepipe, USBControlParams).then((ret) => {
     console.log(`controlTransfer = ${JSON.stringify(ret)}`);
    })
    ```


## usb.bulkTransfer<a name="section1443184853017"></a>

usb.bulkTransfer\(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array, timeout?: number\): Promise<number\>

Performs bulk transfer.

Before you do this, call  [usb.getDevices](#section1885592111287)  to obtain the USB device list and endpoints, call  [usb.requestRight](#section1865915394353)  to request the device access permission, call  [usb.connectDevice](#section910254722918)  to obtain  **devicepipe**  as an input parameter, and call  [usb.claimInterface](#section41056254494)  to claim the USB interface.

-   Parameters

    <a name="table46751314764"></a>
    <table><thead align="left"><tr id="row782715144616"><th class="cellrowborder" valign="top" width="19.921992199219922%" id="mcps1.1.5.1.1"><p id="p88271141468"><a name="p88271141468"></a><a name="p88271141468"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.35203520352035%" id="mcps1.1.5.1.2"><p id="p1882715141664"><a name="p1882715141664"></a><a name="p1882715141664"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.061406140614064%" id="mcps1.1.5.1.3"><p id="p9996149151412"><a name="p9996149151412"></a><a name="p9996149151412"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.66456645664567%" id="mcps1.1.5.1.4"><p id="p1482781412619"><a name="p1482781412619"></a><a name="p1482781412619"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row282714141061"><td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.1.5.1.1 "><p id="p148275142618"><a name="p148275142618"></a><a name="p148275142618"></a>pipe</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.35203520352035%" headers="mcps1.1.5.1.2 "><p id="p98277141168"><a name="p98277141168"></a><a name="p98277141168"></a><a href="#section353972413263">USBDevicePipe</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="14.061406140614064%" headers="mcps1.1.5.1.3 "><p id="p287411123144"><a name="p287411123144"></a><a name="p287411123144"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.66456645664567%" headers="mcps1.1.5.1.4 "><p id="p1982716141569"><a name="p1982716141569"></a><a name="p1982716141569"></a>USB device pipe, which is used to determine the USB device.</p>
    </td>
    </tr>
    <tr id="row138275141569"><td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.1.5.1.1 "><p id="p11827151416611"><a name="p11827151416611"></a><a name="p11827151416611"></a>endpoint</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.35203520352035%" headers="mcps1.1.5.1.2 "><p id="p982751416611"><a name="p982751416611"></a><a name="p982751416611"></a><a href="#section193341439136">USBEndpoint</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="14.061406140614064%" headers="mcps1.1.5.1.3 "><p id="p981411315140"><a name="p981411315140"></a><a name="p981411315140"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.66456645664567%" headers="mcps1.1.5.1.4 "><p id="p98271149613"><a name="p98271149613"></a><a name="p98271149613"></a>USB endpoint, which is used to determine the USB port for data transfer.</p>
    </td>
    </tr>
    <tr id="row68278141064"><td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.1.5.1.1 "><p id="p13827151420619"><a name="p13827151420619"></a><a name="p13827151420619"></a>buffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.35203520352035%" headers="mcps1.1.5.1.2 "><p id="p482710141664"><a name="p482710141664"></a><a name="p482710141664"></a>Uint8Array</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.061406140614064%" headers="mcps1.1.5.1.3 "><p id="p1349411147140"><a name="p1349411147140"></a><a name="p1349411147140"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.66456645664567%" headers="mcps1.1.5.1.4 "><p id="p1282716141067"><a name="p1282716141067"></a><a name="p1282716141067"></a>Buffer for writing or reading data.</p>
    </td>
    </tr>
    <tr id="row182718141366"><td class="cellrowborder" valign="top" width="19.921992199219922%" headers="mcps1.1.5.1.1 "><p id="p182715141063"><a name="p182715141063"></a><a name="p182715141063"></a>timeout</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.35203520352035%" headers="mcps1.1.5.1.2 "><p id="p168274141266"><a name="p168274141266"></a><a name="p168274141266"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.061406140614064%" headers="mcps1.1.5.1.3 "><p id="p189965951415"><a name="p189965951415"></a><a name="p189965951415"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.66456645664567%" headers="mcps1.1.5.1.4 "><p id="p1982720141468"><a name="p1982720141468"></a><a name="p1982720141468"></a>Timeout duration. This parameter is optional. The default value is <strong id="b1179575510347"><a name="b1179575510347"></a><a name="b1179575510347"></a>0</strong>, indicating no timeout.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1668851410616"></a>
    <table><thead align="left"><tr id="row14827141413618"><th class="cellrowborder" valign="top" width="31.97%" id="mcps1.1.3.1.1"><p id="p3827814263"><a name="p3827814263"></a><a name="p3827814263"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="68.03%" id="mcps1.1.3.1.2"><p id="p178281514064"><a name="p178281514064"></a><a name="p178281514064"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row158281714461"><td class="cellrowborder" valign="top" width="31.97%" headers="mcps1.1.3.1.1 "><p id="p982810141762"><a name="p982810141762"></a><a name="p982810141762"></a>Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="68.03%" headers="mcps1.1.3.1.2 "><p id="p47448548549"><a name="p47448548549"></a><a name="p47448548549"></a>Returns the size of the transmitted or received data block if the control transfer is successful; returns <strong id="b1534141920393"><a name="b1534141920393"></a><a name="b1534141920393"></a>-1</strong> if an exception occurs.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    // Call usb.getDevices to obtain a data set. Then, obtain a USB device and its access permission.
    // Pass the obtained USB device as a parameter to usb.connectDevice. Then, call usb.connectDevice to connect the USB device.
    // Call usb.claimInterface to claim the USB interface. After that, call usb.bulkTransfer to start bulk transfer.
    usb.bulkTransfer(devicepipe, endpoint, buffer).then((ret) => {
     console.log(`bulkTransfer = ${JSON.stringify(ret)}`);
    });
    ```


## usb.closePipe<a name="section561261018199"></a>

usb.closePipe\(pipe: USBDevicePipe\): number

Closes a USB device pipe.

Before you do this, call  [usb.getDevices](#section1885592111287)  to obtain the USB device list, call  [usb.requestRight](#section1865915394353)  to request the device access permission, and call  [usb.connectDevice](#section910254722918)  to obtain  **devicepipe**  as an input parameter.

-   Parameters

    <a name="table156441951151316"></a>
    <table><thead align="left"><tr id="row13780185117135"><th class="cellrowborder" valign="top" width="24.842484248424842%" id="mcps1.1.5.1.1"><p id="p0780135111313"><a name="p0780135111313"></a><a name="p0780135111313"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.072207220722074%" id="mcps1.1.5.1.2"><p id="p1678085161314"><a name="p1678085161314"></a><a name="p1678085161314"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.341134113411341%" id="mcps1.1.5.1.3"><p id="p0662152218194"><a name="p0662152218194"></a><a name="p0662152218194"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="41.74417441744174%" id="mcps1.1.5.1.4"><p id="p4780251191311"><a name="p4780251191311"></a><a name="p4780251191311"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13780205111137"><td class="cellrowborder" valign="top" width="24.842484248424842%" headers="mcps1.1.5.1.1 "><p id="p1478095117135"><a name="p1478095117135"></a><a name="p1478095117135"></a>pipe</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.072207220722074%" headers="mcps1.1.5.1.2 "><p id="p178017519138"><a name="p178017519138"></a><a name="p178017519138"></a><a href="#section353972413263">USBDevicePipe</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="11.341134113411341%" headers="mcps1.1.5.1.3 "><p id="p156621225191"><a name="p156621225191"></a><a name="p156621225191"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.74417441744174%" headers="mcps1.1.5.1.4 "><p id="p108741113182319"><a name="p108741113182319"></a><a name="p108741113182319"></a>USB device pipe.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table11649165118138"></a>
    <table><thead align="left"><tr id="row7780751171312"><th class="cellrowborder" valign="top" width="17.07%" id="mcps1.1.3.1.1"><p id="p12780155112139"><a name="p12780155112139"></a><a name="p12780155112139"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.93%" id="mcps1.1.3.1.2"><p id="p10781351141314"><a name="p10781351141314"></a><a name="p10781351141314"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19781175116136"><td class="cellrowborder" valign="top" width="17.07%" headers="mcps1.1.3.1.1 "><p id="p3781145101312"><a name="p3781145101312"></a><a name="p3781145101312"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.93%" headers="mcps1.1.3.1.2 "><p id="p1784614112914"><a name="p1784614112914"></a><a name="p1784614112914"></a>Returns <strong id="b164461237102412"><a name="b164461237102412"></a><a name="b164461237102412"></a>0</strong> if the USB device pipe is closed successfully; returns an error code otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let ret = usb.closePipe(devicepipe);
    console.log(`closePipe = ${ret}`);
    ```


## USBEndpoint<a name="section193341439136"></a>

Represents the USB endpoint from which data is sent or received. You can obtain the USB endpoint through  [USBInterface](#section1564414611311).

<a name="table2364636777"></a>
<table><thead align="left"><tr id="row19365136878"><th class="cellrowborder" valign="top" width="27.24272427242724%" id="mcps1.1.4.1.1"><p id="p1610322561817"><a name="p1610322561817"></a><a name="p1610322561817"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="34.16341634163416%" id="mcps1.1.4.1.2"><p id="p20103132551816"><a name="p20103132551816"></a><a name="p20103132551816"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="38.59385938593859%" id="mcps1.1.4.1.3"><p id="p19103125141812"><a name="p19103125141812"></a><a name="p19103125141812"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row63664361713"><td class="cellrowborder" valign="top" width="27.24272427242724%" headers="mcps1.1.4.1.1 "><p id="p14249639867"><a name="p14249639867"></a><a name="p14249639867"></a>address</p>
</td>
<td class="cellrowborder" valign="top" width="34.16341634163416%" headers="mcps1.1.4.1.2 "><p id="p93469479619"><a name="p93469479619"></a><a name="p93469479619"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="38.59385938593859%" headers="mcps1.1.4.1.3 "><p id="p813616591366"><a name="p813616591366"></a><a name="p813616591366"></a>Endpoint address.</p>
</td>
</tr>
<tr id="row236683613720"><td class="cellrowborder" valign="top" width="27.24272427242724%" headers="mcps1.1.4.1.1 "><p id="p540311121489"><a name="p540311121489"></a><a name="p540311121489"></a>attributes</p>
</td>
<td class="cellrowborder" valign="top" width="34.16341634163416%" headers="mcps1.1.4.1.2 "><p id="p203201016482"><a name="p203201016482"></a><a name="p203201016482"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="38.59385938593859%" headers="mcps1.1.4.1.3 "><p id="p661815273816"><a name="p661815273816"></a><a name="p661815273816"></a>Endpoint attributes.</p>
</td>
</tr>
<tr id="row1536710360719"><td class="cellrowborder" valign="top" width="27.24272427242724%" headers="mcps1.1.4.1.1 "><p id="p17922154618817"><a name="p17922154618817"></a><a name="p17922154618817"></a>interval</p>
</td>
<td class="cellrowborder" valign="top" width="34.16341634163416%" headers="mcps1.1.4.1.2 "><p id="p12367123617711"><a name="p12367123617711"></a><a name="p12367123617711"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="38.59385938593859%" headers="mcps1.1.4.1.3 "><p id="p13464662096"><a name="p13464662096"></a><a name="p13464662096"></a>Endpoint interval.</p>
</td>
</tr>
<tr id="row17367736277"><td class="cellrowborder" valign="top" width="27.24272427242724%" headers="mcps1.1.4.1.1 "><p id="p1098191218912"><a name="p1098191218912"></a><a name="p1098191218912"></a>maxPacketSize</p>
</td>
<td class="cellrowborder" valign="top" width="34.16341634163416%" headers="mcps1.1.4.1.2 "><p id="p35921542897"><a name="p35921542897"></a><a name="p35921542897"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="38.59385938593859%" headers="mcps1.1.4.1.3 "><p id="p9942716696"><a name="p9942716696"></a><a name="p9942716696"></a>Maximum size of data packets on the endpoint.</p>
</td>
</tr>
<tr id="row14367113619710"><td class="cellrowborder" valign="top" width="27.24272427242724%" headers="mcps1.1.4.1.1 "><p id="p51711471095"><a name="p51711471095"></a><a name="p51711471095"></a>direction</p>
</td>
<td class="cellrowborder" valign="top" width="34.16341634163416%" headers="mcps1.1.4.1.2 "><p id="p1621817536919"><a name="p1621817536919"></a><a name="p1621817536919"></a><a href="#section19457181210556">USBRequestDirection</a></p>
</td>
<td class="cellrowborder" valign="top" width="38.59385938593859%" headers="mcps1.1.4.1.3 "><p id="p345143117103"><a name="p345143117103"></a><a name="p345143117103"></a>Endpoint direction.</p>
</td>
</tr>
<tr id="row836712361379"><td class="cellrowborder" valign="top" width="27.24272427242724%" headers="mcps1.1.4.1.1 "><p id="p16351920101111"><a name="p16351920101111"></a><a name="p16351920101111"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="34.16341634163416%" headers="mcps1.1.4.1.2 "><p id="p152111742181116"><a name="p152111742181116"></a><a name="p152111742181116"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="38.59385938593859%" headers="mcps1.1.4.1.3 "><p id="p1876003614105"><a name="p1876003614105"></a><a name="p1876003614105"></a>Endpoint number.</p>
</td>
</tr>
<tr id="row336819368720"><td class="cellrowborder" valign="top" width="27.24272427242724%" headers="mcps1.1.4.1.1 "><p id="p662012461116"><a name="p662012461116"></a><a name="p662012461116"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="34.16341634163416%" headers="mcps1.1.4.1.2 "><p id="p12790164241117"><a name="p12790164241117"></a><a name="p12790164241117"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="38.59385938593859%" headers="mcps1.1.4.1.3 "><p id="p1269911503112"><a name="p1269911503112"></a><a name="p1269911503112"></a>Endpoint type.</p>
</td>
</tr>
<tr id="row17581153241113"><td class="cellrowborder" valign="top" width="27.24272427242724%" headers="mcps1.1.4.1.1 "><p id="p35834331114"><a name="p35834331114"></a><a name="p35834331114"></a>interfaceId</p>
</td>
<td class="cellrowborder" valign="top" width="34.16341634163416%" headers="mcps1.1.4.1.2 "><p id="p1545819434116"><a name="p1545819434116"></a><a name="p1545819434116"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="38.59385938593859%" headers="mcps1.1.4.1.3 "><p id="p4598558171112"><a name="p4598558171112"></a><a name="p4598558171112"></a>Unique ID of the interface to which the endpoint belongs.</p>
</td>
</tr>
</tbody>
</table>

## USBInterface<a name="section1564414611311"></a>

Represents a USB interface. One  [USBConfig](#section1172111051715)  can contain multiple  **USBInterface**  instances, each providing a specific function.

<a name="table7418426161418"></a>
<table><thead align="left"><tr id="row204192260147"><th class="cellrowborder" valign="top" width="26.412641264126414%" id="mcps1.1.4.1.1"><p id="p12909154211142"><a name="p12909154211142"></a><a name="p12909154211142"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.232923292329232%" id="mcps1.1.4.1.2"><p id="p1990964281412"><a name="p1990964281412"></a><a name="p1990964281412"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="44.354435443544354%" id="mcps1.1.4.1.3"><p id="p10909442171411"><a name="p10909442171411"></a><a name="p10909442171411"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row741942617142"><td class="cellrowborder" valign="top" width="26.412641264126414%" headers="mcps1.1.4.1.1 "><p id="p103637373147"><a name="p103637373147"></a><a name="p103637373147"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="29.232923292329232%" headers="mcps1.1.4.1.2 "><p id="p1627081911520"><a name="p1627081911520"></a><a name="p1627081911520"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.354435443544354%" headers="mcps1.1.4.1.3 "><p id="p16707308165"><a name="p16707308165"></a><a name="p16707308165"></a>Unique ID of the USB interface.</p>
</td>
</tr>
<tr id="row341915266147"><td class="cellrowborder" valign="top" width="26.412641264126414%" headers="mcps1.1.4.1.1 "><p id="p1843074981416"><a name="p1843074981416"></a><a name="p1843074981416"></a>protocol</p>
</td>
<td class="cellrowborder" valign="top" width="29.232923292329232%" headers="mcps1.1.4.1.2 "><p id="p1311442316157"><a name="p1311442316157"></a><a name="p1311442316157"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.354435443544354%" headers="mcps1.1.4.1.3 "><p id="p49190254162"><a name="p49190254162"></a><a name="p49190254162"></a>Interface protocol.</p>
</td>
</tr>
<tr id="row10419826141420"><td class="cellrowborder" valign="top" width="26.412641264126414%" headers="mcps1.1.4.1.1 "><p id="p5631353191418"><a name="p5631353191418"></a><a name="p5631353191418"></a>clazz</p>
</td>
<td class="cellrowborder" valign="top" width="29.232923292329232%" headers="mcps1.1.4.1.2 "><p id="p11797122316152"><a name="p11797122316152"></a><a name="p11797122316152"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.354435443544354%" headers="mcps1.1.4.1.3 "><p id="p13452321111612"><a name="p13452321111612"></a><a name="p13452321111612"></a>Device type.</p>
</td>
</tr>
<tr id="row12420126171413"><td class="cellrowborder" valign="top" width="26.412641264126414%" headers="mcps1.1.4.1.1 "><p id="p1697825631413"><a name="p1697825631413"></a><a name="p1697825631413"></a>subClass</p>
</td>
<td class="cellrowborder" valign="top" width="29.232923292329232%" headers="mcps1.1.4.1.2 "><p id="p17867112410159"><a name="p17867112410159"></a><a name="p17867112410159"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.354435443544354%" headers="mcps1.1.4.1.3 "><p id="p15583173161"><a name="p15583173161"></a><a name="p15583173161"></a>Device subclass.</p>
</td>
</tr>
<tr id="row74201226121412"><td class="cellrowborder" valign="top" width="26.412641264126414%" headers="mcps1.1.4.1.1 "><p id="p10969140151513"><a name="p10969140151513"></a><a name="p10969140151513"></a>alternateSetting</p>
</td>
<td class="cellrowborder" valign="top" width="29.232923292329232%" headers="mcps1.1.4.1.2 "><p id="p19359309155"><a name="p19359309155"></a><a name="p19359309155"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.354435443544354%" headers="mcps1.1.4.1.3 "><p id="p237014114169"><a name="p237014114169"></a><a name="p237014114169"></a>Settings for alternating between descriptors of the same USB interface.</p>
</td>
</tr>
<tr id="row1742014263141"><td class="cellrowborder" valign="top" width="26.412641264126414%" headers="mcps1.1.4.1.1 "><p id="p1991734111518"><a name="p1991734111518"></a><a name="p1991734111518"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="29.232923292329232%" headers="mcps1.1.4.1.2 "><p id="p10361173521513"><a name="p10361173521513"></a><a name="p10361173521513"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="44.354435443544354%" headers="mcps1.1.4.1.3 "><p id="p13991352162"><a name="p13991352162"></a><a name="p13991352162"></a>Interface name.</p>
</td>
</tr>
<tr id="row1742002671414"><td class="cellrowborder" valign="top" width="26.412641264126414%" headers="mcps1.1.4.1.1 "><p id="p7337280155"><a name="p7337280155"></a><a name="p7337280155"></a>endpoints</p>
</td>
<td class="cellrowborder" valign="top" width="29.232923292329232%" headers="mcps1.1.4.1.2 "><p id="p1499974251515"><a name="p1499974251515"></a><a name="p1499974251515"></a>Array&lt;<a href="#section193341439136">USBEndpoint</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="44.354435443544354%" headers="mcps1.1.4.1.3 "><p id="p683718011161"><a name="p683718011161"></a><a name="p683718011161"></a>Endpoints that belong to the USB interface.</p>
</td>
</tr>
</tbody>
</table>

## USBConfig<a name="section1172111051715"></a>

Represents the USB configuration. One  [USBDevice](#section14936845182012)  can contain multiple  **USBConfig**  instances.

<a name="table72104313184"></a>
<table><thead align="left"><tr id="row5211173121813"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p61822013191818"><a name="p61822013191818"></a><a name="p61822013191818"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="28.672867286728675%" id="mcps1.1.4.1.2"><p id="p718310136188"><a name="p718310136188"></a><a name="p718310136188"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="37.99379937993799%" id="mcps1.1.4.1.3"><p id="p418320136188"><a name="p418320136188"></a><a name="p418320136188"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row18211173111820"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p56651719131816"><a name="p56651719131816"></a><a name="p56651719131816"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="28.672867286728675%" headers="mcps1.1.4.1.2 "><p id="p1506819161910"><a name="p1506819161910"></a><a name="p1506819161910"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="37.99379937993799%" headers="mcps1.1.4.1.3 "><p id="p1094317273193"><a name="p1094317273193"></a><a name="p1094317273193"></a>Unique ID of the USB configuration.</p>
</td>
</tr>
<tr id="row42115313183"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p1243642351813"><a name="p1243642351813"></a><a name="p1243642351813"></a>attributes</p>
</td>
<td class="cellrowborder" valign="top" width="28.672867286728675%" headers="mcps1.1.4.1.2 "><p id="p15761182131910"><a name="p15761182131910"></a><a name="p15761182131910"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="37.99379937993799%" headers="mcps1.1.4.1.3 "><p id="p799923216198"><a name="p799923216198"></a><a name="p799923216198"></a>Configuration attributes.</p>
</td>
</tr>
<tr id="row13211123171810"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p7929192661812"><a name="p7929192661812"></a><a name="p7929192661812"></a>maxPower</p>
</td>
<td class="cellrowborder" valign="top" width="28.672867286728675%" headers="mcps1.1.4.1.2 "><p id="p8275920131911"><a name="p8275920131911"></a><a name="p8275920131911"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="37.99379937993799%" headers="mcps1.1.4.1.3 "><p id="p161021238181916"><a name="p161021238181916"></a><a name="p161021238181916"></a>Maximum power consumption, in mA.</p>
</td>
</tr>
<tr id="row142125318188"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p111851730171817"><a name="p111851730171817"></a><a name="p111851730171817"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="28.672867286728675%" headers="mcps1.1.4.1.2 "><p id="p0503410111915"><a name="p0503410111915"></a><a name="p0503410111915"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="37.99379937993799%" headers="mcps1.1.4.1.3 "><p id="p18689114391910"><a name="p18689114391910"></a><a name="p18689114391910"></a>Configuration name, which can be left empty.</p>
</td>
</tr>
<tr id="row1821212311812"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p11691173401820"><a name="p11691173401820"></a><a name="p11691173401820"></a>isRemoteWakeup</p>
</td>
<td class="cellrowborder" valign="top" width="28.672867286728675%" headers="mcps1.1.4.1.2 "><p id="p17596458193"><a name="p17596458193"></a><a name="p17596458193"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="37.99379937993799%" headers="mcps1.1.4.1.3 "><p id="p235313485193"><a name="p235313485193"></a><a name="p235313485193"></a>Support for remote wakeup.</p>
</td>
</tr>
<tr id="row2212937187"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p15142113915189"><a name="p15142113915189"></a><a name="p15142113915189"></a>isSelfPowered</p>
</td>
<td class="cellrowborder" valign="top" width="28.672867286728675%" headers="mcps1.1.4.1.2 "><p id="p1310114114198"><a name="p1310114114198"></a><a name="p1310114114198"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="37.99379937993799%" headers="mcps1.1.4.1.3 "><p id="p1086955314191"><a name="p1086955314191"></a><a name="p1086955314191"></a>Support for independent power supplies.</p>
</td>
</tr>
<tr id="row122122351816"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p824943131818"><a name="p824943131818"></a><a name="p824943131818"></a>interfaces</p>
</td>
<td class="cellrowborder" valign="top" width="28.672867286728675%" headers="mcps1.1.4.1.2 "><p id="p13897949151813"><a name="p13897949151813"></a><a name="p13897949151813"></a>Array &lt;<a href="#section1564414611311">USBInterface</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="37.99379937993799%" headers="mcps1.1.4.1.3 "><p id="p6249175917197"><a name="p6249175917197"></a><a name="p6249175917197"></a>Supported interface attributes.</p>
</td>
</tr>
</tbody>
</table>

## USBDevice<a name="section14936845182012"></a>

Represents a USB device.

<a name="table193991522112"></a>
<table><thead align="left"><tr id="row4400165122112"><th class="cellrowborder" valign="top" width="33.31333133313331%" id="mcps1.1.4.1.1"><p id="p114008552114"><a name="p114008552114"></a><a name="p114008552114"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.4029402940294%" id="mcps1.1.4.1.2"><p id="p54008510211"><a name="p54008510211"></a><a name="p54008510211"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="37.28372837283728%" id="mcps1.1.4.1.3"><p id="p14001559213"><a name="p14001559213"></a><a name="p14001559213"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row164007582118"><td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.1.4.1.1 "><p id="p2699133522120"><a name="p2699133522120"></a><a name="p2699133522120"></a>busNum</p>
</td>
<td class="cellrowborder" valign="top" width="29.4029402940294%" headers="mcps1.1.4.1.2 "><p id="p124002515213"><a name="p124002515213"></a><a name="p124002515213"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="37.28372837283728%" headers="mcps1.1.4.1.3 "><p id="p588294852513"><a name="p588294852513"></a><a name="p588294852513"></a>Bus address.</p>
</td>
</tr>
<tr id="row64001751219"><td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.1.4.1.1 "><p id="p12258104010210"><a name="p12258104010210"></a><a name="p12258104010210"></a>devAddress</p>
</td>
<td class="cellrowborder" valign="top" width="29.4029402940294%" headers="mcps1.1.4.1.2 "><p id="p840118514218"><a name="p840118514218"></a><a name="p840118514218"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="37.28372837283728%" headers="mcps1.1.4.1.3 "><p id="p106992041182519"><a name="p106992041182519"></a><a name="p106992041182519"></a>Device address.</p>
</td>
</tr>
<tr id="row1740116511212"><td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.1.4.1.1 "><p id="p104387440215"><a name="p104387440215"></a><a name="p104387440215"></a>serial</p>
</td>
<td class="cellrowborder" valign="top" width="29.4029402940294%" headers="mcps1.1.4.1.2 "><p id="p13736102542411"><a name="p13736102542411"></a><a name="p13736102542411"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="37.28372837283728%" headers="mcps1.1.4.1.3 "><p id="p149893532515"><a name="p149893532515"></a><a name="p149893532515"></a>Device SN.</p>
</td>
</tr>
<tr id="row9401145132117"><td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.1.4.1.1 "><p id="p4922184811213"><a name="p4922184811213"></a><a name="p4922184811213"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="29.4029402940294%" headers="mcps1.1.4.1.2 "><p id="p1463792682413"><a name="p1463792682413"></a><a name="p1463792682413"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="37.28372837283728%" headers="mcps1.1.4.1.3 "><p id="p16453132712258"><a name="p16453132712258"></a><a name="p16453132712258"></a>Device name.</p>
</td>
</tr>
<tr id="row10401195142116"><td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.1.4.1.1 "><p id="p17518253152111"><a name="p17518253152111"></a><a name="p17518253152111"></a>manufacturerName</p>
</td>
<td class="cellrowborder" valign="top" width="29.4029402940294%" headers="mcps1.1.4.1.2 "><p id="p115651927142410"><a name="p115651927142410"></a><a name="p115651927142410"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="37.28372837283728%" headers="mcps1.1.4.1.3 "><p id="p96281211132520"><a name="p96281211132520"></a><a name="p96281211132520"></a>Device manufacturer.</p>
</td>
</tr>
<tr id="row15402955210"><td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.1.4.1.1 "><p id="p1656105712219"><a name="p1656105712219"></a><a name="p1656105712219"></a>productName</p>
</td>
<td class="cellrowborder" valign="top" width="29.4029402940294%" headers="mcps1.1.4.1.2 "><p id="p157163514245"><a name="p157163514245"></a><a name="p157163514245"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="37.28372837283728%" headers="mcps1.1.4.1.3 "><p id="p1754529102519"><a name="p1754529102519"></a><a name="p1754529102519"></a>Product name.</p>
</td>
</tr>
<tr id="row1840215132116"><td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.1.4.1.1 "><p id="p1771110112228"><a name="p1771110112228"></a><a name="p1771110112228"></a>version</p>
</td>
<td class="cellrowborder" valign="top" width="29.4029402940294%" headers="mcps1.1.4.1.2 "><p id="p2070743552417"><a name="p2070743552417"></a><a name="p2070743552417"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="37.28372837283728%" headers="mcps1.1.4.1.3 "><p id="p103579210259"><a name="p103579210259"></a><a name="p103579210259"></a>Product version.</p>
</td>
</tr>
<tr id="row141971965222"><td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.1.4.1.1 "><p id="p1129402212225"><a name="p1129402212225"></a><a name="p1129402212225"></a>vendorId</p>
</td>
<td class="cellrowborder" valign="top" width="29.4029402940294%" headers="mcps1.1.4.1.2 "><p id="p1819811616228"><a name="p1819811616228"></a><a name="p1819811616228"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="37.28372837283728%" headers="mcps1.1.4.1.3 "><p id="p335211217241"><a name="p335211217241"></a><a name="p335211217241"></a>Vendor ID.</p>
</td>
</tr>
<tr id="row5872172516224"><td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.1.4.1.1 "><p id="p20702162920224"><a name="p20702162920224"></a><a name="p20702162920224"></a>productId</p>
</td>
<td class="cellrowborder" valign="top" width="29.4029402940294%" headers="mcps1.1.4.1.2 "><p id="p1887382512211"><a name="p1887382512211"></a><a name="p1887382512211"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="37.28372837283728%" headers="mcps1.1.4.1.3 "><p id="p198731525122213"><a name="p198731525122213"></a><a name="p198731525122213"></a>Product ID.</p>
</td>
</tr>
<tr id="row101371232162216"><td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.1.4.1.1 "><p id="p148682356228"><a name="p148682356228"></a><a name="p148682356228"></a>clazz</p>
</td>
<td class="cellrowborder" valign="top" width="29.4029402940294%" headers="mcps1.1.4.1.2 "><p id="p1513733242217"><a name="p1513733242217"></a><a name="p1513733242217"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="37.28372837283728%" headers="mcps1.1.4.1.3 "><p id="p138779577236"><a name="p138779577236"></a><a name="p138779577236"></a>Device class.</p>
</td>
</tr>
<tr id="row153201440142214"><td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.1.4.1.1 "><p id="p1573364482213"><a name="p1573364482213"></a><a name="p1573364482213"></a>subClass</p>
</td>
<td class="cellrowborder" valign="top" width="29.4029402940294%" headers="mcps1.1.4.1.2 "><p id="p8321124010224"><a name="p8321124010224"></a><a name="p8321124010224"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="37.28372837283728%" headers="mcps1.1.4.1.3 "><p id="p5184632192311"><a name="p5184632192311"></a><a name="p5184632192311"></a>Device subclass.</p>
</td>
</tr>
<tr id="row1327314485226"><td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.1.4.1.1 "><p id="p1581165315220"><a name="p1581165315220"></a><a name="p1581165315220"></a>protocol</p>
</td>
<td class="cellrowborder" valign="top" width="29.4029402940294%" headers="mcps1.1.4.1.2 "><p id="p8977172222314"><a name="p8977172222314"></a><a name="p8977172222314"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="37.28372837283728%" headers="mcps1.1.4.1.3 "><p id="p1645382618237"><a name="p1645382618237"></a><a name="p1645382618237"></a>Device protocol code.</p>
</td>
</tr>
<tr id="row1698325582217"><td class="cellrowborder" valign="top" width="33.31333133313331%" headers="mcps1.1.4.1.1 "><p id="p165096593227"><a name="p165096593227"></a><a name="p165096593227"></a>configs</p>
</td>
<td class="cellrowborder" valign="top" width="29.4029402940294%" headers="mcps1.1.4.1.2 "><p id="p021987202316"><a name="p021987202316"></a><a name="p021987202316"></a>Array&lt;<a href="#section1172111051715">USBConfig</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="37.28372837283728%" headers="mcps1.1.4.1.3 "><p id="p659217182237"><a name="p659217182237"></a><a name="p659217182237"></a>Device configuration descriptor information.</p>
</td>
</tr>
</tbody>
</table>

## USBDevicePipe<a name="section353972413263"></a>

Represents a USB device pipe, which is used to determine a USB device.

<a name="table17553174262614"></a>
<table><thead align="left"><tr id="row205546428261"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p47850533268"><a name="p47850533268"></a><a name="p47850533268"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p3785105320265"><a name="p3785105320265"></a><a name="p3785105320265"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p278685342616"><a name="p278685342616"></a><a name="p278685342616"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row155419423261"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p1941817119279"><a name="p1941817119279"></a><a name="p1941817119279"></a>busNum</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p175176818274"><a name="p175176818274"></a><a name="p175176818274"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1750111144279"><a name="p1750111144279"></a><a name="p1750111144279"></a>Bus address.</p>
</td>
</tr>
<tr id="row85547426260"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p13511658272"><a name="p13511658272"></a><a name="p13511658272"></a>devAddress</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p93168932711"><a name="p93168932711"></a><a name="p93168932711"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1879121122719"><a name="p1879121122719"></a><a name="p1879121122719"></a>Device address.</p>
</td>
</tr>
</tbody>
</table>

## USBControlParams<a name="section124996013327"></a>

Represents control transfer parameters.

<a name="table1293220713217"></a>
<table><thead align="left"><tr id="row79325719325"><th class="cellrowborder" valign="top" width="25.567443255674434%" id="mcps1.1.4.1.1"><p id="p836331611328"><a name="p836331611328"></a><a name="p836331611328"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="35.896410358964104%" id="mcps1.1.4.1.2"><p id="p133632167322"><a name="p133632167322"></a><a name="p133632167322"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="38.53614638536146%" id="mcps1.1.4.1.3"><p id="p1036371618324"><a name="p1036371618324"></a><a name="p1036371618324"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1293347163218"><td class="cellrowborder" valign="top" width="25.567443255674434%" headers="mcps1.1.4.1.1 "><p id="p181958218328"><a name="p181958218328"></a><a name="p181958218328"></a>request</p>
</td>
<td class="cellrowborder" valign="top" width="35.896410358964104%" headers="mcps1.1.4.1.2 "><p id="p2795105815339"><a name="p2795105815339"></a><a name="p2795105815339"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="38.53614638536146%" headers="mcps1.1.4.1.3 "><p id="p69331977327"><a name="p69331977327"></a><a name="p69331977327"></a>Request type.</p>
</td>
</tr>
<tr id="row79335710321"><td class="cellrowborder" valign="top" width="25.567443255674434%" headers="mcps1.1.4.1.1 "><p id="p1646312433215"><a name="p1646312433215"></a><a name="p1646312433215"></a>target</p>
</td>
<td class="cellrowborder" valign="top" width="35.896410358964104%" headers="mcps1.1.4.1.2 "><p id="p04874393320"><a name="p04874393320"></a><a name="p04874393320"></a><a href="#section11962191113510">USBRequestTargetType</a></p>
</td>
<td class="cellrowborder" valign="top" width="38.53614638536146%" headers="mcps1.1.4.1.3 "><p id="p19569847143313"><a name="p19569847143313"></a><a name="p19569847143313"></a>Request target type.</p>
</td>
</tr>
<tr id="row19933157143219"><td class="cellrowborder" valign="top" width="25.567443255674434%" headers="mcps1.1.4.1.1 "><p id="p11838102703215"><a name="p11838102703215"></a><a name="p11838102703215"></a>reqType</p>
</td>
<td class="cellrowborder" valign="top" width="35.896410358964104%" headers="mcps1.1.4.1.2 "><p id="p17188132183310"><a name="p17188132183310"></a><a name="p17188132183310"></a><a href="#section1441863214538">USBControlRequestType</a></p>
</td>
<td class="cellrowborder" valign="top" width="38.53614638536146%" headers="mcps1.1.4.1.3 "><p id="p191111139143312"><a name="p191111139143312"></a><a name="p191111139143312"></a>Request control type.</p>
</td>
</tr>
<tr id="row29331079325"><td class="cellrowborder" valign="top" width="25.567443255674434%" headers="mcps1.1.4.1.1 "><p id="p2792103014321"><a name="p2792103014321"></a><a name="p2792103014321"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="35.896410358964104%" headers="mcps1.1.4.1.2 "><p id="p1654752319338"><a name="p1654752319338"></a><a name="p1654752319338"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="38.53614638536146%" headers="mcps1.1.4.1.3 "><p id="p1369611274337"><a name="p1369611274337"></a><a name="p1369611274337"></a>Request parameter value.</p>
</td>
</tr>
<tr id="row193313716323"><td class="cellrowborder" valign="top" width="25.567443255674434%" headers="mcps1.1.4.1.1 "><p id="p19939153320327"><a name="p19939153320327"></a><a name="p19939153320327"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="35.896410358964104%" headers="mcps1.1.4.1.2 "><p id="p18327513103317"><a name="p18327513103317"></a><a name="p18327513103317"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="38.53614638536146%" headers="mcps1.1.4.1.3 "><p id="p1673791919332"><a name="p1673791919332"></a><a name="p1673791919332"></a>Index of the request parameter value.</p>
</td>
</tr>
<tr id="row693327153211"><td class="cellrowborder" valign="top" width="25.567443255674434%" headers="mcps1.1.4.1.1 "><p id="p198405375324"><a name="p198405375324"></a><a name="p198405375324"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="35.896410358964104%" headers="mcps1.1.4.1.2 "><p id="p59337763214"><a name="p59337763214"></a><a name="p59337763214"></a>Uint8Array</p>
</td>
<td class="cellrowborder" valign="top" width="38.53614638536146%" headers="mcps1.1.4.1.3 "><p id="p1565854183315"><a name="p1565854183315"></a><a name="p1565854183315"></a>Data written to or read from the buffer.</p>
</td>
</tr>
</tbody>
</table>

## USBRequestTargetType<a name="section11962191113510"></a>

Enumerates USB request target types.

<a name="table114895277514"></a>
<table><thead align="left"><tr id="row249192725112"><th class="cellrowborder" valign="top" width="42.96%" id="mcps1.1.4.1.1"><p id="p84911627115119"><a name="p84911627115119"></a><a name="p84911627115119"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.71%" id="mcps1.1.4.1.2"><p id="p64916279512"><a name="p64916279512"></a><a name="p64916279512"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="33.33%" id="mcps1.1.4.1.3"><p id="p184911227105111"><a name="p184911227105111"></a><a name="p184911227105111"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row849117277510"><td class="cellrowborder" valign="top" width="42.96%" headers="mcps1.1.4.1.1 "><p id="p9598247195111"><a name="p9598247195111"></a><a name="p9598247195111"></a>USB_REQUEST_TARGET_DEVICE</p>
</td>
<td class="cellrowborder" valign="top" width="23.71%" headers="mcps1.1.4.1.2 "><p id="p164911427165115"><a name="p164911427165115"></a><a name="p164911427165115"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.33%" headers="mcps1.1.4.1.3 "><p id="p95542314523"><a name="p95542314523"></a><a name="p95542314523"></a>Device</p>
</td>
</tr>
<tr id="row13492327165118"><td class="cellrowborder" valign="top" width="42.96%" headers="mcps1.1.4.1.1 "><p id="p173945212515"><a name="p173945212515"></a><a name="p173945212515"></a>USB_REQUEST_TARGET_INTERFACE</p>
</td>
<td class="cellrowborder" valign="top" width="23.71%" headers="mcps1.1.4.1.2 "><p id="p1249212279519"><a name="p1249212279519"></a><a name="p1249212279519"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.33%" headers="mcps1.1.4.1.3 "><p id="p1049218277517"><a name="p1049218277517"></a><a name="p1049218277517"></a>Interface</p>
</td>
</tr>
<tr id="row34924277513"><td class="cellrowborder" valign="top" width="42.96%" headers="mcps1.1.4.1.1 "><p id="p1840965745113"><a name="p1840965745113"></a><a name="p1840965745113"></a>USB_REQUEST_TARGET_ENDPOINT</p>
</td>
<td class="cellrowborder" valign="top" width="23.71%" headers="mcps1.1.4.1.2 "><p id="p15492162712517"><a name="p15492162712517"></a><a name="p15492162712517"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33.33%" headers="mcps1.1.4.1.3 "><p id="p049252714512"><a name="p049252714512"></a><a name="p049252714512"></a>Endpoint</p>
</td>
</tr>
<tr id="row9258143235117"><td class="cellrowborder" valign="top" width="42.96%" headers="mcps1.1.4.1.1 "><p id="p1244610175220"><a name="p1244610175220"></a><a name="p1244610175220"></a>USB_REQUEST_TARGET_OTHER</p>
</td>
<td class="cellrowborder" valign="top" width="23.71%" headers="mcps1.1.4.1.2 "><p id="p3259203215518"><a name="p3259203215518"></a><a name="p3259203215518"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="33.33%" headers="mcps1.1.4.1.3 "><p id="p1725923265112"><a name="p1725923265112"></a><a name="p1725923265112"></a>Others</p>
</td>
</tr>
</tbody>
</table>

## USBControlRequestType<a name="section1441863214538"></a>

Enumerates control request types.

<a name="table21016460537"></a>
<table><thead align="left"><tr id="row4101164613531"><th class="cellrowborder" valign="top" width="44.43%" id="mcps1.1.4.1.1"><p id="p121012462539"><a name="p121012462539"></a><a name="p121012462539"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.970000000000002%" id="mcps1.1.4.1.2"><p id="p61011146105314"><a name="p61011146105314"></a><a name="p61011146105314"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="25.6%" id="mcps1.1.4.1.3"><p id="p15101946185310"><a name="p15101946185310"></a><a name="p15101946185310"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3102144615539"><td class="cellrowborder" valign="top" width="44.43%" headers="mcps1.1.4.1.1 "><p id="p148633153541"><a name="p148633153541"></a><a name="p148633153541"></a>USB_REQUEST_TYPE_STANDARD</p>
</td>
<td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.1.4.1.2 "><p id="p16102154614533"><a name="p16102154614533"></a><a name="p16102154614533"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="25.6%" headers="mcps1.1.4.1.3 "><p id="p19102346105319"><a name="p19102346105319"></a><a name="p19102346105319"></a>Standard</p>
</td>
</tr>
<tr id="row910234655315"><td class="cellrowborder" valign="top" width="44.43%" headers="mcps1.1.4.1.1 "><p id="p19611221145414"><a name="p19611221145414"></a><a name="p19611221145414"></a>USB_REQUEST_TYPE_CLASS</p>
</td>
<td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.1.4.1.2 "><p id="p5102184616539"><a name="p5102184616539"></a><a name="p5102184616539"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="25.6%" headers="mcps1.1.4.1.3 "><p id="p1510215461539"><a name="p1510215461539"></a><a name="p1510215461539"></a>Class</p>
</td>
</tr>
<tr id="row9102184635313"><td class="cellrowborder" valign="top" width="44.43%" headers="mcps1.1.4.1.1 "><p id="p276392415546"><a name="p276392415546"></a><a name="p276392415546"></a>USB_REQUEST_TYPE_VENDOR</p>
</td>
<td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.1.4.1.2 "><p id="p410294612534"><a name="p410294612534"></a><a name="p410294612534"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="25.6%" headers="mcps1.1.4.1.3 "><p id="p12103246175312"><a name="p12103246175312"></a><a name="p12103246175312"></a>Vendor</p>
</td>
</tr>
</tbody>
</table>

## USBRequestDirection<a name="section19457181210556"></a>

Enumerates request directions.

<a name="table18964172585517"></a>
<table><thead align="left"><tr id="row1965525145513"><th class="cellrowborder" valign="top" width="38.85%" id="mcps1.1.4.1.1"><p id="p796552575514"><a name="p796552575514"></a><a name="p796552575514"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.69%" id="mcps1.1.4.1.2"><p id="p139651725195510"><a name="p139651725195510"></a><a name="p139651725195510"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="37.46%" id="mcps1.1.4.1.3"><p id="p89655256552"><a name="p89655256552"></a><a name="p89655256552"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row496582515512"><td class="cellrowborder" valign="top" width="38.85%" headers="mcps1.1.4.1.1 "><p id="p396513251551"><a name="p396513251551"></a><a name="p396513251551"></a>USB_REQUEST_TYPE_STANDARD</p>
</td>
<td class="cellrowborder" valign="top" width="23.69%" headers="mcps1.1.4.1.2 "><p id="p5965162525515"><a name="p5965162525515"></a><a name="p5965162525515"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="37.46%" headers="mcps1.1.4.1.3 "><p id="p596515259559"><a name="p596515259559"></a><a name="p596515259559"></a>Request for writing data from the host to the device.</p>
</td>
</tr>
<tr id="row69659251552"><td class="cellrowborder" valign="top" width="38.85%" headers="mcps1.1.4.1.1 "><p id="p19651525115510"><a name="p19651525115510"></a><a name="p19651525115510"></a>USB_REQUEST_TYPE_CLASS</p>
</td>
<td class="cellrowborder" valign="top" width="23.69%" headers="mcps1.1.4.1.2 "><p id="p479117231561"><a name="p479117231561"></a><a name="p479117231561"></a>0x80</p>
</td>
<td class="cellrowborder" valign="top" width="37.46%" headers="mcps1.1.4.1.3 "><p id="p134812124563"><a name="p134812124563"></a><a name="p134812124563"></a>Request for reading data from the device to the host.</p>
</td>
</tr>
</tbody>
</table>

<a name="table2012130242"></a>
<table><thead align="left"><tr id="row312701847"><th class="cellrowborder" valign="top" width="35.099999999999994%" id="mcps1.1.4.1.1"><p id="p4122010412"><a name="p4122010412"></a><a name="p4122010412"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="32.45%" id="mcps1.1.4.1.2"><p id="p4121408419"><a name="p4121408419"></a><a name="p4121408419"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="32.45%" id="mcps1.1.4.1.3"><p id="p2121015412"><a name="p2121015412"></a><a name="p2121015412"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row812009418"><td class="cellrowborder" valign="top" width="35.099999999999994%" headers="mcps1.1.4.1.1 "><p id="p11131401446"><a name="p11131401446"></a><a name="p11131401446"></a>NONE</p>
</td>
<td class="cellrowborder" valign="top" width="32.45%" headers="mcps1.1.4.1.2 "><p id="p51310443"><a name="p51310443"></a><a name="p51310443"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="32.45%" headers="mcps1.1.4.1.3 "><p id="p161318013419"><a name="p161318013419"></a><a name="p161318013419"></a>None.</p>
</td>
</tr>
<tr id="row51310843"><td class="cellrowborder" valign="top" width="35.099999999999994%" headers="mcps1.1.4.1.1 "><p id="p8139020413"><a name="p8139020413"></a><a name="p8139020413"></a>ACM</p>
</td>
<td class="cellrowborder" valign="top" width="32.45%" headers="mcps1.1.4.1.2 "><p id="p71319018416"><a name="p71319018416"></a><a name="p71319018416"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="32.45%" headers="mcps1.1.4.1.3 "><p id="p191370245"><a name="p191370245"></a><a name="p191370245"></a>Serial port device</p>
</td>
</tr>
<tr id="row1113304420"><td class="cellrowborder" valign="top" width="35.099999999999994%" headers="mcps1.1.4.1.1 "><p id="p1813701042"><a name="p1813701042"></a><a name="p1813701042"></a>ECM</p>
</td>
<td class="cellrowborder" valign="top" width="32.45%" headers="mcps1.1.4.1.2 "><p id="p213170049"><a name="p213170049"></a><a name="p213170049"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="32.45%" headers="mcps1.1.4.1.3 "><p id="p1813110844"><a name="p1813110844"></a><a name="p1813110844"></a>Ethernet port device</p>
</td>
</tr>
<tr id="row1913301948"><td class="cellrowborder" valign="top" width="35.099999999999994%" headers="mcps1.1.4.1.1 "><p id="p91419012417"><a name="p91419012417"></a><a name="p91419012417"></a>HDC</p>
</td>
<td class="cellrowborder" valign="top" width="32.45%" headers="mcps1.1.4.1.2 "><p id="p5141101246"><a name="p5141101246"></a><a name="p5141101246"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="32.45%" headers="mcps1.1.4.1.3 "><p id="p1714170344"><a name="p1714170344"></a><a name="p1714170344"></a>HDC device</p>
</td>
</tr>
</tbody>
</table>


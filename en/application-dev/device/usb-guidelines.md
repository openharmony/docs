# USB Service Development<a name="EN-US_TOPIC_0000001177435986"></a>

## When to Use<a name="section312612461984"></a>

In Host mode, you can obtain the list of connected devices, enable or disable the devices, manage device access permissions, and perform data transfer or control transfer.

## APIs<a name="section912mcpsimp"></a>

The USB service provides the following functions: query of USB device list, bulk data transfer, control transfer, and access permission management.

The following table lists the USB APIs currently available. For details, see the  _API Reference_.

**Table  1**  Open USB APIs

<a name="table948mcpsimp"></a>
<table><thead align="left"><tr id="row954mcpsimp"><th class="cellrowborder" valign="top" width="58.589999999999996%" id="mcps1.2.3.1.1"><p id="p956mcpsimp"><a name="p956mcpsimp"></a><a name="p956mcpsimp"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="41.410000000000004%" id="mcps1.2.3.1.2"><p id="p958mcpsimp"><a name="p958mcpsimp"></a><a name="p958mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row960mcpsimp"><td class="cellrowborder" valign="top" width="58.589999999999996%" headers="mcps1.2.3.1.1 "><p id="p763891054416"><a name="p763891054416"></a><a name="p763891054416"></a>hasRight(deviceName: string): boolean</p>
</td>
<td class="cellrowborder" valign="top" width="41.410000000000004%" headers="mcps1.2.3.1.2 "><p id="p8666818458"><a name="p8666818458"></a><a name="p8666818458"></a>Checks whether the user, for example, the application or system, has the device access permissions. The value <strong id="b106930333555"><a name="b106930333555"></a><a name="b106930333555"></a>true</strong> is returned if the user has the device access permissions; the value <strong id="b72426431937"><a name="b72426431937"></a><a name="b72426431937"></a>false</strong> is returned otherwise.</p>
</td>
</tr>
<tr id="row965mcpsimp"><td class="cellrowborder" valign="top" width="58.589999999999996%" headers="mcps1.2.3.1.1 "><p id="p1063810103448"><a name="p1063810103448"></a><a name="p1063810103448"></a>requestRight(deviceName: string): Promise&lt;boolean&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="41.410000000000004%" headers="mcps1.2.3.1.2 "><p id="p18677811454"><a name="p18677811454"></a><a name="p18677811454"></a>Requests the temporary permission for a given application to access the USB device.</p>
</td>
</tr>
<tr id="row970mcpsimp"><td class="cellrowborder" valign="top" width="58.589999999999996%" headers="mcps1.2.3.1.1 "><p id="p196381710194415"><a name="p196381710194415"></a><a name="p196381710194415"></a>connectDevice(device: USBDevice): Readonly&lt;USBDevicePipe&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="41.410000000000004%" headers="mcps1.2.3.1.2 "><p id="p467178204510"><a name="p467178204510"></a><a name="p467178204510"></a>Connects to the USB device based on the device information returned by <strong id="b191413527412"><a name="b191413527412"></a><a name="b191413527412"></a>getDevices()</strong>.</p>
</td>
</tr>
<tr id="row975mcpsimp"><td class="cellrowborder" valign="top" width="58.589999999999996%" headers="mcps1.2.3.1.1 "><p id="p8638171010441"><a name="p8638171010441"></a><a name="p8638171010441"></a>getDevices(): Array&lt;Readonly&lt;USBDevice&gt;&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="41.410000000000004%" headers="mcps1.2.3.1.2 "><p id="p176715864514"><a name="p176715864514"></a><a name="p176715864514"></a>Obtains the USB device list.</p>
</td>
</tr>
<tr id="row1551153313610"><td class="cellrowborder" valign="top" width="58.589999999999996%" headers="mcps1.2.3.1.1 "><p id="p156381410184417"><a name="p156381410184417"></a><a name="p156381410184417"></a>setConfiguration(pipe: USBDevicePipe, config: USBConfig): number</p>
</td>
<td class="cellrowborder" valign="top" width="41.410000000000004%" headers="mcps1.2.3.1.2 "><p id="p126812817456"><a name="p126812817456"></a><a name="p126812817456"></a>Sets the USB device configuration.</p>
</td>
</tr>
<tr id="row1393711361263"><td class="cellrowborder" valign="top" width="58.589999999999996%" headers="mcps1.2.3.1.1 "><p id="p1563812109442"><a name="p1563812109442"></a><a name="p1563812109442"></a>setInterface(pipe: USBDevicePipe, iface: USBInterface): number</p>
</td>
<td class="cellrowborder" valign="top" width="41.410000000000004%" headers="mcps1.2.3.1.2 "><p id="p136868164513"><a name="p136868164513"></a><a name="p136868164513"></a>Sets a USB interface.</p>
</td>
</tr>
<tr id="row149651544154717"><td class="cellrowborder" valign="top" width="58.589999999999996%" headers="mcps1.2.3.1.1 "><p id="p991359174910"><a name="p991359174910"></a><a name="p991359174910"></a>claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number</p>
</td>
<td class="cellrowborder" valign="top" width="41.410000000000004%" headers="mcps1.2.3.1.2 "><p id="p20859028134917"><a name="p20859028134917"></a><a name="p20859028134917"></a>Claims a USB interface</p>
</td>
</tr>
<tr id="row115717481477"><td class="cellrowborder" valign="top" width="58.589999999999996%" headers="mcps1.2.3.1.1 "><p id="p17913393493"><a name="p17913393493"></a><a name="p17913393493"></a>function bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array, timeout?: number): Promise&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="41.410000000000004%" headers="mcps1.2.3.1.2 "><p id="p1786016281498"><a name="p1786016281498"></a><a name="p1786016281498"></a>Performs bulk transfer.</p>
</td>
</tr>
<tr id="row1042013527474"><td class="cellrowborder" valign="top" width="58.589999999999996%" headers="mcps1.2.3.1.1 "><p id="p19913596492"><a name="p19913596492"></a><a name="p19913596492"></a>closePipe(pipe: USBDevicePipe): number</p>
</td>
<td class="cellrowborder" valign="top" width="41.410000000000004%" headers="mcps1.2.3.1.2 "><p id="p686013285492"><a name="p686013285492"></a><a name="p686013285492"></a>Closes a USB device pipe.</p>
</td>
</tr>
<tr id="row954011574471"><td class="cellrowborder" valign="top" width="58.589999999999996%" headers="mcps1.2.3.1.1 "><p id="p491315910499"><a name="p491315910499"></a><a name="p491315910499"></a>releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number</p>
</td>
<td class="cellrowborder" valign="top" width="41.410000000000004%" headers="mcps1.2.3.1.2 "><p id="p14860202813493"><a name="p14860202813493"></a><a name="p14860202813493"></a>Releases a USB interface.</p>
</td>
</tr>
<tr id="row1475577184811"><td class="cellrowborder" valign="top" width="58.589999999999996%" headers="mcps1.2.3.1.1 "><p id="p69131096493"><a name="p69131096493"></a><a name="p69131096493"></a>getFileDescriptor(pipe: USBDevicePipe): number</p>
</td>
<td class="cellrowborder" valign="top" width="41.410000000000004%" headers="mcps1.2.3.1.2 "><p id="p16860202864913"><a name="p16860202864913"></a><a name="p16860202864913"></a>Obtains the file descriptor.</p>
</td>
</tr>
<tr id="row074819259481"><td class="cellrowborder" valign="top" width="58.589999999999996%" headers="mcps1.2.3.1.1 "><p id="p891416916496"><a name="p891416916496"></a><a name="p891416916496"></a>getRawDescriptor(pipe: USBDevicePipe): Uint8Array</p>
</td>
<td class="cellrowborder" valign="top" width="41.410000000000004%" headers="mcps1.2.3.1.2 "><p id="p486042804917"><a name="p486042804917"></a><a name="p486042804917"></a>Obtains the raw USB descriptor.</p>
</td>
</tr>
<tr id="row1557362913482"><td class="cellrowborder" valign="top" width="58.589999999999996%" headers="mcps1.2.3.1.1 "><p id="p129141944919"><a name="p129141944919"></a><a name="p129141944919"></a>controlTransfer(pipe: USBDevicePipe, contrlparam: USBControlParams, timeout?: number): Promise&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="41.410000000000004%" headers="mcps1.2.3.1.2 "><p id="p78605286493"><a name="p78605286493"></a><a name="p78605286493"></a>Performs control transfer.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section980mcpsimp"></a>

You can set a USB device as a host to connect to a device for data transfer. The development procedure is as follows:

1.  Obtain the USB device list.

    ```js
    // Import the USB API package.
    import usb from '@ohos.usb';
    // Obtain the USB device list.
    var deviceList = usb.getDevices();
    /*
    Example deviceList structure
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
    ],
    */
    ```

2.  Obtain the device operation permissions.

    ```js
    var deviceName = deviceList[0].name;
    // Request the permissions to operate a specified device.
    usb.requestRight(deviceName).then(hasRight => {
      console.info("usb device request right result: " + hasRight);
    }).catch(error => {
      console.info("usb device request right failed : " + error);
    });
    ```

3.  Open the device.

    ```js
    // Open the device, and obtain the USB device pipe for data transfer.
    var pipe = usb.connectDevice(deviceList[0]);
    /*
    Claim the corresponding interface from deviceList.
    interface1 must be one present in the device configuration.
    */
    usb.claimInterface(pipe , interface1, true);
    ```

4.  Perform data transfer.

    ```js
    /*
    Read data. Select the corresponding RX endpoint from deviceList for data transfer.
    (endpoint.direction == 0x80); dataUint8Array indicates the data to read. The data type is Uint8Array.
    */
    
    usb.bulkTransfer(pipe, inEndpoint, dataUint8Array, 15000).then(dataLength => {
    if (dataLength >= 0) {
      console.info("usb readData result Length : " + dataLength);
      var resultStr = this.ab2str(dataUint8Array); // Convert uint8 data into a string.
      console.info("usb readData buffer : " + resultStr);
    } else {
      console.info("usb readData failed : " + dataLength);
    }
    }).catch(error => {
    console.info("usb readData error : " + JSON.stringify(error));
    });
    // Send data. Select the corresponding TX endpoint from deviceList for data transfer. (endpoint.direction == 0)
    usb.bulkTransfer(pipe, endpoint, dataUint8Array, 15000).then(dataLength => {
      if (dataLength >= 0) {
        console.info("usb writeData result write length : " + dataLength);
      } else {
        console.info("writeData failed");
      }
    }).catch(error => {
      console.info("usb writeData error : " + JSON.stringify(error));
    });
    ```

5.  Release the USB interface, and close the USB device.

    ```js
    usb.releaseInterface(pipe, interface);
    usb.closePipe(pipe);
    ```



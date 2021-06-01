# Function Invocation Logic<a name="EN-US_TOPIC_0000001158241891"></a>

The init function of the input device manager initializes the device management linked list, and the init function of the common driver allocates memory for related structures. The  **RegisterChipDevice**  function passes touchscreen chip driver information to the related structures of the input common driver and initializes hardware information \(for example, interrupt registration\). The  **RegisterInputDevice**  function registers  **inputDev**  \(binding the device and the driver\) with the device manager. The  **RegisterInputDevice**  function adds  **inputDev**  to the device management linked list. The function implementation is as follows:

```
// Code location: ./drivers/framework/model/input/driver/hdf_touch.c
int32_t RegisterChipDevice(ChipDevice *chipDev)
{
    ...
    /* Bind the device to the driver and create an inputDev instance using InputDeviceInstance. */
    DeviceBindDriver(chipDev);
    ...
    /* Implement the interrupt registration and interrupt handling functions. The interrupt handling function contains the channel for reporting data to the user space. */
    ChipDriverInit(chipDev);
    ...
    /* Allocate memory for instantiating inputDev. */
    inputDev = InputDeviceInstance(chipDev);
    ...
    /* Register inputDev with the input device manager. */
    RegisterInputDevice(inputDev);
    ...
}

// Code location: ./drivers/framework/model/input/driver/hdf_input_device_manager.c
int32_t RegisterInputDevice(InputDevice *inputDev)
{
    ...
    /* Allocate a device ID, which is unique for each input device. */
    ret = AllocDeviceID(inputDev);
    ...
    /* This function contains special processing for hid devices but does nothing for the touchscreen driver. */
    CreateDeviceNode(inputDev);
    /* Apply for the buffer for the IOService capability, which is required to transmit kernel-space data to the user space. */
    AllocPackageBuffer(inputDev);
    /* Add the input device to the global device management linked list. */
    AddInputDevice(inputDev);
    ...
}
```


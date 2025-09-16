# Device Rotation Control
<!--Kit: Mechanic Kit-->
<!--Subsystem: Mechanic-->
<!--Owner: @hobbycao-->
<!--Designer: @saga2025-->
<!--Tester: @zhaodengqi-->
<!--Adviser: @foryourself-->

Mechanic Kit is supported since API version 20, providing a richer photography experience, such as device rotation control (only for system apps).

Using a mobile phone as the control terminal, you can adjust the angle and motion trajectory of mechanic devices like gimbals or robotic arms through precise parameter settings, facilitating the rapid development of mechanic device control applications.

## Available APIs

For details about how to use the public APIs of Mechanic Manager, see [@ohos.distributedHardware.mechanicManager (Mechanic Manager)](../reference/apis-mechanic-kit/js-apis-mechanicManager.md).
For details about how to use the system APIs of Mechanic Manager, see [@ohos.distributedHardware.mechanicManager (Mechanic Manager) (System API)](../reference/apis-mechanic-kit/js-apis-mechanicManager-sys.md).

| Name                                                              | Description                      |
| -------------------------------------------------------------------- | -------------------------- |
|on(type: 'attachStateChange', callback: Callback\<AttachStateChangeInfo>): void | Registers the callback listener for **attachStateChange** events.<br>**Note**: This API is supported since API version 20.|
|off(type: 'attachStateChange', callback?: Callback\<AttachStateChangeInfo>): void | Unregisters the callback listener for **attachStateChange** events.<br>**Note**: This API is supported since API version 20.|
|getAttachedMechDevices(): MechInfo[] | Obtain the list of connected mechanic devices.<br>**Note**: This API is supported since API version 20.|
|setUserOperation(operation: Operation, mac: string, params: string): void | Sets a user operation.<br>**Note**: This API is supported since API version 20.|
|setCameraTrackingEnabled(isEnabled: boolean): void | Enables or disables camera tracking.<br>**Note**: This API is supported since API version 20.|
|getCameraTrackingEnabled(): boolean | Checks whether camera tracking is enabled.<br>**Note**: This API is supported since API version 20.|
|getCameraTrackingLayout(): CameraTrackingLayout | Obtains the camera tracking layout of the mechanic device.<br>**Note**: This API is supported since API version 20.|
|rotate(mechId: number, angles: RotationAngles, duration: number): Promise\<Result> | Rotates a mechanic device to the relative angles.<br>**Note**: This API is supported since API version 20.|
|rotateToEulerAngles(mechId: number, angles: EulerAngles, duration: number): Promise\<Result> | Rotates a mechanic device to the absolute angles.<br>**Note**: This API is supported since API version 20.|
|getMaxRotationTime(mechId: number): number | Obtains the maximum duration for continuous rotation of a mechanic device.<br>Note: This API is supported since API version 20.|
|getMaxRotationSpeed(mechId: number): RotationSpeed | Obtains the maximum rotation speed of a mechanic device.<br>**Note**: This API is supported since API version 20.|
|stopMoving(mechId: number): Promise\<void> | Stops movement of a mechanic device.<br>**Note**: This API is supported since API version 20.|
|getCurrentAngles(mechId: number): EulerAngles | Obtains the current angles of a mechanic device.<br>**Note**: This API is supported since API version 20.|
|getRotationLimits(mechId: number): RotationLimits | Obtains the maximum rotation angle of a mechanic device relative to the reference point.<br>**Note**: This API is supported since API version 20.|
|getRotationAxesStatus(mechId: number): RotationAxesStatus | Obtains the status of the rotation axis.<br>**Note**: This API is supported since API version 20.|
|on(type: 'rotationAxesStatusChange', callback: Callback\<RotationAxesStateChangeInfo>): void | Registers a callback listener for the **rotationAxesStatusChange** events.<br>**Note**: This API is supported since API version 20.|
|off(type: 'rotationAxesStatusChange', callback?: Callback\<RotationAxesStateChangeInfo>): void | Unregisters the callback listener for **rotationAxesStatusChange** events.<br>**Note**: This API is supported since API version 20.|

## How to Develop

### Getting Started

1. Prepare a mechanic device that supports Mechanic Kit.
2. To verify the intelligent camera tracking function, check that the camera driver of the main device supports face detection.
3. Update the SDK to API version 20 or later. For details, see https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-software-install.
4. Connect the mechanic device to the control device through Bluetooth.

### Managing the Device Connection Status

Device connection status management helps to ensure that the application responds promptly when the mechanic device is connected or disconnected.

1. Import the **mechanicManager** module.

    ```ts
    import mechanicManager from '@kit.MechanicKit';
    ```

2. Obtain the list of connected mechanic devices.

    ```ts
    let savedMechanicIds: number[] = [];

    try {
    const devices = mechanicManager.getAttachedMechDevices();
    console.log('Connected devices:', devices);

    devices.forEach(device => {
        console.log(`Device ID: ${device.mechId}`);
        console.log(`Device Name: ${device.mechName}`);
        console.log(`Device Type: ${device.mechDeviceType}`);

    // Save the MechId of the device whose device type is GIMBAL_DEVICE.
        if (device.mechDeviceType === mechanicManager.MechDeviceType.GIMBAL_DEVICE) {
        savedMechanicIds.push(device.mechId);
        console.log(`GIMBAL_TYPE device saved ID: ${device.mechId}`);
        } else {
        console.log(`Skip non-gimbal devices: ${device.mechId}`);
        }
    });

    console.log('List of saved gimbal device IDs:', savedMechanicIds);
    } catch (err) {
    console.error('Error getting attached devices:', err);
    }
    ```

3. Listen for the connection state changes of the device.

    ```ts
    const attachStateChangeCallback = (info: mechanicManager.AttachStateChangeInfo) => {
    if (info.state === mechanicManager.AttachState.ATTACHED) {
        console.log('Device attached:', info.mechInfo);
        // Process the device connection logic.
        handleDeviceAttached(info.mechInfo);
    } else if (info.state === mechanicManager.AttachState.DETACHED) {
        console.log('Device detached:', info.mechInfo);
        // Process the device disconnection logic.
        handleDeviceDetached(info.mechInfo);
    }
    };

    // Register a callback listener.
    mechanicManager.on('attachStateChange', attachStateChangeCallback);
    ```

4. Process device connection and disconnection events.

    ```ts
    mechanicManager.on('attachStateChange', attachStateChangeCallback);

    function handleDeviceAttached(mechInfo: mechanicManager.MechInfo) {
    console.log(`New device is connected: ${mechInfo.mechName} (ID: ${mechInfo.mechId})`);
    savedMechanicIds.push(mechInfo.mechId);
    // To do sth.
    }

    function handleDeviceDetached(mechInfo:  mechanicManager.MechInfo) {
    console.log(`Device disconnected: ${mechInfo.mechName} (ID: ${mechInfo.mechId})`);
    savedMechanicIds.filter(id => id !== mechInfo.mechId);
    // To do sth.
    }
    ```

5. Cancel listening for device connection state changes.

    ```ts
    // Cancel listening for device connection state changes.
    mechanicManager.off('attachStateChange', attachStateChangeCallback);
    ```

### Controlling Device Rotation

Precise rotation control, such as angle adjustment and motion trajectory control, helps you to implement flexible operation functions for mechanic devices.

1. Query the current status and restrictions of a device.

    ```ts
    try {
    // Initialize device functions, such as obtaining the device status.
    const devices = mechanicManager.getAttachedMechDevices();
    console.log('Connected devices:', devices);

    devices.forEach(device => {
        console.log(`Device ID: ${device.mechId}`);
        console.log(`Device Name: ${device.mechName}`);
        console.log(`Device Type: ${device.mechDeviceType}`);
    });

    // Register the listener for device connection state changes.
    const attachStateChangeCallback = (info: mechanicManager.AttachStateChangeInfo) => {
        if (info.state === mechanicManager.AttachState.ATTACHED) {
        console.log('Device attached:', info.mechInfo);
        } else if (info.state === mechanicManager.AttachState.DETACHED) {
        console.log('Device detached:', info.mechInfo);
        }
    };
    mechanicManager.on('attachStateChange', attachStateChangeCallback);
    // Obtain the current angle of the device.
    const currentAngles = mechanicManager.getCurrentAngles(savedMechanicIds[0]);
    console.log('current angle:', currentAngles);

    // Obtain the rotation limit of the device.
    const rotationLimits = mechanicManager.getRotationLimits(savedMechanicIds[0]);
    console.log('Rotation limit:', rotationLimits);

    // Obtain the maximum rotation speed of the device.
    const maxSpeed = mechanicManager.getMaxRotationSpeed(savedMechanicIds[0]);
    console.log('Maximum rotation speed:', maxSpeed);

    // Obtain the maximum duration for continuous rotation of the device.
    const maxTime = mechanicManager.getMaxRotationTime(savedMechanicIds[0]);
    console.log('Maximum spin time:', maxTime);
    } catch (err) {
    console.error('Failed to query device status:', err);
    }
    ```

2. Rotate the device by a relative angle.

    ```ts
    // Disable the camera tracking function before rotating the device.
    mechanicManager.setCameraTrackingEnabled(false);

    async function rotateByRelativeAngles() {
    try {
        const mechId = savedMechanicIds[0]; // Device ID.

        // Obtain the current angle of the device.
        const currentAngles = mechanicManager.getCurrentAngles(mechId);
        if (!currentAngles || currentAngles.yaw === undefined || currentAngles.pitch === undefined ||
        currentAngles.roll === undefined) {
        console.error('Failed to retrieve current angles or angles are undefined.');
        return;
        }

        // Obtain the rotation limit of the device.
        const rotationLimits = mechanicManager.getRotationLimits(mechId);
        if (!rotationLimits || rotationLimits.negativeYawMax === undefined || rotationLimits.positiveYawMax === undefined ||
        rotationLimits.negativePitchMax === undefined || rotationLimits.positivePitchMax === undefined ||
        rotationLimits.negativeRollMax === undefined || rotationLimits.positiveRollMax === undefined) {
        console.error('Failed to retrieve rotation limits or limits are undefined.');
        return;
        }
        console.log('Rotation limits:', rotationLimits);

        // Define the target angle.
        const angles: mechanicManager.RotationAngles = {
        yaw: Math.PI / 4, // Yaw angle: 45 degrees
        pitch: Math.PI / 6, // Pitch angle: 30 degrees
        roll: 0            // Roll angle: 0 degrees
        };

        // Check whether the target angle exceeds the limit.
        if (
        currentAngles.yaw + (angles.yaw ?? 0) > rotationLimits.negativeYawMax ||
            currentAngles.yaw + (angles.yaw ?? 0) < rotationLimits.positiveYawMax ||
            currentAngles.pitch + (angles.pitch ?? 0) > rotationLimits.negativePitchMax ||
            currentAngles.pitch + (angles.pitch ?? 0) < rotationLimits.positivePitchMax ||
            currentAngles.roll + (angles.roll ?? 0) > rotationLimits.negativeRollMax ||
            currentAngles.roll + (angles.roll ?? 0) < rotationLimits.positiveRollMax
        ) {
        console.error('Target angles exceed rotation limits.');
        return;
        }

        const duration = 2000; // Rotation duration: 2 seconds

        // Perform rotation.
        const result = await mechanicManager.rotate(mechId, angles, duration);
        console.info(`Rotation Result: ${result}`);
    } catch (err) {
        console.error('Failed to rotate relative angle:', err);
    }
    }
    ```

3. Perform rotation at the specified speed until the task is complete.

    ```ts
    async function rotateBySpeed() {
    try {
        const mechId = savedMechanicIds[0]; // Assume that the first device is used.

        // Obtain the maximum rotation duration.
        const maxTime = mechanicManager.getMaxRotationTime(mechId);
        console.log('Maximum spin time:', maxTime);

        // Obtain the maximum rotation speed.
        const maxSpeed = mechanicManager.getMaxRotationSpeed(mechId);
        if (!maxSpeed || maxSpeed.yawSpeed === undefined || maxSpeed.pitchSpeed === undefined || maxSpeed.rollSpeed === undefined) {
        console.error('Failed to retrieve maximum rotation speed or speed values are undefined.');
        return;
        }
        console.log('Maximum rotation speed:', maxSpeed);
        // Define the rotation speed and duration.
        const speed : mechanicManager.RotationSpeed = {
        yawSpeed: maxSpeed.yawSpeed / 2,    // Yaw speed: half of the maximum speed
        pitchSpeed: maxSpeed.pitchSpeed / 2, // Pitch speed: half of the maximum speed
        rollSpeed: maxSpeed.rollSpeed / 2    // Roll speed: half of the maximum speed
        };
        const duration = Math.min(maxTime, 5000); // Duration: 5 seconds at most

        // Perform rotation.
        const result = await mechanicManager.rotateBySpeed(mechId, speed, duration);
        console.info(`Rotation by speed result: ${result}`);
    } catch (err) {
        console.error('Failed to rotate by speed:', err);
    }
    }
    ```

4. Register a listener for rotation axis state changes.

    ```ts
    const rotationAxesCallback = (info: mechanicManager.RotationAxesStateChangeInfo) => {
    console.log('Rotation Axes state change:', info);
    const mechId = info.mechId;
    const status = info.status;

    console.log(`Device ${mechId} status update:`);
    console.log(`- Yaw  axes enabled: ${status.yawEnabled}`);
    console.log(`- Pitch axes enabled: ${status.pitchEnabled}`);
    console.log(`- Roll axes enabled: ${status.rollEnabled}`);

    if (status.yawLimited !== undefined) {
        console.log(`- Yaw axis restriction state: ${status.yawLimited}`);
    }
    };

    // Register a listener for rotation axis state changes.
    mechanicManager.on('rotationAxesStatusChange', rotationAxesCallback);
    ```

5. Stop the device movement.

    ```ts
    async function stopDeviceMoving() {
    try {
        const mechId = savedMechanicIds[0];
        await mechanicManager.stopMoving(mechId);
        console.log('The device has ceased moving.');
    } catch (err) {
        console.error('Failed to stop device movement:', err);
    }
    }
    ```

### Debugging and Verification

To ensure proper functioning of Mechanic Manager, perform the following steps for debugging and verification:

**Connection Setup**

1. Ensure that the mechanic device is paired with and connected to the development device via Bluetooth.
2. Place the development device on the mechanic device.

**Test Procedure**

1. **Querying the device list**: Call `getAttachedMechDevices` to query the list of connected mechanic devices and check whether all mechanic devices are correctly identified.
2. **Controlling device rotation**: Call `setCameraTrackingEnabled` to disable the camera tracking function and call `getCameraTrackingEnabled` to verify the status. Then, call `rotate` or `rotateBySpeed` to control the rotation of the mechanic device.

**Test Result Description**

- If a list containing all mechanic device is returned after `getAttachedMechDevices` is called, the device identification is normal.
- If the device starts to rotate as expected after `rotate` or `rotateBySpeed` is called, the device rotation is normal.

# Adapting to the Private Drivers of the Touchscreen<a name="EN-US_TOPIC_0000001158361505"></a>

The input driver model consists of three parts of drivers. To develop a brand-new touchscreen driver, you only need to adapt your code with the input chip driver and implement differentiated APIs. The sample code in this section illustrates how you will complete the adaptation.

1.  Implement differentiated APIs for the touchscreen to adapt to the input chip driver.

    You can obtain the sample code at  **./drivers/framework/model/input/driver/touchscreen/touch\_gt911.c**.

    ```
    static struct TouchChipOps g_gt911ChipOps = {                                  // IC options of the touchscreen
        .Init = ChipInit,                                                          // Initialize the chip.
        .Detect = ChipDetect,                                                      // Detect the chip.
        .Resume = ChipResume,                                                      // Resume the chip.
        .Suspend = ChipSuspend,                                                    // Suspend the chip.
        .DataHandle = ChipDataHandle,                                              // Read the chip data.
        .UpdateFirmware = UpdateFirmware,                                          // Update the firmware.
    };
    
    /* The ICs may be different depending on the touchscreen vendors, and the corresponding register operations are also different. Therefore, the code for the input chip driver focuses only on the adaptation of differentiated APIs. The following sample code demonstrates the data parsing of GT911. */
    
    static int32_t ChipDataHandle(ChipDevice *device)
    {
        ...
        /* Read the status register before GT911 obtains coordinates. */
        reg[0] = (GT_BUF_STATE_ADDR >> ONE_BYTE_OFFSET) & ONE_BYTE_MASK; 
        reg[1] = GT_BUF_STATE_ADDR & ONE_BYTE_MASK;
        ret = InputI2cRead(i2cClient, reg, GT_ADDR_LEN, &touchStatus, 1);
        if (ret < 0 || touchStatus == GT_EVENT_INVALID) {
            return HDF_FAILURE;
        }
        ...
        /* Read data from the data register based on the value of the status register. */
        reg[0] = (GT_X_LOW_BYTE_BASE >> ONE_BYTE_OFFSET) & ONE_BYTE_MASK;
        reg[1] = GT_X_LOW_BYTE_BASE & ONE_BYTE_MASK;
        pointNum = touchStatus & GT_FINGER_NUM_MASK;
        if (pointNum == 0 || pointNum > MAX_SUPPORT_POINT) {
            HDF_LOGE("%s: pointNum is invalid, %u", __func__, pointNum);
            (void)ChipCleanBuffer(i2cClient);
            OsalMutexUnlock(&device->driver->mutex);
            return HDF_FAILURE;
        }
        frame->realPointNum = pointNum;
        frame->definedEvent = TOUCH_DOWN;
        (void)InputI2cRead(i2cClient, reg, GT_ADDR_LEN, buf, GT_POINT_SIZE * pointNum);
        /* Parse the obtained data. */
        ParsePointData(device, frame, buf, pointNum);
        ...
    }
    static void ParsePointData(ChipDevice *device, FrameData *frame, uint8_t *buf, uint8_t pointNum)
    {
        ...
        /* Each coordinate value consists of two bytes. Obtain the final coordinate value by combining the obtained single-byte data. */
        for (i = 0; i < pointNum; i++) {
                frame->fingers[i].trackId = buf[GT_POINT_SIZE * i + GT_TRACK_ID];
                frame->fingers[i].y = (buf[GT_POINT_SIZE * i + GT_X_LOW] & ONE_BYTE_MASK) |
                                      ((buf[GT_POINT_SIZE * i + GT_X_HIGH] & ONE_BYTE_MASK) << ONE_BYTE_OFFSET);
                frame->fingers[i].x = (buf[GT_POINT_SIZE * i + GT_Y_LOW] & ONE_BYTE_MASK) |
                                      ((buf[GT_POINT_SIZE * i + GT_Y_HIGH] & ONE_BYTE_MASK) << ONE_BYTE_OFFSET);
                /* Print the parsed coordinate value. */
                HDF_LOGD("%s: x = %d, y = %d", __func__, frame->fingers[i].x, frame->fingers[i].y);
         }
    }
    ```

2.  Initialize the input chip driver and register the driver with the HDF.

    You can obtain the sample code at  **./drivers/framework/model/input/driver/touchscreen/touch\_gt911.c**.

    ```
    static int32_t HdfGoodixChipInit(struct HdfDeviceObject *device)
    {
        ...
        /* Use the chipCfg structure to allocate memory, parse the configuration information, and mount the parsed data. */
        chipCfg = ChipConfigInstance(device);
        ...
        /* Instantiate the touchscreen device. */
        chipDev = ChipDeviceInstance();
        ...
        /* Mount touchscreen chip configuration and private operation data. */
        chipDev->chipCfg = chipCfg;
        chipDev->ops = &g_gt911ChipOps;
        ...
        /* Register the chip driver with the platform driver. */
        RegisterChipDevice(chipDev);
        ...
    }
    struct HdfDriverEntry g_touchGoodixChipEntry = {
        .moduleVersion = 1,
         .moduleName = "HDF_TOUCH_GT911",   // The value must match the moduleName field of the chip driver in the device_info.hcs file.
        .Init = HdfGoodixChipInit,         // Initialize the touchscreen chip driver.
    };
    HDF_INIT(g_touchGoodixChipEntry);      // Register the touchscreen chip driver with the HDF.
    ```

    The private chip drivers present the major differentiations among chip vendors, such as hibernation and wakeup, data parsing, and firmware update.

    Now, you have completed the adaptation for the touchscreen driver based on the HDF and input driver model.



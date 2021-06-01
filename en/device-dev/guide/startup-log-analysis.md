# Startup Log Analysis<a name="EN-US_TOPIC_0000001158241947"></a>

The following is part of the startup log:

```
[I/HDF_INPUT_DRV] HdfInputManagerInit: enter                            // Initialize the input device manager.
[I/HDF_INPUT_DRV] HdfInputManagerInit: exit succ                        // The initialization is successful.
[I/osal_cdev] add cdev hdf_input_host success                                                                                                                   
[I/HDF_LOG_TAG] HdfTouchDriverProbe: enter                              // Initialize the input common driver.
[I/HDF_LOG_TAG] HdfTouchDriverProbe: main_touch exit succ               // The initialization is successful.
[I/osal_cdev] add cdev hdf_input_event1 success                                                                                                                 
[I/HDF_INPUT_DRV] HdfGoodixChipInit: enter                              // Initialize the input chip driver.
[I/HDF_INPUT_DRV] ChipDetect: IC FW version is 0x1060                           
[I/HDF_INPUT_DRV] Product_ID: 911_1060, x_sol = 960, y_sol = 480                
[I/HDF_LOG_TAG] ChipDriverInit: chipDetect succ, ret = 0                                                        
[I/HDF_LOG_TAG] InputDeviceInstance: inputDev->devName = main_touch                      
[I/HDF_INPUT_DRV] HdfGoodixChipInit: exit succ, chipName = gt911        // The initialization is successful.
```


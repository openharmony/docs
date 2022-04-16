# Debugging and Verification


When the burning and networking are complete, you can use either of the following methods to debug and verify whether the source code has been burnt correctly:


1. Using printf to print logs

2. Using ASM files to locate panic issues


As the example used here is simple, we use the printf method. The following describes the two methods in detail.


## printf

Add the printf function to the code, which helps print data to the serial port. You can add log printing in key service paths or service exception locations, as shown in the following figure.

  
```
void HelloWorld(void)
{
    printf("[DEMO] Hello world.\n");
}
```


## Using ASM Files to Locate Issues

  When the system exits abnormally, the call stack information about the abnormal exit is displayed on the serial port. Analyze the displayed information to troubleshoot and pinpoint issues.
  
```
=======KERNEL PANIC=======
**Call Stack*
Call Stack 0 -- 4860d8 addr:f784c
Call Stack 1 -- 47b2b2 addr:f788c
Call Stack 2 -- 3e562c addr:f789c
Call Stack 3 -- 4101de addr:f78ac
Call Stack 4 -- 3e5f32 addr:f78cc
Call Stack 5 -- 3f78c0 addr:f78ec
Call Stack 6 -- 3f5e24 addr:f78fc
Call Stack end***
```

To analyze the call stack information, the **Hi3861_wifiiot_app.asm** file is required. This file records the symbol addresses of the functions in the code in the flash memory and the disassembly information. The ASM file is built and output together with the version software package and is stored in the **./out/wifiiot/** directory.

1. Save the CallStack information to a .txt file for editing. (Optional)

2. Open the asm file, search for the addresses in CallStack, and list the corresponding function names. Generally, you only need to find the functions matching the first several stacks to locate issues.
     
   ```
   Call Stack 0 -- 4860d8 addr:f784c -- WadRecvCB
   Call Stack 1 -- 47b2b2 addr:f788c -- wal_sdp_process_rx_data
   Call Stack 2 -- 3e562c addr:f789c
   Call Stack 3 -- 4101de addr:f78ac
   Call Stack 4 -- 3e5f32 addr:f78cc
   Call Stack 5 -- 3f78c0 addr:f78ec
   Call Stack 6 -- 3f5e24 addr:f78fc
   ```

3. Based on the call stack information, we can conclude that an exception occurs in the **WadRecvCB** function.

   ![en-us_image_0000001226634668](figures/en-us_image_0000001226634668.png)

4. Check and modify the code.

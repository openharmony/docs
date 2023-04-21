# format


## Command Function

This command is used for disk formatting.


## Syntax

format &lt;*dev*inodename_&gt; &lt;*sectors*&gt; &lt;*option*&gt; [_label_]


## Parameters

**Table 1** Parameter description

| Parameter| Description|
| -------- | -------- |
| dev_inodename | Specifies the device name. |
| sectors | Specifies the size of the allocated memory unit or sector. <br/>The value must be **0** or a power of **2**.<br/>The value **0** means to leave this parameter blank. <br/>For FAT32, the maximum value is **128**. If the parameter is set to **0**, a proper cluster size is automatically selected. The available cluster size range varies depending on the partition size. If the cluster size is incorrectly specified, the formatting may fail. |
| option | Specifies the file system type. The options are as follows:<br>- **0x01**: FMT_FAT<br>- **0x02**: FMT_FAT32<br>- **0x07**: FMT_ANY<br>- **0x08**: FMT_ERASE (USB does not support this option.)<br>If an invalid value is specified, the system automatically selects the formatting mode. If the low-level formatting bit is **1** during the formatting of a USB flash drive, an error message is printed.|
| label | Specifies the volume label name. This parameter is optional, and the value is a string. <br/>If **null** is specified for this parameter, the previously set volume label name is cleared. |


## Usage Guidelines

- The **format** command is used for disk formatting. You can find the device name in the **dev** directory. A storage card must be installed before the formatting.

- The **format** command can be used to format the USB flash drive, SD card, and MMC, but not the NAND flash or NOR flash.

- An invalid **sectors** value may cause exceptions.


## Example

Run **format /dev/mmcblk0 128 2**.


## Output

Format an MMC.

```
OHOS # format /dev/mmcblk1 128 2
Format to FAT32, 128 sectors per cluster.
format /dev/mmcblk1 Success 
```

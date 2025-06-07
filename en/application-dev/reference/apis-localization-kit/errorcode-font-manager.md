# Font Management Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 31100101 Font File Not Exist

**Error Message**

Font does not exist.

**Symptom**

This error code is reported input font file path does not exist.

**Possible Causes**

The font file path is incorrect.
 
**Solution**

Ensure that the input file is in **.ttf** or **.ttc** format and the path is correct.

## 31100102 Failed to Install Font File

**Error Message**

Font is not supported.

**Symptom**

This error code is reported if the input file is not a font file, leading to an installation failure.

**Possible Causes**

1. The input file is not in **.ttf** or **.ttc** format.
2. The file content does not comply with the font file specifications.
 
**Solution**

Ensure that the input file is in **.ttf** or **.ttc** format.

## 31100103 Failed to Copy Font File

**Error Message**

Font file copy failed.

**Symptom**

This error code is reported if copying the font file fails during installation.

**Possible Causes**

An exception occurs during font file copying.
 
**Solution**

Try again, or restart the device and try again.

## 31100104 Font File Already Installed

**Error Message**

Font file installed.

**Symptom**

This error code is reported if the input font file has been installed.

**Possible Causes**

The input font file has been installed, and the font name is duplicate.
 
**Solution**

Uninstall the existing font with the same name and reinstall the font file.

## 31100105 Number of Installed Font Files Reaching the Maximum

**Error Message**

Exceeded maximum number of installed files.

**Symptom**

This error code is reported if the number of installed font files reaches the maximum.

**Possible Causes**

The number of installed font files reaches the maximum (200).
 
**Solution**

Uninstall unnecessary font files and try again.

## 31100106 Font File Installation Failed Due to Other Errors

**Error Message**

Other error.

**Symptom**

This error code is reported if the font file installation fails because of a system error. 

**Possible Causes**

An exception occurs during font installation.
 
**Solution**

Try again, or restart the device and try again.

## 31100107 Uninstalled Font File Not Exist

**Error Message**

Font file does not exist.

**Symptom**

This error code is reported if the font file to be uninstalled does not exist.

**Possible Causes**

The font file to be uninstalled has not been installed, or the input font file name is incorrect.
 
**Solution**

Check whether the input font name is correct. If not, correct it and try again.

## 31100108 Failed to Delete Font File

**Error Message**

Font file delete error.

**Symptom**

This error code is reported if deleting the font file fails during uninstallation.

**Possible Causes**

An exception occurs during uninstallation.
 
**Solution**

Try again, or restart the device and try again.

## 31100109 Uninstallation Failed Due to Other Errors

**Error Message**

Other error.

**Symptom**

This error code is reported if the font file uninstallation fails because of a system error. 

**Possible Causes**

An exception occurs during uninstallation.
 
**Solution**

Try again, or restart the device and try again.

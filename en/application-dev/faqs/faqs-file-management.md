# File Management Development

## How do I obtain the path of system screenshots?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Solution**

The screenshots are stored in **/storage/media/100/local/files/Pictures/Screenshots/**.

## How do I change the permissions on a directory to read/write on a device?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Symptom**

When the hdc command is used to send a file to a device, "permission denied" is displayed.

**Solution**

Run the **hdc shell mount -o remount,rw /** command to grant the read/write permissions.

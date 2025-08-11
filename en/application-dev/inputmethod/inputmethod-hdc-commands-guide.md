# IME Tool
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--SE: @andeszhang-->
<!--TSE: @murphy1984-->

**How to Use**<br>

hdc shell ime [option] [parameter]

**Commands**
| Option| Parameter      | Description                                                        |
| ---- | ---------- | ------------------------------------------------------------ |
| -e | bundle [-b /-f] | Enables an input method as a specified mode. If **-b** or **-f** is not set, **-b** defaults to the basic mode, and **-f** defaults to the full mode.<br>**NOTE**<br>The enabling status of the preset default input method cannot be changed.|
| -d | bundle | Disables a specified input method.<br>**NOTE**<br>The preset default input method cannot be disabled.|
| -s   | bundle     | Switches to a specified input method.<br>**NOTE**<br>You are not allowed to switch to another input method when the screen is locked or the password is being entered.|
| -g   | NA         | Obtains the current input method.|
| -l   | NA         | Lists all input methods.|
| -h   | NA         | Displays the help information.|

## Managing Input Methods Using IME Tool

1. Enabling an input method. You can enable a third-party input method as basic mode or full mode.

   ```shell
    # Input: Use an hdc command to enable an input method.
    # Processing: Check if it is an hdc shell command, and call the corresponding API for enabling.
    # Output: The effect is equivalent to a direct API call.
    # Basic mode
    hdc shell ime -e com.xxx.yyy 
    # Full mode
    hdc shell ime -e com.xxx.yyy -f
   ```

2. Disabling an input method. You can disable a third-party input method.

   ```shell
    # Input: Use an hdc command to disable an input method.
    # Processing: Check if it is an hdc shell command, and call the corresponding API for disabling.
    # Output: The effect is equivalent to a direct API call.
    hdc shell ime -d com.xxx.yyy
   ```

3. Switching to a specified input method.

   ```shell
    # Input: Use an hdc command to switch the input method.
    # Processing: Check if it is an hdc shell command, and call the corresponding API for switching.
    # Output: The effect is equivalent to a direct API call.
    hdc shell ime -s com.xxx.yyy
   ```

4. Obtaining the current input method.

   ```shell
    # Input: Use an hdc command to obtain the current input method.
    # Processing: Check if it is an hdc shell command, and call the corresponding API for obtaining.
    # Output: The effect is equivalent to a direct API call.
    hdc shell ime -g
   ```

5. Listing all input methods. The enabling status of the preset default input method is not displayed.

   ```shell
    # Input: Use an hdc command to list all input methods.
    # Processing: Check if it is an hdc shell command, and call the corresponding API for listing.
    # Output: The effect is equivalent to a direct API call.
    hdc shell ime -l
   ```

6. Displaying the help information.

   ```shell
    # Input: Use an hdc command to display the help information.
    # Output: Display the help information.
    hdc shell ime -h
   ```

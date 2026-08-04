# Managing the Input Method Using hdc Commands

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3103aea9f27e22b8029f7224f57c27c4f91680cc translatedAt=2026-08-04T08:29:24.894Z pushedAt=2026-08-04T08:54:14.648Z -->

> **NOTE**
>
> The IME tool is supported since API version 20.

**How to Use**<br>

hdc shell ime [option] [parameter]

**Commands**

| Option| Parameter      | Description                                                        |
| ---- | ---------- | ------------------------------------------------------------ |
| -u | userId | Specifies the user ID for the operation (the default value is the foreground user ID of the home screen). Can be used with other options for input method management in multi-user environments. |
| -e | bundle [-b /-f] | Enables a specified input method to a specified mode. When the -b/-f option is not set, -b is the default basic mode, and -f is the full access mode.<br/>**Note:** The system preset default input method does not support changing its enabled state through this command. |
| -d | bundle | Disables a specified input method.<br>**Note**: The preset default input method cannot be disabled.|
| -s   | bundle     | Switches to a specified input method.<br>**Note**: You are not allowed to switch to another input method when the screen is locked or the password is being entered.|
| -g   | NA         | Obtains the current input method.|
| -l   | NA         | Lists all input methods.|
| -h   | NA         | Displays the help information.|

## Managing Input Methods Using IME Tool

1. Enabling an input method. You can enable a third-party input method as basic mode or full experience mode.

   ```shell
    # Input: Use an hdc command to enable an input method.
    # Processing: Check if it is an hdc shell command, and call the corresponding system API for managing input methods.
    # Output: The effect is equivalent to a direct API call.
    # Basic mode
    hdc shell ime -e com.xxx.yyy 
    # Full experience mode
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

## Managing Input Methods in a Multi-User Environment

Starting from API version 26.0.0, in a multi-user environment, you can use the -u option to specify the target user ID and manage input methods for different users.

### Multi-User Command Examples

1. Obtain the current input method of a specified user.

   ```shell
    # Input: Obtain the current input method of user 100.
    # Processing: The system queries the current input method of user 100.
    # Output: Display the current input method information of user 100.
    hdc shell ime -u 100 -g
   ```

2. Switch the input method for a specified user.

   ```shell
    # Input: Switch user 100 to the specified input method.
    # Processing: The system switches user 100 to the specified input method.
    # Output: Display the switch result.
    hdc shell ime -u 100 -s com.example.ime
   ```

3. Enable an input method for a specified user.

   ```shell
    # Input: Enable the specified input method for user 100 in basic mode.
    # Processing: The system enables the specified input method for user 100.
    # Output: Display the enable result.
    hdc shell ime -u 100 -e com.example.ime

    # Enable in full experience mode.
    hdc shell ime -u 100 -e com.example.ime -f
   ```

4. Disable an input method for a specified user.

   ```shell
    # Input: Disable the specified input method for user 100.
    # Processing: The system disables the specified input method for user 100.
    # Output: Display the disable result.
    hdc shell ime -u 100 -d com.example.ime
   ```

5. List all input methods of a specified user.

   ```shell
    # Input: List all input methods of user 100.
    # Processing: The system queries all input methods of user 100.
    # Output: Display the list of all input methods of user 100.
    hdc shell ime -u 100 -l
   ```

> **NOTE**
>
> - The -u option is optional. If not specified, the operation applies to the current user by default.
> - The user ID must be a non-negative integer.
> - Only apps of user 0 can perform cross-user operations.
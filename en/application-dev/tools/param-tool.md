# param

The param tool enables you to operate system parameters. It is valid only for standard-system devices.

## Prerequisites

* You have obtained the <!--Del-->[<!--DelEnd-->hdc tool<!--Del-->](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd--> to run hdc shell commands.
* The device is properly connected.

## Command Description

  | Command| Description|
  | ----------------- | ------------------------------------------ |
  | ls [-r] [name] | Displays the information about the system parameter that matches the given name. If **-r** is carried, the information is obtained based on the parameter permission. If **-r** is not carried, the information is directly obtained.|
  | get [name] | Obtains the value of the system parameter with the given name. If no name is specified, the values of all system parameters are returned.|
  | set name value | Sets the value for the system parameter with the given name.|
  | wait name [value] [timeout] | Waits for the system parameter with the given name to match the specified value. Fuzzy match is supported. For example, ***** indicates any value, and **val*** indicates matching of only the first three val characters. **timeout** indicates the waiting time, in seconds. If it is not set, the default value 30s is used.|
  | save | Persistently saves the parameters to the workspace.|

## Example

* To display information about the system parameter that matches a given name, run the following command:

  ```bash
  param ls [-r] [name]
  ```
  **Usage Example**
  ![ls-integrity](figures/param-ls-integrity.png)
  ![ls-part](figures/param-ls-part.png)
  ![ls](figures/param-ls.png)

* To obtain the value of the system parameter with the given name, run the following command:

  ```bash
  param get [name]
  ```
  **Usage Example**
  ![get](figures/param-get.png)

* To set the value for the system parameter with the given name, run the following command:

  ```bash
  param set name value
  ```
  **Usage Example**
  ![set](figures/param-set.png)

* To wait for the system parameter with the given name to match the specified value, run the following command:

  ```bash
  param wait name [value] [timeout]
  ```
  **Usage Example**
  ![wait](figures/param-wait.png)

* To persistently save the parameters to the workspace, run the following command:

  ```bash
  param save
  ```
  **Usage Example**
  ![save](figures/param-save.png)

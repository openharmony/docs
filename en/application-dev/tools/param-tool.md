# param

The param tool enables you to operate system parameters. It is valid only for standard-system devices.

## Environment Setup

* You have obtained the <!--Del-->[<!--DelEnd-->hdc tool<!--Del-->](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd--> to run hdc shell commands.
* The device is properly connected.

## Commands

  | Command| Description|
  | ----------------- | ------------------------------------------ |
  | -h | Obtains the commands supported by param.|
  | ls [-r] [name] | Displays the information about the system parameter that matches the given name. If **-r** is carried, the information is obtained based on the parameter permission. If **-r** is not carried, the information is directly obtained.|
  | get [name] | Obtains the value of the system parameter with the given name. If no name is specified, the values of all system parameters are returned.|
  | set name value | Sets the value for the system parameter with the given name.|
  | wait name [value] [timeout] | Waits for the system parameter with the given name to match the specified value. Fuzzy match is supported. For example, * indicates any value, and **val*** indicates matching of only the first three val characters. **timeout** indicates the waiting time, in seconds. If it is not set, the default value 30s is used.|
  | save | Persistently saves the parameters to the workspace.|

## -h

* Obtains the commands supported by the param tool.

  ```bash
  param -h
  ```

## ls

* Displays the information about the system parameter that matches the given name.

  ```bash
  param ls [-r] [name]
  ```
  **Example**<br>
  ![ls-integrity](figures/param-ls-integrity.png)
  ![ls-part](figures/param-ls-part.png)
  ![ls](figures/param-ls.png)

## get

* Obtains the value of the system parameter with the given name.

  ```bash
  param get [name]
  ```
  **Example**<br>
  ![get](figures/param-get.png)

## set name value

* Sets the value for the system parameter with the given name.

  ```bash
  param set name value
  ```
  **Example**<br>
  ![set](figures/param-set.png)

## wait name

* Waits for the system parameter with the given name to match the specified value.

  ```bash
  param wait name [value] [timeout]
  ```
  **Example**<br>
  ![wait](figures/param-wait.png)

## save

* Persistently saves the parameters to the workspace.

  ```bash
  param save
  ```
  **Example**<br>
  ![save](figures/param-save.png)

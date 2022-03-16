# Ability Assistant Usage

The ability assistant enables you to start applications, atomic services, and test cases and debug applications. By using this tool, you can send commands in the hdc shell to perform various system operations, such as starting abilities, forcibly stopping processes, and printing ability information.

## Development Guidelines

The ability assistant is pre-installed in the device environment. You can directly invoke the tool using commands.

### Query-related Commands

- **help**

  Displays the help information about the ability assistant.

  **Return value**

  Returns the help information.

  **Method**

  ```
  aa help
  ```

### Ability-related Commands

- **start**

  Starts an ability.

  | Name| Description|
  | --------- | ---------------------- |
  | -h/--help | Help information.|
  | -d        | Device ID. This parameter is optional.|
  | -a        | Ability name. This parameter is mandatory.|
  | -b        | Bundle name. This parameter is mandatory.|
  | -D        | Debugging mode. This parameter is optional.|

  **Return value**

  Returns "start ability successfully." if the ability is started; returns "error: failed to start ability." otherwise.

  **Method**

  ```
aa start [-d <device-id>] -a <ability-name> -b <bundle-name> [-D]
  ```
  
- **stop-service**

  Stops a Service ability.

  | Name| Description|
  | --------- | ------------------------ |
  | -h/--help | Help information.|
  | -d        | Device ID. This parameter is optional.|
  | -a        | Ability name. This parameter is mandatory.|
  | -b        | Bundle name. This parameter is mandatory.|

  **Return value**

  Returns "stop service ability successfully." if the Service ability is stopped; returns "error: failed to stop service ability." otherwise.

  **Method**

  ```
aa stop-service [-d <device-id>] -a <ability-name> -b <bundle-name>
  ```
  
- **dump**

  Prints ability related information.

  | Name| Description|
  | ---------------------- | -------------------------------------- |
  | -h/--help              | Help information.|
  | -a/--all               | Ability information in all missions.|
  | -s/--stack \<number>   | Ability information in a specified mission stack.|
  | -m/--mission \<number> | Ability information in a specified mission.|
  | -l/--stack-list        | Mission list in each mission stack.|
  | -u/--ui                | System UI ability information.|
  | -e/--serv              | Service ability information.|
  | -d/--data              | Data ability information.|

  **Method**

  ```
  aa dump -a
  ```

- **force-stop**

  Forcibly stops a process based on the bundle name.

  **Return value**

  Returns "force stop process successfully." if the process is forcibly stopped; returns "error: failed to force stop process." otherwise.

  **Method**

  ```
  aa force-stop <bundle-name>
  ```

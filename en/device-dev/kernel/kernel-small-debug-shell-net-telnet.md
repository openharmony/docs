# telnet


## Command Function

This command is used to enable or disable the Telnet server service.


## Syntax

telnet [_on | off_]


## Parameters

**Table 1** Parameter description

| Parameter| Description| Value Range| 
| -------- | -------- | -------- |
| on | Enables the telnet server service.| N/A | 
| off | Disables the telnet server service.| N/A | 


## Usage Guidelines

- Before enabling Telnet, ensure that the network driver and network protocol stack have been initialized and the NIC of the board is in the **link up** state.

- Currently, multiple clients (Telnet + IP) cannot connect to the development board at the same time.
  > **NOTICE**<br>
  > Telnet is used for debugging and is disabled by default. Do not use it in formal products.


## Example

Run **telnet on**.


## Output

Command output:


```
OHOS # telnet on
OHOS # start telnet server successfully, waiting for connection.
```

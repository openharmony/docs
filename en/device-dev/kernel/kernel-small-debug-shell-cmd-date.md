# date


## Command Function

This command is used to query the system date and time.


## Syntax

- date

- date --help

- date +[_Format_]

- date -u


## Parameters

**Table 1** Parameter description

| Parameter   | Description                      | Value Range              |
| ------- | ------------------------------ | ---------------------- |
| --help  | Displays help information.                    | N/A                    |
| +Format | Prints the date and time in the specified format.| Placeholders listed in **--help**|
| -u      | Displays UTC (not the current time zone).       | N/A                    |


## Usage Guidelines

- If no parameter is specified, the system date and time in UTC format are displayed by default.

- The **--help**, **+Format**, and **-u** parameters are mutually exclusive.

- Currently, this command cannot be used to set the time or date.

## Note

The shell does not support **date -u**. mksh supports it. To switch to mksh, run **cd bin** and **./mksh**.

## Example

Run **date +%Y--%m--%d**.


## Output

System date in the specified format:


```
OHOS:/$ date +%Y--%m--%d
1970--01--01
```

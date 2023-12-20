# Progress Bar


A progress bar displays the speed, time, completion rate, and remaining volume of a task.


![progressbar_sub_1](figures/progressbar_sub_1.png)


## How to Use

- Use a progress bar when your users need to wait, for example, for content loading or file transfer through Bluetooth. The loading process or operation progress is displayed so that they can know the task status.

- Generally, use a rectangular bar as the progress bar.

- Design progress bars based on the use scenario. Try to integrate progress bars into the UI content or operation elements to minimize the use of progress bar dialogs, making users feel less complicated.

- In the dialog, if the waiting time is too long, provide a **Hide** button to hide the progress bar and wait the operation to be completed at the background. Display the hidden progress bar in the notification bar.


## Writing Instructions

- If the task object and progress are clearly displayed, no text is required. If necessary, the text must be in the following format: operation description + *XX* %

- If the progress is not clear, use the text *Being xx...*


## Resources

For details about the development guide related to the progress bar, see [Progress](../../application-dev/reference/arkui-ts/ts-basic-components-progress.md).

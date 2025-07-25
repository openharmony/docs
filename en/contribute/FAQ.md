# FAQ<a name="ZH-CN_TOPIC_0000001053622377"></a>


## Handling Simultaneous Builds for Multiple Repositories with Compilation Dependencies<a name="section169732563435"></a>

During OS development, it is typical to face situations where changes in multiple repositories are interdependent for compilation, requiring concurrent builds and integrations. To manage this, the Gitee platform employs Issues as a linking identifier for PRs from multiple repositories with such dependencies. Here is how you can do it:

1. Create an issue in any code repository involved in your submission.

2. Associate PRs that need to be built and merged at the same time with the issue. For details, visit [https://gitee.com/help/articles/4142](https://gitee.com/help/articles/4142).

3. Once the build is initiated (for detailed steps on triggering builds, refer to the relevant help documentation), the build center will recognize PRs linked to the same Issue. It will then download and build these PRs simultaneously and merge them into the repository after the code review is successfully passed.

## Signed-off-by Operations<a name="section-signed-off"></a>

### Adding a signoff Record to a Commit

To include a signoff in your commit, use the command `git commit -s` or `git commit –signoff`.

### Appending a signoff Record to the Most Recent Commit

Simply run the command `git commit --amend --signoff`.

For a comprehensive list of commit options, see [https://](https://git-scm.com/docs/git-commit)[git-scm.com/docs/git-commit](https://git-scm.com/docs/git-commit).

## DCO Verification Exception Handling<a name="section-dco"></a>

When you submit a PR and comments **start build**, the system triggers a gate check to verify:

1. Whether the PR submission includes a Developer Certificate of Origin (DCO) signature.
2. Whether the PR submission contains Signed-off-by information.

If the verification fails, here are some possible reasons and solutions:

1. You have not signed the Developer Certificate of Origin (DCO). Example:

   ```
   The following commits have users who have not signed the DCO agreement:
   
   •345612
   
   •213123
   ```

   **Solution**

   Click [here](https://dco.openharmony.cn/sign) to sign the DCO and check the signing status.

   Enter **check dco** in the comment box of this PR and click **Comment**. The system will check DCO status again.

2. The commit does not contain Signed-off-by. Example:

   ```
   The following commits do not contain the Signed-off-by information:
   
   •123123
   
   •345612
   ```

   **Solution**

   Follow the Signed-off-by instructions to add the information. The format is: Signed-off-by: user.name <user.email>

   Enter **check dco** in the comment box of this PR and click **Comment**. The system will check DCO status again.


3. The email address used for the PR submission on the web/WebIDE does not match the email address used to sign the DCO agreement.

   
   **Solution**

   On the **Settings > Email management** page of Gitee, check whether the email address is correctly configured. Ensure that the commit email address is the same as the email address used for signing the DCO.

   > **NOTE**
   > 
   > If **Keep my email address private** is selected in **Email management**, an *xxxx@user.noreply.gitee.com* email will be used as the PR submission email by default. To use a different email for submissions, uncheck **Keep my email address private**.



## Rolling Back Commits<a name="section479422315253"></a>

For guidance on rolling back commits, see [https://gitee.com/help/articles/4195](https://gitee.com/help/articles/4195).

## Resolving conflicts<a name="section94417232274"></a>

For instructions on resolving conflicts, see [https://gitee.com/help/articles/4194](https://gitee.com/help/articles/4194).

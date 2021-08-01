// When exec() system call is invoked, the program specified in the parameter to exec() will
// "replace the entire process" - including all threads.
// When exec() is called to execute another process, it overrides the current process with
// newly executed program (say ping in our case), we are no longer in our process
// we can't expect, after executing another program with exec, to continue from our main program
// unless there is a problem in next process

// execlp() -> l stands for list, p stands for parameter
// execvp():
            // char* arr[] = {
            //     "ping",
            //     "google.com",
            //     NULL
            // }
            // execvp("ping", arr);

// execvpe()
// execlpe()
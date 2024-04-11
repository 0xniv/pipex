# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

int main(void)
{
// just preparing things like you need to do after start the program and parsing argv(s)
// left and right command of a pipe like "cat Makefile | grep CC"
// remember that full command of pipex emulate this > '< Makefile cat | "grep CC" > outfile'
    char    *l_cmd[] = { "/bin/cat", NULL };
    char    *r_cmd[] = { "/bin/grep", "CC", NULL };
// remember to create a infile with some content (or not) or just use a file that exists.
    char    *inf = "infile";
    char    *out = "outfile";
    int        fd[2];
    pid_t    pid[2];

// note that only opening first pipe is the main process
// I choose this approach because are easier to handle errors inside of a fork (imo)
// open pipe (in case of bonus, open the first pipe
    if (pipe(fd) == -1)
        return (EXIT_FAILURE);
    // open the fork
    pid[0] = fork();
    if (pid[0] == -1)
        return (EXIT_FAILURE);
// handle the left side (or the first fork, in case o bonus)
// bonus: you can manipulate the left side, then middle until last
    if (pid[0] == 0)
    {
        int infile = open(inf, O_RDONLY);
        if (infile < 0)
            exit (EXIT_FAILURE);
        dup2(infile, STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execve (l_cmd[0], l_cmd, __environ);
    }
// mandatory are the right side of fork
// in bonus is the middle and last pipe
    pid[1] = fork();
    if (pid[1] == -1)
        return (EXIT_FAILURE);
    if (pid[1] == 0)
    {
        int outfile = open(out, O_TRUNC | O_CREAT | O_RDWR, 0666);
        if (outfile < 0)
            exit (EXIT_FAILURE);
        dup2(outfile, STDOUT_FILENO);
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        close(fd[0]);
        execve (r_cmd[0], r_cmd, __environ);
    }
 // here is a important thing... note that is happens in main process not in a child process
 // and you need to close the pipe opened in the main process first than wait for childs
 // if you do the opposite it will not work... you can debug this boilerplate to understand better.
    close(fd[0]);
    close(fd[1]);
    waitpid(pid[0], NULL, 0);
    waitpid(pid[1], NULL, 0);

    return EXIT_SUCCESS;
}

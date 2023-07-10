# OS-Infinite-Running-Linux-Shell
This is an individual project which consists of an infinite running shell similar to linux shell. It supports 8 commands in total (cd, mkdir, rm, echo, date, nano, pwd and cat)
				
### Commands handled:
1) echo:
- "echo [args...]" - prints whatever is passed as an argument as it is and ends with a new line character.
- "echo -n [args...]" - prints whatever is passed as an argument as it is and doesn't end with a new line character.
- "echo --help" - prints the echo help page.

2) pwd: 
- "pwd" - prints the path of the current working directory.
- "pwd -P" - uses pwd from environment, even if it contains symlinks.
- "pwd -L" - avoids all kinds of symlinks.

3) cd:
- "cd [directory name]" - changes the current working directory and goes into the directory passed as an argument.
- "cd" - changes the current working directory to the home directory.
- "cd ~" - changes the current working directory to the home directory.
- "cd .." - goes back to the previous directory.

4) cat:
- "cat [files...]" - reads and prints the contents of each of the files passed as an argument.
- "cat -n [files...]" - reads and prints the contents of each of the files passed as an argument. This command also numbers each and every line (starting from 1).
- "cat -e [files...]" - reads and prints the contents of each of the files passed as an argument. It prints "$" sign just before every new line("\n").

5) ls:
- "ls" - reads and prints the files and folders present inside the current directory separated by \t(tab space). It avoids files whose names start with ".".
- "ls [directory name]" - reads and prints the files and folders present inside the directory passed as an argument separated by "\t"(tab space). It avoids files whose names start with ".".
- "ls -1" - reads and prints the files and folders present inside the current directory separated by "\n"(new line character). It avoids files whose names start with ".".
- "ls -1 [directory name]" - reads and prints the files and folders present inside the directory passed as an argument separated by "\n"(new line character). It avoids files whose names start with ".".
- "ls -a" - reads and prints the files and folders present inside the current directory separated by \t(tab space). It doesn't avoid files whose names start with ".".
- "ls -a [directory name]" - reads and prints the files and folders present inside the directory passed as an argument separated by "\t"(tab space). It doesn't avoid files whose names start with ".".

6) rm:
- "rm [files ...]" - removes the files passed as arguments.
- "rm -v [files...]" - removes the files passed as arguments and prints a message corresponding to each file being removed
- "rm -d [directories...]" - removes the empty directories passed as arguments.
 
7) mkdir:
- "mkdir [directories...]" - creates the new directories with the names passed as arguments.
- "mkdir -v [directories...]" - creates the new directories with the names passed as arguments and displays a message corresponding to each directory being created.

8) date:
- "date" - prints the current date and time in Indian Standard Time(IST).
- date -u" - prints the coordinated universal time(UTC).

9) exit:
to exit from the infinite running shell, "exit" command should be used.

### NOTE - All these commands without "&t" at the end of the command are executed using the fork(), execv() and wait() system calls.
If "&t" is appended at the end of the command, the commands are executed using the pthread_create, pthread_join and system() system calls.

### Errors Handled:
1) if an invalid command name is entered, then the program prints an error message.
2) if an invalid option is entered in front of a valid command, the program prints an error message.
3) if any file passed doesn't exist in the directory, then the program prints an error message.
4) if any directory passed doesn't exist, then the program prints an error message.
5) if a file doesn't open due to permission not granted, then the program prints an error message.
6) if a directory couldn't be created due to some reason, then the program prints an error message.
7) if the directory couldn't be changed due to permission reasons or directory not exising, then the program prints an error message.
8) the shell/program doesn't terminate until "exit" command is executed.









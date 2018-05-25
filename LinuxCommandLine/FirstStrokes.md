# Part 1:Learning Shell

## 1.What is Shell
---
#### Shell prompt
---
```sh
[me@linuxbox~]$
```
It will usually include your *username@machinename*, followed by current working directory and dolar sign($).  

If the last character of prompt is a hash sign(#) rather than dolar sign, the ternimal session has *superuser* privilleges.  

#### Command history
----
Press **up-arrow** key, we will see the history.

#### Cursor Movemoent
---
just press right/left-arrow keys, if current terminal remain some command.  

#### Mice and Focus
---
using double-clicking or holding down the left mouse button, you may select some highlight words, then, **pressing the middle mopuse button** will cause the text to be pasted.  
Do not use ctrl + C/V.  They don't work.

#### Date
---
```sh
wujing@ubuntu:~$ date
Thu May 24 01:07:55 PDT 2018
```
A related command is cal, that shows the calendar of current month.
```sh
wujing@ubuntu:~$ cal
      May 2018        
Su Mo Tu We Th Fr Sa  
       1  2  3  4  5  
 6  7  8  9 10 11 12  
13 14 15 16 17 18 19  
20 21 22 23 24 25 26  
27 28 29 30 31        
                   
```
To see the current amount of free space on your disk drives, enter **df**(it indicates disk free?):
```sh
wujing@ubuntu:~$ df
Filesystem     1K-blocks     Used Available Use% Mounted on
udev              982700        0    982700   0% /dev
tmpfs             201808     6376    195432   4% /run
/dev/sda1       18447100 13265832   4221168  76% /
tmpfs            1009040      212   1008828   1% /dev/shm
tmpfs               5120        4      5116   1% /run/lock
tmpfs            1009040        0   1009040   0% /sys/fs/cgroup
tmpfs             201808       52    201756   1% /run/user/1000
```

**free** memory:
```sh
$ free
```
```sh
$ exit
```
#### Help
```sh
$ man man df
```


#### Console Behind Curtain
---
Called *virtual terminals* or *virtual consoles* runs begind the **GUI**.These session can be accessed on Most Linux distribution by pressing **Ctrl-ALT-F6**.When accessed, it presents a login prompt, enter our username and password to switch from one virtual console to another, pass **ALT** and **F1-6**. To return to the graphic desktop, press **ALT-F7**.

## 2.Navigation
---
* pwd -Print working directory
* cd  -change directory
* ls  -list directory contents.
#### Firlsystem Tree
---
Linux organized its files in what it called a *hierarchical directory structure*, that means they are organized in a tree-like pattern of directories.  

The first directory in filesystem is called the *root directory*. The root contains files and subdirectories, and subdirectories contain more files and subdirectories...  
While Windows has a separete filesystem tree for each storage device, Unix-like systems such as Linux always have a single filesystem tree, regardless of how many drives or storage decixes are attched to the computer.  

Storage devices are *mounted*(just like attach) at various points on the tree according to the whims of the *system administrator*, the person responsible for the maintenace of the system.  

#### The Current Working Directory
---
*parent directory* is above *current working directory*.
```sh
wujing@ubuntu:~$ pwd
/home/wujing
```
First log in our system(or start a terminal), our current working directory is set to our *home directory*. Each user account is given its own home directory, which is the only place the user is allowed to wreite files when operating as a regular user.

#### Listing Contents
----
```sh
$ ls
```

#### Changing and Shortcuts
---
**cd ~ **  Changes to /home/username  
**cd - **  Changes working directory to the previous working directory  
**cd ~username**  Changes to home directory of username.


##### Absolute Pathnames
---
Absolute pathname begins with the root directory.
```sh
wujing@ubuntu:~$ cd /usr/bin
wujing@ubuntu:/usr/bin$ cd ~
wujing@ubuntu:~$
```
*/usr/bin* is full of files.

##### Relative Pathnames
---
It starts from working directory. By using **.** and **..** to perform it.  
Most of us know many usage on it, but note here:
```sh
wujing@ubuntu:/usr$ cd bin
wujing@ubuntu:/usr/bin$ 
```
You can omit the **./** because it is implied.

#### Filenames
---
1. Uses **ls -a** to list hidden file.
2. Case sensitive.Linux has no "file extension".

## 3.Exploring System
* **ls**  List directory contents.
* **file**  Determine file type.
* **less**  View file contents.

#### ls
---
1. **$ ls**
2. **$ ls /usr**  Specify the directory to list.
3. **$ ls ~ /usr**  List multiple directories.  
4. **$ ls -l**  Change format of the output to reveal more detail.long format

#### Options and Arguments
---
```sh
command -options arguments
```

GNU Project support *long options*, consisting of a word preceded by two dashes.  

the l option to produce
long format output, and the t option to sort the result by the file’s modification time:  
```sh
wujing@ubuntu:~$ ls -lt
```
We’ll add the long option --reverse to reverse the order of the sort:
```sh
wujing@ubuntu:~$ ls -lt --reverse
```

**Table:**
![](./table3-1.png)

#### Long Format
```sh
total 60
drwxrwxr-x  2 wujing wujing 4096 May 24 01:59 ha
drwxr-xr-x  3 wujing wujing 4096 May  9 01:06 Desktop
drwxr-xr-x  2 wujing wujing 4096 May  6 21:26 Downloads
drwxrwxr-x 22 wujing wujing 4096 May  4 21:44 anaconda3
drwxrwxr-x 22 wujing wujing 4096 May  4 21:25 anaconda2
drwxrwxr-x  2 wujing wujing 4096 May  4 09:44 MyPrograms
drwxr-xr-x  2 wujing wujing 4096 May  4 09:22 Documents
drwxr-xr-x  2 wujing wujing 4096 May  4 09:22 Music
drwxr-xr-x  2 wujing wujing 4096 May  4 09:22 Pictures
drwxr-xr-x  2 wujing wujing 4096 May  4 09:22 Public
drwxr-xr-x  2 wujing wujing 4096 May  4 09:22 Templates
drwxr-xr-x  2 wujing wujing 4096 May  4 09:22 Videos
-rw-r--r--  1 wujing wujing 8980 May  4 09:13 examples.desktop
```
![](./table3-2.png)

#### Determining File's Type with file
---
```sh
file filename
[me@linuxbox ~]$ file picture.jpg
picture.jpg: JPEG image data, JFIF standard 1.01
```
Then you know the filetype to ensure it is readable or a script etc.

#### Viewing File Contents with less
*scripts*, *configuration files*.  
```sh
wujing@ubuntu:~$ less '/home/wujing/Desktop/main.c' 
```

**table:**
![](./table3-3.png)

**less is more.**

#### Tour
---
*symbolic link*, also known as a *soft link* or *symlimk*.  
A file can be referenced by multiple names.  

When the software updating, only instead of the old one such as *foo*, and use the new name to point it. *foo-2.6* -> foo, *foo-2.7* -> foo. So it allows us to keep both version on our machine.

#### Hard Links
---
The second type of link.

## 4.Manipulate Files and Directories
* **cp**—Copy files and directories.
* **mv**—Move/rename files and directories.
* **mkdir**—Create directories.
* **rm**—Remove files and directories.
* **ln**—Create hard and symbolic links.

#### Wildcards
---
![](./table4-1.png)
![](./table4-2.png)
![](./table4-3.png)
  
Wildcards can be used with any command that accepts filenames as
arguments

#### Character Ranges
---
[a**-*], [A-Z], [0-9].
they will not produce the expected results unless properly configured. For now, you should avoid using them and use character classes instead.

#### mkdir—Create Directories
---
```sh
mkdir directory...
mkdir dir1 dir2 dir3
```

#### cp—Copy Files and Directories
---
copy files or directories.
```sh
cp item... directory
```
![](./table4-4.png)  
note the directory -r, when you need to copy directory, append it.
![](./table4-5.png)

#### mv—Move and Rename Files
---
```sh
mv item1 item2
```
move or rename to files or directory item2.  

![](./table4-6.png)
![](./table4-7.png)

#### rm—Remove Files and Directories
---
Be careful with rm.  
**useful tip:**Whenever you use wildcards with rm (besides carefully
checking your typing!), test the wildcard first with ls.    
```sh
rm item...
```  

Use the *-i*, irm only works when you press *y/Y*.

![](./tb4-8.png)
![](./tb4-9.png)

#### ln—Create Links
---
hard link:only file.  
``sh
ln file link
```
symbolic link:
```sh
ln -s item link
```
If the file symbolic points to is deleted, list will show it in a disdinguishing color. Actually it points nothing.

Lile shortcut in Windows.

Ctrl + Shift + dragging to make link.

## 5.Working with Command
* **type**—Indicate how a command name is interpreted.
* **which**—Display which executable program will be executed.
* **man**—Display a command’s manual page.
* **apropos**—Display a list of appropriate commands.
* **info**—Display a command’s info entry.
* **whatis**—Display a very brief description of a command.
* **alias**—Create an alias for a command

#### Creating Your Own Commands with alias
---
Before alias used, we should use *type* to check whether our command existed.
```sh
wujing@ubuntu:~/Desktop$ type test
test is a shell builtin
wujing@ubuntu:~/Desktop$ type hehe
bash: type: hehe: not found
wujing@ubuntu:~/Desktop$ 
wujing@ubuntu:~/Desktop$ alias hehe='cd /usr;ls;cd -'
wujing@ubuntu:~/Desktop$ type hehe
hehe is aliased to 'cd /usr;ls;cd -'
wujing@ubuntu:~/Desktop$ unalias hehe
```

To see all the aliases defined in the environment, use the alias command without arguments.

## 6.Redirection
* **cat**—Concatenate files.
* **sort**—Sort lines of text.
* **uniq**—Report or omit repeated lines.
* **wc**—Print newline, word, and byte counts for each file.
* **grep**—Print lines matching a pattern.
* **head**—Output the first part of a file.
* **tail**—Output the last part of a file.
* **tee**—Read from standard input and write to standard output and files.
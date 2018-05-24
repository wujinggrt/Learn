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

#### Viewing File Contents with less
*scripts*, *configuration files*.  
```sh
wujing@ubuntu:~$ less '/home/wujing/Desktop/main.c' 
```

**table:**
![](./table3-3.png)

**less is more.**
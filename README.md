# ft_ls

##### Reproduction of binary _ls_

### Usage:
> ls [-Rafhlrst] [--all --human-readable --recursive --reverse] [file ...]

- -a      Include directory entries whose names begin with a dot (.)
- -f      Output is not sorted.  This option turns on the -a option.
- -h      When used with the -l option, use unit suffixes: Byte, Kilobyte, Megabyte, Gigabyte and Terabyte in order to reduce the number of digits to three or less using base 2 for sizes.
- -l      List in long format. (see belows) If the output is to a terminal, a total sum for all the file sizes is output on a line before the long listing.
- -R      Recursively list subdirectories encountered.
- -r      Reverse the order of the sort to get reverse lexicographical order or the oldest entries first (or largest files last, if combined with sort by size
- -s      Display the number of file system blocks actually used by each file, in units of 512 bytes, where partial units are rounded up to the next integer value.  If the output is to a terminal, a total sum for all the file sizes is output on a line before the listing.  The environment variable BLOCKSIZE overrides the unit size of 512 bytes.
- -t      Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.



####   The Long Format
     If the -l option is given, the following information is displayed for each file: file mode, number of links, owner name, group name, number of bytes in the
     file, abbreviated month, day-of-month file was last modified, hour file last modified, minute file last modified, and the pathname.  In addition, for each
     directory whose contents are displayed, the total number of 512-byte blocks used by the files in the directory is displayed on a line by itself, immediately
     before the information for the files in the directory.  If the file or directory has extended attributes, the permissions field printed by the -l option is
     followed by a '@' character.  Otherwise, if the file or directory has extended security information (such as an access control list), the permissions field
     printed by the -l option is followed by a '+' character.

     If the modification time of the file is more than 6 months in the past or future, then the year of the last modification is displayed in place of the hour
     and minute fields.

     If the owner or group names are not a known user or group name, or the -n option is given, the numeric ID's are displayed.

     If the file is a character special or block special file, the major and minor device numbers for the file are displayed in the size field.  If the file is a
     symbolic link, the pathname of the linked-to file is preceded by ``->''.

     The file mode printed under the -l option consists of the entry type, owner permissions, and group permissions.  The entry type character describes the type
     of file, as follows:

           b     Block special file.
           c     Character special file.
           d     Directory.
           l     Symbolic link.
           s     Socket link.
           p     FIFO.
           -     Regular file.

     The next three fields are three characters each: owner permissions, group permissions, and other permissions.  Each field has three character positions:

           1.   If r, the file is readable; if -, it is not readable.

           2.   If w, the file is writable; if -, it is not writable.

           3.   The first of the following that applies:

                      S     If in the owner permissions, the file is not executable and set-user-ID mode is set.  If in the group permissions, the file is not
                            executable and set-group-ID mode is set.

                      s     If in the owner permissions, the file is executable and set-user-ID mode is set.  If in the group permissions, the file is executable
                            and setgroup-ID mode is set.

                      x     The file is executable or the directory is searchable.

                      -     The file is neither readable, writable, executable, nor set-user-ID nor set-group-ID mode, nor sticky.  (See below.)

                These next two apply only to the third character in the last group (other permissions).

                      T     The sticky bit is set (mode 1000), but not execute or search permission.  (See chmod(1) or sticky(8).)

                      t     The sticky bit is set (mode 1000), and is searchable or executable.  (See chmod(1) or sticky(8).)
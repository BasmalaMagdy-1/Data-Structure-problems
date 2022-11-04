# Data-Structure-problems
#problem 1
In this problem, you should develop a stack class similar to that provided in the
C++ STL. You cannot use any of the C++ STL classes in this problem.
Given a string path, which is an absolute path (starting with a slash '/') to a file or
directory in a Unix-style file system, convert it to the simplified canonical path.
In a Unix-style file system, a period '.' refers to the current directory, a double
period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e.
'//') are treated as a single slash '/'. For this problem, any other format of periods
such as '...' are treated as file/directory names.
The canonical path should have the following format:
● The path starts with a single slash '/'.
● Any two directories are separated by a single slash '/'.
● The path does not end with a trailing '/'.
● The path only contains the directories on the path from the root directory to
the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path

#problem 2
In this problem, you should develop a queue class similar to that provided in the
C++ STL. You cannot use any of the C++ STL classes in this problem.
There are n people in a line queuing to buy tickets, where the 0th person is at the
front of the line and the (n - 1)th person is at the back of the line.
You are given a 0-indexed integer array of tickets of length n where the number of
tickets that the ith person would like to buy is tickets[i].
Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket
at a time and has to go back to the end of the line (which happens instantaneously)
in order to buy more tickets. If a person does not have any tickets left to buy, the
person will leave the line.
Return the time taken for the person at position k (0-indexed) to finish buying
tickets.

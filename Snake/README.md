Classic Snake game.Read Description for how to run

Note : if the terminal is not clearing the previous grids then in line 90 add system("cls"); for windows or system("clear"); for linux and mac
1. In the void setup function adjust the grid size (n, m) and the starting position for the head. Also adjust the pace in line 152. Higher the number slower the game, and vice versa.
2. Code can be copy pasted for windows
3. For linux or max
    a. Find an alternate library for conio.h and put it in line 8
    b. Find the appropriate function for _getch() and _kbhit() in that library and replace them in line 36 and 37.
    c. Adjust the sleep time in line 154

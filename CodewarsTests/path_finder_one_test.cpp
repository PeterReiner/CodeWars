#include "pch.h"
#include "../Codewars/path_finder_one.cpp"


TEST(path_finder_one_test, handle_simple_mazes)
{
    EXPECT_EQ(path_finder(".W.\n.W.\n..."), true);
    /*
      Maze:
        .W.
        .W.
        W..
    */
    EXPECT_EQ(path_finder(".W.\n.W.\nW.."), false);
    /*
      Maze:
        ......
        ......
        ......
        ......
        ......
        ......
    */
    EXPECT_EQ(path_finder("......\n......\n......\n......\n......\n......"), true);
    /*
      Maze:
        ......
        ......
        ......
        ......
        .....W
        ....W.
    */
    EXPECT_EQ(path_finder("......\n......\n......\n......\n.....W\n....W."), false);
}
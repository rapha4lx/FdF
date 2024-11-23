
#include <unistd.h>
#include "srcs/parser.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "map not inserted\n", 19);
        return (0);
    }
    write (1, "asdlklakl\n", 11);
    map_check(argv[1]);
    return (0);
}

#include <unistd.h>
#include "srcs/parser.h"

int main(int argc, char **argv)
{
    t_map   *map;

    if (argc != 2)
    {
        write(1, "map not inserted\n", 18);
        return (0);
    }
    write (1, "asdlklakl\n", 11);
    map_check(argv[1], &map);
    return (0);
}

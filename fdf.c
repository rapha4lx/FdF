#include <unistd.h>
#include "imports/libft/libft.h"
#include "srcs/parse/parser.h"

void  map_error(char *map)
{
  ft_putstr("This map: ");
  ft_putstr(map);
  ft_putstr(" is brock\n");
  exit(0);
}

int main(int argc, char **argv)
{
    t_map   *map;

    if (argc != 2)
    {
        write(1, "map not inserted\n", 18);
        return (0);
    }
    ft_putstr("[START] init_map\n");
    if (!init_map(&map))
		  return (0);
    ft_putstr("[SUCCESS] init_map\n");
    ft_putstr("[START] map_check\n");
    if (!map_check(argv[1], &map))
      map_error(argv[1]);
    return (0);
}

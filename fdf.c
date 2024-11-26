#include <unistd.h>
#include "imports/libft/libft.h"
#include "srcs/parse/parser.h"

static void  map_error(char *map_file, t_map **map)
{
  ft_putstr("This map: ");
  ft_putstr(map_file);
  ft_putstr(" is brock\n");
  free_map(map);
  exit(0);
}

// static void print_map(t_map *map)
// {
//   while ()
//   {
//     while (/* condition */)
//     {
//       /* code */
//     }
     
//   }
// }

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
      map_error(argv[1], &map);
    ft_putstr("[END] success read map\n");
    // print_map(map);
    free_map(&map);
    return (0);
}

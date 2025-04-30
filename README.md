-#---#---#---#---#---#---#---#---#---#---#-

Usage:
./so_long <path/map.ber>

Only use for MacOS, the MLX42 library has several issues with Linux and Windows.

-#---#---#---#---#---#---#---#---#---#---#-

Map making:
The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position.

- The map must be rectangular.
- The map must be closed/surrounded by walls.
- The map must contain exactly 1 exit, 1 starting position, and at least 1 collectible to be valid.

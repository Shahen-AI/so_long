# SO_LONG

This game is built wuth miniLibX library. <br>
The player’s goal is to collect all collectibles present on the map then escape with minimal movement.<br>
Player can move up, down, left, right.<br>
At every move the current number of movements displays in the shell.<br>

• Program takes as a first argument a map description file with the .ber extension.<br>
  It works with any VALID map you can create. There is a simple valid map in [./maps/map.ber](https://github.com/Shahen-AI/so_long/tree/master/maps)<br>

RUN THIS COMMAND IN SHELL TO START THE GAME:<br>
> ./so_long ./maps/map.ber

• The valid map must be composed of only 5 possible characters:<br>
  0 - for an emptyspace,<br>
  1 - for a wall,<br>
  C - for a collectible,<br>
  E - for map exit,<br>
  P - for the player’s starting position.<br>

• The map must be closed/surrounded by walls (character '1'), if not the program returns an error.<br>
• Map must have at least one collectible, and only one starting position and one exit.<br>

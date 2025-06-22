<div align="center">
  <img src="https://i.ibb.co/cmF80PB/image.png" alt="Project score">
</div>

# so_long
  
This is my so_long project, an implementation of a basic 2D game as part of my 42 School coursework. The core of this project revolved around parsing game environments, implementing player interaction, and displaying visuals using MiniLibX. It provided valuable insights into game logic design, collision detection, and the fundamentals of graphical programming with C libraries.

## Usage

To compile the program you will need to add the minilibX to the project root and compile the minilibX.  
  
After that, if you're not there navigate to the project root and run:
```Bash
make
# or
make bonus
```

Once that's done you can use the program like this:
```Bash
./so_long map_file
```

## Examples

The following examples were recorded using the file maps/map_3.ber:  
- Idle:  
![Example idle](https://i.ibb.co/gMyD65Hn/idle-so-long.gif)  
- Losing:  
![Example losing](https://i.ibb.co/S4XbbWZf/lose-so-long.gif)  
- Winning:  
![Example winning](https://i.ibb.co/tM8S41bX/win-so-long.gif)  
- Small easter egg:  
![Example easter](https://i.ibb.co/N2sCpDt3/easter-so-long.gif)  

## Note on Project State

All projects from my 42 cursus are preserved in their state immediately following their final evaluation. While they may contain mistakes or stylistic errors, I've chosen not to alter them. This approach provides a clear and authentic timeline of my progress and learning journey as a programmer.

## Notable errors

The last step before winning or losing isn't updating the step counter. You can see that behavior in the examples above.

One easy way to fix this is to alter the function ft_end_game like this:

```C
int	ft_end_game(void *vdata)
{
	t_data			*data;

	data = (t_data *)vdata;
	if (data->end == 0)
		return (ft_game_latency(data));
	if (data->end == 1)
	{
        // EDIT BEGIN
		if (data->winner + data->loser == 1)
			ft_render_elements(data);
        // EDIT END

		if (data->loser > 0 && data->loser < 6)
			ft_end_game_loser(data);
		else if (data->winner > 0 && data->winner < 6)
			ft_end_game_winner(data);
		else if (ft_black_fade(data) == 1)
			data->end++;
	}
	if (data->end > 1 && data->end < 30)
		ft_end_game_img(data);
	if (data->end == 30)
		ft_close_window(data);
	return (0);
}
```

This way the game will update the hud one last time before it ends.

There's also an unprotected malloc in my get_next_line function ft_fill_stash.

## Special thanks

Big thanks to [BUTTERHANDS](https://butterhands.itch.io/) who made almost all the sprites I used for this project, and distributed them freely.

## License

[MIT](https://choosealicense.com/licenses/mit/)  

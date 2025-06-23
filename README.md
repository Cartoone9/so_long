<div align="center">
  <img src="https://i.ibb.co/cmF80PB/image.png" alt="Project score">
</div>

# so_long
  
This is my so_long project, an implementation of a basic 2D game as part of my 42 School coursework. The core of this project revolved around parsing game environments, implementing player interaction, and displaying visuals using MiniLibX. It provided valuable insights into game logic design, collision detection, and the fundamentals of graphical programming with C libraries.

## Usage

First, add the minilibX to the project root and compile it. For Linux users: 
```bash
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux && make
```

After that, to compile the game go to the project root and run:
```bash
make
# or
make bonus
```

Once that's done you can use the program like this:
```bash
./so_long map_file.ber
```

## Controls

Move the player:  
- `W`, `A`, `S`, `D`  
- `↑`, `←`, `↓`, `→`  

Quit the game:  
- `ESC`

## Examples

The following examples were recorded using the file `maps/map_3.ber`.  
You can find other maps available in the `maps/` directory, or add your own.  
  
- Idle:  
![Example idle](https://i.ibb.co/gMyD65Hn/idle-so-long.gif)  
- Losing:  
![Example losing](https://i.ibb.co/S4XbbWZf/lose-so-long.gif)  
- Winning:  
![Example winning](https://i.ibb.co/tM8S41bX/win-so-long.gif)  

### Easter Egg

Pressing `E` in-game triggers a small hidden animation after winning:
![Example easter](https://i.ibb.co/N2sCpDt3/easter-so-long.gif)  

## Note on Project State

All projects from my 42 cursus are preserved in their state immediately following their final evaluation. While they may contain mistakes or stylistic errors, I've chosen not to alter them. This approach provides a clear and authentic timeline of my progress and learning journey as a programmer.

## Known Issues & Fix Suggestions

The step counter doesn't update for the final move before winning or losing.  
This can be fixed by updating the `ft_end_game()` function like so:  

```C
int	ft_end_game(void *vdata)
{
	t_data  *data;

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

`ft_fill_stash()` in my `get_next_line` implementation contains an unprotected `malloc()` that could cause issues in edge cases.

## Special Thanks

Big thanks to [BUTTERHANDS](https://butterhands.itch.io/) who made nearly all the sprites used in this project and released them for free.

## License

[MIT](https://choosealicense.com/licenses/mit/)  

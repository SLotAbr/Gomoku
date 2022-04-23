
const int XSIZE = 15;
const int YSIZE = 15;

extern "C" int vertical_check(int last_move[2], int field_info[YSIZE*XSIZE])
{
	const int x = last_move[0];
	const int y = last_move[1] - 4;

	int player_id = 0;
	int line_length = 0;

	for (int i = 0; i < 9; ++i)
	{
		if ((y+i) < 0) continue;
		if ((y+i) >= YSIZE) break;

		int cell = field_info[(y+i)*YSIZE + x];

		if (cell != 0) {
			if (cell == player_id) line_length++;
			else {
				player_id = cell;
				line_length = 1;
			}
		} else {
			player_id = 0;
			line_length = 0;
		}
		
		if (line_length == 5) break;
	}

	if (line_length==5)
		return player_id;
	else
		return 0;
}

extern "C" int horizontal_check(int last_move[2], int field_info[YSIZE*XSIZE])
{
	const int x = last_move[0] - 4;
	const int y = last_move[1];

	int player_id = 0;
	int line_length = 0;

	for (int i = 0; i < 9; ++i)
	{
		if ((x+i) < 0) continue;
		if ((x+i) >= XSIZE) break;

		int cell = field_info[y*YSIZE + (x+i)];

		if (cell != 0) {
			if (cell == player_id) line_length++;
			else {
				player_id = cell;
				line_length = 1;
			}
		} else {
			player_id = 0;
			line_length = 0;
		}
		
		if (line_length == 5) break;
	}

	if (line_length==5)
		return player_id;
	else
		return 0;
}

extern "C" int diagonal_check(int last_move[2], int field_info[YSIZE*XSIZE])
{
	const int x = last_move[0] - 4;
	const int y = last_move[1] - 4;

	int player_id = 0;
	int line_length = 0;

	for (int i = 0; i < 9; ++i)
	{
		if (x+i < 0 || y+i < 0) continue;
		if (x+i >= XSIZE || y+i >= YSIZE) break;

		int cell = field_info[(y+i)*YSIZE + (x+i)];

		if (cell != 0) {
			if (cell == player_id) line_length++;
			else {
				player_id = cell;
				line_length = 1;
			}
		} else {
			player_id = 0;
			line_length = 0;
		}

		if (line_length == 5) break;
	}

	if (line_length==5)
		return player_id;
	else
		return 0;
}

extern "C" int find_winner(int last_player, int last_move[2], int field_info[YSIZE*XSIZE])
{
	// vertical
	int winner;
	winner = vertical_check(last_move, field_info); if (winner!=0) return winner;
	winner = horizontal_check(last_move, field_info); if (winner!=0) return winner;
	return diagonal_check(last_move, field_info);

	// horizontal
	// main diagonal
	// secondary diagonal
}


const int XSIZE = 15;
const int YSIZE = 15;


// returns identifier of winner
extern "C" int find_winner(int last_player, int last_move[2], int field_info[YSIZE*XSIZE])
{
	
	// vertical
	int x = last_move[0];
	int y = last_move[1] - 4;

	int player_id = 0;
	int line_length = 0;

	for (int i = 0; i < 8; ++i)
	{
		if (y < 0) continue;

		int cell = field_info[y*YSIZE + x];

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
		
		y++;
		
		if (y >= YSIZE || line_length == 5) break;
	}

	if (line_length==5)
		return player_id;
	else
		return 0;

	// horizontal
	// main diagonal
	// secondary diagonal
}

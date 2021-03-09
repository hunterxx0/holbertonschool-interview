#include "slide_line.h"
/**
 * slide_left - Slide left
 * @line: Game line
 * @size: Line size
 *
 * Return:
 */
void slide_left(int **line, size_t size)
{
	int c = 0, i = 0, *l = *line;

	for(c = 0; c < (int)size; c++)
		{
			if (!l[c] && c < (int)size - 1)
			{
				i = c + 1;
				while (!l[i] && i < (int)size)
					i++;
				if (l[i] && i != (int)size)
				{
					l[c] = l[i];
					l[i] = 0;
				}
			}
		}
}
/**
 * slide_right - Slide right
 * @line: Game line
 * @size: Line size
 *
 * Return:
 */
void slide_right(int **line, size_t size)
{
	int c = 0, i = 0, *l = *line;

	for(c = (int)size-1; c > -1; c--)
	{
		if (!l[c] && c > 0)
		{
			i = c - 1;
			while (!l[i] && i > -1)
				i--;
			if (l[i] && i != -1)
			{
				l[c] = l[i];
				l[i] = 0;
			}
		}
	}
}

/**
 * add_right - add right
 * @line: Game line
 * @size: Line size
 *
 * Return:
 */
void add_right(int **line, size_t size)
{
	int c = 0, *l = *line;

	for (c = (int)size - 2; c > -1; c--)
	{
		if (l[c] && l[c] == l[c+1])
		{
			l[c+1] *= 2;
			l[c] = 0;
		}
	}

}
/**
 * add_left - add left
 * @line: Game line
 * @size: Line size
 *
 * Return:
 */
void add_left(int **line, size_t size)
{
	int c = 1, *l = *line;

	for (; c < (int)size; c++)
	{
		if (l[c] && l[c] == l[c-1])
		{
			l[c-1] *= 2;
			l[c] = 0;
		}
	}

}
/**
 * slide_line - Slide line game
 * @line: Game line
 * @size: Line size
 * @direction: Direcion
 *
 * Return: 1 for success 0 for failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return(0);

	if (direction == 1)
	{
		slide_right(&line, size);
		add_right(&line, size);
		slide_right(&line, size);
	}
	if (!direction)
	{
		slide_left(&line, size);
		add_left(&line, size);
		slide_left(&line, size);
	}
	return(1);
}

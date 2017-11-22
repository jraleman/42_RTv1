
#include "libft.h"

/*
** Check if the line given as parameter is a comment.
** Useful if you're reading lines and checking comments in a script file.
*/

int   ft_line_is_comment(char *line, char *comment)
{
    return (!ft_strncmp(ft_strtrim(line), comment, ft_strlen(comment)));
}

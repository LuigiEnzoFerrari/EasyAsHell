#include <minishell.h>


void	case_pipe(int *save, t_cmds  *cmds, int *stdpipe)
{
	if(cmds->index == 0)
	{
		if(cmds->next != NULL)
			dup2(cmds->pipe1[OUT], OUT);
	}
	else if(cmds->next == NULL)
    {
		dup2(save[IN], IN);
        dup2(stdpipe[OUT], OUT);
    }
	else 
	{
		dup2(cmds->pipe1[OUT], OUT);
		dup2(save[IN], IN);
	}
}


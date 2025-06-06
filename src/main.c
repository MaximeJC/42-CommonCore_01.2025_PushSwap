#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**args;
	t_list	*a;
	t_list	*b;

	args = NULL;
	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argvtoargs(argc, argv);
	argstostack(args, &a);
	if (ft_lstsize(a) == 2)
		sort_two(&a);
	else if (ft_lstsize(a) == 3)
		sort_three(&a);
	else if (is_sorted(a) == 0)
		sort(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}

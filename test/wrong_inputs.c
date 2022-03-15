/**
 * wrong_inputs - verify wrong input presence
 * @p: string to be controlled
 * Return:true or false
 */
int wrong_inputs(const char *p)
{

	if (*p == '%' && !*(p + 1))
		return (0);

	if (*p == '%' && *(p + 1) == ' ' && !*(p + 2))
		return (0);

	return (1);
}

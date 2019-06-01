while (true) 
{
	arg="$(./a.out )"; 
	echo $arg; 
	arg2="$(./push_swap $arg)"; 
	if (grep FUCK $arg2)
		break;	
	sleep 1;
}; 

int operand(int i)
{
	switch(pass_operand[i][0])
		case '+': if (pass_operand[i-1][1]==pass_operand[i+1][1])
				  	  plus_equal();
				  else if(pass_operand[i-1][1]!=pass_operand[i+1][1])
					  plus_dif();
				  break;

		case '-': if (pass_operand[i-1][1]==pass_operand[i+1][1])
					  minus_equal();
				  else if(pass_operand[i-1][1]!=pass_operand[i+1][1])
					  minus_dif();
				  break;
		case '*': if (pass_operand[i-1][1]==pass_operand[i+1][1])
					  multi_equal();
				  else if(pass_operand[i-1][1]!=pass_operand[i+1][1])
					  multi_dif();
				  break;
		case '/': if (pass_operand[i-1][1]==pass_operand[i+1][1])
					  divi_equal();
				  else if(pass_operand[i-1][1]!=pass_operand[i+1][1])
					  divi_dif();
				  break;
		case '%': if (pass_operand[i-1][1]==pass_operand[i+1][1])
					  rest_equal();
				  else if(pass_operand[i-1][1]!=pass_operand[i+1][1])
					  rest_dif();
				  break;
		default :

}		  

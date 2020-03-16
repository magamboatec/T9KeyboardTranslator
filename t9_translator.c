#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100 
void printT9()
{
	printf("**************************\n");
	printf("**T9 KEYBOARD TRANSLATOR**\n");
    printf("**______________________**\n");
    printf("**|    1 |    2 |    3 |**\n");
    printf("**| ,.!? | ABC  | DEF  |**\n");
    printf("**______________________**\n");
    printf("**|    4 |    5 |    6 |**\n");
    printf("**| GHI  | JKL  | MNO  |**\n");
    printf("**______________________**\n");
    printf("**|    7 |    8 |    9 |**\n");
    printf("**| PQRS | TUV  | WXYZ |**\n");
    printf("**______________________**\n");
    printf("**       |    0 |       **\n");
    printf("**       | [SPC]|       **\n");	
}

char numValue(char num,int quantity)
{
    char list1[4] = {',','.','!','?'}; 
    char list2[3] = {'A','B','C'};
    char list3[3] = {'D','E','F'};
    char list4[3] = {'G','H','I'};
    char list5[3] = {'J','K','L'};
    char list6[3] = {'M','N','O'};
    char list7[4] = {'P','Q','R','S'};
    char list8[3] = {'T','U','V'};
    char list9[4] = {'W','X','Y','Z'};

    switch(num){
    	case '1':{
    		return list1[quantity-1];
    	}
    	case '2':{
    		return list2[quantity-1];
    	}
    	case '3':{
    		return list3[quantity-1];
    	}
    	case '4':{
    		return list4[quantity-1];
    	}
    	case '5':{
    		return list5[quantity-1];
    	}
    	case '6':{
    		return list6[quantity-1];
    	}
    	case '7':{
    		return list7[quantity-1];
    	}
    	case '8':{
    		return list8[quantity-1];
    	}
    	case '9':{
    		return list9[quantity-1];
    	}
    	case '0':{
    		return ' ';
    	}
    	default:{
    		return '.';
    	}
    }

}

char * translateNumMsg(char * msg)
{
	char * res = malloc (sizeof (char) * MAX);
    char temp = msg[0];
    char charRes;
    int quantity=1;
    int i=1;

    while (i<= strlen(msg)-1)
    {
        if(msg[i]==temp)
        {
        	if((((temp=='7') || (temp=='9') ||(temp=='1')) && quantity==4) || ((temp!='7') && (temp!='9') && (temp!='1') && quantity==3) || (temp=='0'))
        	{
	        	charRes=numValue(temp,quantity);
	        	strncat(res, &charRes, 1);
	            quantity=1;
	            temp=msg[i];  
        	}
        	else
        	{
            	quantity++;
        	}
        }
        else{
        	charRes=numValue(temp,quantity);
        	strncat(res, &charRes, 1);
            quantity=1;
            temp=msg[i];       	
        }
        i++;
    }
    charRes=numValue(temp,quantity);
    strncat(res, &charRes, 1); 
    return res;

}

void menu()
{
	int choice;
	char msg[MAX];
	
	
	printf("\n");
	printf("1. numeric to text\n");
	printf("2. text to numeric\n");
	printf("\n");
	printf(">>");
	scanf("%d",&choice);
	switch(choice)	
	{
		case 1:
		{
			printf("\n");
			printf("Enter your text in numerical form:\n");
			printf(">>");
			scanf ("%s",msg);
			char * result = translateNumMsg(msg);
			printf("\nResult: %s\n",result);
			break;
		}
		case 2:
		{
			printf("Enter your text:\n");
			break;
		}
		default:
		{
			menu();
		}
	}	
}

int main(int argc, char const *argv[])
{
	printT9();
	menu();
	return 0;
}
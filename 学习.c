/*
 * @Author: your name
 * @Date: 2021-06-28 14:57:36
 * @LastEditTime: 2021-07-19 17:24:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \cworkplace\学习.c
 */
#include <stdio.h>
#include <string.h>

int main(int argc , const char **argv)
{	
	char name[10];
	char word[10];
	char username[10] = "ania0_art"; 
	char password[10] = "6371";
	int n;

	printf("\n\n");
	printf("\t*******************************\n");
	printf("\t********* 用户登录系统 *********\n");
	printf("\t*******************************\n");
	printf("\n\n");

	printf("\tPlease enter username.\n");	
	printf("\tusername:");
	scanf("%s",name);
	printf("\n");
	
		if( strcmp(username , name) == 0)
		{
			printf("\tPlease enter password.\n");
			printf("\tpassword:");
			scanf("%s",word);
			for(n = 0; n < 5; n++)
			{
				if( strcmp( password , word) == 0 )
				{				
					printf("\n\n");
					printf("\t*******************************\n");
					printf("\t********* 欢迎用户！ *********\n");
					printf("\t*******************************\n");
					printf("\n\n");
					break;
				}
				else
				{
					printf("\tPlease enter again!\n");
					printf("\tpassword:");
					scanf("%s",word);
					if( strcmp( password , word) == 0 )
					{				
						printf("\n\n");
						printf("\t*******************************\n");
						printf("\t********* 欢迎用户！ *********\n");
						printf("\t*******************************\n");
						printf("\n\n");
						break;
					}
				}
			}	
		}
		else if( strlen( name ) < 6)
		{	
			printf("\tLess input!\n");
		}
		else if( strcmp(username , name) != 0)
		{	
			printf("\tUsername error! Please enter again!\n");
		}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>



int main()
{
	
	int process_number,temp;
	int process[30];
	int wait = 0, turnaround=0;
	float ave_wait = 0.0,ave_turnaround=0.0;
	int size,j=0,i,value;

	FILE *in_file = fopen("Q2_1.txt","r");
	
	
	
    while (!feof(in_file)){
     fscanf(in_file,"%d",&value);
     process[j]=value;
    
     j++; 
}



	

	if (!in_file)

	{

		 printf( "Can't open file!\n");

		exit(1);

	}

	
    
	


    printf("Process Waiting Time :\n");
	for (i = 1; i <= process[0]; i++)
	{
        printf("p[%d]:%d\n",i,wait);
		
		ave_wait += wait;
		wait += process[i];
	}


	printf("Process Turnaround Time :\n");
	for (i = 1; i <= process[0]; i++)
	{
		turnaround += process[i];
		printf("p[%d]:%d\n",i,turnaround);
		ave_turnaround += turnaround;
	}
	printf("\nAverage waiting time :%f",ave_wait / process[0] );
	printf("\nAverage turnaround time :%f", ave_turnaround/ process[0] );
	
fclose(in_file);
	system("pause");
	return 0;
}

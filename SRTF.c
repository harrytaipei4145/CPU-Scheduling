#include <stdio.h>
#include <stdlib.h>

void bubble(int burst[],int arrival[],int p_num[],int process)
{
     int i,j,temp;
     for(i=0;i<=process-1;i++)
     {
                              
                              
                       for(j=0;j<process-i-1;j++)
                       {
                                          if(burst[j]>burst[j+1])
                                          {
                                                 temp=burst[j];
                                                 burst[j]=burst[j+1];
                                                 burst[j+1]=temp;  
                                                 temp=p_num[j];
                                                 p_num[j]=p_num[j+1];
                                                 p_num[j+1]=temp;    
                                                 temp=arrival[j];
                                                 arrival[j]=arrival[j+1];
                                                 arrival[j+1]=temp;            
                                          }  
                       }
                       
                        
     }
}
void bubble2(int burst[],int arrival[],int p_num[],int process,int wait[],int turnaround_time[])
{
     int i,j,temp;
     for(i=0;i<process;i++)
     {
                              
                              
                       for(j=0;j<process-i-1;j++)
                       {
                                          if(p_num[j]>p_num[j+1])
                                          {
                                                 temp=burst[j];
                                                 burst[j]=burst[j+1];
                                                 burst[j+1]=temp;  
                                                 temp=p_num[j];
                                                 p_num[j]=p_num[j+1];
                                                 p_num[j+1]=temp;    
                                                 temp=arrival[j];
                                                 arrival[j]=arrival[j+1];
                                                 arrival[j+1]=temp;   
                                                 temp=wait[j];
                                                 wait[j]=wait[j+1];
                                                 wait[j+1]=temp;    
                                                 temp=turnaround_time[j];
                                                 turnaround_time[j]=turnaround_time[j+1];
                                                 turnaround_time[j+1]=temp;          
                                          }  
                       }
                       
                        
     }
}


int main()
{
	
	int process;
	int arrival[30],burst[30],burst_execute[30];
	int wait = 0, turnaround=0;
	float ave_wait = 0.0,ave_turnaround=0.0;
	int j=0,i,value;
    int time=0,burst_sum=0,burst_count=0;
    int check[30];
    int p_num[30];
    int count=0,yet=0;
    int wait_time[30];
    int turnaround_time[30];
	FILE *in_file = fopen("Q2_3.txt","r");
	
	
	
    
     fscanf(in_file,"%d",&value);
     process=value;
     
     



	

	if (!in_file)

	{

		 printf( "Can't open file!\n");

		exit(1);

	}
	for(i=0;i<process;i++)
	{
       fscanf(in_file,"%d",&value);
     arrival[i]=value;
     p_num[i]=i+1;
     check[i]=0;
    }
    
    for(i=0;i<process;i++)
	{
       fscanf(in_file,"%d",&value);
     burst[i]=value;
     burst_sum+=burst[i];
     burst_execute[i]=0;
     
    
    }

   bubble(burst,arrival,p_num,process);

   while(burst_count<burst_sum)
   {
          
              if(burst_count<arrival[j])
              {
                             j++;       
                                 
              }   
              else if(burst_count>=arrival[j])
              {
                  
                if(j==yet)
                {
                          if(check[j]==0)
                          {
                                         
                                        burst_count=burst_count+burst[j]-burst_execute[j];
                                        check[j]=1;
                                        wait_time[j]=burst_count-burst[j]-arrival[j];
                                        turnaround_time[j]=burst_count-arrival[j];
                                        yet++;
                                        j=yet;
                                        printf("%d\n",burst_count);
                                        
                          }
                          else if(check[j]==1)
                          {
                               yet++;
                          }
                }   
                else if(j>yet)
                {
                     if(check[j]==0)
                     {
                               burst_count++;
                               burst_execute[j]++;
                               if(burst[j]==burst_execute[j])
                               {
                                                   check[j]=1;
                                                   wait_time[j]=burst_count-burst[j]-arrival[j];
                                                   turnaround_time[j]=burst_count-arrival[j];
                               } 
                               j=yet; 
                                
                     }
                     
                    

                }
                else if(j<yet)
                {
                     j++;
                }
                
              }
              
             
          
   } 
    bubble2(burst,arrival,p_num,process,wait_time,turnaround_time);
    printf("Process Waiting Time:\n");
    for(i=0;i<process;i++)
    {
                         ave_wait+= wait_time[i];
                        printf("P[%d]  %d\n",p_num[i],wait_time[i]);
    }
    printf("Process Turnaround Time:\n");
    for(i=0;i<process;i++)
    {
                         ave_turnaround+=turnaround_time[i];
                        printf("P[%d]  %d\n",p_num[i],turnaround_time[i]);
    }

printf("\nAverage waiting time :%f",ave_wait / process );
printf("\nAverage turnaround time :%f", ave_turnaround/ process );

   
	
    fclose(in_file);
	system("pause");
	return 0;
}

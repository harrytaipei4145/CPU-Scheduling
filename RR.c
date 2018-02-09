#include <stdio.h>
#include <stdlib.h>




int main()
{
	
	int process;
	int arrival[30],burst[30],burst_execute[30];
	int wait = 0, turnaround=0;
	float ave_wait = 0.0,ave_turnaround=0.0;
	int j=0,i,value;
    int burst_sum=0,burst_count=0;
    int check[30];
    int p_num[30];
    int count=0;
    int wait_time[30];
    int turnaround_time[30];
    int quantum,k,m=0,n=20;
    int order[30]; 
	FILE *in_file = fopen("Q2_4.txt","r");
	
	
	
    
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
    fscanf(in_file,"%d",&value);
     quantum=value;


while(burst_count<burst_sum)
{
                            for(k=0;k<process;k++)
                            {
                                                  
                                                  if(arrival[k]<=burst_count)
                                                  {
                                                                             if (check[k]==0)
                                                                             {
                                                                                             order[m]=k;
                                                                                             m++;
                                                                                              
                                                                             }
                                                                             else if(check[k]==1)
                                                                             {
                                                                                            order[n]=k;
                                                                                            n++;
                                                                                          
                                                                             }
                                                                             
                                                  }         
                            }
                            for(i=20;i<n;i++)
                            {
                            
                                       order[m]=order[i];
                                       m++;          
                                      
                            }
                            n=20;
                            
                            for(j=0;j<m;i++)
                            {
                            if(check[order[0]]==0)
                               {
                                           if(burst[order[0]]-burst_execute[order[0]]<=quantum)
                                           {
                                               burst_count=burst_count+burst[order[0]]-burst_execute[order[0]];
                                               burst_execute[order[0]]=burst[order[0]];
                                               
                                               check[order[0]]=2;
                                               wait_time[order[0]]=burst_count-burst[order[0]]-arrival[order[0]];
                                               turnaround_time[order[0]]=burst_count-arrival[order[0]];
                                               m--;
                                               for(i=0;i<m;i++)
                                               {
                                                               order[i]=order[i+1];
                                               }        
                                              
                                            
                                                                 
                                           }
                                           else if(burst[j]-burst_execute[j]>quantum)
                                           {
                                               
                                               burst_execute[order[0]]=quantum;
                                                burst_count+=burst_execute[order[0]];
                                                check[order[0]]=1;
                                              m--;
                                              
                                               for(i=0;i<m;i++)
                                               {
                                                               order[i]=order[i+1];
                                                               
                                               }       
                                                    
                                               continue;
                                                                           
                                           }
                               }
                               else if(check[order[0]]==1)
                               {
                                           if(burst[order[0]]-burst_execute[order[0]]<=quantum)
                                           {
                                               burst_count=burst_count+burst[order[0]]-burst_execute[order[0]];
                                               burst_execute[order[0]]=burst[order[0]];
                                               
                                               check[order[0]]=2;
                                               wait_time[order[0]]=burst_count-burst[order[0]]-arrival[order[0]];
                                               turnaround_time[order[0]]=burst_count-arrival[order[0]];
                                               m--;
                                               for(i=0;i<m;i++)
                                               {
                                                               order[i]=order[i+1];
                                               }         
                                                   
                            
                                                                 
                                           }
                                           else if(burst[j]-burst_execute[j]>quantum)
                                           {
                                               
                                               burst_execute[order[0]]=quantum;
                                                burst_count+=burst_execute[order[0]];
                                                check[order[0]]=1;
                                              m--;
                                               for(i=0;i<m;i++)
                                               {
                                                               order[i]=order[i+1];
                                               }       
                                                    
                                               
                                                                           
                                           }
                               }
                               
                               }
                           
                             
                           
                          
}
   


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

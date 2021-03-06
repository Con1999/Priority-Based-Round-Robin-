#include<stdio.h>
#include<conio.h>

void sort(int a[],int p[],int pid[],int af[],int b[],int fb[],int n,int comp[])
{
	int i=0,j=0,temp=0;
	for (i = 0; i < n; ++i) 
    {
        for (j = i + 1; j < n; ++j)
        {
            if (af[i]>af[j]) 
            {
            	temp =  comp[i];
                comp[i] = comp[j];
                comp[j] = temp;
                temp =  a[i];
                a[i] = a[j];
                a[j] = temp;
                temp =  af[i];
                af[i] = af[j];
                af[j] = temp;
                temp =  p[i];
                p[i] = p[j];
                p[j] = temp;
                temp =  pid[i];
                pid[i] = pid[j];
                pid[j] = temp; 
                temp =  b[i];
                b[i] = b[j];
                b[j] = temp; 
                temp =  fb[i];
                fb[i] = fb[j];
                fb[j] = temp;
    	    }
			else if(af[i]==af[j])
			{
              	if(p[i]<p[j])
				{
            	   	temp =  comp[i];
            	    comp[i] = comp[j];
            	    comp[j] = temp;
                	temp =  a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    temp =  p[i];
                    p[i] = p[j];
                    p[j] = temp;
                    temp =  af[i];
                    af[i] = af[j];
                    af[j] = temp;
                    temp =  pid[i];
                    pid[i] = pid[j];
                    pid[j] = temp; 
                    temp =  b[i];
                    b[i] = b[j];
                    b[j] = temp;
					temp =  fb[i];
                    fb[i] = fb[j];
                    fb[j] = temp;	
				}
			}
        }
	}
}

void sortid(int a[],int p[],int pid[],int af[],int b[],int fb[],int n,int comp[])
{
	int i=0,j=0,temp=0;
	for (i = 0; i < n; ++i) 
    {
        for (j = i + 1; j < n; ++j)
        {
            if (pid[i]>pid[j]) 
            {
              	temp =  comp[i];
                comp[i] = comp[j];
                comp[j] = temp;
                temp =  a[i];
                a[i] = a[j];
                a[j] = temp;
                temp =  af[i];
                af[i] = af[j];
                af[j] = temp;
                temp =  p[i];
                p[i] = p[j];
                p[j] = temp;
                temp =  pid[i];
                pid[i] = pid[j];
                pid[j] = temp; 
                temp =  b[i];
                b[i] = b[j];
                b[j] = temp; 
                temp =  fb[i];
                fb[i] = fb[j];
                fb[j] = temp;
            }
		}
    }
 
}

int main()
{
	int quantum,n,i,p[10],a[10],af[10],j,pid[10],b[10],time=0,cur=0,slot=0,comp[10],tat[10],wt[10],fb[10];
	printf("Prioirty Based Round Robin Scheduling\n\n");
	printf("Enter Time Quantum :- ");
	scanf("%d",&quantum);
	printf("Enter Number of Process:- ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter Arrval Time of Process %d :- ",i+1);
		pid[i] = i+1;
		scanf("%d",&a[i]);
		af[i]=a[i];
		printf("Enter Burst Time Of Process %d :- ",i+1);
		scanf("%d",&b[i]);
		fb[i] = b[i];
		printf("Enter Priority Of Process %d :- ",i+1);
		scanf("%d",&p[i]);	
	}
	printf("\n\n\t\tQuestion :- \n\n");
	printf(" PROCESS ID \t| ARRIVAL TIME \t| BURST TIME \t| PRIORITY \n");
	for(i=0;i<n;i++)
	{
		printf(" P[%d] \t\t| %d \t\t| %d \t\t| %d\n",pid[i],a[i],b[i],p[i]);
	}
	printf("\n\n");
	sort(a,p,pid,af,b,fb,n,comp);	
	for(i=0;i<n;i++)
	{
		if(b[i]%quantum==0)
			slot = slot+b[i]/quantum;
		else
			slot = slot+(b[i]/quantum)+1;
	}
	for(i=0;i<slot;i++)
	{
		int ft=time;
		if(fb[cur]<=quantum)
		{
			time=time+fb[cur];
			af[cur]=af[cur]+fb[cur];
			fb[cur]=0;
			p[cur]=-100;
			af[cur]=100000;
			comp[cur]=time;
		}
		else
		{
			fb[cur]=fb[cur]-quantum;
			time+=quantum;
			af[cur]=af[cur]+quantum;
		}
		printf("Process P[%d]Executed From %d to %d\n",pid[cur],ft,time);
		sort(a,p,pid,af,b,fb,n,comp);
		cur=0;
		for(j=1;j<n;j++)
			if(p[j]>p[cur]&&af[j]<=time)
					cur = j;
	}
	sortid(a,p,pid,af,b,fb,n,comp);
	printf("\n\n\t Final Solution :- \n");
	float avtat=0,avwt=0;
	printf(" PROCESS ID \t| TurnAroundTime \t| Waiting Time  \n");
	for(i=0;i<n;i++)
	{	
		tat[i] = comp[i]-a[i];
		int x = comp[i]-(a[i]+b[i]);
		printf(" P[%d] \t\t| %d \t\t\t| %d \n",pid[i],tat[i],x);
		avtat+=tat[i];	
		avwt+=x;
	}
	printf("\n\n Average TurnAround Time =  %.2f",avtat/=float(n));
	printf("\n Average Waiting Time =  %.2f",avwt/=float(n));
}
	


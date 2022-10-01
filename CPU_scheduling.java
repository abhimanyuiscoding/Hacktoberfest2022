import java.util.*;
 
class FCFS {
    public void fcfs() 
    {
        int n,sum=0;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of process : ");
        n=sc.nextInt();
        int burst_time[]=new int[n];
        int waiting_time[]=new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.print("Enter BurstTime for process "+i+" : ");
            burst_time[i]=sc.nextInt();         
        }
        sc.close(); 
        waiting_time[0]=0;
        for(int i=1;i<n;i++)
        {
            waiting_time[i]=waiting_time[i-1]+burst_time[i-1];
        }
        //OUTPUT
        System.out.println("--------+---------------+------------");
        System.out.println("Process\t|BurstTime\t|WaitingTime");
        System.out.println("--------+---------------+------------");
        for(int i=0;i<n;i++)
        {
            System.out.println("P"+i+"\t|"+burst_time[i]+"\t\t|"+waiting_time[i]);
        }
        System.out.println("--------+---------------+------------");
        for(int i=0;i<n;i++)
        {
            sum+=waiting_time[i];
        }
        System.out.println("Average waiting time = "+(sum/n));
    }
}

class SJF
{
    public void sjf()
    {
        Scanner sc = new Scanner(System.in);
        System.out.print ("Enter no of process:");
        int n = sc.nextInt();
        int pid[] = new int[n];
        int at[] = new int[n];
        int bt[] = new int[n];
        int ct[] = new int[n];
        int ta[] = new int[n];
        int wt[] = new int[n];  
        int f[] = new int[n];  
        int st=0, tot=0;
        float avgwt=0, avgta=0;
        
        for(int i=0;i<n;i++)
        {
            System.out.println ("Enter process " + (i+1) + " arrival time:");
            at[i] = sc.nextInt();
            System.out.println ("Enter process " + (i+1) + " brust time:");
            bt[i] = sc.nextInt();
            pid[i] = i+1;
            f[i] = 0;
        }
        // boolean a = true;
        while(true)
        {
            int c=n, min=999;
            if (tot == n)
                break;
            for (int i=0; i<n; i++)
            {
                if ((at[i] <= st) && (f[i] == 0) && (bt[i]<min))
                {
                    min=bt[i];
                    c=i;
                }
            }
            if (c==n)
                st++;
            else
            {
                ct[c]=st+bt[c];
                st+=bt[c];
                ta[c]=ct[c]-at[c];
                wt[c]=ta[c]-bt[c];
                f[c]=1;
                tot++;
            }
        }
        System.out.println("\npid\tArrivalTime\tBurstTime\tCT\tTAT\tWT");
        for(int i=0;i<n;i++)
        {
            avgwt+= wt[i];
            avgta+= ta[i];
            System.out.println(pid[i]+"\t"+at[i]+"\t\t"+bt[i]+"\t\t"+ct[i]+"\t"+ta[i]+"\t"+wt[i]);
        }
        System.out.println ("\nAverage tat is "+ (float)(avgta/n));
        System.out.println ("Average wt is "+ (float)(avgwt/n));
        sc.close();
    }
}

class PRIO
{
    public void prio() 
    {
        Scanner s = new Scanner(System.in);
        int ct[],a[],x,n,p[],pp[],bt[],w[],t[],i,k=0;
        float atat,awt;
        p = new int[10];
        pp = new int[10];
        bt = new int[10];
        w = new int[10];
        t = new int[10];
        a= new int[10];
        ct=new int[10];
        System.out.print("Enter the number of process : ");
        n = s.nextInt();
        for(i=0;i<n;i++)
        {
            System.out.print("Enter burst time of process "+i+" : ");
            bt[i] = s.nextInt();
            System.out.print("Enter priority of process "+i+" : ");
            pp[i] = s.nextInt();
            System.out.print("Enter arrival time of process "+i+" : ");
            a[i]=s.nextInt();
            p[i]=i+1;
        }
        s.close();
        for(i=0;i<n-1;i++)
        {

            for(int j=i+1;j<n;j++)
            {
                if(a[i]>=a[j] || pp[i]>pp[j])
                {
                    x=pp[i];
                    pp[i]=pp[j];
                    pp[j]=x;
                    x=bt[i];
                    bt[i]=bt[j];
                    bt[j]=x;
                    x=p[i];
                    p[i]=p[j];
                    p[j]=x;
                    x=a[i];
                    a[i]=a[j];
                    a[j]=x;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            if(i==1)
            { 
                k=bt[0];
                ct[0]=k;
            }
            else
            {
                k=bt[i-1]+k;
                ct[i-1]=k;
            }
            for(int j=i+1;j<=n;j++)
            {
                if(pp[i]<pp[j] && a[j]<=k)
                {
                    x=pp[i];
                    pp[i]=pp[j];
                    pp[j]=x;
                    x=bt[i];
                    bt[i]=bt[j];
                    bt[j]=x;
                    x=p[i];
                    p[i]=p[j];
                    p[j]=x;
                    x=a[i];
                    a[i]=a[j];
                    a[j]=x;
                }
            }
        }
        w[0]=0;
        awt=0;
        t[0]=bt[0];
        atat=t[0];
        for(i=1;i<n;i++)
        {
            t[i]=ct[i]-a[i];
            w[i]=t[i]-bt[i];
            awt+=w[i];
            atat+=t[i];
        }
        System.out.println("\nProcess\tArrivalTime\tBurstTime\tWaitTime\tTAT\tPriority");
        for(i=0;i<n;i++)
            System.out.println(p[i]+"\t"+a[i]+"\t\t"+bt[i]+"\t\t"+w[i]+"\t\t"+t[i]+"\t"+pp[i]);
        awt/=n;
        atat/=n;
        System.out.println("Average Wait Time : "+awt);
        System.out.println("Average Turn Around Time : "+atat);
        
    }
}

class ROBIN 
{
    public void robin()
    {
        int num;
        Scanner s = new Scanner(System.in);
        System.out.print("Enter number of processes : ");
        num = s.nextInt();
        int wtime[],btime[],rtime[],quantum;
        wtime = new int[num];
        btime = new int[num];
        rtime = new int[num];
        for(int i=0;i<num;i++) 
        { 
            System.out.print("Enter burst time for process "+i+" : "); 
            btime[i] = s.nextInt(); 
            rtime[i] = btime[i]; 
            wtime[i]=0; 
        } 
        System.out.print("\nEnter time slice : "); 
        quantum = s.nextInt(); 
        int rp = num;
        int i=0; int time=0; 
        System.out.print("0"); 
        s.close();
        wtime[0]=0; while(rp!=0) 
        { 
            if(rtime[i]>quantum)
            {
                rtime[i]=rtime[i]-quantum;
                System.out.print(" | P["+(i+1)+"] | ");
                time+=quantum;
                System.out.print(time);
            }
            else if(rtime[i]<=quantum && rtime[i]>0)
            {
                time+=rtime[i];
                rtime[i]=rtime[i]-rtime[i];
                System.out.print(" | P["+(i+1)+"] | ");
                rp--;
                System.out.print(time);
            }
            i++;
            if(i==num)
            {
                i=0;
            }
        } 
    }
}
public class scheduling
{
    public static void main(String[] args) {

       
            int ch;
        Scanner sc = new Scanner(System.in);
        System.out.println("1.FCFS\n2.SJF\n3.Priority\n4.Round Robin\n5.Exit");
        System.out.println("Enter your choice : ");
        ch=sc.nextInt();
        
        switch (ch) 
        {
            case 1:
                System.out.println("FCFS Scheduling");
                FCFS fobj = new FCFS();
                fobj.fcfs();
                break;
            case 2:
                System.out.println("SJF Scheduling");  
                SJF sobj = new SJF();
                sobj.sjf();
                break;
            case 3:
                System.out.println("Priority Scheduling");
                PRIO pobj = new PRIO();
                pobj.prio();
                break;
            case 4:
                System.out.println("Round Robin Scheduling");
                ROBIN robj = new ROBIN();
                robj.robin();
            default:
                break;
        }
        sc.close();
        }
        
    
}

# include <stdio.h>
struct processDetails {
        int number;
        int allocatedA;
        int allocatedB;
        int allocatedC;
        int maxA;
        int maxB;
        int maxC;
        int finished;
};
struct resourceDetails
{
        int maxA;
        int maxB;
        int maxC;
        int availableA;
        int availableB;
        int availableC;
};
void main()
{
        int num;
        printf("Enter the number of processes\n");
        scanf("%d",&num);
        struct resourceDetails resources[1];
        printf("Enter the number of instances of resource A\n");
        scanf("%d",&resources[0].maxA);
        printf("Enter the number of instances of resource B\n");
        scanf("%d",&resources[0].maxB);
        printf("Enter the number of instances of resource C\n");
        scanf("%d",&resources[0].maxC);
        resources[0].availableA = resources[0].maxA;
        resources[0].availableB = resources[0].maxB;
        resources[0].availableC = resources[0].maxC;
        int sumA = 0, sumB = 0, sumC = 0;
        struct processDetails process[num];
        for(int i=0; i<num; i++)
        {
                process[i].number = i+1;
                process[i].finished = 0;
                printf("Enter the allocated resources for process %d\n",i+1);
                printf("Resource A:\n");
                scanf("%d",&process[i].allocatedA);
                sumA += process[i].allocatedA;
                printf("Resource B:\n");
                scanf("%d",&process[i].allocatedB);
                sumB += process[i].allocatedB;
                printf("Resource C:\n");
                scanf("%d",&process[i].allocatedC);
                sumC += process[i].allocatedC;
                printf("Enter the maximum resources required for process %d\n",(i+1));
                printf("Resource A:\n");
                scanf("%d",&process[i].maxA);
                printf("Resource B:\n");
                scanf("%d",&process[i].maxB);
                printf("Resource C:\n");
                scanf("%d",&process[i].maxC);
        }
        resources[0].availableA -= sumA;
        resources[0].availableB -= sumB;
        resources[0].availableC -= sumC;
        printf("Process\t\tAllocation\t\t   Max\n");
        printf("\t        A   B   C\t\tA   B   C\n");
        for(int i=0; i<num; i++)
        {
                printf("p%d\t        %d   %d   %d\t\t%d   %d   %d\n",process[i].number,process[i].allocatedA,process[i].allocatedB,process[i].allocatedC,process[i].maxA,process[i].maxB,process[i].maxC);
        }
        printf("Currently Available\n");
        printf("A  B  C\n");
        printf("%d  %d  %d\n",resources[0].availableA,resources[0].availableB,resources[0].availableC);
        struct processNeed
        {
                int needA;
                int needB;
                int needC;
        } need[num];
        for(int i=0; i<num; i++)
        {
                printf("Need for Process %d: ",process[i].number);
                need[i].needA = process[i].maxA - process[i].allocatedA;
                printf("%d ",need[i].needA);
                need[i].needB = process[i].maxB - process[i].allocatedB;
                printf("%d ",need[i].needB);
                need[i].needC = process[i].maxC - process[i].allocatedC;
                printf("%d\n",need[i].needC);
        }
        int i = 0, count = 0;
        printf("Safe Sequence:\n<");
        while(count < num)
        {
                if(need[i].needA <= resources[0].availableA && need[i].needB <= resources[0].availableB && need[i].needC <= resources[0].availableC && process[i].finished ==0)
                {
                        printf("p%d ",process[i].number);
                        process[i].finished = 1;
                        resources[0].availableA += process[i].allocatedA;
                        resources[0].availableB += process[i].allocatedB;
                        resources[0].availableC += process[i].allocatedC;
                        count++;
                }
                i++;
                if(i >= num)
                {
                        i = 0;
                }
                if(count == num)
                {
                        break;
                }
        }
        printf(">\n");
}

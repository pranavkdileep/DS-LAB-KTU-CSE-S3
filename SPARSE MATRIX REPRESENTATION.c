#include<stdio.h>

void read(int A[100][100],int m,int n)
{
    printf("Enter The Elements: \n");
    for(int i = 0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            printf("A[%d][%d]: ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
}
void display(int A[100][100],int m,int n)
{
    for(int i = 0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}
void sparse(int A[100][100],int m,int n,int S[100][100])
{
    int k =1;
    S[0][0] = m;
    S[0][1] = n;
    for(int i = 0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(A[i][j]!=0)
            {
                S[k][0] = i;
                S[k][1] = j;
                S[k][2] = A[i][j];
                k++;
            }
        }
    }
    S[0][2] = k-1;
}
int main()
{
    int A[100][100],S[100][100],i,j,m,n;
    printf("Enter The No OF ROWS: ");
    scanf("%d",&m);
    printf("Enter The No OF COLUMNS: ");
    scanf("%d",&n);
    read(A,m,n);
    display(A,m,n);
    sparse(A,m,n,S);
    printf("Spars Representation\n");
    display(S,S[0][2]+1,3);
    return 0;
}
#include<stdio.h>
struct Poly 
{
    int exp;
    int val;
}p1[10],p2[10],p3[10];

int readPoly(struct Poly p1[10])
{
    int n;
    printf("Enter The No Of Terms: ");
    scanf("%d",&n);
    printf("Enter The Coefficients And Exponents: \n");
    for(int i = 0;i<n;i++)
    {
        printf("Coefficient: ");
        scanf("%d",&p1[i].val);
        printf("Exponent: ");
        scanf("%d",&p1[i].exp);
    }
    return n;
}
void displayPoly(struct Poly p1[10],int n)
{
    for(int i = 0;i<n;i++)
    {
        printf("%dx^%d",p1[i].val,p1[i].exp);
        if(i!=n-1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}
int addPoly(struct Poly p1[10],struct Poly p2[10],int n1,int n2,struct Poly p3[10])
{
    int i = 0,j = 0,k = 0;
    while(i<n1 && j<n2)
    {
        if(p1[i].exp>p2[j].exp)
        {
            p3[k].exp = p1[i].exp;
            p3[k].val = p1[i].val;
            i++;
            k++;
        }
        else if(p1[i].exp<p2[j].exp)
        {
            p3[k].exp = p2[j].exp;
            p3[k].val = p2[j].val;
            j++;
            k++;
        }
        else
        {
            p3[k].exp = p1[i].exp;
            p3[k].val = p1[i].val + p2[j].val;
            i++;
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        p3[k].exp = p1[i].exp;
        p3[k].val = p1[i].val;
        i++;
        k++;
    }
    while(j<n2)
    {
        p3[k].exp = p2[j].exp;
        p3[k].val = p2[j].val;
        j++;
        k++;
    }
    return k;
}
int main()
{
    int n1,n2,n3;
    printf("Enter The First Polynomial: \n");
    n1 = readPoly(p1);
    printf("Enter The Second Polynomial: \n");
    n2 = readPoly(p2);
    printf("First Polynomial: ");
    displayPoly(p1,n1);
    printf("Second Polynomial: ");
    displayPoly(p2,n2);
    n3 = addPoly(p1,p2,n1,n2,p3);
    printf("Resultant Polynomial: ");
    displayPoly(p3,n3);
    return 0;
}
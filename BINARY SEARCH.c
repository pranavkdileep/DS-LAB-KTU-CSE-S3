#include <stdio.h>
void main() {
int A[20], n, i, j, key, low = 0, mid, high, flag = 0,loc;

printf("Enter array size:");
scanf("%d", &n);
high = n - 1;
printf("Enter array elements:");
for (i = 0; i < n; i++) {
scanf("%d", &A[i]);
}
int temp;
for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - i - 1; j++) {
if (A[j] > A[j + 1]) {
temp = A[j + 1];
A[j + 1] = A[j];
A[j] = temp;
}
}
}
printf("Enter the element to be searched:");
scanf("%d", &key);

while (low <= high) {
mid = (low + high) / 2;
if (key == A[mid]) {
flag = 1;
loc = mid + 1;
break;
} else if (key < A[mid]) {
high = mid - 1;
} else {
low = mid + 1;
}
}

if (flag == 0) {
printf("The element is not present.\n");
} else {
printf("The element is present. at location %d\n",loc);
}
}
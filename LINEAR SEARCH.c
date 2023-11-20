#include <stdio.h>
int main() {
int array[20], size, i, key, found = 0,loc;

printf("Enter array size: ");
scanf("%d", &size);

printf("\nEnter array elements: ");
for (i = 0; i < size; i++) {
scanf("%d", &array[i]);
}

printf("\nEnter the element to be searched: ");
scanf("%d", &key);

for (i = 0; i < size; i++) {
if (key == array[i]) {
found = 1;
loc = i+1;
break;
}
}
if (found == 0) {
printf("\nThe element is not present.\n");
} else {
printf("\nThe element is present. At Location of %d\n",loc);
}
return 0;
}

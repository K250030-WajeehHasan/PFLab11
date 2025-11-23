#include <stdio.h>
#include <string.h>
#define MAXE 100
struct Emp {
    char name[60];
    int id;
    int days;
};
int totalAttendance(struct Emp a[], int n) {
    if(n==0) return 0;
    return a[n-1].days + totalAttendance(a, n-1);
}
void lowAttend(struct Emp a[], int n, int min) {
    int i, found=0;
    for(i=0;i<n;i++) {
        if(a[i].days < min) {
            printf("%s %d %d\n", a[i].name, a[i].id, a[i].days);
            found=1;
        }
    }
    if(!found) printf("none\n");
}
int main() {
    struct Emp emps[MAXE];
    int n, i;
    printf("How many employees: ");
    scanf("%d", &n);
    if(n<=0 || n>MAXE) {
        printf("Invalid number of employees.\n");
        return 1;
    }
    for(i=0;i<n;i++) {
        printf("Enter name of employee %d: ", i+1);
        scanf(" %59[^\n]", emps[i].name);
        printf("Enter ID of employee %d: ", i+1);
        scanf("%d", &emps[i].id);
        printf("Enter days present for employee %d: ", i+1);
        scanf("%d", &emps[i].days);
    }
    int tot = totalAttendance(emps,n);
    printf("Total attendance = %d\n", tot);
    int min;
    printf("Minimum days to check: ");
    scanf("%d",&min);
    printf("Employees with less than %d days:\n", min);
    lowAttend(emps,n,min);
    return 0;
}

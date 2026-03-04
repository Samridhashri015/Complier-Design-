#include <stdio.h>
#include <string.h>

#define MAX 10

int nfa[MAX][2][MAX], dfa[100][2], visited[100], queue[100];

int main() {
int states, finalCount, final[MAX];
int rules, i, j, k, p, a, b, start;
int front = 0, rear = 0, newState;

printf("Enter number of NFA states: ");
scanf("%d", &states);

printf("Enter number of final states: ");
scanf("%d", &finalCount);

printf("Enter final states: ");
for (i = 0; i < finalCount; i++)
scanf("%d", &final[i]);

printf("Enter number of transitions: ");
scanf("%d", &rules);

printf("Enter transitions (from input to):\n");
for (i = 0; i < rules; i++) {
scanf("%d %d %d", &p, &a, &b);
nfa[p][a][b] = 1;
}

printf("Enter start state: ");
scanf("%d", &start);

queue[rear++] = (1 << start);
visited[(1 << start)] = 1;

printf("\nDFA Transitions:\n");

while (front < rear) {
int curr = queue[front++];

for (i = 0; i < 2; i++) {
newState = 0;

for (j = 0; j < states; j++) {
if (curr & (1 << j)) {
for (k = 0; k < states; k++) {
if (nfa[j][i][k])
newState |= (1 << k);
}
}
}

dfa[curr][i] = newState;

printf("State %d --%d--> %d\n", curr, i, newState);

if (!visited[newState]) {
visited[newState] = 1;
queue[rear++] = newState;
}
}
}

printf("\nDFA States:\n");
for (i = 0; i < 100; i++) {
if (visited[i]) {
printf("State %d\n", i);
}
}

return 0;
}
